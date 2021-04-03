/*
  schieferwurf.c
  Berechnet den schiefen Wurf aus der Hoehe 58m unter der Anfangsgeschwindigkeit v=(1/1)

  *** Version mit Strukturen/struct ***

  Autor: Der Bortige
  Lizenz: GPLv3
  Datum: 29.11.2019
*/
#include <stdio.h>
#include "vektor_struct.h"

int main(void)
{
  vektor_struct_t v, s, a; // Geschwindigkeit, Strecke, Beschleunigung
  vektor_struct_t vn, // v neu
                  sn; // s neu

  double t = 0;
  double dt = 0.1;
  a = vsinit (0, -9.81);
  v = vsinit (1, 1);
  s = vsinit (0, 58);

  printf ("vx\tvy\tsx\tsy\n");
  printf("%lf\t%lf\t%lf\t%lf\n", v.x, v.y, s.x, s.y);
  while (s.y > 0) {
    vn = vssum(v, vsprod(dt, a));  // v neu = v + delta v
    sn = vssum (s, vsprod(dt, v)); // s neu = s + delta s
    v = vn;
    s = sn;
    printf("%lf\t%lf\t%lf\t%lf\n", v.x, v.y, s.x, s.y);
  }
}
