#include "sphere.h"
#include "ray.h"
#include "raytrace.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    FILE *outFile = fopen("output.ppm", "w"); 

    Sphere *sphere = makeSphere();
    updateSphere(sphere, 0, 0, -5, 1);

    int nx = 10000;
    int ny = 10000;
    double pixelScale = 0.0001;

    fprintf(outFile, "P6\n%d %d\n255\n", nx, ny);

    Ray *projectionRay = makeRay();
    updateRay(projectionRay, 0, 0, 0, 0, 0, 0);


    for(int y = 0; y < ny; y++) {
        for(int x = 0; x < nx; x++) {
            updateVector(projectionRay->direction, (x - (nx / 2)) * pixelScale, (y - (ny / 2)) * pixelScale, -1);

            unitVector(projectionRay->direction, projectionRay->direction);
            if(rayIntersectsSphere(projectionRay, sphere)) {
                putc(255, outFile);
                putc(255, outFile);
                putc(255, outFile);
            } else {
                putc(0, outFile);
                putc(0, outFile);
                putc(0, outFile);
            }
        }
    }
    

    freeRay(projectionRay);
    freeSphere(sphere);
    return EXIT_SUCCESS;
}

void getColorOfRay(Ray *r, Sphere *s, Vector *result) {
    unitVector(r->direction, r->direction);
    Vector *backgroundColor = makeVector();
    updateVector(backgroundColor, 0.5, 0.7, 1);

    multVector(backgroundColor, 256 * (1 + r->direction->y) * 0.5, result);
}
