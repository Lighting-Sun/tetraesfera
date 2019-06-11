#pragma once
class nodo
{
public:

	float verticex;
	float verticey;
	float verticez;
	nodo *siguiente = NULL;
	


	nodo(float,float,float,nodo *sig= NULL);

	

	~nodo();
};



