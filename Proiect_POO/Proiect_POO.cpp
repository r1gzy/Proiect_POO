// proiect oprea vlad 1057D.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Clase_proiect.h"


int main()
{
	int d[3] = { 14,262,12 };
	Carte c1("O poveste frumoasa", "Ion Barbu", 3, d);
	Carte c2;
	Carte c3(3, d);
	std::cout << c3.get_nume_carte() << std::endl;
	c3 = c1;
	c3.set_nume_autor("Marin Preda");
	c3.set_nume_carte("O scurta poezie");

	std::cout << c3 << std::endl;
	c1.set_inchiriata();
	c1.set_returnata();
	std::cout << endl << "Zile inchiriata: " << c1.get_nr_zile_inchiriata() << std::endl;

	c1.set_inchiriata();
	c1.set_returnata();
	std::cout << endl << "Zile inchiriata: " << c1.get_nr_zile_inchiriata() << std::endl;

	Carte* ptr = new Carte();
	ptr = &c3;
	ptr->set_nr_imprumuturi(4);
	c3.afisare_inchirieri_pe_zile();

	double s[4] = { 4131.13,3900,3786.45,3450 };
	Angajat a1("Popescu Gica", 4030, 4, 8, s);
	Angajat a2;
	a2 = a1;
	a2.set_nume("Ionescu Marin");
	Angajat a3(a2);
	std::cout << a2 << std::endl;
	std::cout << a3[2] << std::endl;
	std::cin >> a3;
	std::cout << a3 << std::endl;

	std::cout << "Salariu inaintede marire: " << a3.get_salariu() << std::endl;
	a3 + 500;
	std::cout << "Salariu dupa marire: " << a3.get_salariu() << std::endl;

	std::cout << "Norma inainte de modificare " << a1.get_norma() << std::endl;
	a1--;
	--a1;
	std::cout << "Norma dupa modificare: " << a1.get_norma() << std::endl;

	std::cout << "Operator cast(double): " << (double)a2 << std::endl;
	std::cout << "Operator cast(int): " << (int)a2 << std::endl;
	std::cout << "Operator cast(char): " << (char*)a2 << std::endl;

	if (!a1)
		std::cout << "Nume de a2 e nullptr." << std::endl;
	else
		std::cout << "Nume de a2 nu e nullptr." << std::endl;
	a1 = a2;
	if (a1 == a2)
		std::cout << "Obiectele sunt egale." << std::endl;
	else
		std::cout << "Obiectele nu sunt egale." << std::endl;
	a2.set_salariu(5788);

	if (a1 > a2)
		std::cout << "A1 are salariul mai mare decat a2." << std::endl;
	else
		std::cout << "A1 are salariul mai mic decat a2." << std::endl;

	int p[4] = { 23,3,12,214 };
	Client cl1;
	Client cl2("Andrei Radu", 4, p, "radu_andrei@yahoo.com");
	Client cl3(cl2);
	std::cout << cl2 << std::endl;
	cl2.add_imprumut(135);
	std::cout << cl2 << std::endl;

	std::cout << "Email: " << cl2.get_email() << std::endl;

	int di[3] = { 14,262,12 };
	Inventar i1;
	Inventar i2("6451184", 3, di);
	Inventar i3(i2);
	i1 = i3;
	std::cout << i1.get_ISBN() << std::endl;
	cin >> i1;
	i1.adauga_copie(144);
	cout << i1;

	std::cout << Inventar::get_nr_tipuri_carte();

	std::vector<Inventar> vi = { i1,i2,i3 };
	Colectie_carte cc1;
	Colectie_carte cc2("gafaf", vi);

	std::cout << std::endl;
	std::cout << cc2 << std::endl;
	cc1 = cc2;
	cin >> cc1;
	cout << cc1;


	Bibliotecar b1("ayfvavf", 1413, 8, 0.05);
	Angajat* ptb1 = &b1;
	ptb1->afisare();
	std::cout << std::endl;
	std::cout << ptb1->calcul_salariu_real() << std::endl;


	Bibliotecar_sef bs1;
	bs1.set_nume("Badea Maria");
	bs1.set_salariu(1000);
	bs1.set_bonus(0.1);
	bs1.set_spor(200);
	Angajat* ptbs1 = &bs1;
	ptbs1->afisare();
	std::cout << ptbs1->calcul_salariu_real() << std::endl;


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file