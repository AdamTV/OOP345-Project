#ifndef SICT_ITEMSET_H
#define SICT_ITEMSET_H
/*
 ============================================================================
 Name        : ItemSet.h
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
  Description : ItemSet module for managing the stock inventory of a particular item.
  ============================================================================
 */

#include <string>

namespace sict {
	class ItemSet {
		std::string name;
		std::string description;
		unsigned int serialNumber;
		unsigned int quantity;
	public:
		ItemSet(const std::string& str);
		const std::string& getName() const;
		const unsigned int getSerialNumber() const;
		const unsigned int getQuantity() const;
		ItemSet& operator--();
		void display(std::ostream& os, bool full) const;
	};
}

#endif // !SICT_ITEMSET_H
