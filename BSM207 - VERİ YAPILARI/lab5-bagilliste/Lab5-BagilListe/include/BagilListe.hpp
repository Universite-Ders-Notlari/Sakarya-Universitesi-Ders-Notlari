// �ablon ba��l liste
#ifndef BAGILLISTE_HPP
#define BAGILLISTE_HPP

#include "ListeGezici.hpp"

template <typename Nesne>
class BagilListe{
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
	public:
		BagilListe(){
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
			gezici.simdiki->ileri = new Dugum<Nesne>(yeni,gezici.simdiki->ileri);
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
			ListeGezici<Nesne> onceki;
			try{
				onceki = OncekiniKonumuIleBul(konum);
			}			
			catch(Tasma ts){
				throw ts;
			}
			if(onceki.simdiki->ileri != NULL){
				Dugum<Nesne> *eskiDugum = onceki.simdiki->ileri;
				// silinen eleman� es ge�
				onceki.simdiki->ileri = onceki.simdiki->ileri->ileri;
				delete eskiDugum;
				elemanSayisi--;
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
		~BagilListe(){
			Temizle();
			delete basDugum;
		}
		friend ostream& operator<<(ostream& ekran, BagilListe &sag){
			if(sag.Bosmu()) ekran<<"Liste bos";
			else{
				ListeGezici<Nesne> gezici = sag.Ilk();
				for(;!gezici.SonaGeldimi();gezici.ilerle())
					ekran<<gezici.Getir()<<" ";
				ekran<<endl;
			}
			return ekran;
		}
};
#endif