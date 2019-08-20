#if 0
#include<iostream>
#include<string>

class Item {
public:
	Item(std::string kind, bool fact) 
	{
		this->kind = kind;
		this->fact = fact;
	}
	//物品类别 
	std::string kind;
	//是否真伪？ 
	bool fact;
};

class AbstractBuy {
public:
	virtual void Buy(Item& item) = 0;
};

class AmericaBuy : public AbstractBuy {
public:
	virtual void Buy(Item& item)
	{
		std::cout << "我去美国购物" << item.kind << std::endl;
	}
};

class ChinaBuy : public AbstractBuy {
public:
	virtual void Buy(Item& item)
	{
		std::cout << " 我去中国购物: " << item.kind <<  std::endl;
	}
};

class OverSeasProxy : public AbstractBuy{
public:
	OverSeasProxy(AbstractBuy* buy)
	{
		this->buyMode = buy;
	}
	~OverSeasProxy()
	{
		delete this->buyMode;
	}
public:
	bool distinguish(Item& item) {
		std::cout << "对物品[" << item.kind << "]辨别真伪." << std::endl;
		return item.fact;
	}
	//海关安检 
	void check(Item &item) {
		std::cout << "通过海关安检，带回国内" << std::endl;
	}
public:
	virtual void Buy(Item& item)
	{
		if (distinguish(item) == true)
		{
			this->buyMode->Buy(item);
			check(item);
		}
		else
		{
			std::cout << "Find fake:[" << item.kind << "],not buy" << std::endl;
		}
	}
private:
	AbstractBuy* buyMode;
};

int main()
{
	Item t1("化妆品", true);
	Item t2("CET4证书", false);
	Item t3("addass运动鞋", true);

	OverSeasProxy* proxy = nullptr;
	proxy = new OverSeasProxy(new ChinaBuy);
	proxy->Buy(t1);
	delete proxy;


	proxy = new OverSeasProxy(new AmericaBuy);
	proxy->Buy(t2);
	delete proxy;
	return 0;
}
#endif