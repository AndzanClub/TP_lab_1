#pragma once
#include "Base.h"
class Car :
    public Base
{
private:
	string mark, model, number;
public:
	Car();
	Car(string mark, string model, string number);
	Car(const Car& car);
	~Car() { cout << "Вызван деструктор Car" << endl; }

	virtual void inputFromConsole();
	virtual void inputFromFile(std::ifstream& file, std::string& tmpS);
	virtual void printToConsole();
	virtual void printToFile(ostream& out);
	virtual void change();

	string getMark() { return mark; }
	void setMark(string mark) { this->mark = mark; }

	string getModel() { return model; }
	void setModel(string model) { this->model = model; }

	string getNumber() { return number; }
	void setNumber(string number) { this->number = number; }
};

