#pragma once
#include <iostream>
using namespace std;
template <class T>
class Nodo
{
private: 
	T* dato; //direccion de datos
	Nodo<T>* next;




public:
	Nodo(T* dato);
	~Nodo();

	T* getDato();
	Nodo<T>* getNext();

	void createNext(T* dato);


};

template<class T>
inline Nodo<T>::Nodo(T* dato)
{
	this->dato = dato;
	next = NULL;
}

template<class T>
inline Nodo<T>::~Nodo()
{
}

template<class T>
inline T* Nodo<T>::getDato()
{
	return dato;
}

template<class T>
inline Nodo<T>* Nodo<T>::getNext()
{
	return next;
}

template<class T>
inline void Nodo<T>::createNext(T* dato)
{
	next = new	Nodo<T>(dato);

}
