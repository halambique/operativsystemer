#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur som lagrer data om en page frame
struct page_frame
{
   int id;   // Page-ID/-number
   int load; // Tidspunkt da pagen ble lagt inn i RAM
   int last; // Tidspunkt da pagen siste ble referert til
   int R;    // Referenced bit
   int M;    // Modified bit
};

// Globale variabler
int T = 300;           // Systemtid, settes til passende verdi
int N;                 // Antall prosesser
struct page_frame *PF; // Peker til array med page frames

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
void read_file(char *filename)
{
   int i;
   FILE *p_file;

   // Åpner fil og sjekker for feil i åpning
   p_file = fopen(filename, "r");
   if (p_file == NULL)
   {
      printf("Feil ved åpning av filen \"%s\"\n", filename);
      exit(-1);
   }

   // Leser antall page frames
   fscanf(p_file, "%d", &N);

   // Oppretter array med plass til alle pages
   PF = (struct page_frame *) malloc(N * sizeof(struct page_frame));

   // Leser inn en og en page frame.
   for (i = 0; i < N; i++)
      fscanf(p_file, "%d %d %d %d %d", &PF[i].id, &PF[i].load,
	      &PF[i].last, &PF[i].R, &PF[i].M);
   fclose(p_file);
}

//first_in_first_out(): Simulering av page replacement med FIFO
//
// Skal programmeres ferdig i oppgave 1
void first_in_first_out()
{
    int *frame_queue = (int *)malloc(T * sizeof(int)); // Queue to store page frame IDs
    int front = 0; // Front of the queue
    int rear = 0;  // Rear of the queue

    // Initialize queue and other variables
    for (int i = 0; i < T; i++)
        frame_queue[i] = -1; // -1 indicates an empty slot

    printf("First-In-First-Out\n");

    // Iterate through the page frames
    for (int i = 0; i < N; i++)
    {
        // Check if the current page frame is in the queue
        int found = 0;
        for (int j = front; j <= rear; j++)
        {
            if (PF[i].id == frame_queue[j])
            {
                found = 1;
                break;
            }
        }

        // If the page frame is not in the queue, replace the front element
        if (!found)
        {
            printf("Page: %d   Loaded: %d   Last ref: %d   R: %d   M: %d\n",
                   PF[i].id, PF[i].load, PF[i].last, PF[i].R, PF[i].M);

            // Replace the front element in the queue with the current page frame
            frame_queue[front] = PF[i].id;

            // Update front and rear pointers in the queue
            front = (front + 1) % T;
            rear = (rear + 1) % T;
        }
    }

    // Free the dynamically allocated memory
    free(frame_queue);
}


//least_recently_used(): Simulering av page replacement med LRU
//
// Skal programmeres ferdig i oppgave 2

void least_recently_used()
{
    int *last_referenced = (int *)malloc(N * sizeof(int)); // Array to store last referenced timestamps
    int least_recently_used_index; // Index of the least recently used page frame

    // Initialize last referenced timestamps to -1 (indicating not referenced yet)
    for (int i = 0; i < N; i++)
    {
        last_referenced[i] = -1;
    }

    printf("Least Recently Used\n");

    // Iterate through the page frames
    for (int i = 0; i < N; i++)
    {
        // Update the last referenced timestamp for the current page frame
        last_referenced[PF[i].id] = i;

        // Find the least recently used page frame
        least_recently_used_index = 0;
        for (int j = 1; j < N; j++)
        {
            if (last_referenced[PF[j].id] < last_referenced[PF[least_recently_used_index].id])
            {
                least_recently_used_index = j;
            }
        }

        // Print the least recently used page frame details
        if (i >= T - 1)
        {
            printf("Page: %d   Loaded: %d   Last ref: %d   R: %d   M: %d\n",
                   PF[least_recently_used_index].id, PF[least_recently_used_index].load,
                   PF[least_recently_used_index].last, PF[least_recently_used_index].R, PF[least_recently_used_index].M);
        }
    }

    // Free the dynamically allocated memory
    free(last_referenced);
}


//second_chance(): Simulering av page replacement med Second Chance
//
// Skal programmeres ferdig i oppgave 3
void second_chance()
{
    int hand = 0; // Clock hand pointer

    // Array to track the reference bit for each page frame
    int *reference_bit = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
    {
        reference_bit[i] = PF[i].R;
    }

    printf("Second Chance\n");

    // Iterate through the page frames
    for (int i = 0; i < N; i++)
    {
        // Simulate clock algorithm
        while (1)
        {
            // If the reference bit is 0, replace the current page frame
            if (reference_bit[hand] == 0)
            {
                printf("Page: %d   Loaded: %d   Last ref: %d   R: %d   M: %d\n",
                       PF[hand].id, PF[hand].load, PF[hand].last, PF[hand].R, PF[hand].M);

                // Update the current page frame with the new one
                reference_bit[hand] = 1;
                break;
            }
            else
            {
                // Set the reference bit to 0 and move the clock hand to the next page frame
                reference_bit[hand] = 0;
                hand = (hand + 1) % N;
            }
        }
    }

    // Free the dynamically allocated memory
    free(reference_bit);
}


// main(): Leser filnavn med page frame data, leser inndata fra fil og
// kjører tre ulike page replacement algoritmer
//
int main()
{
   char filename[100];

   // Leser filnavn fra bruker
   printf("File? ");
   scanf("%s", filename);

   // Leser inn prosessdataene
   read_file(filename);

   // Simulerer page replacement
   first_in_first_out();
   least_recently_used();
   second_chance();
}
1m

