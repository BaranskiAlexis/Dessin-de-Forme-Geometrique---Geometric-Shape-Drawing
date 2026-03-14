#include "../include/FormeChargerCercle.h"
#include "../include/Cercle.h"

Forme * FormeChargerCercle::charger(const string & s, istringstream & flux) const {
    istringstream iss(s);
    string type;
    if (!(iss >> type) || type != "Cercle") {
        return nullptr;
    }
    string couleur;
    double xc, yc, r;
    if (iss >> couleur >> xc >> yc >> r) {
        return new Cercle(xc, yc, r, stringToCouleur(couleur));
    }
    return nullptr;
}

FormeChargerCercle::FormeChargerCercle(FormeCharger * suivant) : FormeCharger(suivant) {}

FormeChargerCercle::~FormeChargerCercle() = default;