#include "src/Raytracing.h"
#include "src/Esfera.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600

void save_image_ppm(const char *filename, unsigned char *image, int width, int height) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }

    fprintf(file, "P6\n%d %d\n255\n", width, height);
    fwrite(image, 3, width * height, file);
    fclose(file);
}

Vector3 calcularColor(Esfera sphere, Ray r, Luz luz) {
    float t;
    Vector3 normal;
    if (hit(sphere, r, &t, &normal)) {
        Vector3 hit_point = rayo(r, t);
        Vector3 light_dir = norm3(rest3(luz.posicion, hit_point));
        float difuso = fmax(0.0, dot3(normal, light_dir));
        
        Vector3 color = Esc3(luz.color, difuso);
        return color;
    }
    return (Vector3){255, 255, 255};
    }

void generateRayTracingImage(const char *filename, Esfera sphere, Luz luz) {
    unsigned char *image = (unsigned char *)malloc(3 * WIDTH * HEIGHT);
    if (!image) {
        printf("Error allocating memory for image.\n");
        return;
    }

    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            float u = (float)x / (WIDTH - 1);
            float v = (float)y / (HEIGHT - 1);

            Ray rayo;
            rayo.origen = (Vector3){0, 0, 0};
            rayo.direccion = norm3((Vector3){u * 2 - 1, v * 2 - 1, -1});

            Vector3 color = calcularColor(sphere, rayo, luz);
            int pixel_index = (y * WIDTH + x) * 3;
            image[pixel_index] = (unsigned char)(color.x * 255);
            image[pixel_index + 1] = (unsigned char)(color.y * 255);
            image[pixel_index + 2] = (unsigned char)(color.z * 255);
        }
    }

    save_image_ppm(filename, image, WIDTH, HEIGHT);
    free(image);
}

int main() {
    Esfera sphere;
    sphere.centro = (Vector3){0, 0, -5};
    sphere.r = 1.0;

    Luz luz;
    luz.posicion = (Vector3){-2, 2, 0};
    luz.color = (Vector3){1, 1, 1}; // Luz blanca

    generateRayTracingImage("ray_traced_sphere.ppm", sphere, luz);

    return 0;
}