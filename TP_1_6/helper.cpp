#include "helper.h"
//получаем от пользовател€ номер телефона работника
std::string inputPhoneNumber() {
	std::string phone;
	while (true)
	{
		std::cin >> phone;
		if (!checkPhoneNumber(phone))
			std::cout << "Ќеверный ввод.\nѕовторите снова: ";
		else
			return phone;
	}
}
//провер€ем номер на кооректность
bool checkPhoneNumber(std::string s) {
	return s.size() == 11 && checkStringToInt(s);
}
//провер€ем, что строка €вл€етс€ числом
bool checkStringToInt(std::string s)
{
	for (auto letter : s)
		if (letter < '0' || letter > '9')
			return false;
	return true;
}
//провер€ем, что строка €вл€етс€ числом с плавающей точкой
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