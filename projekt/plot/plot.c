#include "plot.h"

void write_results(FILE *in3, sim_t results[], int n)
{
	int i;

	for(i = 0; i < n; i++)
		fprintf(in3, "%g %g %g\n", results[i].t, results[i].Tb, results[i].Tw);
}
