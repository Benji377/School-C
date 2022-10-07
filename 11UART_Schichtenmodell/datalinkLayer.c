#include <stdio.h>
#include "physikalLayer.h"

void writeFrame(unsigned char* frame,unsigned char framelength, int port){
	writeByte(framelength,port);
	char xOr=0;
	//übergibt das Frame einzeln der writeByte() Methode
	for(int i=0;i<framelength;i++){
		writeByte(frame[i],port);
		xOr=xOr^frame[i];
	}
	writeByte(xOr, port);
}

int readFrame(unsigned char* frame,unsigned char* framelength,int port){
	*framelength=readByte(port);
	char xOr=0;
	//liest die einzelnen Frames und schreibt sie in das übergebene Frame
	for(int i=0;i<*framelength;i++){
		frame[i]=readByte(port);
		xOr=xOr^frame[i];
	}
	//wenn die Prüfsumme stimmt gibt es 0 zurück sonst 0
	if(xOr==readByte(port)){
		return 0;
	}else{
		return -1;
	}
}
