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
class bagliListe
{
private:
	dugum<T> *kok;
public:
	bagliListe()
	{
		kok=NULL;
	}
	bool bosMu()
	{
		return kok==NULL;
	}
	void elemanEkle(T eleman)
	{
		dugum<T> *yenidugum=new dugum<T>();
		yenidugum->veri=eleman;
		yenidugum->sonraki=NULL;
		if(bosMu()) kok=yenidugum;
		else
		{
			dugum<T> *gecici=kok;
			while(gecici->sonraki!=NULL) gecici=gecici->sonraki;
			gecici->sonraki=yenidugum;
		}
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
	void listele()
	{
		if(bosMu()) throw Hata(3);
		dugum<T> *gecici=kok;
		while(gecici!=NULL)
		{
			cout<<gecici->veri<<endl;
			gecici=gecici->sonraki;
		}
	}
	void arayaElemanEkle(int indis, T deger)
	{
		if(bosMu()) throw Hata(3);
		if(indis<0||indis>uzunluk()) throw Hata(1);
		dugum<T> *yenidugum=new dugum<T>();
		yenidugum->veri=deger;
		yenidugum->sonraki=NULL;
		if(indis==0)
		{
			yenidugum->sonraki=kok;
			kok=yenidugum;
		}
		else if(indis==uzunluk()) elemanEkle(deger);
		else
		{
			int u=0;
			dugum<T> *gecici=kok;
			while(gecici!=NULL)
			{
				if(u==(indis-1)) break;
				u++;
				gecici=gecici->sonraki;
			}
			yenidugum->sonraki=gecici->sonraki;
			gecici->sonraki=yenidugum;
		}

	}
	int elemanAra(T deger)
	{
		int u=0;
		if(bosMu()) throw Hata(3);
		dugum<T> *gecici=kok;
		while(gecici!=NULL)
		{
			if(gecici->veri==deger) return u;
			u++;
			gecici=gecici->sonraki;
		}
		throw Hata(2);
	}
	T indisIleAra(int indis)
	{
		int u=0;
		if(bosMu()) throw Hata(3);
		if(indis<0||indis>=uzunluk()) throw Hata(1);
		dugum<T> *gecici=kok;
		while(gecici!=NULL)
		{
			if(u==indis) return gecici->veri;
			u++;
			gecici=gecici->sonraki;
		}
	}
	void sil()
	{
		if(bosMu()) throw Hata(3);
		dugum<T> *onceki=kok;
		dugum<T> *gecici=kok;
		if(kok->sonraki==NULL) 
		{
			delete kok;
			kok=NULL;
		}
		else
		{
			while(gecici->sonraki!=NULL)
			{
				onceki=gecici;
				gecici=gecici->sonraki;
			}
		onceki->sonraki=NULL;
		delete gecici;
		}
	}
	T elemanCek()
	{
		if(bosMu()) throw Hata(3);
		T deger;
		dugum<T> *onceki=kok;
		dugum<T> *gecici=kok;
		if(kok->sonraki==NULL) 
		{
			deger=kok->veri;
			delete kok;
			kok=NULL;
			return deger;
		}
		else
		{
			while(gecici->sonraki!=NULL)
			{
				onceki=gecici;
				gecici=gecici->sonraki;
			}
		onceki->sonraki=NULL;
		deger=gecici->veri;
		delete gecici;
		return deger;
		}
	}
	void indisIleSil(int indis)
	{
		if(bosMu()) throw Hata(3);
		if(indis<0||indis>=uzunluk()) throw Hata(1);
		int u=0;
		if(indis==0) 
		{
			dugum<T> *gecici=kok;
			kok=kok->sonraki;
			delete gecici;
		}
		else if(uzunluk()==1) 
		{
			delete kok;
			kok=NULL;
		}
		else 
		{
		dugum<T> *gecici=kok;
		dugum<T> *onceki=kok;
		while(gecici!=NULL)
		{
			if(u==indis) break;
			u++;
			onceki=gecici;
			gecici=gecici->sonraki;
		}
		onceki->sonraki=gecici->sonraki;
		delete gecici;
		}
	}
	void elemanIleSil(T eleman)
	{
		indisIleSil(elemanAra(eleman));
	}
};
#endif BAGLILISTE_H