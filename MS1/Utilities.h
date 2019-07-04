#ifndef SICT_UTILITIES_H
#define SICT_UTILITIES_H
/*
 ============================================================================
 Name        : Utilities.h
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

#include <string>

namespace sict {
	class Utilities {
		static char delimiter;
		size_t fieldWidth;
	public:
		Utilities();
		const std::string extractToken(const std::string& str, size_t& next_pos);
		const char getDelimiter() const;
		size_t getFieldWidth() const;
		static void setDelimiter(const char d);
		void setFieldWidth(size_t);
	};
}

#endif // !SICT_UTILITIES_H

