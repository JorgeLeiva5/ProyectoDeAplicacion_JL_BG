#include "Cancion.h"

Cancion::Cancion(const std::string& nombre, const std::string& artista, const std::string& duracion)
    : nombre(nombre), artista(artista), duracion(duracion) {}

std::string Cancion::getNombre() const {
    return nombre;
}

std::string Cancion::getArtista() const {
    return artista;
}

std::string Cancion::getDuracion() const {
    return duracion;
}
