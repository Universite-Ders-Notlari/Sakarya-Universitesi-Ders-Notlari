#include "Queue.hpp"

struct Ogrenci{
	int no;
	string adSoyad;
	Ogrenci(int numara, string isim){
		no=numara;
		adSoyad=isim;
	}
	friend ostream& operator<<(ostream& ekran, Ogrenci& sag){
		ekran<<sag.no<<" "<<sag.adSoyad<<endl;
		return ekran;
	}
};

int main(){
	Queue<Ogrenci*> *kuyruk = new Queue<Ogrenci*>();
	Ogrenci *ali = new Ogrenci(224,"Ali Yilmaz");
	Ogrenci *mehmet = new Ogrenci(100,"Mehmet Korkmaz");
	Ogrenci *veli = new Ogrenci(500,"veli sari");
	kuyruk->enqueue(ali);
	kuyruk->enqueue(mehmet);
	cout<<*(kuyruk->peek())<<endl;
	kuyruk->dequeue();
	cout<<*(kuyruk->peek())<<endl;
	kuyruk->enqueue(veli);
	kuyruk->enqueue(ali);
	cout<<*(kuyruk->peek())<<endl;
	delete ali;
	delete mehmet;
	delete veli;
	delete kuyruk;
	return 0;
}