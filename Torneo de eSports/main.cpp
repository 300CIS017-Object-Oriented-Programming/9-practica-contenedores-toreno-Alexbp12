#include <iostream>
#include <limits>
#include "src/Torneo.h"

void mostrarMenu() {
    std::cout << "\n=== SISTEMA DE TORNEOS DE VIDEOJUEGOS ===\n";
    std::cout << "1. Registrar nuevo videojuego\n";
    std::cout << "2. Registrar nuevo jugador\n";
    std::cout << "3. Inscribir jugador a videojuego\n";
    std::cout << "4. Consultar videojuegos de un jugador\n";
    std::cout << "5. Calcular promedio de dificultad de un jugador\n";
    std::cout << "6. Mostrar todos los videojuegos disponibles\n";
    std::cout << "7. Mostrar todos los jugadores registrados\n";
    std::cout << "8. Cargar datos de prueba\n";
    std::cout << "9. Salir del sistema\n";
    std::cout << "Ingrese su opcion: ";
}

void limpiarBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void pausarPantalla() {
    std::cout << "\nPresione Enter para continuar...";
    limpiarBuffer();
}

void registrarVideojuego(Torneo& torneo) {
    std::string codigo, nombre, genero;
    int dificultad;

    std::cout << "\n--- REGISTRO DE VIDEOJUEGO ---\n";
    std::cout << "Codigo unico: ";
    std::cin >> codigo;

    if (torneo.existeVideojuego(codigo)) {
        std::cout << "\n¡Error! Ya existe un videojuego con ese codigo.\n";
        pausarPantalla();
        return;
    }

    limpiarBuffer();
    std::cout << "Nombre: ";
    std::getline(std::cin, nombre);

    std::cout << "Genero: ";
    std::getline(std::cin, genero);

    std::cout << "Dificultad (1-5): ";
    std::cin >> dificultad;

    if (dificultad < 1 || dificultad > 5) {
        std::cout << "\n¡Advertencia! Dificultad fuera de rango. Se establecera a 1.\n";
        dificultad = 1;
    }

    Videojuego* nuevo = new Videojuego(codigo, nombre, genero, dificultad);
    if (torneo.registrarVideojuego(nuevo)) {
        std::cout << "\n¡Videojuego registrado exitosamente!\n";
    } else {
        std::cout << "\n¡Error! No se pudo registrar el videojuego.\n";
        delete nuevo;
    }
    pausarPantalla();
}

void registrarJugador(Torneo& torneo) {
    std::string nickname;
    int nivel;

    std::cout << "\n--- REGISTRO DE JUGADOR ---\n";
    std::cout << "Nickname: ";
    std::cin >> nickname;

    if (torneo.existeJugador(nickname)) {
        std::cout << "\n¡Error! Ya existe un jugador con ese nickname.\n";
        pausarPantalla();
        return;
    }

    std::cout << "Nivel de ranking (1-100): ";
    std::cin >> nivel;

    if (nivel < 1 || nivel > 100) {
        std::cout << "\n¡Advertencia! Nivel fuera de rango. Se establecera a 1.\n";
        nivel = 1;
    }

    Jugador* nuevo = new Jugador(nickname, nivel);
    if (torneo.registrarJugador(nuevo)) {
        std::cout << "\n¡Jugador registrado exitosamente!\n";
    } else {
        std::cout << "\n¡Error! No se pudo registrar el jugador.\n";
        delete nuevo;
    }
    pausarPantalla();
}

void inscribirJugadorVideojuego(Torneo& torneo) {
    std::string nickname, codigo;

    std::cout << "\n--- INSCRIPCIÓN DE JUGADOR A VIDEOJUEGO ---\n";
    std::cout << "Nickname del jugador: ";
    std::cin >> nickname;

    if (!torneo.existeJugador(nickname)) {
        std::cout << "\n¡Error! No existe un jugador con ese nickname.\n";
        pausarPantalla();
        return;
    }

    std::cout << "Codigo del videojuego: ";
    std::cin >> codigo;

    if (!torneo.existeVideojuego(codigo)) {
        std::cout << "\n¡Error! No existe un videojuego con ese codigo.\n";
        pausarPantalla();
        return;
    }

    if (torneo.inscribirJugadorVideojuego(nickname, codigo)) {
        std::cout << "\n¡Inscripción exitosa!\n";
    } else {
        std::cout << "\n¡Error! El jugador ya está inscrito en ese videojuego.\n";
    }
    pausarPantalla();
}

void mostrarVideojuegosJugador(Torneo& torneo) {
    std::string nickname;

    std::cout << "\n--- VIDEOJUEGOS DE JUGADOR ---\n";
    std::cout << "Nickname del jugador: ";
    std::cin >> nickname;

    Jugador* jugador = torneo.obtenerJugador(nickname);
    if (!jugador) {
        std::cout << "\n¡Error! No existe un jugador con ese nickname.\n";
        pausarPantalla();
        return;
    }

    std::cout << "\n--- Videojuegos de " << nickname << " ---\n";
    jugador->mostrarVideojuegos();
    pausarPantalla();
}

void mostrarPromedioDificultad(Torneo& torneo) {
    std::string nickname;

    std::cout << "\n--- PROMEDIO DE DIFICULTAD ---\n";
    std::cout << "Nickname del jugador: ";
    std::cin >> nickname;

    Jugador* jugador = torneo.obtenerJugador(nickname);
    if (!jugador) {
        std::cout << "\n¡Error! No existe un jugador con ese nickname.\n";
        pausarPantalla();
        return;
    }

    double promedio = jugador->promedioDificultad();
    std::cout << "\nEl promedio de dificultad de los videojuegos de " << nickname
              << " es: " << promedio << "/5\n";

    if (promedio == 0) {
        std::cout << "(El jugador no está inscrito en ningun videojuego)\n";
    } else if (promedio < 2.5) {
        std::cout << "Preferencia por juegos fáciles\n";
    } else if (promedio > 3.5) {
        std::cout << "Preferencia por juegos difíciles\n";
    } else {
        std::cout << "Preferencia por juegos intermedios\n";
    }

    pausarPantalla();
}

int main() {
    Torneo torneo;
    int opcion;

    std::cout << "Bienvenido al Sistema de Gestión de Torneos de Videojuegos\n";

    do {
        mostrarMenu();
        std::cin >> opcion;

        if (std::cin.fail()) {
            std::cin.clear();
            limpiarBuffer();
            opcion = 0; // Forzar caso default
        }

        switch (opcion) {
            case 1:
                registrarVideojuego(torneo);
                break;
            case 2:
                registrarJugador(torneo);
                break;
            case 3:
                inscribirJugadorVideojuego(torneo);
                break;
            case 4:
                mostrarVideojuegosJugador(torneo);
                break;
            case 5:
                mostrarPromedioDificultad(torneo);
                break;
            case 6:
                std::cout << "\n--- VIDEOJUEGOS DISPONIBLES ---\n";
                torneo.mostrarVideojuegos();
                pausarPantalla();
                break;
            case 7:
                std::cout << "\n--- JUGADORES REGISTRADOS ---\n";
                torneo.mostrarJugadores();
                pausarPantalla();
                break;
            case 8:
                torneo.inicializarVideojuegos();
                torneo.inicializarJugadores();
                std::cout << "\n¡Datos de prueba cargados exitosamente!\n";
                pausarPantalla();
                break;
            case 9:
                std::cout << "\nSaliendo del sistema...\n";
                break;
            default:
                std::cout << "\n¡Opcion no valida! Por favor ingrese un numero del 1 al 9.\n";
                pausarPantalla();
        }
    } while (opcion != 9);

    return 0;
}