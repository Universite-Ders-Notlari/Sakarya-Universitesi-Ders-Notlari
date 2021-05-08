// isdigit metodunu i�eren k�t�phane parametre olarak verilen karakterin rakam olup olmad���n� d�nd�r�yor.
#include <cctype> 
// strchr kullanabilmek i�in, string'te aranan karakterin ilk konumunu d�nd�r�r. 
#include <cstring> 
// atof  kullan�m� i�in   
#include <cstdlib>   

#include "Stack.hpp"

/**
 ��lem �nceli�ini kontrol eden fonksiyon
 */
bool OncelikDusukmu(char ch1, char ch2)
{
	  if (ch1 == '(')
         return false;

	  else if (ch2 == '(')
		 return false;

      else if (ch2 == ')')
		 return true;

	  else if ((ch1 == '^') && (ch2 == '^'))
          return false;

  	  else if (ch1 == '^')
          return true;
    
	  else if (ch2 == '^')
          return false;

      else if ((ch1 == '*') || (ch1 == '/'))
          return true;

      else if ((ch2 == '*') || (ch2 == '/'))
          return false;

      else
          return true;

}

string InfixtoPostfix(string infix)
{
    int uzunluk = infix.length();
    Stack<char> *stack = new Stack<char>();
    string postfix = "";
 
    for (int i = 0; i < uzunluk; i++)
    {
        if (isdigit(infix[i]))
        {
            while(isdigit(infix[i])){ postfix+=infix[i]; i++;} // Ondalik say�lar desteklenmiyor.
			postfix+=" ";
			i--;
			continue;
        }
        else if (infix[i] == '(')
        {
            stack->push(infix[i]);
        }
        else if ((infix[i] == '*') || (infix[i] == '+') || (infix[i] == '-') || (infix[i] == '/'))
        {
            while ((!stack->isEmpty()) && (stack->top() != '('))
            {
                if (OncelikDusukmu(stack->top(), infix[i]))
                {
                    postfix+=stack->top();
					postfix+=" ";
					stack->pop();
                }
                else
                {
                    break;
                }
            }
            stack->push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while ((!stack->isEmpty()) && (stack->top() != '('))
            {
                postfix+=stack->top();
				postfix+=" ";
				stack->pop();
            }
            if (!stack->isEmpty())
                stack->pop(); // Sol parantez y���ttan pop ediliyor.
        }
    }
    while (!stack->isEmpty())
    {
        postfix+=stack->top();
		postfix+=" ";
		stack->pop();
    }
	delete stack;
    return postfix;
}

double PostfixHesapla(string postfix)
{
   double sonuc = -1;
   int uzunluk = postfix.length();
   Stack<double> *yigit = new Stack<double>();
   for(int i=0;i<uzunluk;i++)
   {
	 // bo�luklar� ge�
     if (isspace(postfix[i])) continue;
     if (isdigit(postfix[i]))
        {
		   string sayi ="";
		   while(isdigit(postfix[i])){ sayi+=postfix[i]; i++;} // Ondalik say�lar desteklenmiyor.
		   double s;
		   s=atof(sayi.c_str());
		   yigit->push(s);
		   i--;
		   continue;
		}
	 else // Operat�r ise
	  {
	     double sayi2 = yigit->top();
		 yigit->pop();
		 double sayi1 = yigit->top();
		 yigit->pop();
	     switch(postfix[i])
		 {
		   case '+':
		     yigit->push(sayi1+sayi2);
			 break;
		   case '-':
		     yigit->push(sayi1-sayi2);
			 break;
		   case '*':
		     yigit->push(sayi1*sayi2);
			 break;
		   case '/':
		     if(sayi2==0) return -1;  // S�f�ra b�l�nme hatas�
		     yigit->push(sayi1/sayi2);
			 break;
		   default: // Hata Desteklenmeyen operat�r
		     return -1;
			 break;
		 }
	  }
   }
   if(!yigit->isEmpty()) sonuc=yigit->top();
   yigit->pop();
   delete yigit;
   return sonuc;
}

int main()
{
   string sayi;
   cout<<"Infix ifade:";
   cin>>sayi;
   string postfix = InfixtoPostfix(sayi);
   cout<<"Postfix:"<<postfix<<endl;
   cout<<"Sonuc="<<PostfixHesapla(postfix)<<endl;
   return 0;
}