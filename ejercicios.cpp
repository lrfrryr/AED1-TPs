#include <algorithm>
#include "ejercicios.h"
#include "auxiliares.h"

// EJERCICIO 1
bool posicionValida ( pair < tablero, int > const &p ) {
    return (esPosicionValida(p));
}

// EJERCICIO 2
bool posicionInicial ( posicion const &p ) {
    return (esPosicionInicial(p));
}
// EJERCICIO 3

vector <coordenada> casillasAtacadas ( posicion const &p, int j ) {
    return (sonCasillasAtacadas(p,j));
}
// EJERCICIO 4
bool posicionSiguienteCorrecta ( posicion const &p1, posicion const &p2, coordenada o, coordenada d ) {
    return (posicionSiguiente(p1, p2, o, d));
}
// EJERCICIO 5
void ordenarTablero ( posicion &p ) {
    for (int i = 0; i < 8; i++) {

        ordenarFila(p.first[i]);
    }
    return;
}
// EJERCICIO 6
bool finDeLaPartida ( posicion const &p, int &j) {
    return (esFinDeLaPartida(p, j));
}
// EJERCICIO 7
bool hayJaqueDescubierto ( posicion const &p ) {
    return (esJaqueDescubierto (p));
}
// EJERCICIO 8
void ejecutarSecuenciaForzada ( posicion &p, secuencia s ) {
    ejecutarSecuencia(p, s);
    return;
}
// EJERCICIO 9
int seVieneElJaqueEn ( posicion const & p ) {
    return vaASerJaqueEn(p);
}
