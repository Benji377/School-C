#include <stdio.h>
#include "sum.h"
#include "diff.h"
#include "prod.h"
#include "divis.h"

int main(void)
{
  float a, b; // Definition zweier Variabler, vom Typ float
  a = 1;
  b = 2; 
  printf("Bitte erstes Argument eingeben:");
  scanf("%f", &a);  // wir uebergeben dem scanf die Adresse auf a
  printf("Bitte zweites Argument eingeben:");
  scanf("%f", &b);  
  printf("%f + %f = %f\n", a, b, /* a + b */ sum(a,b));
  printf("%f - %f = %f\n", a, b, diff(a, b));
  printf("%f * %f = %f\n", a, b, prod(a, b));
  printf("%f / %f = %f\n", a, b, divis(a, b));
  return (0);
}
