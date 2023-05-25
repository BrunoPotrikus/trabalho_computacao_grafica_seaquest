#pragma once

float posXtubarao02 = -(janelaLargura / 2) - 10;
float posYtubarao02 = (janelaAltura / 2) - 160;
float velocidadeTubarao02 = 10.0f;
bool nadarTubarao02 = false;

float tubarao02vertice01[] = { (posXtubarao02 - 10.0f), (posYtubarao02 - 5.0f) };
float tubarao02vertice02[] = { (posXtubarao02 - 10.0f), (posYtubarao02 + 5.0f) };
float tubarao02vertice03[] = { (posXtubarao02 - 30.0f), (posYtubarao02 + 5.0f) };
float tubarao02vertice04[] = { (posXtubarao02 - 30.0f), (posYtubarao02 - 5.0f) };

void tubarao02()
{
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(tubarao02vertice01[0], tubarao02vertice01[1]);
    glVertex2f(tubarao02vertice02[0], tubarao02vertice02[1]);
    glVertex2f(tubarao02vertice03[0], tubarao02vertice03[1]);
    glVertex2f(tubarao02vertice04[0], tubarao02vertice04[1]);
    glEnd();
}

void randomValorTubarao02()
{
    int valor = rand() % 11;

    if (valor == 2)
    {
        nadarTubarao02 = true;
    }
}

void animaTubarao02(int val)
{
    if (!nadarTubarao02)
    {
        randomValorTubarao02();
    }
    else
    {
        posXtubarao02 += velocidadeTubarao02;

        tubarao02vertice01[0] += velocidadeTubarao02;
        tubarao02vertice02[0] += velocidadeTubarao02;
        tubarao02vertice03[0] += velocidadeTubarao02;
        tubarao02vertice04[0] += velocidadeTubarao02;

        if (posXtubarao02 > ((janelaLargura / 2) + 10) ||
            (
                (
                    (
                        torpedoVertice01[0] <= tubarao02vertice03[0] &&
                        torpedoVertice01[0] >= tubarao02vertice02[0] &&
                        torpedoVertice01[1] <= tubarao02vertice03[1] &&
                        torpedoVertice01[1] >= tubarao02vertice04[1]
                        ) ||
                    (
                        torpedoVertice02[0] <= tubarao02vertice04[0] &&
                        torpedoVertice02[0] >= tubarao02vertice01[0] &&
                        torpedoVertice02[1] >= tubarao02vertice04[1] &&
                        torpedoVertice02[1] <= tubarao02vertice03[1]
                        ) ||
                    (
                        torpedoVertice03[0] >= tubarao02vertice01[0] &&
                        torpedoVertice03[0] <= tubarao02vertice04[0] &&
                        torpedoVertice03[1] >= tubarao02vertice01[1] &&
                        torpedoVertice03[1] <= tubarao02vertice02[1]
                        ) ||
                    (
                        torpedoVertice04[0] >= tubarao02vertice02[0] &&
                        torpedoVertice04[0] <= tubarao02vertice03[0] &&
                        torpedoVertice04[1] <= tubarao02vertice02[1] &&
                        torpedoVertice04[1] >= tubarao02vertice01[1]
                        )
                    )
                )
            )
        {
            nadarTubarao01 = false;
            posXtubarao02 = -(janelaLargura / 2) - 10;

            tubarao02vertice01[0] = (posXtubarao02 - 10.0f);
            tubarao02vertice02[0] = (posXtubarao02 - 10.0f);
            tubarao02vertice03[0] = (posXtubarao02 + 10.0f);
            tubarao02vertice04[0] = (posXtubarao02 + 10.0f);
        }

        if (
            (posXtubarao02 >= (posXsubmarino - raioLarguraSubmarino)) &&
            (posXtubarao02 <= (posXsubmarino + raioLarguraSubmarino)) &&
            (posYtubarao02 >= (posYsubmarino - raioAlturaSubmarino)) &&
            (posYtubarao02 <= (posYsubmarino + raioAlturaSubmarino))
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
    glutTimerFunc(150, animaTubarao02, 1);
}
