#pragma once

#include "Informacoes.h"

float posXmergulhador03 = -(janelaLargura / 2) - 30;
float posYmergulhador03 = (janelaAltura / 2) - 160;
float velocidadeMergulhador03 = 10.0f;
bool nadarMergulhador03 = false;

float mergulhador03vertice01[] = { (posXmergulhador03 - 10.0f), (posYmergulhador03 - 5.0f) };
float mergulhador03vertice02[] = { (posXmergulhador03 - 10.0f), (posYmergulhador03 + 5.0f) };
float mergulhador03vertice03[] = { (posXmergulhador03 + 10.0f), (posYmergulhador03 + 5.0f) };
float mergulhador03vertice04[] = { (posXmergulhador03 + 10.0f), (posYmergulhador03 - 5.0f) };

void mergulhador03()
{
    glColor3f(0.5f, 1.0f, 0.5f);
    glBegin(GL_QUADS);
    glVertex2f(mergulhador03vertice01[0], mergulhador03vertice01[1]);
    glVertex2f(mergulhador03vertice02[0], mergulhador03vertice02[1]);
    glVertex2f(mergulhador03vertice03[0], mergulhador03vertice03[1]);
    glVertex2f(mergulhador03vertice04[0], mergulhador03vertice04[1]);
    glEnd();
}

void randomValorMergulhador03()
{
    int valor = rand() % 11;

    if (valor == 3)
    {
        nadarMergulhador03 = true;
    }
}

void animaMergulhador03(int val)
{
    if (!nadarMergulhador03)
    {
        randomValorMergulhador03();
    }
    else
    {
        posXmergulhador03 += velocidadeMergulhador03;

        mergulhador03vertice01[0] += velocidadeMergulhador03;
        mergulhador03vertice02[0] += velocidadeMergulhador03;
        mergulhador03vertice03[0] += velocidadeMergulhador03;
        mergulhador03vertice04[0] += velocidadeMergulhador03;

        if (
            (posXmergulhador03 >= (posXsubmarino - raioLarguraSubmarino)) &&
            (posXmergulhador03 <= (posXsubmarino + raioLarguraSubmarino)) &&
            (posYmergulhador03 >= (posYsubmarino - raioAlturaSubmarino)) &&
            (posYmergulhador03 <= (posYsubmarino + raioAlturaSubmarino))
           )
        {
            nadarMergulhador03 = false;
            posXmergulhador03 = -(janelaLargura / 2) - 30;
            mostraResgates();

            mergulhador03vertice01[0] = (posXmergulhador03 - 10.0f);
            mergulhador03vertice02[0] = (posXmergulhador03 - 10.0f);
            mergulhador03vertice03[0] = (posXmergulhador03 + 10.0f);
            mergulhador03vertice04[0] = (posXmergulhador03 + 10.0f);
        }

        if (posXmergulhador03 > (janelaLargura / 2) + 30)
        {
            nadarMergulhador03 = false;
            posXmergulhador03 = -(janelaLargura / 2) - 30;

            mergulhador03vertice01[0] = (posXmergulhador03 - 10.0f);
            mergulhador03vertice02[0] = (posXmergulhador03 - 10.0f);
            mergulhador03vertice03[0] = (posXmergulhador03 + 10.0f);
            mergulhador03vertice04[0] = (posXmergulhador03 + 10.0f);
        }
    }

    glutPostRedisplay();
    glutTimerFunc(150, animaMergulhador03, 1);
}

