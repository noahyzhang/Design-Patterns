
#if 0
#include<iostream>
#include<mutex>
#include<Windows.h>

//¿¡∫∫ Ω
class Singleton {

public:
	static Singleton* GetInstance()
	{
		if (_sInstance == nullptr)
		{
			//_mtx.lock();
			std::lock_guard<std::mutex> lock(_mtx);
			if (_sInstance == nullptr)
			{
				//_sInstance = new Singleton;
				Singleton* tmp = new Singleton;
				MemoryBarrier();
				_sInstance = tmp;
			}
			//_mtx.unlock();
		}
		return _sInstance;
	}

private:
	Singleton()
		: _data(0)
	{}
	Singleton(const Singleton&);
	Singleton& operator=(const Singleton&);
	static Singleton* _sInstance;
	static std::mutex _mtx;

	int _data;
};

Singleton* Singleton::_sInstance = nullptr;
std::mutex Singleton::_mtx;

int main()
{
	Singleton* ptr1 = Singleton::GetInstance();
	Singleton* ptr2 = Singleton::GetInstance();
	std::cout << ptr1 << " " << ptr2 << std::endl;
	system("pause");
	return 0;
}
#endif

#if 0   //∂ˆ∫∫ 1
#include<iostream>
#include<assert.h>

class Singleton {
	
public:
	static Singleton* GetInstance()
	{
		assert(_sInstance);
		return _sInstance;
	}
private:
	Singleton() : _data(0)
	{}
	Singleton(const Singleton&);
	Singleton& operator=(const Singleton&);
	int _data;

	static Singleton* _sInstance;
};

Singleton* Singleton::_sInstance = new Singleton;

Singleton* ptr3 = Singleton::GetInstance();

int main()
{
	Singleton* ptr1 = Singleton::GetInstance();
	Singleton* ptr2 = Singleton::GetInstance();
	std::cout << ptr1 << " " << ptr2 <<" "<< ptr3 << std::endl;
	system("pause");
	return 0;
}
#endif
 
#if 0  //∂ˆ∫∫ƒ£ Ω 2
#include<iostream>
#include<assert.h>


class Singleton {
public:
	static Singleton* GetInstance()
	{
		static Singleton _sIntance;
		return &_sIntance;
	}
	void Print()
	{
		std::cout << _data << std::endl;
	}

private:
	Singleton() : _data(0)
	{}
	Singleton(const Singleton&);
	Singleton& operator=(const Singleton&);
	int _data;
};

int main()
{
	Singleton* ptr1 = Singleton::GetInstance();
	Singleton* ptr2 = Singleton::GetInstance();
	std::cout << ptr1 << " " << ptr2 << std::endl;
	system("pause");
	return 0;
}
#endif

#if 0
#include<mutex>
#include<iostream>
#include<Windows.h>

template<typename T>
class Singleton {
public:
	static Singleton* GetInstance()
	{
		if (_sInstance == nullptr)
		{
			std::lock_guard<std::mutex> lock(_mux);
			if (_sInstance == nullptr)
			{
				Singleton* tmp = new Singleton;
				MemoryBarrier();
				_sInstance = tmp;
			}
		}
		return _sInstance;
	}
	void Print()
	{
		std::cout << data << std::endl;
	}
private:
	Singleton(T val = (T)0)
		: data(val)
	{}
	Singleton(const Singleton&);
	Singleton& operator=(const Singleton&);
private:
	T data;
	static std::mutex _mux;
	static Singleton* _sInstance;
};

template<typename T>
Singleton<T>* Singleton<T>::_sInstance = nullptr;

template<typename T>
std::mutex Singleton<T>::_mux;


int main()
{
	Singleton<int>::GetInstance()->Print();
	return 0;
}
#endif

#include<mutex>
#include<iostream>
#include<Windows.h>

// ¿¡∫∫
#if 0
class Singleton {
public:
	static Singleton* GetInstance()
	{
		if (_sIntance == nullptr)
		{
			std::lock_guard<std::mutex> lock(_mtu);
			if (_sIntance == nullptr)
			{
				Singleton* tmp = new Singleton(); 
				MemoryBarrier();
				_sIntance = tmp;
			}
		}
		return _sIntance;
	}
private:
	Singleton(int val = 0) : data(val) {}
	Singleton(const Singleton&);
	Singleton& operator = (const Singleton&);
private:
	static Singleton* _sIntance;
	static std::mutex _mtu;
	int data;
};

Singleton* Singleton::_sIntance = nullptr;
std::mutex _mtu;


#include<cassert>

class Singleton{
public:
	Singleton* GetInstance()
	{
		assert(_sIntance);
		return _sIntance;
	}
private:
	Singleton(int val = 0) : data(val) {}
	Singleton(const Singleton&);
	Singleton& operator = (const Singleton&);
private:
	static Singleton* _sIntance;
	int data;
};

Singleton* Singleton::_sIntance = new Singleton();

#endif