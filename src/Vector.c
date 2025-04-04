#include "Vector.h"
#include <math.h>

//Funciones de Vectores de 2 dimensiones
Vector2 sum2(Vector2 a, Vector2 b) {
    return (Vector2){(a.x+b.x),(a.y+b.y)};
}

Vector2 rest2(Vector2 a, Vector2 b){
    return (Vector2){(a.x-b.x),(a.y-b.y)};
}

float mag2(Vector2 a) {
    return sqrt((a.x * a.x) + (a.y * a.y));
}

Vector2 norm2(Vector2 a) {
    float mag = mag2(a);

    return (Vector2) {a.x / mag, a.y / mag};
}
Vector2 Esc2(Vector2 a, float b) {
    return (Vector2) {a.x * b, a.y * b};
}

float dot2(Vector2 a, Vector2 b) {
    return (a.x * b.x) + (a.y * b.y);
}

Vector3 cruz2(Vector2 a, Vector2 b) {
    return (Vector3) {0, 0, (a.x * b.y) - (a.y * b.x)};
}

//Funciones de Vectores de 3 dimensiones 
Vector3 sum3(Vector3 a, Vector3 b) {
    return(Vector3){(a.x+b.x),(a.y+b.y),(a.z+b.z)};
}

Vector3 rest3(Vector3 a, Vector3 b) {
   return(Vector3){(a.x-b.x),(a.y-b.y),(a.z-b.z)};
}

float mag3(Vector3 a) {
    return sqrt((a.x * a.x )+ (a.y * a.y) + (a.z * a.z));
}

Vector3 norm3(Vector3 a) {
    float mag = mag3(a);

    return (Vector3) {a.x / mag, a.y / mag, a.z / mag};
}

Vector3 Esc3(Vector3 a, float b) {
    return (Vector3) {a.x * b, a.y * b, a.z * b};
}

float dot3(Vector3 a, Vector3 b) {
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

Vector3 cruz3(Vector3 a, Vector3 b) {
    return (Vector3) {
        (a.y * b.z) - (a.z * b.y),
        (a.z * b.x) - (a.x * b.z),
        (a.x * b.y) - (a.y * b.x)
    };
}
Vector3 rotarX(Vector3 v, float angle) {
    float cosAngle = cos(angle);
    float sinAngle = sin(angle);
    return (Vector3){
        v.x,
        v.y * cosAngle - v.z * sinAngle,
        v.y * sinAngle + v.z * cosAngle
    };
}


Vector3 puntoMedio(Vector3 a, Vector3 b) {
    return (Vector3){
        (a.x + b.x) / 2,
        (a.y + b.y) / 2,
        (a.z + b.z) / 2
    };
}

