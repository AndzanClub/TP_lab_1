#include "Furniture.h"

Furniture::Furniture() : Base("Мебель"), type("Не задано"), color("Не задано"), material("Не задано"),
	hight(0), lenght(0), width(0), price(0.0)
{
	cout << "Вызван конструктор Furniture" << endl;
}

Furniture::Furniture(string type, string color, string material, double hight, double lenght, double width, double price) :
	Base("Мебель"), type(type), color(color), material(material), hight(hight), lenght(lenght), width(width), price(price)
{
	cout << "Вызван конструктор Furniture" << endl;
}

Furniture::Furniture(const Furniture& furniture) :
	Base(furniture), type(furniture.type), color(color), material(furniture.material), 
	hight(furniture.hight), lenght(furniture.lenght), width(furniture.width), price(furniture.price)
{
	cout << "Вызван конструктор копирования Furniture" << endl;
}
//поочередно получаем от пользователя поля
void Furniture::inputFromConsole()
{
	cout << "Введите тип: ";
	getline(cin, type);
	cout << "Введите цвет: ";
	getline(cin, color);
	cout << "Введите материал: ";
	getline(cin, material);
	cout << "Введите высоту: ";
	hight = safeInput(1.0, (double)INT32_MAX);
	cout << "Введите длину: ";
	lenght = safeInput(1.0, (double)INT32_MAX);
	cout << "Введите высоту: ";
	width = safeInput(1.0, (double)INT32_MAX);
	cout << "Введите цену: ";
	price = safeInput(1.0, (double)INT32_MAX);
}
//поочередно вводим поля из файла, если не смогли прочитать сроку, занчит файл закончился раньше времени
void Furniture::inputFromFile(std::ifstream& file, std::string& tmpS)
{
	string err = "Файл не может быть корректно прочитан";
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
	cout << "Тип: " << type << endl;
	cout << "Цвет: " << color << endl;
	cout << "Материал: " << material << endl;
	cout << "Высота: " << hight << endl;
	cout << "Длина: " << lenght << endl;
	cout << "Ширина: " << width << endl;
	cout << "Цена: " << price << endl;
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
	cout << "Введите новый тип: ";
	getline(cin, type);
	cout << "Введите новый цвет: ";
	getline(cin, color);
	cout << "Введите новый материал: ";
	getline(cin, material);
	cout << "Введите новую высоту: ";
	hight = safeInput(1.0, (double)INT32_MAX);
	cout << "Введите новую длину: ";
	lenght = safeInput(1.0, (double)INT32_MAX);
	cout << "Введите новую высоту: ";
	width = safeInput(1.0, (double)INT32_MAX);
	cout << "Введите новую цену: ";
	price = safeInput(1.0, (double)INT32_MAX);
}