#include <stdio.h>
#include <unistd.h>
#include <sys/io.h>


void writeByte(unsigned char byte, int port){
	//wartet bis der Port zum senden bereit ist und sendet dann
	while((inb(port+5)&0b100000)==0){
		usleep(100);
	}
	outb(byte,port);
	//wartet bis etwas zurückgesendet wird
	while((inb(port+5)&1)==0){
                usleep(100);
	}
	inb(port);
}

char readByte(int port){
	//wartet bis ein Byte ankommt und liest dieses
	while((inb(port+5)&1)==0){
		usleep(100);
	}
	char a = inb(port);
	//wartet bis der Port zum senden bereit ist und sendet dann 
	while((inb(port+5)&0b100000)==0){
		usleep(100);
	}
	outb(1,port);
	return a;
}
