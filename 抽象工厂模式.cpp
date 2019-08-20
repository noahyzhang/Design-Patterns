#include<iostream>
using namespace std;
#if 0
//����ƻ��
class AbstratApple {
public:
	virtual void ShowName() = 0;
};

//�й�ƻ��
class ChinaApple : public AbstratApple {
public:
	virtual void ShowName()
	{
		cout << "�й�ƻ��" << endl;
	}
};

//����ƻ��
class USApple : public AbstratApple {
public:
	virtual void ShowName()
	{
		cout << "����ƻ��" << endl;
	}
};

//�ձ�ƻ��
class JapanApple : public AbstratApple {
public:
	virtual void ShowName()
	{
		cout << "�ձ�ƻ��" << endl;
	}
};


//�����㽶
class AbstratBanana {
public:
	virtual void ShowName() = 0;
};

//�й��㽶
class ChinaBanana : public AbstratBanana {
public:
	virtual void ShowName()
	{
		cout << "�й��㽶" << endl;
	}
};

//�����㽶
class USBanana : public AbstratBanana {
public:
	virtual void ShowName()
	{
		cout << "�����㽶" << endl;
	}
};

//�ձ��㽶
class JapanBanana : public AbstratBanana {
public:
	virtual void ShowName()
	{
		cout << "�ձ��㽶" << endl;
	}
};


//����Ѽ��
class AbstratPear {
public:
	virtual void ShowName() = 0;
};

//�й�Ѽ��
class ChinaPear : public AbstratPear {
public:
	virtual void ShowName()
	{
		cout << "�й�Ѽ��" << endl;
	}
};

//����Ѽ��
class USPear : public AbstratPear {
public:
	virtual void ShowName()
	{
		cout << "����Ѽ��" << endl;
	}
};

//�ձ��㽶
class JapanPear : public AbstratPear {
public:
	virtual void ShowName()
	{
		cout << "�ձ�Ѽ��" << endl;
	}
};

//���󹤳�  ��Բ�Ʒ���
class AbstracFactory {
public:
	virtual AbstratApple* CreateApple() = 0;
	virtual AbstratBanana* CreateBanana() = 0;
	virtual AbstratPear* CreatePear() = 0;
};

//�й�����
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


//�ձ�����
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

//��������
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