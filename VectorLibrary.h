//
//  VectorLibrary.h
//  Matrix Library
//
//  Created by Mario Andrade on 4/15/14.
//  Copyright (c) 2014 Mario Andrade. All rights reserved.
//

#ifndef __Matrix_Library__VectorLibrary__
#define __Matrix_Library__VectorLibrary__

#include <iostream>

class Vec3 {
    float x, y, z;
    
public:
    float getX();
    
    float getY();
    
    float getZ();
    
    void setX(float);
    
    void setY(float);
    
    void setZ(float);
    
    void initVec(Vec3*, float, float, float);
    
    void vecAdd(Vec3*, Vec3*, Vec3*);
    
    float vecDot(Vec3*, Vec3*);
    
    void vecCross(Vec3*, Vec3*, Vec3*);
    
    void vecCopy (Vec3*, Vec3*);
};
#endif /* defined(__Matrix_Library__VectorLibrary__) */
