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

	// custom constructor to set data members
	//
	Station::Station(const std::string& str) : items(ItemSet(str))
	{
		name = getName();
	}

	// method to display items object to any ostream
	//
	void Station::display(std::ostream& os) const
	{
		items.display(os, true);
	}

	// method to fill the last order in the customer order queue
	//
	void Station::fill(std::ostream& os)
	{
		if (!custOrders.empty())
			custOrders.back().fillItem(items, os);
	}

	// forwarding query to get reference to name of items object
	//
	const std::string& Station::getName() const
	{
		return items.getName();
	}

	// query that returns the release state of the current object
	//
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

	// decrements number of items in items object
	//
	Station& Station::operator--()
	{
		items.operator--();
		return *this;
	}

	// moves rvalue reference to the back of the station's queue
	//
	Station& Station::operator+=(CustomerOrder&& order)
	{
		custOrders.push(std::move(order));
		return *this;
	}

	// removes order at the front of queue moves it to calling function
	//
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

	// reports the state of the items object
	//
	void Station::validate(std::ostream& os) const
	{
		os << " getName(): " << items.getName() << std::endl;
		os << " getSerialNumber(): " << items.getSerialNumber() << std::endl;
		os << " getQuantity(): " << items.getQuantity() << std::endl;
	}
}