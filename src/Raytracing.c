#include "Raytracing.h"
#include "Vector.h"

Vector3 rayo(Rayo r, float t){
    return sum3(r.origen, Esc3(r.direccion, t));
}
