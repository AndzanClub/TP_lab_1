#pragma once
#include "Base.h"

class Worker :
    public Base
{
private:
	string FIO, status, adress, phone;
	int salary;
public:
	Worker();
	Worker(string FIO, string status, string adress, string phone, int salary);
	Worker(const Worker& worker);
	~Worker() { cout << "Вызван деструктор Worker" << endl; }

	virtual void inputFromConsole();
	virtual void inputFromFile(std::ifstream& file, std::string& tmpS);
	virtual void printToConsole();
	virtual void printToFile(ostream& out);
	virtual void change();

	string getFIO() { return FIO; }
	void setFIO(string FIO) { this->FIO = FIO; }

	string getStatus() { return status; }
	void setStatus(string status) { this->status = status; }

	string getAdress() { return adress; }
	void setAdress(string adress) { this->adress = adress; }

	string getPhone() { return phone; }
	void setPhone(string phone) { this->phone = phone; }

	int geSalary() { return salary; }
	void setSalary(int salary) { this->salary = salary; }
};

