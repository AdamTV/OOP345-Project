#ifndef SICT_UTILITIES_H
#define SICT_UTILITIES_H
/*
 ============================================================================
 Name          : Utilities.h
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

#include <string>

namespace sict {
	class Utilities {
		static char delimiter;
		static size_t fieldWidth;
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

