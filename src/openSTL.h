#ifndef OPENSTL_H
#define OPENSTL_H

#include <math.h>
#include <stdio.h>

void writeFace(FILE *file, float normal[3], float v1[3], float v2[3], float v3[3]) ;
void generateSTL(const char *filename, float radius, int slices, int stacks);


#endif 
