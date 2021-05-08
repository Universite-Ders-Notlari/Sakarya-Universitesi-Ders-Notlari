#include "stdafx.h"
#include "bagliKuyruk.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	bagliKuyruk<int> *liste=new bagliKuyruk<int>();

	liste->Ekle(5);
	liste->Ekle(8);
	liste->Ekle(-3);
	liste->Ekle(0);
	liste->Ekle(-7);
	int secim;
	do{
	cout<<"\n------------"<<endl;
	cout<<"11-Kuyruk Bos Mu?"<<endl;
	cout<<"1-Eleman Ekle"<<endl;
	cout<<"2-En Ondeki"<<endl;
	cout<<"3-Uzunluk"<<endl;
	cout<<"4-Eleman Cek"<<endl;
	cout<<"99-cikis<<"<<endl;
	cout<<"Secim:";cin>>secim;
	try
	{
	switch (secim)
	{
	case 11:if(liste->bosMu()) cout<<"Kuyruk bostur"<<endl;
	else cout<<"Kuyruk bos DEGIL"<<endl;
	break;
	case 1:{
	int deger;
	cout<<"Bir deger giriniz:";cin>>deger;
	liste->Ekle(deger);
	break;}
	case 3:cout<<"Kuyruk eleman sayisi:"<<liste->uzunluk()<<endl;break;
	case 2:cout<<"En Ustteki : "<<liste->enOndeki();break;
	case 4:cout<<liste->elemanCek()<<endl;break;
	default:

	break;
	}
	}
	catch(Hata h)
	{
	h.Mesaj();
	}

	}while(secim!=99);

	int d; cin >> d;
	return 0;
}



