#pragma once

#include <string>
#include <vector>
#include "employee.h"
#include <iostream>

///Klasa Company - abstrakcyjna klasa bazowa
/** Klasa Company zawiera:
- konstruktor kopiuj¹cy i z parametrem, bêd¹cy równoczesnie konstruktorem domyslnym
- destruktor
- funkcje - wirtualn¹ presentEmployees i pozostale
- operator indeksowy

*/

class Company {
public:

	/// Konstruktor z parametrem dla klasy Company
	/**Jest rowniez konstruktorem domyslnym*/

	Company(std::string = "Anonim", float = 0.0);

	///Konstruktor kopiujacy dla klasy Company
	Company(Company &f);

	///Destruktor klasy Company
	virtual ~Company();



	///funkcja dostepu do pol
	std::string getName() { return name; }
	///funkcja zmiany wartosci pola klasy 
	void changeArea();
	///funkcja dostepu do pol
	float getArea() { return area; }
	///funkcja dostepu do ilosci obiektow klasy Employee
	int getNumberOfEmployees() { return employees.size(); }
	///Wirtualna funkcja klasy Company
	virtual void presentEmployees() = 0;

	///metoda klasy
	void hireSomebody(Employee &candidate);

	///Operator indeksowy dla klasy Company
	/** Operator wywoluje pracownika o odpowiednim indeksie*/
	Employee& operator[](int i) {
		return *employees[i];
	}

	///OPERATOR STRUMIENIOWY:
	/**	zwraca uporzadkowane dane o Beauty Salon na strumien postaci:
	name
	area
	ilosc pracownikow

	w string*/
	friend ostream& operator<<(ostream &s, Company &b);

	///wirtualna funkcja dla abstrakcyjnej klasy bazowej
	virtual void outputFile() = 0;
	///wirtualna funkcja dla abstrakcyjnej klasy bazowej
	virtual void inputFile() = 0;


protected:
	float area; ///< pole stanowiace powierzchnie 
	std::string name; ///< pole stanowiace nazwe zakladu
	vector <Employee*> employees; ///< vector zbierajacy dane pracownikow zapisane w klasach Employee
};


