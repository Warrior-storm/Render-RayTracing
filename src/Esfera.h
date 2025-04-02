#ifndef ESFERA_H
#define ESFERA_H

#include "Vector.h"
#include "Raytracing.h"

typedef struct 
{
    Vector3 centro;
    float r;
}Esfera;

int hit(Esfera E, Ray r, float *);

#endif