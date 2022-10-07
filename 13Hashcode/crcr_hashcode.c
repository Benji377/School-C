/**
 * Cyclic Redundancy Check (CRC)
 * @author Benjamin Demetz
 */
#include<stdio.h>

/**
 * Führt die arithmetische Bit-division durch
 * Dabei wird das XOR angewendet:
 * 0 + 0 -> 0
 * 0 + 1 -> 1
 * 1 + 0 -> 1
 * 1 + 1 -> 0
 * Uns interessiert im Endeffekt nur den Rest, und nicht das Ergebnis
 */
void division(int temp[],int gen[],int n,int r) {
    // Geht Bit für Bit alle durch und wenn möglich wird es dividiert
    for(int i=0; i<n; i++) {
        // Kontrolliert, ob eine division möglich ist
        if (gen[0]==temp[i]) {
            for(int j=0,k=i; j<r+1; j++,k++)
                if(!(temp[k]^gen[j]))
                    temp[k]=0;
                else
                    temp[k]=1;
        }
    }
}
/**
 * Simuliert den Sender der Nachricht. Es generiert eine Nachricht mit CRC
 */
void sender() {
    int nachricht_bits_anzahl = 0;
    int generator_bits_anzahl = 1;
    // Liest die Länge der verschiedenen Arrays ein
    printf("Sender!\n");
    while (nachricht_bits_anzahl < generator_bits_anzahl){
        printf("Geben Sie die Anzahl an Bits der Nachricht ein: ");
        scanf("%d", &nachricht_bits_anzahl);
        printf("Geben Sie die Anzahl an Bits des Generators an: ");
        scanf("%d", &generator_bits_anzahl);

        if (nachricht_bits_anzahl < generator_bits_anzahl)
            printf("Generator darf nicht größer als die Nachricht sein\n");
    }

    // Legt alle String und int-Arrays fest
    char nachrichten_string[nachricht_bits_anzahl];
    char generator_string[generator_bits_anzahl];
    int nachricht[nachricht_bits_anzahl+generator_bits_anzahl];
    int generator[generator_bits_anzahl];
    int temp[nachricht_bits_anzahl+generator_bits_anzahl];

    // Liest die Nachricht ein und konvertiert sie zu int-Array
    printf("Geben Sie die Nachricht ein: ");
    scanf("%s", &nachrichten_string);
    for(int i=0; i < nachricht_bits_anzahl; i++) {
        if (nachrichten_string[i] == '0')
            nachricht[i] = 0;
        else
            nachricht[i] = 1;
    }

    // Liest den Generator ein und konvertiert ihn zu int-Array
    printf("Geben Sie den Generator ein: ");
    scanf("%s", &generator_string);
    for(int i=0; i < generator_bits_anzahl; i++) {
        if (generator_string[i] == '0')
            generator[i] = 0;
        else
            generator[i] = 1;
    }

    // Der Generator-code dass am Ende der Nachricht anfügt:
    // nachricht + länge des generator - 1
    generator_bits_anzahl--;
    // Hängt Nullen am Ende der Nachricht hinzu, dies vereinfacht die Division
    for(int i=0; i < generator_bits_anzahl; i++)
        nachricht[nachricht_bits_anzahl + i] = 0;

    // Die Nachricht wird im temp kopiert
    for(int i=0; i < nachricht_bits_anzahl + generator_bits_anzahl; i++)
        temp[i] = nachricht[i];

    // Führt die division durch
    division(temp, generator, nachricht_bits_anzahl, generator_bits_anzahl);

    // Gibt den CRC (Rest der Division) zurück
    printf("CRC: ");
    for(int i=0; i < generator_bits_anzahl; i++) {
        printf("%d", temp[nachricht_bits_anzahl + i]);
        // Temp wird in der Nachricht zurückgeschrieben
        nachricht[nachricht_bits_anzahl + i] = temp[nachricht_bits_anzahl + i];
    }

    // Gibt die Nachricht aus, die am Ende gesendet wird
    printf("\nGesendete Nachricht: ");
    for(int i=0; i < nachricht_bits_anzahl + generator_bits_anzahl; i++)
        printf("%d", nachricht[i]);
}
/**
 * Simuliert den Empfänger der Nachricht und kontrolliert dass diese übereinstimmt
 * @return 0 wenn alles stimmt, ansonsten 1 wenn ein Fehler erkannt wurde
 */
int empfaenger() {
    int nachricht_bits_anzahl = 0;
    int generator_bits_anzahl = 1;

    // Liest die größe der Daten ein
    printf("Sender!\n");
    while (nachricht_bits_anzahl < generator_bits_anzahl){
        printf("Geben Sie die Anzahl an Bits der Nachricht ein: ");
        scanf("%d", &nachricht_bits_anzahl);
        printf("Geben Sie die Anzahl an Bits des Generators an: ");
        scanf("%d", &generator_bits_anzahl);

        if (nachricht_bits_anzahl < generator_bits_anzahl)
            printf("Generator darf nicht größer als die Nachricht sein\n");
    }

    // Hier werden alle Strings und int-Arrays angelegt
    char nachrichten_string[nachricht_bits_anzahl+generator_bits_anzahl-1];
    char generator_string[generator_bits_anzahl];
    char crc_string[generator_bits_anzahl-1];
    int nachricht[nachricht_bits_anzahl+generator_bits_anzahl-1];
    int generator[generator_bits_anzahl];
    int crc[generator_bits_anzahl-1];
    int temp[nachricht_bits_anzahl+generator_bits_anzahl-1];

    // Eingabe der Nachricht und konvertierung in int-Array
    printf("Geben Sie die Nachricht ein: ");
    scanf("%s", &nachrichten_string);
    for(int i=0; i < nachricht_bits_anzahl; i++) {
        if (nachrichten_string[i] == '0')
            nachricht[i] = 0;
        else
            nachricht[i] = 1;
    }

    // Eingabe des Generators und konvertierung zu int-Array
    printf("Geben Sie den Generator ein: ");
    scanf("%s", &generator_string);
    for(int i=0; i < generator_bits_anzahl; i++) {
        if (generator_string[i] == '0')
            generator[i] = 0;
        else
            generator[i] = 1;
    }

    // Eingabe des CRC und konvertierung zu int-Array
    printf("Geben Sie den CRC ein: ");
    scanf("%s", &crc_string);
    for(int i=0; i < generator_bits_anzahl-1; i++) {
        if (crc_string[i] == '0')
            crc[i] = 0;
        else
            crc[i] = 1;
    }

    // CRC wird am Ende der Nachricht angehängt
    for (int i = nachricht_bits_anzahl; i < nachricht_bits_anzahl+generator_bits_anzahl-1; i++)
        nachricht[i] = crc[i - nachricht_bits_anzahl];

    // Nachricht wird nach temp kopiert, um es später in der division zu verwenden
    for(int i=0; i < nachricht_bits_anzahl + generator_bits_anzahl-1; i++)
        temp[i] = nachricht[i];
    // Division wird auf dem temporären Array gemacht, um das Originale nicht zu verändern
    division(temp, generator, nachricht_bits_anzahl, generator_bits_anzahl-1);

    // Kontrolliert die übereinstimmung jedes Bit und validiert die Gültigkeit
    // Rest muss 0 sein
    for(int i=0; i < nachricht_bits_anzahl + generator_bits_anzahl; i++) {
        if(temp[i] == 1) {
            printf("Es wurde ein Fehler in der Nachricht gefunden");
            return 1;
        }
    }

    printf("Kein Fehler in der Nachricht gefunden.\n");
    printf("Übergebene Nachricht: ");
    // Gibt die Nachricht ohne CRC zurück
    for(int i=0; i < nachricht_bits_anzahl; i++)
        printf("%d", nachricht[i]);
    return 0;
}

/**
 *
 * @return 0 wenn alles gut geht,
 * 1 wenn der Empfänger einen Fehler meldet
 */
int main(){
    sender();
    printf("\n===========\n");
    return empfaenger();
}