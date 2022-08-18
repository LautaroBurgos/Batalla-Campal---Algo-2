#include "visuales.hpp"
#include "EasyBMP.h"
#include <iostream>

void dibujarCasillerosVertical(BMP &Tablero){
	for(int x=0;x<Tablero.TellWidth();x+=10){
		for(int y=0;y<Tablero.TellHeight();y++){
			Tablero(x,y)->Red=0;
			Tablero(x,y)->Green=0;
			Tablero(x,y)->Blue=0;
		}
	}
}
void dibujarCasillerosHorizontal(BMP &Tablero){
	for(int y=0;y<Tablero.TellHeight();y+=10){
		for(int x=0;x<Tablero.TellWidth();x++){
			Tablero(x,y)->Red=0;
			Tablero(x,y)->Green=0;
			Tablero(x,y)->Blue=0;
		}
	}
}
void dibujarCasilleros(BMP &Tablero){
	dibujarCasillerosHorizontal(Tablero);
	dibujarCasillerosVertical(Tablero);
}
void adaptarMedidas(unsigned int &ancho,unsigned int &largo){
	largo=largo*10;
	ancho=ancho*10;
}
void establecerMedidas(BMP &Tablero,unsigned int &ancho,unsigned int &largo){
	adaptarMedidas(ancho,largo);
	Tablero.SetSize(ancho,largo);
}
void crearBMPTablero(BMP &TableroVisual,unsigned int ancho,unsigned int largo){
	establecerMedidas(TableroVisual,ancho,largo);
	dibujarCasilleros(TableroVisual);
}
void pintarArea(BMP &Tablero,int xInicial,int xFinal,int yInicial,int yFinal,int r,int g,int b){
		for(int x=0;x<Tablero.BMP::TellWidth();x++){
			for(int y=0;y<Tablero.BMP::TellHeight();y++){
				if(((x>=xInicial)&&(x<xFinal))&&((y>=yInicial)&&(y<yFinal))){
					Tablero(x,y)->Red=r;
					Tablero(x,y)->Green=g;
					Tablero(x,y)->Blue=b;
 				}
			}
		}
}

void crearBMPSoldado(BMP &Soldado){
	Soldado.SetSize(9,9);
	pintarArea(Soldado,0,10,0,10,113,85,52);
	pintarArea(Soldado,4,5,2,7,0,255,35);
	pintarArea(Soldado,2,7,4,5,0,255,35);
	pintarArea(Soldado,3,4,7,9,0,255,35);
	pintarArea(Soldado,5,6,7,9,0,255,35);
}

void crearBMPAvion(BMP &Avion){
	Avion.SetSize(9,9);
	pintarArea(Avion,0,10,0,10,255,255,255);
	pintarArea(Avion,4,5,2,7,0,0,0);
	pintarArea(Avion,3,6,7,8,0,0,0);
	pintarArea(Avion,2,7,4,5,0,0,0);
	pintarArea(Avion,3,6,3,4,0,0,0);
}

void crearBMPBarco(BMP &Barco){
	Barco.SetSize(9,9);
	pintarArea(Barco,0,10,0,10,0,0,255);
	pintarArea(Barco,4,5,2,8,0,0,0);
	pintarArea(Barco,3,4,3,7,0,0,0);
	pintarArea(Barco,5,6,3,7,0,0,0);
}
void crearBMPUnidades(BMP &Soldado,BMP &Barco,BMP &Avion){
	crearBMPSoldado(Soldado);
	crearBMPBarco(Barco);
	crearBMPAvion(Avion);
}
void crearBMPTierra(BMP &Tierra){
	Tierra.SetSize(9,9);
	pintarArea(Tierra,0,10,0,10,113,85,52);
}
void crearBMPAgua(BMP &Agua){
	Agua.SetSize(9,9);
	pintarArea(Agua,0,10,0,10,0,0,255);
}
void crearBMPAire(BMP &Aire){
	Aire.SetSize(9,9);
	pintarArea(Aire,0,10,0,10,255,255,255);
}
void crearBMPTInhabilitado(BMP &TInhabilitado){
	TInhabilitado.SetSize(9,9);
	pintarArea(TInhabilitado,0,10,0,10,0,0,0);
}
void crearBMPTiposTerreno(BMP &Tierra,BMP &Agua,BMP &Aire,BMP &TInhabilitado){
	crearBMPTierra(Tierra);
	crearBMPAgua(Agua);
	crearBMPAire(Aire);
	crearBMPTInhabilitado(TInhabilitado);
}
void adaptarValoresBMP(int &xInicial,int &yInicial){
	xInicial=1+MAX_ANCHO_CASILLERO*(xInicial-1);
	yInicial=1+MAX_ALTO_CASILLERO*(yInicial-1);
}
void copiarBMPAlMapa(BMP &Mapa,BMP Modificacion,int xInicial,int yInicial){
	int x,y,auxiliar;
	adaptarValoresBMP(xInicial,yInicial);
	auxiliar=yInicial;

	int xFinal=xInicial+MAX_ANCHO_CASILLERO-1;
 	int yFinal=yInicial+MAX_ALTO_CASILLERO-1;

 	x=0;

	for(;xInicial<xFinal;xInicial++){
		y=0;
		for(;yInicial<yFinal;yInicial++){
			PixelToPixelCopy(Modificacion,x,y,Mapa,xInicial,yInicial);
			y++;

		}
		x++;
		yInicial=auxiliar;
	}
}