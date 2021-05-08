// Prosesler ile ilgili örnekler: Ebeveyn proses id'si
// Tarih: 11 ekim 2017

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
  int pid, ppid;

  pid = getpid();
  ppid = getppid();

  printf("pid = %d, ppid = %d\n", pid, ppid);

  //  while(1) ;

  return 0;
}
