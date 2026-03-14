#include "../include/FormeChargerPolygone.h"
#include "../include/Polygone.h"

Forme * FormeChargerPolygone::charger(const string & s, istringstream & flux) const {
    istringstream iss(s);
    string type;
    if (!(iss >> type) || type != "Polygone") {
        return nullptr;
    }
    string couleur;
    if (iss >> couleur) {
        auto * p = new Polygone(stringToCouleur(couleur));
        double x, y;
        while (iss >> x >> y) {
            *p + Vecteur2D(x, y);
        }
        return p;
    }
    return nullptr;
}

FormeChargerPolygone::FormeChargerPolygone(FormeCharger * suivant) : FormeCharger(suivant) {}

FormeChargerPolygone::~FormeChargerPolygone() = default;