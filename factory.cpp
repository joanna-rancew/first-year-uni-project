#include <iostream>
#include <string>
#include "employee.h"
#include "factory.h"


Factory::Factory(std::string name, float area)
{
	this->name.clear();
	this->name.insert(0, name);
	this->area = area;
}

Factory::Factory(Factory & f)
{
	this->name.clear();
	this->name.insert(0, f.name);
	this->area = area;

	if (f.getNumberOfEmployees())
	{
		for (int i = 0; i < f.getNumberOfEmployees(); i++)
		{
			employees.push_back(&f[i]);
		}
	}

	if (f.getNumberOfProducts())
	{
		for (int i = 0; i < f.getNumberOfProducts(); i++)
		{
			products.push_back(&f.getProduct(i));
		}
	}


}

/*Destruktor: */
Factory::~Factory() {


	if (employees.size()) {
		employees.clear();
	}

	if (products.size()) {
		products.clear();
	}

}

void Factory::presentEmployees()
{
	int n = getNumberOfEmployees();
	if (n) {
		cout << "\nPracownicy fabryki " << this->name << ":\n";
		for (int i = 0; i < n; i++)
			cout << *employees[i];
	}
	else
		cout << "Fabryka " << name << " aktualnie nie ma pracownikow\n ";

}



/*FUNKCJE: */




/*operatory:   */


bool operator >= (const Factory &f1, const Factory &f2) {

	if (f1.area >= f2.area) {
		cout << "Fabryka: " << f1.name << " jest wieksza niz fabryka: " << f2.name << endl;
		return true;

	}
	else {
		cout << "Fabryka: " << f1.name << " nie jest wieksza niz fabryka: " << f2.name << endl;
		return false;

	}

}

ostream & operator<<(ostream & s, Factory & b)
{
	std::string text;
	text = b.name + "\n" + std::to_string(b.area) + "\n" + std::to_string(b.getNumberOfEmployees()) + "\n" + std::to_string(b.getNumberOfProducts()) + "\n";

	s << text;
	for (int i = 0; i < b.getNumberOfEmployees(); i++)
		s << b[i];

	for (int i = 0; i < b.getNumberOfProducts(); i++) {
		s << b.getProduct(i);
	}
	return s;

}



/* operator konwersji:		*/
Factory::operator std::string() {

	return  "Fabryka:\t\t\t" + name + "\nPOWIERZCHNIA:\t\t" + std::to_string(this->area);
}

void Factory::outputFile()
{
	fstream file;

	file.open("factory1.txt", ios::out);//otwieranie pliku do zapisu
	if (file.is_open())
		file << *this;

	file.close();
}

void Factory::inputFile()
{

	fstream file;
	int number_e;
	int number_p;


	file.open("danefactory.txt", ios::in);//otwieranie pliku do odczytu
	if (file.good() == false) {
		cout << "Problem z plikiem";
		return;
	}

	file >> name;
	file >> area;

	file >> number_e;


	Employee *emp = new Employee[number_e];
	string n, s;
	int a, p;

	for (int i = 0; i < number_e; i++) {
		file >> n;
		file >> s;
		file >> a;
		file >> p;
		emp[i].setData(n, s, a, p);

		employees.push_back(&emp[i]);
	}

	file >> number_p;

	Product *prod = new Product[number_p];
	string b;
	int price;

	for (int i = 0; i < number_p; i++) {
		file >> b;
		file >> price;

		prod[i].setBrand(b);
		prod[i].setPrice(price);

		products.push_back(&prod[i]);
	}



	file.close();

}

