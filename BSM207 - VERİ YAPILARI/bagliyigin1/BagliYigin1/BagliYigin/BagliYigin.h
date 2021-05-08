#ifndef BAGLILISTE_H
#define BAGLILISTE_H
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
class bagliYigin
{
private:
	dugum<T> *kok;
public:
	bagliYigin()
	{
		kok=NULL;
	}
	bool bosMu()
	{
		return kok==NULL;
	}
	void Ekle(T eleman)
	{
		dugum<T> *yenidugum=new dugum<T>();
		yenidugum->veri=eleman;
		yenidugum->sonraki=kok;
		kok=yenidugum;
	}
	int uzunluk()
	{
		int u=0;
		if(bosMu()) throw Hata(3);
		dugum<T> *gecici=kok;
		while(gecici!=NULL)
		{
			u++;
			gecici=gecici->sonraki;
		}
		return u;
	}
	T enUstteki()
	{
		if(bosMu()) throw Hata(3);
		return kok->veri;
	}
	T elemanCek()
	{
		if(bosMu()) throw Hata(3);
		T deger=kok->veri;
		dugum<T> *gecici=kok;
		kok=kok->sonraki;
		delete gecici;
		return deger;
	}
};
#endif BAGLILISTE_H