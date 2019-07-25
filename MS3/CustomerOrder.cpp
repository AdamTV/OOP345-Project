/*
 ============================================================================
 Name          : CustomerOrder.cpp
 Author        : Adam Stinziani
 Email         : astinziani@myseneca.ca
 Student #     : 124 521 188
 Course Code   : OOP345
 Section       : SCC
 Date Created  : 2019-07-16
 Last Modified : 2019-07-25
 Project	   : Milestone 3
 ============================================================================
 */

 /*
  ============================================================================
  Description  : Customer Order module for handling customer orders
  ============================================================================
 */

#include <algorithm>
#include <iostream>
#include <iomanip>
#include "CustomerOrder.h"

namespace sict {

	// default constructor to set safe empty state
	//
	CustomerOrder::CustomerOrder()
	{
		currentItems = nullptr;
		custName = prodName = std::string();
		currentNumItems = 0;
		util = Utilities();
	}

	// custom constructor to set member values
	//
	CustomerOrder::CustomerOrder(const std::string& str)
	{
		std::vector<std::string> items;
		size_t pos = 0;
		custName = util.extractToken(str, pos);
		if (custName.length() > util.getFieldWidth())
			util.setFieldWidth(custName.length());
		prodName = util.extractToken(str, pos);
		int numItems = std::count(str.begin(), str.end(), util.getDelimiter()) - 1;
		if (numItems > 0) {
			for (auto i = 0; i < numItems; i++)
				items.push_back(util.extractToken(str, pos));
		}
		else {
			throw "no items requested to be added";
		}

		currentItems = new ItemInfo[numItems];
		currentNumItems = numItems;
		for (auto i = 0; i < numItems; i++) {
			currentItems[i].itemName = items[i];
			currentItems[i].fullfilled = false;
		}
	}

	// destructor to deallocate any allocated memory
	//
	CustomerOrder::~CustomerOrder()
	{
		delete[] currentItems;
		currentItems = nullptr;
	}

	// move constructor to move an object near end of lifetime
	//
	CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept
	{
		currentItems = nullptr;
		*this = std::move(src);
	}

	// move operator to move object near end of lifetime
	//
	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) noexcept
	{
		if (this != &src) {
			delete[] currentItems;
			currentNumItems = src.currentNumItems;
			currentItems = src.currentItems;
			custName = src.custName;
			prodName = src.prodName;
			src.currentItems = nullptr;
			src.currentNumItems = 0;
			src.custName = { '\n' };
			src.prodName = { '\n' };
		}
		return *this;
	}

	// checks each item request against item and handles accordingly
	//
	void CustomerOrder::fillItem(ItemSet& item, std::ostream& os)
	{
		if (item.getQuantity() != 0) {
			for (unsigned int i = 0; i < currentNumItems; i++) {
				if (currentItems[i].itemName == item.getName()) {
					if (!currentItems[i].fullfilled) {
						currentItems[i].itemNumber = item.getSerialNumber();
						currentItems[i].fullfilled = true;
						--item;
						os << " Filled " << getNameProduct() << "["
							<< item.getName() << "][" << currentItems[i].itemNumber << "]\n";
					}
					else {
						os << " Unable to fill " << getNameProduct() << "["
							<< item.getName() << "][" << currentItems[i].itemNumber << "] already filled\n";
					}
				}
			}
		}
		else {
			os << " Unable to fill " << getNameProduct() << "["
				<< item.getName() << "][" << item.getSerialNumber() << "] out of stock\n";
		}
	}

	// checks if all item requests are filled
	//
	bool CustomerOrder::isFilled() const
	{
		bool filled = true;
		for (unsigned int i = 0; i < currentNumItems; i++) {
			if (!currentItems[i].fullfilled)
				filled = false;
		}
		return filled;
	}

	// checks if all item requests of certain name have been filled
	//
	bool CustomerOrder::isItemFilled(const std::string& item) const
	{
		bool filled = true;
		for (unsigned int i = 0; i < currentNumItems; i++) {
			if (currentItems[i].itemName == item && !currentItems[i].fullfilled)
				filled = false;
		}
		return filled;
	}

	// concatenate name of customer and their product
	//
	std::string CustomerOrder::getNameProduct() const
	{
		return custName + " [" + prodName + "]";
	}

	// display customer order object to any ostream&
	//
	void CustomerOrder::display(std::ostream& os, bool showDetail)
	{
		auto FW = std::setw(util.getFieldWidth() + 1);
		if (!showDetail) {
			os << FW << custName << '[' << prodName << "]\n";
			for (unsigned int i = 0; i < currentNumItems; i++) {
				os << FW << " " << currentItems[i].itemName << '\n';
			}
		}
		else {
			os << FW << custName << '[' << prodName << "]\n";
			for (unsigned int i = 0; i < currentNumItems; i++) {
				os << FW << " " << '[' << currentItems[i].itemNumber << "] " 
					<< currentItems[i].itemName << '-' << (currentItems[i].fullfilled ? "Filled" : "Not Filled");
			}
		}
	}

}
