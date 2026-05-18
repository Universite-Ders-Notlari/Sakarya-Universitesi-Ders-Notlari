#include "Huffman.hpp"

int main(){
	Huffman *huffman = new Huffman("dene.txt");
	huffman->Kodla();
	cout<<*huffman;
	delete huffman;
	return 0;
}