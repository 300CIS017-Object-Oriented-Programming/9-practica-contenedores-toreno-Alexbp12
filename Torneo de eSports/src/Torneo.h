//
// Created by alexb on 1/04/2025.
//

#ifndef TORNEO_H
#define TORNEO_H

#include <map>
#include <string>
#include "Videojuego.h"
#include "Jugador.h"

class Torneo {
private:
    std::map<std::string, Videojuego*> videojuegosDisponibles;
    std::map<std::string, Jugador*> jugadoresRegistrados;

public:
    ~Torneo();

    // Métodos para videojuegos
    bool registrarVideojuego(Videojuego* videojuego);
    bool existeVideojuego(std::string codigo) const;
    Videojuego* obtenerVideojuego(std::string codigo) const;
    void mostrarVideojuegos() const;

    // Métodos para jugadores
    bool registrarJugador(Jugador* jugador);
    bool existeJugador(std::string nickname) const;
    Jugador* obtenerJugador(std::string nickname) const;
    bool inscribirJugadorVideojuego(std::string nickname, std::string codigoVideojuego);
    void mostrarJugadores() const;

    // Métodos de inicialización
    void inicializarVideojuegos();
    void inicializarJugadores();
};

#endif // TORNEO_H
