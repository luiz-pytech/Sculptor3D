#ifndef PUTSPHERE_H
#define PUTSPHERE_H

#include "FiguraGeometrica.h"
#include "Sculptor.h"


class PutSphere : public FiguraGeometrica
{
private:
    int xcenter, ycenter,zcenter,radius;
public:
    PutSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a);
    virtual void draw(Sculptor &t);
};

#endif // PUTSPHERE_H
