# 🧊 Sculptor 3D

[![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://isocpp.org/)
[![Status](https://img.shields.io/badge/Status-Concluído-green?style=for-the-badge)]()

**Sculptor 3D** é uma ferramenta de linha de comando desenvolvida em C++ para modelagem tridimensional baseada em voxels. A aplicação interpreta um script de texto para criar esculturas digitais e exportá-las no formato `.OFF`, compatível com visualizadores 3D como MeshLab e Geomview.

---

## 📋 Tabela de Conteúdos

* [Sobre o Projeto](#-sobre-o-projeto)
* [Galeria de Exemplos](#-galeria-de-exemplos)
* [Principais Funcionalidades](#-principais-funcionalidades)
* [Tecnologias Utilizadas](#-tecnologias-utilizadas)
* [Como Compilar e Executar](#-como-compilar-e-executar)
* [Formato do Arquivo de Entrada](#-formato-do-arquivo-de-entrada)
* [Estrutura do Código](#-estrutura-do-código)
* [Agradecimentos](#-agradecimentos)
* [Autor](#-autor)

---

## 📖 Sobre o Projeto

Este projeto foi desenvolvido para a disciplina de **Programação Avançada (DCA3303)** do curso de Engenharia da Computação da UFRN. A proposta é criar uma ferramenta em C++ para realizar **esculturas digitais** em um espaço tridimensional, de forma similar à lógica de blocos do jogo **Minecraft**.

Um arquivo de texto com uma sequência de comandos é utilizado para definir as dimensões da escultura e aplicar primitivas geométricas, como `putVoxel`, `cutVoxel`, `putBox`, `cutSphere`, entre outras. O programa processa essas instruções e gera um arquivo de saída no formato `.OFF`.

---

## 🎨 Galeria de Exemplos

A criatividade é o essencial para criar qualquer coisa nesse projeto. Abaixo, um exemplo de um boneco de neve inspirado no Olaf, da animação Frozen.

![Boneco de neve feito com voxels](snapshot01.png)

---

## ✨ Principais Funcionalidades

-   Criação de uma matriz 3D de voxels com dimensões personalizadas.
-   Escultura aditiva (`put`) e subtrativa (`cut`) de voxels.
-   Uso de primitivas geométricas como Voxel, Box, Sphere e Ellipsoid.
-   Definição de cores (RGBA) para cada primitiva aplicada.
-   Interpretação de scripts a partir de um arquivo de texto.
-   Exportação do modelo 3D final no formato `.OFF`.

---

## 🛠️ Tecnologias Utilizadas

* **C++:** Linguagem de programação principal para a lógica e manipulação de dados.
* **Make/g++:** Sistema de build para compilação do código-fonte.

---

## 🚀 Como Compilar e Executar

Siga os passos abaixo para compilar e executar o projeto em um ambiente Linux ou similar com g++.

### Pré-requisitos

* Compilador C++ (g++)
* Git (para clonar o repositório)

### Passos

1.  **Clone o repositório:**
    ```sh
    git clone [https://github.com/luiz-pytech/Sculptor3D.git](https://github.com/luiz-pytech/Sculptor3D.git)
    ```

2.  **Navegue até o diretório do projeto:**
    ```sh
    cd Sculptor3D
    ```

3.  **Compile o código-fonte:**
    Utilize o `g++` para compilar os arquivos do projeto e gerar o executável.
    ```sh
    g++ main.cpp sculptor.cpp -o sculptor
    ```

4.  **Crie um arquivo de script:**
    Crie um arquivo de texto (ex: `meu_desenho.txt`) com os comandos de escultura. Veja a seção [Formato do Arquivo de Entrada](#-formato-do-arquivo-de-entrada) para mais detalhes.

5.  **Execute o programa:**
    Passe o arquivo de script como argumento de entrada e defina um nome para o arquivo de saída.
    ```sh
    ./sculptor meu_desenho.txt saida.off
    ```

6.  **Visualize o resultado:**
    Abra o arquivo `saida.off` gerado em um visualizador 3D como o **MeshLab** ou **Geomview**.

---

## 📝 Formato do Arquivo de Entrada

O arquivo de script (`.txt`) deve seguir o formato abaixo, onde cada linha representa um comando.

| Comando         | Descrição                                         | Exemplo                                 |
| --------------- | ------------------------------------------------- | --------------------------------------- |
| `dim nx ny nz`  | Define as dimensões do escultor (matriz 3D)       | `dim 30 30 30`                          |
| `color r g b a` | Define a cor atual para os próximos comandos      | `color 1.0 0.5 0.0 1.0`                 |
| `putVoxel x y z`| Desenha um voxel na posição (x,y,z)               | `putVoxel 10 10 10`                     |
| `cutVoxel x y z`| Apaga um voxel na posição (x,y,z)                 | `cutVoxel 15 15 15`                     |
| `putBox...`     | Desenha uma caixa (verificar parâmetros)          | `putBox 0 9 0 9 0 9`                    |
| `cutBox...`     | Apaga uma caixa (verificar parâmetros)            | `cutBox 2 7 2 7 2 7`                    |
| `putSphere...`  | Desenha uma esfera (verificar parâmetros)         | `putSphere 15 15 15 8`                  |
| `cutSphere...`  | Apaga uma esfera (verificar parâmetros)           | `cutSphere 15 15 15 4`                  |
| `putEllipsoid...`| Desenha uma elipsoide (verificar parâmetros)      | `putEllipsoid 15 15 15 8 4 2`           |
| `cutEllipsoid...`| Apaga uma elipsoide (verificar parâmetros)        | `cutEllipsoid 15 15 15 6 3 1`           |

---

## 📂 Estrutura do Código

* **`voxel.h`**: Define a `struct Voxel`, que representa a unidade básica da escultura (cores, transparência e estado).
* **`sculptor.h`**: Arquivo de cabeçalho da classe `Sculptor`, declarando todos os seus métodos e atributos.
* **`sculptor.cpp`**: Implementação dos métodos da classe `Sculptor`, contendo a lógica de manipulação da matriz 3D e exportação.
* **`main.cpp`**: Ponto de entrada do programa. Responsável por ler o arquivo de script, interpretar os comandos e chamar os métodos apropriados da classe `Sculptor`.

---

## 🙏 Agradecimentos

* Agradecimento especial ao professor **Agostinho Brito Jr.** pelas orientações e pelo material de apoio que nortearam o desenvolvimento deste projeto.
    * [Link para o material da disciplina](https://agostinhobritojr.github.io/curso/progav-dca3303/escultor.html)

---

## 👨‍💻 Autor

**Luiz Felipe**
* Graduado em Ciência e Tecnologia - UERN - Natal
* Graduando em Engenharia da Computação – UFRN
