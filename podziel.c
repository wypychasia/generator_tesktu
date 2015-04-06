#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "podzial.h"

lista_t wektor[1000];
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
void dopisz_ngram(char *wyraz){
	int liczba_ngramow = 0;
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
void dopisz_slowo(char *sufiks, char *wyraz){
	int i;

	for (i = 0; i < dl_wektora; i++){
		if (strcmp(wyraz, wektor[i].wyraz) == 0){
			dodaj(wektor[i].next, sufiks);
		}
	}
	printf("sufiks=%s\n",sufiks);
}
lista_t *dodaj(lista_t *l, char *slowo){
	lista_t *aux, *tmp;

	aux = malloc(sizeof(lista_t));
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
void podzial(FILE *tekst, int dltekstu,int ilosc_linii, int ngram){
	int max_dl_txt = 100;
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
		printf("wyraz=%s\n",wyraz);
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
	 printf("wyraz=%s\n",wyraz);
 strcpy(sufiks, aux->wyraz);
                dopisz_slowo(sufiks, wyraz);
	


}	

int main(int argc, char **argv){
	int i;
	FILE *in = fopen(argv[1],"r");

	podzial(in,16,1,4);	

return 0;
}
