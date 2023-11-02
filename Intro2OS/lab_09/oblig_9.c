#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur som lagrer data om en page frame
struct page_frame
{
  int id;			// Page-ID/-number
  int load;			// Tidspunkt da pagen ble lagt inn i RAM
  int last;			// Tidspunkt da pagen siste ble referert til
  int R;			// Referenced bit
  int M;			// Modified bit
};

// Globale variabler
int T = 300;			// Systemtid, settes til passende verdi
int N;				// Antall prosesser
struct page_frame *PF;		// Peker til array med page frames

// read_file(): Leser data for N page frames fra fil. Pages skal
// ligge sortert på ankomsttid. Alle data må være ikke-negative
// heltall. Alle tider oppgis i hele tidsenheter. Filformat:
//
//    N
//    id load last R M
//    id load last R M
//    id load last R M
//    ...
//
void
read_file (char *filename)
{
  int i;
  FILE *p_file;

  // Åpner fil og sjekker for feil i åpning
  p_file = fopen (filename, "r");
  if (p_file == NULL)
    {
      printf ("Feil ved åpning av filen \"%s\"\n", filename);
      exit (-1);
    }

  // Leser antall page frames
  fscanf (p_file, "%d", &N);

  // Oppretter array med plass til alle pages
  PF = (struct page_frame *) malloc (N * sizeof (struct page_frame));

  // Leser inn en og en page frame.
  for (i = 0; i < N; i++)
    fscanf (p_file, "%d %d %d %d %d", &PF[i].id, &PF[i].load,
	    &PF[i].last, &PF[i].R, &PF[i].M);
  fclose (p_file);
}

//first_in_first_out(): Simulering av page replacement med FIFO
// OPPGAVE 1
void
first_in_first_out ()
{
  int *queue = (int *) malloc (T * sizeof (int));
  int first = 0;
  int last = 0;

  for (int i = 0; i < T; i++)
    queue[i] = -1;

  printf ("FIFO:\n");

  for (int i = 0; i < N; i++)
    {
      int exists = 0;
      for (int f = first; f <= last; f++)
	{
	  if (PF[i].id == queue[f])
	    {
	      exists = 1;
	      break;
	    }
	}

      if (!exists)
	{
	  printf ("Page: %d  Loaded: %d  Last ref: %d   R: %d M: %d\n",
		  PF[i].id, PF[i].load, PF[i].last, PF[i].R, PF[i].M);

	  queue[first] = PF[i].id;
	  first = (first + 1) % T;
	  last = (last + 1) % T;
	}
    }
  free (queue);
}

//least_recently_used(): Simulering av page replacement med LRU
// OPPGAVE 2
void least_recently_used ()
{
  int *last_used = (int *) malloc (N * sizeof (int));
  int least_recently_used_index;

  for (int i = 0; i < N; i++)
  {
    last_used[i] = -1;
  }

  printf ("Least Recently Used:\n");

  for (int i = 0; i < N; i++)
  {
    last_used[PF[i].id] = PF[i].last;
  }

  for (int i = 0; i < N; i++)
  {
    least_recently_used_index = 0;
    for (int x = 1; x < N; x++)
    {
      if (last_used[x] < last_used[least_recently_used_index])
      {
        least_recently_used_index = x;
      }
    }
    printf ("Page: %d   Loaded: %d   Last ref: %d   R: %d   M: %d\n",
        PF[least_recently_used_index].id,
        PF[least_recently_used_index].load,
        PF[least_recently_used_index].last,
        PF[least_recently_used_index].R,
        PF[least_recently_used_index].M);

    last_used[least_recently_used_index] = T + 1;
  }

  free (last_used);
}


// OPPGAVE 3
//second_chance(): Simulering av page replacement med Second Chance
void second_chance()
{
  int timer = 0;

  int *reference_bit = (int *)malloc(N * sizeof(int));

  for (int i = 0; i < N; i++)
  {
    reference_bit[i] = PF[i].R;
  }

  printf("Second Chance:\n");

  for (int i = 0; i < N; i++)
  {
    while (1)
    {
      if (reference_bit[timer] == 0)
      {
        printf("Page: %d   Loaded: %d   Last ref: %d   R: %d   M: %d\n",
               PF[timer].id, PF[timer].load, PF[timer].last, PF[timer].R,
               PF[timer].M);

        reference_bit[timer] = 1;
        break;
      }
      else
      {
        reference_bit[timer] = 0;
      }
      timer = (timer + 1) % N;
    }
  }
  free(reference_bit);
}


// main(): Leser filnavn med page frame data, leser inndata fra fil og
// kjører tre ulike page replacement algoritmer
//
int
main ()
{
  char filename[100];

  // Leser filnavn fra bruker
  printf ("File? ");
  scanf ("%s", filename);

  // Leser inn prosessdataene
  read_file (filename);

  // Simulerer page replacement
  first_in_first_out ();
  least_recently_used ();
  second_chance ();
  return 0;
}
