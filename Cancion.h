#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <filesystem>
#include <fstream>
#include <sstream>
using namespace std;

class Cancion
{
public:
    string nombre;
    string artista;
    string duracion;

    Cancion(){}
    Cancion(string _nombre, string _artista, string _duracion) : nombre(_nombre), artista(_artista), duracion(_duracion) {}
};

