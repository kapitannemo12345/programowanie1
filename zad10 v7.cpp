#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include <iostream>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include <string>
#include <stdlib.h>

using namespace std;
int t = 1;
int ilosc_kontaktow = 0;

char fileName[100];


struct osoba {                            // deklaracja struktury
	string imie;
	string nazwisko;
	int numer_tel;
}; osoba  kont[1000];

void create_contact()
{
	cout << "\n";
	string imie1; string nazwisko1;
	int numertel;

	cout << "podaj imie kontaktu \n ";
	cin >> imie1;
	cout << "podaj nazwisko kontaktu\n ";
	cin >> nazwisko1;
	cout << "podaj numer telefonu kontaktu\n ";
	cin >> numertel;

	kont[t].imie = imie1;
	kont[t].nazwisko = nazwisko1;
	kont[t].numer_tel = numertel;

	// deklaruje zmienna filename ktora jest stringem
	sprintf_s(fileName, "outfile%d.txt", 1); // nadaje nazwe  i %d jest zamieniane na i
	FILE * outputFile;
	fopen_s(&outputFile, fileName, "a"); // otwiera plik o tym pinterze; w- otwiera plik do zpisu
	fprintf_s(outputFile, " %s \n", kont[t].imie.c_str());
	fprintf_s(outputFile, " %s \n", kont[t].nazwisko.c_str());
	fprintf_s(outputFile, " %d \n", kont[t].numer_tel);
	fclose(outputFile);

	t++;
	ilosc_kontaktow++;
}

void display_contacts()
{
	cout << "\n";

	for (int i = 1; i < t; i++)
	{
		cout << "kontakt " << i << ":";
		cout << "imie : " << kont[i].imie << "\n";
		cout << "nazwkisko :" << kont[i].nazwisko << "\n";
		cout << "numer tel. :" << kont[i].numer_tel << "\n";
		cout << "\n";
	}

}

void delete_contact()
{
	cout << "\n";

	int odp1;
	int odp2;

	cout << "podaj numer kontaktu ktory chcialbys skasowac\n";
	cin >> odp1;
	cout << "czy napewno chcesz usnac kontakt nr " << odp1 << "? \n";
	cout << "1-tak 2-nie \n";
	cin >> odp2;

	if (odp2 == 1)
	{
		if (ilosc_kontaktow > 1)
		{
			int status;
			for (int i = odp1; i < t - 1; i++)
			{

				kont[i].imie = kont[i + 1].imie;
				kont[i].nazwisko = kont[i + 1].nazwisko;
				kont[i].numer_tel = kont[i + 1].numer_tel;
			}
			t--;
			status = remove("outfile1");         // usuwanie pliku za pomoca pocniczej zmiennej zmiennej status

			sprintf_s(fileName, "outfile%d.txt", 1); // nadaje nazwe  i %d jest zamieniane na i
			FILE * outputFile;
			fopen_s(&outputFile, fileName, "w"); // otwiera plik o tym pinterze; w- otwiera plik do zpisu
			for (int i = 0; i < t - 1; i++)
			{
				fprintf_s(outputFile, " %s \n", kont[i + 1].imie.c_str());
				fprintf_s(outputFile, " %s \n", kont[i + 1].nazwisko.c_str());
				fprintf_s(outputFile, " %d \n", kont[i + 1].numer_tel);
			}
			fclose(outputFile);
			ilosc_kontaktow--;
		}

		if (ilosc_kontaktow = 1)
		{
			int status;
			status = remove("outfile1");
			ilosc_kontaktow--;
		}

	}
	if (odp2 == 2)
	{
		cout << "kontakt nie zostanie usuniety";
	}

}

void edit_contact()
{
	cout << "\n";

	int odp1;
	int odp2;

	cout << "podaj numer kontaktu ktory chciałbys edytowac\n";
	cin >> odp1;

	cout << "podaj ktore dane kontaktu chcialbys edytowac \n \n";
	cout << "1-imie \n";
	cout << "2_nazwisko \n";
	cout << "3-numer telefonu \n";
	cin >> odp2;

	if (odp2 == 1)
	{
		string imie1;
		cout << "pdaj nowe imie kontaktu\n \n \n ";
		cin >> imie1;
		kont[odp1].imie = imie1;

		int status;
		status = remove("outfile1");         // usuwanie pliku za pomoca pocniczej zmiennej zmiennej status

		sprintf_s(fileName, "outfile%d.txt", 1); // nadaje nazwe  i %d jest zamieniane na i
		FILE * outputFile;
		fopen_s(&outputFile, fileName, "w"); // otwiera plik o tym pinterze; w- otwiera plik do zpisu
		for (int i = 0; i < t - 1; i++)
		{
			fprintf_s(outputFile, " %s \n", kont[i + 1].imie.c_str());
			fprintf_s(outputFile, " %s \n", kont[i + 1].nazwisko.c_str());
			fprintf_s(outputFile, " %d \n", kont[i + 1].numer_tel);
		}
		fclose(outputFile);


	}
	else if (odp2 == 2)
	{
		string nazwisko1;
		cout << "pdaj nowe nazwisko kontaktu\n \n \n ";
		cin >> nazwisko1;
		kont[odp1].nazwisko = nazwisko1;
		int status;
		status = remove("outfile1");         // usuwanie pliku za pomoca pocniczej zmiennej zmiennej status

		sprintf_s(fileName, "outfile%d.txt", 1); // nadaje nazwe  i %d jest zamieniane na i
		FILE * outputFile;
		fopen_s(&outputFile, fileName, "w"); // otwiera plik o tym pinterze; w- otwiera plik do zpisu
		for (int i = 0; i < t - 1; i++)
		{
			fprintf_s(outputFile, " %s \n", kont[i + 1].imie.c_str());
			fprintf_s(outputFile, " %s \n", kont[i + 1].nazwisko.c_str());
			fprintf_s(outputFile, " %d \n", kont[i + 1].numer_tel);
		}
		fclose(outputFile);

	}
	else if (odp2 == 3)
	{
		int numertel;
		cout << "podaj nowe imie kontaktu\n \n \n ";
		cin >> numertel;
		kont[odp1].numer_tel = numertel;
		
		int status;
		status = remove("outfile1");         // usuwanie pliku za pomoca pocniczej zmiennej zmiennej status

		sprintf_s(fileName, "outfile%d.txt", 1); // nadaje nazwe  i %d jest zamieniane na i
		FILE * outputFile;
		fopen_s(&outputFile, fileName, "w"); // otwiera plik o tym pinterze; w- otwiera plik do zpisu
		for (int i = 0; i < t - 1; i++)
		{
			fprintf_s(outputFile, " %s \n", kont[i + 1].imie.c_str());
			fprintf_s(outputFile, " %s \n", kont[i + 1].nazwisko.c_str());
			fprintf_s(outputFile, " %d \n", kont[i + 1].numer_tel);
		}
		fclose(outputFile);
	}
	else
	{

	}

}

void menu()
{

	char znak;
	cout << "witaj w ksiażce telefonicznej \n \n";
	cout << "C-tworzenie nowych wpisow \n";
	cout << "R- przegladanie danych \n";
	cout << "U-aktualizacja istniejacych wpisow \n";
	cout << "D-kasowanie istniejacych wpisow \n";
	cin >> znak;

	if (znak == 'c' || znak == 'C')
	{
		create_contact();
		cout << "\n \n";
		menu();
	}
	if (znak == 'r' || znak == 'R')
	{
		display_contacts();
		cout << "\n \n";
		menu();
	}
	if (znak == 'u' || znak == 'U')
	{
		edit_contact();
		cout << "\n \n";
		menu();
	}
	if (znak == 'd' || znak == 'D')
	{
		delete_contact();
		cout << "\n \n";
		menu();
	}

}

void program_start()
{
	int odp1;

	cout << "czy w pliku outfiel znajduja sie kontakty?\n";
	cout << "1-tak \n";
	cout << "2-nie \n";
	cin >> odp1;

	if (odp1 == 1)
	{
		int j = 1;
		int nr_linii = 1;
		int rzad = 0;
		int odp2;
		cout << "iles jest kontaktow?\n";
		cin >> odp2;

		t = odp2 + 1;									//bardzo ważna linijka kluczowa dla nie nadpisania kontaktu w funcji edit_contacts
		ilosc_kontaktow = odp2;

		string line;
		ifstream myfile("outfile1.txt");
		if (myfile.is_open())
		{
			while (getline(myfile, line))							// getline pobiera cala linie lacznie ze spacjami getline(skąd pobrac czyli z pliku,lnie czyli pomocnicza zmienna string która przechowa pobraną linie tekstu 
																		// while powoduje ze powtarza sie dopoki prawda jest ze istnieja linie)
			{

				switch (nr_linii)
				{
				case 1: kont[j].imie = line; break;
				case 2: kont[j].nazwisko = line; break;
				case 3: kont[j].numer_tel = atoi(line.c_str());	break; // tutaj trzeba przerobic strin na int 									
				}

				if (nr_linii == 3)
				{
					nr_linii = 0;
					j++;
				}
				nr_linii++;
			}
			myfile.close();
		}
		else cout << "nie udalo sie otworzyc pliku";


		menu();
	}
	if (odp1 == 2)
	{
		menu();

	}

}
int main()
{
	program_start();

	return 0;
}


//int odp;
	//cout << "podaj numer kontaktu ktory chciałbys\n";
	//cin >> odp;

// struct Contact * person =
//(struct Contact *) malloc(sizeof(struct Contact));

//osoba * kont = (struct osoba *)malloc(sizeof(struct osoba));









