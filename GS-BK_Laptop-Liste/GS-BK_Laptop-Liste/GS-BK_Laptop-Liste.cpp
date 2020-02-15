/*
						SAE Projekt

		Name: René Lohrer
		Fachrichtung: SAE
		Entwicklungsumgebungen:
								Visual Studio 2017
								Visual Studio Code
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



/*

	Die main() Methode ist der Einstiegspunkt für das Programm

*/
int main()
{
	AusgabeHeader();
	AusgabeMenue();

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
