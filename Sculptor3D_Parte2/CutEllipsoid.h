#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H

#include "FiguraGeometrica.h"
#include "Sculptor.h"


class CutEllipsoid : public FiguraGeometrica
{
private:
    int xcenter,ycenter, zcenter,rx,ry,rz;
public:
    CutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    virtual void draw(Sculptor &t);
};

#endif // CUTELLIPSOID_H
