#include "settle_accounts_assistance.h"
#include <cmath>

SettleAccountsAssistance::SettleAccountsAssistance(Consumer & _consumer)
	: special_price_commodity(NESTLE_COFFEE)
	, total_costs(0)
	, consumer(_consumer)
{
}

SettleAccountsAssistance::~SettleAccountsAssistance()
{
}

void SettleAccountsAssistance::signUpNewMember(Consumer & new_consumer)
{
	consumer = new_consumer;
}

void SettleAccountsAssistance::shoppingCartAdd(const Commodity & commodity, unsigned int number)
{
	if (isSpecialPriceCommodity(commodity))
		total_costs += commodity.price() * number;
	else
		total_costs += commodity.price() * consumer.getDiscountsRatio() * number;
}

float SettleAccountsAssistance::settleAccounts()
{
	increaseMemberPoints();
	float costs = total_costs;
	total_costs = 0;
	return costs;
}

bool SettleAccountsAssistance::isSpecialPriceCommodity(const Commodity & commodity) const
{
	if (commodity == special_price_commodity)
		return true;
	return false;
}


// friend function
void SettleAccountsAssistance::increaseMemberPoints()
{
	consumer.member_points += total_costs;
}
