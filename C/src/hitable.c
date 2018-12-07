#include <stdlib.h>
#include <float.h>
#include "hitable.h"

#define INIT_HITABLE_LIST_SIZE 10

HitRecord *makeHitRecord() {
    HitRecord *result = malloc(sizeof(HitRecord));
    result->t = 0;
    result->point = makeVector();
    result->normal = makeVector();
    return result;
}

void updateHitRecordFromOther(HitRecord *h, HitRecord *other) {
    h->t = other->t;
    updateVectorFromOther(h->point, other->point);
    updateVectorFromOther(h->normal, other->normal);
}

void freeHitRecord(HitRecord *h) {
    free(h->point);
    free(h->normal);
    free(h);
}
