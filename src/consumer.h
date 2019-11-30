#pragma once
#include "settle_accounts_assistance.h"

enum MembershipLevel
{
	GOLD_MEMBER = 90,
	SILVER_MEMBER = 95,
	COMMON_MEMBER = 100
};


class Consumer
{
private:
	friend class SettleAccountsAssistance;
public:
	Consumer(MembershipLevel level)
		: member_points(0)
		, membership_level(level)
	{}

	const float getDiscountsRatio() const
	{
		return static_cast<float>(membership_level) / 100.0f;
	}

	float getMemberPoints() const
	{
		return member_points;
	}

private:
	float			member_points;
	MembershipLevel	membership_level;
};