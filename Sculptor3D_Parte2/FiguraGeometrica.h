#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H
#include "Sculptor.h"

class FiguraGeometrica{
protected:
    float r, g, b, a;
public:
    FiguraGeometrica();

    // destrutor virtual: invoca-se o destrutor da subclasse
    virtual ~FiguraGeometrica();

    // funcao virtual: invoca-se a funcao da subclasse
    // funcao virtual PURA
    virtual void draw(Sculptor &t) = 0; // essa função força a classe mae chamar essa funcao da subclasse: significa que cada subclasse sabe se desenhar especificamente
};

#endif // FIGURAGEOMETRICA_H
