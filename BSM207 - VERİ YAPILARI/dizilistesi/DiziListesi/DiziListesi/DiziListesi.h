#ifndef DIZILISTESI_H
#define DIZILISTESI_H
#include "Hata.h";
#include <iostream>
using namespace std;
template<typename T>
class diziListesi
{
private:
	int boyut;
	int elemanSayisi;
	T *liste;
public:
	diziListesi()
	{
		boyut=5;
		elemanSayisi=0;
		liste=new T[boyut];
	}
	bool bosMu()
	{
		return elemanSayisi==0;
	}
	int uzunluk()
	{
		return elemanSayisi;
	}
	void boyutArtir()
	{
		T *yliste=new T[boyut*2];
		for(int i=0;i<boyut;i++)
			yliste[i]=liste[i];
		delete[] liste;
		liste=yliste;
	}
	void elemanEkle(T eleman)
	{
		if(elemanSayisi>=boyut) boyutArtir();
		liste[elemanSayisi]=eleman;
		elemanSayisi++;
	}
	void listele()
	{
		if(bosMu()) throw Hata(3);
		for(int i=0;i<elemanSayisi;i++)
			cout<<liste[i]<<endl;
	}
	void arayaElemanEkle(int aralik,T eleman)
	{
		if(aralik<0||aralik>=elemanSayisi) throw Hata(2);
		for(int i=elemanSayisi;i>aralik;i--)
			liste[i]=liste[i-1];
		liste[aralik]=eleman;
		elemanSayisi++;
	}
	int elemanAra(T eleman)
	{
		if(bosMu()) throw Hata(3);
		for(int i=0;i<elemanSayisi;i++)
			if(liste[i]==eleman) return i;
		throw Hata(1);
	}
	T indisileAra(int indis)
	{
		if(indis<0||indis>=elemanSayisi) throw Hata(2);
		if(bosMu()) throw Hata(3);
		return liste[indis];
	}
	void sil()
	{
		if(bosMu()) throw Hata(3);
		elemanSayisi--;
	}
	void indistekiElemaniSil(int indis)
	{
		if(indis<0||indis>=elemanSayisi) throw Hata(2);
		if(bosMu()) throw Hata(3);
		for(int i=indis+1;i<elemanSayisi;i++)
			liste[i-1]=liste[i];
		elemanSayisi--;
	}
	void elemanSil(T eleman)
	{
		indistekiElemaniSil(elemanAra(eleman));
	}
};

#endif DIZILISTESI_H