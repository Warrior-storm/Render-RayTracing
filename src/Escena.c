#include "Escena.h"

Escena crear_escena(Esfera *esferas, int num_esferas) {
    Escena escena = {esferas, num_esferas};
    return escena;
}