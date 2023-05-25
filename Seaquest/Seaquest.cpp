#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include <random>
#include "Submarino.h"
#include "Oxigenio.h"
#include "Torpedo.h"
#include "Informacoes.h"
#include "Tubarao01.h"
#include "Tubarao02.h"
#include "Tubarao03.h"
#include "Tubarao04.h"
#include "Mergulhador01.h"
#include "Mergulhador02.h"
#include "Mergulhador03.h"
#include "Mergulhador04.h"
#include "Vidas.h"
#include "Resgates.h"

using namespace std;

void ceu()
{
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(-300.0f, 200.0f);
    glVertex2f(300.0f, 200.0f);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(300.0f, 120.0f);
    glVertex2f(-300.0f, 120.0f);
    glEnd();
}

void desenhar()
{
    glPushMatrix();

    ceu();
    barraOxigenio();

    glPopMatrix();
    glPushMatrix();

    submarino();

    glPopMatrix();
    glPushMatrix();

    torpedo();

    glPopMatrix();
    glPushMatrix();

    tubarao01();
    tubarao02();
    tubarao03();
    tubarao04();

    mergulhador01();
    mergulhador02();
    mergulhador03();
    mergulhador04();

    vida01();

    glPopMatrix();
    glPushMatrix();

    vida02();

    glPopMatrix();
    glPushMatrix();

    vida03();

    glPopMatrix();
    glPushMatrix();

    resgate01();

    glPopMatrix();
    glPushMatrix();

    resgate02();

    glPopMatrix();
    glPushMatrix();

    resgate03();

    glPopMatrix();
    glPushMatrix();

    resgate04();

    glPopMatrix();
    glPushMatrix();

    resgate05();

    if (!temVida03 || oxigenio <= -100.0f)
    {
        glClearColor(1.0, 0.0, 0.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    if (resgatados == 5)
    {
        glClearColor(1.0, 1.0, 1.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);
    }
}

void display()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClearColor(0.0, 0.0, 1.0, 1.0);

    glClear(GL_COLOR_BUFFER_BIT);

    glTranslatef(janelaLargura / 2, janelaAltura / 2, 0.0f);

    glViewport(0, 0, janelaLargura, janelaAltura);

    desenhar();

    glFlush();
}

void tela(GLsizei w, GLsizei h)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0, janelaLargura, 0, janelaAltura);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char tecla, int x, int y)
{
    switch (tecla)
    {
    case 'd':

        direita = true;

        if (posXsubmarino < ((janelaLargura / 2) - raioLarguraSubmarino))
        {
            posXsubmarino += velocidadeSubmarino;

            torpedoVertice01[0] += velocidadeSubmarino;
            torpedoVertice02[0] += velocidadeSubmarino;
            torpedoVertice03[0] += velocidadeSubmarino;
            torpedoVertice04[0] += velocidadeSubmarino;
        }
        else
        {
            posXsubmarino += 0;
        }
        break;

    case 'a':

        direita = false;

        if (posXsubmarino > (-(janelaLargura / 2) + raioLarguraSubmarino))
        {
            posXsubmarino -= velocidadeSubmarino;

            torpedoVertice01[0] -= velocidadeSubmarino;
            torpedoVertice02[0] -= velocidadeSubmarino;
            torpedoVertice03[0] -= velocidadeSubmarino;
            torpedoVertice04[0] -= velocidadeSubmarino;
        }
        else
        {
            posXsubmarino -= 0;
        }
        break;

    case 'w':
        if (posYsubmarino < 120)
        {
            posYsubmarino += velocidadeSubmarino;

            torpedoVertice01[1] += velocidadeSubmarino;
            torpedoVertice02[1] += velocidadeSubmarino;
            torpedoVertice03[1] += velocidadeSubmarino;
            torpedoVertice04[1] += velocidadeSubmarino;
        }
        else
        {
            posYsubmarino += 0;
        }
        break;

    case 's':
        if (posYsubmarino > (-120 + raioAlturaSubmarino))
        {
            posYsubmarino -= velocidadeSubmarino;

            torpedoVertice01[1] -= velocidadeSubmarino;
            torpedoVertice02[1] -= velocidadeSubmarino;
            torpedoVertice03[1] -= velocidadeSubmarino;
            torpedoVertice04[1] -= velocidadeSubmarino;
        }
        else
        {
            posYsubmarino -= 0;
        }
        break;

    case 't':
        if (!atirou)
        {
            atirou = true;
        }
        break;

    default:
        break;
    }

    cout << "Valor posicao X: " << posXsubmarino << endl;
    cout << "Valor posicao Y: " << posYsubmarino << endl;
    cout << "Valor posicao Torpedo: " << "x: " << posXtorpedo << " " << "y: " << posYtorpedo << endl;

    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(janelaLargura, janelaAltura);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Seaquest");

    glutKeyboardFunc(&keyboard);
    glutReshapeFunc(tela);
    glutDisplayFunc(display);
    glutTimerFunc(150, mudaOxigenio, 1);
    glutTimerFunc(30, disparaTorpedo, 0);
    glutTimerFunc(150, animaTubarao01, 0);
    glutTimerFunc(150, animaTubarao02, 1);
    glutTimerFunc(150, animaTubarao03, 1);
    glutTimerFunc(150, animaTubarao04, 1);
    glutTimerFunc(150, animaMergulhador01, 1);
    glutTimerFunc(150, animaMergulhador02, 1);
    glutTimerFunc(150, animaMergulhador03, 1);
    glutTimerFunc(150, animaMergulhador04, 1);
    glutMainLoop();

    return 0;
}