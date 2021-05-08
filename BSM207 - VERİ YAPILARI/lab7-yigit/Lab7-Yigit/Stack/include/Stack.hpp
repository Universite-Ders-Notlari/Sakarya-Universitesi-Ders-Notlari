#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
using namespace std;

#include "ElemanYok.hpp"

template <typename Nesne>
class Stack{
	private:
		Nesne *elemanlar;
		int stackBasi;
		int elemanSayisi;
		int kapasite;
		
		bool dolumu(){
			return elemanSayisi == kapasite;
		}
		
		/**
			Kapasite dolunca yer a�ar.
		*/
		void yerAc(int boyut)
		{
			 Nesne *tmp = new Nesne[boyut];
			 for(int j=0;j<elemanSayisi;j++) tmp[j]= elemanlar[j];
			 if(elemanlar != NULL) delete [] elemanlar;
			 elemanlar = tmp;
			 kapasite = boyut;
		}
	public:
		Stack(){
			elemanlar=NULL;
			stackBasi=-1;
			elemanSayisi=0;
			kapasite=0;
		}
		bool isEmpty() const{
			return stackBasi == -1;
		}
		void push(const Nesne &eleman){
			if(dolumu()){
				yerAc(max(1,2*kapasite));
			}			
			stackBasi++;
			elemanlar[stackBasi] = eleman;
			elemanSayisi++;
		}
		void pop() throw(ElemanYok){
			if(isEmpty()) throw ElemanYok("Eleman yok"); // Stack bo�ken pop metodu �a�r�lamaz
			stackBasi--;
			elemanSayisi--;
		}
		const Nesne& top()const throw(ElemanYok){
			if(isEmpty()) throw ElemanYok("Eleman yok"); // Stack bo�ken top metodu �a�r�lamaz
			return elemanlar[stackBasi];
		}
		void makeEmpty(){ // stack'i ilk haline �ivirir
			stackBasi=-1;
			elemanSayisi=0;
			kapasite=0;
			
			if(elemanlar != NULL) delete [] elemanlar;
			elemanlar=NULL;
		}
		~Stack(){
			makeEmpty();
		}
};
#endif