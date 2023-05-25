#pragma once

#include "Informacoes.h"
#include "Resgates.h"

float posXmergulhador01 = (janelaLargura / 2) + 30;
float posYmergulhador01 = (janelaAltura / 2) - 210;
int velocidadeMergulhador01 = 10;
bool nadarMergulhador01 = false;

float mergulhador01vertice01[] = { (posXmergulhador01 - 10.0f), (posYmergulhador01 - 5.0f) };
float mergulhador01vertice02[] = { (posXmergulhador01 - 10.0f), (posYmergulhador01 + 5.0f) };
float mergulhador01vertice03[] = { (posXmergulhador01 + 10.0f), (posYmergulhador01 + 5.0f) };
float mergulhador01vertice04[] = { (posXmergulhador01 + 10.0f), (posYmergulhador01 - 5.0f) };

void mergulhador01()
{
    glColor3f(0.5f, 1.0f, 0.5f);
    glBegin(GL_QUADS);
    glVertex2f(mergulhador01vertice01[0], mergulhador01vertice01[1]);
    glVertex2f(mergulhador01vertice02[0], mergulhador01vertice02[1]);
    glVertex2f(mergulhador01vertice03[0], mergulhador01vertice03[1]);
    glVertex2f(mergulhador01vertice04[0], mergulhador01vertice04[1]);
    glEnd();
}

void randomValorMergulhador01()
{
    int valor = rand() % 11;

    if (valor == 3)
    {
        nadarMergulhador01 = true;
    }
}

void animaMergulhador01(int val)
{
    if (!nadarMergulhador01)
    {
        randomValorMergulhador01();
    }
    else
    {
        posXmergulhador01 -= velocidadeMergulhador01;

        mergulhador01vertice01[0] -= velocidadeMergulhador01;
        mergulhador01vertice02[0] -= velocidadeMergulhador01;
        mergulhador01vertice03[0] -= velocidadeMergulhador01;
        mergulhador01vertice04[0] -= velocidadeMergulhador01;

        if (
            (posXmergulhador01 >= (posXsubmarino - raioLarguraSubmarino)) &&
            (posXmergulhador01 <= (posXsubmarino + raioLarguraSubmarino)) &&
            (posYmergulhador01 >= (posYsubmarino - raioAlturaSubmarino)) &&
            (posYmergulhador01 <= (posYsubmarino + raioAlturaSubmarino))
           )
        {
            nadarMergulhador01 = false;
            posXmergulhador01 = (janelaLargura / 2) + 30;
            mostraResgates();

            mergulhador01vertice01[0] = (posXmergulhador01 - 10.0f);
            mergulhador01vertice02[0] = (posXmergulhador01 - 10.0f);
            mergulhador01vertice03[0] = (posXmergulhador01 + 10.0f);
            mergulhador01vertice04[0] = (posXmergulhador01 + 10.0f);
        }

        if (posXmergulhador01 < -(janelaLargura / 2) - 30)
        {
            nadarMergulhador01 = false;
            posXmergulhador01 = (janelaLargura / 2) + 30;

            mergulhador01vertice01[0] = (posXmergulhador01 - 10.0f);
            mergulhador01vertice02[0] = (posXmergulhador01 - 10.0f);
            mergulhador01vertice03[0] = (posXmergulhador01 + 10.0f);
            mergulhador01vertice04[0] = (posXmergulhador01 + 10.0f);
        }
    }

    glutPostRedisplay();
    glutTimerFunc(150, animaMergulhador01, 1);
}

