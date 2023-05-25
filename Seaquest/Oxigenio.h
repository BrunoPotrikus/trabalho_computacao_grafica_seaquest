#pragma once

float oxigenio = 100.0f;
float barraVermelha = 100.0f;

void barraOxigenio()
{
	glColor3f(0.5f, 0.5f, 0.5f);
	glBegin(GL_QUADS);
	glVertex2f(-300.0f, -200.0f);
	glVertex2f(-300.0f, -120.0f);
	glVertex2f(300.0f, -120.0f);
	glVertex2f(300.0f, -200.0f);
	glEnd();

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
	glVertex2f(-100.0f, -150.0f);
	glVertex2f(-100.0f, -140.0f);
	glVertex2f(oxigenio, -140.0f);
	glVertex2f(oxigenio, -150.0f);
	glEnd();

	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex2f(barraVermelha, -150.0f);
	glVertex2f(barraVermelha, -140.0f);
	glVertex2f(100.0f, -140.0f);
	glVertex2f(100.0f, -150.0f);
	glEnd();
}

void mudaOxigenio(int val)
{
	if (oxigenio > -100.0f && posYsubmarino < 120.0f)
	{
		oxigenio -= 1.0f;
		barraVermelha -= 1.0f;
	}
	else
	{
		if (oxigenio < 100.0f && posYsubmarino >= 120.0f)
		{
			oxigenio += 4.0f;
			barraVermelha += 4.0f;
		}
	}

	glutPostRedisplay();
	glutTimerFunc(150, mudaOxigenio, 1);
}
