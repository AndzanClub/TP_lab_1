#include "Worker.h"

Worker::Worker() : Base("Работник"), FIO("Не задано"), status("Не задано"), adress("Не задано"), adress("Не задано"), salary(0)
{
	cout << "Вызван конструктор Worker" << endl;
}

Worker::Worker(string FIO, string status, string adress, string phone, int salary) :
	Base("Работник"), FIO(FIO), status(status), adress(adress), phone(phone), salary(salary)
{
	cout << "Вызван конструктор Worker" << endl;
}

Worker::Worker(const Worker& worker) :
	Base(worker), FIO(worker.FIO), status(worker.status), adress(worker.adress), phone(worker.phone), salary(worker.salary)
{
	cout << "Вызван конструктор копирования Worker" << endl;
}

void Worker::inputFromConsole()
{
	cout << "Введите ФИО: ";
	getline(cin, FIO);
	cout << "Введите должность: ";
	getline(cin, status);
	cout << "Введите адресс: ";
	getline(cin, adress);
	cout << "Введите телефон (11 цифр): ";
	getline(cin, phone);
	cout << "Введите заработную плату: ";
	salary = safeInput(1, INT32_MAX);
}

void Worker::inputFromFile(std::ifstream& file, std::string& tmpS)
{
	string err = "Файл не может быть корректно прочитан";
	if (!getline(file, tmpS))
		throw err;
	FIO = tmpS;
	if (!getline(file, tmpS))
		throw err;
	status = tmpS;
	if (!getline(file, tmpS))
		throw err;
	adress = tmpS;
	if (!getline(file, tmpS))
		throw err;
	phone = (checkPhoneNumber(tmpS) ? tmpS: "0");
	if (!getline(file, tmpS))
		throw err;
	salary = (checkStringToInt(tmpS) ? stoi(tmpS) : 0);
}

void Worker::printToConsole()
{
	Base::printToConsole();
	cout << "ФИО: " << FIO << endl;
	cout << "Должность: " << status << endl;
	cout << "Адрес проживания: " << adress << endl;
	cout << "телефон: " << phone << endl;
	cout << "Зароботна плата: " << salary << endl;
}

void Worker::printToFile(ostream& out)
{
	Base::printToFile(out);
	out << FIO << endl;
	out << status << endl;
	out << adress << endl;
	out << phone << endl;
	out << salary << endl;
}

void Worker::change()
{
	cout << "Введите новое ФИО: ";
	getline(cin, FIO);
	cout << "Введите новую должность: ";
	getline(cin, status);
	cout << "Введите новый адресс: ";
	getline(cin, adress);
	cout << "Введите новый телефон (11 цифр): ";
	phone = inputPhoneNumber();
	cout << "Введите новую заработную плату: ";
	salary = safeInput(1, INT32_MAX);
}