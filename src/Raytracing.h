#ifndef RAYTRACING_H
#define RAYTRACING_H

#include "Vector.h"

typedef struct {
    Vector3 origen;
    Vector3 direccion;
} Rayo;

Vector3 ray_at(Rayo r, float t);

#endif