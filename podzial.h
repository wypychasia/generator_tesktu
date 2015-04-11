#ifndef _PODZIAL_H_
#define _PODZIAL_H_
#include <stdio.h>

typedef struct e{
	char wyraz[200];
	struct e *next;
} lista_t;

extern lista_t wektor[1000];
extern int dl_wektora;

char* czytaj_slowo(FILE *tekst);
int dopisz_ngram(char *wyraz);
void dopisz_slowo(char *sufiks, char *wyraz);
lista_t *dodaj(lista_t *l, char *slowo);
int podzial(FILE *tekst, int ngram);

#endif


