#pragma once
#include <iostream>
using namespace std;
class Persona
{


private:
	string nombre;
	int ci;
	long telf;

public:
	Persona(int ci);
	Persona(string nombre, int ci, long telf);
	~Persona();
	void mostrar();
	static void mostrarT(Persona* p);
	int getCi();
	bool operator==(Persona* persona);


	static bool compCiAsc(Persona* p1, Persona* p2);
	static bool compCiDesc(Persona* p1, Persona* p2);

	//static bool compNomAsc(Persona* p1, Persona* p2);
	//static bool compNomDesc(Persona* p1, Persona* p2);










};

