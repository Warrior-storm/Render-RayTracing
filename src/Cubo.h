
#ifndef CUBO_H
#define CUBO_H

#include "Vector.h"
#include "Raytracing.h"

typedef struct {
    Vector3 min;
    Vector3 max; 
} Cubo;

int hit_cubo(Cubo C, Ray r, float *t, Vector3 *normal);

#endif