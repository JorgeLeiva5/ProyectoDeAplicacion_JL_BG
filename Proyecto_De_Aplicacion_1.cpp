#include "Reproductor.h"
#include <iostream>


int main() {
    //std::string RUTAN;
    //std::cout << "Ingrese la rura para buscar sus archivos: ";
    //std::cin >> RUTAN;
    //Reproductor reproductor(RUTAN);
    // no pudimos leer la ruta :(

    Reproductor reproductor("C:\\ArchivosdePrueba_20231001"); // Ingresar aca la ruta de la carpeta

    int opcion = 0;
    do {
        std::cout << "\n--- Menu Principal ---\n";
        std::cout << "1. Cargar y mostrar canciones\n";
        std::cout << "2. Agregar Cancion a la cola de reproduccion\n";
        std::cout << "3. Ver Cola de Reproduccion\n";
        std::cout << "4. Reproducir siguiente\n";
        std::cout << "5. Mostrar reproduccion actual\n";
        std::cout << "6. Salir\n";
        std::cout << "Ingrese una opcion: ";
        std::cin >> opcion;
        std::cin.ignore();

        switch (opcion) {
        case 1:
            reproductor.cargarCDs();
            reproductor.mostrarCDs();
            break;

        case 2:
            reproductor.mostrarCDs();
            std::cout << "\nSeleccione un CD por su numero: ";
            int indiceCD;
            std::cin >> indiceCD;
            reproductor.mostrarCancionesDeCD(indiceCD - 1);
            std::cout << "\nSeleccione una cancion por su numero: ";
            int indiceCancion;
            std::cin >> indiceCancion;
            reproductor.agregarACola(indiceCD - 1, indiceCancion - 1);
            break;

        case 3:
            std::cout << "\n--- Ver Cola de Reproduccion ---\n";
            std::cout << "1. Ver tal cual\n";
            std::cout << "2. Ordenar por nombre del artista\n";
            std::cout << "3. Ordenar por nombre de la cancion\n";
            std::cout << "4. Ordenar por duracion de la cancion\n";
            std::cout << "Ingrese una opcion: ";
            int opcionCola;
            std::cin >> opcionCola;
            switch (opcionCola) {
            case 1:
                reproductor.mostrarColaReproduccion();
                break;
            case 2:
                reproductor.ordenarColaPorArtista();
                reproductor.mostrarColaReproduccion();
                break;
            case 3:
                reproductor.ordenarColaPorNombre();
                reproductor.mostrarColaReproduccion();
                break;
            case 4:
                reproductor.ordenarColaPorDuracion();
                reproductor.mostrarColaReproduccion();
                break;
                std::cout << "Opcion no valida.\n";
                break;
            }
            break;

        case 4:
            reproductor.reproducirSiguiente();
            break;
        case 5:
            reproductor.mostrarReproduccionActual();
            break;
        case 6:
            std::cout << "¡Hasta luego!\n";
            break;

        default:
            std::cout << "Opcion no valida. Por favor, intente nuevamente.\n";
            break;
        }
    } while (opcion != 6);

    return 0;
}

