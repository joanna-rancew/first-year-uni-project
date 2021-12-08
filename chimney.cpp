#include "chimney.h"
#include <fstream>
#include <iostream>
#include <string>



Chimney::Chimney(double h, string n, int colour)
{

	this->name.clear();
	this->name.insert(0, n);
	height = h;
	colour_number = colour;
}

Chimney::~Chimney() {

}

string Chimney::getColourOfSmoke()
{
	//w zaleznosci od indeksu koloru (colour_number) zwraca nazwe koloru
	switch (this->colour_number) {
	case 1:
	{
		return "bialy";
		break;
	}

	case 2:
	{
		return "czarny";
		break;
	}

	case 3:
	{
		return "szary";
		break;
	}
	}
	return "Niepoprawny indeks koloru";
}


void Chimney::setTypeOfSmoke()
{
	int c;
	cout << "\nWybierz indeks dymu (1,2 albo 3): ";

	colour_number = 0;
	do {
		//kontrola bledow
		cin >> c;
		if (cin.fail() || c < 0 || c>3) {
			cout << "\nBledna wartosc\n";
			cin.clear();
			cin.ignore(200000, '\n');

		}
		else
			colour_number = c;
	} while (!colour_number);


}

bool Chimney::operator!=(Chimney & c)
{
	if (this->height != c.height)
		return true;
	return false;
}

void Chimney::inputFile()
{
	fstream file;


	file.open("danechimney.txt", ios::in);//otwieranie pliku do odczytu
	if (file.good() == false) {
		cout << "Problem z plikiem";
		return;
	}

	file >> height;
	file >> name;
	file >> colour_number;

	file.close();



}

void Chimney::outputFile()
{
	fstream file;

	file.open("chimney1.txt", ios::out);//otwieranie pliku do zapisu
	if (file.is_open())
		file << *this;

	file.close();
}

ostream & operator<<(ostream & s, Chimney & b)
{
	std::string text;
	text = std::to_string(b.height) + "\n" + b.name + "\n" + std::to_string(b.colour_number) + "\n";
	return  s << text;

}
