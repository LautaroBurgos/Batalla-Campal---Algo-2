#include "coordenada.hpp"
#include <iostream>

using namespace std;

Coordenada::Coordenada(int largo, int ancho, int alto){
    this->largo = largo;
    this->ancho = ancho;
    this->alto = alto;
}

Coordenada::Coordenada(){
    this->largo = 0;
    this->ancho = 0;
    this->alto = 0;
}

void Coordenada::setLargo(int largo){
    this->largo = largo;
}

void Coordenada::setAncho(int ancho){
    this->ancho = ancho;
}

void Coordenada::setAlto(int alto){
    this->alto = alto;
}


int Coordenada::getLargo(){
    return (this->largo);
}

int Coordenada::getAncho(){
    return (this->ancho);
}

int Coordenada::getAlto(){
    return (this->alto);
}

Coordenada::~Coordenada(){

}
