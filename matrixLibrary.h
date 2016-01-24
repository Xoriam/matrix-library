//
//  matrixLibrary.h
//  Matrix Library
//
//  Created by Mario Andrade on 2/19/14.
//  Copyright (c) 2014 Mario Andrade. All rights reserved.
//

#ifndef __Matrix_Library__matrixLibrary__
#define __Matrix_Library__matrixLibrary__

#include <iostream>
#include "VectorLibrary.h"

class Mat3 {
    float elements[9];
    
public:
    
    void initMat(float[]);
    
    float getElement(int);
    
    void matSumScalar(Mat3*, Mat3*, float);
    
    void matMultScalar(Mat3*, Mat3*, float);
    
    void matMultVector(Vec3*, Mat3*, Vec3*);

    void matSum(Mat3*, Mat3*, Mat3*);
    
    void matMult(Mat3*, Mat3*, Mat3*);
    
    float matDeterminant(Mat3*);
    
    void matTranspose(Mat3*, Mat3*);
    
    void matAdjoint(Mat3*, Mat3*);
    
    void matInverse(Mat3*, Mat3*);
    
    void matCofactor(Mat3*, Mat3*);
    
    bool matIsEqual(Mat3*, Mat3*);
    
    void copyRow(Vec3*, int, Mat3*);
    
    void printMatToFile(Mat3*);
    
};

#endif /* defined(__Matrix_Library__matrixLibrary__) */
