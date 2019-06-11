#include "stdafx.h"
#include "listaver.h"
#include "nodo.h"
#include <iostream>
#include "GL/glut.h"

using namespace std;

//listaver vertice;
//listaver cara;




listaver::listaver()
{
	prime = ultim = NULL;
}



void listaver::Agregar(float verx, float very, float verz)  {

	nodo *aux = new nodo(verx, very, verz, prime);
	if (Listavacia ())
	{
		prime = ultim = aux;
	}
	else
	{
			ultim->siguiente = aux;
			ultim = aux;
	}
	carilla++;
}

float listaver::vertex(int unoa){
	
	float compx=0;

	nodo *aux = prime;

	for (int i = 0; i <= unoa; i++)
	{
		if (i == 0)
		{
		compx = aux->verticex;
		}
		else
		{
		aux = aux->siguiente;
		compx = aux->verticex;
		}
	}
	return compx;
	}


float listaver::vertey(int dosb){

	float compy=0;

	nodo *aux = prime;
	for (int i = 0; i <= dosb ; i++)
	{
		if (i == 0)
		{
		compy = aux->verticey;
		}
		else
		{
			aux = aux->siguiente;
			compy = aux->verticey;
		}
	}
	return compy;
}

float listaver::vertez(int tresc){

	float compz=0;

	nodo *aux = prime;
	for (int i = 0; i <= tresc; i++)
	{
		if (i == 0)
		{
			compz = aux->verticez;
		}
		else
		{
			aux = aux->siguiente;
			compz = aux->verticez;
		}
	}
	return compz;
}


void listaver::Obtcaras(int carai){


	nodo *aux = prime;

	for (int i = 0; i <= carai; i++)
	{
		if (i == 0)
		{

			vai = aux->verticex;
			vbi = aux->verticey;
			vci = aux->verticez;
			
		}
		else
		{
			
			vai = aux->verticex;
			vbi = aux->verticey;
			vci = aux->verticez;
			
			
		}
		
	}
	aux = aux->siguiente;

	vcx = vai;
	vcy = vbi;
	vcz = vci;

	/*cout << vai << ", " << vbi << ", " << vci;*/

}





void listaver::Eliminar(){
	
	if (Listavacia()== true)
	{
		"La lista se encuentra vacia";
	}
	else
	{
		if (prime == ultim)
		{
			prime = ultim = NULL;
			cout << "elemento eliminado";
		}
		else
		{
			nodo *aux = prime;
			prime = prime->siguiente;
			delete aux;
			cout << "elemento eliminado";
		}
	}	
}


void listaver::Eliminarultim(){



	if (Listavacia()== true)
	{
		"La lista se encuentra vacia";
	}
	else
	{
			nodo *aux = prime;
			while (aux != NULL)
			{
				if (prime == ultim)
				{
					prime = ultim = NULL;
					cout << "elemento eliminado";
				}
				else if (aux->siguiente==ultim)
				{
					nodo *temp = ultim;

					ultim = aux;
					ultim->siguiente = NULL;
					delete temp;
					
					cout << "elemento eliminado";
				}
				aux = aux->siguiente;
			}

		}
	}	



void listaver::Elimbuscar(int verx,int very,int verz){

	
	nodo *aux = prime;
	if (verx == aux->verticex && very == aux->verticey && verz == aux->verticez)
	{

		cout << endl;
		cout << endl;
		cout << aux->verticex << " , " << aux->verticey << " , " << aux->verticez;
		cout << endl;
		cout << endl;
		prime = prime->siguiente;
		delete aux;

		cout << "elemento eliminado";
		cout << endl;
		cout << endl;

	}
	else
	{
		while (verx != (aux->siguiente)->verticex && very != (aux->siguiente)->verticey && verz != (aux->siguiente)->verticez)
		{
			aux = aux->siguiente;
		};

		cout << endl;
		cout << endl;
		cout << (aux->siguiente)->verticex << " , " << (aux->siguiente)->verticey << " , " << (aux->siguiente)->verticez;
		cout << endl;
		cout << endl;


		nodo *temp = aux->siguiente;
		aux->siguiente = (aux->siguiente)->siguiente;
		delete temp;
		
	}



}



void listaver::Mostrar(){
	nodo *aux = prime;
	while (aux != NULL)
	{
		cout << aux->verticex << ", " << aux->verticey << " , " << aux->verticez;
		aux = aux->siguiente;
		cout << endl;
	}
}


int listaver::conteo(){

	
	int contador = 0;
	nodo *aux = prime;
	
	size = 0;

	while (aux != NULL)
	{
		contador++;
		aux = aux->siguiente;
		
	}
	size = contador;

	contador = 0;

	return size;

	
}



listaver::~listaver()
{
	nodo *aux;

	while (prime)
	{
		aux = prime;
		prime = prime->siguiente;
		delete aux;
	}
	ultim = NULL;
}
