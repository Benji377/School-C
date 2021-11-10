#include "physikheader.h"
#include <stdio.h>

// Erstellt einen Frame und gibt es der ersten Schicht über
void writeFrame(unsigned char* f, unsigned char flength, int port) {
    // Zuerst wird durch die Funktion der ersten Schicht die Länge des Frames geschriebenS
    writeFunc(flength, port);
    char final = '0';
    // Das Frame wird nun unterteilt und Stück für Stück der unteren Schicht übergeben
    for (int i = 0; i < flength; i++) {
        writeFunc(f[i], port);
        // Zur Kontrolle des Frames
        final ^= f[i];
    }
    printf("CHECKSUM: %i\n", final);
    writeFunc(final, port);
}

int readFrame(unsigned char* f, unsigned char* flength, int port) {
    // Zuerst wird die Länge des Frames eingelesen
    *flength = readFunc(port);
    char final = '0';
    // Liest alle Teile des Frames ein und gibt sie dem übergebenen Frame über
    for (int j = 0; j < *flength; j++) {
        f[j] = readFunc(port);
        // Wiederum zur Kontrolle des Frame
        final ^= f[j];
    }
    // Wenn die finals übereinstimmen ist der Frame richtig
    if (final == readFunc(port))
        return 0;
    else
        return -1;
}