#include "commodity.h"


const Commodity& Commodity::NestleCoffee()
{
	static Commodity nestle_coffee( { 0,0,0,0,0,1 }, 48.0f);
	return nestle_coffee;
}

const Commodity& Commodity::CoffeeCup()
{
	static Commodity coffee_cup( { 0,0,0,0,0,2 }, 60.0f);
	return coffee_cup;
}

const Commodity& Commodity::Chocolate()
{
	static Commodity chocolate( { 0,0,0,0,0,3 },48.8f);
	return chocolate;
}

const Commodity& Commodity::GuoLiTea()
{
	static Commodity guo_li_tea( { 0,0,0,0,0,4 },118.0f);
	return guo_li_tea;
}


bool Commodity::operator==(const Commodity & commodity) const
{
	for (int i = static_cast<int>(BAR_CODE_BITS) - 1; i >= 0; i--)
		if (this->m_bar_code[i] != commodity.m_bar_code[i])
			return false;
	return true;
}