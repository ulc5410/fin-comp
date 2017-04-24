#include "Group.h"

Group::Group()
{

}

Group::~Group()
{
}

bool Group::pushStock(Stock s)
{
	stocks[s.getTicker()] = s;
	return true;
}

bool Group::compute()
{
	double re_turnSum = 0;
	for (auto j = stocks.begin(); j != stocks.end(); j++)
		re_turnSum += j->second.re_turn;
	AAR[0] = re_turnSum / stocks.size() - SPY.re_turn[i];
	CAAR[0] = AAR[0];
	for (int i = 1; i < AAR.size(); i++)
	{
		double re_turnSum = 0;
		for (auto j = stocks.begin(); j != stocks.end(); j++)
			re_turnSum += j->second.re_turn;
		AAR[i] = re_turnSum / stocks.size() - SPY.re_turn[i];
		CAAR[i] = CAAR[i - 1] + AAR[i];
	}
}