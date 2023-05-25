#pragma once

float posXtubarao03 = (janelaLargura / 2) + 30;
float posYtubarao03 = (janelaAltura / 2) - 210;
int velocidadeTubarao03 = 10;
bool nadarTubarao03 = false;

float tubarao03vertice01[] = { (posXtubarao03 - 10.0f), (posYtubarao03 - 5.0f) };
float tubarao03vertice02[] = { (posXtubarao03 - 10.0f), (posYtubarao03 + 5.0f) };
float tubarao03vertice03[] = { (posXtubarao03 + 10.0f), (posYtubarao03 + 5.0f) };
float tubarao03vertice04[] = { (posXtubarao03 + 10.0f), (posYtubarao03 - 5.0f) };

void tubarao03()
{
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(tubarao03vertice01[0], tubarao03vertice01[1]);
    glVertex2f(tubarao03vertice02[0], tubarao03vertice02[1]);
    glVertex2f(tubarao03vertice03[0], tubarao03vertice03[1]);
    glVertex2f(tubarao03vertice04[0], tubarao03vertice04[1]);
    glEnd();
}

void randomValorTubarao03()
{
    int valor = rand() % 11;

    if (valor == 3)
    {
        nadarTubarao03 = true;
    }
}

void animaTubarao03(int val)
{
    if (!nadarTubarao03)
    {
        randomValorTubarao03();
    }
    else
    {
        posXtubarao03 -= velocidadeTubarao03;

        tubarao03vertice01[0] -= velocidadeTubarao03;
        tubarao03vertice02[0] -= velocidadeTubarao03;
        tubarao03vertice03[0] -= velocidadeTubarao03;
        tubarao03vertice04[0] -= velocidadeTubarao03;

        if (posXtubarao03 < (-(janelaLargura / 2) - 10) ||
            (
                (
                    (
                        torpedoVertice01[0] <= tubarao03vertice03[0] &&
                        torpedoVertice01[0] >= tubarao03vertice02[0] &&
                        torpedoVertice01[1] <= tubarao03vertice03[1] &&
                        torpedoVertice01[1] >= tubarao03vertice04[1]
                        ) ||
                    (
                        torpedoVertice02[0] <= tubarao03vertice04[0] &&
                        torpedoVertice02[0] >= tubarao03vertice01[0] &&
                        torpedoVertice02[1] >= tubarao03vertice04[1] &&
                        torpedoVertice02[1] <= tubarao03vertice03[1]
                        ) ||
                    (
                        torpedoVertice03[0] >= tubarao03vertice01[0] &&
                        torpedoVertice03[0] <= tubarao03vertice04[0] &&
                        torpedoVertice03[1] >= tubarao03vertice01[1] &&
                        torpedoVertice03[1] <= tubarao03vertice02[1]
                        ) ||
                    (
                        torpedoVertice04[0] >= tubarao03vertice02[0] &&
                        torpedoVertice04[0] <= tubarao03vertice03[0] &&
                        torpedoVertice04[1] <= tubarao03vertice02[1] &&
                        torpedoVertice04[1] >= tubarao03vertice01[1]
                        )
                    )
                )
            )
        {
            nadarTubarao01 = false;
            posXtubarao03 = (janelaLargura / 2) + 30;

            tubarao03vertice01[0] = (posXtubarao03 - 10.0f);
            tubarao03vertice02[0] = (posXtubarao03 - 10.0f);
            tubarao03vertice03[0] = (posXtubarao03 + 10.0f);
            tubarao03vertice04[0] = (posXtubarao03 + 10.0f);
        }

        if (
            (posXtubarao03 >= (posXsubmarino - raioLarguraSubmarino)) &&
            (posXtubarao03 <= (posXsubmarino + raioLarguraSubmarino)) &&
            (posYtubarao03 >= (posYsubmarino - raioAlturaSubmarino)) &&
            (posYtubarao03 <= (posYsubmarino + raioAlturaSubmarino))
            )
        {
            posXsubmarino = 0.0f;
            posYsubmarino = 120.0f;
            oxigenio = 100.0f;
            barraVermelha = 100.0;
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
    glutTimerFunc(150, animaTubarao03, 1);
}
