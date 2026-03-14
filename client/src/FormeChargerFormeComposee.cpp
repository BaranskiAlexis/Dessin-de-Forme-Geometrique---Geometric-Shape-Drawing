#include "../include/FormeChargerFormeComposee.h"
#include "../include/FormeComposee.h"

Forme * FormeChargerFormeComposee::charger(const string & s, istringstream & flux) const {
    istringstream iss(s);
    string type;
    if (!(iss >> type) || type != "FormeComposee") {
        return nullptr;
    }
    string couleur;
    if (iss >> couleur) {
        auto * f = new FormeComposee(stringToCouleur(couleur));
        string sEnfant;
        while (getline(flux, sEnfant) && sEnfant.find(']') == string::npos) {
            const Forme * tmp = getOrigine()->chargerDepuisFlux(sEnfant, flux);
            *f + *tmp;
            delete tmp;
        }
        return f;
    }
    return nullptr;
}

FormeChargerFormeComposee::FormeChargerFormeComposee(FormeCharger * suivant) : FormeCharger(suivant) {}

FormeChargerFormeComposee::~FormeChargerFormeComposee() = default;