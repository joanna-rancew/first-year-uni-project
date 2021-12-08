#pragma once

//definicja klasy Hairdressers

#include "beauty salon.h"
#include <string>
#include <iostream>


///klasa Hairdressers dziedziczy po Beauty Salon, wiec rowniez po Company
class Hairdressers : public BeautySalon {
public:


	/// konstruktor z parametrem klasy Hairdressers
	Hairdressers(std::string = "Anonim", float = 0.0);

	/// konstruktor kopiujacy klasy Hairdressers
	Hairdressers(Hairdressers &h);

	/// destruktor
	~Hairdressers();


	///funkcja klasy Hairdressers:    
	void doService();

	///OPERATOR STRUMIENIOWY:
	/**	zwraca uporzadkowane dane o Beauty Salon na strumien postaci:
	name
	area
	ilosc pracownikow

	w string*/
	friend ostream& operator<<(ostream &s, Hairdressers &b);

	///funkcja zapisu do pliku
	void outputFile();
	///funkcja odczytu z pliku
	void inputFile();




};


