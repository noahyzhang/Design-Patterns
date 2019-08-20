#if 0 
#include<iostream>

class SingLeton {
private:
	SingLeton()
	{}
public:
	static SingLeton* GetP()
	{
		if (p == nullptr)
		{
			p = new SingLeton();
		}
		return p;
	}
private:
	static SingLeton* p;
};

SingLeton* SingLeton::p = new SingLeton();

int main()
{
	SingLeton* p1 = SingLeton::GetP();
	SingLeton* p2 = SingLeton::GetP();
	std::cout << p1 << std::endl << p2 << std::endl;
	return 0;
}

#endif

#if 0 //懒汉模式
#include<iostream>
#include<mutex>
using namespace std;

class Singleton {
public:
	static Singleton* GetInstance()
	{
		//thread1
		//thread2
		if (_sInstance == NULL)  //双重检查是为了效率
		{
			//RAII
			//_mtx.lock();  //线程安全
			lock_guard<mutex> lock(_mtx); //在构造中加锁，在析构中解锁。出了这个作用域自动解锁
			if (_sInstance == NULL)
			{
				_sInstance = new Singleton; //有可能会抛异常，可能会死锁
											//1、可以在下面捕获异常
											//2、利用RAII 的方式，可以在构造中加锁，在析构中解锁
										    //3、使用lock_guard,c++11，构造函数中lock，出了作用域在析构中解锁
				//如果带有赋值的话，还需要防止编译器优化，需要设定一个内存栅栏
#ifndef __MemoryBarrier__
				Singleton* tmp = new Singleton();
				MemoryBarrier(); //内存栅栏
				_sInstance = tmp;
#endif // 



			}
			//_mtx.unlock();
		}
		return _sInstance;
	}
	void Print()
	{
		std::cout << _data << std::endl;
	}
private:
	Singleton()  //构造私有
		: _data(0)
	{}
	//防止拷贝
	Singleton(Singleton&);
	Singleton& operator=(Singleton&);

	static Singleton* _sInstance;
	static mutex _mtx;
	int _data;
};

Singleton*  Singleton::_sInstance = NULL;
mutex Singleton::_mtx;


int main()
{
	Singleton::GetInstance()->Print();
	system("pause");
	return 0;
}
#endif

#if 0  //饿汉模式
#include<iostream>
#include<mutex>
#include<assert.h>
using namespace std;

class Singleton {
public:
	static Singleton* GetInstance()
	{
		//assert(_sInstance);
		static Singleton tmp; //也可以这样
		return &tmp;
		//return _sInstance;
	}
	void Print()
	{
		std::cout << _data << std::endl;
	}
private:
	Singleton()  //构造私有
		: _data(0)
	{}
	//防止拷贝
	Singleton(Singleton&);
	Singleton& operator=(Singleton&);

	static Singleton* _sInstance;
	int _data;
};

//main函数以前就初始化了。因为main函数以前只有一个线程，因此不存在线程安全的问题
//但是还是会出现一些问题，在静态库动态库会出现问题，比如我在构造函数时就创建一个线程还是会出现问题的
Singleton*  Singleton::_sInstance = new Singleton;


int main()
{
	Singleton::GetInstance()->Print();
	system("pause");
	return 0;
}
#endif

#if 0
class Tingleton {
public:
	static Tingleton* GetIntence()
	{
		if (_sIntence == nullptr)
		{
			_sIntence = new Tingleton();
		}
		return _sIntence;
	}
private:
	Tingleton() : _data(0)
	{}

private:
	int _data;
	static Tingleton* _sIntence;
};

#endif