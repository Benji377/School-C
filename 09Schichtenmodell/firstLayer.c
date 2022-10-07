// Erster Layer --> Physikallayer
#include <sys/io.h>

// Schreibt ein Character über ein Port
int writeFunc(unsigned char c, int port) {
    // Wartet ab bis der Port zum Senden bereit ist
    // 0b100000 ist das Signal dass man erhält wenn der Port besetzt ist
    while ((inb(port+5) & 0b1000000) == 0) {
        //sleep(100);
    }
    // Wenn der Port bereit ist, kann gesendet werden
    outb(c, port);
    // Liest die Bestätigung ein
    return inb(port);
}
// Liest ein Character über ein Port ein
char readFunc(int port) {
    // Das Character welches die Antwort speichern wird
    unsigned char read_char;
    // Liest den Character ein
    read_char = inb(port);
    return (char) read_char;
}