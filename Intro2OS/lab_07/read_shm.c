#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MODE 0666
#define N 10000000
#define SIZE (N * sizeof(int)) 

int main()
{
   int i, fd, *A;
   long sum1 = 0, sum2;
   char *NAME = getlogin();

   fd = shm_open(NAME, O_CREAT | O_RDWR, MODE);
   
   ftruncate(fd, SIZE);
   
   A = mmap(NULL, SIZE, PROT_READ|PROT_WRITE,
	    MAP_SHARED, fd, 0);
   
   for (i = 0; i < N; i++)
      sum1 += A[i];
   sum2 = (long) N * (N+1) / 2;
   printf("sum1 = %ld, sum2 = %ld\n", sum1, sum2);

   munmap(A, SIZE);
   
   close(fd);
   
   shm_unlink(NAME);	  
}
