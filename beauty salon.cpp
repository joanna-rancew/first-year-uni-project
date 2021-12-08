#include <iostream>
#include <string>
#include "employee.h"
#include "beauty salon.h"
#include <fstream>


BeautySalon::BeautySalon(std::string n, float area)
{
	this->area = area;
	//dopisanie do pustej nazwy imienia po 0
	this->name.clear();
	this->name.insert(0, n);
}

BeautySalon::BeautySalon(BeautySalon & bs)
{
	this->area = bs.area;
	this->name.clear();
	this->name.insert(0, bs.name);
	if (bs.getNumberOfEmployees()) {
		for (int i = 0; i < bs.getNumberOfEmployees(); i++)
		{
			employees.push_back(&bs[i]);
		}
	}
}

BeautySalon::~BeautySalon()
{
	if (employees.size()) {
		employees.clear();
	}
}

void BeautySalon::presentEmployees()
{
	int n = getNumberOfEmployees();
	if (n) {
		cout << "\nPracownicy salonu " << name << ":\n ";
		for (int i = 0; i < n; i++)
			cout << *employees[i];
	}
	else {
		cout << "\nSalon " << name << " aktualnie nie ma pracownikow\n ";
	}
}

void BeautySalon::doService()
{
	std::cout << "Wykonuje usluge";
}



void BeautySalon::inputFile()
{

	fstream file;
	int number;


	file.open("danebeautysalon.txt", ios::in);//otwieranie pliku do odczytu
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

void BeautySalon::outputFile() {

	fstream file;

	file.open("beauty1.txt", ios::out);//otwieranie pliku do zapisu
	if (file.is_open())
		file << *this;

	file.close();
}
ostream & operator<<(ostream & s, BeautySalon & b)
{

	std::string text;
	text = b.name + "\n" + std::to_string(b.area) + "\n" + std::to_string(b.getNumberOfEmployees()) + "\n";
	s << text;
	for (int i = 0; i < b.getNumberOfEmployees(); i++)
		s << b[i];
	return s;

}
