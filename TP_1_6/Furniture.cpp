#include "Furniture.h"

Furniture::Furniture() : Base("������"), type("�� ������"), color("�� ������"), material("�� ������"),
	hight(0), lenght(0), width(0), price(0.0)
{
	cout << "������ ����������� Furniture" << endl;
}

Furniture::Furniture(string type, string color, string material, double hight, double lenght, double width, double price) :
	Base("������"), type(type), color(color), material(material), hight(hight), lenght(lenght), width(width), price(price)
{
	cout << "������ ����������� Furniture" << endl;
}

Furniture::Furniture(const Furniture& furniture) :
	Base(furniture), type(furniture.type), color(color), material(furniture.material), 
	hight(furniture.hight), lenght(furniture.lenght), width(furniture.width), price(furniture.price)
{
	cout << "������ ����������� ����������� Furniture" << endl;
}
//���������� �������� �� ������������ ����
void Furniture::inputFromConsole()
{
	cout << "������� ���: ";
	getline(cin, type);
	cout << "������� ����: ";
	getline(cin, color);
	cout << "������� ��������: ";
	getline(cin, material);
	cout << "������� ������: ";
	hight = safeInput(1.0, (double)INT32_MAX);
	cout << "������� �����: ";
	lenght = safeInput(1.0, (double)INT32_MAX);
	cout << "������� ������: ";
	width = safeInput(1.0, (double)INT32_MAX);
	cout << "������� ����: ";
	price = safeInput(1.0, (double)INT32_MAX);
}
//���������� ������ ���� �� �����, ���� �� ������ ��������� �����, ������ ���� ���������� ������ �������
void Furniture::inputFromFile(std::ifstream& file, std::string& tmpS)
{
	string err = "���� �� ����� ���� ��������� ��������";
	if (!getline(file, tmpS))
		throw err;
	type = tmpS;
	if (!getline(file, tmpS))
		throw err;
	color = tmpS;
	if (!getline(file, tmpS))
		throw err;
	material = tmpS;
	if (!getline(file, tmpS))
		throw err;
	hight = (checkStringToDouble(tmpS) ? stod(tmpS) : 0);
	if (!getline(file, tmpS))
		throw err;
	lenght = (checkStringToDouble(tmpS) ? stod(tmpS) : 0);
	if (!getline(file, tmpS))
		throw err;
	width = (checkStringToDouble(tmpS) ? stod(tmpS) : 0);
	if (!getline(file, tmpS))
		throw err;
	price = (checkStringToDouble(tmpS) ? stod(tmpS) : 0);
}

void Furniture::printToConsole()
{
	Base::printToConsole();
	cout << "���: " << type << endl;
	cout << "����: " << color << endl;
	cout << "��������: " << material << endl;
	cout << "������: " << hight << endl;
	cout << "�����: " << lenght << endl;
	cout << "������: " << width << endl;
	cout << "����: " << price << endl;
}

void Furniture::printToFile(ostream& out)
{
	Base::printToFile(out);
	out << type << endl;
	out << color << endl;
	out << material << endl;
	out << hight << endl;
	out << lenght << endl;
	out << width << endl;
	out << price << endl;
}

void Furniture::change()
{
	cout << "������� ����� ���: ";
	getline(cin, type);
	cout << "������� ����� ����: ";
	getline(cin, color);
	cout << "������� ����� ��������: ";
	getline(cin, material);
	cout << "������� ����� ������: ";
	hight = safeInput(1.0, (double)INT32_MAX);
	cout << "������� ����� �����: ";
	lenght = safeInput(1.0, (double)INT32_MAX);
	cout << "������� ����� ������: ";
	width = safeInput(1.0, (double)INT32_MAX);
	cout << "������� ����� ����: ";
	price = safeInput(1.0, (double)INT32_MAX);
}