//
//  VectorLibrary.cpp
//  Matrix Library
//
//  Created by Mario Andrade on 4/15/14.
//  Copyright (c) 2014 Mario Andrade. All rights reserved.
//

#include "VectorLibrary.h"

void Vec3::initVec(Vec3* v, float a, float b, float c) {
    v->x = a;
    v->y = b;
    v->z = c;
}

float Vec3::getX() {
    return x;
}

float Vec3::getY() {
    return y;
}

float Vec3::getZ() {
    return z;
}

void Vec3::setX(float a) {
    x = a;
}

void Vec3::setY(float b) {
    y = b;
}

void Vec3::setZ(float c) {
    z = c;
}

void Vec3::vecAdd(Vec3* v, Vec3 *a, Vec3*b) {
    v->x = a->x + b->x;
    v->y = a->y + b->y;
    v->z = a->z + b->z;
}

float Vec3::vecDot(Vec3* a, Vec3* b) {
    return (a->x * b->x + a->y * b->y + a->z * b->z);
}

void Vec3::vecCross(Vec3* v, Vec3* a, Vec3* b) {
    //This gives us our vector i.
    v->x = a->y * b->z - b->y * a->z;
    //This gives us our vector j.
    v->y = -(a->x * b->z - b->x * a->z);
    //This gives us our vector k.
    v->z = a->x * b->y - b->x * a->y;
}

void Vec3::vecCopy(Vec3* v, Vec3* a){
    v->x = a->x;
    v->y = a->y;
    v->z = a->z;
}