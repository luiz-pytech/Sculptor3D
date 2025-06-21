#ifndef CUTVOXEL_H
#define CUTVOXEL_H

#include "FiguraGeometrica.h"
#include "Sculptor.h"

class CutVoxel : public FiguraGeometrica
{
private:
    int x0, y0, z0;
public:
    CutVoxel(int x0, int y0, int z0);
    virtual void draw(Sculptor &t);
};
#endif // CUTVOXEL_H
