// GD-Praktikum:   teil_1.cpp  (Teil 1: Start-Programm)
// Hergenroether / Groch    Last Update: 05.07.2014

#include <iostream> 
#include <GL/freeglut.h>         //lädt alles für OpenGL
#include <GL/SOIL.h>
#include "CameraManager.h"
#include "CubeMap.h"
#include "PolygonGenerator.h"

float fRotation = 315.0;
CubeMap cubemap;
PolygonGenerator polgen;
CameraManager cameraManager;

//float xRotation = 0;

void Init()	
{
	glClearColor(0.33f, 0.225f, 0.0f, 1.0f);

	cubemap.initCubeMap(); // laden der Texturen
	cubemap.createVertizes(2048, 2048, 2048); // erstellen der vertizes
 
	polgen.initPolygonGenerator(); // laden der texturen

	
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 }; // Farbmischung des Lichts ->weiß
	GLfloat mat_shininess[] = { 50.0 }; // Größe des Lichts
	GLfloat light_position[] = { 5, 3, 5, 0. }; // Lichtposition
	glShadeModel(GL_SMOOTH); //Gouraid Shading

	glLightfv(GL_LIGHT0, GL_POSITION, light_position); // Licht Nr. 0 rechts oben
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);

	glEnable(GL_COLOR_MATERIAL);

	glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glEnable(GL_DEPTH_TEST);
	glClearDepth(1.0);
	

	glEnable(GL_NORMALIZE);
}

//float oldPitch = 114.73;
//float tesst = 0;

float positionShip1X = 0;
float positionShip1Z = 0;

float positionShip2X = 0;
float positionShip2Z = 0;
float positionShip2Y = 0;

float positionShip3X = 0;
float positionShip3Z = 0;

bool renderShip2;

bool renderShip3;

void RenderScene() //Zeichenfunktion
{
	//float cameraPositionX = 0; // Vorne: 0. 0. 6.
	//float cameraPositionY = 0; // Schräg Oben: 1 3. 3.
	//float cameraPositionZ = -10; // Schräg unten: 1. -2. 3.

	//cameraManager.setCameraPosition(0,0, -10);
	//cameraManager.setCameraLookAtPosition(0, 0, 0);
	//cameraManager.setThirdPersonCamera();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity ();   // Aktuelle Model-/View-Transformations-Matrix zuruecksetzen

	//glRotatef(tesst+= 0.1, 0, 0, 1);
	cameraManager.repositionCamera();


		glPushMatrix();
			glRotatef(45, 0,1,0);
			glTranslatef(5,-3,0);
			glTranslatef(positionShip1X-=0.02, 0, positionShip1Z+= 0.01);
			if (positionShip1Z >= 5)
			{
				renderShip2 = true;
			}
			polgen.createShip(3);
		glPopMatrix();

		if (renderShip2 == true)
		{
			
			glPushMatrix();
				glRotatef(150, 0, 1, 0);
				glRotatef(-15, 1, 0, 0);
				glTranslatef(5, -3, 0);
				glTranslatef(positionShip2X -= 0.02, positionShip2Y += 0.01, positionShip2Z -= 0.01);
				if (positionShip2Z <= -10)
				{
					renderShip3 = true;
				}
				polgen.createShip(3);
			glPopMatrix();
		}

		if (renderShip3 == true) // irgendwie ist die X und die Z Achse beim dritten Schiff vertauscht
		{
			glPushMatrix();
				glRotatef(-90, 0, 1, 0);
				glTranslatef(20, 0, -10);
				glTranslatef(positionShip3X -= 0.05, 0, positionShip3Z += 0.02);
				if (positionShip3X <= -30)
				{
					positionShip1X = 0;
					positionShip1Z = 0;

					positionShip2X = 0;
					positionShip2Z = 0;
					positionShip2Y = 0;

					positionShip3X = 0;
					positionShip3Z = 0;

				}
				polgen.createShip(3);
			glPopMatrix();

		}


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
	cameraManager.reshapeDisplay(0.1, 2048); // near Plane und far Plane setzen
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

void mouseMove(int x, int y) // wird aufgerufen wenn die Mau bewegt wird
{
	cameraManager.setThirdPersonCamera(x, y);
	//tesst += xRotation ;
}

int main(int argc, char **argv)
{
   glutInit( &argc, argv );                // GLUT initialisieren
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize( 1024,  1080);         // Fenster-Konfiguration
   cameraManager = CameraManager(ViewOptions::perspective, 1024, 1080);
   cameraManager.setCameraPosition(0, 0, -10);
   cameraManager.setCameraLookAtPosition(0, 0, 0);


   glutCreateWindow( "Dennis Köhler; Michael Klimek" );   // Fenster-Erzeugung
   glutDisplayFunc( RenderScene );         // Zeichenfunktion bekannt machen
   glutReshapeFunc( Reshape );
   // TimerCallback registrieren; wird nach 10 msec aufgerufen mit Parameter 0  
   glutTimerFunc( 10, Animate, 0);

   glutPassiveMotionFunc(mouseMove);
   Init();
   glutMainLoop();
   return 0;
}
