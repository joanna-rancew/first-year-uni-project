#pragma once
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;


///klasa Chimney
class Chimney {
public:
	///konstruktor, a kopiujacy domyslny, gdyz automatyczne zmienne
	Chimney(double = 0.0, string = "Anonim", int = 0);

	///destruktor
	~Chimney();

	///zwraca nazwe koloru w zaleznosci od typu dymu (colour_number)
	string getColourOfSmoke();


	int getTypeOfSmoke() { return colour_number; }
	void setTypeOfSmoke();

	double getHeight() { return height; }
	string getName() { return name; }

	///operator:
	/**	porownuje po wysokosci komina*/
	bool operator!=(Chimney &c);


	///OPERATOR STRUMIENIOWY:
	/**	zwraca uporzadkowane dane o Beauty Salon na strumien postaci:
	height
	name
	colour_number

	w string*/

	friend ostream& operator<<(ostream &s, Chimney &b);

	///funkcja odczytu z pliku
	void inputFile();
	///funkcja zapisu do pliku
	void outputFile();

private:
	double height; ///< wysokosc komina
	string name; ///< nazwa komina
	int colour_number; ///< liczba calkowita odpowiadajaca kolorowi dymu z komina

};