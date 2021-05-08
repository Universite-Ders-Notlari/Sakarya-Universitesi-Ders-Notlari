#ifndef KUYRUK_HPP
#define KUYRUK_HPP

#include "KuyrukBos.hpp"

template <typename Object>
class Node{
	public:
		Object item;
		Node<Object> *next;
		Node(Object itm,Node<Object> *nxt=NULL){
			item=itm;
			next=nxt;
		}
};

template <typename Object>
class Queue{
	private:
		Node<Object> *front;
		Node<Object> *back;
		int length;
		
		Node<Object>* previousMaxNode(){
			Node<Object> *prev = NULL;
			Node<Object> *tmp = front;
			Object max=front->item;
			while(tmp->next != NULL){
				if(tmp->next->item > max){
					max = tmp->next->item;
					prev = tmp;
				}
				tmp = tmp->next;
			}
			return prev;
		}
	public:
		Queue(){
			front=back=NULL;
			length=0;
		}
		void clear(){
			while(!isEmpty()) dequeue();
		}
		int count() const{
			return length;
		}
		bool isEmpty() const {
			if(length == 0) return true;
			return false;
		}
		/// Kuyrukta en öndeki elemanı getirir
		const Object& peek() const throw(KuyrukBos){
			if(isEmpty()) throw KuyrukBos();
			return front->item;
		}
		void enqueue(const Object& item){			
			Node<Object> *enSon = new Node<Object>(item);	
			if(isEmpty()) front = back = enSon;
			else{
				back->next = enSon;
				back = enSon;
			}
			length++;
		}
		void dequeue() throw(KuyrukBos){
			if(isEmpty()) throw KuyrukBos();			
			Node<Object> *eskiOn = front;
			front = front->next;
			delete eskiOn;
			length--;
		}		
		void dequeueMax() throw(KuyrukBos){
			if(isEmpty()) throw KuyrukBos();			
			Node<Object> *prev = previousMaxNode();
			Node<Object> *tmp;
			if(prev == NULL){
				tmp = front;
				front = front->next;
			} 
			else{
				if(prev->next == back) back=prev; // en son eleman silinecekse
				tmp = prev->next;
				prev->next = prev->next->next;				
			}
			delete tmp;
			length--;
		}
		~Queue(){
			clear();
		}		
};
#endif