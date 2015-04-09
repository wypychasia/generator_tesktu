#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "generator.h"
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
void generowanie(int dl_wektora){
	int c,d,i;
	int licznik =0;
	char pomocniczy[500];
		
	srand(time(NULL));
	c= rand()/(RAND_MAX+1.0)*(dl_wektora);

	strcmp(pomocniczy, wektor[c].wyraz);
	fprintf(plik, "%s", pomocniczy);
	while(wektor[c].next !=NULL)
		licznik++;
	d=rand()/(RAND_MAX+1.0)*licznik;
	for(i=0; i<d; i++){
		wektor[c].wyraz=wektor[c].next;
	}	
	fprintf(plik, "%s", wektor[c].wyraz);
	usun_z_wektora(pomocniczy);
	strcat(pomocniczy,wektor[c].wyraz);
	
	while( *wektor.wyraz != NULL){
		for(i=0; i<dl_wektora; i++){
			if(strcmp(wektor[i], pomocniczy))
				break;	
		}
		while(wektor[i].next !=NULL)
			licznik++;
		d=0;
		d=rand()/(RAND_MAX+1.0)*licznik;
		for(i=0; i<d; i++){
			wektor[i].wyraz=wektor[i].next;
		}	
		fprintf(plik, "%s", wektor[i].wyraz);
		usun_z_wektora(pomocniczy);
		strcat(pomocniczy,wektor[i].wyraz); 
}
}

