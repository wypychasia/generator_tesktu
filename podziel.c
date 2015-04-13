#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "podzial.h"

lista_t wektor[10000];
int dl_wektora =0;

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
int dopisz_ngram(char *wyraz){
	int liczba_ngramow = 0;
	int i;

	for (i = 0; i < dl_wektora; i++){
		if (strcmp(wyraz, wektor[i].wyraz) == 0){
			return 0;
		}
	}

	strcpy(wektor[dl_wektora].wyraz, wyraz);
	dl_wektora++;
	liczba_ngramow++;
	return 0;
	

}
void dopisz_slowo(char *sufiks, char *wyraz){
	int i;

	for (i = 0; i < dl_wektora; i++){
		if (strcmp(wyraz, wektor[i].wyraz) == 0){
			wektor[i].next=dodaj(wektor[i].next, sufiks);
		}
	}
}
lista_t *dodaj(lista_t *l, char *slowo){
	lista_t *aux, *tmp;

	aux=malloc(sizeof(lista_t));

	strcpy(aux->wyraz, slowo);
	aux->next = NULL;

	if (l == NULL){
		l = aux;
	}else{
		for (tmp = l; tmp->next != NULL; tmp = tmp->next);
		tmp->next = aux;
	}
	return l;
}
int  podzial(FILE *tekst, int ngram){
	int i,k;
	char wyraz[5000];
	char slowo[200];
	char sufiks[200];

	lista_t *l, *aux;
	l = NULL;
	wyraz[0] = 0;

	for (i = 0; i < ngram; i++){
		strcpy(slowo, czytaj_slowo(tekst));
		l = dodaj(l, slowo);
	}

	for (aux = l; aux->next != NULL; aux = aux->next);
	aux->next = l;
	
	for(k=0; k<ngram; k++){
	l=l->next;
	}	
	while (!feof(tekst)){
		wyraz[0] = 0;
		for (aux = l, i=0; i<ngram; i++, aux= aux->next){
			strcat(wyraz, aux->wyraz);
			strcat(wyraz, " ");
		}
                dopisz_ngram(wyraz);
		strcpy(slowo, czytaj_slowo(tekst));
		strcpy(l->wyraz, slowo);
		l = l->next;

	}
		wyraz[0]=0;
                for (aux = l, i=0; i<ngram; i++, aux= aux->next){
                        strcat(wyraz, aux->wyraz);
                        strcat(wyraz, " ");
                }
		dopisz_ngram(wyraz);
	rewind(tekst);
	l=NULL;
	for (i = 0; i < ngram+1; i++)
		l = dodaj(l, czytaj_slowo(tekst));
	for (aux = l; aux->next != NULL; aux = aux->next);
	aux->next = l;
	while (!feof(tekst)){
		wyraz[0] = 0;
		for (aux = l, i = 0; i<ngram; i++, aux = aux->next){
			strcat(wyraz, aux->wyraz);
			strcat(wyraz, " ");
		}
		strcpy(sufiks, aux->wyraz);
		dopisz_slowo(sufiks, wyraz);
		strcpy(slowo, czytaj_slowo(tekst));
		strcpy(l->wyraz, slowo);
		l = l->next;
        }
  	 wyraz[0] = 0;
         for (aux = l, i = 0; i<ngram; i++, aux = aux->next){
            strcat(wyraz, aux->wyraz);
            strcat(wyraz, " ");
                }
	 strcpy(sufiks, aux->wyraz);
                dopisz_slowo(sufiks, wyraz);
	return dl_wektora;
}
