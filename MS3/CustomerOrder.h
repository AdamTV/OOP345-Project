#ifndef SICT_CUSTOMER_ORDER_H
#define SICT_CUSTOMER_ORDER_H
/*
 ============================================================================
 Name          : CustomerOrder.h
 Author        : Adam Stinziani
 Email         : astinziani@myseneca.ca
 Student #     : 124 521 188
 Course Code   : OOP345
 Section       : SCC
 Date Created  : 2019-07-16
 Last Modified : 2019-07-25
 Project	   : Milestone 3
 ============================================================================
 */

 /*
  ============================================================================
  Description  : Customer Order module for handling customer orders
  ============================================================================
 */

#include <string>
#include <vector>
#include "ItemSet.h"


namespace sict {
	class CustomerOrder {
		Utilities util;
		std::string custName, prodName;
		unsigned int currentNumItems;
		struct ItemInfo {
			bool fullfilled = false;
			std::string itemName;
			unsigned int itemNumber;
		};
		ItemInfo* currentItems;
	public:
		CustomerOrder();
		CustomerOrder(const std::string& str);
		~CustomerOrder();
		CustomerOrder(CustomerOrder&&) noexcept;
		CustomerOrder& operator=(CustomerOrder&&) noexcept;
		void fillItem(ItemSet& item, std::ostream& os);
		bool isFilled() const;
		bool isItemFilled(const std::string& item) const;
		std::string getNameProduct() const;
		void display(std::ostream& os, bool showDetail = false);

		//CustomerOrder(const CustomerOrder&) = delete;
		//CustomerOrder& operator=(const CustomerOrder&) = delete;
	};
}
#endif // !SICT_CUSTOMER_ORDER_H