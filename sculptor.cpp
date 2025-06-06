#include "sculptor.h"
#include <iostream>
#include <fstream>

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
    }
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}
void Sculptor::putVoxel(int x, int y, int z){
    if(x < 0 || x >= nx || y < 0 || y >= ny || z < 0 || z >= nz){
        std::cout << "As coordenadas passadas sao invalidas " << std::endl;
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
        std::cout << "As coordenadas passadas sao invalidas " << std::endl;
        exit(0);
    }

    // Se a coordenada for válida apago o voxel.
    v[x][y][z].show = false;

}
void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for (int i = x0; i < x1; ++i) {
        for (int j = y0; j < y1; ++j) {
            for (int k = z0; k < z1; ++k) {
                putVoxel(i, j, k);
            }
        }
    }

}
void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for (int i = x0; i < x1; ++i) {
        for (int j = y0; j < y1; ++j) {
            for (int k = z0; k < z1; ++k) {
                cutVoxel(i, j, k);
            }
        }
    }
}
void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
    for (int i = xcenter - radius; i <= xcenter + radius; ++i) {
        for (int j = ycenter - radius; j <= ycenter + radius; ++j) {
            for (int k = zcenter - radius; k <= zcenter + radius; ++k) {
                // verificando equação da esfera
                // (x - xc)^2 + (y - yc)^2 + (z - zc)^2 <= radius^2
                if((i - xcenter)*(i - xcenter) + (j - ycenter)*(j - ycenter) + (k - zcenter)*(k - zcenter) <= radius * radius){
                    putVoxel(i, j, k);
                }
            }
        }
    }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
    for (int i = xcenter - radius; i <= xcenter + radius; ++i) {
        for (int j = ycenter - radius; j <= ycenter + radius; ++j) {
            for (int k = zcenter - radius; k <= zcenter + radius; ++k) {
                // verificando equação da esfera
                // (x - xc)^2 + (y - yc)^2 + (z - zc)^2 <= radius^2
                if((i - xcenter)*(i - xcenter) + (j - ycenter)*(j - ycenter) + (k - zcenter)*(k - zcenter) <= radius * radius){
                    cutVoxel(i, j, k);
                }
            }
        }
    }
}
void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    if(rx == 0 || ry == 0 || rz == 0){
        std::cout << "Raios invalidos para formacao do elipsoide" << std::endl;
        exit(0);
    }

    for (int i = xcenter - rx; i <= xcenter + rx; ++i) {
        for (int j = ycenter - ry; j <= ycenter + ry; ++j) {
            for (int k = zcenter - rz; k <= zcenter + rz; ++k) {
                // verificando equação do elipsoide
                // (x - xc)^2/rx^2 + (y - yc)^2/ry^2 + (z - zc)^2/rz^2 <= 1

                // Calculando as diferenças
                int difX = i - xcenter;
                int difY = j - ycenter;
                int difZ = k - zcenter;
                if((float)(difX * difX)/(rx*rx) + (float)(difY * difY)/(ry*ry) + (float)(difZ * difZ)/(rz*rz) <= 1){
                    putVoxel(i, j, k);
                }
            }
        }
    }

}
void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    if(rx == 0 || ry == 0 || rz == 0){
        std::cout << "Raios invalidos para formacao do elipsoide" << std::endl;
        exit(0);
    }

    for (int i = xcenter - rx; i <= xcenter + rx; ++i) {
        for (int j = ycenter - ry; j <= ycenter + ry; ++j) {
            for (int k = zcenter - rz; k <= zcenter + rz; ++k) {
                // verificando equação do elipsoide
                // (x - xc)^2/rx^2 + (y - yc)^2/ry^2 + (z - zc)^2/rz^2 <= 1

                // Calculando as diferenças
                int difX = i - xcenter;
                int difY = j - ycenter;
                int difZ = k - zcenter;
                if((difX * difX)/(rx*rx) + (difY * difY)/(ry*ry) + (difZ * difZ)/(rz*rz) <= 1.0f){
                    cutVoxel(i, j, k);
                }
            }
        }
    }
}
void Sculptor::writeOFF(const char* filename){
    std::ofstream fout;
    int nvoxels = 0; // contar a quantidade de voxels visíveis

    fout.open(filename);
    if (!fout.is_open()) {
        exit(1);
    }
    fout << "COFF\n";

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
