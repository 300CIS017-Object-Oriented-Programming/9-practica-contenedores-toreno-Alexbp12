//
// Created by alexb on 1/04/2025.
//

#include "Torneo.h"
#include <iostream>

Torneo::~Torneo() {
    // Liberar memoria de los videojuegos
    for (auto& pair : videojuegosDisponibles) {
        delete pair.second;
    }
    videojuegosDisponibles.clear();

    // Liberar memoria de los jugadores
    for (auto& pair : jugadoresRegistrados) {
        delete pair.second;
    }
    jugadoresRegistrados.clear();
}

bool Torneo::registrarVideojuego(Videojuego* videojuego) {
    if (!videojuego || existeVideojuego(videojuego->getCodigo())) {
        return false;
    }
    videojuegosDisponibles[videojuego->getCodigo()] = videojuego;
    return true;
}

bool Torneo::existeVideojuego(std::string codigo) const {
    return videojuegosDisponibles.find(codigo) != videojuegosDisponibles.end();
}

Videojuego* Torneo::obtenerVideojuego(std::string codigo) const {
    auto it = videojuegosDisponibles.find(codigo);
    if (it != videojuegosDisponibles.end()) {
        return it->second;
    }
    return nullptr;
}

void Torneo::mostrarVideojuegos() const {
    if (videojuegosDisponibles.empty()) {
        std::cout << "No hay videojuegos registrados.\n";
        return;
    }

    std::cout << "Videojuegos disponibles:\n";
    for (const auto& pair : videojuegosDisponibles) {
        pair.second->mostrarInfo();
        std::cout << "-----------------\n";
    }
}

bool Torneo::registrarJugador(Jugador* jugador) {
    if (!jugador || existeJugador(jugador->getNickname())) {
        return false;
    }
    jugadoresRegistrados[jugador->getNickname()] = jugador;
    return true;
}

bool Torneo::existeJugador(std::string nickname) const {
    return jugadoresRegistrados.find(nickname) != jugadoresRegistrados.end();
}

Jugador* Torneo::obtenerJugador(std::string nickname) const {
    auto it = jugadoresRegistrados.find(nickname);
    if (it != jugadoresRegistrados.end()) {
        return it->second;
    }
    return nullptr;
}

bool Torneo::inscribirJugadorVideojuego(std::string nickname, std::string codigoVideojuego) {
    Jugador* jugador = obtenerJugador(nickname);
    Videojuego* videojuego = obtenerVideojuego(codigoVideojuego);

    if (!jugador || !videojuego) {
        return false;
    }

    return jugador->inscribirVideojuego(videojuego);
}

void Torneo::mostrarJugadores() const {
    if (jugadoresRegistrados.empty()) {
        std::cout << "No hay jugadores registrados.\n";
        return;
    }

    std::cout << "Jugadores registrados:\n";
    for (const auto& pair : jugadoresRegistrados) {
        pair.second->mostrarInfo();
        pair.second->mostrarVideojuegos();
        std::cout << "=================\n";
    }
}

void Torneo::inicializarVideojuegos() {
    registrarVideojuego(new Videojuego("LOL001", "League of Legends", "MOBA", 3));
    registrarVideojuego(new Videojuego("VAL001", "Valorant", "FPS", 4));
    registrarVideojuego(new Videojuego("FORT001", "Fortnite", "Battle Royale", 2));
    registrarVideojuego(new Videojuego("SF001", "Street Fighter VI", "Fighting", 4));
    registrarVideojuego(new Videojuego("CS001", "Counter Strike 2", "FPS", 5));
}

void Torneo::inicializarJugadores() {
    registrarJugador(new Jugador("ProPlayer1", 95));
    registrarJugador(new Jugador("NoobMaster", 30));
    registrarJugador(new Jugador("GameChanger", 75));
    registrarJugador(new Jugador("EliteGamer", 88));
}
