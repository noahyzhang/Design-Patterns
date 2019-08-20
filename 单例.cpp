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

#if 0 //����ģʽ
#include<iostream>
#include<mutex>
using namespace std;

class Singleton {
public:
	static Singleton* GetInstance()
	{
		//thread1
		//thread2
		if (_sInstance == NULL)  //˫�ؼ����Ϊ��Ч��
		{
			//RAII
			//_mtx.lock();  //�̰߳�ȫ
			lock_guard<mutex> lock(_mtx); //�ڹ����м������������н�������������������Զ�����
			if (_sInstance == NULL)
			{
				_sInstance = new Singleton; //�п��ܻ����쳣�����ܻ�����
											//1�����������沶���쳣
											//2������RAII �ķ�ʽ�������ڹ����м������������н���
										    //3��ʹ��lock_guard,c++11�����캯����lock�������������������н���
				//������и�ֵ�Ļ�������Ҫ��ֹ�������Ż�����Ҫ�趨һ���ڴ�դ��
#ifndef __MemoryBarrier__
				Singleton* tmp = new Singleton();
				MemoryBarrier(); //�ڴ�դ��
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
	Singleton()  //����˽��
		: _data(0)
	{}
	//��ֹ����
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

#if 0  //����ģʽ
#include<iostream>
#include<mutex>
#include<assert.h>
using namespace std;

class Singleton {
public:
	static Singleton* GetInstance()
	{
		//assert(_sInstance);
		static Singleton tmp; //Ҳ��������
		return &tmp;
		//return _sInstance;
	}
	void Print()
	{
		std::cout << _data << std::endl;
	}
private:
	Singleton()  //����˽��
		: _data(0)
	{}
	//��ֹ����
	Singleton(Singleton&);
	Singleton& operator=(Singleton&);

	static Singleton* _sInstance;
	int _data;
};

//main������ǰ�ͳ�ʼ���ˡ���Ϊmain������ǰֻ��һ���̣߳���˲������̰߳�ȫ������
//���ǻ��ǻ����һЩ���⣬�ھ�̬�⶯̬���������⣬�������ڹ��캯��ʱ�ʹ���һ���̻߳��ǻ���������
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