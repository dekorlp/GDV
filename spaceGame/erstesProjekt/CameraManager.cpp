#include <GL/freeglut.h>         //lädt alles für OpenGL
#include <GL/SOIL.h>
#include "CameraManager.h"
#include <cmath>

CameraManager::CameraManager()
{

}

CameraManager::CameraManager(ViewOptions options, GLuint viewPortWidth, GLuint viewPortheight)
{
	switch (options)
	{
		case ViewOptions::orthograpic:
			this->viewOption = ViewOptions::orthograpic;
			break;
		case ViewOptions::perspective:
			this->viewOption = ViewOptions::perspective;
			break;
	}
	this->oldMousePositionX = viewPortWidth / 2;
	this->oldMousePositionY = viewPortheight / 2;

	pitch = 43.9;
	yaw = 114.73;

	this->viewPortheight = viewPortheight;
	this->viewPortWidth = viewPortWidth;
}

void CameraManager::reshapeDisplay(GLdouble nearPlane, GLdouble farPlane)
{
	switch (this->viewOption)
	{
	case ViewOptions::orthograpic:
			//glOrtho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near, GLdouble far);
			glOrtho(-1., 1., -1., 1., nearPlane, farPlane);
		break;
	case ViewOptions::perspective:
			gluPerspective(45., 1., nearPlane, farPlane);
		break;
	}
}

void CameraManager::setCameraPosition(GLdouble cameraPositionX, GLdouble cameraPositionY, GLdouble cameraPositionZ)
{
	this->cameraPositionX = cameraPositionX;
	this->cameraPositionY = cameraPositionY;
	this->cameraPositionZ = cameraPositionZ;
}

void CameraManager::setCameraLookAtPosition(GLdouble viewAtPositionX, GLdouble viewAtPositionY, GLdouble viewAtPositionZ)
{
	this->viewAtPositionX = viewAtPositionX;
	this->viewAtPositionY = viewAtPositionY;
	this->viewAtPositionZ = viewAtPositionZ;
}

void CameraManager::repositionCamera()
{
	gluLookAt(this->cameraPositionX, this->cameraPositionY, this->cameraPositionZ, this->viewAtPositionX, this->viewAtPositionY,this->viewAtPositionZ, 0., 1., 0.); // // Ansicht Schräg oben
}

void CameraManager::setThirdPersonCamera(float mouseX, float mouseY)
{
	//= 43.9;
	// = 114.73;

	float offsetX = mouseX - oldMousePositionX;
	float offsetY = oldMousePositionY - mouseY;

	oldMousePositionX = mouseX;
	oldMousePositionY = mouseY;

	float sensitivity = 0.005;

	offsetX *= sensitivity;
	offsetY *= sensitivity;

	

	pitch -= offsetY;
	yaw += offsetX;

	if (pitch >= 35.0f)
		pitch = 35.0f;

	if (pitch < -35.0f)
		pitch = -35.0f;

	

	cameraPositionX = 10 * cos(pitch) * cos(yaw);
	cameraPositionY = 10 * sin(pitch);
	cameraPositionZ = 10 * cos(pitch) * sin(yaw);
}

GLfloat CameraManager::getYaw()
{
	return this->yaw;
}

GLfloat CameraManager::getPitch()
{
	return this->pitch;
}