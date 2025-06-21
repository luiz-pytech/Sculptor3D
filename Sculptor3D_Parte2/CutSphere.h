#ifndef CUTSPHERE_H
#define CUTSPHERE_H

#include "FiguraGeometrica.h"
#include "Sculptor.h"


class CutSphere : public FiguraGeometrica
{
private:
    int xcenter, ycenter,zcenter,radius;
public:
    CutSphere(int xcenter, int ycenter, int zcenter, int radius);
    virtual void draw(Sculptor &t);
};

#endif // CUTSPHERE_H
