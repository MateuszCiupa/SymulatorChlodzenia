#ifndef _READ_H_
#define _READ_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	double h;
	double A;
	double mb;
	double mw;
	double Tb;
	double Tw;
	double cb;
	double t;
	int s;
} data_t;

int read_data(FILE *, data_t *);

void write_data(data_t *);

#endif
