#include "read.h"

int read_data(FILE *in1, data_t *data)
{
	int i;

	i = fscanf(in1, "%lg", &data->h);	

	if(i == 0 || i == EOF)
		return 1;

	i = fscanf(in1, "%lg", &data->A);	

	if(i == 0 || i == EOF)
		return 1;

	i = fscanf(in1, "%lg", &data->mb);	

	if(i == 0 || i == EOF)
		return 1;

	i = fscanf(in1, "%lg", &data->mw);	

	if(i == 0 || i == EOF)
		return 1;

	i = fscanf(in1, "%lg", &data->Tb);	

	if(i == 0 || i == EOF)
		return 1;

	i = fscanf(in1, "%lg", &data->Tw);	

	if(i == 0 || i == EOF)
		return 1;

	i = fscanf(in1, "%lg", &data->cb);	

	if(i == 0 || i == EOF)
		return 1;

	i = fscanf(in1, "%lg", &data->t);	

	if(i == 0 || i == EOF)
		return 1;

	i = fscanf(in1, "%d", &data->s);	

	if(i == 0 || i == EOF)
		return 1;

	fclose(in1);

	return 0;
}

void write_data(data_t *tmp)
{
	tmp->h = 50;
	tmp->A = 0.0109;
	tmp->mb = 0.2;
	tmp->mw = 2.5;
	tmp->Tb = 1200;
	tmp->Tw = 65;
	tmp->cb = 0.22;
	tmp->t = 1;
	tmp->s = 100;
}
