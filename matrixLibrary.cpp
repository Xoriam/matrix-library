//
//  matrixLibrary.cpp
//  Matrix Library
//
//  Created by Mario Andrade on 2/19/14.
//  Copyright (c) 2014 Mario Andrade. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "matrixLibrary.h"

using namespace std;

//Initialized the Matrix based on the matrix fed in from Main.
void Mat3::initMat(float a[9]) {
    for (int i = 0; i < 9; i++) {
        elements[i] = a[i];
    }
}

float Mat3::getElement(int index) {
    return elements[index];
}

void Mat3::matSumScalar(Mat3* m, Mat3* a, float x) {
    for (int i = 0; i < 9; i++) {
        m->elements[i] = a->elements[i] * x;
    }
}

void Mat3::matMultScalar(Mat3* m, Mat3* a, float x) {
    for (int i = 0; i < 9; i++) {
        m->elements[i] = a->elements[i] + x;
    }
}

void Mat3::matMultVector(Vec3* v, Mat3* a, Vec3* u) {
    Vec3* tmp = NULL;
    tmp->initVec(tmp, 0, 0, 0);
    tmp->vecCopy(tmp, u);
    v->setX(tmp->getX() * a->elements[0] + tmp->getY() * a->elements[3] + tmp->getZ() * a -> elements[6]);
    v->setY(tmp->getX() * a->elements[1] + tmp->getY() * a->elements[4] + tmp->getZ() * a -> elements[7]);
    v->setZ(tmp->getX() * a->elements[2] + tmp->getY() * a->elements[5] + tmp->getZ() * a -> elements[8]);
}

//Adds two Matrices together. m can equal a or b.
void Mat3::matSum(Mat3* m, Mat3* a, Mat3* b) {
    for (int i = 0; i < 9; i++) {
        m->elements[i] = a->elements[i] + b->elements[i];
    }
}

void Mat3::matMult(Mat3* m, Mat3* a , Mat3* b) {
    float b00 = b-> elements[0]; float b01 = b->elements[3]; float b02 = b->elements[6];
    float b10 = b-> elements[1]; float b11 = b->elements[4]; float b12 = b->elements[7];
    float b20 = b-> elements[2]; float b21 = b->elements[5]; float b22 = b->elements[8];
    
    for (int i = 0; i < 3; i++) {
        m->elements[i] = a->elements[0 + i] * b00 + a->elements[3 + i] * b10 + a->elements[6 + i] * b20;
        m->elements[i + 3] = a->elements[0 + i] * b01 + a->elements[3 + i] * b11 + a->elements[6 + i] * b21;
        m->elements[i + 6] = a->elements[0 + i] * b02 + a->elements[3 + i] * b12 + a->elements[6 + i] * b22;
    }
}

float Mat3::matDeterminant(Mat3* m) {
    float d;
    
    d = m->elements[0] * ((m->elements[4] * m->elements[8]) - (m->elements[7] * m->elements[5])) + m->elements[3] * ((m->elements[7] * m->elements[2]) - (m->elements[1] * m->elements[8])) + m -> elements[6] * ((m -> elements[1] * m -> elements[5]) - (m -> elements[4] * m -> elements[2]));
    
    return d;
}

void Mat3::matTranspose(Mat3* t, Mat3* m) {
    float m00 = m -> elements[0]; float m01 = m -> elements[3]; float m02 = m -> elements[6];
    float m10 = m -> elements[1]; float m11 = m -> elements[4]; float m12 = m -> elements[7];
    float m20 = m -> elements[2]; float m21 = m -> elements[5]; float m22 = m -> elements[8];
    
    t -> elements[0] = m00; t -> elements[3] = m10; t -> elements[6] = m20;
    t -> elements[1] = m01; t -> elements[4] = m11; t -> elements[7] = m21;
    t -> elements[2] = m02; t -> elements[5] = m12; t -> elements[8] = m22;
}

void Mat3::matAdjoint(Mat3* adjoint, Mat3* m) {
    Mat3 cofactor;
    matCofactor(&cofactor, m);
    matTranspose(adjoint, &cofactor);
    
}

void Mat3::matInverse(Mat3* inverse, Mat3* m) {
    Mat3 adjoint;
    float determinant;
    determinant = matDeterminant(m);
    matAdjoint(&adjoint, m);
}

void Mat3::matCofactor(Mat3* cofactor, Mat3* m) {
    Vec3 row0; Vec3 row1; Vec3 row2;
    Vec3 a; Vec3 b; Vec3 c;
    
    copyRow(&row0, 0, m);
    copyRow(&row1, 1, m);
    copyRow(&row2, 2, m);
    
    a.vecCross(&a, &row1, &row2);
    b.vecCross(&b, &row2, &row0);
    c.vecCross(&c, &row0, &row1);
    
    
    cofactor->elements[0] = a.getX();
    cofactor->elements[3] = a.getY();
    cofactor->elements[6] = a.getZ();
    
    cofactor->elements[1] = b.getX();
    cofactor->elements[4] = b.getY();
    cofactor->elements[7] = b.getZ();
    
    cofactor->elements[2] = c.getX();
    cofactor->elements[5] = c.getY();
    cofactor->elements[8] = c.getZ();
}

bool Mat3::matIsEqual(Mat3*, Mat3*) {
    
    return true;
}

void copyRow(Vec3* v, int row, Mat3* m) {
    v->setX(m->getElement(0 + row));
    v->setY(m->getElement(3 + row));
    v->setZ(m->getElement(6 + row));
}

void Mat3::printMatToFile(Mat3*) {
    ofstream fout;
    fout.open("Matrix.txt");
    fout << "Sample Writing into the text";
    fout.close();
}
