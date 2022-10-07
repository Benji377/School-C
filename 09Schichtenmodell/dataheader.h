#ifndef DATAHEADER_H
#define DATAHEADER_H

void writeFrame(unsigned char* f, unsigned char flength, int port);
int readFrame(unsigned char* f, unsigned char* flength, int port);

#endif
