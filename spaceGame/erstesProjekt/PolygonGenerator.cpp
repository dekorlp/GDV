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


void PolygonGenerator::createCylinder(GLfloat radius, GLfloat height)
{
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f); //BLAU
	GLUquadricObj *quadObj;

	quadObj = gluNewQuadric();
	gluQuadricDrawStyle(quadObj, GLU_FILL);
	gluQuadricNormals(quadObj, GLU_SMOOTH);
	gluCylinder(quadObj, 0.1, 0.1, 0.1, 24, 4);
}

void PolygonGenerator::createShip(GLfloat rotationSpeed)
{
	glPushMatrix();
		// Shuttle Cockpit
		glPushMatrix();
			glTranslatef(-1.46, 0, 0);
			glRotatef(90, 0, 1, 0);
			createCockpit(0.4);
		glPopMatrix();
	
		// Shuttlekörper
		glPushMatrix();
			glScalef(3,1,1);
			glTranslatef(-0.22,0,0);
			createCube(0.4);
		glPopMatrix();

		// Shuttle Hinten Flügel Rechts
		glPushMatrix();
			glRotatef(-35, 0, 1, 0);
			glScalef(1.5, 0.5, 5);
			glTranslatef(-0.5, 0, -0.10);
			createPropeller(0.4);
		glPopMatrix();

		// Shuttle Hinten Flügel Links
		glPushMatrix();
			glRotatef(215, 0, 1, 0);
			glScalef(1.5, 0.5, 5);
			glTranslatef(0.5, 0, -0.10);
			createPropeller(0.4);
		glPopMatrix();

	
		glRotatef(propellerRotationSpeed += rotationSpeed, 1, 0, 0);
		glPushMatrix();
			// Halterung der Propeller
			glPushMatrix();
			glTranslatef(-0.1, 0, 0);
			glRotatef(90, 0,1,0);
			
			createCylinder(2, 0.4);
			glPopMatrix();

			// Oberer Propeller
			glPushMatrix();
			glScalef(0.1, 1, 0.1);
			glTranslatef(-0.2, 0.3, 0.0);
			createCube(0.4);
			glPopMatrix();


			// Unterer Propeller Propeller
			glPushMatrix();
			glScalef(0.1, 1, 0.1);
			glTranslatef(-0.2, -0.3, 0);
			createCube(0.4);
			glPopMatrix();

			// Hinten rechter Propeller
			glPushMatrix();
			glRotatef(90, 1,0,0);
			glScalef(0.1, 1, 0.1);
			glTranslatef(-0.2, -0.3, 0);
			createCube(0.4);
			glPopMatrix();

			// Hinten linker Propeller
			glPushMatrix();
			glRotatef(90, 1, 0, 0);
			glScalef(0.1, 1, 0.1);
			glTranslatef(-0.2, 0.3, 0);
			createCube(0.4);
			glPopMatrix();
		glPopMatrix();

	glPopMatrix();


}