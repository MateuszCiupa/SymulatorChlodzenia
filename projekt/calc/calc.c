#include "calc.h"

void calc(data_t *data, sim_t sim[])
{
	sim[0].Tw = data->Tw;
	sim[0].Tb = data->Tb;
	sim[0].t = 0;
	
	double cw;
	double t = data->t / data->s;
	int i;

	for(i = 0; i < data->s - 1; i++)
	{
		cw = eval(sim[i].Tw);
		sim[i+1].Tw = sim[i].Tw + t * (sim[i].Tb - sim[i].Tw) * data->h * data->A / (data->mw * cw);
		sim[i+1].Tb = sim[i].Tb + t * (sim[i].Tw - sim[i].Tb) * data->h * data->A / (data->mb * data->cb);
		sim[i+1].t = sim[i].t + t; 
	}
}

int temp_search(sim_t tab[], int elem)
{
	int i;
	
	for(i = 0; i < elem; i++)
		if(tab[i].Tb < 200)
			return i;

	return 0;
}

void mass_search(data_t *tmp, sim_t tab[], int n)
{
	double t[n];
	int i;	
	int k;
	double step = 0.01;

	for(i = 0; i < n; i++)
	{
		calc(tmp, tab);
		k = temp_search(tab, tmp->s);

		if(k)
			if(tab[k].t >= 0.4 && tab[k].t <= 0.41)
			{
				printf("Minimalna masa oleju potrzebna do ostudzenia preta do 200stopni w czasie 0.4s to: %g;\n", tmp->mw);	
				break;
			}
		tmp->mw += step;
	}

	tmp->mw -= step*n;

}
