#include "Vector.h"
#include <math.h>

//Funciones de Vectores de 2 dimensiones
void sum2(struct Vector_2 a, struct Vector_2 b, struct Vector_2 *result) {
    result->x = a.x + b.x;
    result->y = a.y + b.y;
}

void rest2(struct Vector_2 a, struct Vector_2 b, struct Vector_2 *result) {
    result->x = a.x - b.x;
    result->y = a.y - b.y;
}

float mag2(struct Vector_2 a) {
    return sqrt((a.x * a.x) + (a.y * a.y));
}

struct Vector_2 norm2(struct Vector_2 a) {
    float mag = mag2(a);

    return (struct Vector_2) {a.x / mag, a.y / mag};
}
struct Vector_2 Esc2(struct Vector_2 a, float b) {
    return (struct Vector_2) {a.x * b, a.y * b};
}

//Funciones de Vectores de 3 dimensiones 
void sum3(struct Vector_3 a, struct Vector_3 b, struct Vector_3 *result) {
    result->x = a.x + b.x;
    result->y = a.y + b.y;
    result->z = a.z + b.z;
}

void rest3(struct Vector_3 a, struct Vector_3 b, struct Vector_3 *result) {
    result->x = a.x - b.x;
    result->y = a.y - b.y;
    result->z = a.z - b.z;
}

float mag3(struct Vector_3 a) {
    return sqrt((a.x * a.x )+ (a.y * a.y) + (a.z * a.z));
}

struct Vector_3 norm3(struct Vector_3 a) {
    float mag = mag3(a);

    return (struct Vector_3) {a.x / mag, a.y / mag, a.z / mag};
}

struct Vector_3 Esc3(struct Vector_3 a, float b) {
    return (struct Vector_3) {a.x * b, a.y * b, a.z * b};
}


