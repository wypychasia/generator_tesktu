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
/*char *slowo(FILE *tekst){
	char tmp[100];
	static char wyraz[100];
	int n=0,i,nowa_dl=0,j, a=0,k,b=0;
	int s=0, najwiekszy=0;
	n=dl_txt(tekst);
	tablica_t t[10000];
	rewind(tekst);

	strcpy(t[0].slowo,czytaj_slowo(tekst));
	t[0].licznik++;
	nowa_dl++;

	for(i=1; i< n; i++){
		strcpy(tmp,czytaj_slowo(tekst));
		printf("nowa dl=%d\n", nowa_dl);
	    for(j=0; j< nowa_dl; j++){
		a=0;
		a=t[j].licznik;
		if(strcmp(t[j].slowo,tmp)==0){
			t[j].licznik++;
			b=0;
			b=t[j].licznik;
			printf("b=%d\n",b);
	        }
	        if(b > a){
		   strcpy(t[i].slowo,tmp);
		   t[i].licznik++;
		   nowa_dl++;
	    }
	}
	}
	printf("nowa_dl=%d\n",nowa_dl);

	for(k=0; k<nowa_dl; k++){
	  s=t[k].licznik;
	  if(s>najwiekszy){
		najwiekszy=s;
		strcpy(wyraz,t[k].slowo);
	  }
        }

	
	
	rewind(tekst);
	return wyraz;
}*/
void statystyka(FILE *plik, FILE *tekst){
	int n=0;
	double c=0;
	char ng[500];
	char s[100];
	
	n=dl_txt(tekst);
	printf("Dlugosc tekstu wejsciowego = %d\n", n);

        strcpy(ng,ngram(tekst));
        printf("Najczęstszy ngram w tekście wejściowym to: ' %s' \n", ng);
/*	
	strcpy(s,slowo(tekst));
	printf("Najczęstsze słowo w tekście wejściowym to : %s \n", s);
*/
	c=czestotliwosc(plik);
	printf("Częstotliwość podanego słowa wynosi %g\n",c);
	
}

