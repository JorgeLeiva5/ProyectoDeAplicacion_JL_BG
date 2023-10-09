#pragma once
#ifndef CANCION_H
#define CANCION_H

#include <string>

class Cancion {
private:
    std::string nombre;
    std::string artista;
    std::string duracion;

public:
    Cancion(const std::string& nombre, const std::string& artista, const std::string& duracion);

    std::string getNombre() const;
    std::string getArtista() const;
    std::string getDuracion() const;

public:
    Cancion();
};

#endif
