//Classe que imprime um voxel
#ifndef PUTVOXEL_H
#define PUTVOXEL_H

#include "FiguraGeometrica.h"
#include "Sculptor.h"


class PutVoxel : public FiguraGeometrica
{
private:
    int x0, y0, z0;
public:
    PutVoxel(int x0, int y0, int z0, float r, float g, float b, float a);
    virtual void draw(Sculptor &t);
};

#endif // PUTVOXEL_H
