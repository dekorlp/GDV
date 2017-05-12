// GD-Praktikum:   teil_1.cpp  (Teil 1: Start-Programm)
// Hergenroether / Groch    Last Update: 05.07.2014

#include <iostream> 
#include <GL/freeglut.h>         //l�dt alles f�r OpenGL
#include <GL/SOIL.h>
#include "WuerfelTextured.h"
#include "Wuerfel.h"
#include "CubeMap.h"
#include "PolygonGenerator.h"

float fRotation = 315.0;
CubeMap cubemap;
PolygonGenerator polgen;

void Init()	
{
	glClearColor(0.33f, 0.225f, 0.0f, 1.0f);

	cubemap.initCubeMap();
	cubemap.createVertizes(2048, 2048, 2048);
 
	polgen.initPolygonGenerator();

	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	GLfloat light_position[] = { -5, 2, 5, 0. };
	glLightfv(GL_LIGHT0, GL_POSITION, light_position); // Licht Nr. 0 rechts oben

	glEnable(GL_COLOR_MATERIAL);

	glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glEnable(GL_DEPTH_TEST);
	glClearDepth(1.0);
	

	glEnable(GL_NORMALIZE);
}

float tesst = 0;

void RenderScene() //Zeichenfunktion
{
	float cameraPositionX = 0; // Vorne: 0. 0. 6.
	float cameraPositionY = 0; // Schr�g Oben: 1 3. 3.
	float cameraPositionZ = -10; // Schr�g unten: 1. -2. 3.

   // Hier befindet sich der Code der in jedem Frame ausgefuehrt werden muss

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity ();   // Aktuelle Model-/View-Transformations-Matrix zuruecksetzen

	//glRotatef(tesst+= 0.1, 0, 0, 1);
	gluLookAt(cameraPositionX, cameraPositionY, cameraPositionZ, 0., 0., 0., 0., 1., 0.); // // Ansicht Schr�g oben

	glRotatef(tesst += 0.2, 0, 1, 0);

	glEnable(GL_TEXTURE_2D);
	polgen.createShip(3);
	glDisable(GL_TEXTURE_2D);


	// Skybox with texture
	glPushMatrix();
	cubemap.drawCubeMap();
	glPopMatrix();
   
	glutSwapBuffers();
	glFlush();
}

void Reshape(int width,int height)
{
   // Hier finden die Reaktionen auf eine Ver�nderung der Gr��e des 
   // Graphikfensters statt

	// Matrix f�r Transformation: Frustum->viewport 
	glMatrixMode(GL_PROJECTION);
	// Aktuelle Transformations-Matrix zuruecksetzen 
	glLoadIdentity();
	// Viewport definieren  
	glViewport(0, 0, width, height);
	// Frustum definieren (siehe unten)
	//glOrtho( GLdouble left, GLdouble right,   GLdouble bottom, GLdouble top,   GLdouble near, GLdouble far ); 
	//glOrtho(-1., 1., -1., 1., 0.0, 2.0);
	gluPerspective(45., 1., 0.1, 2048);
	// Matrix f�r Modellierung/Viewing 
	glMatrixMode(GL_MODELVIEW);
}

void Animate (int value)    
{
   // Hier werden Berechnungen durchgef�hrt, die zu einer Animation der Szene  
   // erforderlich sind. Dieser Prozess l�uft im Hintergrund und wird alle 
   // 1000 msec aufgerufen. Der Parameter "value" wird einfach nur um eins 
   // inkrementiert und dem Callback wieder uebergeben. 
   std::cout << "value=" << value << std::endl;

   // Rotationsvariable akke 1000msec �ndern
   fRotation = fRotation - 1.0;  // Rotationswinkel aendern
   if (fRotation <= 0.0)
   {
	   fRotation = fRotation + 360.0;
   }

   // RenderScene aufrufen
   glutPostRedisplay();
   // Timer wieder registrieren - Animate wird so nach 10 msec mit value+=1 aufgerufen.
   int wait_msec = 10;
   glutTimerFunc(wait_msec, Animate, ++value);
}

int main(int argc, char **argv)
{
   glutInit( &argc, argv );                // GLUT initialisieren
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize( 1024,  1080);         // Fenster-Konfiguration
   glutCreateWindow( "Dennis K�hler; Michael Klimek" );   // Fenster-Erzeugung
   glutDisplayFunc( RenderScene );         // Zeichenfunktion bekannt machen
   glutReshapeFunc( Reshape );
   // TimerCallback registrieren; wird nach 10 msec aufgerufen mit Parameter 0  
   glutTimerFunc( 10, Animate, 0);
   Init();
   glutMainLoop();
   return 0;
}
