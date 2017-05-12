#include <GL/freeglut.h>
#include <GL/SOIL.h>
#include <iostream>
#include "PolygonGenerator.h"

#define _USE_MATH_DEFINES
#include <cmath>

void PolygonGenerator::initPolygonGenerator()
{
	hull = SOIL_load_OGL_texture("textures/hull.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	if (hull == 0)
	{
		std::cout << "Textur Hull konnte nicht geladen werden" << std::endl;
		printf("SOIL loading error: '%s'\n", SOIL_last_result());
	}

	carbon = SOIL_load_OGL_texture("textures/carbon.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	if (carbon == 0)
	{
		std::cout << "Textur Carbon konnte nicht geladen werden" << std::endl;
	}

}

void PolygonGenerator::createCube(GLfloat fSeitenL)
{
	glBegin(GL_POLYGON);   //Vorderseite
	glNormal3f(0.0f, 0.0f, 1.0f);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f); //BLAU
	glTexCoord2f(0, 0); glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glTexCoord2f(1, 0); glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glTexCoord2f(1, 1); glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glTexCoord2f(0, 1); glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glEnd();

	glBegin(GL_POLYGON);   //Rechte Seite
	glNormal3f(1.0f, 0.0f, 0.0f);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f); //BLAU
	glTexCoord2f(0, 0); glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glTexCoord2f(1, 0); glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glTexCoord2f(1, 1); glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glTexCoord2f(0, 1); glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glEnd();

	glBegin(GL_POLYGON);   //Rueckseite
	glNormal3f(0.0f, 0.0f, -1.0f);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f); //BLAU
	glTexCoord2f(0, 0); glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glTexCoord2f(1, 0); glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glTexCoord2f(1, 1); glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glTexCoord2f(0, 1); glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glEnd();

	glBegin(GL_POLYGON);   //Linke Seite
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f); //BLAU
	glTexCoord2f(0, 0); glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glTexCoord2f(1, 0); glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glTexCoord2f(1, 1); glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glTexCoord2f(0, 1); glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glEnd();

	glBegin(GL_POLYGON);   //Deckflaeche
	glNormal3f(0.0f, 1.0f, 0.0f);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f); //BLAU
	glTexCoord2f(0, 0); glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glTexCoord2f(1, 0); glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glTexCoord2f(1, 1); glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glTexCoord2f(0, 1); glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glEnd();

	glBegin(GL_POLYGON);   //Bodenflaeche
	glNormal3f(0.0f, -1.0f, 0.0f);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f); //BLAU
	glTexCoord2f(0, 0); glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glTexCoord2f(1, 0); glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glTexCoord2f(1, 1); glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glTexCoord2f(0, 1); glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glEnd();

}

void PolygonGenerator::createCockpit(GLfloat fSeitenL)
{
	glBegin(GL_POLYGON);   //Vorderseite
	glNormal3f(0.0f, 0.0f, 1.0f);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f); //BLAU
	glTexCoord2f(0, 0); glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glTexCoord2f(1, 0); glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glTexCoord2f(1, 1); glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glTexCoord2f(0, 1); glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glEnd();


	glBegin(GL_POLYGON);   //Rechte Seite Unten
	glNormal3f(1.0f, -1.0f, 0.0f);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f); //BLAU
	glTexCoord2f(0, 0); glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glTexCoord2f(1, 0); glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glTexCoord2f(1, 1); glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f / 4, -fSeitenL / 2.0f);
	glTexCoord2f(0, 1); glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f / 4, +fSeitenL / 2.0f);
	glEnd();

	glBegin(GL_POLYGON);   //Rechte Seite Oben
	glNormal3f(1.0f, 1.0f, 0.0f);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f); //BLAU
	glTexCoord2f(0, 0); glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f / 4);
	glTexCoord2f(1, 0); glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f / 4, -fSeitenL / 2.0f);
	glTexCoord2f(1, 1); glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f / 4, +fSeitenL / 2.0f);
	glTexCoord2f(0, 1); glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glEnd();

	glBegin(GL_POLYGON);   //Rueckseite
	glNormal3f(0.0f, 0.0f, -1.0f);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f); //BLAU
	glTexCoord2f(0, 0); glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f / 4, -fSeitenL / 2.0f);
	glTexCoord2f(1, 0); glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glTexCoord2f(1, 1); glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glTexCoord2f(0, 1); glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f / 4, -fSeitenL / 2.0f);
	glEnd();


	glBegin(GL_POLYGON);   //Linke Seite Unten
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f); //BLAU
	glTexCoord2f(0, 0); glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f / 4, -fSeitenL / 2.0f);
	glTexCoord2f(1, 0); glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glTexCoord2f(1, 1); glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glTexCoord2f(0, 1); glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f / 4, +fSeitenL / 2.0f);
	glEnd();

	glBegin(GL_POLYGON);   //Linke Seite Oben
	glNormal3f(-1.0f, 1.0f, 0.0f);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f); //BLAU
	glTexCoord2f(0, 0); glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f / 4);
	glTexCoord2f(1, 0); glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f / 4, -fSeitenL / 2.0f);
	glTexCoord2f(1, 1); glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f / 4, +fSeitenL / 2.0f);
	glTexCoord2f(0, 1); glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glEnd();

	glDisable(GL_TEXTURE);
	glBegin(GL_POLYGON);   // Scheibe
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glColor4f(0.8f, 0.8f, 0.8f, 0.6f); //BLAU
	glTexCoord2f(0, 0); glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f / 4, -fSeitenL / 2.0f);
	glTexCoord2f(1, 0); glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f / 4);
	glTexCoord2f(1, 1); glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f / 4);
	glTexCoord2f(0, 1); glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f / 4, -fSeitenL / 2.0f);
	glEnd();
	glEnable(GL_TEXTURE);

	glBegin(GL_POLYGON);   //Deckflaeche
	glNormal3f(0.0f, 1.0f, 0.0f);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f); //BLAU
	glTexCoord2f(0, 0); glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glTexCoord2f(1, 0); glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glTexCoord2f(1, 1); glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f / 4);
	glTexCoord2f(0, 1); glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f / 4);
	glEnd();

	glBegin(GL_POLYGON);   //Bodenflaeche
	glNormal3f(0.0f, -1.0f, 0.0f);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f); //BLAU
	glTexCoord2f(0, 0); glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glTexCoord2f(1, 0); glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glTexCoord2f(1, 1); glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glTexCoord2f(0, 1); glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glEnd();
}

void PolygonGenerator::createPropeller(GLfloat fSeitenL)
{
	glBegin(GL_POLYGON);   //Vorderseite
	glNormal3f(0.0f, 0.0f, 1.0f);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f); //BLAU
	glTexCoord2f(0, 0); glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glTexCoord2f(1, 0); glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glTexCoord2f(1, 1); glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glTexCoord2f(0, 1); glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glEnd();


	glBegin(GL_POLYGON);   //Rechte Seite Mitte
	glNormal3f(0.0f, 0.0f, 0.0f);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f); //BLAU
	glTexCoord2f(0, 0); glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f / 4, +fSeitenL / 2.0f);
	glTexCoord2f(1, 0); glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f / 4, -fSeitenL / 2.0f);
	glTexCoord2f(1, 1); glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f / 4, -fSeitenL / 2.0f);
	glTexCoord2f(0, 1); glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f / 4, +fSeitenL / 2.0f);
	glEnd();

	glBegin(GL_POLYGON);   //Rechte Seite Oben
	glNormal3f(0.0f, 0.0f, 0.0f);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f); //BLAU
	glTexCoord2f(0, 0); glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f / 4);
	glTexCoord2f(1, 0); glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f / 4, -fSeitenL / 2.0f);
	glTexCoord2f(1, 1); glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f / 4, +fSeitenL / 2.0f);
	glTexCoord2f(0, 1); glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glEnd();

	glBegin(GL_POLYGON);   //Rechte Seite Unten
	glNormal3f(0.0f, 0.0f, 0.0f);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f); //BLAU
	glTexCoord2f(0, 0); glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glTexCoord2f(1, 0); glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f / 4, +fSeitenL / 2.0f);
	glTexCoord2f(1, 1); glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f / 4, -fSeitenL / 2.0f);
	glTexCoord2f(0, 1); glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f / 4);
	glEnd();


	glBegin(GL_POLYGON);   //Rueckseite
	glNormal3f(0.0f, 0.0f, -1.0f);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f); //BLAU
	glTexCoord2f(0, 0); glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f / 4, -fSeitenL / 2.0f);
	glTexCoord2f(1, 0); glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f / 4, -fSeitenL / 2.0f);
	glTexCoord2f(1, 1); glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f / 4, -fSeitenL / 2.0f);
	glTexCoord2f(0, 1); glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f / 4, -fSeitenL / 2.0f);
	glEnd();


	glBegin(GL_POLYGON);   //Linke Seite Mitte
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f); //BLAU
	glTexCoord2f(0, 0); glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f / 4, -fSeitenL / 2.0f);
	glTexCoord2f(1, 0); glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f / 4, -fSeitenL / 2.0f);
	glTexCoord2f(1, 1); glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f / 4, +fSeitenL / 2.0f);
	glTexCoord2f(0, 1); glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f / 4, +fSeitenL / 2.0f);
	glEnd();

	glBegin(GL_POLYGON);   //Linke Seite Unten
	glNormal3f(0.0f, 0.0f, 0.0f);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f); //BLAU
	glTexCoord2f(0, 0); glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glTexCoord2f(1, 0); glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f / 4, +fSeitenL / 2.0f);
	glTexCoord2f(1, 1); glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f / 4, -fSeitenL / 2.0f);
	glTexCoord2f(0, 1); glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f / 4);
	glEnd();


	glBegin(GL_POLYGON);   //Linke Seite Oben
	glNormal3f(0.0f, 0.0f, 0.0f);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f); //BLAU
	glTexCoord2f(0, 0); glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f / 4);
	glTexCoord2f(1, 0); glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f / 4, -fSeitenL / 2.0f);
	glTexCoord2f(1, 1); glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f / 4, +fSeitenL / 2.0f);
	glTexCoord2f(0, 1); glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glEnd();

	glBegin(GL_POLYGON);   // Scheibe Oben
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f); //BLAU
	glTexCoord2f(0, 0); glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f / 4, -fSeitenL / 2.0f);
	glTexCoord2f(1, 0); glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f / 4);
	glTexCoord2f(1, 1); glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f / 4);
	glTexCoord2f(0, 1); glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f / 4, -fSeitenL / 2.0f);
	glEnd();

	glBegin(GL_POLYGON);   // Scheibe Oben
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f); //BLAU
	glTexCoord2f(0, 0); glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f / 4, -fSeitenL / 2.0f);
	glTexCoord2f(1, 0); glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f / 4);
	glTexCoord2f(1, 1); glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f / 4);
	glTexCoord2f(0, 1); glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f / 4, -fSeitenL / 2.0f);
	glEnd();

	glBegin(GL_POLYGON);   //Deckflaeche
	glNormal3f(0.0f, 1.0f, 0.0f);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f); //BLAU
	glTexCoord2f(0, 0); glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glTexCoord2f(1, 0); glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glTexCoord2f(1, 1); glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f / 4);
	glTexCoord2f(0, 1); glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f / 4);
	glEnd();

	glBegin(GL_POLYGON);   //Bodenflaeche
	glNormal3f(0.0f, -1.0f, 0.0f);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f); //BLAU
	glTexCoord2f(0, 0); glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f / 4);
	glTexCoord2f(1, 0); glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f / 4);
	glTexCoord2f(1, 1); glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glTexCoord2f(0, 1); glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glEnd();
}

void PolygonGenerator::createSphere(GLfloat r, int lats, int longs)
{
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f); //BLAU
	GLUquadricObj *quadObj;

	quadObj = gluNewQuadric();
	gluQuadricDrawStyle(quadObj, GLU_FILL);
	gluQuadricNormals(quadObj, GLU_SMOOTH);
	gluSphere(quadObj, 0.2, 24, 4);
}


void PolygonGenerator::createCylinder(GLfloat radius, GLfloat height)
{
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f); //BLAU
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
			glBindTexture(GL_TEXTURE_2D, hull);
			createCockpit(0.4);
		glPopMatrix();
	
		// Shuttlekörper
		glPushMatrix();
			glScalef(3,1,1);
			glTranslatef(-0.22,0,0);
			glBindTexture(GL_TEXTURE_2D, hull);
			createCube(0.4);
		glPopMatrix();

		// Shuttle Hinten Flügel Rechts
		glPushMatrix();
			glRotatef(-35, 0, 1, 0);
			glScalef(1.5, 0.5, 5);
			glTranslatef(-0.5, 0, -0.10);
			glBindTexture(GL_TEXTURE_2D, hull);
			createPropeller(0.4);
		glPopMatrix();

		// Shuttle Hinten Flügel Links
		glPushMatrix();
			glRotatef(215, 0, 1, 0);
			glScalef(1.5, 0.5, 5);
			glTranslatef(0.5, 0, -0.10);
			glBindTexture(GL_TEXTURE_2D, hull);
			createPropeller(0.4);
		glPopMatrix();

	
		glRotatef(propellerRotationSpeed += rotationSpeed, 1, 0, 0);
		glPushMatrix();
			// Halterung der Propeller
			glPushMatrix();
			glTranslatef(-0.1, 0, 0);
			glRotatef(90, 0,1,0);
			glBindTexture(GL_TEXTURE_2D, hull);
			createCylinder(2, 0.4);
			glPopMatrix();

			// Kugelabdeckung von der Halterung
			glPushMatrix();
			glTranslatef(-0.1, 0, 0);
			glBindTexture(GL_TEXTURE_2D, hull);
			createSphere(2, 0.4, 10);
			glPopMatrix();

			// Oberer Propeller
			glPushMatrix();
			glScalef(0.1, 1, 0.1);
			glTranslatef(-0.2, 0.3, 0.0);
			glBindTexture(GL_TEXTURE_2D, carbon);
			createCube(0.4);
			glPopMatrix();


			// Unterer Propeller Propeller
			glPushMatrix();
			glScalef(0.1, 1, 0.1);
			glTranslatef(-0.2, -0.3, 0);
			glBindTexture(GL_TEXTURE_2D, carbon);
			createCube(0.4);
			glPopMatrix();

			// Hinten rechter Propeller
			glPushMatrix();
			glRotatef(90, 1,0,0);
			glScalef(0.1, 1, 0.1);
			glTranslatef(-0.2, -0.3, 0);
			glBindTexture(GL_TEXTURE_2D, carbon);
			createCube(0.4);
			glPopMatrix();

			// Hinten linker Propeller
			glPushMatrix();
			glRotatef(90, 1, 0, 0);
			glScalef(0.1, 1, 0.1);
			glTranslatef(-0.2, 0.3, 0);
			glBindTexture(GL_TEXTURE_2D, carbon);
			createCube(0.4);
			glPopMatrix();
		glPopMatrix();

	glPopMatrix();


}