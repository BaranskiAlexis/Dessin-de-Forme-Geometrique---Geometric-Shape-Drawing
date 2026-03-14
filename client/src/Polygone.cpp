#include <algorithm>
#include "../include/Polygone.h"
#include "../include/FormeVisiteur.h"

void Polygone::verificationParametreVector(const vector<Vecteur2D> & v) {
    if (v.size() >= 2) {
        for (auto it = v.begin(); it != v.end() - 1; ++it) {
            for (auto it2 = it + 1; it2 != v.end(); ++it2) {
                verificationNonEgaliteVecteur2D(*it, *it2);
            }
        }
    }
}

void Polygone::verificationVectorEtVecteur2D(const vector<Vecteur2D>& v, const Vecteur2D& p) {
    for (auto it : v) {
        verificationNonEgaliteVecteur2D(it, p);
    }
}

Polygone::Polygone(const Couleur & couleur) : FormeSimple(couleur) {
}

Polygone::Polygone(const vector<Vecteur2D> & v, const Couleur & couleur) : FormeSimple(couleur) {
    verificationParametreVector(v);
    this->v = v;
}

Polygone * Polygone::clone() const {
    return new Polygone(*this);
}

Polygone::~Polygone() = default;

vector<Vecteur2D> Polygone::getPoints() const {
    return v;
}

Polygone & Polygone::setPoints(const vector<Vecteur2D>& v) {
    verificationParametreVector(v);
    this->v = v;
    return *this;
}

Vecteur2D Polygone::getPointAt(const int i) const {
    verificationAccesVector(v, i);
    return v[i];
}

Polygone & Polygone::addPoint(const Vecteur2D & p) {
    verificationVectorEtVecteur2D(v, p);
    v.push_back(p);
    return *this;
}

Polygone & Polygone::addPointAt(const Vecteur2D & p, const int i) {
    verificationAccesVectorAddPoint(v, i);
    verificationVectorEtVecteur2D(v, p);
    v.insert(v.begin() + i, p);
    return *this;
}

Polygone & Polygone::removePoint(const Vecteur2D & p) {
    const auto it = find(v.begin(), v.end(), p);
    if (it != v.end()) v.erase(it);
    return *this;
}

Polygone & Polygone::removePointAt(const int i) {
    verificationAccesVector(v, i);
    v.erase(v.begin() + i);
    return *this;
}

Polygone & Polygone::modifyPoint(const Vecteur2D & p, const Vecteur2D & q) {
    verificationVectorEtVecteur2D(v, q);
    const auto it = find(v.begin(), v.end(), p);
    if (it != v.end()) *it = q;
    return *this;
}


Polygone & Polygone::modifyPointAt(const int i, const Vecteur2D & q) {
    verificationVectorEtVecteur2D(v, q);
    verificationAccesVector(v, i);
    *(v.begin() + i) = q;
    return *this;
}

Polygone & Polygone::switchPoint(const Vecteur2D & p, const Vecteur2D & q) {
    const auto it = find(v.begin(), v.end(), p);
    if (it != v.end()) {
        const auto it2 = find(v.begin(), v.end(), q);
        if (it2 != v.end()) {
            *it = q;
            *it2 = p;
        }
    }
    return *this;
}

Polygone & Polygone::switchPointAt(const int i, const int j) {
    verificationAccesVector(v, i);
    verificationAccesVector(v, j);
    const Vecteur2D tmp = *(v.begin() + i);
    *(v.begin() + i) = *(v.begin() + j);
    *(v.begin() + j) = tmp;
    return *this;
}

double Polygone::getAire() const {
    double aire = 0;
    if (v.size() >= 3) {
        const Vecteur2D o = v[0];
        for (auto it = v.begin() + 2; it != v.end(); ++it) {
            aire += ((o - *(it - 1)) | (o - *it)) / 2;
        }
    }
    return aire;
}

string Polygone::toString() const {
    string s = "Polygone " + Forme::toString();
    for (auto it : v) {
        s += " " + string(it);
    }
    return s;
}

Polygone & Polygone::operator+(const Vecteur2D & p) {
    return addPoint(p);
}

Polygone & Polygone::operator-(const Vecteur2D & p) {
    return removePoint(p);
}

Vecteur2D Polygone::operator[](const int i) const {
    return getPointAt(i);
}

Polygone & Polygone::accept(FormeVisiteur& visiteur) {
    visiteur.visit(*this);
    return *this;
}