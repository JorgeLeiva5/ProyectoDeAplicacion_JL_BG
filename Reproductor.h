#pragma once
#include "Cancion.h"
#include "Disco.h"

class Reproductor
{
public:

	Reproductor(){}
	void cargarRespaldos(){}
	Disco cargarCDDesdeArchivo(const string& RutaArchivo){}
	bool formatoValido(const string& linea){}
	void mostrarCDs(){}
	void agregarCancion(){}
	void verColaReproduccion(){}
	void reproducirActual(){}
	void reproducirSiguiente(){}
	void ordenarCola(){}
	vector <string> listarArchivos(const string& ruta){}
};
