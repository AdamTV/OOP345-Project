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

#include "LineManager.h"

namespace sict {
	LineManager::LineManager(std::vector<Station*>& adrs, std::vector<size_t>
		idxs, std::vector<CustomerOrder> ords, size_t aidx, std::ostream& os)
	{

	}
	void LineManager::display(std::ostream& os) const
	{
	}
	bool LineManager::run(std::ostream& os)
	{
		return false;
	}
}