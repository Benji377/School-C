/*
  schieferwurf.c
  Berechnet den schiefen Wurf aus der Hoehe 58m unter der Anfangsgeschwindigkeit v=(1/1)

  *** Version mit Felder/Array ***

  Autor: Der Bortige
  Lizenz: GPLv3
  Datum: 29.11.2019
*/
#include <stdio.h>
#include "vektor_array.h"

int main(void)
{
  vektor_array_t v, s, a; // Geschwindigkeit, Strecke, Beschleunigung
  vektor_array_t vn, // v neu
                 dv, // delta v
                 sn, // s neu
                 ds; // delta s

  double t = 0;
  double dt = 0.1;
  vainit (a, 0, -9.81);
  vainit (v, 1, 1);
  vainit (s, 0, 58);

  printf ("vx\tvy\tsx\tsy\n");
  printf("%lf\t%lf\t%lf\t%lf\n", v[0], v[1], s[0], s[1]);
  while (s[1] > 0) {
    vaprod(dv, dt, a); // delta v
    vasum(vn, v, dv);  // v neu
    vaprod(ds, dt, v); // delta s
    vasum (sn, s, ds); // s neu
    vazuw (v, vn);
    vazuw (s, sn);
    printf("%lf\t%lf\t%lf\t%lf\n", v[0], v[1], s[0], s[1]);
  }
}
