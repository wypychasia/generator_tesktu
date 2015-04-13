#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "statystyka.h"
#include "generator.h"

void pomoc(){
printf("Poczatkowo prosze o wpisanie flagi '-txt' z nazwa pliku, z ktorego będzie tworzony tekst wyjsciowy oraz flage '-plik' z nazwa pliku do ktorego wpisany zostanie tekst wyjsciowy. Następnie z flagą '-ngram' wybrac zadana dlugosc ngramu oraz z flagą '-dl_txt' wpisac dlugosc tekstu wejsciowego. By otrzymać informacje o statystyce należy wpisać flagę '-stat'.\n");
}

int main(int argc, char  **argv)
{
  int dlugosc_tekstu = 0;
  int ngram = 0;
  int i;

  if(strcmp(argv[1],"-pomoc")==0)
	pomoc();

  for(i=0; i<argc-1;i++){
    if(strcmp(argv[i],"-txt")==0){
      FILE *tekst = fopen(argv[i+1],"r");
          if(tekst == NULL)
	    printf("Blad we wczytywaniu tekstu\n");
    }
    else if(srtcmp(argv[i],"-plik")==0){
      FILE *plik = fopen(argv[i+1],"w");
        if(plik == NULL)
     	  printf("Blad we wczytywaniu pliku wyjsiowego\n");  
    }
    else if(strcmp(argv[i],"-ngram")==0)
      ngram=atoi(argv[i+1]);
  	if(ngram == 0)
  	  ngram = 2;
    else if(strcmp(argv[i],"-dl_txt")){
      dlugosc_tekstu=atoi(argv[i+1]);
	if(dlugosc_tekstu == 0)
	  printf("Brak dlugosci tesktu - problemy ze statystyka\n");  
    }
    else if(strcmp(argv[i],"-stat")==0)
      statystyka();
  
    else
      pomoc();
}
  if(tekst!=NULL && plik != NULL)
     generowanie(tekst,ngram,plik);
  return 0;
}
