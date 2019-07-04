/*
 ============================================================================
 Name        : ItemSet.cpp
 Author      : Adam Stinziani
 Email       : astinziani@myseneca.ca
 Student #   : 124 521 188
 Course Code : OOP345
 Section     : SCC
 Date        : 2019-07-03
 Project	 : Milestone 1
 ============================================================================
 */

 /*
  ============================================================================
  Description : ItemSet module for managing the stock inventory of a
				particular item.
  ============================================================================
 */

#include <iostream>
#include <sstream>
#include <iomanip>
#include "ItemSet.h"
#include "Utilities.h"

namespace sict {
	ItemSet::ItemSet(const std::string& str)
	{
		Utilities util;
		quantity = 0;
		serialNumber = 0;
		name = std::string();
		size_t pos = 0;

		name = util.extractToken(str, pos);

		std::string sn = util.extractToken(str, pos);
		std::stringstream s(sn);
		s >> serialNumber;


		std::string q = util.extractToken(str, pos);
		std::stringstream s2(q);
		s2 >> quantity;

		description = util.extractToken(str, pos);
	}
	const std::string& ItemSet::getName() const
	{
		return name;
	}
	const unsigned int ItemSet::getSerialNumber() const
	{
		return serialNumber;
	}
	const unsigned int ItemSet::getQuantity() const
	{
		return quantity;
	}
	ItemSet& ItemSet::operator--()
	{
		quantity--;
		serialNumber++;
		return *this;
	}
	void ItemSet::display(std::ostream& os, bool full) const
	{
		os << std::setw(12) << std::left << name << " [" << std::setfill('0')
			<< serialNumber << "] Quantity " << std::setw(3) << std::setfill(' ')
			<< quantity << " Description: " << description << std::endl;
		//os << name << " " << serialNumber << " " << quantity << " " << description << std::endl;
	}
}