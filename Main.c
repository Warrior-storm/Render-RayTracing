#include "src/Raytracing.h"
#include "src/Esfera.h"
#include "src/Cilindro.h"
#include "src/Cono.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/stat.h>

#define WIDTH 800
#define HEIGHT 600
#define FRAMES 60
#define PI 3.14159265359
#define FRAME_DIR "frames"
#define ROTATION_RADIUS 1.0

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

Vector3 calcularColor(Esfera sphere, Cilindro cilindro, Cono cono, Ray r, Luz luz) {
    float t_sphere, t_cilindro, t_cono;
    Vector3 normal_sphere, normal_cilindro, normal_cono;
    int hit_sphere = hit(sphere, r, &t_sphere, &normal_sphere);
    int hit_cyl = hit_Cilindro(cilindro, r, &t_cilindro, &normal_cilindro);
    int hit_cone = hit_cono(cono, r, &t_cono, &normal_cono);

    Vector3 color = {0, 0, 0}; 
    Vector3 ambient = {0.1, 0.1, 0.1}; 

    if (hit_sphere && (!hit_cyl || t_sphere < t_cilindro) && (!hit_cone || t_sphere < t_cono)) {
        Vector3 hit_point = rayo(r, t_sphere);
        Vector3 light_dir = norm3(rest3(luz.posicion, hit_point));
        Vector3 normal = normal_sphere;

        float difuso = dot3(normal, light_dir);
        if (difuso < 0.0) {
            normal = Esc3(normal, -1.0);
            difuso = fmax(0.0, dot3(normal, light_dir));
        }

        difuso = fmax(0.0, difuso);
        Vector3 diffuse = Esc3(luz.color, difuso);

        Vector3 view_dir = norm3(rest3(r.origen, hit_point));
        Vector3 reflect_dir = norm3(rest3(Esc3(normal, 2.0 * dot3(normal, light_dir)), light_dir));
        float specular = pow(fmax(0.0, dot3(view_dir, reflect_dir)), 32.0);
        Vector3 specular_color = Esc3(luz.color, specular);

        color = sum3(ambient, sum3(diffuse, specular_color));
    } else if (hit_cyl && (!hit_cone || t_cilindro < t_cono)) {
        Vector3 hit_point = rayo(r, t_cilindro);
        Vector3 light_dir = norm3(rest3(luz.posicion, hit_point));
        Vector3 normal = normal_cilindro;

        float difuso = dot3(normal, light_dir);
        if (difuso < 0.0) {
            normal = Esc3(normal, -1.0);
            difuso = fmax(0.0, dot3(normal, light_dir));
        }

        difuso = fmax(0.0, difuso);
        Vector3 diffuse = Esc3(luz.color, difuso);

        Vector3 view_dir = norm3(rest3(r.origen, hit_point));
        Vector3 reflect_dir = norm3(rest3(Esc3(normal, 2.0 * dot3(normal, light_dir)), light_dir));
        float specular = pow(fmax(0.0, dot3(view_dir, reflect_dir)), 32.0);
        Vector3 specular_color = Esc3(luz.color, specular);

        color = sum3(ambient, sum3(diffuse, specular_color));
    } else if (hit_cone) {
        Vector3 hit_point = rayo(r, t_cono);
        Vector3 light_dir = norm3(rest3(luz.posicion, hit_point));
        Vector3 normal = normal_cono;

        float difuso = dot3(normal, light_dir);
        if (difuso < 0.0) {
            normal = Esc3(normal, -1.0);
            difuso = fmax(0.0, dot3(normal, light_dir));
        }

        difuso = fmax(0.0, difuso);
        Vector3 diffuse = Esc3(luz.color, difuso);

        Vector3 view_dir = norm3(rest3(r.origen, hit_point));
        Vector3 reflect_dir = norm3(rest3(Esc3(normal, 2.0 * dot3(normal, light_dir)), light_dir));
        float specular = pow(fmax(0.0, dot3(view_dir, reflect_dir)), 32.0);
        Vector3 specular_color = Esc3(luz.color, specular);

        color = sum3(ambient, sum3(diffuse, specular_color));
    }

    color.x = fmax(0.0, fmin(1.0, color.x));
    color.y = fmax(0.0, fmin(1.0, color.y));
    color.z = fmax(0.0, fmin(1.0, color.z));

    return color; 
}

Vector3 rotarY(Vector3 v, float angle) {
    float sin_theta = sin(angle);
    float cos_theta = cos(angle);
    return (Vector3){
        v.x * cos_theta + v.z * sin_theta,
        v.y,
        -v.x * sin_theta + v.z * cos_theta
    };
}

void generateRayTracingImage(const char *filename, Esfera sphere, Cilindro cilindro, Cono cono, Luz luz, float angle) {
    unsigned char *image = (unsigned char *)malloc(3 * WIDTH * HEIGHT);
    if (!image) {
        printf("Error allocating memory for image.\n");
        return;
    }

    sphere.centro = rotarY(sphere.centro, angle);
    cilindro.base = rotarY(cilindro.base, angle); 
    cono.base = rotarY(cono.base, angle); 

    Vector3 camera_position = {0, 0, 5}; 

    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            float u = (float)x / (WIDTH - 1);
            float v = (float)y / (HEIGHT - 1);

            Ray rayo;
            rayo.origen = camera_position;
            rayo.direccion = norm3((Vector3){u * 2 - 1, v * 2 - 1, -1});

            Vector3 color = calcularColor(sphere, cilindro, cono, rayo, luz);
            int pixel_index = (y * WIDTH + x) * 3;
            image[pixel_index] = (unsigned char)(color.x * 255);
            image[pixel_index + 1] = (unsigned char)(color.y * 255);
            image[pixel_index + 2] = (unsigned char)(color.z * 255);
        }
    }

    save_image_ppm(filename, image, WIDTH, HEIGHT);
    free(image);
}

void createAnimationFrames(Esfera sphere, Cilindro cilindro, Cono cono, Luz luz) {
    struct stat st = {0};

    if (stat(FRAME_DIR, &st) == -1) {
        mkdir(FRAME_DIR, 0700);
    }

    char filename[100];
    for (int i = 0; i < FRAMES; ++i) {
        float angle = (float)i / FRAMES * 2.0 * PI;
        snprintf(filename, sizeof(filename), FRAME_DIR "/frame_%03d.ppm", i);
        generateRayTracingImage(filename, sphere, cilindro, cono, luz, angle);
    }
}

int main() {
    Esfera sphere;
    sphere.centro = (Vector3){0, 0, 0};
    sphere.r = 1.0;

    Cilindro cilindro;
    cilindro.base = (Vector3){-2, 0, 0}; 
    cilindro.axis = (Vector3){0, 1, 0};
    cilindro.radius = 0.5;
    cilindro.height = 2.0;

    Cono cono;
    cono.base = (Vector3){2, 0, 0};
    cono.axis = (Vector3){0, 1, 0};
    cono.radius = 0.5;
    cono.height = 2.0;

    Luz luz;
    luz.posicion = (Vector3){-2, 2, 0}; // Light position
    luz.color = (Vector3){1, 1, 1};

    createAnimationFrames(sphere, cilindro, cono, luz);

    return 0;
}