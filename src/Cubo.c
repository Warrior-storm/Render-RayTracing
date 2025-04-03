#include "Cubo.h"
#include "Vector.h"
#include <math.h>

int hit_cubo(Cubo C, Ray r, float *t, Vector3 *normal) {
    float tmin = (C.min.x - r.origen.x) / r.direccion.x;
    float tmax = (C.max.x - r.origen.x) / r.direccion.x;

    if (tmin > tmax) {
        float temp = tmin;
        tmin = tmax;
        tmax = temp;
    }

    float tymin = (C.min.y - r.origen.y) / r.direccion.y;
    float tymax = (C.max.y - r.origen.y) / r.direccion.y;

    if (tymin > tymax) {
        float temp = tymin;
        tymin = tymax;
        tymax = temp;
    }

    if ((tmin > tymax) || (tymin > tmax)) {
        return 0;
    }

    if (tymin > tmin) {
        tmin = tymin;
    }

    if (tymax < tmax) {
        tmax = tymax;
    }

    float tzmin = (C.min.z - r.origen.z) / r.direccion.z;
    float tzmax = (C.max.z - r.origen.z) / r.direccion.z;

    if (tzmin > tzmax) {
        float temp = tzmin;
        tzmin = tzmax;
        tzmax = temp;
    }

    if ((tmin > tzmax) || (tzmin > tmax)) {
        return 0;
    }

    if (tzmin > tmin) {
        tmin = tzmin;
    }

    if (tzmax < tmax) {
        tmax = tzmax;
    }

    *t = tmin;
    if (*t < 0) {
        *t = tmax;
        if (*t < 0) {
            return 0;
        }
    }

    // Calcular la normal
    Vector3 hit_point = rayo(r, *t);
    if (fabs(hit_point.x - C.min.x) < 0.001) {
        *normal = (Vector3){-1, 0, 0};
    } else if (fabs(hit_point.x - C.max.x) < 0.001) {
        *normal = (Vector3){1, 0, 0};
    } else if (fabs(hit_point.y - C.min.y) < 0.001) {
        *normal = (Vector3){0, -1, 0};
    } else if (fabs(hit_point.y - C.max.y) < 0.001) {
        *normal = (Vector3){0, 1, 0};
    } else if (fabs(hit_point.z - C.min.z) < 0.001) {
        *normal = (Vector3){0, 0, -1};
    } else if (fabs(hit_point.z - C.max.z) < 0.001) {
        *normal = (Vector3){0, 0, 1};
    }

    return 1;
}