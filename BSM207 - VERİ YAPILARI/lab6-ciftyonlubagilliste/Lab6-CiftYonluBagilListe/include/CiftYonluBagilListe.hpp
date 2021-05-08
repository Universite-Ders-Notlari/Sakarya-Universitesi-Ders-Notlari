// �ablon ba��l liste
#ifndef BAGILLISTE_HPP
#define BAGILLISTE_HPP

#include "ListeGezici.hpp"

template <typename Nesne>
class CiftYonluBagilListe{
	private:
		Dugum<Nesne> *basDugum; // i�inde eleman olmayan sadece listenin ba��n� tutan d���m.
		int elemanSayisi;
		
		/// Eleman i�ermeyen liste ba��n� d�nd�r�yor
		ListeGezici<Nesne> ListeBasi() const{
			return ListeGezici<Nesne>(basDugum);
		}
		ListeGezici<Nesne> OncekiniBul(const Nesne& aranan) const throw(ElemanYok){
			Dugum<Nesne> *gezici = basDugum;
			while(gezici->ileri != NULL){
				if(gezici->ileri->eleman == aranan) return ListeGezici<Nesne>(gezici);
				gezici = gezici->ileri;
			}
			throw ElemanYok();
		}
		ListeGezici<Nesne> OncekiniKonumuIleBul(int konum) const throw(Tasma){
			if(konum<0 || konum > Uzunluk()) throw Tasma();
			int indeks=0;
			Dugum<Nesne> *gezici = basDugum;
			while(gezici->ileri != NULL && konum != indeks++) gezici = gezici->ileri;
			return ListeGezici<Nesne>(gezici);
		}
		
		ListeGezici<Nesne> BulKonum(int konum) const throw(Tasma){
			if(konum<0 || konum > Uzunluk()) throw Tasma();
			int indeks=0;
			Dugum<Nesne> *gezici = basDugum;
			while(gezici->ileri != NULL && konum != indeks++) gezici = gezici->ileri;
			return ListeGezici<Nesne>(gezici);
		}
		
		ListeGezici<Nesne> Bul(const Nesne& aranan) const throw(ElemanYok)
		{
			Dugum<Nesne> *gezici = basDugum;
			while(gezici != NULL && gezici->eleman != aranan) gezici=gezici->ileri;
			if(gezici == NULL) throw ElemanYok();
			return ListeGezici<Nesne>(gezici);
		}
	public:
		CiftYonluBagilListe(){
			basDugum = new Dugum<Nesne>(); // Bo� bir d���m olu�turuluyor	
			elemanSayisi=0;			
		}
		bool Bosmu() const{
			return basDugum->ileri == NULL;
		}
		int Uzunluk() const{
			return elemanSayisi;
		}		
		/// Listenin ilk d���m�n� d�nd�r�r
		ListeGezici<Nesne> Ilk() const throw(ListeBos){
			if(Bosmu()) throw ListeBos();
			return ListeGezici<Nesne>(basDugum->ileri);
		}
		/// Listenin ilk eleman�n� d�nd�r�r
		const Nesne& IlkEleman() const throw(ListeBos){
			if(Bosmu()) throw ListeBos();
			return basDugum->ileri->eleman;
		}
		/// Listenin son eleman�n� d�nd�r�r
		const Nesne& SonEleman() const throw(ListeBos){
			if(Bosmu()) throw ListeBos();
			ListeGezici<Nesne> gezici;
			for(gezici=Ilk();!gezici.SonaGeldimi();gezici.ilerle()); // for d�ng�s�n� sadece sona ileleyene kadar �al��t�r�yoruz.
			return gezici->Getir();
		}
		/// Listenin sonuna verilen eleman� ekler
		void Ekle(const Nesne& yeni){
			Ekle(yeni,Uzunluk());
		}
		/// Listenin istenen konumuna verilen eleman� ekler
		void Ekle(const Nesne& yeni,int konum) throw(Tasma){
			ListeGezici<Nesne> gezici;
			try{
				gezici = OncekiniKonumuIleBul(konum);
			}
			catch(Tasma ts){
				throw ts;
			}
			
			Dugum<Nesne> *geciciGeri = gezici.simdiki->ileri;
			gezici.simdiki->ileri = new Dugum<Nesne>(yeni,gezici.simdiki->ileri,gezici.simdiki);
			if(geciciGeri != NULL) geciciGeri->geri = gezici.simdiki->ileri;
			elemanSayisi++;
		}
		/// Verilen eleman� listede bulur ve siler.
		void Sil(const Nesne& aranan) throw(ElemanYok){			
			try{
				int konum = KonumuBul(aranan);
				KonumdakiniSil(konum);
			}
			catch(ElemanYok ey){
				throw ey;
			}
		}
		void KonumdakiniSil(int konum) throw(Tasma){
			try{
				ListeGezici<Nesne> gezici = OncekiniKonumuIleBul(konum);
				Dugum<Nesne> *sil = gezici.simdiki->ileri;
				gezici.simdiki->ileri = gezici.simdiki->ileri->ileri;
				if(gezici.simdiki->ileri != NULL) gezici.simdiki->ileri->geri = gezici.simdiki;
				delete sil;
				elemanSayisi--;
			}
			catch(Tasma ts){
				throw ts;
			}
		}
		bool ElemanBul(const Nesne& aranan) const{
			if(Bosmu()) return false;
			Dugum<Nesne> *gezici = basDugum->ileri;
			while(gezici != NULL){
				if(gezici->eleman == aranan) return true;
				gezici = gezici->ileri;
			}
			return false;
		}
		int KonumuBul(const Nesne& aranan) const throw(ElemanYok){
			if(Bosmu()) throw ElemanYok();
			int indeks=0;
			Dugum<Nesne> *gezici = basDugum->ileri;
			while(gezici != NULL){
				if(gezici->eleman == aranan) return indeks;
				indeks++;
				gezici = gezici->ileri;
			}
			throw ElemanYok();
		}
		/// Listedeki elemanlar� temizler
		void Temizle(){
			while(!Bosmu())
				Sil(Ilk().Getir());
		}
		~CiftYonluBagilListe(){
			Temizle();
			delete basDugum;
		}
		friend ostream& operator<<(ostream& ekran, CiftYonluBagilListe &sag){
			if(sag.Bosmu()) ekran<<"Liste bos";
			ListeGezici<Nesne> gezici = sag.Ilk();
			for(;!gezici.SonaGeldimi();gezici.ilerle())
				ekran<<gezici.Getir()<<" ";
			ekran<<endl;
			return ekran;
		}
};
#endif