#ifndef ESCENA_H
#define ESCENA_H

#include "Esfera.h"

typedef struct {
    Esfera *esferas;
    int num_esferas;
} Escena;

Escena crear_escena(Esfera *esferas, int num_esferas);

#endif // ESCENA_H