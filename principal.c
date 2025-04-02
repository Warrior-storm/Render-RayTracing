#include <stdio.h>
#include "Esfera.h"
#include "Raytracing.h"
#include "Camara.h"
#include "Escena.h"
#include "Vector.h"

int main() {
    Esfera esfera = {{0, 0, -5}, 1};
    Ray rayo = {{0, 0, 0}, {0, 0, -1}};

    Camara camara = crear_camara((Vector3){0, 0, 0}, (Vector3){0, 0, -1});

    Esfera esferas[] = {esfera};
    Escena escena = crear_escena(esferas, 1);

    float x;
    if (hit(esfera, rayo, &x)) {
        printf("El rayo intersecta con la esfera en x = %f\n", x);
    } else {
        printf("El rayo no intersecta con la esfera\n");
    }

    return 0;
}