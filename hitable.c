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

HitableList *makeHitableList() {
   HitableList *result = malloc(sizeof(HitableList)); 
   result->capacity = INIT_HITABLE_LIST_SIZE;
   result->size = 0;
   result->list = malloc(INIT_HITABLE_LIST_SIZE * sizeof(Sphere *));

   return result;
}

void addToHitableList(HitableList *list, Sphere *obj) {
    if(list->size >= list->capacity) {
        list->list = realloc(list->list, list->capacity * 2);
        list->capacity *= 2;
    }
}

void freeHitableList(HitableList *list) {
    free(list->list);
    free(list);
}

bool hitHitableList(Ray *r, HitableList* list, double tMin, double tMax, HitRecord *result) {
    //HitRecord *tmp = makeHitRecord();
    //double closestSoFar = FLT_MAX;
    //for(int i = 0; i < list->size; i++) {
    //}
    return false;
}
