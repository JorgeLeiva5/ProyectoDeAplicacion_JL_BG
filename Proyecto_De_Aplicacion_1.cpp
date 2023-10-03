#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <queue>
#include "CDs.h"

using namespace std;
namespace fs = filesystem;

int main() {
    string carpeta, DISCO;
    int ContadorDeListas = 0, ContadorDeCanciones = 0;
    cout << "Ingrese la ruta de la carpeta para cargar sus CD's (RESPALDO): ";
    cin >> carpeta;
    try {
        for (const auto& inicio : fs::directory_iterator(carpeta)) {
            if (inicio.is_regular_file() && inicio.path().extension() == ".txt") {
                ifstream file(inicio.path());
                if (file.is_open()) {
                    cout << "Contenido de " << inicio.path().filename() << ":" << endl;
                    string linea;
                    DISCO == inicio.path().filename();
                    while (getline(file, linea)) {
                        cout << linea << endl;
                        ContadorDeCanciones++;
                    }

                    CDs DISCO = CDs();

                    // *********** ESPACIO PARA CREAR LAS COLAS *****************


                    file.close();
                }
                else {
                    cerr << "No se pudo abrir el archivo: " << inicio.path().filename() << endl;
                }
            }
            ContadorDeListas++;
            cout << DISCO << endl;
        }
    }
    catch (const exception& e) {
        cerr << "Error al acceder a la carpeta: " << e.what() << endl;
    }

    cout << ContadorDeListas << endl;
    cout << ContadorDeCanciones << endl;
}

