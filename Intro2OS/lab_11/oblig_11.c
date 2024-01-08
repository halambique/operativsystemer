#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1
#define M 100
#define N 100


int m;
int n;
int E[M];
int A[M];
int C[N][M];
int R[N][M];

void
read_file (char *filename)
{
  int i, j;
  FILE *p_file;
  p_file = fopen (filename, "r");
  if (p_file == NULL)
    {
      printf ("Feil ved åpning av filen %s\n", filename);
      exit (-1);
    }

  fscanf (p_file, "%d %d", &m, &n);

  for (i = 0; i < m; i++)
    fscanf (p_file, "%d", &E[i]);

  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      fscanf (p_file, "%d", &C[i][j]);

  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      fscanf (p_file, "%d", &R[i][j]);

  for (i = 0; i < m; i++)
    {
      A[i] = E[i];
      for (j = 0; j < n; j++)
	A[i] -= C[j][i];
    }
  fclose (p_file);
}

int safe() {
  int processing[M], complete[N], i, j, process_done, incomplete_processes;
  for (i = 0; i < m; i++)
    processing[i] = A[i];
  for (i = 0; i < n; i++)
    complete[i] = FALSE;

  while (1) {
    process_done = FALSE;
    for (i = 0; i < n; i++) {
      if (!complete[i]) {
        int can_allocate = TRUE;
        for (j = 0; j < m; j++) {
          if (R[i][j] > processing[j]) {
            can_allocate = FALSE;
            break;
          }
        }
        if (can_allocate) {
          for (j = 0; j < m; j++)
          processing[j] += C[i][j];
          complete[i] = TRUE;
          process_done = TRUE;
          printf("p%d can run A = [ ", i + 1);
          for (j = 0; j < m; j++)
            printf("%d ", processing[j]);
          printf("]\n");
        }
      }
    }

    if (!process_done) {
      incomplete_processes = FALSE;
      for (i = 0; i < n; i++) {
        if (!complete[i]) {
          incomplete_processes = TRUE;
          break;
        }
      }
      if (incomplete_processes) {
        printf("No more processes can run\n");
      }
      break;
    }
  }

  for (i = 0; i < n; i++) {
    if (!complete[i]) {
      return FALSE;
    }
  }
  return TRUE;
}

int main()
{
   char filename[100];

   // Leser filnavn fra bruker
   printf("File? ");
   scanf("%s", filename);

   // Leser inn data fra fil
   read_file(filename);

   // Simulerer Bankers
   if (safe())
     printf("Safe\n");
   else
     printf("Unsafe\n");
}
