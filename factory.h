#pragma once
//definicja klasy Fabryka

#include "employee.h"
#include "chimney.h"
#include "product.h"
#include "company.h"
#include <string>


///klasa Factory dziedziczaca po Company
class Factory : public Company {
public:


	/// konstruktory z parametrem, zachowuje sie rowniez jak domyslny 
	Factory(std::string = "Anonim", float = 0.0);

	/// konstruktor kopiujacy 
	Factory(Factory &f);

	///destruktor 
	~Factory();


	///funkcje klasy Factory:    
	void presentEmployees();

	///funkcja zwracajaca ilosc obiektow klasy Product
	int getNumberOfProducts() { return products.size(); }



	///porownanie powierzchni dwoch fabryk 
	friend bool operator >=(const Factory &f2, const Factory &f1);



	///operator konwersji	
	operator std::string();

	///dostep do pol klasy
	Product& getProduct(int i) { return *products[i]; }

	///OPERATOR STRUMIENIOWY:
	/**	zwraca uporzadkowane dane o Beauty Salon na strumien postaci:
	name
	area
	ilosc pracownikow
	ilosc produktow

	w string*/
	friend ostream& operator<<(ostream &s, Factory &b);
	///zapis do pliku
	void outputFile();

	///odczyt  z pliku
	void inputFile();





private:
	Chimney chimney1, chimney2, chimney3;	///< klasa Chimney
	vector<Product*> products;		///< vector wskaznikow na obiekty klasy Product


};


