#include <stdio.h>
#include "vektoren.h"


struct vektoren vektsum(struct vektoren punkt_p, struct vektoren punkt_q) {
    struct vektoren summe;
    summe.x = punkt_p.x + punkt_q.x;
    summe.y = punkt_p.y + punkt_q.y;
    return summe;
}

struct vektoren vektprod(struct vektoren punkt_p, float zahl) {
    struct vektoren produkt;
    produkt.x = punkt_p.x * zahl;
    produkt.y = punkt_p.y * zahl;
    return produkt;
}