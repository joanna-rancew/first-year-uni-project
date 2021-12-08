#pragma once

#include <iostream>
#include <cstring>
#include <string>

using namespace std;


class Employee {

public:
	///konstruktory
	Employee(int = 0, string = "", string = "", int = 0);

	///destruktor
	~Employee();

	//kopiujacy - domyslny



	///metoda ustawiania danych
	void setPasscode(int);
	///metoda dostepu do pol klasy
	int getPasscode() { return passcode; }
	///metoda ustawiania danych
	void setData(string n, string s, int = 0, int = 0);

	///metoda dostepu do pol klasy
	int getAge() { return age; }
	///metoda dostepu do pol klasy
	string getName() { return name; }
	///metoda dostepu do pol klasy
	string getSurname() { return surname; }

	///operator porownania
	friend bool operator == (Employee &e1, Employee &e2);


	///OPERATOR STRUMIENIOWY:
		/**zwraca uporzadkowane dane o pracowniku na strumien:
		name
		surname
		age
		passcode
	*/
	friend ostream& operator<<(ostream &s, Employee &e);



	///OPERATOR ZABLOKOWANY
	void operator++();

	///odczyt z pliku
	void inputFile();
	///zapis do pliku
	void outputFile();

private:
	int age; ///< pole klasy Employee bedace danymi pracownika
	string name; ///< pole klasy Employee bedace danymi pracownika
	string surname; ///< pole klasy Employee bedace danymi pracownika
	int passcode; ///< pole klasy Employee bedace danymi pracownika
};