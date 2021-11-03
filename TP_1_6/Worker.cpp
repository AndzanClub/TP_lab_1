#include "Worker.h"

Worker::Worker() : Base("��������"), FIO("�� ������"), status("�� ������"), adress("�� ������"), phone("�� ������"), salary(0), isDriver(false)
{
	cout << "������ ����������� Worker" << endl;
}

Worker::Worker(string FIO, string status, string adress, string phone, int salary, bool isDriver) :
	Base("��������"), FIO(FIO), status(status), adress(adress), phone(phone), salary(salary), isDriver(isDriver)
{
	cout << "������ ����������� Worker" << endl;
}

Worker::Worker(const Worker& worker) :
	Base(worker), FIO(worker.FIO), status(worker.status), adress(worker.adress),
	phone(worker.phone), salary(worker.salary), isDriver(worker.isDriver)
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
	cout << "�������� �� �� ���������?(1/0): ";
	isDriver = safeInput(0, 1);
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
	if (!getline(file, tmpS))
		throw err;
	isDriver = (tmpS == "1" || tmpS == "0" ? stoi(tmpS) : 0);
}

void Worker::printToConsole()
{
	Base::printToConsole();
	cout << "���: " << FIO << endl;
	cout << "���������: " << status << endl;
	cout << "����� ����������: " << adress << endl;
	cout << "�������: " << phone << endl;
	cout << "��������� �����: " << salary << endl;
	if (isDriver)
		cout << "����� ������ ������" << endl;
	else
		cout << "�� ����� ������ ������" << endl;
}

void Worker::printToFile(ostream& out)
{
	Base::printToFile(out);
	out << FIO << endl;
	out << status << endl;
	out << adress << endl;
	out << phone << endl;
	out << salary << endl;
	out << isDriver << endl;
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
	cout << "�������� �� �� ���������?(1/0): ";
	isDriver = safeInput(0, 1);
}