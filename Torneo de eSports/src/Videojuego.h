//
// Created by alexb on 1/04/2025.
//

#ifndef VIDEOJUEGO_H
#define VIDEOJUEGO_H

#include <string>

class Videojuego {
private:
    std::string codigo;
    std::string nombre;
    std::string genero;
    int nivelDificultad;

public:
    Videojuego(std::string codigo, std::string nombre, std::string genero, int nivelDificultad);

    // Getters
    std::string getCodigo() const;
    std::string getNombre() const;
    std::string getGenero() const;
    int getNivelDificultad() const;

    // Setters
    void setNombre(std::string nombre);
    void setGenero(std::string genero);
    void setNivelDificultad(int nivelDificultad);

    void mostrarInfo() const;
};

#endif //VIDEOJUEGO_H
