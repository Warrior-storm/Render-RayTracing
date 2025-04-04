#include "Camara.h"

Camara crear_camara(Vector3 origen, Vector3 direccion) {
    Camara camara = {origen, direccion};
    return camara;
}

