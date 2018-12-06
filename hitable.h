#ifndef HITABLE_H
#define HITABLE_H

#include <stdbool.h>
#include "ray.h"
#include "sphere.h"

typedef struct {
    double t;
    Vector *point;
    Vector *normal;
} HitRecord;

HitRecord *makeHitRecord();
void updateHitRecordFromOther(HitRecord *h, HitRecord *other);
void freeHitRecord(HitRecord *h);

typedef struct {
    Sphere **list;
    int capacity;
    int size;
} HitableList;

bool hitHitableList(Ray *r, HitableList* list, double tMin, double tMax, HitRecord *result);


#endif
