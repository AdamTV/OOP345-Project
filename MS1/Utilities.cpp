/*
 ============================================================================
 Name          : Utilities.cpp
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
  Description : Utilities module with functionality common across system.
  ============================================================================
 */

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
		std::string token = tmp.substr(0, tmp.find(delimiter));
		
		//token length can't be checked here or field width incorrect

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