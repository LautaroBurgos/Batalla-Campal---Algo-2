#ifndef COORDENADA_H_
#define COORDENADA_H_

#include <iostream>

class Coordenada{
private:
    int largo;
    int ancho;
    int alto;

public:

    //Pre:
    //Post:
    Coordenada(int largo, int ancho, int alto);

    //Pre:
    //Post:
    Coordenada();

    //Pre:
    //Post:
    void setLargo(int largo);

    //Pre:
    //Post:
    void setAncho(int ancho);

    //Pre:
    //Post:
    void setAlto(int alto);

    //Pre:
    //Post:
    int getLargo();

    //Pre:
    //Post:
    int getAncho();

    //Pre:
    //Post:
    int getAlto();

    //Pre:
    //Post:
    virtual ~Coordenada();
    
};

#endif