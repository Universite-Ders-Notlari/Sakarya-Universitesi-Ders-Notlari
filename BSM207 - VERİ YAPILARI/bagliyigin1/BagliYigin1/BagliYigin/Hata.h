#ifndef HATA_H
#define HATA_H
#include <iostream>
using namespace std;

class Hata
{
private:
	int hata;
public:
	Hata(int hata):hata(hata){}
	void Mesaj()
	{
		switch (hata)
		{
		case 1:cout<<"Indis degeri Aralik Disi"<<endl;break;
		case 2:cout<<"Aranan eleman bulunamadi"<<endl;break;
		case 3:cout<<"Liste Bos"<<endl;break;
		case 99:cout<<"Dizi Boyutunu Asti";break;
		default:cout<<"Diger Hata turunde"<<endl;
			break;
		}
	}
};


#endif HATA_H