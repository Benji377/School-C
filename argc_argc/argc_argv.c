/*
argc_argv.c 
Es wird die Verwendung der Schnittstelle der aufrufenden Umgebung (Befehlszeile) zum Programm gezeigt

Autor: Der Bortige
Lizenz: GPLv3
Datum: 31.01.2021
*/
#include <stdio.h>

/*
argc: Anzahl der Elemente auf der Befehlszeile, der Programmaufruf wird mitgezählt, also ist argc um 1 höher als die Anzahl der Argumente
argv: Feld von Zeigern auf char. Die Zeiger zeigen auf die einzelnen übergebenen Elemente auf der Befehlszeile. argv[0] ist der Programmaufruf, mit argv[1] beginnen die Argumente. Nach dem letzen Argument filgt dann ein NULL
*/
int main(int argc, char *argv[]) {
  int i = 0;
  printf("argc=%i\n", argc);
  for(i = 0; argv[i]; i++) {
    printf("argv[%i]=%s - %p\n", i, argv[i], argv[i]);
  }  
  printf("argv[%i]=%s - %p\n", i, argv[i], argv[i]);
  return 0;
}

