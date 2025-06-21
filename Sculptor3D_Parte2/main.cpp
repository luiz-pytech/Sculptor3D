#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include "ReaderFile.h"
#include "FiguraGeometrica.h"
#include "Sculptor.h"
int main()
{
    Sculptor *pfig;
    ReaderFile rf;
    vector<FiguraGeometrica*> figuras;

    figuras = rf.readFile("C:/Users/lf060/Documents/olaf.txt");

    pfig = new Sculptor(rf.getdx(),rf.getdy(), rf.getdz());

    for (auto figs : figuras) {
        figs -> draw(*pfig);
    }

    pfig ->writeOFF("C:/Users/lf060/Documents/olaf.off");

    for (auto figs : figuras) {
        delete figs;
    }

    delete pfig;

    return 0;
}
