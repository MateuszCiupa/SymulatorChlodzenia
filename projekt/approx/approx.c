#include "approx.h"

spline_t *spline;

int approx(FILE *fpoints, int nbase)
{
	points_t points;

	if(read_points_failed(fpoints, &points))
	{
		printf("Błąd podczas wczytywania punktów z pliku!\n");
		return 1;
	}

	fclose(fpoints);

	if((spline = splines_approximate(&points, nbase)) != NULL);
	else
	{
		printf("Błąd podczas wyznaczania współczynników funkcji sklejanych!\n");
		return 2;
	}

	return 0;
}

double eval(double Tb)
{
	return splines_eval(spline, Tb);	
}

void free_memory(void)
{
	free_spline(spline);
}
