#ifndef JUGADOR_H_
#define JUGADOR_H_

#include "carta.hpp"
#include "lista.hpp"
#include "unidad.hpp"
#include "coordenada.hpp"


class Jugador{
private: 
    unsigned int nroJugador;
    //Carta* cartas;

    Lista<Unidad*>* unidades;
    unsigned int cantidadSoldados;
    unsigned int cantidadAviones;
    unsigned int cantidadBarcos;
    unsigned int cantidadTotalUnidades;

    unsigned int cantidadDisparosDisponibles;
    unsigned int cantidadMisilesDisponibles;
    bool misilAdicionalEnProximoTurno;

    unsigned int cantidadTurnosInhabilitado;
    bool gano; 
    
public:
    // PRE: ingresar un numero unico identificador
    // POST: crea un jugador
    Jugador(unsigned int numeroJugador);

    // PRE: 
    // POST: devuelve el numero de jugador
    unsigned int getNumeroJugador();

    // PRE:
    // POST: retorna la cantidad total de unidades que el jugador ha poseido a lo largo del juego
    unsigned int getCantidadTotalUnidades();

    // PRE: ingreso de una unidad de batalla que ya ha sido creado con memoria dinamica
    // POST: añade la unidad a la lista de unidades
    void asignarUnidad(Unidad* unidadDeBatalla);

    // PRE
    // POST: retorna la primer unidad en la lista de unidades
    Unidad* buscarPrimerUnidad();

    // PRE: ingreso del ID de una unidad de batalla
    // POST: busca la unidad en la lista de punteros a unidad
    Unidad* buscarUnidad(unsigned int numeroDeUnidad);

    // PRE: ingresar una unidad
    // POST: Remueve la unidad de la lista de unidades, disminuye en uno la cantidad del tipo de unidad.
    void removerUnidad(Unidad* unidad);

    // PRE: 
    // POST: devuelve los disparos que el jugador tiene disponible dependiendo del tipo de unidad
    unsigned int getCantidadDisparosDisponibles();

    // PRE: 
    // POST: devuelve los misiles que el jugador tiene disponible dependiendo del tipo de unidad
    unsigned int getCantidadMisilesDisponibles();

    // PRE:
    // POST: añade un misil a la cantidad de misiles para el proximo turno (carta)
    void agregarMisilProximoTurno();

    // PRE: 
    // POST: Se inhabilita al jugador por un turno mas
    void inhabilitarPorUnTurno();

    // PRE: 
    // POST: retorna si el jugador puede jugar en el turno. En caso de estar inhabilitado, descuenta el turno en cantidadTurnosInhabilitado
    bool estaHabilitado();

    // PRE: 
    // POST: retorna si el jugador posee soldados y por tanto sigue en juego
    bool poseeSoldados();

    // PRE: exista el jugador
    // POST: 
    virtual ~Jugador();
};

#endif