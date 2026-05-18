#ifndef KUYRUK_HPP
#define KUYRUK_HPP

#include "BagilListe.hpp"
#include "KuyrukBos.hpp"

template <typename Object>
class Queue{
	private:
		BagilListe<Object>* list;
		
	public:
		Queue(){
			list = new BagilListe<Object>();
		}
		void clear(){
			while(!isEmpty()) dequeue();
		}
		int count() const{
			return list->Uzunluk();
		}
		bool isEmpty() const {
			if(count() == 0) return true;
			return false;
		}
		/// Kuyrukta en öndeki elemanı getirir
		const Object& peek() const throw(KuyrukBos){
			if(isEmpty()) throw KuyrukBos();
			return list->IlkEleman();
		}
		void enqueue(const Object& item){
			list->Ekle(item);
		}
		void dequeue() throw(KuyrukBos){
			if(isEmpty()) throw KuyrukBos();			
			list->KonumdakiniSil(0);
		}
		~Queue(){
			delete list;
		}		
};
#endif