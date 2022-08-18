#ifndef UNIDAD_H_
#define UNIDAD_H_

#include <iostream>
#include "coordenada.hpp"

enum TipoDeUnidad{
    soldado,
    avion,
    barco
};

class Unidad{
private:
    TipoDeUnidad tipo;
    unsigned int nroUnidad;
    Coordenada* posicion;

public:
    // PRE: posicion valida dentro del tablero.
    // POST: crea una unidad con un tipo, numero y posicion
    Unidad(TipoDeUnidad tipo, unsigned int nroUnidad, Coordenada* posicion);

    // PRE: 
    // POST: devuelve el tipo de unidad
    TipoDeUnidad getTipoDeUnidad();

    // PRE: 
    // POST: devuelve el ID de la unidad
    unsigned int getNroUnidad();

    // PRE: 
    // POST: devuelve un puntero a la posicion de la unidad
    Coordenada* getPosicion();

    // PRE: posicion valida, distinta de NULL. Tablero se encarga de validar las coordenadas.
    // POST: Cambia la posicion de la unidad.
    void setPosicionUnidad(Coordenada* posicion);

    // PRE:
    // POST: imprime el tipo de unidad por consola
    static std::string imprimirTipo(TipoDeUnidad);

    // PRE: -
    // POST: elimina la unidad
    virtual ~Unidad();
};

#endif