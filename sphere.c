#include "sphere.h"
#include "ray.h"
#include "hitable.h"
#include <math.h>
#include <stdlib.h>

Sphere *makeSphere() {
    Sphere *result = malloc(sizeof(Sphere));
    result->pos = makeVector();
    result->radius = 0;

    return result;
}

void updateSphere(Sphere *s, double x, double y, double z, double r) {
    updateVector(s->pos, x, y, z);
    s->radius = r;
}

void updateSphereFromOther(Sphere *s, Sphere *other) {
    updateVectorFromOther(s->pos, other->pos);
    s->radius = other->radius;
}

void freeSphere(Sphere *s) {
    free(s->pos);
    free(s);
}

bool hitSphere(Sphere *s, Ray *r, HitRecord *rec) {
    Vector *o_sub_c = makeVector();
    subVectors(r->pos, s->pos, o_sub_c);

    double a = normSquared(r->direction);
    double b = 2 * dotProduct(r->direction, o_sub_c);
    double c = normSquared(o_sub_c) - pow(s->radius, 2);

    freeVector(o_sub_c);

    double discriminant = pow(b, 2) - (4 * a * c);
    if(discriminant < 0) {
        return false;
    }

    float t1 = (-b + sqrt(discriminant)) / (2 * a);
    float t2 = (-b - sqrt(discriminant)) / (2 * a);
    float t = fmin(t1, t2);
    pointAtParameter(r, t, rec->point);
    subVectors(rec->point, s->pos, rec->normal);
    unitVector(rec->normal, rec->normal);
    return true; 
}
