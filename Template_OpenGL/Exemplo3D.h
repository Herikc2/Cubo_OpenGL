#pragma once
#include <GL/glut.h>  

/*
using vertice = std::pair<double, double>;
using lista_vertices = std::vector<vertice>;
using aresta = std::pair<int, int>;
using lista_arestas = std::vector<aresta>;


struct Poligono3D {
    double tamanhoLado;
    int numLados;
    vertice posicao;
    vertice escala;
    double rotacao;
    lista_vertices vertices;
    lista_arestas arestas;
};

Poligono3D criar_poligono3D(double posicao_x, double posicao_y, double posicao_z, double tamanho_lado, int num_lados) {
    Poligono3D novo_poligono;
    novo_poligono.numLados = num_lados;
    novo_poligono.posicao.first = posicao_x;
    novo_poligono.posicao.second = posicao_y;
    novo_poligono.tamanhoLado = tamanho_lado;

    novo_poligono.escala.first = 1;
    novo_poligono.escala.second = 1;

    novo_poligono.rotacao = 0;

    float angulo = 0;
    float passo_angulo = ((360 / float(num_lados)) * 3.1416) / 180.0;

    float apothem = tamanho_lado / (2 * tan(3.1416 / float(num_lados)));
    posicao_x -= tamanho_lado / 2.0;
    posicao_y -= apothem;

    novo_poligono.vertices.push_back(vertice(posicao_x, posicao_y));
    std::cout << "Vertices:\n";
    std::cout << 0 << " - " << posicao_x << " - " << posicao_y << "\n";

    for (int i = 1; i < num_lados; i++) {
        posicao_x = posicao_x + tamanho_lado * cos(angulo);
        posicao_y = posicao_y + tamanho_lado * sin(angulo);
        novo_poligono.vertices.push_back(vertice(posicao_x, posicao_y));
        std::cout << i << " - " << posicao_x << " - " << posicao_y << "\n";
        angulo += passo_angulo;
    }

    std::cout << "Arestas:\n";
    for (int i = 0; i < num_lados; i++) {
        novo_poligono.arestas.push_back(aresta(i, (i + 1) % num_lados));
        std::cout << i << " - " << (i + 1) % num_lados << "\n";
    }


    return novo_poligono;
}
*/

void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); //Coloca a cor de background para preto e opaco
    glClearDepth(1.0f);                   // Define o buffer de profundidade para o mais distante possível
    glEnable(GL_DEPTH_TEST);   // Habilita o culling de profundidade
    glDepthFunc(GL_LEQUAL);    // Define o tipo de teste de profundidade
}


void display3D() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Limpa o buffer de cor e o de profundidade
    glMatrixMode(GL_MODELVIEW);     //Operar na matriz de ModelView

    // Renderiza um cubo com 6 quads diferentes
    glLoadIdentity();                 // Reseta para a matriz identidade
    glTranslatef(1.5f, 0.0f, -7.0f);  // Move para a direta da view o que será desenhado

    glBegin(GL_QUADS);                // Começa a desenhar o cubo
    // Face de cima (y = 1.0f)
    
    /*
    // Define os vértice em ordem anti-horário com a face apontando para cima
    glColor3f(0.0f, 1.0f, 0.0f);     // Verde

    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);*/

    // Face de baixo (y = -1.0f)
    glColor3f(1.0f, 0.5f, 0.0f);     // Laranja

    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);

    /*
    // Face da frente  (z = 1.0f)
    glColor3f(1.0f, 0.0f, 0.0f);     // Vermelho
    glVertex3f(1.0f, 1.0f, 2.0f);
    glVertex3f(-1.0f, 1.0f, 2.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);*/

    /*
    // Face de trás (z = -1.0f)
    glColor3f(1.0f, 1.0f, 0.0f);     // Amarelo
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);

    // Face esquerda (x = -1.0f)
    glColor3f(0.0f, 0.0f, 1.0f);     // Azul
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);

    // Face direita (x = 1.0f)
    glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);*/
    glEnd();

    glutSwapBuffers();  // Double Buffer, troca o atual pelo que está aguardando
}


//Função de redesenhou prioriza o aspecto da projeção
void reshape(GLsizei width, GLsizei height) {
    if (height == 0) height = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}