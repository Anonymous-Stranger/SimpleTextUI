/*
 * menu.cpp
 *
 * A class to display a menu in front of the user, and call a function based on their selection.
 * See _test.cpp for a demo of how to use Menu.
 * 
 *  Created on: Aug 17, 2015
 *      Author: Akash
 */

#include "Menu.h"

namespace SimpleTextUI {

	const std::string Menu::showMenuTitle {"Display Menu"};
	const std::string Menu::chooseMessage {"Choose one: "};

	int Menu::choose() {
	/* Displays the menu, and runs the function corresponding to the user's selection. 
	 * Returns the index corresponding with the choice. */

		printTitle();

		// print default items
		int defaultItems {0};
		printItem(showMenuTitle, defaultItems++);

		// print programmer defined items
		int count {defaultItems};
		for (MenuItem& i : items) printItem(i.first, count++);
		io->outputSeparator();

		// get choice
		int choice {input<int>(*io, chooseMessage, [count](int i)->bool{ return  0 <= i && i < count; })};
		*io << std::endl;

		// if choice is a default item, perform relevant action
		if (choice == 0) return choose();

		// otherwise run the function corresponding to the choice
		items[choice-defaultItems].second(*io);

		return choice;

	}

	void Menu::printTitle() {
	/* Prints the title. */
		*io << std::endl << title << std::endl;
		io->outputSeparator();
	}

	void Menu::printItem(const std::string title, const int count) {
	/* Prints an item with a given count. */
		*io << std::setw(3) << std::right << count << ". " << title << std::endl;
	}

} /* namespace SimpleTextUI */
