#include "openSTL.h"
#include "Raytracing.h"
#include "Esfera.h"
#include <stdio.h>

void generateRayTracingSTL(const char *filename, Esfera sphere, Ray ray, int numRays) {
    FILE *file = fopen(filename, "w");
    
    if (!file) {
        printf("Error opening file.\n");
        return;
    }

    fprintf(file, "solid ray_traced_sphere\n");

    for (int i = 0; i < numRays; ++i) {
        Ray currentRay = ray;
        currentRay.direccion = norm3((Vector3){ray.direccion.x + 0.1f * i, ray.direccion.y, ray.direccion.z});  // Pequeña variación en la dirección del rayo

        float t;
        if (hit(sphere, currentRay, &t)) {
            printf("Ray %d hit the sphere at t = %f\n", i, t);

            Vector3 intersection = rayo(currentRay, t);

            float size = 0.1f;
            float v0[3] = { intersection.x - size, intersection.y - size, intersection.z };
            float v1[3] = { intersection.x + size, intersection.y - size, intersection.z };
            float v2[3] = { intersection.x, intersection.y + size, intersection.z };
            float v3[3] = { intersection.x, intersection.y, intersection.z + size };
            float normal[3] = {0, 0, 1};  

            writeFace(file, normal, v0, v1, v2);
            writeFace(file, normal, v0, v2, v3);
        }
    }

    fprintf(file, "endsolid ray_traced_sphere\n");
    fclose(file);
}

int main() {
    generateSTL("sphere.stl", 1.0, 20, 20);

    Esfera sphere;
    sphere.centro = (Vector3){0, 0, 0};
    sphere.r = 1.0;

    Ray ray;
    ray.origen = (Vector3){0, 0, -5};
    ray.direccion = (Vector3){0, 0, 1};

    generateRayTracingSTL("ray_traced_sphere.stl", sphere, ray, 10);

    return 0;
}