#if 0
#include<iostream>
#include<string>

class Phone {
public:
	virtual void show() = 0;
};
//具体的构件 
class iPhone : public Phone {
public:
	iPhone(std::string kind) {
		this->kind = kind;
	}
	virtual void show() {
		std::cout << "秀出了 iPhone-" << kind << ":" << std::endl;
	}
private:
	std::string kind;
};

class Mi : public Phone {
public:
	Mi(std::string kind)
	{
		this->kind = kind;
	}
	virtual void show()
	{
		std::cout << "秀出了 iPhone-" << kind << ":" << std::endl;
	}
private:
	std::string kind;
};

class DecoratorPhone : public Phone{
public:
	DecoratorPhone() {}
	DecoratorPhone(Phone* phone) 
	{
		this->phone = phone;
	}
	virtual void show()
	{
		this->phone->show();
	}
private:
	Phone* phone;
};

class DecoratorPhoneMo : public DecoratorPhone {
public:
	DecoratorPhoneMo(Phone* phone)
	{
		this->phone = phone;
	}
	virtual void show()
	{
		this->phone->show();
		AddMo();
	}
	void AddMo()
	{
		std::cout << "装饰 : 手机贴膜" << std::endl;
	}
private:
	Phone* phone;
};

class DecoratorPhoneTao : public DecoratorPhone {
public:
	DecoratorPhoneTao(Phone* phone)
	{
		this->phone = phone;
	}
	virtual void show()
	{
		this->phone->show();
		AddTao();
	}
	void AddTao()
	{
		std::cout << "装饰 : 手机套" << std::endl;
	}
private:
	Phone* phone;
};

int main()
{
	Phone* phone = nullptr;
	DecoratorPhone* hasMoPhone = nullptr;
	DecoratorPhone* hasTaoPhone = nullptr;
	DecoratorPhone* hasMoTaoPhone = nullptr;

	phone = new iPhone("iPhone 7 plus");
	hasMoPhone = new DecoratorPhoneMo(phone);
	hasMoPhone->show();
	hasTaoPhone = new DecoratorPhoneTao(phone);
	hasTaoPhone->show();

	hasMoTaoPhone = new DecoratorPhoneTao(hasMoPhone);
	hasMoTaoPhone->show();

	phone = new Mi("mi 8");
	hasMoPhone = new DecoratorPhoneMo(phone);
	hasMoTaoPhone = new DecoratorPhoneTao(hasMoPhone);
	hasMoTaoPhone->show();
	return 0;
}
#endif