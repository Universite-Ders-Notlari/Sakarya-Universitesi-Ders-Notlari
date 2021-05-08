// �ablon liste gezici s�n�f�
#ifndef LISTEGEZICI_HPP
#define LISTEGEZICI_HPP

#include "Hatalar.hpp"
#include "Dugum.hpp"

template <typename Nesne>
class ListeGezici{
	public:
		Dugum<Nesne> *simdiki; // Listede o anki bulunan konumu ifade eder.
		ListeGezici(){  // Yap�c� metot
			simdiki=NULL;
		}
		ListeGezici(Dugum<Nesne> *dugum){  // Yap�c� metot
			simdiki=dugum;
		}
		bool SonaGeldimi() const{
			return simdiki == NULL;
		}
		void ilerle() throw(ListeSonu){ // ilerleme metodu
			if(SonaGeldimi()) throw ListeSonu();
			simdiki = simdiki->ileri;
		}
		const Nesne& Getir() const throw(NullHatasi) { // o anki konumdaki nesneyi getirir.
			if(simdiki == NULL) throw NullHatasi();
			return simdiki->eleman;
		}
};
#endif