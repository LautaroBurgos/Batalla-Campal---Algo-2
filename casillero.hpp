#ifndef CASILLERO_H_
#define CASILLERO_H_

#include "coordenada.hpp"
#include "jugador.hpp"
#include "unidad.hpp"
#include <iostream>

enum EstadoDeCasillero{
    inhabilitado,
    vacio,
    ocupado
};

enum TipoTerreno{
    tierra,
    agua,
    aire
};

class Casillero{
private:
    Coordenada* posicion;
    EstadoDeCasillero estado;
    TipoTerreno tipoTerreno;
    Jugador* jugador;
    Unidad* unidad;

public:
    // PRE: posicion de coordenada valida
    // POST: se crea un casillero en una posicion valida con un tipo de terreno.
    Casillero(int fila, int columna, int altura, TipoTerreno tipo);

    // PRE: 
    // POST: retorna la coordenada del casillero
    Coordenada* getCoordenada();

    // PRE
    // POST: retorna el estado del casillero
    EstadoDeCasillero getEstado();
    
    // PRE: 
    // POST: cambia el estado del casillero
    void setEstado(EstadoDeCasillero);
   
    // PRE: 
    // POST: devuelve el tipo de terreno
    TipoTerreno getTipoDeTerreno();
    
    // PRE: 
    // POST: agrega el jugador cuya unidad se encuentra en el casillero
    void setJugador(Jugador* jugador);
        
    // PRE: 
    // POST: retorna el jugador cuya unidad se encuentra en el casillero
    Jugador* getJugador();
    
    // PRE: 
    // POST: coloca la unidad en el casillero
    void setUnidad(Unidad* unidad);

    // PRE:
    // POST: devuelve un puntero a la unidad que se encuentra en el casillero
    Unidad* getUnidad();

    // PRE:
    // POST: coloca en NULL los punteros y cambia el estado del casillero
    void inhabilitar();

    // PRE: exista un casillero
    // POST: elimina el casillero y la coordenada asociada
    virtual ~Casillero();
};


#endif