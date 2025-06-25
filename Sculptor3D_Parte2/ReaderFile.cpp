#include "ReaderFile.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include "CutBox.h"
#include "CutEllipsoid.h"
#include "CutSphere.h"
#include "CutVoxel.h"
#include "PutBox.h"
#include "PutEllipsoid.h"
#include "PutSphere.h"
#include "PutVoxel.h"
#include "Sculptor.h"


using namespace std;

ReaderFile::ReaderFile()
{
    // construtor
}

vector<FiguraGeometrica *> ReaderFile::readFile(string filename){
    std::vector<FiguraGeometrica*> figuras;

    std::ifstream fin;
    fin.open(filename);

    if(!fin.is_open()){
        exit(0);
    }
    std::string s;

    while(fin.good()){
        fin >> s;
        if(!fin.good())
            break;
        //      std::cout << s << std::endl;
        if(s.compare("dim")==0){
            fin >> dx >> dy >> dz;
        } else if(s.compare("putvoxel")==0){
            int x0,y0,z0;
            fin >> x0 >> y0 >> z0 >> r >> g >> b >> a;
            figuras.push_back(new PutVoxel(x0,y0,z0,r,g,b,a));
        } else if(s.compare("cutvoxel")==0){
            int x0,y0,z0;
            fin >> x0 >> y0 >> z0;
            figuras.push_back(new CutVoxel(x0,y0,z0));
        } else if(s.compare("putbox")==0){
            int x0,y0,z0,x1,y1,z1;
            fin >> x0 >> y0 >> z0 >> x1 >> y1 >> z1 >> r >> g >> b >> a;
            figuras.push_back(new PutBox(x0,y0,z0,x1,y1,z1,r,g,b,a));
        }
        else if(s.compare("cutbox")==0){
            int x0,y0,z0,x1,y1,z1;
            fin >> x0 >> y0 >> z0 >> x1 >> y1 >> z1 ;
            figuras.push_back(new CutBox(x0,y0,z0,x1,y1,z1));
        }
        else if(s.compare("putsphere")==0){
            int xc,yc,zc, radius;
            fin >> xc >> yc >> zc >> radius >> r >> g >> b >> a ;
            figuras.push_back(new PutSphere(xc,yc,zc,radius, r, g, b, a));
        }
        else if(s.compare("cutsphere")==0){
            int xc,yc,zc, radius;
            fin >> xc >> yc >> zc >> radius ;
            figuras.push_back(new CutSphere(xc,yc,zc,radius));
        }
        else if(s.compare("putellipsoid")==0){
            int xc,yc,zc,rx,ry,rz;
            fin >> xc >> yc >> zc >> rx >> ry >> rz >> r >> g >> b >> a;
            figuras.push_back(new PutEllipsoid(xc,yc,zc,rx,ry,rz,r,g,b,a));
        }
        else if(s.compare("cutellipsoid")==0){
            int xc,yc,zc,rx,ry,rz;
            fin >> xc >> yc >> zc >> rx >> ry >> rz >> r >> g >> b >> a;
            figuras.push_back(new CutEllipsoid(xc,yc,zc,rx,ry,rz));
        }
        else{
            fin.close();
            cout << "\nComando desconhecido\n";
            exit(0);
        }
    }
    fin.close();

    return figuras;
}
int ReaderFile::getdx(){
    return dx;
}
int ReaderFile::getdy(){
    return dy;
}
int ReaderFile:: getdz(){
    return dz;
}

