/*
 ============================================================================
 Name        : Utilities.cpp
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
  Description : Utilities module that contains functionality which is common
				across the system.
  ============================================================================
 */

#include "Utilities.h"

namespace sict {

	char Utilities::delimiter;

	// custom constructor to initialize member values
	//
	Utilities::Utilities() : fieldWidth(-1)
	{
	}

	// method to extract token and increase current position
	//
	const std::string Utilities::extractToken(const std::string& str, size_t& next_pos)
	{
		std::string tmp = str.substr(next_pos);
		std::string token = tmp.substr(0, tmp.find(delimiter));

		if (token.length() > fieldWidth)
			fieldWidth = token.length();

		next_pos += tmp.find(delimiter) + 1;

		return token;
	}

	// query to get delimiter of all Utilities objects
	//
	const char Utilities::getDelimiter() const
	{
		return Utilities::delimiter;
	}

	// query to get field width of current Utilities object
	//
	size_t Utilities::getFieldWidth() const
	{
		return fieldWidth;
	}

	// static method to set delimiter of all Utilities objects
	//
	void Utilities::setDelimiter(const char d)
	{
		Utilities::delimiter = d;
	}

	// method to set field width of current Utilities object
	//
	void Utilities::setFieldWidth(size_t w)
	{
		fieldWidth = w;
	}
}