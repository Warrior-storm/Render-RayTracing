#ifndef RAYTRACING_H
#define RAYTRACING_H

#include "Vector.h"

typedef struct {
    Vector3 origen;
    Vector3 direccion;
} Ray;

typedef struct {
    Vector3 posicion;
    Vector3 color;
} Luz;

Vector3 rayo(Ray r, float t);

#endif