schieferwurf: schieferwurf.o vektor_struct.o
	gcc -o schieferwurf schieferwurf.o vektor_struct.o

vektor_array.o: vektor_struct.c
	gcc -c -o vektor_struct.o vektor_struct.c

schieferwurf.o: schieferwurf.c
	gcc -c -o schieferwurf.o schieferwurf.c
run:
	./schieferwurf > schieferwurf1.csv
	cat schieferwurf1.csv | tr \. \, > schieferwurf2.csv
clean:
	rm -f *.o
cleanall:
	rm -f *.o schieferwurf
