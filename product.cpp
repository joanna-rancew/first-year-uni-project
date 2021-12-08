#include <iostream>
#include "product.h"
#include <string>
#include <fstream>

using namespace std;

Product::Product(std::string n, int p)
{

	this->price = p;
	this->brand.clear();
	this->brand.insert(0, n);

}


Product::~Product() {


}

void Product::setPrice(int p)
{
	this->price = p;
}

void Product::setBrand(string b)
{
	brand = b;
}

void Product::inputFile()
{
	fstream file;


	file.open("daneproduct.txt", ios::in);//otwieranie pliku do odczytu
	if (file.good() == false) {
		cout << "Problem z plikiem";
		return;
	}

	file >> brand;
	file >> price;


	file.close();
}

void Product::outputFile()
{
	fstream file;

	file.open("product1.txt", ios::out);	//otwieranie pliku do zapisu
	if (file.is_open())
		file << *this;

	file.close();
}

ostream& operator<<(ostream &s, Product &p) {

	std::string text;
	text = p.brand + "\n" + std::to_string(p.price) + "\n";
	return  s << text;


}

