/*
 ============================================================================
 Name          : LineManager.h
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
  Description  : Line manager module for processing orders in assembly line 
  ============================================================================
 */

#include <vector>
#include "Station.h"

namespace sict {
	class LineManager {
	private:
		std::vector<Station*> addresses;
		std::vector<size_t> indexes;
		std::vector<CustomerOrder> orders, ordersC, ordersI;
		size_t start, end, size;
	public:
		LineManager(std::vector<Station*>& adr,std::vector<size_t>&
			idx, std::vector<CustomerOrder>&, size_t& aidx, std::ostream& os);
		void display(std::ostream& os) const;
		bool run(std::ostream& os);
	};
}