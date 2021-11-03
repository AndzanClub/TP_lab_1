#include "Car.h"

Car::Car() : Base("Машина"), mark("Не задано"), model("Не задано"), number("Не задано")
{
	cout << "Вызван конструктор Car" << endl;
}

Car::Car(string mark, string model, string number) :
	Base("Машина"), mark(mark), model(model), number(number)
{
	cout << "Вызван конструктор Car" << endl;
}

Car::Car(const Car& car) :
	Base(car), mark(car.mark), model(car.model), number(car.number)
{
	cout << "Вызван конструктор копирования Car" << endl;
}

void Car::inputFromConsole()
{
	cout << "Введите марку: ";
	getline(cin, mark);
	cout << "Введите модель: ";
	getline(cin, model);
	cout << "Введите гос. номер: ";
	getline(cin, number);
}

void Car::inputFromFile(std::ifstream& file, std::string& tmpS)
{
	string err = "Файл не может быть корректно прочитан";
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
	cout << "Марка: " << mark << endl;
	cout << "Модель: " << model << endl;
	cout << "Гос. номер: " << number << endl;
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
	cout << "Введите новою марку: ";
	getline(cin, mark);
	cout << "Введите новую модель: ";
	getline(cin, model);
	cout << "Введите новый гос. номер: ";
	getline(cin, number);
}