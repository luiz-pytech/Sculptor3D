#ifndef CUTBOX_H
#define CUTBOX_H

#include "FiguraGeometrica.h"
#include "Sculptor.h"


class CutBox : public FiguraGeometrica
{
private:
    int x0, y0, z0, x1, y1, z1;
public:
    CutBox(int x0, int y0, int z0, int x1, int y1, int z1);
    virtual void draw(Sculptor &t);
};

#endif // CUTBOX_H
