#include "stdafx.h"
#include <iostream>
#include "CYBL.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	cYBL<int> *liste=new cYBL<int>();
	liste->elemanEkle(5);
	liste->elemanEkle(4);
	liste->elemanEkle(-3);
	liste->elemanEkle(0);
	liste->elemanEkle(-7);
	int secim;
	do
	{
		cout<<"\n-------------------\n";
		cout<<"11-Liste Bos mu?"<<endl;
		cout<<"1-Listenin uzunlugu:"<<endl;
		cout<<"2-Eleman Ekle:"<<endl;
		cout<<"3-listele:"<<endl;
		cout<<"13-Tersten listele:"<<endl;
		cout<<"4-araya eleman Ekle"<<endl;
		cout<<"5-elaman ara"<<endl;
		cout<<"6-indisteki elaman"<<endl;
		cout<<"7-sondaki elemani sil"<<endl;
		cout<<"8-indisteki elemani sil"<<endl;
		cout<<"9-deger ile  elemani sil"<<endl;
		cout<<"99-cikis"<<endl;
		cout<<"secim:";cin>>secim;
		try
		{
		switch (secim)
		{
		case 11:if(liste->bosMu()) cout<<"liste bos"<<endl;
				else cout<<"liste bos DEGIL"<<endl;
				break;
		
		case 2:{
			   int eleman;
			   cout<<"Bir eleman:";cin>>eleman;
			   liste->elemanEkle(eleman);
			   break;
			   }
		case 1:cout<<liste->uzunluk()<<endl;break;
		case 3:liste->listele();break;
		case 13:liste->terstenlistele();break;
		
		
		case 4:{
			   int eleman;
			   int indis;
			   cout<<"Bir eleman:";cin>>eleman;
			   cout<<"aralik degeri";cin>>indis;
			   liste->indisIleElemanEkle(indis,eleman);
			   break;
			   }
		case 5:{
			   int eleman;
			   cout<<"Bir eleman:";cin>>eleman;
			   cout<<"aranan Eleman :"<<liste->elemanAra(eleman)<<endl;
			   break;
			   }
		case 6:{
			   int indis;
			   cout<<"aralik degeri :";cin>>indis;
			   cout<<"indisli eleman:"<<liste->indisileAra(indis)<<endl;
			   break;
			   }
		case 7:liste->sil();cout<<"silindi "<<endl;break;
		case 8:{
			   int indis;
			   cout<<"indis degeri :";cin>>indis;
			   liste->indistekiElemaniSil(indis);
			   cout<<"indisdeki eleman silindi:"<<endl;
			   break;
			   }
		case 9:{
			   int eleman;
			   cout<<"Bir eleman:";cin>>eleman;
			   liste->elemanSil(eleman);
			   cout<<"Eleman silindi:"<<endl;
			   break;
			   }
		default:
			break;
		}
		}
		catch(Hata h)
		{
			h.Mesaj();
		}
	}while(secim!=99);


	int d;cin>>d;
	return 0;
}

