#pragma once

#include "Torpedo.h"
#include "Vidas.h"

float posXtubarao01 = -(janelaLargura / 2) - 10;
float posYtubarao01 = (janelaAltura / 2) - 105;
int velocidadeTubarao01 = 10;
bool nadarTubarao01 = false;

float tubarao01vertice01[] = { (posXtubarao01 - 10.0f), (posYtubarao01 - 5.0f) };
float tubarao01vertice02[] = { (posXtubarao01 - 10.0f), (posYtubarao01 + 5.0f) };
float tubarao01vertice03[] = { (posXtubarao01 + 10.0f), (posYtubarao01 + 5.0f) };
float tubarao01vertice04[] = { (posXtubarao01 + 10.0f), (posYtubarao01 - 5.0f) };

void tubarao01()
{
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(tubarao01vertice01[0], tubarao01vertice01[1]);
    glVertex2f(tubarao01vertice02[0], tubarao01vertice02[1]);
    glVertex2f(tubarao01vertice03[0], tubarao01vertice03[1]);
    glVertex2f(tubarao01vertice04[0], tubarao01vertice04[1]);
    glEnd();
}

void randomValorTubarao01()
{
    int valor = rand() % 11;

    if (valor == 1)
    {
        nadarTubarao01 = true;
    }
}

void animaTubarao01(int val)
{
    if (!nadarTubarao01)
    {
        randomValorTubarao01();
    }
    else
    {
        posXtubarao01 += velocidadeTubarao01;

        tubarao01vertice01[0] += velocidadeTubarao01;
        tubarao01vertice02[0] += velocidadeTubarao01;
        tubarao01vertice03[0] += velocidadeTubarao01;
        tubarao01vertice04[0] += velocidadeTubarao01;

        if (posXtubarao01 > ((janelaLargura / 2) + 10) ||
                (
                    ( 
                        (
                            torpedoVertice01[0] <= tubarao01vertice03[0] &&
                            torpedoVertice01[0] >= tubarao01vertice02[0] &&
                            torpedoVertice01[1] <= tubarao01vertice03[1] &&
                            torpedoVertice01[1] >= tubarao01vertice04[1]
                        ) ||
                        (
                            torpedoVertice02[0] <= tubarao01vertice04[0] &&
                            torpedoVertice02[0] >= tubarao01vertice01[0] &&
                            torpedoVertice02[1] >= tubarao01vertice04[1] &&
                            torpedoVertice02[1] <= tubarao01vertice03[1] 
                        ) ||
                        (
                            torpedoVertice03[0] >= tubarao01vertice01[0] &&
                            torpedoVertice03[0] <= tubarao01vertice04[0] &&
                            torpedoVertice03[1] >= tubarao01vertice01[1] &&
                            torpedoVertice03[1] <= tubarao01vertice02[1]
                        ) ||
                        (
                            torpedoVertice04[0] >= tubarao01vertice02[0] &&
                            torpedoVertice04[0] <= tubarao01vertice03[0] &&
                            torpedoVertice04[1] <= tubarao01vertice02[1] &&
                            torpedoVertice04[1] >= tubarao01vertice01[1]
                        )
                    ) 
                )
            )
        {
            nadarTubarao01 = false;
            posXtubarao01= -(janelaLargura / 2) - 10;

            tubarao01vertice01[0] = (posXtubarao01 - 10.0f);
            tubarao01vertice02[0] = (posXtubarao01 - 10.0f);
            tubarao01vertice03[0] = (posXtubarao01 + 10.0f);
            tubarao01vertice04[0] = (posXtubarao01 + 10.0f);
        }

        if (
            (posXtubarao01 >= (posXsubmarino - raioLarguraSubmarino)) &&
            (posXtubarao01 <= (posXsubmarino + raioLarguraSubmarino)) &&
            (posYtubarao01 >= (posYsubmarino - raioAlturaSubmarino)) &&
            (posYtubarao01 <= (posYsubmarino + raioAlturaSubmarino))
           )
        {
            posXsubmarino = 0.0f;
            posYsubmarino = 120.0f;
            oxigenio = 100.0f;
            barraVermelha = 100.0f;
            perdeVida();

            torpedoVertice01[0] = (posXsubmarino - 5.0f);
            torpedoVertice01[1] = (posYsubmarino - 1.0f);
            torpedoVertice02[0] = (posXsubmarino - 5.0f);
            torpedoVertice02[1] = (posYsubmarino + 1.0f);
            torpedoVertice03[0] = (posXsubmarino + 5.0f);
            torpedoVertice03[1] = (posYsubmarino + 1.0f);
            torpedoVertice04[0] = (posXsubmarino + 5.0f);
            torpedoVertice04[1] = (posYsubmarino - 1.0f);
        }
    }

    glutPostRedisplay();
    glutTimerFunc(150, animaTubarao01, 0);
}
