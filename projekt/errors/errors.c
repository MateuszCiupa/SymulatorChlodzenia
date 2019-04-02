#include "errors.h"
#include <string.h>

void help(void)
{
	printf("Witaj w symulatorze chlodzenia preta w oleju chlodzacym!\n\n");
	printf("Aby uzyc programu, nalezy przy jego wywolaniu podac\n");
	printf("CZTERY odpowiednio sformatowane argumenty w ponizszej kolejnosci:\n\n");
	printf("\t1) Plik z parametrami preta i cieczy (stalymi)\n");
	printf("\t2) Pusty plik sluzacy do zapisania wynikow obliczen programu\n");
	printf("\t3) Plik z punktami zaleznosci cw(Tw)\n");
	printf("\t4) Liczbe funkcji sklejanych niezbedna do aproksymacji\n");
}

int errors(int argc, char **argv)
{
	if(argc == 1)
	{
		printf("%s: Z powodu braku argumentow wejscia, uzyto wartosci domyslnych.\n", argv[0]);
		printf("Aby wyswietlic instrukcje uzywania programu, wywolaj go z argumentem 'help' lub 'h'.\n");
		return 0;
	}

	else if(argc != 5)
	{
		if( strcmp(argv[1], "help") == 0 || strcmp(argv[1], "h") == 0)
		{
			help();
			return 1;
		}
		else
		{
			printf("%s: Bledna ilosc argumentow wejscia.\n", argv[0]);
			printf("Aby wyswietlic instrukcje uzywania programu, wywolaj go z argumentem 'help' lub 'h'.\n");
			return 1;
		}
	}

	return 0;
}
