#ifndef SICT_ITEMSET_H
#define SICT_ITEMSET_H
/*
 ============================================================================
 Name          : ItemSet.h
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

#include <string>
#include "Utilities.h"

namespace sict {
	class ItemSet {
		std::string name;
		std::string description;
		unsigned int serialNumber;
		unsigned int quantity;
		Utilities util;
	public:
		ItemSet();
		ItemSet(const std::string& str);
		const std::string& getName() const;
		const unsigned int getSerialNumber() const;
		const unsigned int getQuantity() const;
		ItemSet& operator--();
		void display(std::ostream& os, bool full) const;
		ItemSet(ItemSet&& src) noexcept;

		ItemSet& operator=(ItemSet&&) = delete;
		ItemSet& operator=(const ItemSet&) = delete;
		ItemSet(const ItemSet&) = delete;
	};
}

#endif // !SICT_ITEMSET_H
