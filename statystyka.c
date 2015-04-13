#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "statystyka.h"
#include "podzial.h"

int dl_txt(FILE *plik){
        int licznik = 0;
        char b[100];

        b[0] = 0;
        while (fscanf(plik, "%s", b) != EOF)
                licznik++;

	rewind(plik);
        return licznik;
}

float czestotliwosc(FILE *plik){
	int i,n=0,licznik=0;
	char slowo[100];
	float czestosc=0;
	char wyraz[100];

	n=dl_txt(plik);
	printf("Podaj słowo, dla którego chcesz poznać częstotliwość:  ");
	scanf("%s",slowo);
	rewind(plik);

	for(i=0; i < n; i++){
		strcpy(wyraz, czytaj_slowo(plik));
		if(strcmp(wyraz, slowo)==0)
			licznik++;
	}
	
	if(licznik ==0){
		return czestosc;
	}else{
		czestosc=(double)licznik/n;
	}
	rewind(plik);
	return czestosc;
}
void statystyka(FILE *plik){
	int n=0;
	double c=0;
	
	n=dl_txt(plik);
	printf("Dlugosc tekstu wyjsciowego = %d\n", n);
	
	c=czestotliwosc(plik);
	printf("Częstotliwość podanego słowa wynosi %g\n",c);
}
/*
int main (int argc, char **argv){

	FILE *in=fopen(argv[1],"r");
	statystyka(in);

  return 0;
}
*/
