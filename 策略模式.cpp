#if 0
#include<iostream>

class WeaponStrategy {
public:
	virtual void useWeapon() = 0;
};

class AK47 : public WeaponStrategy{
public:
	virtual void useWeapon()
	{
		std::cout << "use AK47" << std::endl;
	}
};

class Knife : public WeaponStrategy {
public:
	virtual void useWeapon()
	{
		std::cout << "use Knife" << std::endl;
	}
};

class Character {
public:
	void setWeapon(WeaponStrategy* wStrategy)
	{
		this->wStrategy = wStrategy;
	}
	void Fight()
	{
		wStrategy->useWeapon();
	}
private:
	WeaponStrategy* wStrategy;
};

//class CharacterKnife {
//public:
//	void Fight()
//	{
//		knife->useWeapon();
//	}
//private:
//	Knife* knife;
//};
//
//class CharacterAK47 {
//public:
//	void Fight()
//	{
//		ak47->useWeapon();
//	}
//private:
//	AK47* ak47;
//};

int main()
{
	WeaponStrategy * strategy = NULL;
	Character * c = new Character;

	//使⽤用⼔匕⾸首策略 
	strategy = new Knife;
	c->setWeapon(strategy);
	c->Fight();
	delete strategy;
	//是哟AK47  装备策略 
	strategy = new AK47;
	c->setWeapon(strategy);
	c->Fight();
	delete strategy;
	delete c;
	return 0;
}
#endif