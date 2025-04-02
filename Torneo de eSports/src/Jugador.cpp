//
// Created by alexb on 1/04/2025.
//

#include "Jugador.h"
#include <iostream>

Jugador::Jugador(std::string nickname, int nivelRanking)
    : nickname(nickname), nivelRanking(nivelRanking) {
    if (nivelRanking < 1 || nivelRanking > 100) {
        this->nivelRanking = 1;
    }
}

std::string Jugador::getNickname() const {
    return nickname;
}

int Jugador::getNivelRanking() const {
    return nivelRanking;
}

const std::vector<Videojuego*>& Jugador::getVideojuegosInscritos() const {
    return videojuegosInscritos;
}

void Jugador::setNivelRanking(int nivelRanking) {
    if (nivelRanking >= 1 && nivelRanking <= 100) {
        this->nivelRanking = nivelRanking;
    }
}

bool Jugador::inscribirVideojuego(Videojuego* videojuego) {
    if (!estaInscrito(videojuego)) {
        videojuegosInscritos.push_back(videojuego);
        return true;
    }
    return false;
}

bool Jugador::estaInscrito(Videojuego* videojuego) const {
    for (auto vj : videojuegosInscritos) {
        if (vj->getCodigo() == videojuego->getCodigo()) {
            return true;
        }
    }
    return false;
}

double Jugador::promedioDificultad() const {
    if (videojuegosInscritos.empty()) {
        return 0.0;
    }

    double suma = 0.0;
    for (auto vj : videojuegosInscritos) {
        suma += vj->getNivelDificultad();
    }
    return suma / videojuegosInscritos.size();
}

void Jugador::mostrarVideojuegos() const {
    if (videojuegosInscritos.empty()) {
        std::cout << "El jugador no está inscrito en ningún videojuego.\n";
        return;
    }

    std::cout << "Videojuegos inscritos:\n";
    for (auto vj : videojuegosInscritos) {
        vj->mostrarInfo();
        std::cout << "-----------------\n";
    }
}

void Jugador::mostrarInfo() const {
    std::cout << "Nickname: " << nickname << "\n";
    std::cout << "Nivel de ranking: " << nivelRanking << "/100\n";
    std::cout << "Promedio dificultad juegos: " << promedioDificultad() << "/5\n";
}