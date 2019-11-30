#include <gtest/gtest.h>
#include "settle_accounts_assistance.h"

/**
 * 对会员实行优惠，会员目前分为两个等级：金卡、银卡。
 * 会员享有折扣优惠。
 * 金卡9折，银卡95折，非会员无折扣。
 * 特价商品不参加折扣。
 * 示例商品单价：
 *    商品编号    商品名称    单价/元    特价商品
 *    000001     雀巢咖啡	  48       Yes
 *    000002     咖啡杯  	  60       No
 *    000003     巧克力	      48.8     No
 *    000004     果粒茶	      118      No
 * 需求澄清：
 * - 只需要计算单个客户的一次消费金额
 * - 一次消费可能包含多个商品
 * - 无需实现商品管理系统
 *
 * 增加购物车，购物和结算分开
 * 增加用户积分
 * 
 */

TEST(The_costs_of_consumption, only_need_to_calculate_the_costs_of_a_consumer_a_time)
{

}

TEST(The_consumption, should_includes_two_parts__adding_commodities_to_shopping_cart_and_settling_accounts_finally)
{
	Consumer consumer(GOLD_MEMBER);
	SettleAccountsAssistance assist(consumer);
	
	assist.shoppingCartAdd(CHOCOLATE, 2);
	assist.shoppingCartAdd(GUO_LI_TEA, 2);
	assist.shoppingCartAdd(NESTLE_COFFEE);
	float costs = assist.settleAccounts();

	float money = 0.9f*(CHOCOLATE.price()*2 + GUO_LI_TEA.price()*2) + NESTLE_COFFEE.price(); //348.24f;

	ASSERT_FLOAT_EQ(costs, money);
}

TEST(Gold_members, could_enjoy_10_percents_discount)
{
	Consumer consumer(GOLD_MEMBER);
	SettleAccountsAssistance assist(consumer);

	assist.shoppingCartAdd(CHOCOLATE);
	float costs = assist.settleAccounts();


	ASSERT_FLOAT_EQ(costs, 0.9f*CHOCOLATE.price());
}

TEST(Silver_members, could_enjoy_5_percents_discount)
{
	Consumer consumer(SILVER_MEMBER);
	SettleAccountsAssistance assist(consumer);

	assist.shoppingCartAdd(CHOCOLATE);
	float costs = assist.settleAccounts();

	ASSERT_FLOAT_EQ(costs, 0.95f*CHOCOLATE.price());
}

TEST(Common_members, could_not_enjoy_any_discount)
{
	Consumer consumer(COMMON_MEMBER);
	SettleAccountsAssistance assist(consumer);

	assist.shoppingCartAdd(CHOCOLATE);
	float costs = assist.settleAccounts();

	ASSERT_FLOAT_EQ(costs, CHOCOLATE.price());
}

TEST(Special_price_goods, could_not_be_considered_when_make_discount)
{
	Consumer consumer1(GOLD_MEMBER);
	Consumer consumer2(SILVER_MEMBER);

	SettleAccountsAssistance assist(consumer1);
	assist.shoppingCartAdd(NESTLE_COFFEE);
	float costs1 = assist.settleAccounts();

	ASSERT_FLOAT_EQ(costs1, NESTLE_COFFEE.price());


	assist.signUpNewMember(consumer2);
	assist.shoppingCartAdd(NESTLE_COFFEE);
	float costs2 = assist.settleAccounts();

	ASSERT_FLOAT_EQ(costs2, NESTLE_COFFEE.price());
}

TEST(The_costs_of_commodities, should_be_stored_as_the_member_points_of_consumers)
{
	Consumer consumer(GOLD_MEMBER);
	SettleAccountsAssistance assist(consumer);

	assist.shoppingCartAdd(CHOCOLATE, 2);
	assist.shoppingCartAdd(GUO_LI_TEA, 2);
	assist.shoppingCartAdd(NESTLE_COFFEE);
	float costs = assist.settleAccounts();

	float points = consumer.getMemberPoints(); //348.24f;

	ASSERT_FLOAT_EQ(costs, points);
}

TEST(The_member_points_of_a_consumer, should_be_cumulated_after_each_consumption)
{
	Consumer consumer(GOLD_MEMBER);
	SettleAccountsAssistance assist(consumer);

	assist.shoppingCartAdd(CHOCOLATE, 2);
	assist.shoppingCartAdd(GUO_LI_TEA, 2);
	assist.shoppingCartAdd(NESTLE_COFFEE);
	float costs1 = assist.settleAccounts();

	assist.shoppingCartAdd(CHOCOLATE);
	assist.shoppingCartAdd(COFFEE_CUP);
	assist.shoppingCartAdd(NESTLE_COFFEE);
	float costs2 = assist.settleAccounts();

	float points = consumer.getMemberPoints(); //348.24f;

	ASSERT_FLOAT_EQ(costs1+costs2, points);
}