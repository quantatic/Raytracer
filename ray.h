#ifndef RAY_H
#define RAY_H

typedef struct {
    double x;
    double y;
    double z;
} Vector;

typedef struct {
    Vector *pos;
    Vector *direction;
} Ray;

Ray *makeRay();
void updateRay(Ray *r, double posX, double posY, double posZ, double dirX, double dirY, double dirZ);
void updateRayFromOther(Ray *r, Ray *other);
void freeRay(Ray *r);

void pointAtParameter(Ray *r, double t, Vector *result);

Vector *makeVector();
void updateVector(Vector *v, double x, double y, double z);
void updateVectorFromOther(Vector *v, Vector *other);
void freeVector(Vector *v);

double dotProduct(Vector *a, Vector *b);
double normSquared(Vector *v);
double norm(Vector *v);

void addVectors(Vector *a, Vector *b, Vector *result);
void subVectors(Vector *a, Vector *b, Vector *result);

void multVector(Vector *v, double scalar, Vector *result);
void divideVector(Vector *v, double scalar, Vector *result);

void unitVector(Vector *v, Vector *result);

#endif
