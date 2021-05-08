#include "stdafx.h"
#include "bagliListe.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	bagliListe<int> *liste=new bagliListe<int>();
	liste->elemanEkle(5);
	liste->elemanEkle(8);
	liste->elemanEkle(-3);
	liste->elemanEkle(0);
	liste->elemanEkle(-7);
	int secim;
	do{
		cout<<"\n------------"<<endl;
		cout<<"11-liste Bos Mu?"<<endl;
		cout<<"1-Eleman Ekle"<<endl;
		cout<<"2-Listele"<<endl;
		cout<<"3-Uzunluk"<<endl;
		cout<<"4-Eleman Cek"<<endl;
		cout<<"5-Araya Eleman Ekle"<<endl;
		cout<<"6-Eleman Ara"<<endl;
		cout<<"7-Indis ile Ara"<<endl;
		cout<<"8-Eleman Sil"<<endl;
		cout<<"9-indis ile Eleman Sil"<<endl;
		cout<<"10-Deger ile Eleman Sil"<<endl;
		cout<<"99-cikis<<"<<endl;
		cout<<"Secim:";cin>>secim;
		try
		{
			switch (secim)
			{
			case 11:if(liste->bosMu()) cout<<"Liste bostur"<<endl;
					else cout<<"Liste bos DEGIL"<<endl;
					break;
			case 1:{
				int deger;
				cout<<"Bir deger giriniz:";cin>>deger;
				liste->elemanEkle(deger);
				break;}
			case 3:cout<<"liste eleman sayisi:"<<liste->uzunluk()<<endl;break;
			case 2:liste->listele();break;
			case 5:	{
				int deger;int aralik;
				cout<<"Bir deger giriniz:";cin>>deger;
				cout<<"Aralik degerini giriniz";cin>>aralik;
				liste->arayaElemanEkle(aralik,deger);
					}
			case 6:	{
				int deger;
				cout<<"Bir deger giriniz:";cin>>deger;
				cout<<"Elemanin indisi:"<<liste->elemanAra(deger)<<endl;
				break;
					}
			case 7:	{
				int indis;
				cout<<"Bir indis degeri giriniz:";cin>>indis;				
				cout<<indis<<" indisli eleman:"<<liste->indisIleAra(indis)<<endl;
				break;
					}
		
			
			
			case 8:	{
				liste->sil();
				cout<<"listenin sonundaki eleman silindi"<<endl;
				break;
					}
			case 4:cout<<liste->elemanCek()<<endl;break;
			case 9:	{
				int indis;
				cout<<"Bir indis degeri giriniz:";cin>>indis;	
				liste->indisIleSil(indis);
				cout<<indis<<" indisli eleman silindi"<<endl;
				break;
					}
			case 10:	{
				int eleman;
				cout<<"Elemanin degerini giriniz:";cin>>eleman;	
				liste->elemanIleSil(eleman);
				cout<<eleman<<" degerli eleman silindi"<<endl;
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

