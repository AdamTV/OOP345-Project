/*
 ============================================================================
 Name          : Utilities.cpp
 Author        : Adam Stinziani
 Email         : astinziani@myseneca.ca
 Student #     : 124 521 188
 Course Code   : OOP345
 Section       : SCC
 Date Created  : 2019-07-03
 Last Modified : 2019-07-25
 Project	   : Milestone 3
 ============================================================================
 */

 /*
  ============================================================================
  Description : Utilities module with functionality common across system.
  ============================================================================
 */

#include <string>
#include "Utilities.h"

namespace sict {

	char Utilities::delimiter;
	size_t Utilities::fieldWidth;

	// custom constructor to initialize member values
	//
	Utilities::Utilities() {}

	// method to extract token and increase current position
	//
	const std::string Utilities::extractToken(const std::string& str, size_t& next_pos)
	{
		std::string tmp = str.substr(next_pos);
		size_t nextPos = tmp.find(delimiter);

		std::string token = tmp.substr(0, nextPos);
		if (nextPos != std::string::npos) {
			nextPos++;
			next_pos += nextPos;
		}
		else {
			next_pos = nextPos;
		}

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