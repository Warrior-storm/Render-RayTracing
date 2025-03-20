#ifndef VECTOR_H
#define VECTOR_H



// Definiciones de Vectores en 2 dimensiones

typedef struct{
    float x;
    float y;
}Vector2;

Vector2  sum2( Vector2 a,  Vector2 b);
Vector2 rest2( Vector2 a,  Vector2 b);
float mag2( Vector2 a);
Vector2 norm2( Vector2 a);
Vector2 Esc2( Vector2 a, float b);
float dot2( Vector2 a,  Vector2 b);
Vector3 cruz2( Vector2 a,  Vector2 b);


// Definiciones de Vectores en 3 dimensiones

typedef struct{
    float x;
    float y;
    float z;
}Vector3;

Vector3 sum3( Vector3 a,  Vector3 b);
Vector3 rest3( Vector3 a,  Vector3 b);
float mag3( Vector3 a);
Vector3 norm3( Vector3 a);
Vector3 Esc3( Vector3 a, float b);
float dot3( Vector3 a,  Vector3 b);
Vector3 cruz3( Vector3 a,  Vector3 b);

#endif 