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
		~Queue(){
			clear();
		}		
};
#endif