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

class AbstractFruitFactory {
public:
	virtual AbstractFruit* CreateFruit() = 0;
};

class AppleFactory : public AbstractFruitFactory{
public:
	virtual AbstractFruit* CreateFruit()
	{
		return new Apple;
	}
};

class BananaFactory : public AbstractFruitFactory {
public:
	virtual AbstractFruit* CreateFruit()
	{
		return new Banana;
	}
};

class PearFactory : public AbstractFruitFactory {
public:
	virtual AbstractFruit* CreateFruit()
	{
		return new Pear;
	}
};

void test01()
{
	AbstractFruitFactory* factory = nullptr;
	AbstractFruit* fruit = nullptr;

	factory = new AppleFactory;
	fruit = factory->CreateFruit();
	fruit->ShowName();
	delete fruit;
	delete factory;

	factory = new BananaFactory;
	fruit = factory->CreateFruit();
	fruit->ShowName();
	delete fruit;
	delete factory;

	factory = new PearFactory;
	fruit = factory->CreateFruit();
	fruit->ShowName();
	delete fruit;
	delete factory;
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

class Apple :public AbstractFruit
{
public:
	virtual void ShowName()
	{
		std::cout << "Apple" << std::endl;
	}
};

class Banana : public AbstractFruit {
public:
	virtual void ShowName()
	{
		std::cout << "Banana" << std::endl;
	}
};

class AbstractFactory {
public:
	virtual AbstractFruit* CreateFruit() = 0;
};

class AppleFactory : public AbstractFactory {
public:
	virtual AbstractFruit* CreateFruit()
	{
		return new Apple;
	}
};

class BananaFactory : public AbstractFactory {
public:
	virtual AbstractFruit* CreateFruit()
	{
		return new Banana;
	}
};

int main()
{
	AbstractFactory* factory = nullptr;
	AbstractFruit* fruit = nullptr;
	factory = new AppleFactory;
	fruit = factory->CreateFruit();
	fruit->ShowName();
	delete factory;
	delete fruit;

	factory = new BananaFactory;
	fruit = factory->CreateFruit();
	fruit->ShowName();
	delete factory;
	delete fruit;
	factory = nullptr;
	fruit = nullptr;
	return 0;
}
#endif