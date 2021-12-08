#include <iostream>
#include "hairdresser's.h"
#include <fstream>


Hairdressers::Hairdressers(std::string name, float area)
{
	this->name.clear();
	this->name.insert(0, name);
	this->area = area;
}

Hairdressers::Hairdressers(Hairdressers & h)
{
	this->area = h.area;
	this->name.clear();
	this->name.insert(0, h.name);


	if (h.getNumberOfEmployees()) {
		for (int i = 0; i < h.getNumberOfEmployees(); i++)
		{
			employees.push_back(&h[i]);
		}
	}
}

Hairdressers::~Hairdressers()
{
	if (employees.size()) {
		employees.clear();
	}
}



void Hairdressers::doService()
{
	std::cout << "Myje wlosy, scinam wlosy, susze wlosy";
}

void Hairdressers::inputFile()
{
	fstream file;
	int number;


	file.open("danehairdressers.txt", ios::in);//otwieranie pliku do odczytu
	if (file.good() == false) {
		cout << "Problem z plikiem";
		return;
	}

	file >> name;
	file >> area;

	file >> number;


	Employee *emp = new Employee[number];
	string n, s;
	int a, p;

	for (int i = 0; i < number; i++) {
		file >> n;
		file >> s;
		file >> a;
		file >> p;
		emp[i].setData(n, s, a, p);

		employees.push_back(&emp[i]);
	}

	file.close();

}

void Hairdressers::outputFile()
{

	fstream file;

	file.open("hair1.txt", ios::out);	//otwieranie pliku do zapisu
	if (file.is_open())
		file << *this;

	file.close();

}



ostream & operator<<(ostream & s, Hairdressers & b)
{


	std::string text;
	text = b.name + "\n" + std::to_string(b.area) + "\n" + std::to_string(b.getNumberOfEmployees()) + "\n";
	s << text;
	for (int i = 0; i < b.getNumberOfEmployees(); i++)
		s << b[i];
	return s;



}