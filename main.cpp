#include <iostream>
#include "sculptor.h"

int main(){
    Sculptor escultura(20, 20, 20);  // Criando uma escultura de 20x20x20

    // Definindo cor para o cubo (vermelho)
    escultura.setColor(1.0, 0.0, 0.0, 1.0);
    // Criando um cubo "cheio"
    escultura.putBox(5, 15, 5, 15, 5, 15);
    // Cortando o interior para deixar o cubo "oco"
    escultura.cutBox(7, 13, 7, 13, 7, 13);

    // Definindo cor para a esfera (azul)
    escultura.setColor(0.0, 0.0, 1.0, 1.0);
    // Criando uma esfera no centro do cubo
    escultura.putSphere(10, 10, 10, 3);

    // Exportando o arquivo para visualizar
    escultura.writeOFF("escultura.off");

    return 0;


}
