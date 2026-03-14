#include "../include/Cercle.h"
#include "../include/FormeVisiteur.h"

void Cercle::verificationRayon(const double & r) {
    if (r <= 0) {
        throw ExceptionRayonNegatif();
    }
}

Cercle::Cercle(const Vecteur2D & c, const double & r, const Couleur& couleur) : FormeSimple(couleur) {
    verificationRayon(r);
    this->c = c; this->r = r;
}

Cercle::Cercle(const double & xc, const double & yc, const double & r, const Couleur & couleur) : Cercle(Vecteur2D(xc, yc), r, couleur) {}

Cercle * Cercle::clone() const {
    return new Cercle(*this);
}

Cercle::~Cercle() = default;

Vecteur2D Cercle::getc() const {
    return c;
}

double Cercle::getr() const {
    return r;
}

Cercle & Cercle::setc(const Vecteur2D & c) {
    this->c = c;
    return *this;
}

Cercle & Cercle::setc(const double & xc, const double & yc) {
    return setc(Vecteur2D(xc, yc));
}

Cercle & Cercle::setr(const double & r) {
    verificationRayon(r);
    return *this;
}

vector<Vecteur2D> Cercle::getPoints() const {
    return {c, Vecteur2D(c.x - r, c.y - r), Vecteur2D(c.x + r, c.y + r)};
}

Cercle & Cercle::setPoints(const vector<Vecteur2D> & v) {
    verificationTailleVector(v, 3);
    verificationNonEgaliteVecteur2D(v[1], v[2]);
    c = v[0];
    r = (v[1] - v[2]).norme() / (2 * sqrt(2));
    return *this;
}

double Cercle::getAire() const {
    return M_PI * pow(r, 2);
}

string Cercle::toString() const {
    return "Cercle " + Forme::toString() + " " + string(c) + " " + to_string(r);
}

Cercle & Cercle::accept(FormeVisiteur & visiteur) {
    visiteur.visit(*this);
    return *this;
}