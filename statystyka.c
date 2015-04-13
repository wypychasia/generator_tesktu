#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "statystyka.h"
#include "podzial.h"

int dl_txt(FILE *tekst){
        int licznik = 0;
        char b[100];

        b[0] = 0;
        while (fscanf(tekst, "%s", b) != EOF)
                licznik++;

	rewind(tekst);
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
char *ngram(FILE *tekst){
	int licznik=0;
	int najdluzszy=0;
	lista_t *tmp;
	int n=0,i;
     	static char ngram[500];

	n=dl_txt(tekst);
	rewind(tekst);
	for(i=0; i < n; i++){
	  for(tmp=wektor[i].next , licznik=0; tmp != NULL; tmp=tmp->next){
		licznik++;
	  }
	  if(licznik>najdluzszy){
		najdluzszy=licznik;
		ngram[0]=0;
		strcpy(ngram,wektor[i].wyraz);
	  }
        }

	return ngram;
}
void statystyka(FILE *plik, FILE *tekst){
	int n=0;
	double c=0;
	char ng[500];
	
	n=dl_txt(tekst);
	printf("Dlugosc tekstu wejsciowego = %d\n", n);

        strcpy(ng,ngram(tekst));
        printf("Najczęstszy ngram w tekście wejściowym to: ' %s' \n", ng);
	
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
