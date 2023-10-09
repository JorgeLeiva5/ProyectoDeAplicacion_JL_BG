#include "Reproductor.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <filesystem>
#include "CD.h"



Reproductor::Reproductor(const std::string& ruta) : ruta(ruta) {}


void Reproductor::cargarCDs() {
    for (const auto& file : std::filesystem::directory_iterator(ruta)) {
        if (file.path().extension() == "ArchivosdePrueba_20231001") { // Ingresar aca el nombre de la carpeta de los archivos
            std::ifstream inFile(file.path());

            if (!inFile.is_open()) {
                std::cout << "Error al abrir el archivo: " << file.path() << std::endl;
                continue;
            }

            std::string line;
            CD cdActual(file.path().stem().string());

            while (getline(inFile, line)) {
                std::istringstream iss(line);
                std::string nombre, artista, duracion;


                std::getline(iss, nombre, '|');
                iss.ignore(1);
                std::getline(iss, artista, '|');
                iss.ignore(1);
                std::getline(iss, duracion);

                if (nombre.empty() || artista.empty() || duracion.empty()) {
                    std::cout << "Formato de linea incorrecto en el archivo: " << file.path() << std::endl;
                    continue;
                }

                Cancion cancion(nombre, artista, duracion);
                cdActual.agregarCancion(cancion);
            }

            if (cdActual.getCanciones().empty()) {
                std::cout << "Archivo vacio: " << file.path() << std::endl;
                continue;
            }

            cds.push_back(cdActual);

            inFile.close();
        }
    }
}

void Reproductor::mostrarCDs() const {
    int count = 1;
    for (const CD& cd : cds) {
        std::cout << count << ". " << cd.getNombreCD() << std::endl;
        count++;
    }
}

int Reproductor::getNumeroCDs() const {
    return cds.size();
}

void Reproductor::mostrarCancionesDeCD(int index) const {
    if (index >= 0 && index < cds.size()) {
        const CD& cdSeleccionado = cds[index];
        std::cout << "Canciones en CD: " << cdSeleccionado.getNombreCD() << std::endl;
        int count = 1;
        for (const Cancion& cancion : cdSeleccionado.getCanciones()) {
            std::cout << count << ". " << cancion.getNombre() << " || "
                << cancion.getArtista() << " || "
                << cancion.getDuracion() << std::endl;
            count++;
        }
    }
    else {
        std::cout << "Indice de CD invalido." << std::endl;
    }
}

void Reproductor::agregarACola(int indiceCD, int indiceCancion) {
    if (indiceCD >= 0 && indiceCD < cds.size()) {
        CD& cdSeleccionado = cds[indiceCD];
        if (indiceCancion >= 0 && indiceCancion < cdSeleccionado.getCanciones().size()) {
            colaDeReproduccion.push_back(cdSeleccionado.getCanciones()[indiceCancion]);
            std::cout << "Cancion agregada a la cola de reproduccion.\n";
        }
        else {
            std::cout << "Índice de canción invalido.\n";
        }
    }
    else {
        std::cout << "Indice de CD invalido.\n";
    }
}

void Reproductor::mostrarColaReproduccion() const {
    int count = 1;
    for (const Cancion& cancion : colaDeReproduccion) {
        std::cout << count << ". " << cancion.getNombre() << " || "
            << cancion.getArtista() << " || "
            << cancion.getDuracion() << std::endl;
        count++;
    }
}


void Reproductor::ordenarColaPorArtista() {
    int n = colaDeReproduccion.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (colaDeReproduccion[j].getArtista().compare(colaDeReproduccion[j + 1].getArtista()) > 0) {
                std::swap(colaDeReproduccion[j], colaDeReproduccion[j + 1]);
            }
        }
    }
}

void Reproductor::ordenarColaPorNombre() {
    int n = colaDeReproduccion.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (colaDeReproduccion[j].getNombre().compare(colaDeReproduccion[j + 1].getNombre()) > 0) {
                std::swap(colaDeReproduccion[j], colaDeReproduccion[j + 1]);
            }
        }
    }
}

// 
void Reproductor::ordenarColaPorDuracion() {
    int n = colaDeReproduccion.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            double duracion1 = std::stod(colaDeReproduccion[j].getDuracion().substr(0, colaDeReproduccion[j].getDuracion().find(':')))
                + std::stoi(colaDeReproduccion[j].getDuracion().substr(colaDeReproduccion[j].getDuracion().find(':') + 1)) / 60.0;

            double duracion2 = std::stod(colaDeReproduccion[j + 1].getDuracion().substr(0, colaDeReproduccion[j + 1].getDuracion().find(':')))
                + std::stoi(colaDeReproduccion[j + 1].getDuracion().substr(colaDeReproduccion[j + 1].getDuracion().find(':') + 1)) / 60.0;

            if (duracion1 > duracion2) {
                std::swap(colaDeReproduccion[j], colaDeReproduccion[j + 1]);
            }
        }
    }
}

void Reproductor::mostrarReproduccionActual() const {
    if (!colaDeReproduccion.empty()) {
        Cancion cancionEnReproduccion = colaDeReproduccion.front();
        std::cout << "Reproduciendo:\n";
        std::cout << cancionEnReproduccion.getNombre() << " || ";
        std::cout << cancionEnReproduccion.getArtista() << " || ";
        std::cout << cancionEnReproduccion.getDuracion();
    }
    else {
        std::cout << "Reproduccion en Pausa\n";
    }
}


void Reproductor::reproducirSiguiente() {
    if (!colaDeReproduccion.empty()) {
        cancionActual = &(colaDeReproduccion.front());
        colaDeReproduccion.erase(colaDeReproduccion.begin());

    }
    else {
        cancionActual = nullptr;
        cdActual = nullptr;
        reproduciendo = false;
    }
}
