#include "stdafx.h"
#include "listaver.h"
#include <iostream>
#include "GL/glut.h"
#include "objmalla.h"
#include "math.h"

using namespace std;

listaver vertice;
listaver cara;

float lado = (sqrt(3)*sqrt(2));
float radio = (sqrt(3) / 2);
float base = radio / 3;
float corte = sqrt(((sqrt(3) / 2)*(sqrt(3) / 2)) - ((radio / 3) * (radio / 3)));
float vertbasex = (sqrt(2) / 2);
float vertbasez = (sqrt(6) / 6);


int busc = 0;

int vfin = 0;

float verticeAB[3];
float verticeBC[3];
float verticeCA[3];



float CXx[];
float CXy[];
float CXz[];

int num;


int vaai = 0;
int vbbi = 0;
int vcci = 0;

objmalla::objmalla()
{


}


void objmalla::graficar(){

	vertice.Agregar(0, radio, 0.0);
	vertice.Agregar(vertbasex, -base, vertbasez);
	vertice.Agregar(-0, -base, -corte);
	vertice.Agregar(-vertbasex, -base, vertbasez);   //tetra yolo
	


	cara.Agregar(0, 1, 2);
	cara.Agregar(0, 3, 1);
	cara.Agregar(3, 2, 1);
	/*cara.Agregar(3, 2, 1);*/
	//cara.Agregar(1, 2, 3);
	cara.Agregar(0, 2, 3);
	//cara.Agregar(3, 2, 0);
}

void objmalla::Obtdata(){

	int var = cara.carilla;


	for (int i = 0; i < var; i++)
	{

		cara.Obtcaras(i);

		vaai = cara.vai;
		vbbi = cara.vbi;
		vcci = cara.vci;




		float verticeva[3] = { vertice.vertex(vaai), vertice.vertey(vaai), vertice.vertez(vaai) };
		float verticevb[3] = { vertice.vertex(vbbi), vertice.vertey(vbbi), vertice.vertez(vbbi) };
		float verticevc[3] = { vertice.vertex(vcci), vertice.vertey(vcci), vertice.vertez(vcci) };

		cout << endl;
		cout << endl;

		vertice.conteo();

		vfin = vertice.size-1;

		cout << endl;
		cout << vfin;

		cout << endl;






		//vertices medios
	

		for (int i = 0; i < 3; i++)
		{
			verticeAB[i] = verticeva[i] + (verticevb[i] - verticeva[i])*0.5;
		}

		for (int i = 0; i < 3; i++)
		{
			verticeBC[i] = verticevb[i] + (verticevc[i] - verticevb[i])*0.5;
		}

		for (int i = 0; i < 3; i++)
		{
			verticeCA[i] = verticevc[i] + (verticeva[i] - verticevc[i])*0.5;
		}
	
		/*conversion a esfera*/

		vertice.tAB = sqrt((radio * radio)/((verticeAB[0] * verticeAB[0]) + (verticeAB[1] * verticeAB[1]) + (verticeAB[2] * verticeAB[2])));


		for (int i = 0; i < 3; i++)
		{
			verticeAB[i] = verticeAB[i] * vertice.tAB;
		}

		vertice.tBC = sqrt((radio * radio)/((verticeBC[0] * verticeBC[0]) + (verticeBC[1] * verticeBC[1]) + (verticeBC[2] * verticeBC[2])));

		for (int i = 0; i < 3; i++)
		{
			verticeBC[i] = verticeBC[i] * vertice.tBC;
		}

		vertice.tCA = sqrt((radio * radio)/((verticeCA[0] * verticeCA[0]) + (verticeCA[1] * verticeCA[1]) + (verticeCA[2] * verticeCA[2])));

		for (int i = 0; i < 3; i++)
		{
			verticeCA[i] = verticeCA[i] * vertice.tCA;
		}



		//se añaden los nuevos vertices
		vertice.Agregar(verticeAB[0], verticeAB[1], verticeAB[2]);

		vertice.Agregar(verticeBC[0], verticeBC[1], verticeBC[2]);
		
		vertice.Agregar(verticeCA[0], verticeCA[1], verticeCA[2]);

		//cara X

		cara.Agregar(vaai, vfin + 1, vfin + 3);

	
		//cara y

		cara.Agregar(vbbi, vfin + 2, vfin + 1);


		////cara z 

		cara.Agregar(vcci, vfin + 3, vfin + 2);

		////cara k

		cara.Agregar(vfin+1, vfin + 2, vfin + 3);


		cout << endl;
		cout << endl;



		cara.Elimbuscar(vaai, vbbi, vcci);
		/*cara.Eliminar();*/

		/*cara.Eliminarultim();*/

		cara.carilla = cara.carilla-1;


	}


	
	//cout << "lista de caras";
	//cout << endl;
	//cout << endl;
	//cout << endl;
	//cara.Mostrar();


	

	

	//cara.Eliminar();

	/*cout << "vertice 1";
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
	cout << verticeva[i] << " ";
	}
	cout << endl;
	cout << endl;
	cout << "vertice 2";
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
	cout << verticevb[i] << " ";
	}
	cout << endl;
	cout << endl;
	cout << "vertice 3";
	cout << endl;

	for (int i = 0; i < 3; i++)
	{
	cout << verticevc[i] << " ";
	}
	cout << endl;
	cout << endl;*/



}



void objmalla::esfera(){





}





void objmalla::NoTetraedro(){

	


	glBegin(GL_TRIANGLES);


	float caras[3];
	for (int ci = 0; ci <= cara.carilla-1; ci++)
	{
		caras[0] = cara.vertex(ci);
		caras[1] = cara.vertey(ci);
		caras[2] = cara.vertez(ci);
		for (int vi = 0; vi < 3; vi++)
		{
			glVertex3f(vertice.vertex(caras[vi]), vertice.vertey(caras[vi]), vertice.vertez(caras[vi]));
		}

	}
	glEnd();


}

objmalla::~objmalla()
{
}
