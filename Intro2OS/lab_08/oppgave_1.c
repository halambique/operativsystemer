#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur som lagrer data om en prosess
struct process
{
   int id;      // Prosess-ID
   int arrive;  // Tidspunkt da prosessen ble satt inn i kø
   int cpu;     // Total CPU-tid som prosessen krever
   int start;   // Tidspunkt da prosessen startet å kjøre
   int end;     // Tidspunkt da prosessen er ferdig
   int extra_time;
};

// Globale variabler
int T = 0;         // Systemtid, starter simulering ved tid lik 0
int N;             // Antall prosesser
struct process *P; // Peker til array med prosessene

// read_file(): Leser data for N prosesser fra fil. Prosessene skal
// ligge sortert på ankomsttid. Alle data må være ikke-negative
// heltall. Alle tider oppgis i hele tidsenheter. Filformat:
//
//    N
//    id arrive CPU
//    id arrive CPU
//    id arrive CPU
//    ...
//



void read_file(char *filename)
{
   int i, last_arrive = 0;
   FILE *p_file;

   // Åpner fil og sjekker for feil i åpning
   p_file = fopen(filename, "r");
   if (p_file == NULL)
   {
      printf("Feil ved åpning av filen \"%s\"\n", filename);
      exit(-1);
   }

   // Leser antall prosesser
   fscanf(p_file, "%d", &N);

   // Oppretter array med plass til alle prosessene
   P = (struct process *) malloc(N * sizeof(struct process));

   // Leser inn en og en prosess. Prosessene skal ligge sortert på
   // ankomsttid i filen, hvis ikke gis en feilmelding.
   for (i = 0; i < N; i++)
   {
      fscanf(p_file, "%d %d %d", &P[i].id, &P[i].arrive, &P[i].cpu);
      P[i].start = P[i].end = 0;

      if (P[i].arrive < last_arrive)
      {
	 printf("Feil i ankomsttider, prosess %d\n", P[i].id);
         exit(-1);
      }
      last_arrive = P[i].arrive;
   }
   fclose(p_file);
}

// simulate(): Simulering av batch scheduling. "Kjører" til alle
// prosessene er ferdige.
//
void simulate()
{
  // Skal programmeres ferdig i oppgavene
	int i;
	int start_time = 0, end_time = 0;
	float total_wait = 0, total_turnaround = 0;

	printf("PID	Arrive	CPU	Start	End\n");

	for (i = 0; i < N; i++){
		if (P[i].arrive > end_time){
			P[i].extra_time = (P[i].arrive - end_time);
		}

		if (i == 0){
			start_time = P[i].arrive;
		}
		else{
			start_time = start_time + P[i-1].cpu + P[i].extra_time;
		}

		end_time = P[i].cpu + end_time + P[i].extra_time;

		P[i].start = start_time;
		P[i].end = end_time;

		printf("%d %d %d %d\n", P[i].id, P[i].arrive, P[i].cpu, P[i].start, P[i].end);

		total_wait += (P[i].start - P[i].arrive);
		total_turnaround += (P[i].end - P[i].arrive);
	}

	float avg_wait = total_wait / N;
	float avg_turnaround = total_turnaround / N;

	printf("Total wait-time: %.2f, Avgerage wait-time: %.2f\n", total_wait, avg_wait);
    printf("Total turnaround: %.2f, Avg. turnaround: %.2f\n", total_turnaround, avg_turnaround);

}


// main(): Leser filnavn med prosessdata, leser fil og kjører scheduling
//
int main()
{
   char filename[100];

   // Leser filnavn fra bruker
   printf("File? ");
   scanf("%s", filename);

   // Leser inn prosessdataene
   read_file(filename);

   // Simulerer batch-scheduling
   simulate();
}
