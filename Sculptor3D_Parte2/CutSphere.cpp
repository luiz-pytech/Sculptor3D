#include "CutSphere.h"
#include <iostream>


CutSphere::CutSphere(int xcenter, int ycenter, int zcenter, int radius){
    this ->xcenter = xcenter;
    this -> ycenter = ycenter;
    this ->zcenter = zcenter;
    this ->radius = radius;

}

void CutSphere::draw(Sculptor &t){
    for (int i = xcenter - radius; i <= xcenter + radius; ++i) {
        for (int j = ycenter - radius; j <= ycenter + radius; ++j) {
            for (int k = zcenter - radius; k <= zcenter + radius; ++k) {
                // verificando equação da esfera
                // (x - xc)^2 + (y - yc)^2 + (z - zc)^2 <= radius^2
                if((i - xcenter)*(i - xcenter) + (j - ycenter)*(j - ycenter) + (k - zcenter)*(k - zcenter) <= radius * radius){
                    t.cutVoxel(i, j, k);
                }
            }
        }
    }
}
