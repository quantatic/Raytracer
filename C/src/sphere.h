#ifndef SPHERE_H
#define SPHERE_H

#include "ray.h"
#include "hitable.h"
#include <stdbool.h>

typedef struct {
    Vector *pos;
    double radius;
} Sphere;

Sphere *makeSphere();
void updateSphere(Sphere *s, double x, double y, double z, double r);
void updateSphereFromOther(Sphere *s, Sphere *other);
void freeSphere(Sphere *s);

bool hitSphere(Sphere *s, Ray *r, HitRecord *rec);

#endif
