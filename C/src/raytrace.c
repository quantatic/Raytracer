#include <stdlib.h>
#include <stdio.h>
#include "sphere.h"
#include "ray.h"
#include "raytrace.h"
#include "hitable.h"

int main() {
    FILE *outFile = fopen("output.ppm", "w"); 

    Sphere *sphere = makeSphere();
    updateSphere(sphere, 0, 0, -5, 1);

    int nx = 100;
    int ny = 100;
    int ns = 10;
    double pixelScale = 0.01;

    fprintf(outFile, "P6\n%d %d\n255\n", nx, ny);

    Ray *projectionRay = makeRay();
    updateRay(projectionRay, 0, 0, 0, 0, 0, 0);

    Vector *color = makeVector();
    Vector *tmpColor = makeVector();

    for(int y = 0; y < ny; y++) {
        for(int x = 0; x < nx; x++) {
            updateVector(color, 0, 0, 0);
            for(int s = 0; s < ns; s++) {
                double thisX = x + ((double)rand() / RAND_MAX);
                double thisY = y + ((double)rand() / RAND_MAX);
                updateVector(projectionRay->direction, (thisX - (nx / 2)) * pixelScale, (thisY - (ny / 2)) * pixelScale, -1);

                getRayColor(projectionRay, sphere, tmpColor);
                addVectors(color, tmpColor, color);
            }
            divideVector(color, ns, color);
            putc(color->x, outFile);
            putc(color->y, outFile);
            putc(color->z, outFile);
        }
    }
    

    freeVector(color);
    freeVector(tmpColor);
    freeRay(projectionRay);
    freeSphere(sphere);

    fclose(outFile);

    return EXIT_SUCCESS;
}

void getRayColor(Ray *r, Sphere *s, Vector *result) {
    HitRecord *hit = makeHitRecord();
    if(hitSphere(s, r, hit)) {
        result->x = ((hit->normal->x + 1) * 0.5) * 255;
        result->y = ((hit->normal->y + 1) * 0.5) * 255;
        result->z = ((hit->normal->z + 1) * 0.5) * 255;
    } else {
        result->x = 0;
        result->y = 0;
        result->z = 0;
    }
    freeHitRecord(hit);
}
