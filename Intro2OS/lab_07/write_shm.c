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
   char *NAME = getlogin();
   
   fd = shm_open(NAME, O_CREAT | O_RDWR, MODE);
   
   ftruncate(fd, SIZE);
   
   A = mmap(NULL, SIZE, PROT_READ|PROT_WRITE,
	    MAP_SHARED, fd, 0);

    for (i = 0; i < N; i++)
       A[i] = i + 1;
   
   munmap(A, SIZE);
   
   close(fd);
}
