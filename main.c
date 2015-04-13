#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "statystyka.h"
#include "generator.h"
#include "podzial.h"

void pomoc(){
printf("Poczatkowo prosze o wpisanie flagi '-txt' z nazwa pliku, z ktorego będzie tworzony tekst wyjsciowy oraz flage '-plik' z nazwa pliku do ktorego wpisany zostanie tekst wyjsciowy. Następnie z flagą '-ngram' wybrac zadana dlugosc ngramu oraz z flagą '-dl_txt' wpisac dlugosc tekstu wejsciowego. By otrzymać informacje o statystyce należy wpisać flagę '-stat'.\n");
}

int main(int argc, char  **argv)
{
  int dlugosc_tekstu = 0;
  int ngram = 0;
  FILE *tekst, *plik;

  if(strcmp(argv[1],"-pomoc")==0){
	pomoc();
	return 0;
  }

  if(strcmp(argv[1],"-txt")==0){
      FILE *tekst = fopen(argv[2],"r");
          if(tekst == NULL){
	    printf("Blad we wczytywaniu tekstu\n");
	      return -1;
	  }	
  }else
	pomoc();
  if(strcmp(argv[3],"-plik")==0){
      FILE *plik = fopen(argv[4],"w");
        if(plik == NULL){
     	  printf("Blad we wczytywaniu pliku wyjsiowego\n");  
	     return -1;
	}	
    }else
	pomoc();
  if(strcmp(argv[5],"-ngram")==0){
      ngram=atoi(argv[6]);
  	if(ngram == 0)
  	  ngram = 2;
    }
  if(strcmp(argv[7],"-dl_txt")==0){
      dlugosc_tekstu=atoi(argv[8]);
	if(dlugosc_tekstu == 0)
	  printf("Brak dlugosci tesktu - problemy ze statystyka\n");  
    } 
  else{
      pomoc();
      return 0;
  }
  generowanie(tekst,ngram,plik);
  printf("Wygenerowany tekst został zapisany do pliku\n");
  if(strcmp(argv[9],"-stat")==0){

      statystyka(plik);
      return 0;
  }

  fclose(plik);
  fclose(tekst);   
  return 0;
}
