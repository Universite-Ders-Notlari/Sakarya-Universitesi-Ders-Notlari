#include "BagilListe.hpp"

int main(){
	int sec=0;
	BagilListe<int> *liste = new BagilListe<int>();
	do{
		cout<<"1. Sayi Sona Ekle"<<endl;
		cout<<"2. Sayi Araya Ekle"<<endl;
		cout<<"3. Sayi Sil"<<endl;
		cout<<"4. Konumdaki Sayiyi Sil"<<endl;
		cout<<"5. Sayi Ara"<<endl;
		cout<<"6. Eleman Sayisi"<<endl;
		cout<<"7. Listeyi Yazdir"<<endl;
		cout<<"8. Listeyi Temizle"<<endl;
		cout<<"9. Cikis"<<endl;
		cout<<"=>";
		cin>>sec;
		switch(sec){
			case 1:
			{
				int sayi;
				cout<<"Sayi:";
				cin>>sayi;
				liste->Ekle(sayi);
				cout<<"Sayi eklendi. Devam etmek icin enter tusuna basin.";
				cin.get();
				cin.ignore();
				break;
			}
			case 2:
			{
				int sayi,konum;
				cout<<"Sayi:";
				cin>>sayi;
				cout<<"Konum:";
				cin>>konum;
				liste->Ekle(sayi,konum);
				cout<<"Sayi eklendi. Devam etmek icin enter tusuna basin.";
				cin.get();
				cin.ignore();
				break;
			}
			case 3:{
				int sayi;
				cout<<"Sayi:";
				cin>>sayi;
				liste->Sil(sayi);
				cout<<"Sayi silindi. Devam etmek icin enter tusuna basin.";
				cin.get();
				cin.ignore();
				break;
			}
			case 4:{
				int konum;
				cout<<"Konum:";
				cin>>konum;
				liste->KonumdakiniSil(konum);
				cout<<"Sayi silindi. Devam etmek icin enter tusuna basin.";
				cin.get();
				cin.ignore();
				break;
			}
			case 5:{
				int sayi;
				cout<<"Aranacak Sayi:";
				cin>>sayi;
				if(liste->ElemanBul(sayi)) cout<<"Sayi listede var."<<endl;
				else cout<<"Sayi listede yok."<<endl;				
				cout<<"Devam etmek icin enter tusuna basin.";
				cin.get();
				cin.ignore();
				break;
			}
			case 6:{
				cout<<"Eleman Sayisi: "<<liste->Uzunluk()<<endl;			
				cout<<"Devam etmek icin enter tusuna basin.";
				cin.get();
				cin.ignore();
				break;
			}
			case 7:{
				cout<<"Liste: "<<endl;	
				cout<<*liste<<endl;
				cout<<"Devam etmek icin enter tusuna basin.";
				cin.get();
				cin.ignore();
				break;
			}
			case 8:{
				liste->Temizle();
				cout<<"Liste temizlendi. Devam etmek icin enter tusuna basin.";
				cin.get();
				cin.ignore();
				break;
			}
		}
	}while(sec != 9);
	
	
	delete liste;
}