#ifndef VECTOR_H
#define VECTOR_H



// Definiciones de Vectores de 2

struct Vector_2 {
    int x;
    int y;
};

void sum2(struct Vector_2 a, struct Vector_2 b, struct Vector_2 *result);
void rest2(struct Vector_2 a, struct Vector_2 b, struct Vector_2 *result);
float mag2(struct Vector_2 a, float *result);
struct Vector_2 norm2(struct Vector_2 a);
struct Vector_2 Esc2(struct vector_2 a, float b);

// Definiciones de Vectores de 3

struct Vector_3 {
    int x;
    int y;
    int z;
};

void sum3(struct Vector_3 a, struct Vector_3 b, struct Vector_3 *result);
void rest3(struct Vector_3 a, struct Vector_3 b, struct Vector_3 *result);
float mag3(struct Vector_3 a, float *result);
struct Vector_3 norm3(struct Vector_3 a);
struct Vector_3 Esc3(struct vector_3 a, float b);

#endif 