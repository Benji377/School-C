/*
 * Shell erstellt von Benjamin Demetz
 * Weitere Dateien im gleichen Ordner:
 * - Laborbericht: shell_laborbericht.docx
 * - Handbuch: shell_handbuch.docx
 * - Testbericht: shell_testbericht.docx
 */


#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Hier werden die Funktionen für die Shellbefehle deklariert
int shell_cd(char **args);
int shell_help();
int shell_exit();

// Diese String beinhaltet alle Funktionen die ohne externe Befehle funktionieren
// Die Funktionen dazu wurden bereits oben deklariert
char *eingebaut_str[] = {"cd", "help", "exit"};

// Beinhaltet alle bereits in der Shell existierenden Funktionen
int (*eingebaut_func[]) (char **) = {&shell_cd, &shell_help, &shell_exit};

// Funktion um die Anzahl der eingebauten Befehle zurückzugeben
int shell_anzahl_eingebaut() {
    return sizeof(eingebaut_str) / sizeof(char *);
}

/**
   Ist einer der in der Shell eingebaute Befehl. Es wird benutzt um in der Shell
   Pfad zu wechseln.
   @param args List der Argumente  args[0] ist "cd".  args[1] ist das Verzeichnis.
   @return gibt immer 1 zurück um weiter auszuführen
 */
int shell_cd(char **args) {
    // Wenn kein Argument gegeben wurde, wird ein Fehler ausgegeben
    if (args[1] == NULL) {
        fprintf(stderr, "Shell: \"cd\" braucht ein Argument\n");
    } else {
        // Wenn es nicht möglich war, Verzeichnis zu wechseln wird auch ein Fehler zurückzugeben
        if (chdir(args[1]) != 0) {
            perror("Shell konnte nicht das Verzeichnis wechseln");
        }
    }
    // Gibt immer 1 zurück damit die Shell nicht unterbrochen wird
    return 1;
}

/**
   Ist einer der in der Shell eingebaute Befehle und soll den Benutzer beim Benutzen der Shell aushelfen
   @return Gibt immer 1 zurück damit die Shell weiter ausführen kann
 */
int shell_help() {
    printf("Um Befehle auszuführen, geben sie einfach die Programmnamen ein.\n"
           "Vergessen sie dabei nicht die Argumente jedes Befehls wenn notwendig\n"
           "Wenn Sie mehr dazu wissen möchten können sie das Handbuch verwenden dass sich im gleichen Ordner befindet\n"
           "Diese hier sind die in der Shell eingebauten Befehle:\n");

    for (int i = 0; i < shell_anzahl_eingebaut(); i++) {
        printf("- %s\n", eingebaut_str[i]);
    }

    printf("Für Informationen über andere Befehle oder Programme benutzen Sie den \"man\" Befehl\n");
    return 1;
}

/**
   Ein in der Shell eingebaute Befehl um das Programm abzubrechen.
   Solange eine Methode 1 zurückgibt wird die Shell weiterhin ausgeführt, wenn 0 zurückgegeben wird,
   wird die Shell fehlerfrei abgebrochen
   @return Gibt immer 0 zurück um das Programm fehlerfrei abzubrechen
 */
int shell_exit() {
    return 0;
}

/**
  Erstellt für jeden Befehl ein neuen Prozess damit die Shell während der Ausführung
  des Befehls nicht unterbrochen werden muss
  @param args Sind die Argumente für jeden Befehl
  @return Gibt immer 1 zurück damit die Shell nicht unterbrochen werden muss
 */
int shell_prozess(char **args) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {
        // Bei Fehler mit dem Kindprozess
        if (execvp(args[0], args) == -1) {
            perror("Fehler mit Kindprozess");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        // Fehler mit Fork
        perror("Fehler mit Fork");
    } else {
        // Führt Elternprozess aus solange keine Fehler auftreten
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    return 1;
}

/**
   Führt die verschiedene Befehle die der Shell übergeben werden aus. Diese Methode gibt auch an,
   ob die Shell weiterhin ausgeführt werden, oder ob die Shell abgebrochen werden soll
   @param args Befehle die ausgeführt werden sollen
   @return 1 wenn die Shell weiterhin ausgeführt werden soll, sonst 0 um abzubrechen
 */
int shell_execute(char **args) {

    // Wenn nichts eingegeben wurde soll die Shell einfach weiter ausgeführt werden
    if (args[0] == NULL) {
        return 1;
    }
    // Hier werden die eingebaute Programme ausgeführt
    for (int i = 0; i < shell_anzahl_eingebaut(); i++) {
        if (strcmp(args[0], eingebaut_str[i]) == 0) {
            return (*eingebaut_func[i])(args);
        }
    }
    // Ansonsten wird das eingegebene Befehl ausgeführt
    return shell_prozess(args);
}

/**
   Sehr wichtige Methode die die vom Benutzer eingegebenen Befehle liest und zurückgibt
   @return Die von stdin gelesene Zeile
 */
char *shell_zeilenleser(void) {
    int bufsize = 1024;
    int position = 0;
    char *buffer = malloc(sizeof(char) * bufsize);
    int c;

    // Bei Fehlern mit dem Buffer
    if (!buffer) {
        fprintf(stderr, "Shell: Buffer falsch angelegt\n");
        exit(EXIT_FAILURE);
    }
    // Praktisch unendliche Schleife die jedes Character in einer Zeile liest
    while (1) {
        // Liest nur ein Character
        c = getchar();

        // EOF = End of line --> Die Zeile ist zu Ende
        if (c == EOF) {
            exit(EXIT_SUCCESS);
        // Bei neuer Zeile soll ein null an der Stelle im Buffer gesetzt werden
        } else if (c == '\n') {
            buffer[position] = '\0';
            return buffer;
        // Wenn ein Zeichen gefunden wurde, wird das Zeichne im Buffer gesetzt
        } else {
            buffer[position] = c;
        }
        // Geht somit den gesamten Buffer durch
        position++;

        // Buffer hat nur platz für 1024 Zeichen, sollte reichen, aber wenn nicht dann wird es verdoppelt
        if (position >= bufsize) {
            bufsize += 1024;
            // Buffer wird neu angelegt
            buffer = realloc(buffer, bufsize);
            // Wenn der Buffer falsch angelegt wurde, wird ein Fehler ausgegeben
            if (!buffer) {
                fprintf(stderr, "Shell: Buffer falsch angelegt\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}

/**
   Methode um die übergebenenen Zeile in "Tokens" einzuteilen. Das wird gebraucht um
   die Eingabe des Benutzers in Befehle und Argumente der Befehle
   @param line Die Zeile die eingeteilt werden soll
   @return Ein Array mit alle Tokens, also Befehl und Argumente
 */
char **shell_zeilenspalter(char *line)
{
    int bufsize = 64, position = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token, **tokens_backup;

    // Wenn der Buffer falsch angelegt wurde, wird ein Fehler gemeldet
    if (!tokens) {
        fprintf(stderr, "Shell: Buffer falsch angelegt\n");
        exit(EXIT_FAILURE);
    }

    // Liest die Zeile bis ein Delnim-Zeichen gefunden wird
    // Delnim-Zeichen: " \t\r\n\a"
    token = strtok(line, " \t\r\n\a");
    while (token != NULL) {
        tokens[position] = token;
        position++;

        // Wenn der Buffer nicht ausreicht, wird es verdoppelt und neu angelegt
        if (position >= bufsize) {
            bufsize += 64;
            // Speichert den Token
            tokens_backup = tokens;
            // Buffer neu angelegt
            tokens = realloc(tokens, bufsize * sizeof(char*));
            // Wenn beim neu angelegten Buffer ein Fehler auftritt
            if (!tokens) {
                // Die bis jetzt gespeicherte Tokens werden gelöscht
                free(tokens_backup);
                // Fehlermeldung
                fprintf(stderr, "Shell: Buffer falsch angelegt\n");
                exit(EXIT_FAILURE);
            }
        }
        // Ein Token wird von Zeilenanfang bis zu einem der folgenden Zeichen:
        // " \t\r\n\a"
        token = strtok(NULL, " \t\r\n\a");
    }
    // Nachdem ein Token gelesen wurde, wird dort NULL eingetragen, damit der nächste gelesen werden kann
    tokens[position] = NULL;
    return tokens;
}

/**
   Steuert das gesamte Programm. Benutzt die verschiedenen oben deklarierten Methoden
   um die Shell zu starten, Befehle auszuführen und die Shell zu beenden
   @return status. 1 Bei Fehler, 0 wenn alles gut gegangen ist
 */
int main() {
    char *line;
    char **args;
    int status;

    do {
        // Wird am Anfang jeder Zeile geschrieben
        printf("Shell> ");
        // Deklariert die Variabeln jedes mal neu
        line = shell_zeilenleser();
        args = shell_zeilenspalter(line);
        status = shell_execute(args);

        // Nachdem die Shell den Befehl ausführt wird die Befehlszeile auf null gestellt
        // Ansonsten würden Befehle mehrmals ausgeführt
        free(line);
        free(args);
    } while (status);
    return EXIT_SUCCESS;
}