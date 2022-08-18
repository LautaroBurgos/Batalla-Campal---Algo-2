#ifndef LISTA_H_
#define LISTA_H_

#ifndef NULL
#define NULL 0
#endif /* NULL */

#include "nodo.hpp"

template<class T> class Lista{
private:

	Nodo<T>* primero;
	unsigned int tamanio;
	Nodo<T>* cursor;
	
public:
	Lista();
	Lista(Lista<T> &otraLista);
	bool vacia()const;
	unsigned int contarElementos()const;
	void add(T elemento);
	void add(T elemento, unsigned int posicion);
	void add(Lista<T> &otraLista);
	T get(unsigned int posicion);
	void asignar(T elemento, unsigned int posicion);
	void remover(unsigned int posicion);
	void reiniciarCursor();
	bool avanzarCursor();
	T getCursor()const;
	~Lista();

private:
	Nodo<T>* getNodo(unsigned int posicion)const;
};


/*	IMPLEMENTACIÓN	*/

/* PUBLIC: */

/* POST: Crea una Lista vacía */
template<class T> Lista<T>::Lista(){
	this->primero = NULL;
	this->tamanio = 0;
	this->cursor = NULL;
}

/* POST: Lista 'this' se hace igual a lista pasada por parámetro. */
template<class T> Lista<T>::Lista(Lista<T> &otraLista){
	this->primero = NULL;
	this->tamanio = 0;
	this->cursor = NULL;
	this->add(otraLista);
}

/* POST: Devuelve true en caso que la lista esté vacía. */
template<class T> bool Lista<T>::vacia()const{
	return (this->tamanio == 0);
}

/* POST: Devuelve la cantidad de elementos de la lista. */
template<class T> unsigned int Lista<T>::contarElementos()const{
	return (this->tamanio);
}

/* POST: Añade un elemento al final de la lista (posición contarElementos() + 1). */
template<class T> void Lista<T>::add(T elemento){
	this->add(elemento, this->tamanio + 1);
}

/* PRE: La posición está entre [1, contarElementos() + 1].
  POST: Agrega el elemento en la posición pasada. */
template<class T> void Lista<T>::add(T elemento, unsigned int posicion){
	if((posicion > 0) && (posicion <= this->tamanio + 1)){ /* posición válida */
		Nodo<T>* nuevoNodo = new Nodo<T>(elemento);
		if(posicion == 1){
			nuevoNodo->setSiguiente(this->primero);
			this->primero = nuevoNodo;
		} else{
			Nodo<T>* nodoAnterior = this->getNodo(posicion - 1);
			nuevoNodo->setSiguiente(nodoAnterior->getSiguiente());
			nodoAnterior->setSiguiente(nuevoNodo);
		}
		this->tamanio ++;
		this->reiniciarCursor();
	}
}

/* POST: Agrega todos los elementos de la lista pasada al final de la lista,
  * eso es desde la posición contarElementos() + 1. */
template<class T> void Lista<T>::add(Lista<T> &otraLista){
	otraLista.reiniciarCursor();
	while(otraLista.avanzarCursor()){
		this->add(otraLista.getCursor());
	}
}

/* PRE: La posición está entre [1, contarElementos()].
 * POST: Devuelve el elemento en esa posición. */
template<class T> T Lista<T>::get(unsigned int posicion){
	if((posicion <= 0) || (posicion > this->tamanio)){
		throw "POSICION INVALIDA";
	}
	return (this->getNodo(posicion)->getValor());
}

/* PRE: La posición está entre [1, contarElementos()].
 * POST: Cambia elemento en esa posición a elemento pasado. */
template<class T> void Lista<T>::asignar(T elemento, unsigned int posicion){
	if((posicion > 0) && (posicion <= this->tamanio)){
		this->getNodo(posicion)->setValor(elemento);
	}
}

/* PRE: La posición está entre [1, contarElementos()].
 * POST: Elimina el elemento en esa posición de la lista. */
template<class T> void Lista<T>::remover(unsigned int posicion){
	if((posicion > 0) && (posicion <= this->tamanio)){
		Nodo<T>* nodoRemovido;
		if(posicion == 1){
			nodoRemovido = this->primero;
			this->primero = this->primero->getSiguiente();
		} else{
			Nodo<T>* nodoAnterior = this->getNodo(posicion - 1);
			nodoRemovido = nodoAnterior->getSiguiente();
			nodoAnterior->setSiguiente(nodoRemovido->getSiguiente());
		}
		delete nodoRemovido;
		this->tamanio --;
		this->reiniciarCursor();
	}
}

/* POST: Deja el cursor listo para una nueva iteración. */
template<class T> void Lista<T>::reiniciarCursor(){
	this->cursor = NULL;
}

/* Permite mover el cursor de un nodo al siguiente.
 * PRE: Se ha iniciado la iteración (mediante el método reiniciarCursor()),
 * y no se han agregado ni eliminado elementos desde entonces.
 * POST: Mueve el cursor al siguiente elemento en la iteración.
 * El valor devuelto indica si el cursor ahora se encuentra en un elemento o no,
 * (en caso de que la lista esté vacía o no haya más elementos). */
template<class T> bool Lista<T>::avanzarCursor(){
	if(this->cursor == NULL){
		this->cursor = this->primero;
	} else{
		this->cursor = this->cursor->getSiguiente();
	}
	return (this->cursor != NULL);
}

/* PRE: El cursor está sobre un elemento de la lista,
 * (se llamó al método avanzarCursor() y se devolvió "true").
 * POST: Devuelve el elemento en la posición del cursor. */
template<class T> T Lista<T>::getCursor()const{
	if(this->cursor == NULL){
		throw "CURSOR ESTA NULL";
	}
	return (this->cursor->getValor());
}

/* POST: Libera recursos asociados a la lista. */
template<class T> Lista<T>::~Lista(){
	while(this->primero != NULL){
		Nodo<T>* nodoRemovido = this->primero;
		this->primero = this->primero->getSiguiente();
		delete nodoRemovido;
	}
}

/* PRIVATE: */

/* PRE: La posición está entre [1, contarElementos()].
 * POST: Devuelve el nodo en esa posición (puntero). */
template<class T> Nodo<T>* Lista<T>::getNodo(unsigned int posicion)const{
	Nodo<T>* nodoActual = this->primero;
	for(unsigned int i = 1; i < posicion; i++){
		nodoActual = nodoActual->getSiguiente();
	}
	return nodoActual;
}


#endif /* LISTA_H_ */