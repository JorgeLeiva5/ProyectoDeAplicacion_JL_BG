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

    const Cancion* cancionActual; // Usaremos punteros para representar la canción actual
    const CD* cdActual;          // ...y el CD actual
    bool reproduciendo;    // Flag para saber si hay una canción en reproducción

public:
    // Constructor
    Reproductor(const std::string& ruta);

    // Métodos para cargar y mostrar CDs y canciones
    void cargarCDs();
    void mostrarCDs() const;
    int getNumeroCDs() const;
    void mostrarCancionesDeCD(int index) const;

    // Métodos relacionados con la cola de reproducción
    void agregarACola(int indiceCD, int indiceCancion);
    void mostrarColaReproduccion() const;
    void ordenarColaPorArtista();
    void ordenarColaPorNombre();
    void ordenarColaPorDuracion();

    // Métodos para manejar la reproducción
    void mostrarReproduccionActual() const;
    void reproducirSiguiente();
    void iniciarReproduccion(const Cancion& cancion, const CD& cd);
};

#endif 