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
 Last Modified : 2019-07-16
 Project	   : Milestone 2
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
		std::string custName, prodName;
		//const struct ItemSet {
		//	bool fullfilled = false;
		//}ItemInfo[];
	public:
		CustomerOrder();
		CustomerOrder(const std::string& str);
		~CustomerOrder();
		CustomerOrder(CustomerOrder&&);
		CustomerOrder& operator=(CustomerOrder&&);
		void fillItem(ItemSet& item, std::ostream& os);
		bool isFilled() const;
		bool isItemFilled(const std::string& item) const;
		std::string getNameProduct() const;
		void display(std::ostream& os, bool showDetail = false);

		CustomerOrder(const CustomerOrder&) = delete;
		CustomerOrder& operator=(const CustomerOrder&) = delete;
	};
}
#endif // !SICT_CUSTOMER_ORDER_H