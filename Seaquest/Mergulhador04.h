#pragma once

#include "Informacoes.h"
#include "Resgates.h"

float posXmergulhador04 = (janelaLargura / 2) + 30;
float posYmergulhador04 = (janelaAltura / 2) - 260;
int velocidadeMergulhador04 = 10;
bool nadarMergulhador04 = false;

float mergulhador04vertice01[] = { (posXmergulhador04 - 10.0f), (posYmergulhador04 - 5.0f) };
float mergulhador04vertice02[] = { (posXmergulhador04 - 10.0f), (posYmergulhador04 + 5.0f) };
float mergulhador04vertice03[] = { (posXmergulhador04 + 10.0f), (posYmergulhador04 + 5.0f) };
float mergulhador04vertice04[] = { (posXmergulhador04 + 10.0f), (posYmergulhador04 - 5.0f) };

void mergulhador04()
{
    glColor3f(0.5f, 1.0f, 0.5f);
    glBegin(GL_QUADS);
    glVertex2f(mergulhador04vertice01[0], mergulhador04vertice01[1]);
    glVertex2f(mergulhador04vertice02[0], mergulhador04vertice02[1]);
    glVertex2f(mergulhador04vertice03[0], mergulhador04vertice03[1]);
    glVertex2f(mergulhador04vertice04[0], mergulhador04vertice04[1]);
    glEnd();
}

void randomValorMergulhador04()
{
    int valor = rand() % 11;

    if (valor == 3)
    {
        nadarMergulhador04 = true;
    }
}

void animaMergulhador04(int val)
{
    if (!nadarMergulhador04)
    {
        randomValorMergulhador04();
    }
    else
    {
        posXmergulhador04 -= velocidadeMergulhador04;

        mergulhador04vertice01[0] -= velocidadeMergulhador04;
        mergulhador04vertice02[0] -= velocidadeMergulhador04;
        mergulhador04vertice03[0] -= velocidadeMergulhador04;
        mergulhador04vertice04[0] -= velocidadeMergulhador04;

        if (
            (posXmergulhador04 >= (posXsubmarino - raioLarguraSubmarino)) &&
            (posXmergulhador04 <= (posXsubmarino + raioLarguraSubmarino)) &&
            (posYmergulhador04 >= (posYsubmarino - raioAlturaSubmarino)) &&
            (posYmergulhador04 <= (posYsubmarino + raioAlturaSubmarino))
           )
        {
            nadarMergulhador04 = false;
            posXmergulhador04 = (janelaLargura / 2) + 30;
            mostraResgates();

            mergulhador04vertice01[0] = (posXmergulhador04 - 10.0f);
            mergulhador04vertice02[0] = (posXmergulhador04 - 10.0f);
            mergulhador04vertice03[0] = (posXmergulhador04 + 10.0f);
            mergulhador04vertice04[0] = (posXmergulhador04 + 10.0f);
        }

        if (posXmergulhador04 < -(janelaLargura / 2) - 30)
        {
            nadarMergulhador04 = false;
            posXmergulhador04 = (janelaLargura / 2) + 30;

            mergulhador04vertice01[0] = (posXmergulhador04 - 10.0f);
            mergulhador04vertice02[0] = (posXmergulhador04 - 10.0f);
            mergulhador04vertice03[0] = (posXmergulhador04 + 10.0f);
            mergulhador04vertice04[0] = (posXmergulhador04 + 10.0f);
        }
    }

    glutPostRedisplay();
    glutTimerFunc(150, animaMergulhador04, 1);
}

