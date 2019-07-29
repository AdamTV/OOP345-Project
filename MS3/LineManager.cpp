/*
 ============================================================================
 Name          : LineManager.cpp
 Author        : Adam Stinziani
 Email         : astinziani@myseneca.ca
 Student #     : 124 521 188
 Course Code   : OOP345
 Section       : SCC
 Date Created  : 2019-07-16
 Last Modified : 2019-07-29
 Project	   : Milestone 3
 ============================================================================
 */

 /*
  ============================================================================
  Description  : Line manager module for processing orders in assembly line
  ============================================================================
 */

#include <iostream>
#include "LineManager.h"
#include "CustomerOrder.h"

namespace sict {

	LineManager::LineManager(std::vector<Station*>& adrs, std::vector<size_t>&
		idx, std::vector<CustomerOrder>& ords, size_t& strt, std::ostream& os) :
		addresses(adrs),
		indexes(idx),
		start(strt)
	{
		while (!ords.empty()) {
			orders.push_back(std::move(ords.back()));
			ords.pop_back();
		}
		end = indexes.size();
		size = orders.size();
	}

	void LineManager::display(std::ostream& os) const
	{
		auto display = [&](std::vector<CustomerOrder>&& orders) {
			for (auto& i : orders) {
				i.display(os, true);
			}
		};

		os << "COMPLETED ORDERS\n";
		display((std::vector<CustomerOrder>&&)(ordersC));
		os << "INCOMPLETE ORDERS\n";
		display((std::vector<CustomerOrder>&&)ordersI);
	}

	bool LineManager::run(std::ostream& os)
	{
		bool processed = false;
		CustomerOrder tmp;

		if (!orders.empty()) {
			*addresses[start] += std::move(orders.back());
			orders.pop_back();
		}

		for (auto i : addresses)
			i->fill(os);

		for (size_t i = 0; i < addresses.size(); i++) {
			if (addresses[i]->hasAnOrderToRelease() && indexes[i] != end) {
				addresses[i]->pop(tmp);
				*addresses[indexes[i]] += std::move(tmp);
				os << " --> " << tmp.getNameProduct() << " moved from " << addresses[i]->getName() << " to " << addresses[indexes[i]]->getName() << std::endl;
			}
			else if (addresses[i]->hasAnOrderToRelease()) {
				addresses[i]->pop(tmp);
				os << " --> " << tmp.getNameProduct() << " moved from " << addresses[i]->getName() << (tmp.isFilled() ? " to Completed Set\n" : " to Incompleted Set\n");
				if (tmp.isFilled()) {
					ordersC.push_back(std::move(tmp));
					size--;
				}
				else {
					ordersI.push_back(std::move(tmp));
					size--;
				}
			}
		}

		if (size == 0)
			processed = !processed;

		return processed;
	}
}