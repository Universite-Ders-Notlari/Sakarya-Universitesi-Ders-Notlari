#ifndef BAGLIKUYRUK_H
#define BAGLIKUYRUK_H
#include "Hata.h"
#include <iostream>
using namespace std;
template<typename T>
class dugum
{
public:
	T veri;
	dugum *sonraki;
};
template<typename T>
class bagliKuyruk
{
private:
	dugum<T> *ilk;
	dugum<T> *son;
public:
	bagliKuyruk()
	{
		ilk=NULL;
		son = NULL;
	}
	bool bosMu()
	{
		return ilk==NULL;
	}
	void Ekle(T eleman)
	{
		dugum<T> *yenidugum=new dugum<T>();
		yenidugum->veri=eleman;
		yenidugum->sonraki=NULL;
		if (bosMu())
		{
			ilk = yenidugum;
			son = yenidugum;
		}
		else
		{
			son->sonraki = yenidugum;
			son = yenidugum;
		}
	}
	int uzunluk()
	{
		int u=0;
		if(bosMu()) throw Hata(3);
		dugum<T> *gecici=ilk;
		while(gecici!=NULL)
		{
			u++;
			gecici=gecici->sonraki;
		}
		return u;
	}
	T enOndeki()
	{
		if(bosMu()) throw Hata(3);
		return ilk->veri;
	}
	T elemanCek()
	{
		if(bosMu()) throw Hata(3);
		T deger=ilk->veri;
		dugum<T> *silinecek=ilk;
		ilk=ilk->sonraki;
		delete silinecek;
		return deger;
	}
};
#endif BAGLIKUYRUK_H