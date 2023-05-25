#pragma once

#include "Informacoes.h"

static float posXsubmarino = 0.0f;
static float posYsubmarino = 120.0f;
int velocidadeSubmarino = 10;
int raioLarguraSubmarino = 40;
int raioAlturaSubmarino = 10;

void submarino()
{
    GLfloat circ_pnt = 100;
    GLfloat ang;

    glTranslatef(posXsubmarino, posYsubmarino, 0);

    circ_pnt = 100;

    glBegin(GL_POLYGON);
    for (int i = 0; i < circ_pnt; i++)
    {
        glColor3f(1.0, 1.0, 0.0);
        ang = (2 * PI * i) / circ_pnt;
        glVertex2f(cos(ang) * raioLarguraSubmarino, sin(ang) * raioAlturaSubmarino);
    }
    glEnd();
}

