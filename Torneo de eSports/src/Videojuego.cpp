//
// Created by alexb on 1/04/2025.
//

#include "Videojuego.h"
#include <iostream>

Videojuego::Videojuego(std::string codigo, std::string nombre, std::string genero, int nivelDificultad)
    : codigo(codigo), nombre(nombre), genero(genero), nivelDificultad(nivelDificultad) {
    if (nivelDificultad < 1 || nivelDificultad > 5) {
        this->nivelDificultad = 1;
    }
}

std::string Videojuego::getCodigo() const {
    return codigo;
}

std::string Videojuego::getNombre() const {
    return nombre;
}

std::string Videojuego::getGenero() const {
    return genero;
}

int Videojuego::getNivelDificultad() const {
    return nivelDificultad;
}

void Videojuego::setNombre(std::string nombre) {
    this->nombre = nombre;
}

void Videojuego::setGenero(std::string genero) {
    this->genero = genero;
}

void Videojuego::setNivelDificultad(int nivelDificultad) {
    if (nivelDificultad >= 1 && nivelDificultad <= 5) {
        this->nivelDificultad = nivelDificultad;
    }
}

void Videojuego::mostrarInfo() const {
    std::cout << "Código: " << codigo << "\n";
    std::cout << "Nombre: " << nombre << "\n";
    std::cout << "Género: " << genero << "\n";
    std::cout << "Dificultad: " << nivelDificultad << "/5\n";
}
