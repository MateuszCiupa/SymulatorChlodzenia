#ifndef _CALC_H_
#define _CALC_H_

#include "../read/read.h"
#include "../approx/approx.h"

typedef struct
{
	double Tb;
	double Tw;
	double t;
} sim_t;

void calc(data_t *, sim_t *);

void mass_search(data_t *, sim_t *, int);

int temp_search(sim_t *, int);

#endif
