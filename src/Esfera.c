#include "Esfera.h"
#include "Raytracing.h"
#include "Vector.h"
#include <math.h>

int hit(Esfera E, Rayo r, float *x ){
    Vector3  h = rest3(r.origen, E.centro);
    float a = dot3(r.origen,r.direccion);
    float b = 2.0 * dot3(h,r.direccion);
    float c = dot3(h,h) - E.r * E.r; 
    float discriminante = b*b  - 4 * a * c;

    if (discriminante > 0){
        *x = (-b - sqrt(discriminante))/(2.0*a);

        return(*x > 0);
    }

    return 0;

}