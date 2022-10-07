#include <stdio.h>
#include <stdlib.h>

const int g[3][2] ={{0, 1},{2,1},{0,1}}; /* naechster Zustand */
const int f[3][2] ={{0, 0},{0,0},{0,1}}; /* Ausgang */

int main(void)
{
  char e;    /* Eingang */
  int z = 0; /* Zustand */
  
  while (1)
  {
    /* Eingabe */
    if(scanf(" %c",&e) == EOF)
    {
      printf(" \n");
      exit (0);
    }
    if ((e != '0') && (e != '1')) 
    {
      printf(" \n");
      exit (0);
    } 
    /*Ausgabe - Eingang (e-48) ist die Zahl 0 oder 1*/
    printf ("%i", f[z][e-'0']); fflush(stdout);
    /* naechster Zustand - e abfragen und abbilden '0' --> 0 und '1' --> 1 */
    z = g[z][(e=='0'?0:1)];
  }    
  return 0;
}
