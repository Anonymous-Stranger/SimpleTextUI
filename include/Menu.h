/*
 * menu.h
 *
 *  Created on: Aug 17, 2015
 *      Author: Akash
 */

#ifndef SIMPLE_TEXT_UI_MENU_H_
#define SIMPLE_TEXT_UI_MENU_H_

#include <functional>
#include <vector>
#include <iomanip>
#include "IOObj.h"
#include "input.h"

namespace SimpleTextUI {

class Menu {

public:
	using MenuItemFunc = std::function<void(IOObj&)>;
	using MenuItem = std::pair<std::string, MenuItemFunc>;

	Menu(std::vector<MenuItem> items={}): Menu(new IOObj{}, items) {}
	Menu(std::vector<MenuItem> items, std::string title): Menu(new IOObj{}, items, title) {}
	Menu(IOObj* io, std::vector<MenuItem> items={}): Menu(io, true, items) {}
	Menu(IOObj& io, std::vector<MenuItem> items={}): Menu(&io, false, items) {}
	Menu(IOObj* io, std::vector<MenuItem> items, std::string title): Menu(io, true, items, title) {}
	Menu(IOObj& io, std::vector<MenuItem> items, std::string title): Menu(&io, false, items, title) {}

	Menu(const Menu&)=delete;
	Menu& operator=(const Menu&)=delete;

	~Menu() { releaseIO(); }

	void choose();

	const std::string& getTitle() const { return title; }
	void setTitle(std::string title) { this->title = title; }

	const std::vector<MenuItem>& getItems() const { return items; }
	void setItems(const std::vector<MenuItem>& items) { this->items = items; }
	void addItem(std::string s, MenuItemFunc f) { items.push_back({s, f}); }
	void clearItems() { items.clear(); }

	IOObj& getIOObj() { return *io; } // intentionally modifiable

	void setIOObj(IOObj& io);
	void setIOObj(IOObj* io);

protected:
	std::vector<MenuItem> items;
	std::string title;

	Menu(Menu&&)=default;
	Menu& operator=(Menu&&)=default;

	void printTitle();
	void printItem(const std::string title, const int count);
private:
	const static std::string showMenuTitle;
	const static std::string chooseMessage;

	IOObj* io;
	bool owner;

	Menu(IOObj* io, bool owner, std::vector<MenuItem> items, std::string title="Menu"):
		io{io}, owner{owner}, items{items}, title{title} {}

	void releaseIO() { if (owner) delete io; }
};

} /* namespace SimpleTextUI */

#endif /* MENU_H_ */
