#pragma once
#ifndef REPRODUCTOR_H
#define REPRODUCTOR_H
#include "Cancion.h"
#include <vector>
#include <string>
#include "CD.h"


class Reproductor {
private:
    std::string ruta;
    std::vector<CD> cds;
    std::vector<Cancion> colaDeReproduccion;

    const Cancion* cancionActual; // Usaremos punteros para representar la canci�n actual
    const CD* cdActual;          // ...y el CD actual
    bool reproduciendo;    // Flag para saber si hay una canci�n en reproducci�n

public:
    // Constructor
    Reproductor(const std::string& ruta);

    // M�todos para cargar y mostrar CDs y canciones
    void cargarCDs();
    void mostrarCDs() const;
    int getNumeroCDs() const;
    void mostrarCancionesDeCD(int index) const;

    // M�todos relacionados con la cola de reproducci�n
    void agregarACola(int indiceCD, int indiceCancion);
    void mostrarColaReproduccion() const;
    void ordenarColaPorArtista();
    void ordenarColaPorNombre();
    void ordenarColaPorDuracion();

    // M�todos para manejar la reproducci�n
    void mostrarReproduccionActual() const;
    void reproducirSiguiente();
    void iniciarReproduccion(const Cancion& cancion, const CD& cd);
};

#endif 