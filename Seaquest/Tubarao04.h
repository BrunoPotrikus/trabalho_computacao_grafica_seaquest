#pragma once

float posXtubarao04 = (janelaLargura / 2) + 30;
float posYtubarao04 = (janelaAltura / 2) - 260;
int velocidadeTubarao04 = 10;
bool nadarTubarao04 = false;

float tubarao04vertice01[] = { (posXtubarao04 - 10.0f), (posYtubarao04 - 5.0f) };
float tubarao04vertice02[] = { (posXtubarao04 - 10.0f), (posYtubarao04 + 5.0f) };
float tubarao04vertice03[] = { (posXtubarao04 + 10.0f), (posYtubarao04 + 5.0f) };
float tubarao04vertice04[] = { (posXtubarao04 + 10.0f), (posYtubarao04 - 5.0f) };

void tubarao04()
{
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(tubarao04vertice01[0], tubarao04vertice01[1]);
    glVertex2f(tubarao04vertice02[0], tubarao04vertice02[1]);
    glVertex2f(tubarao04vertice03[0], tubarao04vertice03[1]);
    glVertex2f(tubarao04vertice04[0], tubarao04vertice04[1]);
    glEnd();
}

void randomValorTubarao04()
{
    int valor = rand() % 11;

    if (valor == 4)
    {
        nadarTubarao04 = true;
    }
}

void animaTubarao04(int val)
{
    if (!nadarTubarao04)
    {
        randomValorTubarao04();
    }
    else
    {
        posXtubarao04 -= velocidadeTubarao04;

        tubarao04vertice01[0] -= velocidadeTubarao04;
        tubarao04vertice02[0] -= velocidadeTubarao04;
        tubarao04vertice03[0] -= velocidadeTubarao04;
        tubarao04vertice04[0] -= velocidadeTubarao04;

        if (posXtubarao04 < (-(janelaLargura / 2) - 10) ||
            (
                (
                    (
                        torpedoVertice01[0] <= tubarao04vertice03[0] &&
                        torpedoVertice01[0] >= tubarao04vertice02[0] &&
                        torpedoVertice01[1] <= tubarao04vertice03[1] &&
                        torpedoVertice01[1] >= tubarao04vertice04[1]
                        ) ||
                    (
                        torpedoVertice02[0] <= tubarao04vertice04[0] &&
                        torpedoVertice02[0] >= tubarao04vertice01[0] &&
                        torpedoVertice02[1] >= tubarao04vertice04[1] &&
                        torpedoVertice02[1] <= tubarao04vertice03[1]
                        ) ||
                    (
                        torpedoVertice03[0] >= tubarao04vertice01[0] &&
                        torpedoVertice03[0] <= tubarao04vertice04[0] &&
                        torpedoVertice03[1] >= tubarao04vertice01[1] &&
                        torpedoVertice03[1] <= tubarao04vertice02[1]
                        ) ||
                    (
                        torpedoVertice04[0] >= tubarao04vertice02[0] &&
                        torpedoVertice04[0] <= tubarao04vertice03[0] &&
                        torpedoVertice04[1] <= tubarao04vertice02[1] &&
                        torpedoVertice04[1] >= tubarao04vertice01[1]
                        )
                    )
                )
            )
        {
            nadarTubarao01 = false;
            posXtubarao04 = (janelaLargura / 2) + 30;

            tubarao04vertice01[0] = (posXtubarao04 - 10.0f);
            tubarao04vertice02[0] = (posXtubarao04 - 10.0f);
            tubarao04vertice03[0] = (posXtubarao04 + 10.0f);
            tubarao04vertice04[0] = (posXtubarao04 + 10.0f);
        }

        if (
            (posXtubarao04 >= (posXsubmarino - raioLarguraSubmarino)) &&
            (posXtubarao04 <= (posXsubmarino + raioLarguraSubmarino)) &&
            (posYtubarao04 >= (posYsubmarino - raioAlturaSubmarino)) &&
            (posYtubarao04 <= (posYsubmarino + raioAlturaSubmarino))
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
    glutTimerFunc(150, animaTubarao04, 1);
}
