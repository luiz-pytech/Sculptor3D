#include "sculptor.h"
#include <cstdlib>

int main() {

    Sculptor olaf(120,120,120); // Criando o armazenamento para o olaf


    olaf.setColor(1,1,1,1); // branco

    // cabeça
    olaf.putSphere(60,90,60,10);

    // ---- CACHECOL ----
    olaf.setColor(1, 0, 0, 1); // Vermelho
    olaf.putEllipsoid(60, 80, 60, 15, 5, 15);

    olaf.setColor(1,1,1,1); // branco

    // corpo superior
    olaf.putSphere(60,70,60,15);

    // corpo inferior
    olaf.putSphere(60,40,60,20);

    // --- Pés ---
    // Pé esquerdo
    olaf.putEllipsoid(50, 20, 55, 8, 5, 8);
    // Pé direito
    olaf.putEllipsoid(70, 20, 55, 8, 5, 8);


    // -------- detalhes -------
    // nariz
    olaf.setColor(1, 0.647, 0, 1);
    olaf.putEllipsoid(60,90,50, 2, 2, 8);

    // detalhes do corpo
    olaf.setColor(0,0,0,1);
    olaf.putEllipsoid(60,70,45, 3, 4, 3); // detalhe do corpo superior

    olaf.putEllipsoid(60,48,42, 3, 4, 3); // detalhe do corpo inferior
    olaf.putEllipsoid(60,32,42, 3, 4, 3); // detalhe do corpo inferior

    // olhos
    olaf.putSphere(55, 92, 53, 2); // Olho esquerdo
    olaf.putSphere(65, 92, 53, 2); // Olho direito

    // Sorriso (3 pequenas esferas)
    olaf.setColor(0,0,0,1);  // preto para o sorriso
    olaf.putSphere(56, 87, 55, 3);  // esquerda
    olaf.putSphere(59, 86, 55, 3);  // centro
    olaf.putSphere(64, 87, 55, 3);  // direita

    // ---- CABELO ----
    olaf.setColor(0.5, 0.3, 0.1, 1); // Marrom

    for(int i = 0; i < 5; i++) {
        olaf.putVoxel(60+i, 100+i, 60); // Diagonal direita
        olaf.putVoxel(60-i, 100+i, 60); // Diagonal esquerda
    }
    for(int i = 0; i < 8; i++) {
        olaf.putVoxel(60, 100+i, 60);
    }
    // ---- BRAÇOS ----
    olaf.putBox(40,45,70,70,60,60);
    for(int i = 0; i < 15; i++) {
        olaf.putVoxel(40, 70+i, 60);
    }
    olaf.putBox(75,80,70,70,60,60);
    for(int i = 0; i < 15; i++) {
        olaf.putVoxel(80, 70+i, 60);
    }

    // ---- SOBRANCELHA ----
    olaf.putVoxel(53, 96, 54);
    olaf.putVoxel(54, 96, 54);
    olaf.putVoxel(55, 96, 54);
    olaf.putVoxel(56, 96, 54);
    olaf.putVoxel(67, 96, 54);
    olaf.putVoxel(66, 96, 54);
    olaf.putVoxel(65, 96, 54);
    olaf.putVoxel(64, 96, 54);


    olaf.setColor(1,0,0,1);
    olaf.putEllipsoid(50,75,50, 2, 8, 3);

    for (int i = 0; i < 200; ++i) {
        int v1 = rand() % 120;
        int v2 = rand() % 120;
        int v3 = rand() % 120;
        olaf.setColor(1,1,1,0.2);
        olaf.putVoxel(v1,v2,v3);
    }

    olaf.putSphere(-1, 5, 8, 7);

    olaf.writeOFF("Olaf.off");
    return 0;
}
