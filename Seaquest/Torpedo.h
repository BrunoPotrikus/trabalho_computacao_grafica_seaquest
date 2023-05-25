#pragma once

float posXtorpedo = 0.0f;
float posYtorpedo = 0.0f;
float velocidadeTorpedo = 50.0f;
bool atirou = false;
bool direita = true;

float torpedoVertice01[] = { (posXsubmarino - 5.0f), (posYsubmarino - 1.0f) };
float torpedoVertice02[] = { (posXsubmarino - 5.0f), (posYsubmarino + 1.0f) };
float torpedoVertice03[] = { (posXsubmarino + 5.0f), (posYsubmarino + 1.0f) };
float torpedoVertice04[] = { (posXsubmarino + 5.0f), (posYsubmarino - 1.0f) };

void torpedo()
{
    glTranslatef(posXtorpedo, posYtorpedo, 0);

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(torpedoVertice01[0], torpedoVertice01[1]);
    glVertex2f(torpedoVertice02[0], torpedoVertice02[1]);
    glVertex2f(torpedoVertice03[0], torpedoVertice03[1]);
    glVertex2f(torpedoVertice04[0], torpedoVertice04[1]);
    glEnd();
}

void disparaTorpedo(int valor)
{
    if (atirou)
    {
        if (direita)
        {
            posXtorpedo += velocidadeTorpedo;

            torpedoVertice01[0] += velocidadeTorpedo;
            torpedoVertice02[0] += velocidadeTorpedo;
            torpedoVertice03[0] += velocidadeTorpedo;
            torpedoVertice04[0] += velocidadeTorpedo;

            if (posXtorpedo > janelaLargura / 2)
            {
                atirou = false;
                posXtorpedo = 0.0f;

                torpedoVertice01[0] = (posXsubmarino - 5.0f);
                torpedoVertice02[0] = (posXsubmarino - 5.0f);
                torpedoVertice03[0] = (posXsubmarino + 5.0f);
                torpedoVertice04[0] = (posXsubmarino + 5.0f);
            }
        }
        else
        {
            posXtorpedo -= velocidadeTorpedo;

            torpedoVertice01[0] -= velocidadeTorpedo;
            torpedoVertice02[0] -= velocidadeTorpedo;
            torpedoVertice03[0] -= velocidadeTorpedo;
            torpedoVertice04[0] -= velocidadeTorpedo;

            if (posXtorpedo < -(janelaLargura) / 2)
            {
                atirou = false;
                posXtorpedo = 0.0f;

                torpedoVertice01[0] = (posXsubmarino - 5.0f);
                torpedoVertice02[0] = (posXsubmarino - 5.0f);
                torpedoVertice03[0] = (posXsubmarino + 5.0f);
                torpedoVertice04[0] = (posXsubmarino + 5.0f);
            }
        }
    }

    glutPostRedisplay();
    glutTimerFunc(30, disparaTorpedo, 0);
}
