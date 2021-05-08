/**
* @file VeriYap�lar�Odev1
* @description Kart adeti girip rastgele kartlar olu�turup de�i�tirme,ters �evirme i�lemlerini yapma
* @course 1.ogretim C grubu
* @assignment 1
* @date 21.10.2016
* @author Alperen Kaymak alperen.kaymak@ogr.sakarya.edu.tr , Erbil Nas erbil.nas@ogr.sakarya.edu.tr
*/
////////////////////////////////////
#include <iostream>
#include <locale.h>
#include <Windows.h>
#include <iomanip>
#include <time.h>
#include <cstdlib>
#include "Kart.h"
#include "Sembol.h"
using namespace std;
////////////////////////////////////
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
////////////////////////////////////
int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Turkish");
	int secenek, kartadedi;
	cout << "Kart adedi giriniz..:";
	cin >> kartadedi;
	////////////////////////////////////
	Kart *kartdizisi = new Kart[kartadedi];
	Kart *renkdizisi = new Kart[kartadedi];
	Kart *tempdizi;
	////////////////////////////////////
	for (int i = 0;i < kartadedi;i++)
	{
		tempdizi = new Kart();
		kartdizisi[i] = *tempdizi;
	}
	for (int i = 0;i < kartadedi;i++)	kartdizisi[i].semboltemp->getsembol(i);
	////////////////////////////////////
	for (int i = 0;i < kartadedi;i++)
	{
		tempdizi = new Kart();
		renkdizisi[i] = *tempdizi;
	}
	for (int i = 0;i < kartadedi;i++)	renkdizisi[i].getrenk(i);
	////////////////////////////////////
	do
	{
		////////////////////////////////////
		for (int i = 0;i < kartadedi;i++)
		{
			cout <<setw(10)<< i+1 << setw(10);
		}
		cout << endl;
		for (int i = 0;i < kartadedi;i++)
		{	
			SetConsoleTextAttribute(hConsole, renkdizisi[i].printrenk());
			cout << setw(10) <<kartdizisi[i].semboltemp->printsembol() <<setw(10);
			SetConsoleTextAttribute(hConsole, 15);
		}
		////////////////////////////////////
		cout << endl << "��lemler" << endl;
		cout << "1. Kart De�i�tir" << endl;
		cout << "2. Ters �evir" << endl;
		cout << "3. ��k��" << endl << ">> ";
		cin >> secenek;
		////////////////////////////////////
		switch (secenek)
		{
		case 1:
			int a, b;
			cout << "1. Kart� Girin..: ";
			cin >> a;
			cout << "2. Kart� Grini..: ";
			cin >> b;
			kartdizisi->changesembol(a, b, kartdizisi);
			renkdizisi->changerenk(a, b, renkdizisi);
			break;
		case 2:
			kartdizisi->semboltersdondur(kartadedi, kartdizisi);
			renkdizisi->semboltersdondur(kartadedi, renkdizisi);
			break;
		case 3:break;
		default:cout << "Men� say�lar�n� kullan�n�z..!"<<endl;continue;
		}
	} while (secenek != 3);
	delete renkdizisi->semboltemp;
	delete renkdizisi, kartdizisi, tempdizi;
	cin.get();
	cin.ignore();
	return 0;
}
