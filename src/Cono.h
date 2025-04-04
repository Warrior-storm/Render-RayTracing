
#ifndef CONO_H
#define CONO_H
#include "Vector.h"
#include "Raytracing.h"

typedef struct {
    Vector3 base;  
    Vector3 axis; 
    float radius;  
    float height;  
} Cono;

int hit_cono(Cono cono, Ray r, float *t, Vector3 *normal);
Vector3 norm3(Vector3 v);
Vector3 rest3(Vector3 a, Vector3 b);
float dot3(Vector3 a, Vector3 b);
Vector3 Esc3(Vector3 v, float escalar);

#endif 