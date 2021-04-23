#include "Persona.h"

Persona::Persona(int ci)
{
	this->ci = ci;
}

Persona::Persona(string nombre, int ci, long telf)
{
	this->nombre = nombre;
	this->ci = ci;
	this->telf = telf;

}

Persona::~Persona()
{


}

void Persona::mostrar()
{
	cout << "nombre : " << endl;
	cout << nombre << endl;
	cout << "ci : " << ci << endl;
	cout << "telf  : " << telf << endl;
}

void Persona::mostrarT(Persona* p)
{
	if (p != NULL)
	{
		p->mostrar();
	}
	else { cout << " vacio " << endl; }

}

int Persona::getCi()
{
	return ci;
}

bool Persona::operator==(Persona* persona)
{
	return ci == persona->ci;
}

bool Persona::compCiAsc(Persona* p1, Persona* p2)
{
	return p1->getCi() > p2->getCi();
}

bool Persona::compCiDesc(Persona* p1, Persona* p2)
{
	return p1->getCi() < p2->getCi();
}


