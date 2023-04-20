#include "Clase_proiect.h"

int Carte::nr_carti = 0;
short int Carte::inchirieri_pe_zi[365] = { 0 };

Carte::Carte(const char* _nume_carte, const char* _nume_autor, int _nr_imprumuturi, int _id_imprumuturi[])
	:stare{ 0 }, nr_imprumuturi{ _nr_imprumuturi }, id_carte{ ++nr_carti }, nr_zile_inchiriata{ 0 }, data_inchiriere{ 0,0,0 }, data_retur{ 0,0,0 }
{

	if (nume_carte != nullptr)
		delete[] nume_carte;
	nume_carte = new char[strlen(_nume_carte) + 1];
	strcpy_s(nume_carte, strlen(_nume_carte) + 1, _nume_carte);
	//nume_carte[strlen(_nume_carte)] = '\0';

	if (nume_autor != nullptr)
		delete[] nume_autor;
	nume_autor = new char[strlen(_nume_autor) + 1];
	strcpy_s(nume_autor, strlen(_nume_autor) + 1, _nume_autor);
	//nume_autor[strlen(_nume_autor)] = '\0';

	if (nr_imprumuturi > 0)
	{
		id_imprumuturi = new int[nr_imprumuturi];
		for (int i = 0; i < nr_imprumuturi; i++)
			id_imprumuturi[i] = _id_imprumuturi[i];
	}
	else
		id_imprumuturi = nullptr;

	//std::cout << "Constructor cu toti parametrii - clasa Carte" << std::endl;
}

Carte::Carte(int _nr_imprumuturi, int _id_imprumuturi[])
	:Carte("Default", "Anonim", _nr_imprumuturi, _id_imprumuturi) {
	//std::cout << "Constructor cu 2 parametrii - clasa Carte" << std::endl;
}

Carte::Carte()
	:Carte("Default", "Anonim", 0, nullptr) {
	//std::cout << "Constructor implicit - clasa Carte" << std::endl;
}

Carte::Carte(const Carte& obj)
	:Carte(obj.nume_carte, obj.nume_autor, obj.nr_imprumuturi, obj.id_imprumuturi) {


	//std::cout << "Constructor copiere - clasa Carte" << std::endl;
}

int& Carte::get_zi_inchiriere()
{
	return data_inchiriere.zi;
}
int& Carte::get_luna_inchiriere()
{
	return data_inchiriere.luna;
}
int& Carte::get_an_inchiriere()
{
	return data_inchiriere.an;
}
int& Carte::get_zi_retur()
{
	return data_retur.zi;
}
int& Carte::get_luna_retur()
{
	return data_retur.luna;
}
int& Carte::get_an_retur()
{
	return data_retur.an;
}


Carte Carte::operator=(const Carte& obj)
{
	if (this == &obj)
		return (*this);
	else
	{
		if (obj.nume_autor != nullptr)
		{
			delete[] nume_autor;
			nume_autor = new char[strlen(obj.nume_autor) + 1];
			strcpy_s(nume_autor, strlen(obj.nume_autor) + 1, obj.nume_autor);
		}
		else
			nume_autor = nullptr;

		if (obj.nume_carte != nullptr)
		{
			delete[] nume_carte;
			nume_carte = new char[strlen(obj.nume_carte) + 1];
			strcpy_s(nume_carte, strlen(obj.nume_carte) + 1, obj.nume_carte);
		}
		else
			nume_carte = nullptr;

		nr_imprumuturi = obj.nr_imprumuturi;
		nr_zile_inchiriata = obj.nr_zile_inchiriata;
		data_inchiriere = obj.data_inchiriere;
		data_retur = obj.data_retur;

		if (nr_imprumuturi > 0)
		{
			delete[] id_imprumuturi;
			id_imprumuturi = new int[nr_imprumuturi];
			for (int i = 0; i < nr_imprumuturi; i++)
				id_imprumuturi[i] = obj.id_imprumuturi[i];
		}
		else
			id_imprumuturi = nullptr;

		return (*this);
	}
}

void* Carte::operator new(size_t dim)
{
	void* p = ::operator new(dim);
	return p;
}

void Carte::afisare()
{
	std::cout << "ID carte: " << id_carte << std::endl;
	std::cout << "Nume carte: " << nume_carte << std::endl;
	std::cout << "Nume autor" << nume_autor << std::endl;
	std::cout << "Starea cartii: " << stare << " - 0(neinchiriata , 1(inchiriata) " << std::endl;
	std::cout << "Numar zile inchiriata: " << nr_zile_inchiriata << std::endl;
	std::cout << "Dati imprumutata: " << nr_imprumuturi << std::endl;
	if (nr_imprumuturi > 0)
	{
		std::cout << "Id clienti care au imprumutat cartea: ";
		for (int i = 0; i < nr_imprumuturi; i++)
			std::cout << id_imprumuturi[i] << " ";

	}

	std::cout << std::endl;
}

void Carte::adaugare_imprumut(int id)
{

	int* temp = id_imprumuturi;
	nr_imprumuturi++;
	id_imprumuturi = new int[nr_imprumuturi];
	for (int i = 0; i < nr_imprumuturi - 1; i++)
		id_imprumuturi[i] = temp[i];

	id_imprumuturi[nr_imprumuturi - 1] = id;
	if (temp != nullptr)
		delete[] temp;
}

const char* Carte::get_nume_carte()
{
	return nume_carte;
}

void Carte::set_nume_carte(const char* _nume_carte)
{
	if (_nume_carte != nullptr)
	{
		delete[] nume_carte;
		nume_carte = new char[strlen(_nume_carte) + 1];
		strcpy_s(nume_carte, strlen(_nume_carte) + 1, _nume_carte);
	}
	else nume_carte = nullptr;
}

const char* Carte::get_nume_autor()
{
	return nume_autor;
}

void Carte::set_nume_autor(const char* _nume_autor)
{
	if (_nume_autor != nullptr)
	{
		delete[] nume_autor;
		nume_autor = new char[strlen(_nume_autor) + 1];
		strcpy_s(nume_autor, strlen(_nume_autor) + 1, _nume_autor);
	}
	else
		nume_autor = nullptr;
}

int Carte::get_id_carte() const
{
	return id_carte;
}

bool& Carte::get_stare()
{
	if (stare == 0 || stare == 1)
		return stare;
}

void Carte::set_stare(bool _stare)
{
	if (_stare = 0 || _stare == 1)
		stare = _stare;
}

int& Carte::get_nr_imprumuturi()
{
	if (nr_imprumuturi >= 0)
		return nr_imprumuturi;
}

int* Carte::get_id_imprumuturi()
{
	return id_imprumuturi;
}

void Carte::set_nr_imprumuturi(int _nr_imp)
{
	if (_nr_imp >= 0)
		nr_imprumuturi = _nr_imp;
	Carte::set_id_imprumuturi(_nr_imp);
}

void Carte::set_nr_zile_inchiriata(int nr)
{
	nr_zile_inchiriata = nr;
}
void Carte::set_id_imprumuturi(int _nr_imp)
{
	if (_nr_imp > 0)
	{
		if (id_imprumuturi != nullptr)
			delete[] id_imprumuturi;
		id_imprumuturi = new int[_nr_imp];

		for (int i = 0; i < _nr_imp; i++)
		{
			std::cout << "Id-ul clientului de pe pozitia " << i + 1 << " este: "; std::cin >> id_imprumuturi[i];
		}
	}
	else
		id_imprumuturi = nullptr;
}

ostream& operator<<(ostream& os, const Carte& obj)
{
	os << "Id carte: " << obj.id_carte << std::endl;
	os << "Nume carte: " << obj.nume_carte << std::endl;
	os << "Nume autor: " << obj.nume_autor << std::endl;;
	os << "Starea cartii: " << obj.stare << " - 0(neinchiriata), 1(inchiriata) " << std::endl;
	os << "Dati imprumutata: " << obj.nr_imprumuturi << std::endl;
	if (obj.nr_imprumuturi > 0)
	{
		os << "Id clienti care au imprumutat cartea: ";
		for (int i = 0; i < obj.nr_imprumuturi; i++)
			os << obj.id_imprumuturi[i] << " ";

	}

	os << std::endl;
	return os;
}

istream& operator>>(istream& is, Carte& obj)
{
	std::cout << "Nume carte: ";
	char* nc = new char[255];
	is >> nc;
	if (nc != nullptr)
	{
		delete[] obj.nume_carte;
		obj.nume_carte = new char[strlen(nc) + 1];
		strcpy_s(obj.nume_carte, strlen(nc) + 1, nc);
		std::cout << "Nume autor: ";
	}
	delete[] nc;

	char* na = new char[255];
	is >> na;
	if (na != nullptr)
	{
		delete[] obj.nume_autor;
		obj.nume_autor = new char[strlen(na) + 1];
		strcpy_s(obj.nume_autor, strlen(na) + 1, na);
	}
	delete[] na; 
		std::cout << "Dati imprumutata: ";
	is >> obj.nr_imprumuturi;
	if (obj.nr_imprumuturi > 0)
	{
		obj.id_imprumuturi = new int[obj.nr_imprumuturi];
		std::cout << "Id clienti care au imprumutat cartea: " << std::endl;
		for (int i = 0; i < obj.nr_imprumuturi; i++)
		{
			std::cout << "Id-ul de pe pozitia " << i + 1 << " are valoarea: ";
			is >> obj.id_imprumuturi[i];
		}

	}

	std::cout << std::endl;
	return is;
}

int Carte::operator[](int idx)
{
	if (idx >= 0 && idx < 365)
		return inchirieri_pe_zi[idx];
}

int Carte::get_nr_zile_inchiriata()
{
	return nr_zile_inchiriata;
}

void Carte::set_inchiriata()
{
	int id;
	std::cout << "ID client: "; std::cin >> id;
	stare = 1;
	std::cout << "Zi inchiriere: "; std::cin >> data_inchiriere.zi;
	std::cout << "Luna inchiriere: "; std::cin >> data_inchiriere.luna;
	std::cout << "An inchiriere: "; std::cin >> data_inchiriere.an;

	Carte::incrementare_inchiriere(data_inchiriere.zi + 31 * (data_inchiriere.luna - 1));


	std::cout << "Zi pt retur: "; std::cin >> data_retur.zi;
	std::cout << "Luna pt retur: "; std::cin >> data_retur.luna;
	std::cout << "An pt retur: "; std::cin >> data_retur.an;
	Carte::adaugare_imprumut(id);

}

void Carte::set_returnata()
{
	stare = 0;
	std::cout << "Zi retur: "; std::cin >> data_retur.zi;
	std::cout << "Luna retur: "; std::cin >> data_retur.luna;
	std::cout << "An retur: "; std::cin >> data_retur.an;
	nr_zile_inchiriata = nr_zile_inchiriata + calcul_zile_inchiriata();
}

int Carte::calcul_zile_inchiriata()
{
	int zile = 0;
	if (data_retur.an == data_inchiriere.an)
	{
		if (data_retur.luna == data_inchiriere.luna)
		{
			zile = data_retur.zi - data_inchiriere.zi;
		}
		else if (data_retur.luna > data_inchiriere.luna)
		{
			zile = (data_retur.luna - data_inchiriere.luna) * 30 + (data_retur.zi - data_inchiriere.zi);
		}
	}
	else if (data_retur.an > data_inchiriere.an)
	{
		zile = (data_retur.an - data_inchiriere.an) * 365 - (data_retur.luna - data_inchiriere.luna) * 30 - (data_retur.zi - data_inchiriere.zi);
	}

	return zile;
}

void Carte::incrementare_inchiriere(int i) {

	inchirieri_pe_zi[i]++;
}

void Carte::afisare_inchirieri_pe_zile()
{
	for (int i = 0; i < 365; i++)
	{
		if (inchirieri_pe_zi[i] > 0)
			std::cout << "In ziua " << i + 1 << " a anului curent s-au inchiriat: " << inchirieri_pe_zi[i] << " carti" << std::endl;
	}
}

Carte::~Carte() {
	delete[] nume_carte;
	nume_carte = nullptr;
	delete[] nume_autor;
	nume_autor = nullptr;
	delete[] id_imprumuturi;
	id_imprumuturi = nullptr;

	nr_carti--;


	//std::cout << "Destructor - clasa Carte" << std::endl;
}

int Angajat::nr_angajati = 0;

Angajat::Angajat(const char* _nume, double _salariu, int _nr_salarii_anterioare, int _norma, double _salarii_anterioare[])
	:id_angajat{ ++nr_angajati }, salariu{ _salariu }, nr_salarii_anterioare{ _nr_salarii_anterioare }, norma{ _norma }{
	if (_nume != nullptr)
	{
		delete[] nume;
		nume = new char[strlen(_nume) + 1];
		strcpy_s(nume, strlen(_nume) + 1, _nume);
	}

	if (nr_salarii_anterioare > 0)
	{
		delete[] salarii_anterioare;
		salarii_anterioare = new double[nr_salarii_anterioare];
		for (int i = 0; i < nr_salarii_anterioare; i++)
			salarii_anterioare[i] = _salarii_anterioare[i];
	}
}

Angajat::Angajat()
	:Angajat("Anonim", 0, 0, 8, 0) {

}

Angajat::Angajat(const char* _nume, double _salariu, int _norma)
	:Angajat(_nume, _salariu, 0, _norma, 0) {

}

Angajat::Angajat(const Angajat& obj)
	:Angajat(obj.nume, obj.salariu, obj.nr_salarii_anterioare, obj.norma, obj.salarii_anterioare) {
}

Angajat::~Angajat() {
	if (nume != nullptr)
		delete[] nume;
	if (salarii_anterioare != nullptr)
		delete[] salarii_anterioare;

	nr_angajati--;
}

Angajat& Angajat::operator=(const Angajat& obj)
{
	if (this == &obj)
		return *this;
	else
	{
		if (obj.nume != nullptr)
		{
			delete[] nume;
			nume = new char[strlen(obj.nume) + 1];
			strcpy_s(nume, strlen(obj.nume) + 1, obj.nume);
		}
		else nume = nullptr;
		salariu = obj.salariu;
		nr_salarii_anterioare = obj.nr_salarii_anterioare;
		norma = obj.norma;

		if (nr_salarii_anterioare > 0)
		{
			delete[] salarii_anterioare;
			salarii_anterioare = new double[nr_salarii_anterioare];
			for (int i = 0; i < nr_salarii_anterioare; i++)
				salarii_anterioare[i] = obj.salarii_anterioare[i];
		}
		else
			salarii_anterioare = nullptr;

		return *this;
	}
}

void Angajat::afisare()
{
	std::cout << "Id angajat: " << id_angajat << std::endl;
	std::cout << "Nume angajat: " << nume << std::endl;
	std::cout << "Salariu angajat/norma intreaga: " << salariu << std::endl;
	std::cout << "Norma: " << norma << std::endl;
	std::cout << "Numar salarii anterioare: " << nr_salarii_anterioare << std::endl;

	std::cout << "Salarii anterioare: ";
	if (nr_salarii_anterioare > 0)
	{
		for (int i = 0; i < nr_salarii_anterioare; i++)
			std::cout << salarii_anterioare[i] << " ";
	}
	else
		std::cout << "0";

	std::cout << std::endl << "Numar total de angajati: " << nr_angajati;
	std::cout << std::endl;
}

double Angajat::calcul_salariu_real()
{
	return (salariu * norma) / 8;
}

const char* Angajat::get_nume()
{
	return nume;
}

void Angajat::set_nume(const char* _nume)
{
	if (_nume != nullptr)
	{
		delete[] nume;
		nume = new char[strlen(_nume) + 1];
		strcpy_s(nume, strlen(_nume) + 1, _nume);
	}
}

double& Angajat::get_salariu() {
	return salariu;
}

void Angajat::set_salariu(double sal)
{
	if (sal > 0)
	{
		nr_salarii_anterioare++;
		double* temp = salarii_anterioare;
		salarii_anterioare = new double[nr_salarii_anterioare];
		for (int i = 0; i < nr_salarii_anterioare - 1; i++)
			salarii_anterioare[i] = temp[i];
		salarii_anterioare[nr_salarii_anterioare - 1] = salariu;
		salariu = sal;

		if (temp != nullptr)
			delete[] temp;
	}
}


int Angajat::get_nr_salarii_anterioare()
{
	return nr_salarii_anterioare;
}

double* Angajat::get_salarii_anterioare()
{
	return salarii_anterioare;
}

int& Angajat::get_norma()
{
	return norma;
}

void Angajat::set_norma(int n)
{
	if (n > 0 && n < 24)
		norma = n;
}

ostream& operator<<(ostream& os, Angajat& obj)
{
	os << "Id angajat: " << obj.id_angajat << std::endl;
	os << "Nume angajat: " << obj.nume << std::endl;
	os << "Salariu: " << obj.salariu << std::endl;
	os << "Norma: " << obj.norma << std::endl;
	os << "Nr salarii anterioare: " << obj.nr_salarii_anterioare << std::endl;
	os << "Salarii anterioare: ";
	if (obj.nr_salarii_anterioare > 0)
	{
		for (int i = 0; i < obj.nr_salarii_anterioare; i++)
			os << obj.salarii_anterioare[i] << " ";
	}
	os << std::endl;
	return os;
}

istream& operator>>(istream& is, Angajat& obj)
{
	char* n = new char[255];
	std::cout << "Nume angajat "; is >> n;
	if (n != nullptr)
	{
		delete[] obj.nume;
		obj.nume = new char[strlen(n) + 1];
		strcpy_s(obj.nume, strlen(n) + 1, n);
	}
	delete[]n;
	std::cout << "Salariu: "; is >> obj.salariu;
	std::cout << "Norma: "; is >> obj.norma;
	std::cout << "Nr salarii anterioare: "; is >> obj.nr_salarii_anterioare;

	if (obj.nr_salarii_anterioare > 0)
	{
		delete[] obj.salarii_anterioare;
		obj.salarii_anterioare = new double[obj.nr_salarii_anterioare];
		for (int i = 0; i < obj.nr_salarii_anterioare; i++)
		{
			std::cout << "Salariul de pe pozitia " << i + 1 << " este: ";
			is >> obj.salarii_anterioare[i];
		}
	}
	return is;
}

double Angajat::operator[](int idx)
{
	if (idx >= 0 && idx < nr_salarii_anterioare)
		return salarii_anterioare[idx];
	else
		return -1;
}

Angajat& Angajat::operator+(const int sum)
{
	salariu += sum;
	return (*this);
}

Angajat& Angajat::operator--()
{
	norma--;
	return (*this);
}

Angajat& Angajat::operator--(int)
{
	norma--;
	return *this;
}

Angajat& Angajat::operator++()
{
	norma++;
	return (*this);
}

Angajat& Angajat::operator++(int)
{
	norma++;
	return *this;
}

Angajat::operator double()
{
	return salariu;
}

int Angajat::get_nr_angajati()
{
	return nr_angajati;
}

Angajat::operator int()
{
	return norma;
}

Angajat::operator char* ()
{
	return nume;
}

bool Angajat::operator!()
{
	if (salarii_anterioare == nullptr)
		return 1;
	else
		return 0;
}

bool Angajat::operator>(const Angajat& obj)
{
	if (salariu > obj.salariu)
		return 1;
	else
		return 0;
}

bool Angajat::operator<(const Angajat& obj)
{
	if (salariu < obj.salariu)
		return 1;
	else
		return 0;
}

bool Angajat::operator>=(const Angajat& obj)
{
	if (salariu >= obj.salariu)
		return 1;
	else
		return 0;
}

bool Angajat::operator<=(const Angajat& obj)
{
	if (salariu <= obj.salariu)
		return 1;
	else
		return 0;
}

bool Angajat::operator==(const Angajat& obj)
{
	if ((*nume) == (*obj.nume) && salariu == obj.salariu && norma == obj.norma && nr_salarii_anterioare == obj.nr_salarii_anterioare)
	{
		for (int i = 0; i < nr_salarii_anterioare; i++)
		{
			if (salarii_anterioare[i] != obj.salarii_anterioare[i])
				return 0;
		}

		return 1;
	}
	else
		return 0;
}

int Client::nr_clienti = 0;

Client::Client(const char* _nume_client, int _nr_carti_imprumutate, int _id_carti_imprumutate[], const char* _email)
	:id_client{ ++nr_clienti }, nr_carti_imprumutate{ _nr_carti_imprumutate }{
	if (_nume_client != nullptr)
	{
		delete[] nume_client;
		nume_client = new char[strlen(_nume_client) + 1];
		strcpy_s(nume_client, strlen(_nume_client) + 1, _nume_client);
	}
	if (_email != nullptr)
	{
		delete[] email;
		email = new char[strlen(_email) + 1];
		strcpy_s(email, strlen(_email) + 1, _email);
	}

	if (nr_carti_imprumutate > 0)
	{
		delete[] id_carti_imprumutate;
		id_carti_imprumutate = new int[nr_carti_imprumutate];
		for (int i = 0; i < nr_carti_imprumutate; i++)
			id_carti_imprumutate[i] = _id_carti_imprumutate[i];
	}

}

Client::Client()
	:Client("Anonim", 0, 0, "nespecificat") {

}

Client::Client(const char* _nume_client, const char* _email)
	:Client(_nume_client, 0, 0, "nespecificat") {

}

Client::Client(const Client& obj)
	:Client(obj.nume_client, obj.nr_carti_imprumutate, obj.id_carti_imprumutate, obj.email) {

}

Client& Client::operator=(const Client& obj)
{
	if (this == &obj)
		return (*this);
	else
	{
		if (obj.nume_client != nullptr)
		{
			delete[] nume_client;
			nume_client = new char[strlen(obj.nume_client) + 1];
			strcpy_s(nume_client, strlen(obj.nume_client) + 1, obj.nume_client);
		}
		else
			nume_client = nullptr;

		if (obj.email != nullptr)
		{
			delete[] email;
			email = new char[strlen(obj.email) + 1];
			strcpy_s(email, strlen(obj.email) + 1, obj.email);
		}
		else
			email = nullptr;

		nr_carti_imprumutate = obj.nr_carti_imprumutate;
		if (nr_carti_imprumutate > 0)
		{
			delete[] id_carti_imprumutate;
			id_carti_imprumutate = new int[nr_carti_imprumutate];
			for (int i = 0; i < nr_carti_imprumutate; i++)
				id_carti_imprumutate[i] = obj.id_carti_imprumutate[i];
		}
		else
			id_carti_imprumutate = nullptr;
	}
}

void Client::afisare()
{
	std::cout << "Id client: " << id_client << std::endl;
	std::cout << "Nume client: " << nume_client << std::endl;
	std::cout << "Email client: " << email << std::endl;
	std::cout << "Nr carti imprumutate: " << nr_carti_imprumutate << std::endl;
	std::cout << "Id carti imprumutate: ";

	if (nr_carti_imprumutate > 0)
	{
		for (int i = 0; i < nr_carti_imprumutate; i++)
			std::cout << id_carti_imprumutate[i] << " ";
	}
	else std::cout << "Clientul nu a imprumutat carti.";

	std::cout << std::endl << "Numar clienti: " << nr_clienti << std::endl;
}

ostream& operator<<(ostream& os, const Client& obj)
{

	os << "Id client: " << obj.id_client << std::endl;
	os << "Nume client: " << obj.nume_client << std::endl;
	os << "Email client: " << obj.email << std::endl;
	os << "Nr carti imprumutate: " << obj.nr_carti_imprumutate << std::endl;
	os << "Id carti imprumutate: ";

	if (obj.nr_carti_imprumutate > 0)
	{
		for (int i = 0; i < obj.nr_carti_imprumutate; i++)
			os << obj.id_carti_imprumutate[i] << " ";
	}
	else os << "Clientul nu a imprumutat carti.";

	os << std::endl << "Numar clienti: " << obj.nr_clienti << std::endl;
	return os;
}

istream& operator>>(istream& is, Client& obj)
{
	char* temp = new char[255];
	std::cout << "Nume client: "; is >> temp;
	if (temp != nullptr)
	{
		delete[] obj.nume_client;
		obj.nume_client = new char[strlen(temp) + 1];
		strcpy_s(obj.nume_client, strlen(temp) + 1, temp);
	}
	delete[] temp;

	char* t = new char[255];
	std::cout << "Email: "; is >> t;
	if (t != nullptr)
	{
		delete[] obj.email;
		obj.email = new char[strlen(t) + 1];
		strcpy_s(obj.email, strlen(t) + 1, t);
	}
	delete[] t;

	std::cout << "Nr carti imprumutate: "; is >> obj.nr_carti_imprumutate;
	if (obj.nr_carti_imprumutate > 0)
	{
		if (obj.id_carti_imprumutate != nullptr)
			delete[] obj.id_carti_imprumutate;
		obj.id_carti_imprumutate = new int[obj.nr_carti_imprumutate];
		for (int i = 0; i < obj.nr_carti_imprumutate; i++)
		{
			is >> obj.id_carti_imprumutate[i];
		}
	}

	return is;

}

const char* Client::get_nume_client()
{
	return nume_client;
}

void Client::set_nume_client(const char* nume)
{
	if (nume_client != nullptr)
	{
		delete[] nume_client;
		nume_client = new char[strlen(nume) + 1];
		strcpy_s(nume_client, strlen(nume) + 1, nume);
	}
	else
		nume_client = nullptr;
}

int Client::get_id_client() const
{
	return id_client;
}

const char* Client::get_email()
{
	return email;
}

void Client::set_email(const char* _email)
{
	if (email != nullptr)
	{
		delete[] email;
		email = new char[strlen(_email) + 1];
		strcpy_s(email, strlen(_email) + 1, _email);
	}
	else
		email = nullptr;
}

int Client::get_nr_carti_imprumutate() const
{
	return nr_carti_imprumutate;
}


void Client::set_nr_carti_imprumutate(int idx)
{
	nr_carti_imprumutate = idx;
	Client::set_id_carti_imprumutate(nr_carti_imprumutate);
}

int Client::get_nr_clienti()
{
	return nr_clienti;
}

void Carte::set_zi_inchiriere(int nr)
{
	data_inchiriere.zi = nr;
}
void Carte::set_luna_inchiriere(int nr)
{
	data_inchiriere.luna = nr;
}
void Carte::set_an_inchiriere(int nr)
{
	data_inchiriere.an = nr;
}

void Carte::set_zi_retur(int nr)
{
	data_retur.zi = nr;
}
void Carte::set_luna_retur(int nr)
{
	data_retur.luna = nr;
}
void Carte::set_an_retur(int nr)
{
	data_retur.an = nr;
}

void Client::add_imprumut(int id_carte)
{
	nr_carti_imprumutate++;
	int* temp = id_carti_imprumutate;

	if (nr_carti_imprumutate > 0)
	{
		id_carti_imprumutate = new int[nr_carti_imprumutate];
		for (int i = 0; i < nr_carti_imprumutate - 1; i++)
			id_carti_imprumutate[i] = temp[i];
		id_carti_imprumutate[nr_carti_imprumutate - 1] = id_carte;
	}
	if (temp != nullptr)
		delete[] temp;
}

void Client::set_id_carti_imprumutate(int idx)
{
	if (idx > 0)
	{
		if (id_carti_imprumutate != nullptr)
			delete[] id_carti_imprumutate;
		id_carti_imprumutate = new int[idx];

		for (int i = 0; i < idx; i++)
		{
			std::cout << "Id-ul de pe pozitia " << i + 1 << " este: "; std::cin >> id_carti_imprumutate[i];
		}
	}
	else
		id_carti_imprumutate = nullptr;
}

Client::~Client() {
	if (nume_client != nullptr)
		delete[] nume_client;
	if (email != nullptr)
		delete[] email;
	if (id_carti_imprumutate != nullptr)
		delete[] id_carti_imprumutate;
	--nr_clienti;
}


int Inventar::nr_tipuri_carti = 0;

Inventar::Inventar(const char* _ISBN, int _nr_copii, int _conditie_carti[])
	:nr_copii{ _nr_copii } {
	++nr_tipuri_carti;
	if (_ISBN != nullptr)
	{
		delete[] ISBN;
		ISBN = new char[strlen(_ISBN) + 1];
		strcpy_s(ISBN, strlen(_ISBN) + 1, _ISBN);

	}
	else
		ISBN = nullptr;

	if (nr_copii > 0)
	{
		delete[] conditie_carti;
		conditie_carti = new int[nr_copii];
		for (int i = 0; i < nr_copii; i++)
			conditie_carti[i] = _conditie_carti[i];
	}
	else
		conditie_carti = nullptr;
}

Inventar::Inventar()
	:Inventar("000000000000", 0, nullptr) {

}

Inventar::Inventar(const char* _ISBN)
	:Inventar(_ISBN, 0, nullptr) {

}

Inventar::Inventar(const Inventar& obj)
	:Inventar(obj.ISBN, obj.nr_copii, obj.conditie_carti) {

}

Inventar& Inventar::operator=(const Inventar& obj)
{
	if (this == (&obj))
		return (*this);
	else
	{
		if (obj.ISBN != nullptr)
		{
			delete[] ISBN;
			ISBN = new char[strlen(obj.ISBN) + 1];
			strcpy_s(ISBN, strlen(obj.ISBN) + 1, obj.ISBN);
		}
		else
			ISBN = nullptr;

		nr_copii = obj.nr_copii;
		if (nr_copii > 0)
		{
			if (obj.conditie_carti != nullptr)
			{
				delete[] conditie_carti;
				conditie_carti = new int[nr_copii];
				for (int i = 0; i < nr_copii; i++)
					conditie_carti[i] = obj.conditie_carti[i];

			}
			else
				conditie_carti = nullptr;
		}
		else
			conditie_carti = nullptr;
		return (*this);
	}
}

void Inventar::afisare()
{
	std::cout << "ISBN: " << ISBN << std::endl;
	std::cout << "Nr copii: " << nr_copii << std::endl;
	std::cout << "Conditia cartiilor: ";
	if (nr_copii > 0)
	{
		for (int i = 0; i < nr_copii; i++)
			std::cout << conditie_carti[i] << " ";

	}
	else
		std::cout << "0";
	std::cout << std::endl << "Nr tipuri de carti: " << nr_tipuri_carti << std::endl;
}

void Inventar::adauga_copie(int cond)
{
	nr_copii++;
	int* temp = conditie_carti;
	if (nr_copii > 0)
	{
		conditie_carti = new int[nr_copii];
		for (int i = 0; i < nr_copii - 1; i++)
			conditie_carti[i] = temp[i];
		conditie_carti[nr_copii - 1] = cond;

	}
	if (temp != nullptr)
		delete[] temp;
}

ostream& operator<<(ostream& os, const Inventar& obj)
{
	os << "ISBN: " << obj.ISBN << std::endl;
	os << "Numar copii: " << obj.nr_copii << std::endl;
	if (obj.nr_copii > 0)
	{
		os << "Conditie carti: ";
		for (int i = 0; i < obj.nr_copii; i++)
			os << obj.conditie_carti[i] << " ";
	}

	os << std::endl << "Numar exemplare: " << Inventar::nr_tipuri_carti << std::endl;
	return os;
}

istream& operator>>(istream& is, Inventar& obj)
{
	char* temp = new char[255];
	std::cout << "ISBN: "; is >> temp;
	if (temp != nullptr)
	{
		delete[] obj.ISBN;
		obj.ISBN = new char[strlen(temp) + 1];
		strcpy_s(obj.ISBN, strlen(temp) + 1, temp);
	}
	else
		obj.ISBN = nullptr;

	if (temp != nullptr)
		delete[] temp;

	std::cout << "Nr exemplare: "; is >> obj.nr_copii;
	if (obj.nr_copii > 0)
	{
		delete[] obj.conditie_carti;
		obj.conditie_carti = new int[obj.nr_copii];
		std::cout << "Starea exemplarelor: ";
		for (int i = 0; i < obj.nr_copii; i++)
			is >> obj.conditie_carti[i];
	}
	return is;
}

int& Inventar::get_nr_copii()
{
	return nr_copii;
}

void Inventar::set_nr_copii(int idx)
{
	if (idx > 0)
		nr_copii = idx;
	Inventar::set_conditie_carti(idx);
}

void Inventar::set_conditie_carti(int idx)
{
	if (idx > 0)
	{
		if (conditie_carti != nullptr)
			delete[] conditie_carti;
		conditie_carti = new int[idx];

		for (int i = 0; i < idx; i++)
		{
			std::cout << "Conditia cartii de pe pozitia " << i + 1 << " este: "; std::cin >> conditie_carti[i];
		}
	}
	else
		conditie_carti = nullptr;
}

const char* Inventar::get_ISBN()
{
	return ISBN;
}

void* Inventar::operator new(size_t dim)
{
	void* p = ::operator new(dim);
	return p;
}

void Inventar::operator delete(void* p)
{
	return::delete p;
}

void Inventar::set_ISBN(const char* str)
{
	if (str != nullptr)
	{
		delete[] ISBN;
		ISBN = new char[strlen(str) + 1];
		strcpy_s(ISBN, strlen(str) + 1, str);
	}
}

int& Inventar::get_nr_tipuri_carte()
{
	return nr_tipuri_carti;
}

Inventar::~Inventar()
{
	if (ISBN != nullptr)
		delete[] ISBN;
	if (conditie_carti != nullptr)
		delete[] conditie_carti;
}

Colectie_carte::Colectie_carte(const char* _nume, vector<Inventar> _inv)
{
	if (_nume != nullptr)
	{
		nume_colectie = new char[strlen(_nume) + 1];
		strcpy_s(nume_colectie, strlen(_nume) + 1, _nume);
	}
	else
		nume_colectie = nullptr;

	inv = _inv;

}

Colectie_carte::Colectie_carte() {
	nume_colectie = new char[strlen("Default") + 1];
	strcpy_s(nume_colectie, strlen("Default") + 1, "Default");
	inv.resize(2);
	for (auto& i : inv)
		i = Inventar();
}

Colectie_carte::Colectie_carte(const Colectie_carte& obj)
	:Colectie_carte(obj.nume_colectie, obj.inv) {

}


Colectie_carte& Colectie_carte::operator=(const Colectie_carte& obj)
{
	if (this == &obj)
		return (*this);
	else
	{
		if (obj.nume_colectie != nullptr)
		{
			delete[] nume_colectie;
			nume_colectie = new char[strlen(obj.nume_colectie) + 1];
			strcpy_s(nume_colectie, strlen(obj.nume_colectie) + 1, obj.nume_colectie);
		}
		else
			nume_colectie = nullptr;

		inv.clear();
		inv.resize(obj.inv.size());
		inv = obj.inv;

		return (*this);
	}
}

void Colectie_carte::afisare()
{
	std::cout << "Nume colectie: " << nume_colectie << std::endl;
	for (auto i : inv)
		std::cout << i << std::endl;
}

void Colectie_carte::reducere_dimensiune_colectie(int idx)
{
	if (idx > 0 && idx < inv.size())
	{
		inv.resize(idx);
	}
}

void Colectie_carte::get_inv()
{
	for (auto i : inv)
		std::cout << i << std::endl;
}

const char* Colectie_carte::get_nume_colectie() {
	return nume_colectie;
}

void Colectie_carte::set_nume_colectie(const char* str)
{
	if (str != nullptr)
	{
		delete[] nume_colectie;
		nume_colectie = new char[strlen(str) + 1];
		strcpy_s(nume_colectie, strlen(str) + 1, str);
	}
	else
		nume_colectie = nullptr;
}

ostream& operator<<(ostream& os, const Colectie_carte& obj)
{
	os << "Nume colectie: " << obj.nume_colectie << std::endl;
	for (auto i : obj.inv)
		os << i << std::endl;
	return os;
}
istream& operator>>(istream& is, Colectie_carte& obj)
{
	char* temp = new char[255];
	std::cout << "Nume colectie: "; is >> temp;
	if (temp != nullptr)
	{
		delete[] obj.nume_colectie;
		obj.nume_colectie = new char[strlen(temp) + 1];
		strcpy_s(obj.nume_colectie, strlen(temp) + 1, temp);
	}
	if (temp != nullptr)
		delete[] temp;
	int k = 0;
	for (int i = 0; i < obj.inv.size(); i++)
	{
		std::cout << "------Cartea: " << k + 1 << std::endl;
		++k;
		is >> obj.inv[i];
	}
	return is;
}

Colectie_carte::~Colectie_carte() {
	if (nume_colectie != nullptr)
		delete[] nume_colectie;
}

Retur_inainte_de_termen::Retur_inainte_de_termen(Data drt, Data dr, Data di, double ti)
	:data_retur_actual{ drt }, data_retur{ dr }, data_inchiriere{ di }, taxa_intarziere{ ti }{

}

Retur_inainte_de_termen::Retur_inainte_de_termen()
	:Retur_inainte_de_termen({ 0,0,0 }, { 0,0,0 }, { 0,0,0 }, 0) {

}

Retur_inainte_de_termen::Retur_inainte_de_termen(const Retur_inainte_de_termen& obj)
	:Retur_inainte_de_termen(obj.data_retur_actual, obj.data_retur, obj.data_inchiriere, obj.taxa_intarziere) {

}

Retur_inainte_de_termen& Retur_inainte_de_termen::operator=(const Retur_inainte_de_termen& obj)
{
	if (this == &obj)
		return *this;
	else
	{
		data_retur_actual = obj.data_retur_actual;
		data_retur = obj.data_retur;
		data_inchiriere = obj.data_inchiriere;
		taxa_intarziere = obj.taxa_intarziere;

		return *this;
	}
}

void Retur_inainte_de_termen::afisare()
{
	std::cout << "Data inchiriere: " << data_inchiriere.zi << "/ " << data_inchiriere.luna << "/ " << data_inchiriere.an << std::endl;
	std::cout << "Data pentru retur: " << data_retur.zi << "/ " << data_retur.luna << "/ " << data_retur.an << std::endl;
	std::cout << "Data retur actual: " << data_retur_actual.zi << "/ " << data_retur_actual.luna << "/ " << data_retur_actual.an << std::endl;
}



int Retur_inainte_de_termen::calcul_diferenta_zile()
{
	int zile = 0;
	if (((data_retur_actual.zi < data_retur.zi) && (data_retur_actual.luna == data_retur.luna) || (data_retur_actual.zi > data_retur.zi) && (data_retur_actual.luna < data_retur.luna) || (data_retur_actual.luna > data_retur.luna) && (data_retur_actual.an < data_retur.an)))
	{
		if (data_retur_actual.an == data_inchiriere.an)
		{
			if (data_retur_actual.luna == data_inchiriere.luna)
			{
				zile = data_retur_actual.zi - data_inchiriere.zi;
			}
			else if (data_retur_actual.luna > data_inchiriere.luna)
			{
				zile = (data_retur_actual.luna - data_inchiriere.luna) * 30 + (data_retur_actual.zi - data_inchiriere.zi);
			}
		}
		else if (data_retur_actual.an > data_inchiriere.an)
		{
			zile = (data_retur_actual.an - data_inchiriere.an) * 365 - (data_retur_actual.luna - data_inchiriere.luna) * 30 - (data_retur_actual.zi - data_inchiriere.zi);
		}
	}

	return zile;
}

double Retur_inainte_de_termen::calcul_taxa_intarziere()
{
	return 0;
}

Retur_inainte_de_termen::~Retur_inainte_de_termen()
{

}

Retur_dupa_termen::Retur_dupa_termen(Data drt, Data dr, Data di, double ti)
	:data_retur_actual{ drt }, data_retur{ dr }, data_inchiriere{ di }, taxa_intarziere{ ti }{

}

Retur_dupa_termen::Retur_dupa_termen()
	:Retur_dupa_termen({ 0,0,0 }, { 0,0,0 }, { 0,0,0 }, 0) {

}

Retur_dupa_termen::Retur_dupa_termen(const Retur_dupa_termen& obj)
	:Retur_dupa_termen(obj.data_retur_actual, obj.data_retur, obj.data_inchiriere, obj.taxa_intarziere) {

}

void Retur_dupa_termen::afisare()
{
	std::cout << "Data inchiriere: " << data_inchiriere.zi << "/ " << data_inchiriere.luna << "/ " << data_inchiriere.an << std::endl;
	std::cout << "Data pentru retur: " << data_retur.zi << "/ " << data_retur.luna << "/ " << data_retur.an << std::endl;
	std::cout << "Data retur actual: " << data_retur_actual.zi << "/ " << data_retur_actual.luna << "/ " << data_retur_actual.an << std::endl;
	std::cout << "Taxa pe zi: " << taxa_intarziere << std::endl;
}

int Retur_dupa_termen::calcul_diferenta_zile()
{
	int zile = 0;
	if (((data_retur_actual.zi > data_retur.zi) && (data_retur_actual.luna == data_retur.luna) || (data_retur_actual.zi < data_retur.zi) && (data_retur_actual.luna > data_retur.luna) || (data_retur_actual.luna < data_retur.luna) && (data_retur_actual.an > data_retur.an)))
	{
		if (data_retur_actual.an == data_inchiriere.an)
		{
			if (data_retur_actual.luna == data_inchiriere.luna)
			{
				zile = data_retur_actual.zi - data_retur.zi;
			}
			else if (data_retur_actual.luna > data_inchiriere.luna)
			{
				zile = (data_retur_actual.luna - data_retur.luna) * 30 + (data_retur_actual.zi - data_retur.zi);
			}
		}
		else if (data_retur_actual.an > data_inchiriere.an)
		{
			zile = (data_retur_actual.an - data_retur.an) * 365 - (data_retur_actual.luna - data_retur.luna) * 30 - (data_retur_actual.zi - data_retur.zi);
		}
	}

	return zile;
}

double Retur_dupa_termen::calcul_taxa_intarziere()
{
	int k = Retur_dupa_termen::calcul_diferenta_zile();
	double sum = 0;
	sum = k * taxa_intarziere;
	return sum;
}

Retur_dupa_termen::~Retur_dupa_termen() {

}

Pierdere_carte::Pierdere_carte(Data di, double t)
	:data_inchiriere{ di }, taxa_pierdere{ t }{

}
Pierdere_carte::Pierdere_carte()
	:Pierdere_carte{ {0,0,0},30 } {

}

Pierdere_carte::Pierdere_carte(const Pierdere_carte& obj)
	:Pierdere_carte(obj.data_inchiriere, obj.taxa_pierdere) {

}

Pierdere_carte& Pierdere_carte::operator=(const Pierdere_carte& obj)
{
	if (this == &obj)
		return *this;
	else
	{
		data_inchiriere = obj.data_inchiriere;
		taxa_pierdere = obj.taxa_pierdere;
		return *this;
	}
}

void Pierdere_carte::afisare()
{
	std::cout << "Data inchiriere: " << data_inchiriere.zi << "/ " << data_inchiriere.luna << "/ " << data_inchiriere.an << std::endl;
	std::cout << "Taxa pierdere: " << taxa_pierdere << std::endl;
}

int Pierdere_carte::calcul_diferenta_zile() {
	std::cout << "Cartea s-a pierdut." << std::endl;
	return -1;

}

double Pierdere_carte::calcul_taxa_intarziere()
{
	return taxa_pierdere;
}



Pierdere_carte::~Pierdere_carte() {

}


Bibliotecar::Bibliotecar(const char* _nume, double _salariu, int _nr_salarii_anterioare, int _norma, double _salarii_anterioare[], float _bonus)
	:Angajat(_nume, _salariu, _nr_salarii_anterioare, _norma, _salarii_anterioare), bonus{ _bonus }{

}

Bibliotecar::Bibliotecar()
	:Angajat("Anonim", 0, 0, 8, 0), bonus{ 0 }{

}

Bibliotecar::Bibliotecar(const char* _nume, double _salariu, int _norma, float _bonus)
	:Angajat(_nume, _salariu, 0, _norma, 0), bonus{ _bonus }{

}

Bibliotecar::Bibliotecar(Bibliotecar& obj)
	:Angajat(obj.get_nume(), obj.get_salariu(), obj.get_nr_salarii_anterioare(), obj.get_norma(), obj.get_salarii_anterioare()), bonus{ obj.bonus }{

}

Bibliotecar& Bibliotecar::operator=(Bibliotecar& obj)
{
	if (this == &obj)
		return *this;
	else
	{
		Angajat::operator=(obj);
		bonus = obj.bonus;
		return *this;

	}
}

void Bibliotecar::afisare()
{
	Angajat::afisare();
	std::cout << "Bonus: " << bonus << std::endl;

}

double Bibliotecar::calcul_salariu_real()
{
	return Angajat::calcul_salariu_real() * (1 + bonus);
}

float& Bibliotecar::get_bonus()
{
	return bonus;
}
void Bibliotecar::set_bonus(float bns)
{
	bonus = bns;
}

Bibliotecar::~Bibliotecar() {

}


Roman::Roman(const char* _nume_carte, const char* _nume_autor, int _nr_imprumuturi, int _id_imprumuturi[], int limita)
	:Carte(_nume_carte, _nume_autor, _nr_imprumuturi, _id_imprumuturi), limita_zile_imprumut{ limita }{

}

Roman::Roman()
	:Carte("Default", "Anonim", 0, nullptr), limita_zile_imprumut{ 0 }{

}

Roman::Roman(int _nr_imprumuturi, int _id_imprumuturi[], int limita)
	:Carte("Default", "Anonim", _nr_imprumuturi, _id_imprumuturi), limita_zile_imprumut{ limita }{

}

Roman::Roman(Roman& obj)
	:Carte(obj.get_nume_carte(), obj.get_nume_autor(), obj.get_nr_imprumuturi(), obj.get_id_imprumuturi()), limita_zile_imprumut{ obj.limita_zile_imprumut }{

}

Roman& Roman::operator=(Roman& obj)
{
	if (this == &obj)
		return *this;
	else
	{
		Carte::operator=(obj);
		limita_zile_imprumut = obj.limita_zile_imprumut;
		return *this;
	}
}

void Roman::afisare()
{
	Carte::afisare();
	std::cout << "Limita maxima de zile pentru retur: " << limita_zile_imprumut << std::endl;
}

void Roman::set_inchiriata()
{
	int id;
	std::cout << "ID client: "; std::cin >> id;
	set_stare(1);
	int k = 0;
	int l = 0;
	int m = 0;
	std::cout << "Zi inchiriere: "; std::cin >> k;
	set_zi_inchiriere(k);
	std::cout << "Luna inchiriere: "; std::cin >> l;
	set_luna_inchiriere(l);
	std::cout << "An inchiriere: "; std::cin >> m;
	set_an_inchiriere(m);

	Carte::incrementare_inchiriere(get_zi_inchiriere() + 31 * (get_luna_inchiriere() - 1));


	std::cout << "Zi pt retur: "; std::cin >> k;
	set_zi_retur(k);
	std::cout << "Luna pt retur: "; std::cin >> m;
	set_luna_retur(m);
	std::cout << "An pt retur: "; std::cin >> l;
	set_an_retur(l);
	Carte::adaugare_imprumut(id);

}

void Roman::set_returnata()
{
	set_stare(0);
	int k, l, m;
	std::cout << "Zi retur: "; std::cin >> k;
	set_zi_retur(k);
	std::cout << "Luna retur: "; std::cin >> l;
	set_luna_retur(l);
	std::cout << "An retur: "; std::cin >> m;
	set_an_retur(m);
	set_nr_zile_inchiriata(get_nr_zile_inchiriata() + calcul_zile_inchiriata());
}

int Roman::calcul_zile_inchiriata()
{
	//int zile = 0;
	if (get_an_retur() == get_an_inchiriere())
	{
		if (get_luna_retur() == get_luna_inchiriere())
		{
			return (limita_zile_imprumut > (get_zi_retur() - get_zi_retur())) ? -1 : (get_zi_retur() - get_zi_retur());
		}
		else if (get_luna_retur() > get_luna_inchiriere())
		{
			return (limita_zile_imprumut > ((get_luna_retur() - get_luna_inchiriere()) * 30 + (get_zi_retur() - get_zi_inchiriere()))) ? -1 : ((get_luna_retur() - get_luna_inchiriere()) * 30 + (get_zi_retur() - get_zi_inchiriere()));
		}
	}
	else if (get_an_retur() > get_an_inchiriere())
	{
		return (limita_zile_imprumut > ((get_an_retur() - get_an_inchiriere()) * 365 - (get_luna_retur() - get_luna_inchiriere()) * 30 - (get_zi_retur() - get_zi_inchiriere()))) ? -1 : ((get_an_retur() - get_an_inchiriere()) * 365 - (get_luna_retur() - get_luna_inchiriere()) * 30 - (get_zi_retur() - get_zi_inchiriere()));
	}

	//return zile;
}

Roman::~Roman() {

}

Bibliotecar_sef::Bibliotecar_sef(const char* _nume, double _salariu, int _nr_salarii_anterioare, int _norma, double _salarii_anterioare[], float _bonus, float _spor)
	:Bibliotecar(_nume, _salariu, _nr_salarii_anterioare, _norma, _salarii_anterioare, _bonus), spor_manager{ _spor }{

}

Bibliotecar_sef::Bibliotecar_sef()
	:Bibliotecar("Anonim", 0, 0, 8, 0, 0), spor_manager{ 0 }{

}

Bibliotecar_sef::Bibliotecar_sef(const char* _nume, double _salariu, int _norma, float _bonus, float _spor)
	:Bibliotecar(_nume, _salariu, 0, _norma, 0, _spor) {

}

Bibliotecar_sef::Bibliotecar_sef(Bibliotecar_sef& obj)
	:Bibliotecar(obj.get_nume(), obj.get_salariu(), obj.get_norma(), obj.get_bonus()), spor_manager{ obj.spor_manager }{

}

Bibliotecar_sef& Bibliotecar_sef::operator=(Bibliotecar_sef& obj)
{
	if (this == &obj)
		return *this;
	else
	{
		Bibliotecar::operator=(obj);
		spor_manager = obj.spor_manager;
		return *this;
	}
}

void Bibliotecar_sef::afisare()
{
	Bibliotecar::afisare();
	std::cout << "Spor managerial: " << spor_manager << std::endl;
}

double Bibliotecar_sef::calcul_salariu_real()
{
	return Bibliotecar::calcul_salariu_real() + spor_manager;
}

float& Bibliotecar_sef::get_spor()
{
	return spor_manager;
}

void Bibliotecar_sef::set_spor(float spor)
{
	spor_manager = spor;
}

Bibliotecar_sef::~Bibliotecar_sef() {

}