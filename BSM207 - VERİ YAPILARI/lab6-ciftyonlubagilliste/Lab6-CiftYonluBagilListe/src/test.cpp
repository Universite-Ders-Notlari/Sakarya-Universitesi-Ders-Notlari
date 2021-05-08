#include "CiftYonluBagilListe.hpp"

int main(){
	CiftYonluBagilListe<int> *liste = new CiftYonluBagilListe<int>();
	liste->Ekle(34);
	liste->Ekle(154,0);
	liste->Ekle(300);
	liste->Ekle(310,2);
	cout<<*liste;
	liste->Sil(154);
	cout<<*liste;
	liste->Ekle(5,2);
	liste->KonumdakiniSil(0);
	cout<<*liste;
	cout<<liste->KonumuBul(310)<<endl;
	if(liste->ElemanBul(300)) cout<<"eleman var";
	else cout<<"eleman yok";
	delete liste;
}