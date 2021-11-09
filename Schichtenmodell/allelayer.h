#pragma once

// Physikallayer:
int writeFunc(unsigned char c, int port);
char readFunc(int port);

// Datalinklayer
void writeFrame(unsigned char* frame,unsigned char framelength, int port);
int readFrame(unsigned char* frame,unsigned char* framelength,int port);