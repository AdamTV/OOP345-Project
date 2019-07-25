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

#include "Station.h"

namespace sict {
	Station::Station(const std::string& str) : items(ItemSet(str))
	{
		name = getName();
	}
	void Station::display(std::ostream& os) const
	{
		items.display(os, false);
	}
	void Station::fill(std::ostream& os)
	{
		if (!custOrders.empty()) {
			//int size = custOrders.size() - 1;
			//CustomerOrder& theOrder = std::move(custOrders[size]);
			//theOrder.fillItem(items, os);
		}
	}
	const std::string& Station::getName() const
	{
		return items.getName();
	}
	bool Station::hasAnOrderToRelease() const
	{
		bool has = false;

		if (items.getQuantity() > 1)
			has = true;

		return has;
	}
	Station& Station::operator--()
	{
		items.operator--();
		return *this;
	}
	Station& Station::operator+=(CustomerOrder&& order)
	{
		custOrders.push(order);
		return *this;
	}
	bool Station::pop(CustomerOrder& ready)
	{
		bool filled = false;
		//CustomerOrder& theOrder = custOrders.front();

		custOrders.pop();
		//ready = std::move(theOrder);

		if (ready.isFilled())
			filled = true;

		return filled;
	}
	void Station::validate(std::ostream& os) const
	{
		items.display(os, false);
	}
}