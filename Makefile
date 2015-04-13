CC = cc -g -Wall -ansi -pedantic

projekt: main.o generator.o statystyka.o podziel.o
	$(CC) $^
main.o: main.c statystyka.h generator.h podzial.h
generator.o: generator.c podzial.h
statystyka.o: statystyka.c statystyka.h
podziel.o: podziel.c podzial.h

.PHONY: clean
clean:
	rm -fv *.o
	rm -r a.out
