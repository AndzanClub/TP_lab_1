#pragma once
#include "Base.h"
class Furniture :
    public Base
{
private:
    string type, color, material;
	double hight, lenght, width, price;
public:
	Furniture();
	Furniture(string type, string color, string material, double hight, double lenght, double width, double price);
	Furniture(const Furniture& furniture);
	~Furniture() { cout << "Вызван деструктор Furniture" << endl; }

	virtual void inputFromConsole();
	virtual void inputFromFile(std::ifstream& file, std::string& tmpS);
	virtual void printToConsole();
	virtual void printToFile(ostream& out);
	virtual void change();

	string getType() { return type; }
	void setType(string type) { this->type = type; }

	string getColor() { return color; }
	void setColor(string color) { this->color = color; }

	string getMaterial() { return material; }
	void setMaterial(string material) { this->material = material; }

	double geHight() { return hight; }
	void setHight(double hight) { this->hight = hight; }

	double geLenght() { return lenght; }
	void setLenght(double lenght) { this->lenght = lenght; }

	double geWidth() { return width; }
	void setWidth(double width) { this->width = width; }

	double gePrice() { return price; }
	void setPrice(double price) { this->price = price; }

};

