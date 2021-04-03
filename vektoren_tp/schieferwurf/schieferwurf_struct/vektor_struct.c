/*
  Modul vektor_struct.c
  Stellt die Vektorsumme, das Produkt zwischen einem Skalar und einem Vektor und die Vekto
rzuweisung zur Verfuegung
  Autor: Der Bortige
  Lizenz: GPLv3
  Datum: 29.11.2019
*/


#include "vektor_struct.h"

vektor_struct_t vssum(vektor_struct_t v1, vektor_struct_t v2)
{
  vektor_struct_t hilfsvektor;
  hilfsvektor.x = v1.x + v2.x;  
  hilfsvektor.y = v1.y + v2.y;
  return (hilfsvektor);
}

vektor_struct_t vsprod(double k, vektor_struct_t v)
{
  vektor_struct_t hilfsvektor;
  hilfsvektor.x = k * v.x; 
  hilfsvektor.y = k * v.y;
  return (hilfsvektor);
}

/* Braucht es zwischen Strukturen nicht
void vszuw(vektor_array_t erg, vektor_array_t v)
{
  erg[0] = v[0];
  erg[1] = v[1];
}
*/
vektor_struct_t vsinit(double x, double y)
{
  vektor_struct_t hilfsvektor;
  hilfsvektor.x = x; 
  hilfsvektor.y = y;
  return (hilfsvektor);
}
