#include<iostream>
using namespace std;
#if 0
//抽象苹果
class AbstratApple {
public:
	virtual void ShowName() = 0;
};

//中国苹果
class ChinaApple : public AbstratApple {
public:
	virtual void ShowName()
	{
		cout << "中国苹果" << endl;
	}
};

//美国苹果
class USApple : public AbstratApple {
public:
	virtual void ShowName()
	{
		cout << "美国苹果" << endl;
	}
};

//日本苹果
class JapanApple : public AbstratApple {
public:
	virtual void ShowName()
	{
		cout << "日本苹果" << endl;
	}
};


//抽象香蕉
class AbstratBanana {
public:
	virtual void ShowName() = 0;
};

//中国香蕉
class ChinaBanana : public AbstratBanana {
public:
	virtual void ShowName()
	{
		cout << "中国香蕉" << endl;
	}
};

//美国香蕉
class USBanana : public AbstratBanana {
public:
	virtual void ShowName()
	{
		cout << "美国香蕉" << endl;
	}
};

//日本香蕉
class JapanBanana : public AbstratBanana {
public:
	virtual void ShowName()
	{
		cout << "日本香蕉" << endl;
	}
};


//抽象鸭梨
class AbstratPear {
public:
	virtual void ShowName() = 0;
};

//中国鸭梨
class ChinaPear : public AbstratPear {
public:
	virtual void ShowName()
	{
		cout << "中国鸭梨" << endl;
	}
};

//美国鸭梨
class USPear : public AbstratPear {
public:
	virtual void ShowName()
	{
		cout << "美国鸭梨" << endl;
	}
};

//日本香蕉
class JapanPear : public AbstratPear {
public:
	virtual void ShowName()
	{
		cout << "日本鸭梨" << endl;
	}
};

//抽象工厂  针对产品族的
class AbstracFactory {
public:
	virtual AbstratApple* CreateApple() = 0;
	virtual AbstratBanana* CreateBanana() = 0;
	virtual AbstratPear* CreatePear() = 0;
};

//中国工厂
class ChinaFactory : public AbstracFactory {
public:
	virtual AbstratApple* CreateApple()
	{
		return new ChinaApple;
	}
	virtual AbstratBanana* CreateBanana()
	{
		return new ChinaBanana;
	}
	virtual AbstratPear* CreatePear()
	{
		return new ChinaPear;
	}
};


//日本工厂
class JapanFactory : public AbstracFactory {
public:
	virtual AbstratApple* CreateApple()
	{
		return new JapanApple;
	}
	virtual AbstratBanana* CreateBanana()
	{
		return new JapanBanana;
	}
	virtual AbstratPear* CreatePear()
	{
		return new JapanPear;
	}
};

//美国工厂
class USAFactory : public AbstracFactory {
public:
	virtual AbstratApple* CreateApple()
	{
		return new USApple;
	}
	virtual AbstratBanana* CreateBanana()
	{
		return new USBanana;
	}
	virtual AbstratPear* CreatePear()
	{
		return new USPear;
	}
};

void  test01()
{
	AbstracFactory* factory = nullptr;
	AbstratApple* apple = nullptr;
	AbstratBanana* banana = nullptr;
	AbstratPear* pear = nullptr;

	factory = new ChinaFactory;
	apple = factory->CreateApple();
	banana = factory->CreateBanana();
	pear = factory->CreatePear();

	apple->ShowName();
	banana->ShowName();
	pear->ShowName();

	delete pear;
	delete banana;
	delete apple;
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

class ChinaApple : public AbstractFruit {
public:
	virtual void ShowName()
	{
		std::cout << "China Apple" << std::endl;
	}
};

class ChinaBanana : public AbstractFruit {
public:
	virtual void ShowName()
	{
		std::cout << "China Banana" << std::endl;
	}
};

class AmericaApple :public AbstractFruit{
public:
	virtual void ShowName()
	{
		std::cout << "America Apple" << std::endl;
	}
};

class AmericaBanana : public AbstractFruit {
public:
	virtual void ShowName()
	{
		std::cout << "America Banana" << std::endl;
	}
};

class AbstractFactory {
public:
	virtual AbstractFruit* AppleFactory() = 0;
	virtual AbstractFruit* BananaFactory() = 0;
};

class ChinaFacory :public AbstractFactory {
public:
	virtual AbstractFruit* AppleFactory()
	{
		return new ChinaApple;
	}
	virtual AbstractFruit* BananaFactory()
	{
		return new ChinaBanana;
	}
};

class AmericaFactory : public AbstractFactory {
public:
	virtual AbstractFruit* AppleFactory()
	{
		return new AmericaApple;
	}
	virtual AbstractFruit* BananaFactory()
	{
		return new AmericaBanana;
	}
};

int main()
{
	AbstractFactory* factory = nullptr;
	AbstractFruit* apple = nullptr;
	AbstractFruit* banana = nullptr;

	factory = new ChinaFacory;
	apple = factory->AppleFactory();
	banana = factory->BananaFactory();

	apple->ShowName();
	banana->ShowName();
	delete factory;
	delete apple;
	delete banana;

	factory = new AmericaFactory;
	apple = factory->AppleFactory();
	banana = factory->BananaFactory();

	apple->ShowName();
	banana->ShowName();

	return 0;
}

#endif