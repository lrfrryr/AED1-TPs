//


#ifndef AJEDREZLITE_AUXILIARES_H
#define AJEDREZLITE_AUXILIARES_H

#include "definiciones.h"

using namespace std;
// definir aqui las funciones

//ejercicio 1:
bool esPosicionValida (pair < tablero, int > posicion);

//ejercicio 2:
bool esPosicionInicial (pair < tablero, int > posicion);

//ejercicio 3:
vector <coordenada> sonCasillasAtacadas (posicion const &p, int j);

//ejercicio 4:
bool posicionSiguiente (pair < tablero, int > p, pair < tablero, int > q, pair < int, int > o, pair < int, int > d);

//ejercicio 5:
void ordenarFila (vector < casilla > &fila);

//ejercicio 6:
bool esFinDeLaPartida (posicion p, int &j);

//ejercicio 7:
bool esJaqueDescubierto (posicion p);

//ejercicio 8:
void ejecutarSecuencia (posicion &p, secuencia s);

//ejercicio 9:
int vaASerJaqueEn (posicion const & p);

pair<int,int> mp(int a, int b);

vector<pair<int,int>> ordenarVectorPares(vector<pair<int,int>> &v);
tablero inicializarTablero();
coordenada setCoord(int i, int j);
tablero tableroActual ( posicion const &p );
#endif //AJEDREZLITE_AUXILIARES_H
