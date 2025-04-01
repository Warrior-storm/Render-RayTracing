#include "openSTL.h"
#include "openSTL.h"
#include "Raytracing.h"
#include "Esfera.h"
#include <stdio.h>

int main() {
    generateSTL("sphere.stl", 1.0, 20, 20);

    Esfera sphere;
    sphere.centro = (Vector3){0, 0, 0};
    sphere.r = 1.0;

    Rayo ray;
    ray.origen = (Vector3){0, 0, -5};
    ray.direccion = (Vector3){0, 0, 1};

    float t;
    if (hit(sphere, ray, &t)) {
        printf("The ray hit the sphere at t = %f\n", t);
    } else {
        printf("The ray did not hit the sphere\n");
    }

    return 0;
}