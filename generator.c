 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <time.h>
 #include "generator.h"
 #include "podzial.h"
 char* usun_z_wektora(char* wektor){
 	int i,j,k,f,ctr=0,nowa_dl=0,dl=0, a=0;
 	
 	for(f=0; f<500; f++){
 		if(wektor[f] !=0 )
 			dl++;
 		else
 			break;
 	}
 	for(i=0; i< dl; i++){
 		if(wektor[i]!= ' '){
 			wektor[i]=0;
 			ctr++;
 		}
 		else
 			break;
 	}
 	a=ctr+1;
 	for(j=0; j<(dl-a); j++){
 	wektor[j]= wektor[ctr+1];	
 	nowa_dl++;
 	ctr++;
 	}
 	
 	for(k=dl; k>=nowa_dl; k--){
 		wektor[k]=0;
 	}
 
 	return wektor;	
 }
void generowanie(FILE *tekst,int ngram, FILE *plik){
	int c=0,d=0,i=0,j,k;
	int licznik =0;
	char pomocniczy[500];
	int dl_wektora=0;
	lista_t *aux, *tmp, *p, *l;

	dl_wektora=podzial(tekst,ngram);		
 	srand(time(NULL));
 	c= rand()/(RAND_MAX+1.0)*(dl_wektora);

	strcmp(pomocniczy, wektor[c].wyraz);
	fprintf(plik, "%s", pomocniczy);
	for(aux=wektor[c].next; aux != NULL; aux=aux->next)
		licznik++;
	d=rand()/(RAND_MAX+1.0)*licznik;
	for(k=0; k<d; k++){
		tmp=wektor[c].next;
		tmp=tmp->next;
	}	
	fprintf(plik, "%s", wektor[c].wyraz);
	usun_z_wektora(pomocniczy);
	strcat(pomocniczy,wektor[c].wyraz);
	
	while( wektor[i].wyraz != NULL){
		for(i=0; i<dl_wektora; i++){
			if(strcmp(wektor[i].wyraz, pomocniczy)==0)
				break;	
		}
		for(p=wektor[i].next; p != NULL; p=p->next)
			licznik++;
		d=0;
		d=rand()/(RAND_MAX+1.0)*licznik;
		for(j=0; j<d; j++){
			l=wektor[i].next;
			l=l->next;
		}	
		fprintf(plik, "%s", wektor[i].wyraz);
		usun_z_wektora(pomocniczy);
		strcat(pomocniczy,wektor[i].wyraz); 
	}
}
