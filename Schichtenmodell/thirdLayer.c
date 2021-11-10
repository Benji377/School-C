#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/io.h>
#include "dataheader.h"

int main(int argc, char *argv[]){
    // Kontrolliert, dass genau 4 Argumente übergeben wurden
    // 1. Parameter: Ausführte Datei
    // 2. Parameter: -r(read) oder -w(write)
    // 3. Parameter: 1 (Port 1) oder 2 (Port 2)
    // 4. Parameter: Pfad der Datei in der geschrieben oder gelesen wird
    if(argc==4){
        //überprüft, ob alle Argumente correct sind.
        // strcmp ist eine Erweiterung, dass Strings zu C hinzufügt
        if((strcmp(argv[1],"-s")==0||strcmp(argv[1],"-r")==0)&&(strcmp(argv[2],"1")==0||strcmp(argv[2],"2")==0)){
            // UID = 0 bedutet dass der Benutzer die höchste Rechte hat,
            // diese sind für das Ausführen notwendig
            if(getuid()!=0){
                printf("Führen Sie das Programm als ROOT aus\n");
                return -1;
            }
            // Wenn die "Lese"-Option ausgewählt wurde
            if(strcmp(argv[1],"-s")==0){
                // Es wird versucht die Datei zu öffnen
                FILE *f = fopen(argv[3],"r");
                if(f==NULL){
                    printf("Übergeben Datei konnte nicht geöffnet werden\n");
                    // Programm wird beendet
                    return -1;
                }
                // Wählt den Port aus, aus dem gelesen werden soll und gibt dem Programm die Rechte dazu
                switch(*(argv[2])-48){
                    case 1:
                        ioperm(0x03F8,8,1);
                        break;
                    case 2:
                        ioperm(0x02F8,8,1);
                        break;
                }
                // Stellt das Maximum fest, dass gelesen werden kann
                unsigned char payload[256];
                int c;
                int counter = 0;
                // Liest somit die Datei ein, Character für Character und übergibt diese der Payload
                while(counter < 255 && (c = fgetc(f))!= EOF) {
                    payload[counter++] = (unsigned char)c;
                }
                payload[counter-1] = '\0';
                fclose(f);
                printf("Ausgabe: %s\n", payload);
                printf("Counter: %i\n", counter);
                // Ruft die writeFrame() Funktion mit dem übergeben Port auf und schreibt den Payload hinein
                if ((*(argv[2])-48) == 1) {
                    writeFrame(payload, counter, 0x03F8);
                } else if ((*(argv[2])-48) == 2) {
                    writeFrame(payload, counter, 0x02F8);
                } else {
                    printf("THIRD: %i\n", (*(argv[2])-48));
                }
                // Nimmt dem Programm Zugriff auf den Ports
                switch(*(argv[2])-48){
                    case 1:
                        ioperm(0x03F8,8,0);
                        break;
                    case 2:
                        ioperm(0x02F8,8,0);
                        break;
                }
                printf("Senden erfolgreich abgeschlossen\n");
            }

            // Wenn hingegen geschrieben werden soll
            else{
                FILE *f = fopen(argv[3],"w");
                unsigned char payload[256];

                // Gibt dem Programm Rechte auf dem übergebenen Port
                switch(*(argv[2])-48){
                    case 1:
                        ioperm(0x03F8,8,1);
                        break;
                    case 2:
                        ioperm(0x02F8,8,1);
                        break;
                }
                int rueckgabe = 0;

                switch(*(argv[2])-48){
                    case 1:
                        rueckgabe=readFrame(payload, (unsigned char *)&payload, 0x03F8);
                        break;
                    case 2:
                        rueckgabe=readFrame(payload, (unsigned char *)&payload, 0x02F8);
                        break;
                }
                if (rueckgabe == 0)
                    printf("Daten erfolgreich angekommen\n");
                else
                    printf("Failed\n");
                // Aus Sicherheitsgründen muss man dem Programm den Zugriff auf die Ports wegnehmen
                switch(*(argv[2])-48){
                    case 1:
                        ioperm(0x03F8,8,0);
                        break;
                    case 2:
                        ioperm(0x02F8,8,0);
                        break;
                }
                // Nach dem erfolgreiche lesen werden die Frames in eine Textdatei gespeichert
                printf("Payload: %s\n", payload);
                fprintf(f, "%s", payload);
                fclose(f);
                printf("Datei geschrieben\n");
            }
        }else{
            printf("Die Eingabe soll folgendermaßen Aussehen: ./UART -r/-w 1/2 TXT-Dateiname\n");
        }
    }else{
        printf("Übergeben Sie genau 4 Argumente\n");
    }
}
