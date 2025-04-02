#include "src/Raytracing.h"
#include "src/Esfera.h"
#include "src/Cilindro.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define FRAMES 30

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

Vector3 calcularColor(Esfera sphere, Cilindro Cilindro, Ray r, Luz luz) {
    float t_sphere, t_Cilindro;
    Vector3 normal_sphere, normal_Cilindro;
    int hit_sphere = hit(sphere, r, &t_sphere, &normal_sphere);
    int hit_cyl = hit_Cilindro(Cilindro, r, &t_Cilindro, &normal_Cilindro);

    if (hit_sphere && (!hit_cyl || t_sphere < t_Cilindro)) {
        Vector3 hit_point = rayo(r, t_sphere);
        Vector3 light_dir = norm3(rest3(luz.posicion, hit_point));
        float difuso = fmax(0.0, dot3(normal_sphere, light_dir));
        Vector3 color = Esc3(luz.color, difuso);
        return color;
    } else if (hit_cyl) {
        Vector3 hit_point = rayo(r, t_Cilindro);
        Vector3 light_dir = norm3(rest3(luz.posicion, hit_point));
        float difuso = fmax(0.0, dot3(normal_Cilindro, light_dir));
        Vector3 color = Esc3(luz.color, difuso);
        return color;
    }

    return (Vector3){0, 0, 0}; // Fondo blanco
}

void generateRayTracingImage(const char *filename, Esfera sphere, Cilindro Cilindro, Luz luz, float angle) {
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

            Vector3 color = calcularColor(sphere, Cilindro, rayo, luz);
            int pixel_index = (y * WIDTH + x) * 3;
            image[pixel_index] = (unsigned char)(color.x * 255);
            image[pixel_index + 1] = (unsigned char)(color.y * 255);
            image[pixel_index + 2] = (unsigned char)(color.z * 255);
        }
    }

    save_image_ppm(filename, image, WIDTH, HEIGHT);
    free(image);
}

void createAnimationFrames(Esfera sphere, Cilindro Cilindro, Luz luz) {
    char filename[100];
    for (int i = 0; i < FRAMES; ++i) {
        float angle = (float)i / FRAMES * 2.0 * M_PI;
        snprintf(filename, sizeof(filename), "frame_%03d.ppm", i);
        generateRayTracingImage(filename, sphere, Cilindro, luz, angle);
    }
    return 0;
}