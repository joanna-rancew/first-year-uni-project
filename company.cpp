#include "company.h"
#include <vector>
#include "employee.h"

using namespace std;


Company::Company(std::string name, float area)
{
	this->area = area;
	//dopisanie do pustej nazwy imienia po 0
	this->name.clear();
	this->name.insert(0, name);

}


///Konstruktor kopiuj¹cy klasy Company
Company::Company(Company &c)
{
	this->area = c.area;
	this->name.clear();
	this->name.insert(0, c.name);

	if (c.getNumberOfEmployees())
	{
		for (int i = 0; i < c.getNumberOfEmployees(); i++)
		{
			employees.push_back(&c[i]);
		}
	}


}



///Destruktor klasy Company

Company::~Company()
{
	if (employees.size())
		employees.clear();

}

void Company::changeArea()
{
	float new_area;
	do {
		//czyszczenie bledow wprowadzania

		cout << "Podaj nowa powierzchnie: ";
		cin >> new_area;
		if (cin.fail()) {
			cout << "\nBledna wartosc\n";
			cin.clear();
			cin.ignore(200000, '\n');

		}
	} while (cin.fail() || new_area < 0);

	this->area = new_area;

}

void Company::presentEmployees()
{
	int n = getNumberOfEmployees();
	cout << "\nPracownicy zak³adu" << name << ":\n ";
	for (int i = 0; i < n; i++)
		cout << *employees[i];

}

void Company::hireSomebody(Employee &candidate)
{
	employees.push_back(&candidate);
}

ostream & operator<<(ostream & s, Company & b)
{

	std::string text;
	text = b.name + "\n" + std::to_string(b.area) + "\n" + std::to_string(b.getNumberOfEmployees()) + "\n";
	s << text;
	for (int i = 0; i < b.getNumberOfEmployees(); i++)
		s << b[i];
	return s;

}
