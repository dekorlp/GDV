// GD-Praktikum:   teil_1.cpp  (Teil 1: Start-Programm)
// Hergenroether / Groch    Last Update: 05.07.2014

#include <iostream> 
#include <GL/freeglut.h>         //lädt alles für OpenGL
#include "Wuerfel.h"

float fRotation = 315.0;
GLUquadricObj *quadric;

void Init()	
{
   // Hier finden jene Aktionen statt, die zum Programmstart einmalig 
   // durchgeführt werden müssen
	glEnable(GL_DEPTH_TEST);
	glClearDepth(1.0);
	glClearColor(1, 0.5, 0, 1);
	quadric = gluNewQuadric();
	
	//glClearColor(0, 0, 0, 1);
}

float counter = 0;

void RenderScene() //Zeichenfunktion
{
   // Hier befindet sich der Code der in jedem Frame ausgefuehrt werden muss

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	
   glLoadIdentity ();   // Aktuelle Model-/View-Transformations-Matrix zuruecksetzen

   // Aufgabe 10: Welche Fläche sehen Sie und warum sehen Sie gerade diese Fläche?  -> Rückseite

   //glTranslatef(0.,0., -1.);
   //gluLookAt(eyex, eyey, eyez, // Kamera-Position
   //centerx, centery, centerz,  // Betrachtete Position
   //upx, upy, upz);  // Kamera-View-Up-Vektor

   //gluLookAt(0., 0., 6., 0., 0., 0., 0., 1., 0.); // Ansicht von Vorne
   gluLookAt(1., 3., 3., 0., 0., 0., 0., 1., 0.); // // Ansicht Schräg oben
   //gluLookAt(1., -2., 3., 0., 0., 0., 0., 1., 0.); // // Ansicht Schräg unten



   glutWireCube(0.2);
   //glTranslatef(0.1, 0.1, 0.1);
   glPushMatrix();
   // Rotation des gesamten Arms um 45 Grad
   glTranslatef(0.1, 0.1, 0);
   glRotatef(fRotation, 0, 0, 1);
   

	   // Oberarm
	   glPushMatrix();
	  // glRotatef(-45, 0, 0, 1); // Aufgabe 12
	   //glTranslatef(0., 0., 0.);
	   glTranslatef(0.4, 0, 0);
	   glScalef(2., 1, 1.);
	   Wuerfel(0.4);
	   glPopMatrix();
   

	   // Unterarm
	   glPushMatrix();
	   //glRotatef(-45, 0, 0, 1); // Aufgabe 12
	   glTranslatef(1.2,0,0); // merkwürdig  mit 0.8 ????
	   glScalef(2., 0.35, 1.);
	   Wuerfel(0.4);
	   glPopMatrix();
   glPopMatrix();
   

   //glPushMatrix();

   //glTranslatef(0, -0.7, 0);

  // gluQuadricDrawStyle(quadric, GLU_FILL);
   //gluSphere(quadric, .5, 36, 18);
   //glPopMatrix();
   
   glutSwapBuffers();
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
	//glOrtho(-1., 1., -1., 1., 0.0, 10.0);
	gluPerspective(45., 1., 0.1, 10.0);
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
   glutInitWindowSize( 600, 600 );         // Fenster-Konfiguration
   glutCreateWindow( "Dennis Köhler; Michael Klimek" );   // Fenster-Erzeugung
   glutDisplayFunc( RenderScene );         // Zeichenfunktion bekannt machen
   glutReshapeFunc( Reshape );
   // TimerCallback registrieren; wird nach 10 msec aufgerufen mit Parameter 0  
   glutTimerFunc( 10, Animate, 0);
   Init();
   glutMainLoop();
   return 0;
}
