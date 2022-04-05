#include "geometry.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float dotnum(char *c){
        double a = atof(c);
        float b = (float)a;
return b;
}

void per_area(float c3){
        float per = 2 * M_PI * c3;
        float area = M_PI * pow(c3, 2);

        printf("Perimeter = %f\nArea = %f\n", per, area);
}
