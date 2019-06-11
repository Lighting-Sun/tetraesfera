#pragma once
#include "nodo.h" 
#include<stdio.h>


class listaver
{
public:
	
	nodo *prime;
	nodo *ultim;



	void generar();
	void Agregar(float verx, float very, float verz);
	void Eliminar();

	void Eliminarultim();

	bool Listavacia(){ return prime == NULL; }
	void Mostrar();
	void Siguiente();
	void Primero();
	void Ultimo();
	int conteo();


	void Elimbuscar(int,int,int);
	


	void Obtcaras(int);


	int size = 0;
	int carilla = 0;

	float tAB ;
	float tBC ;
	float tCA ;


	int vai = 0;
	int vbi = 0;
	int vci = 0;

	int vcx = 0;
	int vcy = 0;
	int vcz = 0;



	float vertex(int);
	float vertey(int);
	float vertez(int);
	
	listaver();
	~listaver();




};

