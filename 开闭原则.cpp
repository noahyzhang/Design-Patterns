#if 0
#include<iostream>

template<class T>
class ABationCalculator {
public:
	virtual void SetNum(T a, T b) = 0;
	virtual T Calculator() = 0;

};

template<class T>
class PlusCalculator : public ABationCalculator<T>{
public:
	virtual void SetNum(T a, int b)
	{
		this->mA = a;
		this->mB = b;
	}
	virtual T Calculator()
	{
		return this->mA + this->mB;
	}
	T mA;
	T mB;
};

template<class T>
class SubCalculator : public ABationCalculator<T> {
public:
	virtual void SetNum(T a, int b)
	{
		this->mA = a;
		this->mB = b;
	}
	virtual T Calculator()
	{
		return this->mA - this->mB;
	}
	T mA;
	T mB;
};

template<class T>
class MulCalculator : public ABationCalculator<T> {
public:
	virtual void SetNum(T a, int b)
	{
		this->mA = a;
		this->mB = b;
	}
	virtual T Calculator()
	{
		return this->mA * this->mB;
	}
	T mA;
	T mB;
};

void test()
{
	ABationCalculator<int>* ab = new PlusCalculator<int>;
	ab->SetNum(1, 2);
	std::cout << "result : " << ab->Calculator() << std::endl;
}

int main()
{
	test();
	return 0;
}
#endif