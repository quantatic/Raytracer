#include <stdlib.h>
#include <math.h>
#include "ray.h"

Ray *makeRay() {
    Ray *result = malloc(sizeof(Ray));
    result->pos = makeVector();
    result->direction = makeVector();

    return result;
}

void updateRay(Ray *r, double posX, double posY, double posZ, double dirX, double dirY, double dirZ) {
    updateVector(r->pos, posX, posY, posZ);
    updateVector(r->direction, dirX, dirY, dirZ);
}

void updateRayFromOther(Ray *r, Ray *other) {
    updateVectorFromOther(r->pos, other->pos);
    updateVectorFromOther(r->direction, other->direction);
}

void freeRay(Ray *r) {
    free(r->pos);
    free(r->direction);
    free(r);
}

void pointAtParameter(Ray *r, double t, Vector *result) {
    multVector(r->direction, t, result);
    addVectors(result, r->pos, result);
}

Vector *makeVector() {
    Vector *result = malloc(sizeof(Vector));
    result->x = 0;
    result->y = 0;
    result->z = 0;
    return result;
}

void updateVector(Vector *v, double x, double y, double z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

void updateVectorFromOther(Vector *v, Vector *other) {
    v->x = other->x;
    v->y = other->y;
    v->z = other->z;
}

void freeVector(Vector *v) {
    free(v);
}

double dotProduct(Vector *a, Vector *b) {
    double result = 0;
    result += (a->x * b->x);
    result += (a->y * b->y);
    result += (a->z * b->z);
    return result;
}

double normSquared(Vector *v) {
    return dotProduct(v, v);
}

double norm(Vector *v) {
    return sqrt(normSquared(v));
}

void addVectors(Vector *a, Vector *b, Vector *result) {
    result->x = a->x + b->x;
    result->y = a->y + b->y;
    result->z = a->z + b->z;
}

void subVectors(Vector *a, Vector *b, Vector *result) {
    result->x = a->x - b->x;
    result->y = a->y - b->y;
    result->z = a->z - b->z;
}

void multVector(Vector *v, double scalar, Vector *result) {
    result->x = v->x * scalar;
    result->y = v->y * scalar;
    result->z = v->z * scalar;
}

void divideVector(Vector *v, double scalar, Vector *result) {
    result->x = v->x / scalar;
    result->y = v->y / scalar;
    result->z = v->z / scalar;
}

void unitVector(Vector *v, Vector *result) {
    double normVal = norm(v);
    divideVector(v, normVal, result); 
}
