#include "openSTL.h"

void writeFace(FILE *file, float normal[3], float v1[3], float v2[3], float v3[3]) {
    fprintf(file, "facet normal %e %e %e\n", normal[0], normal[1], normal[2]);
    fprintf(file, "  outer loop\n");
    fprintf(file, "    vertex %e %e %e\n", v1[0], v1[1], v1[2]);
    fprintf(file, "    vertex %e %e %e\n", v2[0], v2[1], v2[2]);
    fprintf(file, "    vertex %e %e %e\n", v3[0], v3[1], v3[2]);
    fprintf(file, "  endloop\n");
    fprintf(file, "endfacet\n");
}

void generateSTL(const char *filename, float radius, int slices, int stacks) {
    FILE *file = fopen(filename, "w");
    
    fprintf(file, "solid sphere\n");

    for (int i = 0; i < stacks; ++i) {
        float lat0 = M_PI * (-0.5 + (float)(i) / stacks);
        float z0  = sin(lat0);
        float zr0 =  cos(lat0);
        
        float lat1 = M_PI * (-0.5 + (float)(i+1) / stacks);
        float z1 = sin(lat1);
        float zr1 = cos(lat1);

        for (int j = 0; j < slices; ++j) {
            float lng = 2 * M_PI * (float)(j) / slices;
            float x = cos(lng);
            float y = sin(lng);

            float v0[3] = { x * zr0 * radius, y * zr0 * radius, z0 * radius };
            float v1[3] = { x * zr1 * radius, y * zr1 * radius, z1 * radius };

            lng = 2 * M_PI * (float)(j+1) / slices;
            x = cos(lng);
            y = sin(lng);

            float v2[3] = { x * zr1 * radius, y * zr1 * radius, z1 * radius };
            float v3[3] = { x * zr0 * radius, y * zr0 * radius, z0 * radius };

            float normal[3] = { (v0[0] + v1[0] + v2[0] + v3[0]) / 4.0f, (v0[1] + v1[1] + v2[1] + v3[1]) / 4.0f, (v0[2] + v1[2] + v2[2]) / 4.0f };

            writeFace(file, normal, v0, v1, v2);
            writeFace(file, normal, v0, v2, v3);
        }
    }

    fprintf(file, "endsolid sphere\n");
    fclose(file);
}


