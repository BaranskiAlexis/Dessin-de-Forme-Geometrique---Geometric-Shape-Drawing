#include "../include/FormeChargerSegment.h"
#include "../include/Segment.h"

Forme * FormeChargerSegment::charger(const string & s, istringstream & flux) const {
    istringstream iss(s);
    string type;
    if (!(iss >> type) || type != "Segment") {
        return nullptr;
    }
    string couleur;
    double x1, y1, x2, y2;
    if (iss >> couleur >> x1 >> y1 >> x2 >> y2) {
        return new Segment(x1, y1, x2, y2, stringToCouleur(couleur));
    }
    return nullptr;
}

FormeChargerSegment::FormeChargerSegment(FormeCharger * suivant) : FormeCharger(suivant) {}

FormeChargerSegment::~FormeChargerSegment() = default;