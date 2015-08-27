/*
 * menu.cpp
 *
 *  Created on: Aug 17, 2015
 *      Author: Akash
 */

#include "Menu.h"

namespace SimpleTextUI {

	const std::string Menu::showMenuTitle {"Display Menu"};
	const std::string Menu::chooseMessage {"Choose one: "};

	void Menu::choose() {

		printTitle();

		int defaultItems {0};
		printItem(showMenuTitle, defaultItems++);

		int count {defaultItems};
		for (MenuItem& i : items) printItem(i.first, count++);
		io->outputSeparator();

		int choice {input<int>(*io, chooseMessage, [count](int i)->bool{ return  0 <= i && i < count; })};
		*io << std::endl;

		if (choice == 0) choose();

		else items[choice-defaultItems].second(*io);

	}

	void Menu::printTitle() {
		*io << std::endl << title << std::endl;
		io->outputSeparator();
	}

	void Menu::printItem(const std::string title, const int count) {
		*io << std::setw(3) << std::right << count << ". " << title << std::endl;
	}

} /* namespace SimpleTextUI */
