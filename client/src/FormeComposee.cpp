#include "../include/FormeComposee.h"
#include "../include/FormeVisiteur.h"

void FormeComposee::copy(const FormeComposee & f) {
    Forme::operator=(f);
    for (const auto it : f.getFormes()) {
        v.push_back(it->clone());
    }
}

void FormeComposee::destroy() {
    for (const auto it : v) {
        delete it;
    }
    v.clear();
}

void FormeComposee::verificationAccesVector(const vector<Forme *> & v, const int i) {
    if (i < 0 || static_cast<size_t>(i) >= v.size()) {
        throw ExceptionArrayOutOfBoundFC();
    }
}

void FormeComposee::verificationAccesVectorAddForme(const vector<Forme *> & v, const int i) {
    if (i < 0 || v.size() < static_cast<unsigned int>(i)) {
        throw ExceptionArrayOutOfBoundFC();
    }
}

FormeComposee::FormeComposee(const Couleur & couleur) : Forme(couleur) {}

FormeComposee::FormeComposee(const vector<Forme*> & v, const Couleur& couleur) : Forme(couleur) {
    setFormes(v);
}

FormeComposee::FormeComposee(const FormeComposee & f) : Forme(f) {
    copy(f);
}

FormeComposee & FormeComposee::operator=(const FormeComposee & f) {
    if (this != &f) {
        destroy();
        copy(f);
    }
    return *this;
}

FormeComposee::~FormeComposee() {
    destroy();
}

FormeComposee * FormeComposee::clone() const {
    return new FormeComposee(*this);
}

vector<Vecteur2D> FormeComposee::getPoints() const {
    vector<Vecteur2D> p = {};
    for (const auto it : this->v) {
        vector<Vecteur2D> tmp = it->getPoints();
        p.insert(p.end(), tmp.begin(), tmp.end());
    }
    return p;
}

vector<Forme*> FormeComposee::getFormes() const {
    return v;
}

FormeComposee & FormeComposee::setFormes(const vector<Forme *> & vf) {
    for (const auto it : v) {
        delete it;
    }
    this->v.clear();
    for (const auto it : vf) {
        this->v.push_back(it->clone());
    }
    return *this;
}

Forme * FormeComposee::getFormeAt(const int i) const {
    verificationAccesVector(v, i);
    return v[i];
}

FormeComposee & FormeComposee::addForme(const Forme & f) {
    v.push_back(f.clone());
    return *this;
}

FormeComposee& FormeComposee::addFormeAt(const Forme & f, const int i) {
    verificationAccesVectorAddForme(v, i);
    v.insert(v.begin() + i, f.clone());
    return *this;
}

FormeComposee & FormeComposee::removeFormeAt(const int i) {
    verificationAccesVector(v, i);
    const Forme * f = *(v.begin() + i);
    v.erase(v.begin() + i);
    delete f;
    return *this;
}

double FormeComposee::getAire() const {
    double aire = 0;
    for (const auto it : v) {
        aire += it->getAire();
    }
    return aire;
}

FormeComposee & FormeComposee::translation(const Vecteur2D & p) {
    for (const auto it : v) {
        it->translation(p);
    }
    return *this;
}

FormeComposee & FormeComposee::homothetie(const Vecteur2D & p, const double & k) {
    for (const auto it : v) {
        it->homothetie(p, k);
    }
    return *this;
}

FormeComposee & FormeComposee::rotation(const Vecteur2D & p, const double & r) {
    for (const auto it : v) {
        it->rotation(p, r);
    }
    return *this;
}

FormeComposee & FormeComposee::transformationEcran(const Matrice22& m, const Vecteur2D& ab) {
    for (const auto it : v) {
        it->transformationEcran(m, ab);
    }
    return *this;
}

string FormeComposee::toString() const {
    string str = "FormeComposee " + Forme::toString() + " [\n";
    for (const auto it : v) {
        str += it->toString() + "\n";
    }
    return str + "]";
}

FormeComposee & FormeComposee::operator+(const Forme & f) {
    return addForme(f);
}

FormeComposee & FormeComposee::operator-(const int i) {
    return removeFormeAt(i);
}

Forme * FormeComposee::operator[](const int i) const {
    return getFormeAt(i);
}

FormeComposee & FormeComposee::accept(FormeVisiteur & visiteur) {
    visiteur.visit(*this);
    return *this;
}