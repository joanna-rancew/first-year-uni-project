#include <iostream>
#include "factory.h"
#include "beauty salon.h"
#include "company.h"
#include "hairdresser's.h"
#include <fstream>
#include <vector>



void employeeTest();
void productTest();
void chimneyTest();

int getMenu(vector  <Company*> c);
void failCheck();

void companyTest(Company &c);
void factoryTest(Company &c);
void beautySalonTest(Company &c);
void hairdressersTest(Company &c);


int main() {

	//employeeTest();
	//productTest();
	//chimneyTest();

	vector <Company*> companies;
	Factory f1("Elektron", 250.0), f2("Fabryka AGD", 300.0);
	BeautySalon b1("Wiecej piekna", 80.0);
	Hairdressers h1("Lepsze wlosy", 50.0);
	companies.push_back(&f1);
	companies.push_back(&f2);
	companies.push_back(&b1);
	companies.push_back(&h1);

	Employee e1(45, "Julia", "Szymanska", 8), e3(25, "Kasia", "Nostka", 6);
	Employee e2(33, "Konrad", "Jackowiak", 3);

	f1.hireSomebody(e1);
	b1.hireSomebody(e3);
	f1.hireSomebody(e2);


	return getMenu(companies);

}


int getMenu(vector  <Company*> c) {
	int selection;

	do {
		std::cout << "0. Wyjscie z programu\nWybierz zaklad: \n1. Fabryka 1 \n2. Fabryka 2\n3. Salon pieknosci 1\n4. Salon fryzjerski 1\nTwoj wybor: ";
		do {
			cin >> selection;
			failCheck();
		} while (selection < 0 || cin.fail());

		if (selection == 1 || selection == 2 || selection == 3 || selection == 4)
			companyTest(*c[selection - 1]);


		switch (selection) {

		case 1: //fabryka 1
		case 2:	//fabryka 2
		{
			factoryTest(*c[selection - 1]);
			break;
		}


		case 3: //salon pieknosci 1
		{
			beautySalonTest(*c[selection - 1]);

			break;
		}

		case 4: //salon fryzjerski 1
		{
			hairdressersTest(*c[selection - 1]);

			break;
		}

		case 0:
		{
			return 0;

		}

		default:
		{
			break;
		}

		}
		cout << endl;

	} while (1);



}

void failCheck() {


	//czyszczenie bledow wprowadzania

	if (cin.fail()) {
		cout << "\nBledna wartosc\n";
		cin.clear();
		cin.ignore(200000, '\n');

	}

}

void factoryTest(Company &c) {

	Factory *f = dynamic_cast<Factory*>(&c);
	if (f) {
		cout << "Liczba produktow fabryki: " << f->getNumberOfProducts() << endl;
		for (int i = 0; i < f->getNumberOfProducts(); i++)
			cout << f->getProduct(i);
	}
}

void beautySalonTest(Company &c) {
	BeautySalon *f = dynamic_cast<BeautySalon*>(&c);
	if (f) {
		f->doService();
	}


}

void hairdressersTest(Company &c) {
	Hairdressers *f = dynamic_cast<Hairdressers*>(&c);
	if (f) {
		f->doService();
	}
}

void companyTest(Company &c) {

	int option, end = 0;

	do {
		cout << "\n\nMenu glowne:\n0. Zapis do pliku\n1. Prezentacja pracownikow zakladu\n2. Wyswietlenie powierzchni\n3. Zmiana powierzchni\n4. Przejdz do szczegolowych informacji i powroc\n";

		cout << "\nTwoj wybor: ";
		do {
			cin >> option;
			failCheck();
		} while (option < 0 || cin.fail());

		switch (option) {
		case 0:
		{
			c.outputFile();
			break;
		}
		case 1:
		{
			c.presentEmployees();
			break;
		}
		case 2:
		{
			cout << "Powierzchnia zakladu: " << c.getArea();
			break;
		}
		case 3:
		{
			c.changeArea();
			break;

		}



		case 4: {
			end = 1;
			break;
		}
		default:
		{
			end = 0;
			break;
		}
		}


	} while (!end);
}

void chimneyTest()
{
	Chimney c;
	c.inputFile();

	c.outputFile();
}

void employeeTest() {

	Employee c;
	c.inputFile();

	c.outputFile();

}

void productTest()
{
	Product c;
	c.inputFile();

	c.outputFile();
	
}
