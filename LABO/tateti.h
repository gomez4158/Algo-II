#ifndef _TATETI_H_
#define _TATETI_H_

#include <string>
#include <ostream>

using namespace std;

#define TAM_TABLERO 3

class Tateti{

public:

	// Constructor
	Tateti(const string& jugador1, const string& jugador2);
	
	// Intenta poner la ficha del jugador actual en la
	// posicion (i,j) del tablero
	// Devuelve true si la jugada se pudo realizar 
	// o false si la posicion era invalida
	//
	// @pre: 0 <= i , j < 3
	bool realizarJugada(unsigned short i, unsigned short j);

	// Devuelve true si el juego termino
	bool finalizado() const;

	// Devuelve el jugador actual
	const string& jugadorActual() const;

	// Devuelve el nombre del ganador
	// @pre: finalizado()
	const string& ganador() const;

	//Reincia el juego
	void reiniciar();

	//Funcion para mostrar el tablero hacia el output stream o
	friend ostream& operator<<(ostream& o, const Tateti& t); 

private:

	//Jugadores actuales
	string jugadores[2];

	//Tablero
	char tablero[3][3];

	//jugador actual
	int jActual;

	//Ganador
	int ganadorPartida;

	//Limpia el tablero
	void limpiarTablero();

	//Verifica si hay tateti desde la posicion (i,j)
	bool verificarGanador(unsigned short i, unsigned short j) const;
};

#endif
