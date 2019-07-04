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

	Utilities::Utilities() : fieldWidth(-1)
	{
	}
	const std::string Utilities::extractToken(const std::string& str, size_t& next_pos)
	{
		std::string tmp = str.substr(next_pos);
		std::string token = tmp.substr(0, tmp.find(delimiter));

		if (token.length() > fieldWidth)
			fieldWidth = token.length();

		next_pos += tmp.find(delimiter) + 1;

		return token; //.find(delimiter)
	}
	const char Utilities::getDelimiter() const
	{
		return Utilities::delimiter;
	}
	size_t Utilities::getFieldWidth() const
	{
		return fieldWidth;
	}
	void Utilities::setDelimiter(const char d)
	{
		Utilities::delimiter = d;
	}
	void Utilities::setFieldWidth(size_t w)
	{
		fieldWidth = w;
	}
}