#include "CD.h"

CD::CD(const std::string& nombreCD) : nombreCD(nombreCD) {}

std::string CD::getNombreCD() const {
    return nombreCD;
}

void CD::agregarCancion(const Cancion& cancion) {
    canciones.push_back(cancion);
}

std::vector<Cancion> CD::getCanciones() const {
    return canciones;
}

std::string CD::getNombreCancion(int index) const {
    if (index >= 0 && index < canciones.size()) {
        return canciones[index].getNombre();
    }
    return "";
}

std::string CD::getArtistaCancion(int index) const {
    if (index >= 0 && index < canciones.size()) {
        return canciones[index].getArtista();
    }
    return "";
}

std::string CD::getDuracionCancion(int index) const {
    if (index >= 0 && index < canciones.size()) {
        return canciones[index].getDuracion();
    }
    return "";
}
