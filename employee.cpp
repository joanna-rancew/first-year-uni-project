#include "employee.h"
#include <iostream>
#include <string>
#include <fstream>


/*konstruktory:*/
Employee::Employee(int a, std::string n, std::string s, int i)
{
	this->age = a;
	this->name.clear();
	this->name.insert(0, n);
	this->surname.insert(0, s);
	this->passcode = i;
}

//kopiujacy domyslny

///destruktor	
Employee::~Employee() {}

void Employee::setPasscode(int c)
{
	this->passcode = c;
}

void Employee::setData(string n, string s, int age, int passcode)
{
	//ustawianie danych osobowych po raz pierwszy, dlatego musza byc puste
	if (name == "")
		this->name.insert(0, n);

	if (surname == "")
		this->surname.insert(0, s);
	this->age = age;

	this->passcode = passcode;
}



/*operator porownania, dwuargumentowy, poza klas¹
	sprawdzanie porownujac indywidualne kody dostepu*/
bool operator == (Employee &e1, Employee &e2) {
	if (!e1.passcode && !e2.passcode) {
		cout << "Nie nadano kodu dostepu, nie mozna porownac";
		return false;
	}

	return e1.passcode == e2.passcode;
}



//operator strumieniowy:    
std::ostream& operator<<(std::ostream &s, Employee &b)
{

	std::string text;
	s << b.name << "\n" << b.surname << "\n" << std::to_string(b.age) << "\n" << std::to_string(b.passcode) << "\n";

	return s;


}

void Employee::operator++()
{
	//zablokowany operator
}

void Employee::inputFile()
{
	fstream file;


	file.open("daneemployee.txt", ios::in);		//otwieranie pliku do odczytu
	if (file.good() == false) {
		cout << "Problem z plikiem";
		return;
	}


	file >> name;
	file >> surname;
	file >> age;
	file >> passcode;

	file.close();
}

void Employee::outputFile()
{
	fstream file;

	file.open("employee1.txt", ios::out);//otwieranie pliku do zapisu
	if (file.is_open())
		file << *this;

	file.close();

}
