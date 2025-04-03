#include "src/Raytracing.h"
#include "src/Esfera.h"
#include "src/Cilindro.h"
#include "src/Cubo.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/stat.h> 

#define WIDTH 800
#define HEIGHT 600
#define FRAMES 30
#define FRAME_DIR "frames"

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

Vector3 calcularColor(Esfera sphere, Cilindro cilindro, Cubo cubo, Ray r, Luz luz) {
    float t_sphere, t_cilindro, t_cubo;
    Vector3 normal_sphere, normal_cilindro, normal_cubo;
    int hit_sphere = hit(sphere, r, &t_sphere, &normal_sphere);
    int hit_cyl = hit_Cilindro(cilindro, r, &t_cilindro, &normal_cilindro);
    int hit_cube = hit_cubo(cubo, r, &t_cubo, &normal_cubo);

    if (hit_sphere && (!hit_cyl || t_sphere < t_cilindro) && (!hit_cube || t_sphere < t_cubo)) {
        Vector3 hit_point = rayo(r, t_sphere);
        Vector3 light_dir = norm3(rest3(luz.posicion, hit_point));
        float difuso = fmax(0.0, dot3(normal_sphere, light_dir));
        Vector3 color = Esc3(luz.color, difuso);
        return color;
    } else if (hit_cyl && (!hit_cube || t_cilindro < t_cubo)) {
        Vector3 hit_point = rayo(r, t_cilindro);
        Vector3 light_dir = norm3(rest3(luz.posicion, hit_point));
        float difuso = fmax(0.0, dot3(normal_cilindro, light_dir));
        Vector3 color = Esc3(luz.color, difuso);
        return color;
    } else if (hit_cube) {
        Vector3 hit_point = rayo(r, t_cubo);
        Vector3 light_dir = norm3(rest3(luz.posicion, hit_point));
        float difuso = fmax(0.0, dot3(normal_cubo, light_dir));
        Vector3 color = Esc3(luz.color, difuso);
        return color;
    }

    return (Vector3){0, 0, 0}; // Fondo negro
}

void generateRayTracingImage(const char *filename, Esfera sphere, Cilindro cilindro, Cubo cubo, Luz luz) {
    unsigned char *image = (unsigned char *)malloc(3 * WIDTH * HEIGHT);
    if (!image) {
        printf("Error allocating memory for image.\n");
        return;
    }

    Vector3 camera_position = {0, 0, 1};

    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            float u = (float)x / (WIDTH - 1);
            float v = (float)y / (HEIGHT - 1);

            Ray rayo;
            rayo.origen = camera_position;
            rayo.direccion = norm3((Vector3){u * 2 - 1, v * 2 - 1, -1});

            Vector3 color = calcularColor(sphere, cilindro, cubo, rayo, luz);
            int pixel_index = (y * WIDTH + x) * 3;
            image[pixel_index] = (unsigned char)(color.x * 255);
            image[pixel_index + 1] = (unsigned char)(color.y * 255);
            image[pixel_index + 2] = (unsigned char)(color.z * 255);
        }
    }

    save_image_ppm(filename, image, WIDTH, HEIGHT);
    free(image);
}

void createAnimationFrames(Esfera sphere, Cilindro cilindro, Cubo cubo, Luz luz) {
    struct stat st = {0};

    // Crear la carpeta si no existe
    if (stat(FRAME_DIR, &st) == -1) {
        mkdir(FRAME_DIR, 0700);
    }

    char filename[100];
    for (int i = 0; i < FRAMES; ++i) {
        snprintf(filename, sizeof(filename), FRAME_DIR "/frame_%03d.ppm", i);
        generateRayTracingImage(filename, sphere, cilindro, cubo, luz);
    }
}

int main() {
    Esfera sphere;
    sphere.centro = (Vector3){0, 0, -5};
    sphere.r = 1.0;

    Cilindro cilindro;
    cilindro.base = (Vector3){-2, -1, -6};
    cilindro.axis = (Vector3){0, 1, 0};
    cilindro.radius = 0.5;
    cilindro.height = 2.0;

    Cubo cubo;
    cubo.min = (Vector3){2, -1, -6};
    cubo.max = (Vector3){3, 0, -5};

    Luz luz;
    luz.posicion = (Vector3){-2, 2, 0};
    luz.color = (Vector3){1, 1, 1}; // Luz blanca

    createAnimationFrames(sphere, cilindro, cubo, luz);

    return 0;
}