#include<iostream>
using namespace std;
#if 0
class AbstractFruit {
public:
	virtual void ShowName() = 0;
};

class Apple :public AbstractFruit {
public:
	virtual void ShowName()
	{
		cout << "我是苹果" << std::endl;
	}
};

class Banana :public AbstractFruit {
public:
	virtual void ShowName()
	{
		cout << "我是香蕉" << std::endl;
	}
};

class Pear :public AbstractFruit {
public:
	virtual void ShowName()
	{
		cout << "我是鸭梨" << std::endl;
	}
};

class FruitFactory {
public:
	static AbstractFruit* CreateFruit(string flag)
	{
		if (flag == "apple")
			return new Apple;
		else if (flag == "banana")
			return new Banana;
		else if (flag == "pear")
			return new Pear;
		else
			return nullptr;
	}
};

void test01()
{
	FruitFactory* factory = new FruitFactory;
	AbstractFruit* fruit = factory->CreateFruit("apple");
	fruit->ShowName();
	delete fruit;

	fruit = factory->CreateFruit("banana");
	fruit->ShowName();
	delete fruit;

	fruit = factory->CreateFruit("pear");
	fruit->ShowName();
	delete fruit;

}

int main()
{
	test01();
	return 0;
}
#endif

#if 0
class AbstractFruit {
public:
	virtual void ShowName() = 0;
};

class Apple : public AbstractFruit {
public:
	virtual void ShowName()
	{
		std::cout << "Apple" << std::endl;
	}
};

class Banana :public AbstractFruit {
public:
	virtual void ShowName()
	{
		std::cout << "banana " << std::endl;
	}
};

class Factory {
public:
	AbstractFruit* CreateFruit(std::string str)
	{
		if (str == "apple")
			return new Apple;
		else if (str == "banana")
			return new Banana;
		return nullptr;
	}
};

int main()
{
	Factory* factory = new Factory;
	AbstractFruit* fruit = factory->CreateFruit("apple");
	fruit->ShowName();
	delete fruit;

	fruit = factory->CreateFruit("banana");
	fruit->ShowName();
	delete fruit;

	fruit = nullptr;
	return 0;
}

#endif