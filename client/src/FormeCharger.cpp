#include <fstream>
#include "../include/FormeCharger.h"

FormeCharger * FormeCharger::origine = nullptr;

FormeCharger::FormeCharger(FormeCharger * suivant) : suivant(suivant) {
    origine = this;
}

FormeCharger::~FormeCharger() {
    delete suivant;
}

FormeCharger * FormeCharger::getOrigine() {
    return origine;
}

Forme * FormeCharger::chargerDepuisFichier(const string & path) const {
    ifstream f(path);
    if (!f.is_open()) {
        throw ExceptionFileCantBeRead();
    }
    stringstream buffer;
    buffer << f.rdbuf();
    f.close();
    istringstream flux(buffer.str());
    string s;
    Forme * forme = chargerDepuisFluxStart(flux);
    return forme;
}

Forme * FormeCharger::chargerDepuisFluxStart(istringstream & flux) const {
    string s;
    if (!getline(flux, s)) {
        throw ExceptionFileIsEmpty();
    }
    Forme * f = chargerDepuisFlux(s, flux);
    return f;
}

Forme * FormeCharger::chargerDepuisFlux(const string & s, istringstream & flux) const {
    Forme * f = charger(s, flux);
    if (f != nullptr) return f;
    if (suivant != nullptr) return suivant->chargerDepuisFlux(s, flux);
    throw ExceptionStringIsNotRecognizable();
}