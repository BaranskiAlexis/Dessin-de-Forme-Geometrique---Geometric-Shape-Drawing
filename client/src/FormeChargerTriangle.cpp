#include "../include/FormeChargerTriangle.h"
#include "../include/Triangle.h"

Forme * FormeChargerTriangle::charger(const string & s, istringstream & flux) const {
    istringstream iss(s);
    string type;
    if (!(iss >> type) || type != "Triangle") {
        return nullptr;
    }
    string couleur;
    double x1, y1, x2, y2, x3, y3;
    if (iss >> couleur >> x1 >> y1 >> x2 >> y2 >> x3 >> y3) {
        return new Triangle(x1, y1, x2, y2, x3, y3, stringToCouleur(couleur));
    }
    return nullptr;
}

FormeChargerTriangle::FormeChargerTriangle(FormeCharger * suivant) : FormeCharger(suivant) {}

FormeChargerTriangle::~FormeChargerTriangle() = default;