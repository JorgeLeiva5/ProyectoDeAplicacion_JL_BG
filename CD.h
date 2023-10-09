#pragma once
#ifndef CD_H
#define CD_H

#include <vector>
#include <string>
#include "Cancion.h"

class CD {
private:
    std::vector<Cancion> canciones;
    std::string nombreCD;

public:
    CD(const std::string& nombreCD);
    std::string getNombreCD() const;


    void agregarCancion(const Cancion& cancion);
    std::vector<Cancion> getCanciones() const;


    std::string getNombreCancion(int index) const;
    std::string getArtistaCancion(int index) const;
    std::string getDuracionCancion(int index) const;
public:
    CD();
};


#endif
