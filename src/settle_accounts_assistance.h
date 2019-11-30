#pragma once
#include <type_traits>
#include "commodity.h"
#include "consumer.h"

class SettleAccountsAssistance
{
private:
	friend class Consumer;
public:
	SettleAccountsAssistance(Consumer &);
	~SettleAccountsAssistance();

	void  signUpNewMember(Consumer &);

	void  shoppingCartAdd(const Commodity &, unsigned int number = 1);
	float settleAccounts();
	
private:
	bool isSpecialPriceCommodity(const Commodity &) const;

	// friend function. To increase the member points of a consumer
	void increaseMemberPoints();

private:
	Consumer	&consumer;
	Commodity	special_price_commodity;
	float		total_costs;
};
