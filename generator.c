 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <time.h>
 #include "generator.h"
 #include "podzial.h"

 char* usun_z_wektora(char* w){
 	int i,j,k,f,ctr=0,nowa_dl=0,dl=0, a=0;
 	
 	for(f=0; f<500; f++){
 		if(w[f] !=0 )
 			dl++;
 		else
 			break;
 	}
 	for(i=0; i< dl; i++){
 		if(w[i]!= ' '){
 			w[i]=0;
 			ctr++;
 		}
 		else
 			break;
 	}
 	a=ctr+1;
 	for(j=0; j<(dl-a); j++){
 	w[j]= w[ctr+1];	
 	nowa_dl++;
 	ctr++;
 	}
 	for(k=dl; k>=nowa_dl; k--){
 		w[k]=0;
 	}
	 
 	return w;	
 }
int generowanie(FILE *tekst,int ngram, FILE *plik){
	int c=0,d=0,i=0,j,k,s;
	int licznik =0;
	char pomocniczy[500];
	lista_t *aux, *tmp, *p, *l;

	dl_wektora=podzial(tekst,ngram);
 	srand(time(NULL));
 	c= rand()/(RAND_MAX+1.0)*(dl_wektora);
	strcpy(pomocniczy, wektor[c].wyraz);

	fprintf(plik, "%s", pomocniczy);
	for(aux=wektor[c].next; aux != NULL; aux=aux->next)
		licznik++;
	if(licznik == 1)
		d=0;
	else if(licznik ==0)
		return 0;
	else
	d=rand()/(RAND_MAX+1.0)*licznik;

	for(k=0,tmp = wektor[c].next; k<d;tmp=tmp->next,k++);
	fprintf(plik, "%s", tmp->wyraz);
	fprintf(plik, "%s", " ");
	usun_z_wektora(pomocniczy);
	strcat(pomocniczy,tmp->wyraz);
	strcat(pomocniczy," ");
	
	for(s=0; s<100; s++){
		for(i=0; i<dl_wektora; i++){
			if(strcmp(wektor[i].wyraz, pomocniczy)==0)
				break;	
		}
		for(p=wektor[i].next, licznik=0; p != NULL; p=p->next)
			licznik++;
		if(licznik == 1)
                	d=0;
        	else if(licznik ==0)
                	return 0;
        	else{
			d=0;
        		d=rand()/(RAND_MAX+1.0)*licznik;
			if(d>=licznik)
				d=licznik-1;
		}
		for(j=0, l=wektor[i].next; j<d;l=l->next,j++);
		fprintf(plik, "%s", l->wyraz);
		fprintf(plik, "%s", " ");
		usun_z_wektora(pomocniczy);
		strcat(pomocniczy,l->wyraz); 
		strcat(pomocniczy, " ");
		}
	return 0;
}
