#ifndef RAYTRACING_H
#define RAYTRACING_H

#include "Vector.h"

typedef struct {
    Vector3 origen;
    Vector3 direccion;
} Ray;

Vector3 rayo(Ray r, float t);

#endif