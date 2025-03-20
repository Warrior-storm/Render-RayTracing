#include <stdio.h>
#include "Vector.h"

int main() {
    // Pruebas para vectores de 2 dimensiones
    struct Vector2 v2_a = {3.0, 4.0};
    struct Vector2 v2_b = {1.0, 2.0};
    struct Vector2 v2_result;

    // Suma de vectores 2D
    sum2(v2_a, v2_b, &v2_result);
    printf("Suma 2D: (%.2f, %.2f)\n", v2_result.x, v2_result.y);

    // Resta de vectores 2D
    rest2(v2_a, v2_b, &v2_result);
    printf("Resta 2D: (%.2f, %.2f)\n", v2_result.x, v2_result.y);

    // Magnitud de un vector 2D
    float mag_v2 = mag2(v2_a);
    printf("Magnitud 2D: %.2f\n", mag_v2);

    // Normalización de un vector 2D
    struct Vector2 v2_norm = norm2(v2_a);
    printf("Normalización 2D: (%.2f, %.2f)\n", v2_norm.x, v2_norm.y);

    // Escalar un vector 2D
    struct Vector2 v2_esc = Esc2(v2_a, 2.0);
    printf("Escalar 2D: (%.2f, %.2f)\n", v2_esc.x, v2_esc.y);

    // Pruebas para vectores de 3 dimensiones
    struct Vector3 v3_a = {3.0, 4.0, 5.0};
    struct Vector3 v3_b = {1.0, 2.0, 3.0};
    struct Vector3 v3_result;

    // Suma de vectores 3D
    sum3(v3_a, v3_b, &v3_result);
    printf("Suma 3D: (%.2f, %.2f, %.2f)\n", v3_result.x, v3_result.y, v3_result.z);

    // Resta de vectores 3D
    rest3(v3_a, v3_b, &v3_result);
    printf("Resta 3D: (%.2f, %.2f, %.2f)\n", v3_result.x, v3_result.y, v3_result.z);

    // Magnitud de un vector 3D
    float mag_v3 = mag3(v3_a);
    printf("Magnitud 3D: %.2f\n", mag_v3);

    // Normalización de un vector 3D
    struct Vector3 v3_norm = norm3(v3_a);
    printf("Normalización 3D: (%.2f, %.2f, %.2f)\n", v3_norm.x, v3_norm.y, v3_norm.z);

    // Escalar un vector 3D
    struct Vector3 v3_esc = Esc3(v3_a, 2.0);
    printf("Escalar 3D: (%.2f, %.2f, %.2f)\n", v3_esc.x, v3_esc.y, v3_esc.z);

    return 0;
}