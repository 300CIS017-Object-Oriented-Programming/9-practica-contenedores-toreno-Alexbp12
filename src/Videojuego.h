//
// Created by alexb on 1/04/2025.
//

#ifndef VIDEOJUEGO_H
#define VIDEOJUEGO_H

#include <iostream>
using namespace std;

class Videojuego {
    public:
        string codigo, nombre, genero;
    int nivelDificultad;

    Videojuego(string c, string n, string g, int d);
    void mostrar();
};



#endif //VIDEOJUEGO_H
