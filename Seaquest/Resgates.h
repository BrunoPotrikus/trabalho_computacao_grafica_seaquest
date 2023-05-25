#pragma once

int resgatados = 0;

float posXresgatado01 = -350.0f;
float posXresgatado02 = -350.0f;
float posXresgatado03 = -350.0f;
float posXresgatado04 = -350.0f;
float posXresgatado05 = -350.0f;

void resgate01()
{
    glTranslatef(posXresgatado01, -170.0f, 0.0f);

    glColor3f(0.5f, 1.0f, 0.5f);
    glBegin(GL_QUADS);
    glVertex2f(-20.0f, -5.0f);
    glVertex2f(-20.0f, 5.0f);
    glVertex2f(0.0f, 5.0f);
    glVertex2f(0.0f, -5.0f);
    glEnd();
}

void resgate02()
{
    glTranslatef(posXresgatado02, -170.0f, 0.0f);

    glColor3f(0.5f, 1.0f, 0.5f);
    glBegin(GL_QUADS);
    glVertex2f(-20.0f, -5.0f);
    glVertex2f(-20.0f, 5.0f);
    glVertex2f(0.0f, 5.0f);
    glVertex2f(0.0f, -5.0f);
    glEnd();
}

void resgate03()
{
    glTranslatef(posXresgatado03, -170.0f, 0.0f);

    glColor3f(0.5f, 1.0f, 0.5f);
    glBegin(GL_QUADS);
    glVertex2f(-20.0f, -5.0f);
    glVertex2f(-20.0f, 5.0f);
    glVertex2f(0.0f, 5.0f);
    glVertex2f(0.0f, -5.0f);
    glEnd();
}

void resgate04()
{
    glTranslatef(posXresgatado04, -170.0f, 0.0f);

    glColor3f(0.5f, 1.0f, 0.5f);
    glBegin(GL_QUADS);
    glVertex2f(-20.0f, -5.0f);
    glVertex2f(-20.0f, 5.0f);
    glVertex2f(0.0f, 5.0f);
    glVertex2f(0.0f, -5.0f);
    glEnd();
}

void resgate05()
{
    glTranslatef(posXresgatado05, -170.0f, 0.0f);

    glColor3f(0.5f, 1.0f, 0.5f);
    glBegin(GL_QUADS);
    glVertex2f(-20.0f, -5.0f);
    glVertex2f(-20.0f, 5.0f);
    glVertex2f(0.0f, 5.0f);
    glVertex2f(0.0f, -5.0f);
    glEnd();
}

void mostraResgates()
{
    resgatados++;

    switch (resgatados)
    {
    case 1:
        posXresgatado01 = 60.0f;
        break;

    case 2:
        posXresgatado02 = 30.0f;
        break;

    case 3:
        posXresgatado03 = 0.0f;
        break;

    case 4:
        posXresgatado04 = -30.0f;
        break;

    case 5:
        posXresgatado05 = -60.0f;
        break;

    default:
        break;
    }
}