#include "fabric.h"
//������� ���������� ������ �� ��� ��������
Base* createObj(string name)
{
	if (name == "������")
		return new Furniture();
	if (name == "��������")
		return new Worker();
	if (name == "������")
		return new Car();
	string err = "��� ������� �� ���������";
	throw err;
}