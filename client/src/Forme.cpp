#include "../include/Forme.h"
#include "../include/FormeCharger.h"
#include "../include/FormeChargerCercle.h"
#include "../include/FormeChargerFormeComposee.h"
#include "../include/FormeChargerPolygone.h"
#include "../include/FormeChargerSegment.h"
#include "../include/FormeChargerTriangle.h"

void Forme::verificationKIsNotNull(const double & k) {
    if (k == 0) {
        throw ExceptionKIsNull();
    }
}

Forme::Forme(const Couleur & couleur): couleur(couleur) {}

Forme::~Forme() = default;

Couleur Forme::getCouleur() const {
    return couleur;
}

Forme & Forme::setCouleur(const Couleur & couleur) {
    this->couleur = couleur;
    return *this;
}

Forme * Forme::charger(const string & path) {
    FormeCharger * fc = new FormeChargerSegment(nullptr);
    fc = new FormeChargerCercle(fc);
    fc = new FormeChargerTriangle(fc);
    fc = new FormeChargerPolygone(fc);
    fc = new FormeChargerFormeComposee(fc);
    Forme * f = fc->chargerDepuisFichier(path);
    delete fc;
    return f;
}

string Forme::toString() const {
    return couleurToString(couleur);
}

Forme::operator string() const {
    return toString();
}

ostream & operator<<(ostream & s, const Forme & f) {
    return s << string(f);
}