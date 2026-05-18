#ifndef HUFFMAN_HPP
#define HUFFMAN_HPP

#include <fstream>
#include <cstring>

#include "Dugum.hpp"

class Huffman{
	private:
		int harfler;  			// harflerin ASCII karşılıkları
		string girdi;			// dosyadan okunan girdi
		Dugum *root;
				
		Dugum* AgacOlustur(int frek[]);
		void KodOlustur(Dugum*,string);
		int MinDugumIndeks(Dugum* dugumler[]);
		void DosyaOku(string)throw(string);
		void inorder(Dugum*);
		void SilDugum(Dugum*);
	public:
		Huffman(string)throw(string);
		void Kodla();
		friend ostream& operator<<(ostream&,Huffman&);
		~Huffman();
};


#endif