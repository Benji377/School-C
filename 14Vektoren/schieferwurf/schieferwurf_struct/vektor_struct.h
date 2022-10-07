/*
  vektor_array.h Header zum Modul vektor_array.c
  Stellt zur Verfügung:
  -  Vektortyp mit 2 Elementen von double
  -  die Vektorsumme, 
  -  das Produkt zwischen einem Skalar und einem Vektor 
  -  die Vektorzuweisung 
  -  die Initialisierung eines Vektors
  Autor: Der Bortige
  Lizenz: GPLv3
  Datum: 29.11.2019
*/

#ifndef __VEKTOR_STRUCT_H__
#define __VEKTOR_STRUCT_H__


/*
  Definition eines eigenen Typs: "typedef alterTyp NameNeuerTyp[evtlAnzahl]
*/
typedef 
  struct vektor_struct_s {
    double x;
    double y;
  } vektor_struct_t; // Typ fuer Vektoren als Struktur mit 2 Elementen


/*
  Gibt die Vektorsumme aus v1 und v2 zurueck
  v1:  Eingang
  v2:  Eingang
*/
vektor_struct_t vssum(vektor_struct_t v1, vektor_struct_t v2);


/*
  Gibt das Produkt aus dem Skalar k und dem Vektor v zurueck
  k:   Eingang
  v:   Eingang
*/
vektor_struct_t vsprod(double k, vektor_struct_t v);


/*
  Die Zuweisung brauche ich nicht mehr, weil ich in juengeren C-Versionen Strukturen zuweisen kann
*/
/*
void vszuw(vektor_array_t erg, vektor_array_t v);
*/



/*
  Gibt einen Vektor (x,y) zurueck
  erg: Ausgang --> Referenz
  x, y:   Eingang
*/
vektor_struct_t vsinit(double x, double y);

#endif
