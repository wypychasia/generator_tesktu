#ifndef _PODZIAL_H_
#define _PODZIAL_H_

typedef struct e{
	char wyraz[200];
	struct e *next;
} lista_t;

char* czytaj_slowo(FILE *tekst);
int dopisz_ngram(char *wyraz);
void dopisz_slowo(char *sufiks, char *wyraz);
lista_t *dodaj(lista_t *l, char *slowo);
void podzial(FILE *tekst, int dltekstu,int ilosc_linii, int ngram);

#endif


