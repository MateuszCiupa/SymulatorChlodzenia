#ifndef _APPROX_H_
#define _APPROX_H_

#include <stdio.h>
#include <stdlib.h>
#include "../splines/points.h"
#include "../splines/splines.h"

int approx(FILE *, int);

double eval(double);

void free_memory(void);

#endif
