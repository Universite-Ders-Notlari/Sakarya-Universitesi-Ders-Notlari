#include <iostream>
using namespace std;
#include "Arac.hpp"

int main(){
Arac *a = new Arac(1995);
Arac b(2007);
cout<<a->Hiz()<<endl;
a->Hizlan(10);
cout<<a->Hiz()<<endl;
cout<<b.Yil()<<endl;
delete a;
return 0;
}