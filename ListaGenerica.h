#pragma once
#include <list>
#include "NodoGenerico.h"
template <class T>
class ListaGenerica
{
private:

	Nodo<T>* first;
	Nodo<T>* last;
	int len;

public:
	ListaGenerica();
	~ListaGenerica();

	int getLen();

	void removeFirst();

	void registrar(T* dato);

	void mostrar(void (*mostrarT)(T*));
	T* buscar(T* dato);


	bool isEmpty();

	void sort(bool(*sortBy)(T*, T*));

	void swap (Nodo<T>* a, Nodo<T>* b);



	void deleteNode(T* dato);
	void destroyList();


};

template<class T>
inline ListaGenerica<T>::ListaGenerica()
{
	first = NULL;
	last = NULL;
	len = 0;
}

template <class T>
void ListaGenerica<T>::destroyList()
{
	Nodo<T>* temp;						//pointer to deallocate the 
									//  memory occupied by the node
	while (first != NULL)			//while there are nodes in the list
	{
		temp = first;				//set temp to the current node
		first = first->getNext();	//advance first to the next node
		delete temp;				//deallocate the memory occupied by temp
	}

	last = NULL;	//iniitialize last to NULL
					//  (first has already been set to NULL
					//		by the while loop)
	len = 0;
}



template<class T>
inline ListaGenerica<T>::~ListaGenerica()
{

	//destroyList();
}

template<class T>
inline int ListaGenerica<T>::getLen()
{
	return len;
}
template <class T>
bool ListaGenerica<T>::isEmpty()
{
	return (first == NULL);
}


template<class T>
inline void ListaGenerica<T>::sort(bool(*sortBy)(T*, T*))
{
	Nodo<T>* aux;
	Nodo<T>* nextAux;
	Nodo<T>* temp;
	bool sorted = false;
	while (!sorted)
	{
		sorted = true;
		aux = first;
		nextAux = aux->getNext();
		while (aux->getNext() != NULL)
		{
			if ((*sortBy)(aux->getDato(),nextAux->getDato()))
			{
				sorted = false;
				swap(aux, nextAux);
				 //*(temp->getDato()) = *(aux->getDato());
				 //*(aux->getDato()) = *(nextAux->getDato());
				 //*(nextAux->getDato()) = *(temp->getDato());
			}
			aux = nextAux;
			nextAux = nextAux->getNext();
		}
	}


}





template<class T>
inline void ListaGenerica<T>::swap(Nodo<T>* a, Nodo<T>* b)
{
	Nodo<T> aux = *a;
	*a = *b;
	*b = aux;

}





template<class T>
inline void ListaGenerica<T>::removeFirst()
{

	if (first == NULL)			//CASE 1; list is empty
		cout << "vacio."<<endl;
	else  //CASE 2: delete first node 
	{			
		this->first = this->first->getNext();
	}
}

	template<class T>
inline void ListaGenerica<T>::registrar(T* dato)
{
	if (first == NULL)
		first = new Nodo<T>(dato);
	else
	{
		Nodo<T>* aux = first;
		while (aux->getNext()!=NULL)
		{
			aux = aux->getNext();

		}
		aux->createNext(dato);
	}
	len++;

}

template<class T>
inline void ListaGenerica<T>::mostrar(void(*mostrarT)(T*))
{

	Nodo<T>* aux = first;
	while (aux != NULL)
	{
		(*mostrarT)(aux->getDato());
		aux = aux->getNext();

	}


}


template<class T>
T* ListaGenerica<T>::buscar(T* dato)
{
	Nodo<T>* aux = first;
	while (aux != NULL)
	{
		if (*(aux->getDato())==dato)
		{
			return aux->getDato();
		}
		aux = aux->getNext();

	}
	return nullptr;

}


template <class T>
void ListaGenerica<T>::deleteNode(T* dato)
{
	Nodo<T>* current;				//pointer to traverse the list
	Nodo<T>* trailCurrent;			//pointer just before current
	bool found;

	if (first == NULL)			//CASE 1; list is empty
		cerr << "vacio." << endl;
	else
	{							//CASE 2: delete first node 
		if (*(first->getDato()) == dato)
		{
			current = first;
			first = first->getNext();
			len--;
			if (first == NULL)   //list has only one node
				last = NULL;
			delete current;
		}
		else  //search the list for the node with the given info
		{
			found = false;
			trailCurrent = first;		//set trailCurrent to point to
										//  the first node
			current = first->getNext(); //set current to point to the 
										//  second node

			while (current != NULL && !found)
			{
				if (!(*(current->getDato()) == dato))
				{
					trailCurrent = current;
					current = current->getNext();
				}
				else
					found = true;
			} // end while

			if (found) //CASE 3; if found, delete the node
			{
				trailCurrent->createNext( current->getNext()->getDato() );
				len--;

				if (last == current)			//node to be deleted was 
											//  the last node
					last = trailCurrent;	//update the value of last

				delete current;				//delete the node from the list
			}
			else
				cout << "Item to be deleted is not in the list." << endl;
		}
	}
}
