#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

// Globale Variabeln
#define HOST "testclient-benjamin"
#define BUF_LEN 10240
char mail_from[100];
char mail_to[100];  

// Erstellt den Email-Header der wichtige Informationen zur Email beinhaltet
char * Mail_Header(char *from,char *to,char *sub,char *content)
{
    time_t t;
    time(&t); 

    char *header = NULL;
    char date[26];
    char DATE_h[8 + strlen(date)];
    char sender[8 + strlen(from)];   // FROM: sender's_email\r\n
    char recep[6 + strlen(to)];      // TO: recepient's_email\r\n
    char subject[11 + strlen(sub)];
    char content_a[1 + strlen(content) + 2 + 1 + 1];
    strftime(date, (33), "%a %d %b %Y %H:%M:%S",localtime(&t));
    sprintf(DATE_h,"DATE: %s\r\n",date);
    sprintf(sender,"FROM: %s\r\n",from);
    sprintf(recep,"TO: %s\r\n",to);
    sprintf(subject,"Subject: %s\r",sub);
    // extra \n wird benutzt um den Header zu beenden

    sprintf(content_a,"%s\r\n",content);

    int header_length = strlen(DATE_h) + strlen(sender) + strlen(subject) + strlen(recep) + strlen(content_a);

    header = (char *) malloc(header_length * sizeof(char));

    memcpy(&header[0], &DATE_h, strlen(DATE_h));
    memcpy(&header[0 + strlen(DATE_h)], &sender , strlen(sender));
    memcpy(&header[0 + strlen(DATE_h) + strlen(sender)], &subject , strlen(subject));
    memcpy(&header[0 + strlen(DATE_h) + strlen(sender) + strlen(subject)], &recep , strlen(recep));
    memcpy(&header[0 + strlen(DATE_h) + strlen(sender) + strlen(subject) + strlen(recep)], &content_a , strlen(content_a));
    
    return header;
}


int main(int argc, char *argv[]) {
    int socket_id,n;
    int portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char cname[256];
    char buff[BUF_LEN];
    int first_time = 1; // Wird auf 0 gesetzt um die Schleife fortzufahern, siehe unten


    // Beinhaltet den Statuscode des Server
    char code[4];

    if(argc < 3) {
        perror("Starten Sie das Programm mit einer IP und Port.\n");
        exit(0);
    }
    // Port wird übergeben
    portno = atoi(argv[2]);
    // Socket wird erstellt
    socket_id = socket(AF_INET,SOCK_STREAM, 0);

    if(socket_id < 0) {
        perror("Socket konnte nicht geöffnet werden.\n");
        exit(0);
    }
    // IP des Servers wird übergeben
    server = gethostbyname(argv[1]);

    if(server == NULL) {
        perror("Fehler: Server konnte nicht geffunden werden\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr,server->h_length);
    serv_addr.sin_port = htons(portno);
    
    // Verbindung zum Server wird aufgebaut
    int connect_id;
    connect_id = connect(socket_id,(struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if(connect_id < 0) {
        perror("Error occured while connecting to server...\n");
    }
       
    /*
     * Eine unendliche Schleife die das gesamte Programm durchläuft
     * bis nicht QUIT geschrieben wird.
     * Wenn irgendwelche Fehler wärend der Ausführung auftreten, wird
     * die Schleife abgebrochen und es wird versucht QUIT auszuführen.
     */
    for(;;) {

    	// Zuerst wird der Statuscode vom Server gelesen
        // Statuscode wird aber nur beim ersten Schelifendurchlauf gelesen,
        // danach ist das nicht mehr nötig
        if (first_time) {
            n = read(socket_id,buff,10239);
            if(n < 0) {
                printf("Fehler beim lesen. Server könnte fehlerhaft sein\n");
            }
            printf("SERVER : %s",buff);    // Status code wird gelesen
        } else {
            // Es soll kontrolliert werden ob der Benutzer noch eine Email verschicken will
            printf("--------------------------------------\n");
            char confirm[BUF_LEN];
            scanf("%s", confirm);
            if (strcmp(confirm, "NEXT") != 0) {
                break;
            }
        }


        /* ******************************************************************
         * HELO BEFEHL
		 * Grüßt den Server und teilt ihm den Clientname mit
		 * *****************************************************************/
       	// Werte können oben geändert werden
		bzero(buff,BUF_LEN); // Länge des Buffers
        strcpy(buff,"HELO "); // Telnet Befehl
        strcat(buff, HOST); // Wert des Befehls
        strcat(buff,"\r\n"); // Ende der Zeile
        n = write(socket_id,buff,strlen(buff)); // Befehl wird ausgeschrieben
        if(n < 0) {
            printf("Fehler beim schreiben des HELO Befehls\n");
        }
        printf("CLIENT: %s",buff); // Gibt aus was der Client schreibt
        bzero(buff,BUF_LEN);
        n = read(socket_id,buff,10239);
        if(n < 0) {
            printf("Fehler beim lesen des Statuscode nach dem HELO Befehl\n");
            break;
        }
        printf("SERVER : %s",buff); // Gibt aus was der Server antwortet

        // Hier wird der Statuscode aus der Nachricht extrahiert
        code[0] = buff[0];
        code[1] = buff[1];
        code[2] = buff[2];
        code[3] = '\0';

        // Wenn der Statuscode 250 entspricht, wurde kein Fehler begangen
        if(strcmp(code,"250") == 0) {
            printf("Erfolgreich!\n");
            printf("--------------------------------------\n");
        } else {
            printf("Server antwortete mit einem Fehlercode!\n");
            break;
        }
        // Eingabe wird geleert
        fflush(stdin);


        /* ******************************************************************
         * MAIL FROM BEFEHL
		 * Legt fest von wem die Email versendet wird
		 * *****************************************************************/
        bzero(buff,BUF_LEN);
        // Liest Eingabe des Benutzers ein
        printf("Geben Sie die Email des Absenders ein: ");
        fgets(mail_from, BUF_LEN, stdin);
        strcpy(buff,"MAIL FROM:<"); // Befehl
        // Löscht letztes \n von der Eingabezeile
        mail_from[strcspn(mail_from, "\n")] = 0;
        strcat(buff,mail_from); // Inhalt des Befehls
        strcat(buff,">"); // Abschließung des Befehls
        strcat(buff,"\r\n"); // Ende der Zeile
        n = write(socket_id,buff,strlen(buff));
        if(n < 0) {
            printf("Fehler beim schreiben des MAIL FROM Befehl.\n");
            break;
        }
        printf("CLIENT: %s",buff);  //MAIL FROM:<Absender-email>
        bzero(buff,BUF_LEN);
        n = read(socket_id,buff,10239);
        if(n < 0) {
            printf("Fehler beim lesen des Statuscodes nach dem MAIL FROM Befehl\n");
            break;
        }
        printf("SERVER : %s",buff);  //250 OK

        //checking error
        code[0] = buff[0];
        code[1] = buff[1];
        code[2] = buff[2];
        code[3] = '\0';

        if(strcmp(code,"250") == 0) {
            printf("Erfolgreich!\n");
            printf("--------------------------------------\n");
        } else {
            printf("Server antwortete mit einem Fehlercode!\n");
            break;
        }
        fflush(stdin);


        /* ******************************************************************
         * RCPT TO BEFEHL
		 * Legt fest wem die Email verschickt wird
		 * *****************************************************************/
        bzero(buff,BUF_LEN);
        printf("Geben Sie die Email des Empfängers ein: ");
        fgets(mail_to, BUF_LEN, stdin);
        strcpy(buff,"RCPT TO:<");
        mail_to[strcspn(mail_to, "\n")] = 0;
        strcat(buff,mail_to);
        strcat(buff,">");
        strcat(buff,"\r\n");
        n = write(socket_id,buff,strlen(buff));
        if(n < 0) {
            printf("Fehler beim schreiben des MAIL TO Befehl.\n");
            break;
        }
        printf("CLIENT: %s",buff);  //MAIL TO:<Absender-email>
        bzero(buff,BUF_LEN);
        n = read(socket_id,buff,10239);
        if(n < 0) {
            printf("Fehler beim lesen des Statuscodes nach dem MAIL TO Befehl\n");
            break;
        }
        printf("SERVER : %s",buff);  //250 OK

        //checking error
        code[0] = buff[0];
        code[1] = buff[1];
        code[2] = buff[2];
        code[3] = '\0';

        if(strcmp(code,"250") == 0) {
            printf("Erfolgreich!\n");
            printf("--------------------------------------\n");
        } else {
            printf("Server antwortete mit einem Fehlercode!\n");
            break;
        }
        fflush(stdin);


        /* ******************************************************************
         * DATA BEFEHL
		 * Legt Subject und Message der Email fest
		 * *****************************************************************/
        bzero(buff,BUF_LEN);
        strcpy(buff,"DATA");
        strcat(buff,"\r\n");
        n = write(socket_id,buff,strlen(buff));
        if(n < 0) {
            printf("Fehler beim schreiben des DATA Befehl\n");
            break;
        }
        printf("CLIENT: %s",buff);  //DATA
        bzero(buff,BUF_LEN);
        n = read(socket_id,buff,10239);
        if(n < 0) {
            printf("Fehler beim lesen des Statuscodes nach dem DATA Befehl\n");
            break;
        }
        printf("SERVER : %s",buff);  //354 Statuscode; end with <CRLF>.<CRLF>

        code[0] = buff[0];
        code[1] = buff[1];
        code[2] = buff[2];
        code[3] = '\0';

        if(strcmp(code,"354") == 0) {
            printf("Erfolgreich!\n");
            printf("--------------------------------------\n");
        } else {
            printf("Server antwortete mit einem Fehlercode!\n");
            break;
        }

        // Erstellen des Mail-Headers
        char sub[150]; // Subkect der Email
        char content[450]; // Email Inhalt
        printf("Geben Sie das Subject ein: ");
        fgets(sub, 150, stdin);
        
        printf("Geben Sie den Inhalt der Email ein. \n(Benutze die Tabulatortaste + Entertaste um zu bestätigen):\n");
        scanf("%[^\t]",content); // Es wird scanf benutzt, da es nicht beim Kliken der Entertaste die Email verschickt
        // [^\t] sagt scanf dass er nach einem Tabulator, wenn Enter geklickt wird, abschicken soll

        bzero(buff,BUF_LEN);
        //Mail_header Funktion ist oben deklariert
        strcpy(buff, Mail_Header(mail_from,mail_to,sub,content)); // Dem Header werden Daten übergeben
        
        // Zuerst wird der Email-Header verschickt
        n = write(socket_id,buff,strlen(buff));                     
        if(n < 0) {
            printf("Fehler beim schreieben des Email-Header\n");
            break;
        }
        printf("--------------------------------------\n");
        printf("CLIENT: ====| E-Mail header & inhalt |====\n%s\n",buff);  //header content
        
        bzero(buff,BUF_LEN);
        strcpy(buff,".\r\n");

        // Schreibt den Inhalt der Email zum Socket
        n = write(socket_id,buff,strlen(buff));                    
        if(n < 0)
        {
            printf("Fehler beim schreiben des Inhalt der Email\n");
            break;
        }
        
        bzero(buff,BUF_LEN);
        n = read(socket_id,buff,10239);  
        if(n < 0)
        {
            printf("Fehler beim lesen des Statuscodes\n");
            break;
        } 
        printf("SERVER : %s",buff);     //250 OK

        //checking error
        code[0] = buff[0];
        code[1] = buff[1];
        code[2] = buff[2];
        code[3] = '\0';

        if(strcmp(code,"250") == 0)
        {	
            printf("Erfolgreich!\n");
            printf("--------------------------------------\n");
        }
        else{
            printf("Server antwortete mit einem Fehlercode!\n");
            break;
        }
        fflush(stdin);


        // Neue Email kann verschickt werden!
        printf("Neue Email kann verschickt werden!\n");
        first_time = 0;
        printf("Schreibe 'QUIT' um zu beenden oder 'NEXT' um fortzufahren.\n");
        
    }


    /* ******************************************************************
     * QUIT BEFEHL
	 * Beendet die Verbindung zum SMTP Server
	 * *****************************************************************/
    bzero(buff,BUF_LEN);
    strcpy(buff,"QUIT");
    strcat(buff,"\r\n");
    n = write(socket_id,buff,strlen(buff));
    if(n < 0)
    {
        printf("Fehler beim schreiben des QUIT Befehls\n");
    }
    printf("CLIENT: %s",buff);  //QUIT
    bzero(buff,10240);
    n = read(socket_id,buff,10239);
    if(n < 0)
    {
        printf("Konnte nicht vom Socket lesen\n");
    }
    printf("SERVER : %s\n",buff);    //221 Bye

    code[0] = buff[0];
    code[1] = buff[1];
    code[2] = buff[2];
    code[3] = '\0';

    if(strcmp(code,"221") == 0)
    {
        printf("Verbindung erfolgreich abgeschlossen\n");
    }
    else{
        printf("Fehler ist aufgetreten!\n");
    }
    fflush(stdin);
}