#include <GL/freeglut.h>
#include <GL/SOIL.h>
#include <iostream>
#include "CubeMap.h"

void CubeMap::initCubeMap()
{

	Back = SOIL_load_OGL_texture("textures/cubemap/Back.png", SOIL_FLAG_POWER_OF_TWO |SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	if (Back == 0) 
	{
		std::cout << "Textur Back konnte nicht geladen werden" << std::endl;
		printf("SOIL loading error: '%s'\n", SOIL_last_result());
	}

	Front = SOIL_load_OGL_texture("textures/cubemap/Front.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	if (Front == 0)
	{
		std::cout << "Textur Front konnte nicht geladen werden" << std::endl;
	}

	Bottom = SOIL_load_OGL_texture("textures/cubemap/Bottom.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	if (Bottom == 0)
	{
		std::cout << "Textur Bottom konnte nicht geladen werden" << std::endl;
	}

	Top = SOIL_load_OGL_texture("textures/cubemap/Top.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	if (Top == 0)
	{
		std::cout << "Textur Top konnte nicht geladen werden" << std::endl;
	}

	Left = SOIL_load_OGL_texture("textures/cubemap/Left.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	if (Left == 0)
	{
		std::cout << "Textur Left konnte nicht geladen werden" << std::endl;
	}

	Right = SOIL_load_OGL_texture("textures/cubemap/Right.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	if (Right == 0)
	{
		std::cout << "Textur Right konnte nicht geladen werden" << std::endl;
	}


}

void CubeMap::createVertizes(GLfloat fSeitenL)
{

	cubeMapList = glGenLists(1);
	glNewList(cubeMapList, GL_COMPILE);

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, Front);
	glBegin(GL_POLYGON);   //Vorderseite
	//glColor4f(1.0f, 1.0f, 1.0f, 1.0f)
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, Right);
	glBegin(GL_POLYGON);   //Rechte Seite
	//glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, Back);
	glBegin(GL_POLYGON);   //Rueckseite
	//glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, Left);
	glBegin(GL_POLYGON);   //Linke Seite
	//glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, Top);
	glBegin(GL_POLYGON);   //Deckflaeche
	//glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glTexCoord2f(0.0f, 1.0f);	 glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, Bottom);
	glBegin(GL_POLYGON);   //Bodenflaeche
	//glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glEnd();

	glPopMatrix();
	glEndList();

	return;
}

void CubeMap::drawCubeMap()
{
	glDepthMask(false);
	glDisable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);
	glCallList(cubeMapList);
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_LIGHTING);
	glDepthMask(true);

}