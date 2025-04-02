#ifndef CAMARA_H
#define CAMARA_H

#include "Vector.h"

typedef struct {
    Vector3 origen;
    Vector3 direccion;
} Camara;

Camara crear_camara(Vector3 origen, Vector3 direccion);

#endif