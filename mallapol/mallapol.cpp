// mallapol.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "listaver.h"
#include "objmalla.h"
#include <iostream>
#include "glut.h"


using namespace std;

void tetraedro();
void Render();
//void imprimir();


objmalla EZ;



float radio2 = 0;

double movZ = 0;
double movY = 0;
double giro;
double giro2;


float verticeva[];
float verticevb[];
float verticevc[];






int vfinal =0;
int cfinal = 0;

//void temporizador(int value){
//
//	glutPostRedisplay();
//	glutTimerFunc(15, temporizador, 0);
//	giro = 0.5;
//}

void TransformacionesCamara()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	/*glOrtho(-1, 1, -1, 1, 0.001, 1000);*/
	gluPerspective(45, 1, 0.001, 10000);
	glTranslated(0, movY, movZ);
	/*gluLookAt(4, -0.1, 0, 0, 0, 0, 0, 1, 0); */
	/*gluLookAt(0, 0, -45, 0, 0, 0, 0, 1, 0);*/
	gluLookAt(4, 1, 1, 0, 0, 0, 0, 1, 0);
}

void OnKey(unsigned char key, int x, int y)
{
	 //Ejemplo de modificacion del parametro de traslacion en z
	switch (key)
	{
	case 'i':
	case 'I':
		movZ += 0.1f;
		break;
	case 'k':
	case 'K':
		movZ -= 0.1f;
		break;
	case 'o':
	case 'O':
		movY += 0.1f;
		break;
	case 'l':
	case 'L':
		movY -= 0.1f;
		break;
	case 'a':
	case 'A':
		giro += 0.4f;
		break;
	case 'd':
	case 'D':
		giro -= 0.4f;
		break;
	case 'w':
	case 'W':
		
		EZ.Obtdata();

		break;
	case 's':
	case 'S':
		giro2 -= 0.4f;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}

void tetraedro(){

	
	EZ.NoTetraedro();


}


void Render()

{
	
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glViewport(0, 0, 400, 400);
	
		
	glPolygonMode(GL_BACK, GL_LINE);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	
	
	glEnable(GL_DEPTH_TEST);

	TransformacionesCamara();

	GLfloat mat_ambient[] = { 0.2, 0.2, 0.5, 1.0f };
	GLfloat mat_diffuse[] = { 1.0, 1.0, 1.0, 1.0f };
	GLfloat mat_specular[] = { 0.5, 0.5, 0.5, 0.5f };

	GLfloat lightPos[4] = { 0.0, 4.0, -0.2, 1.0};
	GLfloat ambiente[] = { 1.0,1.0,1.0};

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, 100.0f);


	glEnable(GL_LIGHTING);

	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_AMBIENT,ambiente);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

	glShadeModel(GL_FLAT);

	/*glShadeModel(GL_SMOOTH);*/
	
	glRotated(giro, 0, 1, 0);

	tetraedro();
	
	glColor3f(0.8, 0.6, 0.0);
	glTranslated(0,0, 2.0);
	glutSolidSphere(0.2, 30, 30);

	/*imprimir();*/

	
	glutSwapBuffers();

	glDisable(GL_DEPTH_TEST);
}
	

//void imprimir()
//{
//
//	cout << "ingrese la cara que desea buscar";
//	cin >> busc;
//	cara.Divcaras(busc);
//
//
//
//}


int _tmain(int argc, _TCHAR* argv[])
{
	EZ.graficar();

	glutInit(&argc, (char**)argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	/*glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);*/

	glutCreateWindow("Ejemplo OpenGL");
	glutReshapeWindow(400, 400);
	/*glutTimerFunc(15, temporizador, 0);*/
	glutDisplayFunc(Render);
	glutKeyboardFunc(OnKey);
	glDepthFunc(GL_LESS);
	glDepthRange(-2, 2);
	glutMainLoop();

	

	return 0;
}

