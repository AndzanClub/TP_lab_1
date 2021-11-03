#include "fabric.h"
//создаем конкретный объект по его названию
Base* createObj(string name)
{
	if (name == "Мебель")
		return new Furniture();
	if (name == "Работник")
		return new Worker();
	if (name == "Машина")
		return new Car();
	string err = "Тип объекта не распознан";
	throw err;
}