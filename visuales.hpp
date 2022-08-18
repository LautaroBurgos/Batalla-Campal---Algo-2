#ifndef VISUALES_H_ 
#define VISUALES_H_
#include "EasyBMP.h"
#include <iostream>
const int MAX_ANCHO_CASILLERO=10;
const int MAX_ALTO_CASILLERO=10;
const int NIVEL_SUELO=1;
/*
	PRE:
	POST:Dibuja las lineas que verticales de los casilleros
*/
void dibujarCasillerosVertical(BMP &Tablero);
/*
	PRE:
	POST:dibuja las lineas horizontales de los casilleros.
*/
void dibujarCasillerosHorizontal(BMP &Tablero);
/*
	PRE:
	POST:dibuja los casilleros de 10x10 pixeles en el tablero bmp
*/
void dibujarCasilleros(BMP &Tablero);
/*
	PRE:
	POST: Multiplica por 10 el largo y el ancho del tablero. 
*/
void adaptarMedidas(unsigned int &ancho,unsigned int &largo);

/*
	PRE:
	POST:Establece las medidas en pixeles que va a tener el bmp del tablero.
*/
void establecerMedidas(BMP &Tablero,unsigned int &ancho,unsigned int &largo);
/*

	
	PRE:largo y ancho deben ser valores enteros.
		Numero mapa debe ser un numero entre 1 y 4 inclusive.
	POST:segun los valores que reciba de las dimensiones alto y ancho ,elige un Tablero al azar de los 4 tipos 
	prediseñados y lo crea del tamaño deseado.
	.
		
*/
void crearBMPTablero(BMP &TableroVisual,unsigned int ancho,unsigned int largo);
/*
		PRE:Todas las variables de coordenadas x e y deben tener un valor valido acorde al tamaño del tablero BMP.
		Las variables r,g y b deben tener un valor entre 0 y 255.
		POST:colorea una imagen BMP en las coordenadas marcadas,
		Desde un x a otro(sin incluir el final)
		Desde un y a otro(sin incluir el final)
		Y del color deseado segun las variables r,g,b que segun sus distintos valores formaran un color.
*/
void pintarArea(BMP &Tablero,int xInicial,int xFinal,int yInicial,int yFinal,int r,int g,int b);
/*
	PRE:
	POST:dibuja un soldado en el objeto BMP "Soldado".
*/
void crearBMPSoldado(BMP &Soldado);
/*
	PRE:
	POST:dibuja un avion en el objeto BMP "Avion".
*/
void crearBMPAvion(BMP &Avion);
/*
	PRE:
	POST:dibuja un barco en el BMP "Barco"
*/
void crearBMPBarco(BMP &Barco);
/*
	PRE:
	POST: Los objetos bmp de soldado,barco y avion quedan con su correcto dibujo.
*/
void crearBMPUnidades(BMP &Soldado,BMP &Barco,BMP &Avion);
/*
	PRE:
	POST:
*/
void crearBMPTierra(BMP &Tierra);
/*
	PRE:
	POST:
*/
void crearBMPAgua(BMP &Agua);
/*
	PRE:
	POST:
*/
void crearBMPAire(BMP &Aire);
/*
	PRE:
	POST:
*/
void crearBMPTInhabilitado(BMP &TInhabilitado);

/*
	PRE:
	POST:
*/
void crearBMPTiposTerreno(BMP &Tierra,BMP &Agua,BMP &Aire,BMP &TInhabilitado);
/*
	PRE:
	POST: Adapta los valores de fila y columna de un casillero para posteriormente se efectue un cambio en el BMP Mapa.
*/
void adaptarValoresBMP(int &xInicial,int &yInicial);
/*
	PRE:
	POST:Copia un BMP de 9x9 a un casillero determinado del mapa. Este BMP puede ser unidades(soldado,barco o avion)
	o tipos de terreno (agua,tierra, aire o terreno inhabilitado).
*/
void copiarBMPAlMapa(BMP& Mapa,BMP Modificacion,int xInicial,int yInicial);
#endif