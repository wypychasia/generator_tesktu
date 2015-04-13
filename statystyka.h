#ifndef _STATYSTYKA_H_
#define _STATYSTYKA_H_

int dl_txt(FILE *tekst);
float czestotliwosc(FILE *plik);
char* ngram(FILE *tekst);
void statystyka(FILE *plik, FILE *tekst);

#endif
