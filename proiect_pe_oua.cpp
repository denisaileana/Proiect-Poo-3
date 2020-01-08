#include <fstream> // prentru citire din fisier
#include <iostream> // pentru citire / scriere pe ecran
#include <string> // pentru string
#include <vector> // pentru vector
#include <utility> // pentru pair

using namespace std;

/*
● Cerințe comune tuturor temelor:
	1. utilizarea sabloanelor
	2. utilizarea STL
	3. utilizarea variabilelor, funcțiilor statice, constantelor și a unei functii const
	4. utilizarea conceptelor de RTTI raportat la template-uri
	5. tratarea excepțiilor
	6. citirea informațiilor complete a n obiecte, memorarea și afișarea acestora

● cerințe generale aplicate fiecărei teme din acest fișier:
	- să se identifice și să se implementeze ierarhia de clase;
	- clasele să conțină constructori, destructori, =, funcție prietena de citire a datelor;
	- clasa de baza sa conțină funcție virtuala de afisare, rescrisa în clasele derivate, 
	  iar operatorul de citire să fie implementat ca funcție prieten (în clasele derivate să se facă
	  referire la implementarea acestuia în clasa de baza).

Tema 5. În luna mai se organizează târgul mașinilor sport, astfel ca pasionatii se pot delecta cu modele din clasa:
COUPE
HOT-HATCH (modele hatchback de clasa mica și compacta cu motoare performante ce au la bază modele obișnuite), 
CABRIO(modele decapotabile cu acoperiș metalic sau din material textil)
SUPERSPORT(masini de viteza gen Audi R8, Bugatti Veyron, Lexus LF-A, etc.)

O parte din masinile supersport poate să fie vânduta chiar în cadrul expozitiei, dacă se face plata pe loc.

Structura de date: ​vector sau list <pair<masina, preț>> 
(se rețin mașinile vândute și prețul de vanzare, daca masina nu a fost vanduta prețul este -1)

Să se adauge toate campurile relevante pentru modelarea acestei probleme.

Să se construiască clasa template ​Expoziție care sa conțină nr total de mașini expuse (incrementat automat) și 
  un vector de obiecte de tipul unei mașini, alocat dinamic.

*/

class masina {
protected:
	string _numeMasina;
	string _model;
public:
	masina(string numeMasina, string model) : _numeMasina(numeMasina), _model(model) { }
	virtual ~masina() { cout<<"<<< masina ("<<_model<<")\n"; }
	virtual void afiseaza()=0;
	string numeMasina() const { return this->_numeMasina; } // getter
};

class coupe : public masina {
public:
	coupe(string numeMasina) : masina(numeMasina, "Coupe") { }
	virtual ~coupe() { }
	virtual void afiseaza() {
		cout<<"O coupe foarte frumoasa: "<<this->numeMasina()<<"\n";
	}
};

class hothatch : public masina {
public:
	hothatch(string numeMasina) : masina(numeMasina, "Hot-hatch") { }
	virtual ~hothatch() { }
	virtual void afiseaza() {
		cout<<"Vrum vrum hothatch: "<<this->numeMasina()<<"\n";
	}
};

class cabrio : public masina {
public:
	cabrio(string numeMasina) : masina(numeMasina, "Cabrio") { }
	virtual ~cabrio() { }
	virtual void afiseaza() {
		cout<<"Elegant si cu stil - "<<this->numeMasina()<<"\n";
	}
};

class supersport : public masina {
public:
	supersport(string numeMasina) : masina(numeMasina, "SuperSport") { }
	virtual ~supersport() { cout<<"<<< SuperSport\n"; }
	virtual void afiseaza() {
		cout<<"O masina rapida si furioasa: "<<this->numeMasina()<<"\n";
	}	
};

//Să se construiască clasa template ​Expoziție care sa conțină nr total de mașini expuse (incrementat automat) și
//  un vector de obiecte de tipul unei mașini, alocat dinamic.

template <class Tip>
class Expozitie {
private:
	typedef typename vector< pair<Tip*, int> >::iterator broIterator;
	vector< pair<Tip*, int> > _expozitie;
	int _nrTotal;
	friend istream &operator>>(istream &in, Expozitie<Tip> &expo) {
		int n;
		in>>n;
		in.get(); // ca sa citesc '\n'
		for (int i = 0; i < n; i++) {
			string tip, nume;

			getline(in, tip);
			getline(in, nume); 

			if (tip == "coupe") {
				expo.adauga(new coupe(nume));
			} else if (tip == "hothatch") {
				expo.adauga(new hothatch(nume));
			} else if (tip == "cabrio") {
				expo.adauga(new cabrio(nume));
			} else if (tip == "supersport") {
				expo.adauga(new supersport(nume));
			} else throw "o ohhh, stinkiii! nu avem tipul necesar!";
		}
		return in;
	}
public:
	Expozitie() : _expozitie(), _nrTotal(0) { }
	~Expozitie() { 
		for (broIterator i = _expozitie.begin(); i != _expozitie.end(); i++) {
			delete i->first;
		}
		_expozitie.clear();
	}
	void adauga(Tip* masinuta) { _expozitie.push_back(make_pair(masinuta, -1)); _nrTotal++; }
	void afiseaza() {
		for (broIterator i = _expozitie.begin(); i != _expozitie.end(); i++) {
			i->first->afiseaza();

			supersport *ss = dynamic_cast<supersport *>(i->first);
			if (ss != NULL) {
				cout<<"^^^ e vanzabila (poate) ^^^\n";
			}
		}
	}
};
 

int main() {
	cout<<"hello world!\n";
	Expozitie<masina> test;
	ifstream cin("fisier.in");
	try {
		cin>>test;
	} catch (const char * err) {
		cout<<"eroare: "<<err<<"\n";
		return 0;
	}
	test.afiseaza();
	cout<<"goodbye world!\n";
	return 0;
}