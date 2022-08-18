#ifndef CARTAS_H_
#define CARTAS_H_

enum TipoDeCarta{
    Misil,
    NuevoAvion, 
    NuevoBarco,
    Somnifero,  //Stun por un turno
    Francotirador,   //Dispara matando un soldado enemigo
    Harakiri //Se te muere una unidad random
};

class Carta{
private:
    TipoDeCarta tipo;
public:
    //Pre:  TipoDeCarta pasado por parámetro debe ser Misil, Avion, Barco, Somnifero, Francotirador, o Harakiri.
    //Post: Crea una carta del tipo pasado por parámetro
    Carta(TipoDeCarta tipo);

    //Pre:
    //Post: retorna el tipo de carta.
    TipoDeCarta getTipo();
};

#endif