#if 0
#include<iostream>
#include<list>

class Doctor {
public:
	void treat_eye()
	{
		std::cout << " treat eye" << std::endl;
	}
	void treat_ear()
	{
		std::cout << "treat ear" << std::endl;
	}
};

class Commond {
public:
	Commond(Doctor* doctor)
	{
		this->doctor = doctor;
	}
	virtual void treat() = 0;
protected:
	Doctor* doctor;
};

class CommondTreatEye : public Commond {
public:
	CommondTreatEye(Doctor* doctor) : Commond(doctor) {}
	virtual void treat()
	{
		doctor->treat_eye();
	}
};

class CommondTreatEar : public Commond {
public:
	CommondTreatEar(Doctor* doctor) : Commond(doctor) {}
	virtual void treat()
	{
		doctor->treat_ear();
	}
};

class Nurse {
public:
	Nurse(Commond* commond) 
	{
		this->commond = commond;
	}
	void Submit()
	{
		commond->treat();
	}
private:
	Commond* commond;
};

class AdvNurse {
public:
	AdvNurse()
	{
		this->cmd_list.clear();
	}
	void SetCmdList(Commond* commond)
	{
		cmd_list.push_back(commond);
	}
	void Submit()
	{
		for (std::list<Commond*>::iterator it = cmd_list.begin(); it != cmd_list.end(); ++it)
		{
			(*it)->treat();
		}
	}
private:
	std::list<Commond*> cmd_list;
};

int main()
{
	Doctor* doctor = new Doctor;
	Commond* commond1 = new CommondTreatEar(doctor);
	Commond* commond2 = new CommondTreatEye(doctor);
	AdvNurse* advnurse = new AdvNurse;

	advnurse->SetCmdList(commond1);
	advnurse->SetCmdList(commond2);
	advnurse->Submit();
	delete doctor;
	delete commond1;
	delete commond2;
	delete advnurse;
	return 0;
}
#endif