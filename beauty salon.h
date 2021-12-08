#pragma once
//definicja klasy BeautySalon

#include "employee.h"
#include "company.h"
#include <iostream>
#include <string>



class BeautySalon : public Company {
public:


	/// konstruktor z parametrem klasy BeautySalon
	BeautySalon(std::string = "Anonim", float = 0.0);

	/// konstruktor kopiujacy
	BeautySalon(BeautySalon &bs);

	/// destruktor
	~BeautySalon();


	///funkcja prezentujaca pracownikow
	void presentEmployees();
	///wirtualna funkcja klasy BeautySalon
	virtual void doService();

	///OPERATOR STRUMIENIOWY:
	/**	zwraca uporzadkowane dane o Beauty Salon na strumien postaci:
	name
	area


	w string*/
	friend ostream& operator<<(ostream &s, BeautySalon &b);

	///Operator indeksowy dla klasy Company
	/** Operator wywoluje pracownika o odpowiednim indeksie*/
	Employee& operator[](int i) { return *employees[i]; }

	///wirtualna funkcja zapisu do pliku
	virtual void outputFile();
	///wirtualna funkcja zapisu do pliku
	virtual void inputFile();


};


