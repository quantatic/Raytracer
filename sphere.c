#include "sphere.h"
#include "ray.h"
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

float rayIntersectsSphere(Ray *r, Sphere *s) {
    Vector *o_sub_c = makeVector();
    subVectors(r->pos, s->pos, o_sub_c);

    double intersectionTestValue = pow(dotProduct(o_sub_c, r->direction), 2);
    intersectionTestValue -= normSquared(o_sub_c);
    intersectionTestValue += pow(s->radius, 2);

    freeVector(o_sub_c);
    return (intersectionTestValue >= 0); //solving for the discriminant, if >=0, has real solutions
}
