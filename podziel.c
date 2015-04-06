#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "podzial.h"

char* czytaj_slowo(FILE *tekst){
	static char slowo[100];
	char a;
	int i = 0;
	while ((a = fgetc(tekst)) != EOF){
		if (a==' ')
			break;
		slowo[i] = a;
		i++;
	}
	slowo[i]=0;
	return slowo;
}
void dopisz_ngram(char *wyraz){
	int liczba_ngramow = 0;
	lista_t *wektor;
	int dl_wektora = 0;
	int i;

	for (i = 0; i < dl_wektora; i++){
		if (strcmp(wyraz, wektor[i].wyraz) == 0){
				break;
		}
	}

	strcpy(wektor[dl_wektora].wyraz, wyraz);
	dl_wektora++;
	liczba_ngramow++;

}
lista_t *dodaj(lista_t *l, char *slowo){
	lista_t *aux;

	aux = malloc(sizeof(lista_t));
	strcpy(aux->wyraz, slowo);
	aux->next = NULL;

	if (l == NULL)
		l = aux;
	else{
		for (; l->next != NULL; l = l->next);
		l->next = aux;
	}
	return l;
}
void podzial(FILE *tekst, int dltekstu,int ilosc_linii, int ngram){
	int max_dl_txt = 100;
	int i,k;
	char wyraz[5000];
	char slowo[200];

	lista_t *l, *aux;
	l = NULL;
	wyraz[0] = 0;

	for (i = 0; i < ngram; i++)
		l = dodaj(l, czytaj_slowo(tekst));
	for (aux = l; aux->next != NULL; aux = aux->next);
	aux->next = l;
		
	while (!feof(tekst)){

		///

		strcpy(slowo, czytaj_slowo(tekst));
		strcpy(l->wyraz, slowo);
		l = l->next;
		wyraz[0] = 0;
		for (aux = l, i=0; i<ngram; i++, aux= aux->next){
			strcat(wyraz, aux->wyraz);
			strcat(wyraz, " ");
		}
		dopisz_ngram(wyraz);

	}
}
int main(int agrc, char **argv){
	FILE *in = fopen(argv[1], "r");
	int i;

	for(i=0; i<atoi(argv[2]); i++)
	printf("Słowo %d : %s\n", i,czytaj_slowo(in));

return 0;
}
