// Prosesler ile ilgili örnekler: Exec örneği

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
  int fr;

  // fork ile çatallama
  fr = fork();

  if(fr == 0) // Yavru proses alanı
    {
      printf("\nYAVRU\n"); // Yeni kod yüklemeden önce ekrana yazdırılır.
      execlp("/usr/bin/xeyes", "xeyes", "-fg",  "red", NULL);

    } else if(fr > 0) // Ebeveyn proses alanı
    {
      printf("\nEBEVEYN\n"); 
      while(1)  ;
    } else if( fr < 0) // Hata oluştu
    {
      printf("Fork hatası!\n");
      exit(-1);
    }

  return 0;
}
