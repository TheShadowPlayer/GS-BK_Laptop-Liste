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
	Daklaration von Klassen
*/
class Objekt {
private:
	char name[20];
	int type;
	char bucher[100];
	bool gebucht;
protected:
	char* getName() { return name; };
	int getType() { return type; };
	char* getBucher() { return bucher; };
	bool getStatus() { return gebucht; };
public:
	Objekt(char name[], int type);
	virtual void print() {};
	bool buchen(char bucher[100]);
	Objekt* next;
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
	Deklarationen von Methoden

	Name der Methode | Funktion der Methode
	- AusgabeHeader | Hier wird die Ausgabe des Standart Header der Anwendung
	- AusgabeMenue | Hier wird die Ausgabe des Hauptmenues
	- AusgabeObjekte | Hier wird die Ausgabe aller Objekte geregelt
*/

void AusgabeHeader();
void AusgabeMenue();
void AusgabeObjekte(Objekt* obj);
void addListenElement(Objekt* obj, Objekt* objekt);

/*

	Die main() Methode ist der Einstiegspunkt für das Programm

*/
int main()
{
	int auswahl = 404;
	Objekt* list = NULL;
	char test[] = "test";
	char hp[] = "HP";
	char model[] = "ZBook 1";
	Objekt* testObj = new Laptop(test, hp, model, 1000, 696969, 69.69, 187.69);
	list = testObj;



	while (auswahl > 0) {
		system("cls");

		AusgabeHeader();
		AusgabeMenue();
		cin >> auswahl;
		switch (auswahl)
		{
		case 1:
			AusgabeObjekte(list);
			system("PAUSE");
			break;
		case 2:
			// TODO: Laptop anlegen
			system("PAUSE");
			break;
		case 3:
			// TODO: Zubehoer anlegen
			system("PAUSE");
			break;
		case 4:
			// TODO: Objekt buchen
			system("PAUSE");
			break;
		case 5:
			// TODO: Objekt stonieren
			system("PAUSE");
			break;
		case 9:
			// TODO: Objekt löschen
			system("PAUSE");
			break;
		default:
			break;
		}
	}


	

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
	cout << "|                                         |" << endl;
	cout << "|                  Menue                  |" << endl;
	cout << "|                                         |" << endl;
	cout << "|       1 - Alle Objekte anzeigen         |" << endl;
	cout << "|       2 - Neuen Laptop anlegen          |" << endl;
	cout << "|       3 - Neues Zubehoer anlegen        |" << endl;
	cout << "|       4 - Objekt buchen                 |" << endl;
	cout << "|       5 - Objekt Stonieren              |" << endl;
	cout << "|       9 - Objekt loeschen               |" << endl;
	cout << "|                                         |" << endl;
	cout << "|       0 - Program beenden               |" << endl;
	cout << "|                                         |" << endl;
	cout << "+-----------------------------------------+" << endl;
	cout << "Ihre Auswahl: ";
}

void AusgabeObjekte(Objekt* obj)
{
	Objekt* current = obj;
	cout << "+-----------------------------------------+" << endl;
	while (current != NULL) {
		current->print();
		current = current->next;
		cout << "+-----------------------------------------+" << endl;
	}
}

void addListenElement(Objekt* obj, Objekt* objekt) {
	Objekt* last = obj;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = objekt;
	last = last->next;
}

Objekt::Objekt(char name[], int type)
{
	strcpy_s(Objekt::name, name);
	Objekt::type = type;
	strcpy_s(Objekt::bucher, "");
	Objekt::gebucht = false;
	Objekt::next = NULL;
}

bool Objekt::buchen(char bucher[100])
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
	cout << "Type: Laptop" << endl;
	cout << "Name: " << Laptop::getName() << endl;
	cout << "Hersteller: " << Laptop::hersteller << endl;
	cout << "Model: " << Laptop::model << endl;
	cout << "Kerne | Threads | Takt" << endl;
	cout << Laptop::prozessorKerne << " | " << Laptop::prozessorThreads << " | " << Laptop::prozessorTakt << endl;
	cout << "Arbeitsspeicher: " << Laptop::arbeitsspeicher << "GB" << endl << endl;

	if (Laptop::getStatus()) {
		cout << "Status: " << "Gebucht von " << Laptop::getBucher() << endl;
	}
	else {
		cout << "Status: " << "Frei" << endl;
	}
}