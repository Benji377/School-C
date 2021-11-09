fullprog: firstLayer.c secondLayer.c thirdLayer.c
	gcc -o mainprog physikalLayer.c datalinkLayer.c networkLayer.c

physikalLayer: firstLayer.c
	gcc -o physikalLayer firstLayer.c

datalinkLayer: secondLayer.c
	gcc -o datalinkLayer secondLayer.c

networkLayer: thirdLayer.c
	gcc -o networkLayer thirdLayer.c