#ifndef __VEKTOREN_H__
#define __VEKTOREN_H__

struct vektoren {
    float x;
    float y;
};

struct vektoren vektsum(struct vektoren punkt_p, struct vektoren punkt_q);

struct vektoren vektprod(struct vektoren punkt_p, float zahl);




#endif