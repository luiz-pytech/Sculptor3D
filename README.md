# 🧊 Sculptor 3D

**Sculptor 3D** é um projeto em C++ para modelagem tridimensional com voxels (cubos unitários). O sistema permite a criação, edição e exportação de modelos 3D em formato `.OFF`.



## 🎯 Objetivo do Projeto

Este projeto foi desenvolvido com base nas orientações do professor **Agostinho Brito Jr.** na disciplina de PROGRAMAÇÃO AVANÇADA do curso de engenharia da computação, disponíveis no link:

🔗 [https://agostinhobritojr.github.io/curso/progav-dca3303/escultor.html](https://agostinhobritojr.github.io/curso/progav-dca3303/escultor.html)

O objetivo é construir uma ferramenta em C++ para realizar **esculturas digitais** em blocos tridimensionais, representados por matrizes, seguindo uma lógica semelhante ao jogo **Minecraft**.

A proposta é permitir que o usuário defina uma sequência de comandos em um **arquivo de texto simples** com instruções para:

- Especificar dimensões e propriedades da matriz 3D.
- Aplicar cores e transparência a cada voxel.
- Esculpir formas com comandos como `putVoxel`, `cutVoxel`, `putBox`, `cutSphere`, entre outros.

Essas instruções são interpretadas pela ferramenta, que constrói internamente uma estrutura tridimensional e exporta o modelo final em **formato `.OFF`**, compatível com programas como [Geomview](http://www.geomview.org/) ou [MeshLAB](https://apps.microsoft.com/detail/9N4TL5DXC6C0?hl=neutral&gl=BR&ocid=pdpshare).

## 📦 Funcionalidades

- Criação de uma grade 3D de voxels com dimensões personalizadas.
- Ativação (`put`) e desativação (`cut`) de voxels individuais ou em regiões.
- Definição de cores e transparência para cada voxel.
- Exportação do modelo 3D em formato `.OFF`.
- Interface orientada a objetos com possibilidade de extensão futura.

## 🧩 Estrutura Modular

O projeto é dividido em dois módulos principais:

1. **Classe C++ (`Sculptor`)**  
   Responsável por interpretar os comandos e manipular a matriz 3D de voxels.

2. **Ferramenta Visual (em desenvolvimento)**  
   Uma futura extensão equivalente a um “paint 3D”, com interface gráfica para desenho manual.



