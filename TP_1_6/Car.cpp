#include "Car.h"

Car::Car() : Base("������"), mark("�� ������"), model("�� ������"), number("�� ������")
{
	cout << "������ ����������� Car" << endl;
}

Car::Car(string mark, string model, string number) :
	Base("������"), mark(mark), model(model), number(number)
{
	cout << "������ ����������� Car" << endl;
}

Car::Car(const Car& car) :
	Base(car), mark(car.mark), model(car.model), number(car.number)
{
	cout << "������ ����������� ����������� Car" << endl;
}

void Car::inputFromConsole()
{
	cout << "������� �����: ";
	getline(cin, mark);
	cout << "������� ������: ";
	getline(cin, model);
	cout << "������� ���. �����: ";
	getline(cin, number);
}

void Car::inputFromFile(std::ifstream& file, std::string& tmpS)
{
	string err = "���� �� ����� ���� ��������� ��������";
	if (!getline(file, tmpS))
		throw err;
	mark = tmpS;
	if (!getline(file, tmpS))
		throw err;
	model = tmpS;
	if (!getline(file, tmpS))
		throw err;
	number = tmpS;
}

void Car::printToConsole()
{
	Base::printToConsole();
	cout << "�����: " << mark << endl;
	cout << "������: " << model << endl;
	cout << "���. �����: " << number << endl;
}

void Car::printToFile(ostream& out)
{
	Base::printToFile(out);
	out << mark << endl;
	out << model << endl;
	out << number << endl;
}

void Car::change()
{
	cout << "������� ����� �����: ";
	getline(cin, mark);
	cout << "������� ����� ������: ";
	getline(cin, model);
	cout << "������� ����� ���. �����: ";
	getline(cin, number);
}