#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;

struct Data {
	int zi;
	int luna;
	int an;
};

class Carte {
private:
	const int id_carte = 0;
	char* nume_carte = nullptr;
	char* nume_autor = nullptr;
	bool stare = 0;
	int nr_imprumuturi = 0;
	int* id_imprumuturi = nullptr;
	static int nr_carti;
	int nr_zile_inchiriata = 0;
	static short int inchirieri_pe_zi[365];
	Data data_inchiriere{ 0,0,0 };
	Data data_retur{ 0,0,0 };

public:

	Carte();
	Carte(const char* _nume_carte, const char* _nume_autor, int _nr_imprumuturi, int _id_imprumuturi[]);
	Carte(int _nr_imprumuturi, int _id_imprumuturi[]);
	Carte(const Carte& obj);
	Carte operator=(const Carte& obj);

	virtual void afisare();
	void adaugare_imprumut(int id);

	const char* get_nume_carte();
	void set_nume_carte(const char* nume_c);

	const char* get_nume_autor();
	void set_nume_autor(const char* nume_a);

	bool& get_stare();
	void set_stare(bool _stare);

	int get_id_carte() const;

	int& get_nr_imprumuturi();
	void set_nr_imprumuturi(int _nr_imprumuturi);

	int get_nr_zile_inchiriata();
	void set_nr_zile_inchiriata(int nr);

	int& get_zi_inchiriere();
	int& get_luna_inchiriere();
	int& get_an_inchiriere();

	int& get_zi_retur();
	int& get_luna_retur();
	int& get_an_retur();

	void set_zi_inchiriere(int nr);
	void set_luna_inchiriere(int nr);
	void set_an_inchiriere(int nr);

	void set_zi_retur(int nr);
	void set_luna_retur(int nr);
	void set_an_retur(int nr);



	int* get_id_imprumuturi();
	void set_id_imprumuturi(int _nr_imprumuturi);
	void* operator new(size_t dim);


	friend ostream& operator<<(ostream& os, const Carte& obj);
	friend istream& operator>>(istream& is, Carte& obj);

	int operator[](int idx);

	virtual void set_inchiriata();
	virtual void set_returnata();

	void incrementare_inchiriere(int i);
	virtual int calcul_zile_inchiriata();
	void afisare_inchirieri_pe_zile();


	virtual ~Carte();
};


class Angajat {
private:
	char* nume = nullptr;
	double salariu = 0;
	int nr_salarii_anterioare = 0;
	int norma = 8;
	double* salarii_anterioare = nullptr;
	const int id_angajat = 0;
	static int nr_angajati;

public:
	Angajat();
	Angajat(const char* _nume, double _salariu, int _nr_salarii_anterioare, int _norma, double _salarii_anterioare[]);
	Angajat(const char* _nume, double _salariu, int _norma);
	Angajat(const Angajat& obj);
	Angajat& operator=(const Angajat& obj);

	virtual double calcul_salariu_real();

	const char* get_nume();
	void set_nume(const char* _nume);

	double& get_salariu();
	void set_salariu(double sal);

	int get_nr_salarii_anterioare();
	double* get_salarii_anterioare();

	int& get_norma();
	void set_norma(int n);

	static int get_nr_angajati();

	friend ostream& operator<<(ostream& os, Angajat& obj);
	friend istream& operator>>(istream& is, Angajat& obj);
	virtual void afisare();

	double operator[](int idx);
	Angajat& operator+(const int sum);

	Angajat& operator--();
	Angajat& operator--(int);

	Angajat& operator++();
	Angajat& operator++(int);

	operator double();
	operator int();
	operator char* ();

	bool operator!();
	bool operator>(const Angajat& obj);
	bool operator<(const Angajat& obj);
	bool operator>=(const Angajat& obj);
	bool operator<=(const Angajat& obj);

	bool operator==(const Angajat& obj);


	virtual ~Angajat();
};

class Client {
private:
	const int id_client = 0;
	char* nume_client = nullptr;
	int nr_carti_imprumutate = 0;
	int* id_carti_imprumutate = nullptr;
	char* email = nullptr;
	static int nr_clienti;
public:
	Client(const char* _nume_client, int _nr_carti_imprumutate, int _id_carti_imprumutate[], const char* _email);
	Client();
	Client(const char* _nume_client, const char* _email);
	Client(const Client& obj);
	Client& operator=(const Client& obj);

	void afisare();
	void add_imprumut(int id_carte);
	friend ostream& operator<<(ostream& os, const Client& obj);
	friend istream& operator>>(istream& is, Client& obj);

	const char* get_nume_client();
	void set_nume_client(const char* nume);

	int get_id_client() const;

	const char* get_email();
	void set_email(const char* mail);

	int get_nr_carti_imprumutate() const;
	void set_nr_carti_imprumutate(int idx);

	void set_id_carti_imprumutate(int idx);

	static int get_nr_clienti();
	~Client();
};

class Inventar {
private:
	int nr_copii = 0;
	int* conditie_carti = nullptr;
	char* ISBN = nullptr;
	static int nr_tipuri_carti;
public:
	Inventar();
	Inventar(const char* _ISBN, int _nr_copii, int _conditie_carti[]);
	Inventar(const char* _ISBN);
	Inventar(const Inventar& obj);
	Inventar& operator=(const Inventar& obj);

	void afisare();
	void adauga_copie(int cond);

	friend ostream& operator<<(ostream& os, const Inventar& obj);
	friend istream& operator>>(istream& is, Inventar& obj);

	int& get_nr_copii();
	void set_nr_copii(int idx);
	void* operator new(size_t dim);
	void operator delete(void* p);

	void set_conditie_carti(int idx);

	const char* get_ISBN();
	void set_ISBN(const char* str);

	static int& get_nr_tipuri_carte();
	~Inventar();
};


class Colectie_carte {
private:
	char* nume_colectie = nullptr;
	vector <Inventar> inv;
public:
	Colectie_carte();
	Colectie_carte(const char* nume, vector<Inventar> _inv);
	Colectie_carte(const Colectie_carte& obj);
	Colectie_carte& operator=(const Colectie_carte& obj);

	void afisare();
	void reducere_dimensiune_colectie(int idx);

	void get_inv();
	const char* get_nume_colectie();
	void set_nume_colectie(const char* str);

	friend ostream& operator<<(ostream& os, const Colectie_carte& obj);
	friend istream& operator>>(istream& is, Colectie_carte& obj);

	~Colectie_carte();
};


class Proces {
public:
	virtual void afisare() = 0;
	virtual int calcul_diferenta_zile() = 0;
	virtual double calcul_taxa_intarziere() = 0;
};

class Retur_inainte_de_termen :public Proces {
private:
	Data data_retur_actual = { 0,0,0 };
	Data data_retur = { 0,0,0 };
	Data data_inchiriere = { 0, 0, 0 };
	double taxa_intarziere;
public:
	Retur_inainte_de_termen();
	Retur_inainte_de_termen(Data drt, Data dr, Data di, double ti);
	Retur_inainte_de_termen(const Retur_inainte_de_termen& obj);
	Retur_inainte_de_termen& operator=(const Retur_inainte_de_termen& obj);

	virtual void afisare();
	virtual int calcul_diferenta_zile();
	virtual double calcul_taxa_intarziere();

	virtual ~Retur_inainte_de_termen();
};

class Retur_dupa_termen :public Proces {
private:
	Data data_retur_actual = { 0,0,0 };
	Data data_retur = { 0,0,0 };
	Data data_inchiriere = { 0, 0, 0 };
	double taxa_intarziere;
public:
	Retur_dupa_termen();
	Retur_dupa_termen(Data drt, Data dr, Data di, double ti);
	Retur_dupa_termen(const Retur_dupa_termen& obj);
	Retur_dupa_termen& operator=(const Retur_dupa_termen& obj);

	virtual void afisare();
	virtual int calcul_diferenta_zile();
	virtual double calcul_taxa_intarziere();

	virtual ~Retur_dupa_termen();
};

class Pierdere_carte :public Proces {
private:
	Data data_inchiriere = { 0, 0, 0 };
	double taxa_pierdere;
public:
	Pierdere_carte();
	Pierdere_carte(Data di, double tp);
	Pierdere_carte(const Pierdere_carte& obj);
	Pierdere_carte& operator=(const Pierdere_carte& obj);

	virtual void afisare();
	virtual int calcul_diferenta_zile();
	virtual double calcul_taxa_intarziere();

	virtual ~Pierdere_carte();
};

class Bibliotecar :public Angajat {
private:
	float bonus;
public:
	Bibliotecar();
	Bibliotecar(const char* _nume, double _salariu, int _nr_salarii_anterioare, int _norma, double _salarii_anterioare[], float _bonus);
	Bibliotecar(const char* _nume, double _salariu, int _norma, float _bonus);
	Bibliotecar(Bibliotecar& obj);
	Bibliotecar& operator=(Bibliotecar& obj);
	virtual void afisare();
	virtual double calcul_salariu_real();

	float& get_bonus();
	void set_bonus(float bns);

	virtual ~Bibliotecar();
};


class Bibliotecar_sef :public Bibliotecar {
private:
	float spor_manager;
public:
	Bibliotecar_sef();
	Bibliotecar_sef(const char* _nume, double _salariu, int _nr_salarii_anterioare, int _norma, double _salarii_anterioare[], float _bonus, float _spor);
	Bibliotecar_sef(const char* _nume, double _salariu, int _norma, float _bonus, float _spor_sef);
	Bibliotecar_sef(Bibliotecar_sef& obj);
	Bibliotecar_sef& operator=(Bibliotecar_sef& obj);

	virtual void afisare();
	virtual double calcul_salariu_real();
	float& get_spor();
	void set_spor(float spor);

	virtual ~Bibliotecar_sef();
};

class Roman :public Carte {
private:
	int limita_zile_imprumut = 0;
public:
	Roman();
	Roman(const char* _nume_carte, const char* _nume_autor, int _nr_imprumuturi, int _id_imprumuturi[], int limita);
	Roman(int _nr_imprumuturi, int _id_imprumuturi[], int limita);
	Roman(Roman& obj);
	Roman& operator=(Roman& obj);

	virtual void afisare();

	virtual void set_inchiriata();
	virtual void set_returnata();
	virtual int calcul_zile_inchiriata();


	virtual ~Roman();
};