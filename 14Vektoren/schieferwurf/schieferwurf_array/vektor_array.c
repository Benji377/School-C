/*
  Modul vektor_array.c
  Stellt die Vektorsumme, das Produkt zwischen einem Skalar und einem Vektor und die Vekto
rzuweisung zur Verfuegung
  Autor: Der Bortige
  Lizenz: GPLv3
  Datum: 29.11.2019
*/


#include "vektor_array.h"

void vasum(vektor_array_t erg, vektor_array_t v1, vektor_array_t v2)
{
  erg[0] = v1[0] + v2[0];
  erg[1] = v1[1] + v2[1];
}

void vaprod(vektor_array_t erg, double k, vektor_array_t v)
{
  erg[0] = k * v[0];
  erg[1] = k * v[1];
}

void vazuw(vektor_array_t erg, vektor_array_t v)
{
  erg[0] = v[0];
  erg[1] = v[1];
}

void vainit(vektor_array_t v, double x, double y)
{
  v[0] = x;
  v[1] = y;
}
