#include "Sculptor.h"
#include <iostream>
#include <fstream>
#include <iomanip>

Sculptor::Sculptor(int _nx, int _ny, int _nz){
    if(_nx <= 0 || _ny <= 0 || _nz <= 0){
        std:: cout << "Dimensoes inválidas para alocação" << std::endl;
        exit(0);
    }

    nx = _nx;
    ny = _ny;
    nz = _nz;

    // alocando memória dinamicamente

    v = new Voxel **[nx];
    for (int i = 0; i < nx; ++i) {
        v[i] = new Voxel *[ny];
        for (int j = 0; j < ny; ++j) {
            v[i][j] = new Voxel [nz];
        }
    }

    // Inicializando todas os voxels como false

    for (int i = 0; i < nx; ++i) {
        for (int j = 0; j < ny; ++j) {
            for (int k = 0; k < nz; ++k) {
                v[i][j][k].show = false;
            }
        }
    }
}

Sculptor::~Sculptor(){
    for (int i = 0; i < nx; ++i) {
        for (int j = 0; j < ny; ++j) {
            delete [] v[i][j];
        }
        delete [] v[i];
    }

    delete [] v;
}

void Sculptor::setColor(float r, float g, float b, float a){
    if(r < 0 || g < 0 || b < 0 || a < 0){
        std::cout << "Parametros RGBA invalido" << std::endl;
        exit(0);
    }
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}
void Sculptor::putVoxel(int x, int y, int z){
    if(x < 0 || x >= nx || y < 0 || y >= ny || z < 0 || z >= nz){
        std::cout << "As coordenadas passadas  para put voxel sao invalidas " << std::endl;
        exit(0);
    }

    // Se a coordenada for válida mostro o voxel e aplico a cor.
    v[x][y][z].show = true;
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
}
void Sculptor::cutVoxel(int x, int y, int z){
    if(x < 0 || x >= nx || y < 0 || y >= ny || z < 0 || z >= nz){
        std::cout << "As coordenadas passadas para cut voxel sao invalidas " << std::endl;
        exit(0);
    }

    // Se a coordenada for válida apago o voxel.
    v[x][y][z].show = false;

}

void Sculptor::writeOFF(const char* filename){
    std::ofstream fout;
    int nvoxels = 0; // contar a quantidade de voxels visíveis

    fout.open(filename);
    if (!fout.is_open()) {
        exit(1);
    }
    fout << "OFF\n";

    for (int i = 0; i < nx; ++i) {
        for (int j = 0; j < ny; ++j) {
            for (int k = 0; k < nz; ++k) {
                if(v[i][j][k].show == true){
                    nvoxels++;
                }
            }
        }
    }

    fout << nvoxels * 8 << " " << nvoxels * 6 << " 0\n"; // Escrevendo quantidade vertíces, faces e arestas

    // Escrevendo os pontos do VOXEL
    for (int i = 0; i < nx; ++i) {
        for (int j = 0; j < ny; ++j) {
            for (int k = 0; k < nz; ++k) {
                if(v[i][j][k].show == true){
                    fout << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << std::endl;
                    fout << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << std::endl;
                    fout << i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << std::endl;
                    fout << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << std::endl;
                    fout << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << std::endl;
                    fout << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << std::endl;
                    fout << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << std::endl;
                    fout << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << std::endl;
                    // Pontos do VOXEL
                }
            }
        }
    }

    // escrever as faces
    int proximo_voxel = 0;
    fout << std::fixed;
    fout <<std::setprecision(1);

    for (int i = 0; i < nx; ++i) {
        for (int j = 0; j < ny; ++j) {
            for (int k = 0; k < nz; ++k) {
                if(v[i][j][k].show == true){
                    fout << "4 " << 0 + proximo_voxel << " " << 3 + proximo_voxel << " " <<
                        2 + proximo_voxel << " " << 1 + proximo_voxel << " "<<v[i][j][k].r <<
                        " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;

                    fout << "4 " << 4 + proximo_voxel << " " << 5 + proximo_voxel << " " <<
                        6 + proximo_voxel << " " << 7 + proximo_voxel << " "<<v[i][j][k].r <<
                        " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;

                    fout << "4 " << 0 + proximo_voxel << " " << 1 + proximo_voxel << " " <<
                        5 + proximo_voxel << " " << 4 + proximo_voxel <<" "<< v[i][j][k].r <<
                        " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;

                    fout << "4 " << 0 + proximo_voxel << " " << 4 + proximo_voxel << " " <<
                        7 + proximo_voxel << " " << 3 + proximo_voxel <<" "<< v[i][j][k].r <<
                        " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;

                    fout << "4 " << 3 + proximo_voxel << " " << 7 + proximo_voxel << " " <<
                        6 + proximo_voxel << " " << 2 + proximo_voxel <<" "<< v[i][j][k].r << " "
                         << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;

                    fout << "4 " << 1 + proximo_voxel << " " << 2 + proximo_voxel << " " <<
                        6 + proximo_voxel << " " << 5 + proximo_voxel <<" "<< v[i][j][k].r << " "
                         << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;

                    proximo_voxel = proximo_voxel + 8;
                }
            }
        }
    }

    std::cout << "Arquivo " << filename << " salvo com sucesso!" << std::endl;
    fout.close();

}
