#ifndef PARTIDA_H_
#define PARTIDA_H_

#include <cstdlib>
#include "tablero.hpp"
#include "jugador.hpp"

const int MINIMO_JUGADORES= 2;
const int MAXIMO_JUGADORES= 10;
const int MINIMO_SOLDADOS= 2;
const int MAXIMO_SOLDADOS= 10;
const int MINIMO_LARGO_ANCHO_TABLERO= 2;
const int MAXIMO_LARGO_ANCHO_TABLERO= 1000;
const int MINIMO_ALTO_TABLERO= 2;
const int MAXIMO_ALTO_TABLERO= 20;
const int CANTIDAD_MAPAS= 4;
const int CANTIDAD_CARTAS_POR_JUGADOR= 4;
const int CANTIDAD_DISTINTA_CARTAS = 6;

class Partida{
private:
    Tablero* tablero;
    Jugador** jugadores;
    Carta** mazoDeCartas;

    unsigned int cantidadDeJugadores;
    unsigned int cantidadDeSoldadosPorJugador;
    unsigned int turno;
    unsigned int nroMapa;

    // PRE: 
    // POST: Solicita al usuario los datos necesarios de la partida
    void pedirDatos(unsigned int& largo, unsigned int& ancho, unsigned int& alto);

    // PRE: Ingreso de entero sin signo mayor o igual a 2
    // POST: solicita y valida si el dato ingresado es un entero sin signo, y lo retorna
    unsigned int ingresarNumeroYValidar(int minimo, int maximo);

    // PRE:
    // POST: crea punteros a Carta. Agrega cartas en forma aleatoria al vector de punteros a carta.
    void inicializarMazo();

    // PRE: mazo haya sido creado
    // POST: saca una carta en orden
    void sacarCartaDelMazo(unsigned int nroJugador);

    // PRE:
    // POST: 
    void activarCarta(Carta* carta);

    void activarCartaSomnifero();

    void activarCartaHarakiri(unsigned int nroJugadorEnTurno);

    // PRE: 
    // POST: Asigna soldados al iniciar la partida, pidiendo al usuario las coordenadas correspondientes.
    void inicializarSoldadosAJugadores();

public:
    // PRE: -
    // POST: Crea una partida
    Partida();

    // PRE:
    // POST: 
    void inicializarPartida();

    // PRE: - 
    // POST: Devuelve la cantidad de jugadores
    unsigned int getCantidadJugadores();

    // PRE: - 
    // POST: Devuelve la cantidad de jugadores con soldados en la partida, aviones y barcos no cuentan.
    unsigned int getCantidadJugadoresConSoldados();

    // PRE:
    // POST
    unsigned int getCantidadDeSoldadosPorJugador();

    // PRE:
    // POST: Devuelve el turno actual de la partida
    int getTurno();

    // PRE: 
    // POST: Se juega el siguiente turno de la partida, añade uno a la cantidad de turnos
    void siguienteTurno();

    // PRE: La nueva cantidad de jugadores no puede ser mayor a la anterior
    // POST: En caso de tener que cambiar o reducir la cantidad de jugadores, cambiamos la cantidad de jugadores por una nueva
    // es necesario?
    void setCantidadJugadores(int cantidadNueva);

    // PRE: -
    // POST: Solicita datos de una coordenada para realizar un ataque, retorna el casillero
    Casillero* pedirCoordenadasAtaque();

    // PRE: Las coordenadas deben ser validas, entre 1 y el tamaño del tablero.
    // POST: Solicita datos de una coordenada para colocar una unidad, retorna el casillero correspondiente
    Casillero* pedirCoordenadasUnidad(TipoDeUnidad tipo);

    // PRE:
    // POST:
    void asignarUnidadAlCasillero(Jugador* jugador, int nroUnidad, TipoDeUnidad tipo);

    // PRE:
    // POST:
    bool esSoldado(Unidad unidad);

    // PRE: 
    // POST: jugador realiza disparos dependiendo del a cantidad de unidades y del tipo de unidades que posea
    void realizarDisparosJugador(unsigned int nroJugador, unsigned int disparos);

    // PRE: casillero de tablero valido
    // POST: realiza un disparo, elimina posible unidad e inhabilita el casillero
    void realizarDisparoACasillero(Casillero* casillero);

    // PRE: casillero de tablero valido
    // POST: realiza disparos en un volumen de 27 casillero, elimina posible unidad e inhabilita el casillero
    void lanzarMisilesJugador(unsigned int nroJugador, unsigned int cantMisiles);

    // PRE: coordenadas validas
    // POST: Devuelve true si la coordenada2 es vecina de la coordenada1
    bool esCoordenadaVecina(Coordenada* coordenada1, Coordenada* coordenada2);

    // PRE: 
    // POST: jugador elije una unidad y realiza un movimiento con ella
    // Jugador ingresa el numero de unidad para obtener su posicion, luego
    // usar pedirCoordenadasUnidad() y asignarUnidadAlCasillero()
    void moverUnidad(unsigned int nroJugador);
    
    // PRE: 
    // POST: se crea un archivo bitmap con el mapa de la partida
    // al comenzar el turno para un jugador se exporta el tablero para el solo
    void exportarTablero(unsigned int nroJugador);

    // PRE
    // POST: chequea si el juego ha terminado
    bool haTerminado();

    // PRE: indice del jugador que no posee soldados
    // POST: Las unidades que han quedado, emprenden retirada. Libera memoria
    void jugadorEmprendeRetirada(unsigned int nroJugador);

    // PRE:
    // POST: devuelve el jugador ganador de la partida, en caso de que haya terminado en empate retorna 0;
    unsigned int jugadorGanador();

    // PRE:
    // POST: Destruye la partida
    virtual ~Partida();
};

#endif