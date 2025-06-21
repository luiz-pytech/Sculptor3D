#ifndef READERFILE_H
#define READERFILE_H


#include "FiguraGeometrica.h"
#include <vector>
#include <string>

using namespace std;

class ReaderFile
{
private:
    int dx, dy, dz; // recebe as dimensões x, y e z
    float r, g, b, a; // recebe as cores, nesse caso é necessário pois ele não herda de FiguraGeometrica
public:
    ReaderFile(); // construtor da classe
    virtual ~ReaderFile(){} // destrutor da classe
    vector<FiguraGeometrica *> readFile(string filename); // Analisa o arquivo definido para criar o vetor de Figura Geometrica e gerar o OFF
    int getdx();
    int getdy();
    int getdz();
};

#endif // READERFILE_H
