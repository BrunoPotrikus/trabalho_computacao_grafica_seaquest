#pragma once

#include "Informacoes.h"

float posXmergulhador02 = -(janelaLargura / 2) - 30;
float posYmergulhador02 = (janelaAltura / 2) - 105;
float velocidadeMergulhador02 = 10.0f;
bool nadarMergulhador02 = false;

float mergulhador02vertice01[] = { (posXmergulhador02 - 10.0f), (posYmergulhador02 - 5.0f) };
float mergulhador02vertice02[] = { (posXmergulhador02 - 10.0f), (posYmergulhador02 + 5.0f) };
float mergulhador02vertice03[] = { (posXmergulhador02 + 10.0f), (posYmergulhador02 + 5.0f) };
float mergulhador02vertice04[] = { (posXmergulhador02 + 10.0f), (posYmergulhador02 - 5.0f) };

void mergulhador02()
{
    glColor3f(0.5f, 1.0f, 0.5f);
    glBegin(GL_QUADS);
    glVertex2f(mergulhador02vertice01[0], mergulhador02vertice01[1]);
    glVertex2f(mergulhador02vertice02[0], mergulhador02vertice02[1]);
    glVertex2f(mergulhador02vertice03[0], mergulhador02vertice03[1]);
    glVertex2f(mergulhador02vertice04[0], mergulhador02vertice04[1]);
    glEnd();
}

void randomValorMergulhador02()
{
    int valor = rand() % 11;

    if (valor == 3)
    {
        nadarMergulhador02 = true;
    }
}

void animaMergulhador02(int val)
{
    if (!nadarMergulhador02)
    {
        randomValorMergulhador02();
    }
    else
    {
        posXmergulhador02 += velocidadeMergulhador02;

        mergulhador02vertice01[0] += velocidadeMergulhador02;
        mergulhador02vertice02[0] += velocidadeMergulhador02;
        mergulhador02vertice03[0] += velocidadeMergulhador02;
        mergulhador02vertice04[0] += velocidadeMergulhador02;

        if (
            (posXmergulhador02 >= (posXsubmarino - raioLarguraSubmarino)) &&
            (posXmergulhador02 <= (posXsubmarino + raioLarguraSubmarino)) &&
            (posYmergulhador02 >= (posYsubmarino - raioAlturaSubmarino)) &&
            (posYmergulhador02 <= (posYsubmarino + raioAlturaSubmarino))
           )
        {
            nadarMergulhador02 = false;
            posXmergulhador02 = -(janelaLargura / 2) - 30;
            mostraResgates();

            mergulhador02vertice01[0] = (posXmergulhador02 - 10.0f);
            mergulhador02vertice02[0] = (posXmergulhador02 - 10.0f);
            mergulhador02vertice03[0] = (posXmergulhador02 + 10.0f);
            mergulhador02vertice04[0] = (posXmergulhador02 + 10.0f);
        }

        if (posXmergulhador02 > (janelaLargura / 2) + 30)
        {
            nadarMergulhador02 = false;
            posXmergulhador02 = -(janelaLargura / 2) - 30;

            mergulhador02vertice01[0] = (posXmergulhador02 - 10.0f);
            mergulhador02vertice02[0] = (posXmergulhador02 - 10.0f);
            mergulhador02vertice03[0] = (posXmergulhador02 + 10.0f);
            mergulhador02vertice04[0] = (posXmergulhador02 + 10.0f);
        }
    }

    glutPostRedisplay();
    glutTimerFunc(150, animaMergulhador02, 1);
}

