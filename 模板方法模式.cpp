#if 0
#include<vector>
#include<iostream>

void Print(std::vector<int>& vec)
{
	for (int i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}

int Partion(std::vector<int>& vec, int left, int right)
{
	int index = right;
	int data = vec[index];
	while (left < right)
	{
		while (left < right && vec[left] < data)
			left++;
		if (left == right)
			break;
		while (left < right && vec[right] >= data)
			right--;
		if (left == right)
			break;
		std::swap(vec[left], vec[right]);
	}
	std::swap(vec[index], vec[left]);
	return left;
}

void _QuickSort(std::vector<int>& vec, int left, int right)
{
	if (left >= right)
		return;
	int index = Partion(vec, left, right);

	_QuickSort(vec, left, index-1);
	_QuickSort(vec, index+1,right);
}

void QuickSort(std::vector<int>& vec)
{
	if (vec.empty()) return;
	_QuickSort(vec, 0, vec.size()-1);
}

int main()
{
	std::vector<int> vec{ 9,8,7,6,5,4,3,2,1 };
	Print(vec);
	QuickSort(vec);
	Print(vec);
	return 0;
}
#endif

#if 0
#include<iostream> 
using namespace std;
//制作饮料 
class Beverage {
public:
	//  煮⽔水 
	void BoilWater() 
	{
		cout << "烧开⽔水" << endl;
	}
	//  冲泡   特殊接⼝口 
	virtual void Brew() = 0;
	//  倒⼊入杯中 
	void PourInCup() 
	{
		cout << "倒⼊入杯中" << endl;
	}
	//  添加料  特殊接⼝口 
	virtual void AddCondiments() = 0;
	//  hook  ⽅方法，决定某些算法步骤是否挂钩在算法中 
	virtual bool CustomWantsCondiments() 
	{
		return true;
	}
		//  模板⽅方法 
	void PrepareBeverage() 
	{
		BoilWater();
		Brew();
		PourInCup();
		if (CustomWantsCondiments()) 
		{
			AddCondiments();
		}
	}
};

class Coffee : public Beverage {
public:
	virtual void Brew() 
	{
		cout << "冲泡咖啡⾖豆" << endl;
	}
	virtual void AddCondiments() 
	{
		cout << "添加糖和⽜牛奶  " << endl;
	}
};

class Tea : public Beverage {
public:
	virtual void Brew() 
	{
		cout << "冲泡茶叶  " << endl;
	}
	virtual void AddCondiments() 
	{
		cout << "添加柠檬  " << endl;
	}
};
int main(void)
{
	Beverage *pTea = new Tea;
	pTea->PrepareBeverage();
	delete pTea;
	cout << "-­‐-­‐-­‐-­‐-­‐-­‐-­‐-­‐-­‐-­‐-­‐-­‐-­‐-­‐-­‐-­‐-­‐-­‐-­‐-­‐-­‐" << endl;
	Beverage *pCoffee = new Coffee;
	pCoffee->PrepareBeverage();
	delete pCoffee;
	return 0;
}

#endif