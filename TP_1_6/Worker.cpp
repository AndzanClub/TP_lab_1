#include "Worker.h"

Worker::Worker() : Base("��������"), FIO("�� ������"), status("�� ������"), adress("�� ������"), adress("�� ������"), salary(0)
{
	cout << "������ ����������� Worker" << endl;
}

Worker::Worker(string FIO, string status, string adress, string phone, int salary) :
	Base("��������"), FIO(FIO), status(status), adress(adress), phone(phone), salary(salary)
{
	cout << "������ ����������� Worker" << endl;
}

Worker::Worker(const Worker& worker) :
	Base(worker), FIO(worker.FIO), status(worker.status), adress(worker.adress), phone(worker.phone), salary(worker.salary)
{
	cout << "������ ����������� ����������� Worker" << endl;
}

void Worker::inputFromConsole()
{
	cout << "������� ���: ";
	getline(cin, FIO);
	cout << "������� ���������: ";
	getline(cin, status);
	cout << "������� ������: ";
	getline(cin, adress);
	cout << "������� ������� (11 ����): ";
	getline(cin, phone);
	cout << "������� ���������� �����: ";
	salary = safeInput(1, INT32_MAX);
}

void Worker::inputFromFile(std::ifstream& file, std::string& tmpS)
{
	string err = "���� �� ����� ���� ��������� ��������";
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
	cout << "���: " << FIO << endl;
	cout << "���������: " << status << endl;
	cout << "����� ����������: " << adress << endl;
	cout << "�������: " << phone << endl;
	cout << "��������� �����: " << salary << endl;
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
	cout << "������� ����� ���: ";
	getline(cin, FIO);
	cout << "������� ����� ���������: ";
	getline(cin, status);
	cout << "������� ����� ������: ";
	getline(cin, adress);
	cout << "������� ����� ������� (11 ����): ";
	phone = inputPhoneNumber();
	cout << "������� ����� ���������� �����: ";
	salary = safeInput(1, INT32_MAX);
}