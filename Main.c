#include "Raytracing.h"
#include "Esfera.h"
#include <stdio.h>
#include <stdlib.h>

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

void generateRayTracingImage(const char *filename, Esfera sphere, Ray ray) {
    unsigned char *image = (unsigned char *)malloc(3 * WIDTH * HEIGHT);
    if (!image) {
        printf("Error allocating memory for image.\n");
        return;
    }

    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            float u = (float)x / (WIDTH - 1);
            float v = (float)y / (HEIGHT - 1);

            Ray currentRay = ray;
            currentRay.direccion = norm3((Vector3){ray.direccion.x + u - 0.5f, ray.direccion.y + v - 0.5f, ray.direccion.z});

            float t;
            int pixel_index = (y * WIDTH + x) * 3;
            if (hit(sphere, currentRay, &t)) {
                image[pixel_index] = 255;     // Red
                image[pixel_index + 1] = 0;   // Green
                image[pixel_index + 2] = 0;   // Blue
            } else {
                image[pixel_index] = 0;     // Red
                image[pixel_index + 1] = 0; // Green
                image[pixel_index + 2] = 0; // Blue
            }
        }
    }

    save_image_ppm(filename, image, WIDTH, HEIGHT);
    free(image);
}

int main() {
    Esfera sphere;
    sphere.centro = (Vector3){0, 0, -5};
    sphere.r = 1.0;

    Ray ray;
    ray.origen = (Vector3){0, 0, 0};
    ray.direccion = (Vector3){0, 0, -1};

    generateRayTracingImage("ray_traced_sphere.ppm", sphere, ray);

    return 0;
}
