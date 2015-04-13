#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "statystyka.h"
#include "generator.h"
#include "podzial.h"

void pomoc(){
printf("Poczatkowo prosze o wpisanie flagi '-txt' z nazwa pliku, z ktorego będzie tworzony tekst wyjsciowy oraz flage '-plik' z nazwa pliku do ktorego wpisany zostanie tekst wyjsciowy. Następnie z flagą '-ngram' wybrac żądaną dlugosc ngramu oraz z flagą '-dl_txt' żądaną dlugosc tekstu wyjsciowego. By otrzymać informacje o statystyce należy wpisać flagę '-stat' na końcu linii.\n");
}

int main(int argc, char  **argv)
{
  int ngram = 0;
  FILE *tekst;
  FILE *plik;
  int i;
  int a=0,dlugosc=0,b=0;

  if(argc == 1){
	pomoc();
	return 0;
  }
 
  if(strcmp(argv[1],"-pomoc")==0){
	pomoc();
	return 0;
  }
 for(i=1; i<argc; i++){
  if(strcmp(argv[i],"-txt")==0){
      b=i+1;
      tekst = fopen(argv[i+1],"r");
  }	
  if(strcmp(argv[i],"-plik")==0){
      a=i+1;
      plik = fopen(argv[i+1],"w");
  }	
  if(strcmp(argv[i],"-ngram")==0){
      ngram=atoi(argv[i+1]);
  }
  if(strcmp(argv[i],"-dl_txt")==0){
	dlugosc=atoi(argv[i+1]);
  }
 }
  if(ngram == 0)
	ngram = 2;
  if(tekst == NULL){
        printf("Blad we wczytywaniu tekstu\n");
        pomoc();
        return -1;
  }
  if(plik == NULL){
            printf("Blad we wczytywaniu pliku wyjsciowego\n");
            pomoc();
              return -1;
          }
  if(dlugosc==0)
	dlugosc=1000;

	

  generowanie(tekst,ngram,plik,dlugosc);
  fclose(plik);
  fclose(tekst);

  if(strcmp(argv[argc-1],"-stat")==0){
      FILE *plik = fopen(argv[a],"r");
      FILE *tekst = fopen(argv[b],"r");
      statystyka(plik,tekst);
      return 0;
  }

  fclose(plik);
  fclose(tekst); 
  return 0;
}
