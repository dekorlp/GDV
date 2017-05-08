#include <GL/freeglut.h>
#include "PolygonGenerator.h"

#define _USE_MATH_DEFINES
#include <cmath>


void PolygonGenerator::createCube(GLfloat fSeitenL)
{
	glBegin(GL_POLYGON);   //Vorderseite
	glNormal3f(0.0f, 0.0f, 1.0f);
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f); //BLAU
	glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glEnd();


	glBegin(GL_POLYGON);   //Rechte Seite
	glNormal3f(1.0f, 0.0f, 0.0f);
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f); //BLAU
	glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glEnd();


	glBegin(GL_POLYGON);   //Rueckseite
	glNormal3f(0.0f, 0.0f, -1.0f);
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f); //BLAU
	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glEnd();


	glBegin(GL_POLYGON);   //Linke Seite
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f); //BLAU
	glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glEnd();

	glBegin(GL_POLYGON);   //Deckflaeche
	glNormal3f(0.0f, 1.0f, 0.0f);
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f); //BLAU
	glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glEnd();

	glBegin(GL_POLYGON);   //Bodenflaeche
	glNormal3f(0.0f, -1.0f, 0.0f);
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f); //BLAU
	glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glEnd();

}

void PolygonGenerator::createCockpit(GLfloat fSeitenL)
{
	glBegin(GL_POLYGON);   //Vorderseite
	glNormal3f(0.0f, 0.0f, 1.0f);
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f); //BLAU
	glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glEnd();


	glBegin(GL_POLYGON);   //Rechte Seite Unten
	glNormal3f(0.0f, 0.0f, 0.0f);
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f); //BLAU
	glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL /2.0f);
	glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f / 4, -fSeitenL / 2.0f);
	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f / 4, +fSeitenL / 2.0f);
	glEnd();

	glBegin(GL_POLYGON);   //Rechte Seite Oben
	glNormal3f(0.0f, 0.0f, 0.0f);
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f); //BLAU
	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f / 4);
	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f / 4, -fSeitenL / 2.0f);
	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f / 4, +fSeitenL / 2.0f);
	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glEnd();


	glBegin(GL_POLYGON);   //Rueckseite
	glNormal3f(0.0f, 0.0f, -1.0f);
	glColor4f(1.0f, 0.0f, 1.0f, 1.0f); //BLAU
	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f /4, -fSeitenL / 2.0f);
	glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f /4, -fSeitenL / 2.0f);
	glEnd();


	glBegin(GL_POLYGON);   //Linke Seite Unten
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f); //BLAU
	glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f / 4, -fSeitenL / 2.0f);
	glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f / 4, +fSeitenL / 2.0f);
	glEnd();

	glBegin(GL_POLYGON);   //Linke Seite Oben
	glNormal3f(0.0f, 0.0f, 0.0f);
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f); //BLAU
	glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f / 4);
	glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f / 4, -fSeitenL / 2.0f);
	glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f / 4, +fSeitenL / 2.0f);
	glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glEnd();

	glBegin(GL_POLYGON);   // Scheibe
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f); //BLAU
	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f / 4, -fSeitenL / 2.0f);
	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f / 4);
	glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f / 4);
	glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f / 4, -fSeitenL / 2.0f);
	
	
	glEnd();

	glBegin(GL_POLYGON);   //Deckflaeche
	glNormal3f(0.0f, 1.0f, 0.0f);
	glColor4f(0.0f, 1.0f, 0.0f, 1.0f); //BLAU
	glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f / 4);
	glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f / 4);
	glEnd();

	glBegin(GL_POLYGON);   //Bodenflaeche
	glNormal3f(0.0f, -1.0f, 0.0f);
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f); //BLAU
	glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glEnd();
}

void PolygonGenerator::createPropeller(GLfloat fSeitenL)
{
	glBegin(GL_POLYGON);   //Vorderseite
	glNormal3f(0.0f, 0.0f, 1.0f);
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f); //BLAU
	glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glEnd();


	glBegin(GL_POLYGON);   //Rechte Seite Mitte
	glNormal3f(0.0f, 0.0f, 0.0f);
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f); //BLAU
	glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f / 4, +fSeitenL / 2.0f);
	glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f / 4, -fSeitenL / 2.0f);
	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f / 4, -fSeitenL / 2.0f);
	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f / 4, +fSeitenL / 2.0f);
	glEnd();

	glBegin(GL_POLYGON);   //Rechte Seite Oben
	glNormal3f(0.0f, 0.0f, 0.0f);
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f); //BLAU
	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f / 4);
	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f / 4, -fSeitenL / 2.0f);
	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f / 4, +fSeitenL / 2.0f);
	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glEnd();

	glBegin(GL_POLYGON);   //Rechte Seite Unten
	glNormal3f(0.0f, 0.0f, 0.0f);
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f); //BLAU
	glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f / 4, +fSeitenL / 2.0f);
	glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f / 4, -fSeitenL / 2.0f);
	glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f / 4);
	glEnd();


	glBegin(GL_POLYGON);   //Rueckseite
	glNormal3f(0.0f, 0.0f, -1.0f);
	glColor4f(1.0f, 0.0f, 1.0f, 1.0f); //BLAU
	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f / 4, -fSeitenL / 2.0f);
	glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f / 4, -fSeitenL / 2.0f);
	glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f / 4, -fSeitenL / 2.0f);
	glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f / 4, -fSeitenL / 2.0f);
	glEnd();


	glBegin(GL_POLYGON);   //Linke Seite Mitte
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f); //BLAU
	glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f / 4, -fSeitenL / 2.0f);
	glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f / 4, -fSeitenL / 2.0f);
	glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f / 4, +fSeitenL / 2.0f);
	glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f / 4, +fSeitenL / 2.0f);
	glEnd();

	glBegin(GL_POLYGON);   //Linke Seite Unten
	glNormal3f(0.0f, 0.0f, 0.0f);
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f); //BLAU
	glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f / 4, +fSeitenL / 2.0f);
	glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f / 4, -fSeitenL / 2.0f);
	glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f / 4);
	glEnd();


	glBegin(GL_POLYGON);   //Linke Seite Oben
	glNormal3f(0.0f, 0.0f, 0.0f);
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f); //BLAU
	glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f / 4);
	glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f / 4, -fSeitenL / 2.0f);
	glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f / 4, +fSeitenL / 2.0f);
	glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glEnd();

	glBegin(GL_POLYGON);   // Scheibe Oben
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f); //BLAU
	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f / 4, -fSeitenL / 2.0f);
	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f / 4);
	glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f / 4);
	glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f / 4, -fSeitenL / 2.0f);
	glEnd();

	glBegin(GL_POLYGON);   // Scheibe Oben
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f); //BLAU
	glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f / 4, -fSeitenL / 2.0f);
	glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f / 4);
	glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f / 4);
	glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f / 4, -fSeitenL / 2.0f);
	glEnd();

	glBegin(GL_POLYGON);   //Deckflaeche
	glNormal3f(0.0f, 1.0f, 0.0f);
	glColor4f(0.0f, 1.0f, 0.0f, 1.0f); //BLAU
	glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f / 4);
	glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f / 4);
	glEnd();

	glBegin(GL_POLYGON);   //Bodenflaeche
	glNormal3f(0.0f, -1.0f, 0.0f);
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f); //BLAU
	glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f / 4);
	glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f / 4);
	glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glEnd();
}

void PolygonGenerator::createSphere(GLfloat r, int lats, int longs)
{
	int i, j;
	for (i = 0; i <= lats; i++) {
		GLfloat lat0 = M_PI * (-0.5 + (GLfloat)(i - 1) / lats);
		GLfloat z0 = sin(lat0);
		GLfloat zr0 = cos(lat0);

		GLfloat lat1 = M_PI * (-0.5 + (GLfloat)i / lats);
		GLfloat z1 = sin(lat1);
		GLfloat zr1 = cos(lat1);

		glBegin(GL_QUAD_STRIP);
			for (j = 0; j <= longs; j++) {
				GLfloat lng = 2 * M_PI * (GLfloat)(j - 1) / longs;
				GLfloat x = cos(lng);
				GLfloat y = sin(lng);
				
				glNormal3f(x * zr0, y * zr0, z0);
				glVertex3f(x * zr0, y * zr0, z0);
				glNormal3f(x * zr1, y * zr1, z1);
				glVertex3f(x * zr1, y * zr1, z1);
			}
		glEnd();
	}
}
