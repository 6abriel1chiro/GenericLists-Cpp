

#include "NodoGenerico.h"
#include "ListaGenerica.h"
#include "Persona.h"
void test()
{
	ListaGenerica<Persona> clientes;
	clientes.registrar(new Persona( "pepe",111, 898989));
	clientes.registrar(new Persona( "andrea",222, 546432));
	clientes.registrar(new Persona( "sofia",333, 66532));

	clientes.sort(Persona::compCiAsc);
	clientes.mostrar(Persona::mostrarT);
	Persona* p = new Persona(111);

	clientes.buscar(p)->mostrar();
	//clientes.removeFirst();
	clientes.deleteNode(p);
	cout << " - - -- - -" << endl;
	clientes.mostrar(Persona::mostrarT);






}
int main()
{
	test();
}