// GD-Praktikum:   teil_1.cpp  (Teil 1: Start-Programm)
// Hergenroether / Groch    Last Update: 05.07.2014

#include <iostream> 
#include <GL/freeglut.h>         //l�dt alles f�r OpenGL
#include "Wuerfel.h"

void Init()	
{
   // Hier finden jene Aktionen statt, die zum Programmstart einmalig 
   // durchgef�hrt werden m�ssen
	glEnable(GL_DEPTH_TEST);
	glClearDepth(1.0);
	glClearColor(1, 0.5, 0, 1);
	//glClearColor(0, 0, 0, 1);
}

float counter = 0;

void RenderScene() //Zeichenfunktion
{
   // Hier befindet sich der Code der in jedem Frame ausgefuehrt werden muss

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	
   glLoadIdentity ();   // Aktuelle Model-/View-Transformations-Matrix zuruecksetzen

   // Aufgabe 10: Welche Fl�che sehen Sie und warum sehen Sie gerade diese Fl�che?  -> R�ckseite

   //glTranslatef(0.,0., -1.);
   //gluLookAt(eyex, eyey, eyez, // Kamera-Position
   //centerx, centery, centerz,  // Betrachtete Position
   //upx, upy, upz);  // Kamera-View-Up-Vektor
   // gluLookAt(0., 0., 1., 0., 0., 0., 0., 1., 0.); // 1 Variante von Vorne
   // gluLookAt(0., 1., 1., 0., 0., 0., 0., 1., 0.); // 2 Variante von Vorne - Oben -> Backplane (2) musste um eins erh�ht werden, weil durch die Position der Abstand gr��er wurde-> Satz des Pythagoras
    //gluLookAt(1., 0., 0., 0., 0., 0., 0., 1., 0.); // 2 Variante von rechts -> Backplane (1) gen�gt
   gluLookAt(1., 1., 0., 0., 0., 0., 0., 1., 0.); // 2 Variante von rechts - Oben -> Backplane (2)

   //glTranslatef(4, 1, 3);
   Wuerfel(0.4);

   
   glutSwapBuffers();
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
	gluPerspective(45., 1., 0.1, 2.0);
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
   glutCreateWindow( "Dennis K�hler; Michael Klimek" );   // Fenster-Erzeugung
   glutDisplayFunc( RenderScene );         // Zeichenfunktion bekannt machen
   glutReshapeFunc( Reshape );
   // TimerCallback registrieren; wird nach 10 msec aufgerufen mit Parameter 0  
   glutTimerFunc( 10, Animate, 0);
   Init();
   glutMainLoop();
   return 0;
}
