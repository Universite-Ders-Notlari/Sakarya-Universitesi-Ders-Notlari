// Prosesler ile ilgili örnekler: fork örneği
// 11 Ekim 2017

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
  int pid, fr;

  pid = getpid();
  printf("Forktan önce ebeveyn pid = %d\n", pid);

  // fork çağrısı
  fr = fork();

  if(fr == 0) // Yavru proses alanı
    {
      printf("Burası yavru proses\n");
      pid = getpid();
      printf("Forktan sonra ve yavru içinden pid = %d\n", pid);
      printf("\nYAVRU: fr = %d\n", fr); 
      while(1)  ;  
    } else if(fr > 0) // Ebeveyn proses alanı
    {
      printf("Burası ebeveyn proses\n");
      pid = getpid();
      printf("Forktan sonra ve ebeveyn içinden pid = %d\n", pid);
      printf("\nEBEVEYN: fr = %d\n", fr); 
      while(1)  ;
    } else if( fr < 0) // Hata oluştu
    {
      printf("Fork hatası!\n");
      exit(-1);
    }


  

  //  while(1) ;

  return 0;
}
