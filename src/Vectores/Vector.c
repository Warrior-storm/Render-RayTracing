#include "Vector.h"
#include <math.h>

//Funciones de Vectores de 2 dimensiones
void sum2(struct Vector2 a, struct Vector2 b, struct Vector2 *result) {
    result->x = a.x + b.x;
    result->y = a.y + b.y;
}

void rest2(struct Vector2 a, struct Vector2 b, struct Vector2 *result) {
    result->x = a.x - b.x;
    result->y = a.y - b.y;
}

float mag2(struct Vector2 a) {
    return sqrt((a.x * a.x) + (a.y * a.y));
}

struct Vector2 norm2(struct Vector2 a) {
    float mag = mag2(a);

    return (struct Vector2) {a.x / mag, a.y / mag};
}
struct Vector2 Esc2(struct Vector2 a, float b) {
    return (struct Vector2) {a.x * b, a.y * b};
}

float dot2(struct Vector2 a, struct Vector2 b) {
    return (a.x * b.x) + (a.y * b.y);
}

struct Vector3 cruz2(struct Vector2 a, struct Vector2 b) {
    return (struct Vector3) {0, 0, (a.x * b.y) - (a.y * b.x)};
}

//Funciones de Vectores de 3 dimensiones 
void sum3(struct Vector3 a, struct Vector3 b, struct Vector3 *result) {
    result->x = a.x + b.x;
    result->y = a.y + b.y;
    result->z = a.z + b.z;
}

void rest3(struct Vector3 a, struct Vector3 b, struct Vector3 *result) {
    result->x = a.x - b.x;
    result->y = a.y - b.y;
    result->z = a.z - b.z;
}

float mag3(struct Vector3 a) {
    return sqrt((a.x * a.x )+ (a.y * a.y) + (a.z * a.z));
}

struct Vector3 norm3(struct Vector3 a) {
    float mag = mag3(a);

    return (struct Vector3) {a.x / mag, a.y / mag, a.z / mag};
}

struct Vector3 Esc3(struct Vector3 a, float b) {
    return (struct Vector3) {a.x * b, a.y * b, a.z * b};
}

float dot3(struct Vector3 a, struct Vector3 b) {
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

struct Vector3 cruz3(struct Vector3 a, struct Vector3 b) {
    return (struct Vector3) {
        (a.y * b.z) - (a.z * b.y),
        (a.z * b.x) - (a.x * b.z),
        (a.x * b.y) - (a.y * b.x)
    };
}


