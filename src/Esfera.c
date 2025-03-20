#include "Esfera.h"
#include "Raytracing.h"
#include "Vector.h"

int hit(Esfera E, Rayo r, float *x ){
    Vector3  h = rest3(r.origen, E.centro);
    float a = dot3(r.origen,r.direccion);
    float b = 2.0 * dot3(h,r.direccion);
    float c = dot3(h,h) - E.r * E.r; 

    
}