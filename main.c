#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "statystyka.h"
#include "generator.h"

void pomoc(){
printf("Poczatkowo prosze o wpisanie flagi '-txt' z nazwa pliku, z ktorego będzie tworzony tekst wyjsciowy. Następnie z flagą '-ngram' wybrac zadana dlugosc ngramu oraz z flagą '-dl_txt' wpisac dlugosc tekstu wejsciowego. By otrzymać informacje o statystyce należy wpisać flagę '-stat'.\n");
}

int main(int argc, char  **argv)
{
  int dlugosc_tekstu = 0;
  int ngram = 0;
  int i;

  FILE *in = (strcmp(argv[1],"-txt")==0) ? fopen(argv[1],"r") : "Prosze podac plik wejsciowy";
  if (strcmp(argv[1], "-pomoc") == 0){
    pomoc();
    return 0;
  }
  for(i=1; i<=argc; i++){
    if(strcmp(argv[i],"-dl_txt")==0)
	dlugosc_tekstu = atoi(argv[i+1]);
    if(strcmp(argv[i],"-ngram")==0)
	ngram=atoi(argv[i+1]);	
    if(strcmp(argv[i],"-stat")==0)
	statystyka();
    else
	pomoc();
  }	
  
  if(ngram==0)
	ngram=2;
  if(dlugosc_tekstu ==0)
	printf("Prosze podac dlugosc tekstu\n");
  return 0;
}
