// Erster Layer --> Physikallayer
#include <unistd.h>
#include <sys/io.h>

// Schreibt ein Character über ein Port
int writeFunc(unsigned char c, int port) {
    // Wartet ab bis der Port zum Senden bereit ist
    // 0b100000 ist das Signal dass man erhält wenn der Port besetzt ist
    while ((inb(port+5) & 0b100000) == 0) {
        sleep(100);
    }
    // Wenn der Port bereit ist, kann gesendet werden
    outb(c, port);
    // Dann wird wiederum auf der Bestätigung gewartet
    while((inb(port+5) & 1) == 0) {
        sleep(100);
    }
    // Liest die Bestätigung ein
    return inb(port);
}
// Liest ein Character über ein Port ein
char readFunc(int port) {
    // Das Character welches die Antwort speichern wird
    unsigned char read_char;
    // Wartet bis ein Byte ankommt
    while((inb(port+5) & 1) == 0) {
        sleep(100);
    }
    // Liest den Character ein
    read_char = inb(port);

    // Wartet dann wiederum bis der Port frei ist
    while((inb(port+5) & 0b100000) == 0) {
        sleep(100);
    }
    // Wenn frei, sendet es eine Bestätigung dass ein Character erhalten wurde
    outb(1, port);

    return (char) read_char;
}