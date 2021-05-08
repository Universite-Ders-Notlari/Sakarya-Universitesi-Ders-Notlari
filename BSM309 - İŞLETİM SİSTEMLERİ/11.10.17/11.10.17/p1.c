// Prosesler ile ilgili örnekler: Proses id'sini görüntülemek
// 11 Ekim 2017

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
  int pid;

  pid = getpid();

  printf("pid = %d\n", pid);
  
  // Dikkat sonsuz döngü
  while(1) ;

  return 0;
}
