/*
						SAE Projekt

		Name: René Lohrer
		Fachrichtung: SAE
		Entwicklungsumgebungen:
								Visual Studio 2017
								Visual Studio 2019
		Kurze Beschreibung:
							Dies ist ein kleines Projeckt bei dem es sich um eine Art Laptop Buchungs Software geht.
							Hierbei ist es möglich Laptops anzulegen und zu "buchen".
							Die Idee kam mir da wir im Unternehmen eine Excel Liste haben die genau dies tut,
							hierbei wird es den Auszubildenden ohne Laptop ermöglicht einen Laptop auszuleihen.
		Funtkionalitäten der Anwendung:
									  - Hinzufügen von Laptops
									  - Hinzufügen von Zubehör
									  - Buchen der Laptops
									  - Buchungen Stornieren
									  - Ausgeben aller Laptops mit dem Aktuellen Status
									  - Suchen eines Laptops / Anzeige eines Laptops mit Status
									  - Entfernen von Laptops
									  - Entfernen von Zubehör
		Source Code und weitere Informationen:
											  https://github.com/TheShadowPlayer/GS-BK_Laptop-Liste/
*/


/*
Einbinden von Systembibliotheken
Folgende werden verwendet:
	Name der Bibliothek | Beschreibung was diese macht
	- pch.h | Hier werden "pre-compiled headers" in das Program Eingebunden
	- iostream | Hier sind die Ein- und Ausgabe-Funktionen von C++ enthalten
	- cmath | Fügt mehrere Datentypen der Standartbibliothek ein
	- string.h | Fügt verschiedene Mehtoden für "string" ein
	- using namespace std | Hier werden die befehle vereinfacht, das man statt std::cout nur noch cout machen muss
*/
#include "pch.h"
#include <iostream>
#include <cmath>
#include <time.h>
#include "string.h"
using namespace std;

/*
	Deklarationen von Methoden

	Name der Methode | Funktion der Methode
	- AusgabeHeader | Hier wird die Ausgabe des Standart Header der Anwendung
	- AusgabeMenue | Hier wird die Ausgabe des Hauptmenues
*/

void AusgabeHeader();
void AusgabeMenue();


/*
	Daklaration von Klassen

	Name der Klasse | Beschreibung der Klasse
*/

class Objekt {
private:
	char name[20];
	int type;
	char bucher[20];
	bool gebucht;
protected:


	char* getName() { return name; };
	int getType() { return type; };
	char* getBucher() { return bucher; };
	bool getStatus() { return gebucht; };
public:
	Objekt(char name[], int type);
	virtual void print() {};
	bool buchen(char bucher[10]);
};

class Laptop : public Objekt {
private:
	char hersteller[20];
	char model[20];
	int prozessorKerne;
	int prozessorThreads;
	double prozessorTakt;
	double arbeitsspeicher;
public:
	Laptop(char name[], char hersteller[], char model[], int prozessorKerne, int prozessorThreads, double prozessorTakt, double arbeitsspeicher);
	~Laptop();
	void print();
};


/*

	Die main() Methode ist der Einstiegspunkt für das Programm

*/
int main()
{
	AusgabeHeader();
	AusgabeMenue();
	char test[] = "test";
	char hp[] = "HP";
	char model[] = "ZBook 1";
	Objekt* testObj = new Laptop(test, hp, model, 1000, 696969, 69.69, 187.69);
	testObj->print();
	system("PAUSE");
	return 0;
}

/*

	Definition der Methode

*/

void AusgabeHeader()
{
	cout << "+-----------------------------------------+" << endl;
	cout << "|                                         |" << endl;
	cout << "|    L A P T O P  -                       |" << endl;
	cout << "|                   V E R M I E T U N G   |" << endl;
	cout << "|                                         |" << endl;
	cout << "+-----------------------------------------+" << endl;
}

void AusgabeMenue()
{

}

Objekt::Objekt(char name[], int type)
{
	strcpy_s(Objekt::name, name);
	Objekt::type = type;
	strcpy_s(Objekt::bucher, "");
	Objekt::gebucht = false;
}

bool Objekt::buchen(char bucher[10])
{
	if (!Objekt::gebucht) {
		strcpy_s(Objekt::bucher, bucher);
		Objekt::gebucht = true;
		return true;
	}
	return false;
}

Laptop::Laptop(char name[], char hersteller[], char model[], int prozessorKerne, int prozessorThreads, double prozessorTakt, double arbeitsspeicher) : Objekt(name, 1)
{
	strcpy_s(Laptop::hersteller, hersteller);
	strcpy_s(Laptop::model, model);
	Laptop::prozessorKerne = prozessorKerne;
	Laptop::prozessorThreads = prozessorThreads;
	Laptop::prozessorTakt = prozessorTakt;
	Laptop::arbeitsspeicher = arbeitsspeicher;
}

Laptop::~Laptop()
{
	cout << "Wurde gelöscht";
}

void Laptop::print()
{
	cout << Laptop::getType() << " - " << Laptop::getName() << " - [" << Laptop::hersteller << ", " << Laptop::model << ", " << Laptop::prozessorKerne << ", " << Laptop::prozessorThreads << ", " << Laptop::prozessorTakt << ", " << Laptop::arbeitsspeicher << "]" << endl;
}