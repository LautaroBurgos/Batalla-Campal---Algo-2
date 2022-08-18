#include <iostream>
#include "carta.hpp"
#include "coordenada.hpp"
#include "jugador.hpp"
#include "tablero.hpp"
#include "partida.hpp"

using namespace std;

const int EN_JUEGO = 1;
const int FINALIZADO = -1;

int main(){
    try{
        Partida* partida = new Partida();

        partida->inicializarPartida();

        while(!partida->haTerminado()){
            partida->siguienteTurno();
        }

        /*
        // OBTENER GANADOR DEL JUEGO, si no hay ganador el juego termino en empate
        if(partida.getEstado() == FINALIZADO){
            cout << "Juego finalizado, gana el jugador: " << jugadorActual.getNroJugador();
        }
        */
        delete partida;
    }catch(const char* e){
        cout << endl << e << endl ;
    }
    return 0;
}
