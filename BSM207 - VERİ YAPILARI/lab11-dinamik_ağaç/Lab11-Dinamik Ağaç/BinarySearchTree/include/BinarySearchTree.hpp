#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <cmath>
#include "ElemanYok.hpp"

template <typename Nesne>
struct Dugum{
	Nesne veri;
	Dugum<Nesne> *sol;
	Dugum<Nesne> *sag;
	Dugum(const Nesne& vr,Dugum<Nesne> *sl=NULL,Dugum<Nesne> *sg=NULL){
		veri=vr;
		sol=sl;
		sag=sg;
	}
};

template <typename Nesne>
class BinarySearchTree{
	private:
		Dugum<Nesne> *root;
		
		void AraveEkle(Dugum<Nesne> *&alt_Dugum, const Nesne &yeni){
			if(alt_Dugum == NULL) alt_Dugum = new Dugum<Nesne>(yeni);
			else if(yeni < alt_Dugum->veri)
				AraveEkle(alt_Dugum->sol,yeni);
			else if(yeni > alt_Dugum->veri)
				AraveEkle(alt_Dugum->sag,yeni);
			else return; // Ayný eleman var.
		}
		bool AraveSil(Dugum<Nesne> *&alt_Dugum,const Nesne &yeni)
		{			
			if(alt_Dugum == NULL) return false; //Eleman yok
			if(alt_Dugum->veri == yeni)
				return DugumSil(alt_Dugum);
			else if(yeni < alt_Dugum->veri)
				return AraveSil(alt_Dugum->sol,yeni);
			else
				return AraveSil(alt_Dugum->sag,yeni);
		}
		bool DugumSil(Dugum<Nesne> *&alt_Dugum)
		{			
			Dugum<Nesne> *silinecekDugum = alt_Dugum;
			
			if(alt_Dugum->sag == NULL) alt_Dugum = alt_Dugum->sol;
			else if(alt_Dugum->sol == NULL)alt_Dugum = alt_Dugum->sag;
			else{
				silinecekDugum = alt_Dugum->sol;
				Dugum<Nesne> *ebeveynDugum = alt_Dugum;
				while(silinecekDugum->sag != NULL){
					ebeveynDugum=silinecekDugum;
					silinecekDugum=silinecekDugum->sag;
				}
				alt_Dugum->veri = silinecekDugum->veri;
				if(ebeveynDugum == alt_Dugum) alt_Dugum->sol = silinecekDugum->sol;
				else ebeveynDugum->sag = silinecekDugum->sol;
			}
			delete silinecekDugum;
			return true;
		}
		void Inorder(Dugum<Nesne> *alt_Dugum) const{
			if(alt_Dugum != NULL){
				Inorder(alt_Dugum->sol);
				cout<<alt_Dugum->veri<<" ";
				Inorder(alt_Dugum->sag);
			}
		}
		void Preorder(Dugum<Nesne> *alt_Dugum) const{
			if(alt_Dugum != NULL){
				cout<<alt_Dugum->veri<<" ";
				Preorder(alt_Dugum->sol);
				Preorder(alt_Dugum->sag);
			}
		}
		void Postorder(Dugum<Nesne> *alt_Dugum) const{
			if(alt_Dugum != NULL){
				Postorder(alt_Dugum->sol);
				Postorder(alt_Dugum->sag);				
				cout<<alt_Dugum->veri<<" ";
			}
		}		
		int Yukseklik(Dugum<Nesne> *alt_Dugum){
			if(alt_Dugum == NULL) return -1; // Ortada düðüm yoksa yükseklik anlamsýzdýr. Hata da fýrlatýlabilir.
			return 1+max(Yukseklik(alt_Dugum->sol),Yukseklik(alt_Dugum->sag));
		}
		public:
			BinarySearchTree(){
				root = NULL;
			}
			bool Bosmu() const{
				return root == NULL;
			}
			void Ekle(const Nesne &yeni)
			{
				AraveEkle(root,yeni);
			}
			void Sil(const Nesne &veri) throw(ElemanYok)
			{
				if(AraveSil(root,veri) == false) throw ElemanYok();
			}
			void Inorder() const{
				Inorder(root);
			}
			void Preorder() const{
				Preorder(root);
			}
			void Postorder() const{
				Postorder(root);
			}
			void Temizle(){
				while(!Bosmu()) DugumSil(root);
			}
			int Yukseklik(){
				return Yukseklik(root);
			}
			~BinarySearchTree(){
				Temizle();
			}		
};

#endif