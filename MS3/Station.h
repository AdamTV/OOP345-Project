#ifndef SICT_STATION_H
#define SICT_STATION_H
/*
 ============================================================================
 Name          : Station.h
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
  Description  : Station module for filling customer orders with items
  ============================================================================
 */

#include <queue>
#include "CustomerOrder.h"
#include "ItemSet.h"

namespace sict {
	class Station {
		std::queue<CustomerOrder> custOrders;
		ItemSet items;
		std::string name;
	public:
		Station(const std::string& str);
		void display(std::ostream& os) const;
		void fill(std::ostream& os);
		const std::string& getName() const;
		bool hasAnOrderToRelease() const;
		Station& operator--();
		Station& operator+=(CustomerOrder&& order);
		bool pop(CustomerOrder& ready);
		void validate(std::ostream& os) const;
		ItemSet& getItems() { return items; }

		Station(const Station&) = delete;
		Station(Station&&) = delete;
		Station& operator=(const Station&) = delete;
		Station& operator=(Station&&) = delete;
	};
}

#endif // !SICT_STATION_H
