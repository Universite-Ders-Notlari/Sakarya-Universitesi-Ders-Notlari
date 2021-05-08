#include "Arac.hpp"
Arac::Arac(int yl){
hiz=0;
yil=yl;
}
void Arac::Hizlan(float artiHiz){
hiz+=artiHiz;
}
void Arac::Yavasla(float eksiHiz){
hiz-=eksiHiz;
}
float Arac::Hiz(){
return hiz;
}
float Arac::Yil(){
return yil;
}