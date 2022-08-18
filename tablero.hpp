#ifndef TABLERO_H_
#define TABLERO_H_

#include "lista.hpp"
#include "casillero.hpp"

const int PRIMER_MAPA = 1;
const int SEGUNDO_MAPA = 2;
const int TERCER_MAPA = 3;
const int CUARTO_MAPA = 4;

class Tablero{
private:
    unsigned int largo;
    unsigned int ancho;
    unsigned int alto;

    Lista<Lista<Lista<Casillero*>*>*>* tablero; 

public:

    //Pre: largo, ancho y alto deben ser mayores a 0
    //Post: Crea un tablero de juego
    Tablero(unsigned int largo, unsigned int ancho, unsigned int alto, int nroMapa);

    //Pre:
    //Post: Devuelve el largo del tablero
    int getLargo();

    //Pre:
    //Post: Devuelve el ancho del tablero
    int getAncho();

    //Pre: 
    //Post: Devuelve el alto del tablero
    int getAlto();
    
    //Pre:
    //Post: devuelve un puntero a casillero según las coordenadas que se indiquen
    Casillero* getCasillero(int largo, int ancho, int alto);

    //Pre:
    //Post:
    void crearPrimerMapa(int x,int y,int z,int largo,int ancho);
    
    //Pre:
    //Post:
    void crearSegundoMapa(int x,int y,int z,int largo,int ancho);
    
    //Pre:
    //Post:
    void crearTercerMapa(int x,int y,int z,int largo,int ancho);
    
    //Pre:
    //Post:
    void crearCuartoMapa(int x,int y,int z,int largo,int ancho);

    //Pre.
    //Post: Destruye el tablero
    virtual ~Tablero();
};




#endif /* TABLERO_H_ */