#ifndef VECTOR_H
#define VECTOR_H



// Definiciones de Vectores en 2 dimensiones

struct Vector2 {
    float x;
    float y;
};

void sum2(struct Vector2 a, struct Vector2 b, struct Vector2 *result);
void rest2(struct Vector2 a, struct Vector2 b, struct Vector2 *result);
float mag2(struct Vector2 a);
struct Vector2 norm2(struct Vector2 a);
struct Vector2 Esc2(struct Vector2 a, float b);
float dot2(struct Vector2 a, struct Vector2 b);
struct Vector3 cruz2(struct Vector2 a, struct Vector2 b);


// Definiciones de Vectores en 3 dimensiones

struct Vector3 {
    float x;
    float y;
    float z;
};

void sum3(struct Vector3 a, struct Vector3 b, struct Vector3 *result);
void rest3(struct Vector3 a, struct Vector3 b, struct Vector3 *result);
float mag3(struct Vector3 a);
struct Vector3 norm3(struct Vector3 a);
struct Vector3 Esc3(struct Vector3 a, float b);
float dot3(struct Vector3 a, struct Vector3 b);
struct Vector3 cruz3(struct Vector3 a, struct Vector3 b);

#endif 