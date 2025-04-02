//
// Created by alexb on 1/04/2025.
//
#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include <vector>
#include "Videojuego.h"

class Jugador {
private:
    std::string nickname;
    int nivelRanking;
    std::vector<Videojuego*> videojuegosInscritos;

public:
    Jugador(std::string nickname, int nivelRanking);

    // Getters
    std::string getNickname() const;
    int getNivelRanking() const;
    const std::vector<Videojuego*>& getVideojuegosInscritos() const;

    // Setters
    void setNivelRanking(int nivelRanking);

    // Métodos de gestión de videojuegos
    bool inscribirVideojuego(Videojuego* videojuego);
    bool estaInscrito(Videojuego* videojuego) const;
    double promedioDificultad() const;
    void mostrarVideojuegos() const;
    void mostrarInfo() const;
};

#endif // JUGADOR_H
