// GD-Praktikum:   teil_1.cpp  (Teil 1: Start-Programm)
// Hergenroether / Groch    Last Update: 05.07.2014

#include <iostream> 
#include <GL/freeglut.h>         //lädt alles für OpenGL
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
 
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	GLfloat light_position[] = { -5, 2, 5, 0. };
	glLightfv(GL_LIGHT0, GL_POSITION, light_position); // Licht Nr. 0 rechts oben

	glEnable(GL_COLOR_MATERIAL);


	glEnable(GL_DEPTH_TEST);
	glClearDepth(1.0);
	

	glEnable(GL_NORMALIZE);
}

float counter = 0;

float tesst = 0;

void RenderScene() //Zeichenfunktion
{
	float cameraPositionX = 1; // Vorne: 0. 0. 6.
	float cameraPositionY = 3.; // Schräg Oben: 1 3. 3.
	float cameraPositionZ = -10; // Schräg unten: 1. -2. 3.

   // Hier befindet sich der Code der in jedem Frame ausgefuehrt werden muss

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity ();   // Aktuelle Model-/View-Transformations-Matrix zuruecksetzen

	//glRotatef(tesst+= 0.1, 0, 1, 0);
	gluLookAt(cameraPositionX, cameraPositionY, cameraPositionZ, 0., 0., 0., 0., 1., 0.); // // Ansicht Schräg oben

	// Schiffskoerper
	glPushMatrix();
	//glTranslatef(0.5, 1.5, 1.5);
	//glTranslatef(5,0,0);
	
	glRotatef(fRotation, 0, 1, 0);
	glTranslatef(2., 0, 2.);
	glRotatef(90, 1, 0, 0);
	//glScalef(2, 2, 2);
	//polgen.createSphere(1.0, 10, 10);
	//polgen.createCube(0.4);
	//polgen.createCockpit(0.4);
	//polgen.createPropeller(0.4);
	polgen.createCylinder(1.0, 10);
	glPopMatrix();
	

   
	// Skybox with texture
	glPushMatrix();
	cubemap.drawCubeMap();
	glPopMatrix();


	
   
   
   
	glutSwapBuffers();
	glFlush();
}

void Reshape(int width,int height)
{
   // Hier finden die Reaktionen auf eine Veränderung der Größe des 
   // Graphikfensters statt

	// Matrix für Transformation: Frustum->viewport 
	glMatrixMode(GL_PROJECTION);
	// Aktuelle Transformations-Matrix zuruecksetzen 
	glLoadIdentity();
	// Viewport definieren  
	glViewport(0, 0, width, height);
	// Frustum definieren (siehe unten)
	//glOrtho( GLdouble left, GLdouble right,   GLdouble bottom, GLdouble top,   GLdouble near, GLdouble far ); 
	//glOrtho(-1., 1., -1., 1., 0.0, 2.0);
	gluPerspective(45., 1., 0.1, 2048);
	// Matrix für Modellierung/Viewing 
	glMatrixMode(GL_MODELVIEW);
}

void Animate (int value)    
{
   // Hier werden Berechnungen durchgeführt, die zu einer Animation der Szene  
   // erforderlich sind. Dieser Prozess läuft im Hintergrund und wird alle 
   // 1000 msec aufgerufen. Der Parameter "value" wird einfach nur um eins 
   // inkrementiert und dem Callback wieder uebergeben. 
   std::cout << "value=" << value << std::endl;

   // Rotationsvariable akke 1000msec ändern
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
   glutCreateWindow( "Dennis Köhler; Michael Klimek" );   // Fenster-Erzeugung
   glutDisplayFunc( RenderScene );         // Zeichenfunktion bekannt machen
   glutReshapeFunc( Reshape );
   // TimerCallback registrieren; wird nach 10 msec aufgerufen mit Parameter 0  
   glutTimerFunc( 10, Animate, 0);
   Init();
   glutMainLoop();
   return 0;
}
