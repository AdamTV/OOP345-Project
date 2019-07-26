/*
 ============================================================================
 Name          : LineManager.cpp
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
		end = indexes.back();
	}
	void LineManager::display(std::ostream& os) const
	{
		auto display = [&](bool filled) {
			for (auto& i : orders) {
				if (filled ? i.isFilled() : !i.isFilled())
					const_cast<CustomerOrder&>(i).display(os, true);
			}
		};
		os << "COMPLETED ORDERS\n";
		display(true);
		os << "INCOMPLETE ORDERS\n";
		display(false);
	}
	bool LineManager::run(std::ostream& os)
	{
		bool processed = true;

		if (!orders.empty()) {
			CustomerOrder&& theOrder = std::move(orders.back());

			Station*& theAddress = addresses.back();

			theOrder.fillItem(theAddress->getItems(), os);
			
			os << "--> " << theOrder.getNameProduct() << " moved from " <<
				theAddress->getItems().getName() << " to " << theOrder.getItemName();
		}

		return processed;
		//bool done = false;
		//CustomerOrder temp;

		//if (!orders.empty())
		//{
		//	*addresses[start] += std::move(orders.back());
		//	orders.pop_back();
		//}

		//try
		//{
		//	for (size_t i = 0; i != indexes.size(); ++i)
		//		addresses[i]->fill(os);

		//	for (size_t i = 0; i < addresses.size(); ++i)
		//	{
		//		bool hasOrderForRelease = addresses[i]->hasAnOrderToRelease();
		//		bool isTheLastStation = indexes[i] == end;

		//		if (hasOrderForRelease && isTheLastStation)
		//		{
		//			addresses[i]->pop(temp);

		//			if (temp.isFilled())
		//			{
		//				os << " --> " << temp.getNameProduct() << " moved from " << addresses[i]->getName() << " to Completed Set" << std::endl;
		//				orders.push_back(std::move(temp));
		//				size--;
		//			}
		//			else
		//			{
		//				os << " --> " << temp.getNameProduct() << " moved from " << addresses[i]->getName() << " to Incompleted Set" << std::endl;
		//				orders.push_back(std::move(temp));
		//				size--;
		//			}
		//		}
		//		if (hasOrderForRelease && !isTheLastStation)
		//		{
		//			addresses[i]->pop(temp);
		//			os << " --> " << temp.getNameProduct() << " moved from " << addresses[i]->getName() << " to " << addresses[indexes[i]]->getName() << std::endl;

		//			*addresses[indexes[i]] += std::move(temp);
		//		}
		//	}
		//}
		//catch (const std::exception& e)
		//{
		//	e.what();
		//}

		//if (size == 0)
		//	done = true;
		//else
		//	done = false;

		//return done;
	}
}