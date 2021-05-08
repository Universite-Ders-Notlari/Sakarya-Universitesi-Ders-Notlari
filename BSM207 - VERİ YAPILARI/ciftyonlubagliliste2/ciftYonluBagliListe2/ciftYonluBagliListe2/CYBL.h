#ifndef CYBL_H
#define CYBL_H
#include "Hata.h"
#include <iostream>
using namespace std;
template<typename T>
class dugum
{
public:
	T veri;
	dugum *onceki;
	dugum *sonraki;
};
template<typename T>
class cYBL
{
private:
	dugum<T> *kok;
public:
	cYBL()
	{
		kok=NULL;
	}
	bool bosMu()
	{
		return !kok;
	}
	void elemanEkle(T eleman)
	{
		dugum<T> *yeniDugum=new dugum<T>();
		yeniDugum->veri=eleman;
		yeniDugum->onceki=NULL;
		yeniDugum->sonraki=NULL;

		if(bosMu()) kok=yeniDugum;
		else
		{
			dugum<T> *gecici=kok;
			while(gecici->sonraki!=NULL)
				gecici=gecici->sonraki;
			gecici->sonraki=yeniDugum;
			yeniDugum->onceki=gecici;
		}
	}
	int uzunluk()
	{
		int u=0;
		dugum<T> *gecici=kok;
			while(gecici!=NULL)
			{
				gecici=gecici->sonraki;
				u++;
			}
		return u;
	}
	void listele()
	{
		if(bosMu()) throw Hata(3);
		dugum<T> *gecici=kok;
		cout<<"----Listeleme-----"<<endl;
		while(gecici!=NULL) 
		{
			cout<<gecici->veri<<endl;
			gecici=gecici->sonraki;
		}
	}
	void terstenlistele()
	{
		if(bosMu()) throw Hata(3);
		dugum<T> *gecici=kok;
		cout<<"----Tersten Listeleme-----"<<endl;
		while(gecici->sonraki!=NULL) gecici=gecici->sonraki;
		while(gecici!=NULL) 
		{
			cout<<gecici->veri<<endl;
			gecici=gecici->onceki;
		}
	}
	void indisIleElemanEkle(int indis, T eleman)
	{
		if(bosMu()) throw Hata(3);
		if(indis<0||indis>uzunluk()) throw Hata(2);
		dugum<T> *yeni=new dugum<T>();
		yeni->veri=eleman;
		yeni->onceki=NULL;
		yeni->sonraki=NULL;
		if(indis==0) 
		{
			yeni->sonraki=kok;
			kok->onceki=yeni;
			kok=yeni;
		}
		else if(indis==uzunluk()) elemanEkle(eleman);
		else
		{
			dugum<T> *gecici=kok;
			int u=0;
			while(indis!=u)
			{
				u++;
				gecici=gecici->sonraki;
			}
			gecici=gecici->onceki;
			yeni->sonraki=gecici->sonraki;
			yeni->onceki=gecici;
			gecici->sonraki=yeni;
			yeni->sonraki->onceki=yeni;
		}
	}
	int elemanAra(T eleman)
	{
		if(bosMu()) throw Hata(3);
		int indis=0;
		dugum<T> *gecici=kok;
		while(gecici!=NULL)
		{
			if(gecici->veri==eleman) return indis;
			indis++;
			gecici=gecici->sonraki;
		}
		throw Hata(1);
	}
	T indisileAra(int indis)
	{
		if(bosMu()) throw Hata(3);
		if(indis<0||indis>=uzunluk()) throw Hata(2);
		int u=0;
		dugum<T> *gecici=kok;
		while(gecici!=NULL)
		{
			if(indis==u) return gecici->veri;
			u++;
			gecici=gecici->sonraki;
		}
	}
	void sil()
	{
		if(bosMu()) throw Hata(3);
		dugum<T> *gecici=kok;
		if(uzunluk()==1) 
		{
			delete kok;
			kok=NULL;
		}
		else
		{
			while(gecici->sonraki!=NULL)
				gecici=gecici->sonraki;
			gecici=gecici->onceki;
			delete gecici->sonraki;
			gecici->sonraki=NULL;
		}
	}
	void indistekiElemaniSil(int indis)
	{
		if(bosMu()) throw Hata(3);
		if(indis<0||indis>=uzunluk()) throw Hata(2);
		int u=0;
		dugum<T> *gecici=kok;
		if(indis==0) 
			if(uzunluk()==1)
			{
				delete kok;
				kok=NULL;
			}
			else
			{
				kok=kok->sonraki;
				delete kok->onceki;
				kok->onceki=NULL;
			}
		else if((uzunluk()-1)==indis) sil();
		else
		{
			while(indis!=u)
			{
				gecici=gecici->sonraki;
				u++;
			}
			gecici=gecici->onceki;
			gecici->sonraki=gecici->sonraki->sonraki;
			delete gecici->sonraki->onceki;
			gecici->sonraki->onceki=gecici;
		}
	}
	void elemanSil(T eleman)
	{
		indistekiElemaniSil(elemanAra(eleman));
	}
};


#endif CYBL_H