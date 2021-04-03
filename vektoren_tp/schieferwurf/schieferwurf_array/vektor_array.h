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

#ifndef __VEKTOR_ARRAY_H__
#define __VEKTOR_ARRAY_H__


/*
  Definition eines eigenen Typs: "typedef alterTyp NameNeuerTyp[evtlAnzahl]
*/
typedef 
  double vektor_array_t[2]; // Typ fuer Vektoren als Feld mit 2 Elementen


/*
  erg ist die Vektorsumme aus v1 und v2
  Felder kann ich in C nicht zurueckgeben --> Ergebnis als Referenzuebergabe
  erg: Ausgang --> Referenz
  v1:  Eingang
  v2:  Eingang
*/
void vasum(vektor_array_t erg, vektor_array_t v1, vektor_array_t v2);


/*
  erg ist das Produkt aus dem Skalar k und dem Vektor v
  erg: Ausgang --> Referenz
  k:   Eingang
  v:   Eingang
*/
void vaprod(vektor_array_t erg, double k, vektor_array_t v);


/*
  erg wird v
  erg: Ausgang --> Referenz
  v:   Eingang
*/
void vazuw(vektor_array_t erg, vektor_array_t v);


/*
  erg v
  erg: Ausgang --> Referenz
  x, y:   Eingang
*/
void vainit(vektor_array_t v, double x, double y);

#endif
