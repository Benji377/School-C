schieferwurf: schieferwurf.o vektor_array.o
	gcc -o schieferwurf schieferwurf.o vektor_array.o

vektor_array.o: vektor_array.c
	gcc -c -o vektor_array.o vektor_array.c

schieferwurf.o: schieferwurf.c
	gcc -c -o schieferwurf.o schieferwurf.c
run:
	./schieferwurf > schieferwurf1.csv
	cat schieferwurf1.csv | tr \. \, > schieferwurf2.csv
clean:
	rm -f *.o
cleanall:
	rm -f *.o schieferwurf
