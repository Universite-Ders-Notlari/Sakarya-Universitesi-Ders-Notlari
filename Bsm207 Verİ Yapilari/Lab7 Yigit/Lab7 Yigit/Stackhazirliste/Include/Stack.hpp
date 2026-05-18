#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
using namespace std;

#include "BagilListe.hpp"

template <typename Nesne>
class Stack{
	private:
		BagilListe<Nesne>* liste;
	public:
		Stack(){
			liste = new BagilListe<Nesne>();
		}
		bool isEmpty() const{
			return liste->Bosmu();
		}
		void push(const Nesne& eleman){
			liste->Ekle(eleman,0); 
		}
		void pop() throw(ElemanYok){
			if(isEmpty()) throw ElemanYok("Eleman yok");
			liste->KonumdakiniSil(0);
		}
		const Nesne& top() const throw(ElemanYok){
			if(isEmpty()) throw ElemanYok("Eleman yok");
			return liste->IlkEleman();
		}		
		void makeEmpty(){
			liste->Temizle();
		}
		~Stack(){
			makeEmpty();
			delete liste;
		}		
};
#endif