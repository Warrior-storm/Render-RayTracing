#include "Esfera.h"
#include "Raytracing.h"
#include "Vector.h"
#include <math.h>


int hit(Esfera E, Ray r, float *x, Vector3 *normal) {
    Vector3 h = rest3(r.origen, E.centro);
    float a = dot3(r.direccion, r.direccion);
    float b = 2.0 * dot3(h, r.direccion);
    float c = dot3(h, h) - E.r * E.r;
    float discriminante = b * b - 4 * a * c;

    if (discriminante > 0) {
        *x = (-b - sqrt(discriminante)) / (2.0 * a);
        if (*x > 0) {
            Vector3 hit_point = rayo(r, *x);
            *normal = norm3(rest3(hit_point, E.centro));
            return 1;
        }
    }

    return 0;
}