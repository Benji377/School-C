#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/io.h>
#include "allelayer.h"

int main(int argc, char *argv[]){
    // Kontrolliert, dass genau 4 Argumente übergeben wurden
    // 1. Parameter: Ausführte Datei
    // 2. Parameter: -r(read) oder -w(write)
    // 3. Parameter: 1 (Port 1) oder 2 (Port 2)
    // 4. Parameter: Pfad der Datei in der geschrieben oder gelesen wird
    if(argc==4){
        //überprüft, ob alle Argumente correct sind.
        // strcmp ist eine Erweiterung, dass Strings zu C hinzufügt
        if((strcmp(argv[1],"-r")==0||strcmp(argv[1],"-w")==0)&&(strcmp(argv[2],"1")==0||strcmp(argv[2],"2")==0)){
            // UID = 0 bedutet dass der Benutzer die höchste Rechte hat,
            // diese sind für das Ausführen notwendig
            if(getuid()!=0){
                printf("Führen Sie das Programm als ROOT aus\n");
                return -1;
            }
            // Wenn die "Lese"-Option ausgewählt wurde
            if(strcmp(argv[1],"-r")==0){
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
                unsigned char payload[300][256];
                int i=0;
                char counter=0;
                // Liest somit die Datei ein, Character für Character und übergibt diese der Payload
                for(char c = fgetc(f); c != EOF; i++){
                    payload[counter][255]=i;
                    if(i<254){
                        payload[counter][i]=c;
                    }else{
                        i=0;
                        counter++;
                        // Das Maximum wurde erreicht
                        if(counter>=100){
                            printf("In der Datei gibt es zu viele Frames, es wird somit das maximum möglich geschickt");
                            break;
                        }
                        payload[counter][i]=c;
                    }
                    c=fgetc(f);
                }
                // Datei wird geschlossen
                fclose(f);
                counter++;
                // Ruft die writeFrame() Funktion mit dem übergeben Port auf und schreibt den Payload hinein
                for(i=0;i<counter;i++){
                    switch (*(argv[2])-48){
                        case 1:
                            writeFrame(payload[i],payload[i][255],0x03F8);
                            break;
                        case 2:
                            writeFrame(payload[i],payload[i][255],0x02F8);
                            break;
                    }
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
                printf("Lesen erfolgreich abgeschlossen\n");
            }

            // Wenn hingegen geschrieben werden soll
            else{
                FILE *f = fopen(argv[3],"w");
                unsigned char payload[300][256];
                int i=0;

                // Gibt dem Programm Rechte auf dem übergebenen Port
                switch(*(argv[2])-48){
                    case 1:
                        ioperm(0x03F8,8,1);
                        break;
                    case 2:
                        ioperm(0x02F8,8,1);
                        break;
                }

                int abbruch=1;
                int j=0;
                int rueckgabe=0;
                // Nun wird die Payload ausgelesen. Die readFrame() Methode wird so lange aufgerufen, bis es nichts mehr zu lesen
                // gibt oder ein Fehler auftritt

                // (1 ist gleich wie TRUE in C)
                while(abbruch){
                    switch(*(argv[2])-48){
                        case 1:
                            rueckgabe=readFrame(payload[i],&payload[i][255],0x03F8);
                            break;
                        case 2:
                            rueckgabe=readFrame(payload[i],&payload[i][255],0x02F8);
                            break;
                    }
                    // Es muss als Letztes ein -1 übergeben werden, ansonsten ist etwas schiefgegangen
                    if(rueckgabe!=-1){
                        for(j=0;j<(payload[i][255]);j++);
                        if(payload[i][255]<254){
                            abbruch=0;
                        }
                    }else{
                        printf("Beim lesen der Ports ist etwas schiefgegangen\n");
                        return -1;
                    }
                    i++;
                }
                printf("Schreiben erfolgreich abgeschlossen\n");
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
                for(int k=0;k<i;k++){
                    for(int l=0;l<255;l++){
                        // Schreibt das Frame Zeichen für Zeichen
                        if(payload[k][l]>31||payload[k][l]==10){
                            fprintf(f,"%c",payload[k][l]);
                        }
                    }
                }
            }
        }else{
            printf("Die Eingabe soll folgendermaßen Aussehen: ./UART -r/-w 1/2 TXT-Dateiname\n");
        }
    }else{
        printf("Übergeben Sie genau 4 Argumente\n");
    }
}
