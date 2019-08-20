#if 0
#include<iostream>
#include<string>

class One {
public:
	void OneShow()
	{
		std::cout << "OneShow" << std::endl;
	}
};

class Two {
public:
	void TwoShow()
	{
		std::cout << "TwoShow" << std::endl;
	}
};

class Three {
public:
	void ThreeShow()
	{
		std::cout << "ThreeShow()" << std::endl;
	}
};

class Facade {
public:
	Facade()
	{
		one = new One;
		two = new Two;
		three = new Three;
	}
	void Method1()
	{
		std::cout << "Method 1" << std::endl;
		one->OneShow();
		two->TwoShow();
	}
	void Method2()
	{
		std::cout << "Method 2" << std::endl;
		three->ThreeShow();
	}
	~Facade()
	{
		delete one;
		delete two;
		delete three;
	}
private:
	One* one;
	Two* two;
	Three* three;
};

int main()
{
	Facade* facade = new Facade;
	facade->Method1();
	facade->Method2();
	return 0;
}
#endif