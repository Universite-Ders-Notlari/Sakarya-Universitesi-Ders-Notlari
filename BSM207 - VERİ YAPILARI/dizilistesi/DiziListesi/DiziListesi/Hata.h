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
		case 1:cout<<"Aranan Eleman bulunamadi"<<endl;break;
		case 2:cout<<"Aralik disinda"<<endl;break;
		case 3:cout<<"Liste Bos"<<endl;break;
		case 99:cout<<"Liste Doldu"<<endl;break;
		default:cout<<"Diger Hatalar"<<endl;
			break;
		}
	}

};


#endif HATA_H

