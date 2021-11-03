#include "helper.h"
//�������� �� ������������ ����� �������� ���������
std::string inputPhoneNumber() {
	std::string phone;
	while (true)
	{
		std::cin >> phone;
		if (!checkPhoneNumber(phone))
			std::cout << "�������� ����.\n��������� �����: ";
		else
			return phone;
	}
}
//��������� ����� �� ������������
bool checkPhoneNumber(std::string s) {
	return s.size() == 11 && checkStringToInt(s);
}
//���������, ��� ������ �������� ������
bool checkStringToInt(std::string s)
{
	for (auto letter : s)
		if (letter < '0' || letter > '9')
			return false;
	return true;
}
//���������, ��� ������ �������� ������ � ��������� ������
bool checkStringToDouble(std::string s)
{
	bool flagPoint = false;
	for (int i = 0; i < s.size(); i++)
	{
		if ((s[i] < '0' || s[i] > '9') && (s[i] == '.' && (i == 0 || flagPoint)))
			return false;
		if (s[i] == '.')
			flagPoint = true;
	}
		
	return true;
}