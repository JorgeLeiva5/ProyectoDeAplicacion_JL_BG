#include "Reproductor.h"
#include <iostream>

vector<Disco> CDs;
vector<Cancion> cola;
Cancion* reproduciendo = nullptr;

void cargarRespaldos() {
    cout << "Introduce la ruta de los respaldos (sin espacios, para rutas con espacios, use comillas): ";
    string ruta;
    cin.ignore(); // Limpiar el b�fer para getline
    getline(cin, ruta);

    vector<string> archivos = listarArchivos(ruta);
    if (archivos.empty()) {
        cout << "No se encontraron archivos en la ruta especificada." << endl;
        return;
    }

    for (const auto& archivo : archivos) {
        cout << "Procesando archivo: " << archivo << endl; // Mensaje de depuraci�n
        Disco cd = cargarCDDesdeArchivo(ruta + "/" + archivo);
        if (!cd.canciones.empty()) {
            CDs.push_back(cd);
            cout << "CD " << cd.nombreCD << " cargado con �xito." << endl; // Mensaje de confirmaci�n
        }
        else {
            cout << "Error al cargar CD desde archivo: " << archivo << endl; // Mensaje de error
        }
    }
}

Disco cargarCDDesdeArchivo(const string& rutaArchivo) {
    ifstream archivo(rutaArchivo);
    if (!archivo.is_open()) {
        throw runtime_error("No se pudo abrir el archivo " + rutaArchivo);
    }

    Disco cd;
    cd.nombreCD = filesystem::path(rutaArchivo).filename().replace_extension().string();

    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string nombre, artista, duracion;

        getline(ss, nombre, '|');
        getline(ss, artista, '|');
        getline(ss, duracion, '|');

        Cancion cancion;
        cancion.nombre = nombre;
        cancion.artista = artista;
        cancion.duracion = duracion;

        cd.canciones.push_back(cancion);
    }

    archivo.close();
    return cd;
}


bool formatoValido(const string& linea) {
    int Count = count(linea.begin(), linea.end(), '|');
    return Count == 4 && linea.find("||") != string::npos;
}

void mostrarCDs() {
    for (int i = 0; i < CDs.size(); ++i) {
        cout << i + 1 << ". " << CDs[i].nombreCD << endl;
    }
}

void agregarCancion() {
    mostrarCDs();
    mostrarCDs();
    int eleccion;
    cout << "Seleccione un CD: ";
    cin >> eleccion;
    if (eleccion <= 0 || eleccion > CDs.size()) {
        cout << "Selecci�n no v�lida." << endl;
        return;
    }

    Disco& cdElegido = CDs[eleccion - 1];
    for (int i = 0; i < cdElegido.canciones.size(); ++i) {
        cout << i + 1 << ". " << cdElegido.canciones[i].nombre << endl;
    }
    cout << "Seleccione una canci�n: ";
    cin >> eleccion;
    if (eleccion <= 0 || eleccion > cdElegido.canciones.size()) {
        cout << "Selecci�n no v�lida." << endl;
        return;
    }

    cola.push_back(cdElegido.canciones[eleccion - 1]);
    cout << "Canci�n agregada a la cola." << endl;
}

void verColaReproduccion() {
    if (cola.empty()) {
        std::cout << "Cola de reproducci�n vac�a." << std::endl;
        return;
    }

    for (const auto& cancion : cola) {
        std::cout << cancion.nombre << " - " << cancion.artista << " - " << cancion.duracion << std::endl;
    }
}


void reproducirActual() {
    if (reproduciendo) {
        cout << "Reproduciendo: " << reproduciendo->nombre << " - " << reproduciendo->artista << " - " << reproduciendo->duracion << endl;
    }
    else {
        cout << "Reproducci�n en pausa." << endl;
    }
}


void reproducirSiguiente() {
    if (cola.empty()) {
        cout << "Cola de reproducci�n vac�a." << endl;
        return;
    }

    if (reproduciendo) {
        cola.push_back(*reproduciendo);
    }
    reproduciendo = &cola.front();
    cola.erase(cola.begin());
}

void ordenarCola() {
    cout << "1. Ordenar por artista\n";
    cout << "2. Ordenar por canci�n\n";
    cout << "3. Ordenar por duraci�n\n";
    int eleccion;
    cin >> eleccion;

    switch (eleccion) {
    case 1:
        sort(cola.begin(), cola.end(), [](const Cancion& a, const Cancion& b) {
            return a.artista < b.artista;
            });
        break;
    case 2:
        sort(cola.begin(), cola.end(), [](const Cancion& a, const Cancion& b) {
            return a.nombre < b.nombre;
            });
        break;
    case 3:
        sort(cola.begin(), cola.end(), [](const Cancion& a, const Cancion& b) {
            return a.duracion < b.duracion;
            });
        break;
    default:
        cout << "Opci�n no v�lida." << endl;
        break;
    }
}

vector <string> listarArchivos(const string& ruta) {
    vector<string> archivos;
    for (const auto& entry : filesystem::directory_iterator(ruta)) {
        if (entry.is_regular_file() && entry.path().extension() == ".txt") {
            archivos.push_back(entry.path().filename().string());
        }
    }
    return archivos;
}




