/*
 ============================================================================
 Name          : CustomerOrder.cpp
 Author        : Adam Stinziani
 Email         : astinziani@myseneca.ca
 Student #     : 124 521 188
 Course Code   : OOP345
 Section       : SCC
 Date Created  : 2019-07-16
 Last Modified : 2019-07-16
 Project	   : Milestone 2
 ============================================================================
 */

 /*
  ============================================================================
  Description  : Customer Order module for handling customer orders
  ============================================================================
 */

#include "CustomerOrder.h"

namespace sict {
	CustomerOrder::CustomerOrder()
	{
		custName = std::string();
	}
	CustomerOrder::CustomerOrder(const std::string& str)
	{
		size_t pos = 0;
		Utilities util;
		custName = util.extractToken(str, pos);
		prodName = util.extractToken(str, pos);
		if (pos < str.length()) {
			while (pos < str.length()) {

			}
		}
		else {
			throw "no items requested to be added";
		}
	}
	CustomerOrder::~CustomerOrder()
	{
	}
	CustomerOrder::CustomerOrder(CustomerOrder&&)
	{
	}
	CustomerOrder& CustomerOrder::operator=(CustomerOrder&&)
	{
		return *this;
	}
	void CustomerOrder::fillItem(ItemSet& item, std::ostream& os)
	{
	}
	bool CustomerOrder::isFilled() const
	{
		return false;
	}
	bool CustomerOrder::isItemFilled(const std::string& item) const
	{
		return false;
	}
	std::string CustomerOrder::getNameProduct() const
	{
		return std::string();
	}
	void CustomerOrder::display(std::ostream& os, bool showDetail)
	{
	}
}