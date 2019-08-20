#if 0

#include<iostream>
#include<string>

class V5 {
public:
	virtual void useV5() = 0;
};

class V220 {
public:
	virtual void useV220()
	{
		std::cout << "use 220v run " << std::endl;
	}
};

//  Adapter  充电器 
class ChargerAdapter : public V5 {
public:
	virtual void useV5() {
		std::cout << "充电器对电压进⾏行适配" << std::endl;
		m_p220v.useV220();
	}
private:
	V220 m_p220v;
};

class iPhone {
public:
	iPhone()
	{
		v5Adapter = new ChargerAdapter;
	}
	void charge()
	{
		std::cout << "iPhone start run" << std::endl;
		v5Adapter->useV5();
	}
	~iPhone()
	{
		if (v5Adapter == nullptr)
			delete v5Adapter;
	}
private:
	V5* v5Adapter;
};

int main()
{
	iPhone ipone;
	ipone.charge();
	return 0;
}
#endif