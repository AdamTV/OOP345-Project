/*
 ============================================================================
 Name          : ItemSet.cpp
 Author        : Adam Stinziani
 Email         : astinziani@myseneca.ca
 Student #     : 124 521 188
 Course Code   : OOP345
 Section       : SCC
 Date Created  : 2019-07-03
 Last Modified : 2019-07-10
 Project	   : Milestone 1
 ============================================================================
 */

 /*
  ============================================================================
  Description  : ItemSet module for managing stock inventory of certain item.
  ============================================================================
 */

#include <iostream>
#include <sstream>
#include <iomanip>
#include "ItemSet.h"
#include "Utilities.h"

namespace sict {

	// custom constructor to initialize member values
	//
	ItemSet::ItemSet(const std::string& str)
	{
		quantity = 0;
		serialNumber = 0;
		name = std::string();
		size_t pos = 0;

		// lambda to extract integer with extractToken
		//
		auto extractInt = [&](unsigned int& num, size_t& pos) {
			std::string sn = util.extractToken(str, pos);
			std::stringstream s(sn);
			s >> num;
		};

		name = util.extractToken(str, pos);
		extractInt(serialNumber, pos);
		extractInt(quantity, pos);
		description = util.extractToken(str, pos);

		if (name.length() > util.getFieldWidth())
			util.setFieldWidth(name.length());
		
	}
	
	// query to get name of ItemSet object
	//
	const std::string& ItemSet::getName() const
	{
		return name;
	}

	// query to get serial number of ItemSet object
	//
	const unsigned int ItemSet::getSerialNumber() const
	{
		return serialNumber;
	}

	// query to get quantity of ItemSet object
	//
	const unsigned int ItemSet::getQuantity() const
	{
		return quantity;
	}

	// operator to manually change data members
	//
	ItemSet& ItemSet::operator--()
	{
		quantity--;
		serialNumber++;
		return *this;
	}

	// query to display ItemSet object to any ostream&
	//
	void ItemSet::display(std::ostream& os, bool full) const
	{
		if(full)
		os << std::setw(util.getFieldWidth()) << std::left << name << " [" 
			<< std::setfill('0') << serialNumber << "] Quantity " 
			<< std::setw(3) << std::setfill(' ') << quantity 
			<< " Description: " << description << std::endl;
	}

	// move constructor for STL container
	//
	ItemSet::ItemSet(ItemSet&& src) noexcept
	{
		if (this != &src)
		{
			name = src.name;
			description = src.description;
			serialNumber = src.serialNumber;
			quantity = src.quantity;

			src.name = { "" };
			src.description = { "" };
			src.serialNumber = { 0 };
			src.quantity = { 0 };
		}
	}

}