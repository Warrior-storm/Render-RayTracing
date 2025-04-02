
#ifndef Cilindro_H
#define Cilindro_H

#include "Vector.h"
#include "Raytracing.h"

typedef struct {
    Vector3 base;
    Vector3 axis;
    float radius;
    float height;
} Cilindro;

int hit_Cilindro(Cilindro C, Ray r, float *t, Vector3 *normal);

#endif