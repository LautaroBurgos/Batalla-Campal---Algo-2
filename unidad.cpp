#include <iostream>
#include "unidad.hpp"
#include "coordenada.hpp"

Unidad::Unidad(TipoDeUnidad tipo, unsigned int nroUnidad, Coordenada* posicion){
    this->tipo = tipo;
    this->nroUnidad = nroUnidad;
    this->posicion = posicion;
}

TipoDeUnidad Unidad::getTipoDeUnidad(){
    return this->tipo;
}

unsigned int Unidad::getNroUnidad(){
    return this->nroUnidad;
}

Coordenada* Unidad::getPosicion(){
    return this->posicion;
}

void Unidad::setPosicionUnidad(Coordenada* posicion){
    this->posicion = posicion;
}

std::string Unidad::imprimirTipo(TipoDeUnidad tipo){
    if(tipo == soldado){
        return "soldado";
    }else if(tipo == barco){
        return "barco";
    }else{
        return "avion";
    }
}


Unidad::~Unidad(){
    // TODO
}