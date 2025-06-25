# 🧊 Sculptor 3D - Parte 2

Sculptor é um projeto de construção 3D baseado em voxels, inspirado no estilo do jogo Minecraft.

---

## 📌 Sobre a Parte 2

Esta segunda parte do projeto reestrutura o Sculptor utilizando **herança** e **polimorfismo**, tornando o código mais **modular** e **extensível** para futuras funcionalidades.

---

## 🧱 Desenhos com Classes

Cada classe de figura geométrica (`PutBox`, `CutSphere`, etc.) sabe como se desenhar no objeto `Sculptor`.

A classe base `FiguraGeometrica` possui o método **virtual puro** `draw()`, que obriga todas as classes derivadas a implementarem seu próprio comportamento.  
Isso permite usar **polimorfismo** para desenhar diferentes formas de maneira uniforme.

---

## 📂 Entrada Genérica

A construção dos voxels é feita a partir de um **arquivo de texto de entrada**, como `olaf.txt`, contendo comandos com coordenadas e parâmetros de desenho.

### 📝 Exemplo de entrada:
```
dim 50 50 50
putbox 10 20 10 20 10 20 1 0 0 1
putsphere 25 25 25 5 0 1 0 1
cutvoxel 12 15 18
```
## 👀 Visualização
- Geomview
- MeshLab

## 👨‍💻 Autor

**Luiz Felipe**  
Graduado em Ciência e Tecnologia - UERN - NATAL\
Graduando em Engenharia da Computação – UFRN

