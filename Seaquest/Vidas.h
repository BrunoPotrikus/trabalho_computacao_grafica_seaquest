#pragma once

float posVida01 = -10.0f;
bool temVida01 = true;

float posVida02 = -40.0f;
bool temVida02 = true;

float posVida03 = -70.0f;
bool temVida03 = true;

void vida01()
{
	glTranslatef(posVida01, 170.0f, 0.0f);

    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-20.0f, -5.0f);
    glVertex2f(-20.0f, 5.0f);
    glVertex2f(0.0f, 5.0f);
    glVertex2f(0.0f, -5.0f);
    glEnd();
}

void vida02()
{
    glTranslatef(posVida02, 170.0f, 0.0f);

    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-20.0f, -5.0f);
    glVertex2f(-20.0f, 5.0f);
    glVertex2f(0.0f, 5.0f);
    glVertex2f(0.0f, -5.0f);
    glEnd();
}

void vida03()
{
    glTranslatef(posVida03, 170.0f, 0.0f);

    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-20.0f, -5.0f);
    glVertex2f(-20.0f, 5.0f);
    glVertex2f(0.0f, 5.0f);
    glVertex2f(0.0f, -5.0f);
    glEnd();
}

void perdeVida()
{
    if (temVida01)
    {
        posVida01 = 350.0f;
        temVida01 = false;
    }
    else if (temVida02) 
    {
        posVida02 = 350;
        temVida02 = false;
    }
    else
    {
        posVida03 = 350;
        temVida03 = false;
    }
}
