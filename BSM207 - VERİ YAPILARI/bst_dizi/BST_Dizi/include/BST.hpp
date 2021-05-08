#ifndef BST_HPP
#define BST_HPP

#include <cmath>
#include "ElemanYok.hpp"
#define SIZE 100

template <typename Nesne>
class BST{
	private:
		Nesne *elemanlar;
		int IndeksDolulugu[SIZE];
		
		int Ara(const Nesne& eleman, int suankiIndeks = 0){
			while(true){
				if(suankiIndeks == SIZE) return -1; // Eleman Yok
				if(elemanlar[suankiIndeks] == eleman && IndeksDolulugu[suankiIndeks] == 1){
					return suankiIndeks;
				}
				else if(eleman < elemanlar[suankiIndeks]) suankiIndeks = 2*suankiIndeks+1;
				else if(eleman > elemanlar[suankiIndeks]) suankiIndeks = 2*suankiIndeks+2;
			}
		}		
		bool ikininKatimi(int x)
		{
			while (((x % 2) == 0) && x > 1) 
				x /= 2;
			return (x == 1);
		}
		int EnKucukDeger(int i=0)
		{
			if(2*i+1 > SIZE) return i;
			else if(IndeksDolulugu[2*i+1] == 0) return i;
			else return EnKucukDeger(2*i+1);
		}
	public:
		BST(){
			elemanlar=new Nesne[SIZE];
			Temizle();
		}
		void Ekle(const Nesne& eleman){
			int suankiIndeks = 0;
			while(true){
				if(IndeksDolulugu[suankiIndeks] == 0){
					elemanlar[suankiIndeks]=eleman;
					IndeksDolulugu[suankiIndeks] = 1;
					break;
				}
				else if(eleman < elemanlar[suankiIndeks]) suankiIndeks = 2*suankiIndeks+1;
				else if(eleman > elemanlar[suankiIndeks]) suankiIndeks = 2*suankiIndeks+2;
				else return; // Aynı eleman var ağaca eklenmiyor
			}
		}		
		bool Varmi(const Nesne& eleman){
			if(Ara(eleman) == -1) return false;
			return true;
		}
		int Yukseklik(int indeks=0){
			if(IndeksDolulugu[indeks] == 0) return 0;
			return 1+max(Yukseklik(2*indeks+1),Yukseklik(2*indeks+2));
		}
		void Sil(const Nesne& eleman, int ind=0) throw(ElemanYok){
			int i = Ara(eleman, ind);
			if(i == -1) throw ElemanYok();
			else{
				IndeksDolulugu[i] = 0;		
				if(IndeksDolulugu[2*i+2] == 0)
				{
					if(IndeksDolulugu[2*i+1] == 1) //Sadece sol çocuğu varsa
					{
						int k = 2*i+1; int yedek[SIZE];
						for(int iter = 0; iter < SIZE ; iter++) yedek[iter] = 0;
						yedek[0] = k; int index = 0;
						
						// BFS algoritması kullanılarak sol alt ağaçtaki düğümler silinen düğümün yerine getiriliyor.
						for(int iter = 0; yedek[iter] != 0 && iter < SIZE; iter++) 
						{
							for(int x = 0; x < SIZE; x++)
							{
								if(ikininKatimi(yedek[iter]+1-x))
								{
									elemanlar[(yedek[iter]+x-1)/2] = elemanlar[yedek[iter]];
									IndeksDolulugu[(yedek[iter]+x-1)/2] = 1;
									IndeksDolulugu[yedek[iter]] = 0;
									break;
								}
							}
							if(IndeksDolulugu[2*yedek[iter] + 1] != 0)
							{
									yedek[++index] = 2*yedek[iter] + 1;
							}
							if(IndeksDolulugu[2*yedek[iter] + 2] != 0)
							{
									yedek[++index] = 2*yedek[iter] + 2;
							}
						}
					}
				}
				else
				{
					if(IndeksDolulugu[2*i+1] == 0) //Sadece sağ çocuğu varsa
					{
						int k = 2*i+2; int yedek[SIZE];
						for(int iter = 0; iter < SIZE ; iter++) yedek[iter] = 0;
						yedek[0] = k; int index = 0;
						
						// BFS algoritması kullanılarak sol alt ağaçtaki düğümler silinen düğümün yerine getiriliyor.
						for(int iter = 0; yedek[iter] != 0 && iter < SIZE; iter++){
							for(int x = 0; x < SIZE; x++){
								if(ikininKatimi((yedek[iter]+x)/2+1)){
									elemanlar[(yedek[iter]-2-x)/2] = elemanlar[yedek[iter]];
									IndeksDolulugu[(yedek[iter]-2-x)/2] = 1;
									break;
								}
							}
							IndeksDolulugu[yedek[iter]] = 0;
							if(IndeksDolulugu[2*yedek[iter] + 1] != 0)
							{
									yedek[++index] = 2*yedek[iter] + 1;
							}
							if(IndeksDolulugu[2*yedek[iter] + 2] != 0)
							{
									yedek[++index] = 2*yedek[iter] + 2;
							}
						}
					}
					else //İki çocuğu varsa
					{
						int x = EnKucukDeger(2*i+2);
						Nesne kopyalanacak = elemanlar[x];
						IndeksDolulugu[i] = IndeksDolulugu[x];
						elemanlar[i] = elemanlar[x];
						Sil(kopyalanacak, x);
					}
				}
			}
		}
		void Inorder(int suankiIndeks=0){
		 if(IndeksDolulugu[suankiIndeks] != 0){
				Inorder(2*suankiIndeks+1);
				cout<<elemanlar[suankiIndeks]<<" ";
				Inorder(2*suankiIndeks+2);
		  }
		}
		void Preorder(int suankiIndeks=0){
		 if(IndeksDolulugu[suankiIndeks] != 0){
				cout<<elemanlar[suankiIndeks]<<" ";
				Preorder(2*suankiIndeks+1);
				Preorder(2*suankiIndeks+2);
		  }
		}
		void Postorder(int suankiIndeks=0){
		 if(IndeksDolulugu[suankiIndeks] != 0){
				Postorder(2*suankiIndeks+1);
				Postorder(2*suankiIndeks+2);
				cout<<elemanlar[suankiIndeks]<<" ";
		  }
		}
		void Temizle(){	
			for(int i=0;i<SIZE;i++) IndeksDolulugu[i] = 0;
		}
		~BST(){
			delete [] elemanlar;
		}
};

#endif