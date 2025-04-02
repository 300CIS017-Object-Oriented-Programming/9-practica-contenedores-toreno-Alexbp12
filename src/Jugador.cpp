//
// Created by alexb on 1/04/2025.
//

#include "Jugador.h"

Jugador::Jugador(string n, int r) : nickname(n), nivelRanking(r) {}

void Jugador::mostrar() {
    cout << "Jugador: " << nickname << ", Ranking: " << nivelRanking << "\nVideojuegos inscritos:\n";
    for (auto v : videojuegosInscritos) v->mostrar();
}
