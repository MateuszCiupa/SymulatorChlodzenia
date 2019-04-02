#include "../read/read.h"
#include "../errors/errors.h"
#include "../calc/calc.h"
#include "../approx/approx.h"
#define TAB_POINTS 500

int main(int argc, char **argv)
{
	data_t data;
	
	if(errors(argc, argv))
		return EXIT_FAILURE;

	char *file1 = argc > 1 ? argv[1] : "data.txt";
	char *file3 = argc > 2 ? argv[2] : "results.txt";
	char *file2 = argc > 3 ? argv[3] : "splines/points.pt";

	FILE *in1 = fopen(file1, "r");
	FILE *in3 = fopen(file3, "w");
	FILE *in2 = fopen(file2, "r");

	int nbase = argc > 4 ? atoi(argv[4]) : 20;	

	if(in1 == NULL || in2 == NULL || in3 == NULL)
		return EXIT_FAILURE;
 
	if(approx(in2, nbase)) //obliczenie współczynników wielomianu/aktywacja spline
		return EXIT_FAILURE;
	
	if(read_data(in1, &data)) //czytanie danych z pliku
	{
		printf("Zly plik z danymi!\n");
		return EXIT_FAILURE;
	}

	sim_t results[data.s];

	calc(&data, results); //tworzenie punktów pomiarowych Tb,Tw(t)
	
	write_results(in3, results, data.s); //wpisanie punktów pomiarowych do pliku

	data_t tmp; //trzecia część zadania

	write_data(&tmp); //wpisanie gotowych danych

	sim_t tab[tmp.s];

	mass_search(&tmp, tab, TAB_POINTS); //szukanie minimalnej masy
	
	free_memory(); //zwolnienie spline

	return 0;
}
