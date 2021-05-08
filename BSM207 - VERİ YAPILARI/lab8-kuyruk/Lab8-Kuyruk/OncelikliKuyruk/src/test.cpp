#include "Queue.hpp"

int main(){
	Queue<int> *kuyruk = new Queue<int>();
	
	kuyruk->enqueue(724);
	kuyruk->enqueue(1225);
	kuyruk->enqueue(531);
	kuyruk->dequeueMax();
	cout<<kuyruk->peek()<<endl;
	
	delete kuyruk;
	return 0;
}