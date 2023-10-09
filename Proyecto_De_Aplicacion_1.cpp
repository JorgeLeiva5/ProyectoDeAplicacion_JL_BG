#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <filesystem>
#include <fstream>
#include <sstream>
#include "Cancion.h"
#include "Disco.h"
#include "Reproductor.h"
using namespace std;

int main() {
    Reproductor reproductor;

    int op;

    do {
        cout << "\n--- Menu ---" << endl;
        cout << "1. Cargar respaldos" << endl;
        cout << "2. Agregar Cancion" << endl;
        cout << "3. Ver Cola de Reproduccion" << endl;
        cout << "4. Ordenar Cola de Reproduccion" << endl;
        cout << "5. Reproducir Cancion Actual" << endl;
        cout << "6. Reproducir Siguiente Cancion" << endl;
        cout << "7. Salir" << endl;

        cout << "Seleccione una opcion: ";
        while (!(cin >> op)) {
            cout << "Por favor, ingrese un número válido: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (op) {
        case 1:
            reproductor.cargarRespaldos();
            break;
        case 2:
            reproductor.agregarCancion();
            break;
        case 3:
            reproductor.verColaReproduccion();
            break;
        case 4:
            reproductor.ordenarCola();
            break;
        case 5:
            reproductor.reproducirActual();
            break;
        case 6:
            reproductor.reproducirSiguiente();
            break;
        case 7:
            break;
        default:
            cout << "Opción no válida. Por favor, intente nuevamente." << endl;
            break;
        }

        // Pausar y esperar que el usuario presione enter para continuar
        cout << "\nPresione ENTER para continuar...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();

    } while (op != 7);

    return 0;
}
