#if 0
#include<string>
#include<iostream>
#include<list>

class TeacherListenner {
public:
	virtual void OnTeacherComming() = 0;
	virtual void DoBadThing() = 0;
	virtual void StopBadThing() = 0;
};

class Student : public TeacherListenner {
public:
	Student(std::string name, std::string badthing)
	{
		this->name = name;
		this->badthing = badthing;
	}
	virtual void OnTeacherComming()
	{
		StopBadThing();
	}
	virtual void DoBadThing()
	{
		std::cout << "No Teacher, " << name << " start do " << badthing << std::endl;
	}
	virtual void StopBadThing()
	{
		std::cout << "Teacher comming, "<< name << " stop do" << badthing << std::endl;
	}
private:
	std::string name;
	std::string badthing;
};

class Informer {
public:
	virtual void AddLearning(TeacherListenner*) = 0;
	virtual void RemoveLearning(TeacherListenner*) = 0;
	virtual void inform() = 0;
};

class Moniter : public Informer {
public:
	virtual void AddLearning(TeacherListenner* listenner)
	{
		student_list.push_back(listenner);
	}
	virtual void RemoveLearning(TeacherListenner* listenner)
	{
		student_list.push_back(listenner);
	}
	virtual void inform()
	{
		for (auto it = student_list.begin(); it != student_list.end(); ++it)
		{
			(*it)->OnTeacherComming();
		}
	}
private:
	std::list<TeacherListenner*> student_list;
};

int main()
{
	Moniter moniter;
	Student xiaowang("小王", "抄作业");
	Student xiaoli("小李", "打游戏");

	moniter.AddLearning(&xiaowang);
	moniter.AddLearning(&xiaoli);
	
	xiaowang.DoBadThing();
	xiaoli.DoBadThing();

	moniter.inform();

	return 0;
}
#endif