#include "CutEllipsoid.h"
#include <iostream>


CutEllipsoid:: CutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    this ->xcenter = xcenter;
    this -> ycenter = ycenter;
    this ->zcenter = zcenter;
    this-> rx = rx;
    this-> ry = ry;
    this-> rz = rz;
}

 void CutEllipsoid::draw(Sculptor &t){
    for (int i = xcenter - rx; i <= xcenter + rx; ++i) {
        for (int j = ycenter - ry; j <= ycenter + ry; ++j) {
            for (int k = zcenter - rz; k <= zcenter + rz; ++k) {
                // verificando equação do elipsoide
                // (x - xc)^2/rx^2 + (y - yc)^2/ry^2 + (z - zc)^2/rz^2 <= 1

                // Calculando as diferenças
                int difX = i - xcenter;
                int difY = j - ycenter;
                int difZ = k - zcenter;
                if((float)(difX * difX)/(rx*rx) + (float)(difY * difY)/(ry*ry) + (float)(difZ * difZ)/(rz*rz) <= 1){
                    t.cutVoxel(i, j, k);
                }
            }
        }
    }
}
