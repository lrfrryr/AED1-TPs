#include "definiciones.h"
#include "auxiliares.h"

using namespace std;
// aqui se pueden ubicar todas las funciones auxiliares de soporte para la resolucion de los ejercicios

// EJERCICIO 1

bool esJugadorValido (int j) {
    return (j == BLANCO || j == NEGRO);
}

bool casillaVacia (tablero t, coordenada coord) {
    bool res = false;
    int i = coord.first;
    int j = coord.second;
    if (t[i][j].first == 0 && t[i][j].second == 0) res = true;
    return res;
}

bool piezaEnRango (tablero t, coordenada coord) {
    bool res = false;
    int i = coord.first;
    int j = coord.second;
    if (t[i][j].first <= 4 && t[i][j].first >= 1 && t[i][j].second <= 2 && t[i][j].second >= 1) res = true;
    return res;
}

bool casillasValidas (const tablero & t) {
    bool res = true;
    pair<int, int> coordenada;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            coordenada.first = i;
            coordenada.second = j;
            if (!casillaVacia(t, coordenada) && !piezaEnRango(t, coordenada)) {
                res = false;
            }
        }
    }
    return res;
}

bool sinPeonesNoCoronados (tablero t) {
    bool res = true;
    for (int j = 0; j < 8; j++) {
            if (t[0][j].first == 1) res = false;
            else if (t[7][j].first == 1) res = false;
    }
    return res;
}

int aparicionesEnTablero (tablero t, casilla casilla) {
    int count = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (t[i][j] == casilla) {
                count++;
            }
        }
    }
    return count;
}

bool piezasPeonesValidas (tablero t) {
    bool res = false;
    if (aparicionesEnTablero(t,casilla(PEON,BLANCO)) <= 8 && aparicionesEnTablero(t, casilla(PEON,NEGRO)) <= 8) res = true;
    return res;
}

bool piezasAlfilesValidas (tablero t) {
    bool res = false;
    if (aparicionesEnTablero(t, casilla(ALFIL,BLANCO)) <= 2 && aparicionesEnTablero(t, casilla(ALFIL,NEGRO)) <= 2) res = true;
    return res;
}

bool piezasTorresValidas (tablero t) {
    bool res;
    if (aparicionesEnTablero(t,casilla(TORRE,BLANCO)) <= 2 + (8 - aparicionesEnTablero(t, casilla(PEON, BLANCO))) && aparicionesEnTablero(t,casilla(TORRE,NEGRO)) <= 2 + (8 - aparicionesEnTablero(t, casilla(PEON, NEGRO)))) res = true;
    else res = false;
    return res;
}

bool piezasReyesValidas (tablero t) {
    bool res = false;
    if (aparicionesEnTablero(t,casilla(REY,BLANCO)) == 1 && aparicionesEnTablero(t, casilla(REY,NEGRO)) == 1) res = true;
    return res;
}

bool cantidadValidaDePiezas (tablero t) {
    bool res = false;
    if (piezasPeonesValidas(t) && piezasAlfilesValidas(t) && piezasReyesValidas(t) && piezasTorresValidas(t)) res = true;
    return res;
}

bool esMatriz (tablero t) {
    bool res = true;
    for (int i = 0; i < 8; i++) {
        if (t[i].size() != t.size()) res = false;
    }
    return (t.size() == 8 && res);
}

bool esTableroValido (tablero t) {
    bool res = false;
    if (esMatriz(t) && casillasValidas(t) && sinPeonesNoCoronados(t) && cantidadValidaDePiezas(t)) res = true;
    return res;
}

//función principal ejercicio 1:

bool esPosicionValida (posicion posicion) {
    bool res = false;
    if (esTableroValido(posicion.first) && esJugadorValido(posicion.second)) res = true;
    return res;
}



// EJERCICIO 2

int pieza (tablero t, coordenada coord) {
    return (t[coord.first][coord.second].first);
}

int color (tablero t, coordenada coord) {
    return (t[coord.first][coord.second].second);
}

bool piezaEnCoordenada (tablero t, coordenada coord, int pza, int col) {
    bool res = false;
    if (pieza(t, coord) == pza && color(t, coord) == col) res = true;
    return res;
}

bool peonesEnCoordenadas (tablero t) {
    bool res = true;
    for (int j = 0; j < 8; j++) {
        if (!piezaEnCoordenada(t, coordenada(1, j), PEON, NEGRO)) res = false;
        if (!piezaEnCoordenada(t, coordenada(6, j), PEON, BLANCO)) res = false;
    }
    return res;
}

bool torresEnCoordenadas (tablero t) {
    bool res = true;
    if (!piezaEnCoordenada(t, coordenada(0,0), TORRE, NEGRO)) res = false;
    else if (!piezaEnCoordenada(t, coordenada(0,7), TORRE, NEGRO)) res = false;
    else if (!piezaEnCoordenada(t, coordenada(7,0), TORRE, BLANCO)) res = false;
    else if (!piezaEnCoordenada(t, coordenada(7,7), TORRE, BLANCO)) res = false;
    return res;
}

bool alfilesEnCoordenadas (tablero t) {
    bool res = true;
    if (!piezaEnCoordenada(t, coordenada(0,2), ALFIL, NEGRO)) res = false;
    else if (!piezaEnCoordenada(t, coordenada(0,5), ALFIL, NEGRO)) res = false;
    else if (!piezaEnCoordenada(t, coordenada(7,2), ALFIL, BLANCO)) res = false;
    else if (!piezaEnCoordenada(t, coordenada(7,5), ALFIL, BLANCO)) res = false;
    return res;
}

bool reyesEnCoordenadas (tablero t) {
    bool res = true;
    if (!piezaEnCoordenada(t, coordenada(0,4), REY, NEGRO)) res = false;
    else if (!piezaEnCoordenada(t, coordenada(7,4), REY, BLANCO)) res = false;
    return res;
}

bool piezasEnCoordenadas (const tablero & t) {
    bool res = true;
    if (!torresEnCoordenadas(t)) res = false;
    else if (!peonesEnCoordenadas(t)) res = false;
    else if (!reyesEnCoordenadas(t)) res = false;
    else if (!alfilesEnCoordenadas(t)) res = false;
    return res;
}

bool cantidadDePiezasAlInicio (tablero t) {
    bool res = true;
    if (aparicionesEnTablero(t, casilla(TORRE,NEGRO))!=2) res = false;
    if (aparicionesEnTablero(t, casilla(TORRE,BLANCO))!=2) res = false;
    if (aparicionesEnTablero(t, casilla(ALFIL,NEGRO))!=2) res = false;
    if (aparicionesEnTablero(t, casilla(ALFIL,BLANCO))!=2) res = false;
    if (aparicionesEnTablero(t, casilla(PEON,NEGRO))!=8) res = false;
    if (aparicionesEnTablero(t, casilla(PEON,BLANCO))!=8) res = false;
    return res;
}

//función principal ejercicio 2:

bool esPosicionInicial (posicion posicion) {
    bool res = false;
    if (piezasEnCoordenadas(posicion.first) && cantidadDePiezasAlInicio(posicion.first) && posicion.second == BLANCO) res = true;
    return res;
}



//EJERCICIO 3

//Movimiento pieza válido:

bool mueveEnDiagonal(coordenada o, coordenada d) {
    bool res = false;
    if (abs(o.first - d.first) == 1 && abs(o.second - d.second) == 1) res = true;
    return res;
}

bool mueveEnVertical(coordenada o, coordenada d) {
    bool res = false;
    if (abs(o.first - d.first) == 1 && abs(o.second - d.second) == 0) res = true;
    return res;
}

bool mueveEnHorizontal(coordenada o, coordenada d) {
    bool res = false;
    if (abs(o.first - d.first) == 0 && abs(o.second - d.second) == 1) res = true;
    return res;
}

bool movimientoReyValido (coordenada o, coordenada d) {
    bool res = false;
    if (mueveEnDiagonal(o, d) || mueveEnVertical(o,d) || mueveEnHorizontal(o,d)) res = true;
    return res;
}

bool movimientoTorreValido (tablero t, coordenada o, coordenada d) {
    bool res = true;
    if (o != d) {
        if (d.first - o.first == 0) {    //se mueve en horizontal
            if (d.second > o.second) {   // se mueve a la derecha
                for (int i = o.second+1; i<d.second; i++) { // es menor y no menor o igual por usar la misma funcion para captura
                    if(!casillaVacia(t, coordenada(o.first, i))) res = false;
                }
            } else if (d.second < o.second) {   // se mueve a la izquierda
                for (int i = o.second-1; i>d.second; i--) { // es mayor y no mayor o igual por usar la misma funcion para captura
                    if(!casillaVacia(t, coordenada(o.first, i))) res = false;
                }
            }
        } else if (d.second - o.second == 0) {    //se mueve en vertical
            if (d.first > o.first) {   // se mueve hacia abajo
                for (int i = o.first+1; i<d.first; i++) {
                    if(!casillaVacia(t, coordenada(i, o.second))) res = false;
                }
            } else if (d.first < o.first) {   // se mueve hacia arriba
                for (int i = o.first-1; i>d.first; i--) {
                    if(!casillaVacia(t, coordenada(i, o.second))) res = false;
                }
            }
        } else res = false;
    } else res = false;
    return res;
}

bool movimientoAlfilValido (tablero t, coordenada o, coordenada d) {
    bool res = true;
    if (abs(d.first - o.first) == abs(d.second - o.second)) {
        if (d.first < o.first && d.second < o.second) { // baja baja (izq arriba)
            for (int i = o.first-1, j = o.second-1; i > d.first; i--, j--) {
                if(!casillaVacia(t,coordenada(i,j))) res = false;
            }
        } else if (d.first > o.first && d.second > o.second) { // sube sube (derecha abajo)
            for (int i = o.first+1, j = o.second+1; i < d.first; i++, j++) {
                if(!casillaVacia(t,coordenada(i,j))) res = false;
            }
        } else if (d.first < o.first && d.second > o.second) { // f baja s sube (derecha arriba)
            for (int i = o.first-1, j = o.second+1; i > d.first; i--, j++) {
                if(!casillaVacia(t,coordenada(i,j))) res = false;
            }
        } else if (d.first > o.first && d.second < o.second) { // f sube s baja (izq abajo)
            for (int i = o.first+1, j = o.second-1; i < d.first; i++, j--) {
                if(!casillaVacia(t,coordenada(i,j))) res = false;
            }
        }
    } else res = false;
    return res;
}

bool movimientoPeonValido(int col, coordenada o, coordenada d) {
    bool res = false;
    if ((col == BLANCO && d.first == o.first -1) || (col == NEGRO && d.first == o.first +1)) res = true;
    return (d.second == o.second && res);
}

bool capturaPeonValida(tablero t, coordenada o, coordenada d) {
    bool res = false;
    if (t[o.first][o.second].second == BLANCO && d.first == (o.first-1) && (d.second == (o.second-1) || d.second == (o.second+1))) res = true;
    else if (t[o.first][o.second].second == NEGRO && d.first == (o.first+1) && ((d.second == (o.second-1) || d.second == (o.second+1)))) res = true;
    return (abs(d.first-o.first) == 1 && res);
}

bool capturaPeonValida2(tablero t, coordenada o, coordenada d) {
    bool res = false;
    if (t[d.first][d.second].first != VACIO) {
        if (t[o.first][o.second].second == BLANCO && d.first == (o.first-1) && (d.second == (o.second-1) || d.second == (o.second+1))) res = true;
        else if (t[o.first][o.second].second == NEGRO && d.first == (o.first+1) && ((d.second == (o.second-1) || d.second == (o.second+1)))) res = true;
    }
    return (abs(d.first-o.first) == 1 && res);
}

bool movimientoPiezaValido(tablero t, coordenada o, coordenada d) {
    bool res = false;
    if (d != o) {
        if (t[o.first][o.second].first == PEON) {
            if (movimientoPeonValido(t[o.first][o.second].second, o, d)) res = true;
            if (capturaPeonValida(t, o, d)) res = true;
        } else if (t[o.first][o.second].first  == ALFIL) {
            if (movimientoAlfilValido(t,o,d)) res = true;
        } else if (t[o.first][o.second].first  == TORRE) {
            if (movimientoTorreValido(t,o,d)) res = true;
        } else if (t[o.first][o.second].first  == REY) {
            if (movimientoReyValido(o,d)) res = true;
        }
    }
    return res;
}

bool movimientoPiezaValido2(tablero t, coordenada o, coordenada d) {
    bool res = false;
    if (d != o) {
        if (t[o.first][o.second].first == PEON) {
            if (movimientoPeonValido(t[o.first][o.second].second, o, d) && d.first == VACIO) res = true;
            if (capturaPeonValida2(t, o, d)) res = true;
        } else if (t[o.first][o.second].first  == ALFIL) {
            if (movimientoAlfilValido(t,o,d)) res = true;
        } else if (t[o.first][o.second].first  == TORRE) {
            if (movimientoTorreValido(t,o,d)) res = true;
        } else if (t[o.first][o.second].first  == REY) {
            if (movimientoReyValido(o,d)) res = true;
        }
    }
    return res;
}

bool esCasillaAtacada(tablero t, coordenada o, coordenada d) {
    bool res = false;
    if (t[o.first][o.second].first != PEON && t[o.first][o.second].first != VACIO) {
        if (movimientoPiezaValido(t, o, d)) res = true;
    }
    if (t[o.first][o.second].first == PEON) {
        if (capturaPeonValida(t,o,d)) res = true;
    }
    return (!casillaVacia(t,o) && res);
}

bool noRepetida(casilla c, vector < casilla > secuencia) {
    bool res = true;
    for (int i = 0; i<secuencia.size(); i++) {
        if (secuencia[i] == c) res = false;
    }
    return res;
}

//función principal ejercicio 3:

vector <coordenada> sonCasillasAtacadas (posicion const &p, int j) {
    vector <coordenada> cA;
    vector < vector < casilla > > t = p.first;
    for (int x = 0; x < 8; x++) {
        for (int k = 0; k < 8; k++) {
            for (int i = 0; i < 8; i++) {
                for (int l = 0; l < 8; l++) {
                    if ((coordenada(i,l) != coordenada(0,0)) && (coordenada(x,k) != coordenada(i,l))) {
                        if (t[i][l].second == j) {
                            if (esCasillaAtacada(t, coordenada(i, l), coordenada(x, k))) {
                                if (noRepetida(coordenada(x,k), cA)) {
                                    cA.push_back(coordenada(x, k));
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return (cA);
}



// EJERCICIO 4

bool posicionesIgualesExceptoEn (posicion p, posicion q, vector < coordenada > secuencia) {
    tablero tablerop = p.first;
    tablero tableroq = q.first;
    bool res = true;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (coordenada(i,j) != secuencia[0] && coordenada(i,j) != secuencia[1]) {
                if (tablerop[i][j] != tableroq[i][j]) res = false;
            }
        }
    }
    return res;
}

bool esMovimientoValido (posicion posicion, coordenada o, coordenada d) {
    tablero tablero = posicion.first;
    bool res = true;
    if (posicion.second != tablero[o.first][o.second].second) res = false;
    if (casillaVacia(tablero, o)) res = false;
    if (tablero[o.first][o.second].second == tablero[d.first][d.second].second) res = false;
    if (!(movimientoPiezaValido(tablero, o, d))) res = false;
    return res;
}

bool esMovimientoValido2(posicion posicion, coordenada o, coordenada d) {
    tablero tablero = posicion.first;
    bool res = true;
    if (posicion.second != tablero[o.first][o.second].second) res = false;
    if (casillaVacia(tablero, o)) res = false;
    if (tablero[o.first][o.second].second == tablero[d.first][d.second].second) res = false;
    if (!(movimientoPiezaValido2(tablero, o, d))) res = false;
    return res;
}

bool esCapturaValida (posicion posicion, coordenada o, coordenada d) {
    tablero tablero = posicion.first;
    bool res = true;
    if (casillaVacia(tablero, o)) res = false;
    if (casillaVacia(tablero, d)) res = false;
    if (tablero[o.first][o.second].second == tablero[d.first][d.second].second) res = false;
    if (!esCasillaAtacada(tablero, o, d)) res = false;
    return res;
}

bool piezaCorrectaEnDestino (posicion p, posicion q, coordenada o, coordenada d) {
    tablero tablerop = p.first;
    tablero tableroq = q.first;
    bool res = true;
    if (tablerop[o.first][o.second].second != tableroq[d.first][d.second].second) res = false;
    if (tablerop[o.first][o.second].first == PEON) {
        if (d.first == 0 && tablerop[o.first][o.second].second == BLANCO) {
            if (tableroq[d.first][d.second].first != TORRE) res = false;
        } else if (d.first == 7 && tablerop[o.first][o.second].second == NEGRO) {
            if (tableroq[d.first][d.second].first != TORRE) res = false;
        } else if (tableroq[d.first][d.second].first != PEON) res = false;
    } else {
        if (tablerop[o.first][o.second].first != tableroq[d.first][d.second].first) res = false;
    }
    return res;
}

//función principal ejercicio 4:

bool posicionSiguiente (posicion p, posicion q, coordenada o, coordenada d) {
    tablero tablerop = p.first;
    tablero tableroq = q.first;
    vector <coordenada> coordCambiadas;
    coordCambiadas.push_back(o);
    coordCambiadas.push_back(d);
    bool res = true;
    if (p.second == q.second) res = false;
    if (!posicionesIgualesExceptoEn(p,q,coordCambiadas)) res = false;
    if (!casillaVacia(tableroq, o)) res = false;
    if (!esMovimientoValido(p, o, d) && !esCapturaValida(p, o, d)) res = false;
    if (!piezaCorrectaEnDestino(p, q, o, d)) res = false;
    return res;
}



//EJERCICIO 5

void swap(vector < casilla > &piezas, int i, int j) {
    coordenada temp;
    temp = piezas[i];
    piezas[i] = piezas[j];
    piezas[j] = temp;
}

void ordenarFila (vector < casilla > &fila) {
    int n = 0;
    vector < casilla > piezas;

    //copio las piezas en un vector
    for (int i = 0; i < 8; i++) {
        if (fila[i].first > 0) {
            piezas.push_back(fila[i]);
        }
    }
    //ordeno el vector de piezas
    for (int i = 1; i < piezas.size(); ++i) {
        for (int j = 0; j < piezas.size() - i; ++j) {
            if (piezas[j].first > piezas[j+1].first) {
                swap(piezas, j, j+1);
            }
        }
    }
    int m = 0;
    //vuelvo a poner las piezas en la fila
    for (int i = 0; i < 8; i++) {
        if (fila[i].first > 0) {
            fila[i] = piezas[m];
            m++;
        }
    }
    return;
}



//EJERCICIO 6

bool soloHayReyes (tablero t) {
    bool res = true;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((t[i][j].first != 0 && t[i][j].second != 0) && t[i][j].first != 4) res = false;
        }
    }
    return res;
}

int contrincante (int j) {
    int c;
    if (j == BLANCO) c = NEGRO;
    if (j == NEGRO) c = BLANCO;
    return c;
}

bool jugadorEnJaque (posicion p, int j) {
    bool res = false;
    vector<vector<casilla> > t = p.first;
    for (int i = 0; i < 8; i++) {
        for (int m = 0; m < 8; m++) {
            if (t[i][m].first == 4 && t[i][m].second == j) {
                for (int k = 0; k < 8; k++) {
                    for (int l = 0; l < 8; l++) {
                        if (t[i][m].second != t[k][l].second) {
                            if (esCasillaAtacada(t, coordenada(k, l), coordenada(i, m))) res = true;
                        }
                    }
                }
            }
        }
    }
    return res;
}

bool sePoneEnJaque (posicion p, coordenada o, coordenada d) {
    bool res = false;
    posicion q; //armo una posición q igual a p
    q.first = p.first;
    q.second = contrincante(p.second);
    //ahora cambio la coordenada origen or la coordenada destino en q (esPosicionSiguiente)
    //ya chequee que la jugada sea valida en la función en la que la llamo
    q.first[o.first][o.second].first = 0; //origen queda vacío
    q.first[o.first][o.second].second = 0; //origen queda vacío
    q.first[d.first][d.second].first = p.first[o.first][o.second].first; //destino de q, es origen de p
    q.first[d.first][d.second].second = p.first[o.first][o.second].second; //destino de q, es origen de p
    //ahora chequeo que en la nueva posicion q, el rey de la posicion original p, no haya sido puesto en jaque
    //o sea, gracias al movimiento que hizo para pasar a q
    if (jugadorEnJaque(q, p.second)) res = true;
    return res;
}

bool hayMovimientosLegales(posicion p) {
    bool res = false;
    vector<vector<casilla> > t = p.first;
    int jugador = p.second;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (t[i][j].second == jugador) {
                for (int k = 0; k < 8; k++) {
                    for (int l = 0; l < 8; l++) {
                        if (esMovimientoValido2(p, coordenada(i,j), coordenada(k,l))) {
                            if (!sePoneEnJaque(p, coordenada(i,j), coordenada(k,l))) {
                                res = true;
                            }
                        }
                    }
                }
            }
        }
    }
    return res;
}

bool esJugadaLegal(posicion p, coordenada o, coordenada d) {
    bool res = false;
    if (esMovimientoValido(p, o, d) || esCapturaValida(p, o, d)) {
        if (!sePoneEnJaque(p, o, d)) res = true;
    }
    return res;
}

bool saleDeJaque (posicion p, coordenada o, coordenada d) {
    bool res = false;
    posicion q; //armo una posición q igual a p
    q.first = p.first;
    q.second = contrincante(p.second);
    //ahora cambio la coordenada origen or la coordenada destino en q (esPosicionSiguiente)
    //ya chequee que la jugada sea valida en la función en la que la llamo
    q.first[o.first][o.second].first = 0; //origen queda vacío
    q.first[o.first][o.second].second = 0; //origen queda vacío
    q.first[d.first][d.second].first = p.first[o.first][o.second].first; //destino de q, es origen de p
    q.first[d.first][d.second].second = p.first[o.first][o.second].second; //destino de q, es origen de p
    //ahora chequeo que en la nueva posicion q, el rey de la posicion original p, haya salido del jaque
    //o sea, gracias al movimiento que hizo para pasar a q
    if (!jugadorEnJaque(q, p.second)) {
        res = true;
    }
    return res;
}

bool existeMovimientoParaSalirDelJaque (posicion p) {
    bool res = false;
    vector<vector<casilla> > t = p.first;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 8; k++) {
                for (int l = 0; l < 8; l++) {
                    if (t[i][j].second == p.second && esJugadaLegal(p, coordenada(i,j), coordenada(k,l))) {
                        if (saleDeJaque(p, coordenada(i,j), coordenada(k, l))) res = true;
                    }
                }
            }
        }
    }
    return res;
}

bool esEmpate (posicion p, int &j) {
    bool res = false;
    if (!jugadorEnJaque(p,p.second) && !hayMovimientosLegales(p)) {
        res = true;
        j = 0;
    } else if (soloHayReyes(p.first) ) {
        res = true;
        j = 0;
    }
    return res;
}

bool esJaqueMate (posicion p) {
    bool res = false;
    if (jugadorEnJaque(p, p.second)) {
        if (!existeMovimientoParaSalirDelJaque(p)) res = true;
    }
    return res;
}

//función principal ejercicio 6:

bool esFinDeLaPartida (posicion p, int &j) {
    bool res = false;
    j = p.second;
    if (esEmpate(p, j)) {
        if (j == 0) {
            res = true;
        }
    } else if (esJaqueMate(p)) {
        j = contrincante(p.second);
        res = true;
    }
    return res;
}

// EJERCICIO 7

bool loPoneEnJaque (posicion p, coordenada o, coordenada d) {
    bool res = false;
    posicion q; //armo una posición q igual a p
    q.first = p.first;
    q.second = contrincante(p.second);
    //ahora cambio la coordenada origen or la coordenada destino en q (esPosicionSiguiente)
    //ya chequee que la jugada sea valida en la función en la que la llamo
    q.first[o.first][o.second].first = 0; //origen queda vacío
    q.first[o.first][o.second].second = 0; //origen queda vacío
    q.first[d.first][d.second].first = p.first[o.first][o.second].first; //destino de q, es origen de p
    q.first[d.first][d.second].second = p.first[o.first][o.second].second; //destino de q, es origen de p
    //ahora chequeo que en la nueva posicion q, el rey de la posicion p (el jugador), no haya sido puesto en jaque
    //o sea, gracias al movimiento que hizo el contricante para pasar a q
    if (jugadorEnJaque(q, q.second)) {
        res = true;
    }
    return res;
}

//función principal ejercicio 7:

bool esJaqueDescubierto (posicion p) {
    bool res = false;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 8; k++) {
                for (int l = 0; l < 8; l++) {
                    if (p.first[i][j].second == p.second && esJugadaLegal(p, coordenada(i,j), coordenada(k,l))) {
                        if (loPoneEnJaque(p, coordenada(i, j), coordenada(k,l))) {
                            res = true;
                        }
                    }
                }
            }
        }
    }
    return res;
}

//EJERCICIO 8

secuencia descubrirCoordenadasForzadas (posicion p, secuencia cF) {
    pair < coordenada, coordenada > armar;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (p.first[i][j].second == p.second) {
                for (int k = 0; k < 8; k++) {
                    for (int l = 0; l < 8; l++) {
                        if (p.first[i][j].second != p.first[k][l].second) {
                            if (movimientoPiezaValido(p.first, coordenada(i,j), coordenada(k,l)) && !sePoneEnJaque(p, coordenada(i,j), coordenada(k,l))) {
                                armar.first = coordenada(i,j);
                                armar.second = coordenada(k,l);
                                cF.push_back(armar);
                            }
                        }
                    }
                }
            }
        }
    }
    return cF;
}

bool esConversionDePeon (posicion p, coordenada o, coordenada d) {
    bool res = false;
    if (p.first[o.first][o.second].first == 1) {
        if (p.first[o.first][o.second].second == 1) {
            if (o.first == 1 && d.first == 0) res = true;
        } else if (p.first[o.first][o.second].second == 2) {
            if (o.first == 6 && d.first == 7) res = true;
        }
    }
    return res;
}

posicion mover (posicion &p, coordenada o, coordenada d) {
    posicion q; //armo una posición q igual a p
    q.first = p.first;
    q.second = contrincante(p.second);
    //ahora cambio la coordenada origen or la coordenada destino en q (esPosicionSiguiente)
    //ya chequee que la jugada sea valida en la función en la que la llamo
    q.first[o.first][o.second].first = 0; //origen queda vacío
    q.first[o.first][o.second].second = 0; //origen queda vacío
    if (p.first[o.first][o.second].first == 1) {
        if (esConversionDePeon(p, o, d)) {
            q.first[d.first][d.second].first = 3; //cambio la pieza a torre
            q.first[d.first][d.second].second = p.first[o.first][o.second].second; //color queda igual
        }
        if (!esConversionDePeon(p, o, d)) {
            q.first[d.first][d.second].first = p.first[o.first][o.second].first;
            q.first[d.first][d.second].second = p.first[o.first][o.second].second;
        }
    } else {
        q.first[d.first][d.second].first = p.first[o.first][o.second].first; //destino de q, es origen de p
        q.first[d.first][d.second].second = p.first[o.first][o.second].second; //destino de q, es origen de p
    }
    p = q; //meto q en p
    return p; //devuelvo la posicion con la movida hecha
}

//funcion principal ejercicio 8:

void ejecutarSecuencia (posicion &p, secuencia s) {
    coordenada o;
    coordenada d;
    for (int i = 0; i < s.size(); i++) {
        o = s[i].first;
        d = s[i].second;
        mover(p, o, d);
        secuencia cF;
        cF = descubrirCoordenadasForzadas(p,cF);
        if (cF.size() == 1) {
            mover(p, cF[0].first, cF[0].second);
        }
    }
    int jugador = p.second;
    return;
}

//EJERCICIO 9

bool estaForzado (posicion p) {
    int count = 0;
    if (jugadorEnJaque(p, p.second)) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (p.first[i][j].first != 0 && p.first[i][j].second == p.second) {
                    for (int k = 0; k < 8; k++) {
                        for (int l = 0; l < 8; l++) {
                            if (movimientoPiezaValido2(p.first, coordenada(i,j), coordenada(k,l))
                            && saleDeJaque(p, coordenada(i,j), coordenada(k,l))) {
                                count++;
                               if (count > 1) return false;
                            }
                        }
                    }
                }
            }
        }
    } else {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (p.first[i][j].first != 0 && p.first[i][j].second == p.second) {
                    for (int k = 0; k < 8; k++) {
                        for (int l = 0; l < 8; l++) {
                            if (p.first[i][j].second != p.first[k][l].second) {
                                if (movimientoPiezaValido2(p.first, coordenada(i,j), coordenada(k,l))
                                    && !sePoneEnJaque(p, coordenada(i,j), coordenada(k,l))) {
                                    count++;
                                    if (count > 1) return false;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void buscarMovimientoParaForzar (posicion &p, int vuelta) {
    int jaqueMate = 0;
    int jaque = 0;
    int forzado = 0;
    posicion original = p;
    posicion posJaque;
    posicion posForzada;
    posicion posForzadaJaque;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (p.first[i][j].second == p.second) { //es pieza del jugador
                for (int k = 0; k < 8; k++) {
                    for (int l = 0; l < 8; l++) {
                        //el jugador puede mover la pieza a la segunda coordenada:
                        if (p.first[i][j].second != p.first[k][l].second && movimientoPiezaValido2(p.first, coordenada(i,j), coordenada(k,l)) &&
                        !sePoneEnJaque(p, coordenada(i,j), coordenada(k,l))) {
                            mover(p, coordenada(i,j), coordenada(k,l)); //hago el movimiento
                            if (esJaqueMate(p)) {
                                posJaque = p;
                                jaqueMate++;
                            }
                            if (estaForzado(p)) { //me fijo si en la nueva posicion, se generó un mov forzado al otro jugador
                                if (vuelta == 0) {
                                    if (forzado == 0) {
                                        posForzada = p;
                                    }
                                }
                                if (vuelta >= 1) {
                                    if (forzado != 0) {
                                        if (jugadorEnJaque(p, p.second)) {
                                            posForzadaJaque = p;
                                            jaque++;
                                        } else posForzada = p;
                                    }
                                }
                                forzado++;
                            }
                            p = original; //vuelvo a la posicion anterior para seguir recorriendola hasta encontrar
                                //el movimiento forzado
                        }
                    }
                }
            }
        }
    }
    //priorizo el jaque mate antes que el movimiento forzado:
    if (jaqueMate > 0) {
        p = posJaque;
    } else if (jaque > 0) {
        p = posForzadaJaque;
    } else if (forzado > 0) {
        p = posForzada;
    }
    return;
}

int vaASerJaqueEn (posicion const & p) {
    int count = 0;
    posicion q = p;
    int vuelta = 0;
    bool terminada = false;
    while (!esJaqueMate(q) && !terminada) {
        buscarMovimientoParaForzar(q, vuelta); //busca el movimiento que genera mov forzado o jaqueMate Y MUEVE
        if (!esJaqueMate(q)) {
            if (hayMovimientosLegales(q)) {
                secuencia cF;
                cF = descubrirCoordenadasForzadas(q,cF); //busco el movimiento forzado
                mover(q, cF[0].first, cF[0].second); //muevo y ahora vuelvo a arrancar
            } else {
                q.second = contrincante(q.second);
                terminada = true;
            }
        }
        count++;
        if (count > 3) {
            vuelta++;
            q = p;
            count = 0;
        }
    }
    return count;
}





// TEST

pair<int,int> mp(int a, int b) {
    return make_pair(a, b);
}

vector<pair<int,int>> ordenarVectorPares(vector<pair<int,int>> &v) {
    sort(v.begin(), v.end());
//    v.erase(unique(v.begin(), v.end()), v.end());
    return v;
}

coordenada setCoord(int i, int j) {
    return make_pair(i,j);
}

tablero tableroActual ( posicion const &p ) {
    return p.first;
}

tablero inicializarTablero(){
    vector<casilla> fila(ANCHO_TABLERO, cVACIA);
    tablero out(ANCHO_TABLERO, fila);
    return out;
}