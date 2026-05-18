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
	Queue<int> *kuyruk = new Queue<int>();
	kuyruk->enqueue(15);
	kuyruk->enqueue(16);
	kuyruk->enqueue(17);
	kuyruk->enqueue(18);
	kuyruk->enqueue(19);
	kuyruk->enqueue(20);
	kuyruk->enqueue(21);
	
	kuyruk->dequeue();
	kuyruk->dequeue();
	kuyruk->dequeue();
	
	kuyruk->enqueue(1);
	kuyruk->enqueue(2);
	kuyruk->enqueue(3);
	kuyruk->enqueue(4);
	kuyruk->enqueue(5);
	kuyruk->enqueue(6);
	kuyruk->enqueue(7); 
	cout<<kuyruk->peek()<<endl<<endl;	
	delete kuyruk;
	
	Queue<Ogrenci*> *kuyruk2 = new Queue<Ogrenci*>();
	Ogrenci *ali = new Ogrenci(224,"Ali Yilmaz");
	Ogrenci *mehmet = new Ogrenci(100,"Mehmet Korkmaz");
	Ogrenci *veli = new Ogrenci(500,"veli sari");
	kuyruk2->enqueue(ali);
	kuyruk2->enqueue(mehmet);
	cout<<*(kuyruk2->peek())<<endl;
	kuyruk2->dequeue();
	cout<<*(kuyruk2->peek())<<endl;
	kuyruk2->enqueue(veli);
	kuyruk2->enqueue(ali);
	cout<<*(kuyruk2->peek())<<endl;
	delete ali;
	delete mehmet;
	delete veli;
	delete kuyruk2;
	return 0;
}