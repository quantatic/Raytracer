#ifndef HITABLE_H
#define HITABLE_H

#include <stdbool.h>
#include "ray.h"

typedef struct {
    double t;
    Vector *point;
    Vector *normal;
} HitRecord;

HitRecord *makeHitRecord();
void updateHitRecordFromOther(HitRecord *h, HitRecord *other);
void freeHitRecord(HitRecord *h);

#endif
