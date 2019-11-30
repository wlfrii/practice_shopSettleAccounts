#pragma once
#include <array>

class Commodity
{
public:
	static const Commodity& NestleCoffee();
	static const Commodity& CoffeeCup();
	static const Commodity& Chocolate();
	static const Commodity& GuoLiTea();

	float price() const
	{
		return m_price;
	}

	bool operator==(const Commodity & commodity) const;

private:
	Commodity(std::array<int, 6> bar_code, float price)
		: m_bar_code(bar_code)
		, m_price(price)
	{}
	
private:
	enum{ BAR_CODE_BITS = 6 };
	std::array<int, BAR_CODE_BITS> m_bar_code;
	float m_price;
};

#define NESTLE_COFFEE ( Commodity::NestleCoffee() )
#define COFFEE_CUP ( Commodity::CoffeeCup() )
#define CHOCOLATE ( Commodity::Chocolate() )
#define GUO_LI_TEA ( Commodity::GuoLiTea() )