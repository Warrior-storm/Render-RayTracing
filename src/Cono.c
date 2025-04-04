#include "Cono.h"
#include "Vector.h"
#include <math.h>

int hit_cono(Cono cono, Ray r, float *t, Vector3 *normal) {
    Vector3 CO = rest3(r.origen, cono.base);
    float k = cono.radius / cono.height;
    k = k * k;

    float a = dot3(r.direccion, r.direccion) - (1 + k) * pow(dot3(r.direccion, cono.axis), 2);
    float b = 2 * (dot3(r.direccion, CO) - (1 + k) * dot3(r.direccion, cono.axis) * dot3(CO, cono.axis));
    float c = dot3(CO, CO) - (1 + k) * pow(dot3(CO, cono.axis), 2);

    float discriminant = b * b - 4 * a * c;
    if (discriminant < 0) return 0;

    float t0 = (-b - sqrt(discriminant)) / (2 * a);
    float t1 = (-b + sqrt(discriminant)) / (2 * a);

    if (t0 > t1) {
        float temp = t0;
        t0 = t1;
        t1 = temp;
    }

    if (t0 < 0) {
        t0 = t1;
        if (t0 < 0) return 0;
    }

    *t = t0;
    Vector3 hit_point = rayo(r, *t);
    Vector3 v = rest3(hit_point, cono.base);
    float m = dot3(cono.axis, v);

    if (m < 0 || m > cono.height) return 0;

    Vector3 temp = Esc3(cono.axis, m);
    *normal = norm3(rest3(v, temp));
    return 1;
}

