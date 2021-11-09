testprog: physikalLayer.o datalinkLayer.o networkLayer.o
	gcc -o testprog physikalLayer.o datalinkLayer.o networkLayer.o

physikalLayer.o: physikalLayer.c
	gcc -c -o physikalLayer.o physikalLayer.c

datalinkLayer.o: datalinkLayer.c
	gcc -c -o datalinkLayer.o datalinkLayer.c

networkLayer.o: networkLayer.c
	gcc -c -o networkLayer.o networkLayer.c

clean:
	rm -f *.o

cleanall:
	rm -f *.o testprog
