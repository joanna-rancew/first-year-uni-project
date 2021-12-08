#pragma once
#include <cstring>
#include <iostream>

using namespace std;
class Product {
public:
	///konstruktor klasy Product
	/**konstruktor kopiujacy, operator przypisania - domyslne */
	Product(std::string = "Produkt bez nazwy", int = 0);

	///destruktor klasy Product
	~Product();

	///funkcja ustawiania ceny 
	void setPrice(int p);
	///funkcja zwracajaca cene
	int getPrice() { return price; }

	///funkcja ustawiania nazwy marki
	string getBrand() { return brand; }
	///funkcja zwracajaca nazwe marki
	void setBrand(string b);



	///OPERATOR STRUMIENIOWY:
		/**	zwraca uporzadkowane dane o Beauty Salon na strumien postaci:
		brand
		price

		w string*/
	friend ostream& operator<<(ostream &s, Product &b);
	///funkcja odczytu z pliku
	void inputFile();
	///funkcja zapisu do pliku
	void outputFile();


private:
	int price; ///<cena klasy Product
	std::string brand; ///<nazwa marki klasy Product

};