/*
 ============================================================================
 Name          : Station.cpp
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
  Description  : Station module for filling customer orders with items
  ============================================================================
 */

#include <iostream>
#include "Station.h"

namespace sict {
	Station::Station(const std::string& str) : items(ItemSet(str))
	{
		name = getName();
	}
	void Station::display(std::ostream& os) const
	{
		items.display(os, true);
	}
	void Station::fill(std::ostream& os)
	{
		if (!custOrders.empty())
			custOrders.back().fillItem(items, os);
	}
	const std::string& Station::getName() const
	{
		return items.getName();
	}
	bool Station::hasAnOrderToRelease() const
	{
		bool has = false;
		if(!custOrders.empty()) {
			if (items.getQuantity() < 1)
				has = true;
			else
				has = custOrders.front().isItemFilled(getName());
		}
		return has;
	}
	Station& Station::operator--()
	{
		items.operator--();
		return *this;
	}
	Station& Station::operator+=(CustomerOrder&& order)
	{
		custOrders.push(std::move(order));
		return *this;
	}
	bool Station::pop(CustomerOrder& ready)
	{
		bool filled = false;
		if (!custOrders.empty()) {
			ready = std::move(custOrders.front());
			filled = ready.isItemFilled(getName());
			custOrders.pop();
		}
		return filled;
	}
	void Station::validate(std::ostream& os) const
	{
		os << " getName(): " << items.getName() << std::endl;
		os << " getSerialNumber(): " << items.getSerialNumber() << std::endl;
		os << " getQuantity(): " << items.getQuantity() << std::endl;
	}
}