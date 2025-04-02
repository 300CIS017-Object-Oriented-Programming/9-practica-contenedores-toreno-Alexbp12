//
// Created by alexb on 1/04/2025.
//

#ifndef JUGADOR_H
#define JUGADOR_H

#include "Videojuego.h"
#include <vector>

class Jugador {
public:
    string nickname;
    int nivelRanking;
    vector<Videojuego*> videojuegosInscritos;

    Jugador(string n, int r);
    void mostrar();
};



#endif //JUGADOR_H
