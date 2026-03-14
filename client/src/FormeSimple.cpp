#include "../include/FormeSimple.h"
#include "../include/Matrice22.h"

void FormeSimple::verificationNonEgaliteVecteur2D(const Vecteur2D & a, const Vecteur2D & b) {
    if (a == b) {
        throw ExceptionPointEqualsAnotherPoint();
    }
}

void FormeSimple::verificationTailleVector(const vector<Vecteur2D> & v, const int i) {
    if (v.size() != static_cast<unsigned int>(i)) {
        throw ExceptionArrayIsTooShort();
    }
}

void FormeSimple::verificationAccesVector(const vector<Vecteur2D> & v, const int i) {
    if (i < 0 || static_cast<size_t>(i) >= v.size()) {
        throw ExceptionArrayOutOfBound();
    }
}

void FormeSimple::verificationAccesVectorAddPoint(const vector<Vecteur2D> & v, const int i) {
    if (i < 0 || v.size() < static_cast<unsigned int>(i)) {
        throw ExceptionArrayOutOfBound();
    }
}

FormeSimple::FormeSimple(const Couleur & couleur) : Forme(couleur) {}

FormeSimple::~FormeSimple() = default;

FormeSimple & FormeSimple::translation(const Vecteur2D & p) {
    vector<Vecteur2D> v = getPoints();
    for (auto & it : v) {
        it = it + p;
    }
    setPoints(v);
    return *this;
}

FormeSimple & FormeSimple::homothetie(const Vecteur2D & p, const double & k) {
    verificationKIsNotNull(k);
    vector<Vecteur2D> v = getPoints();
    for (auto & it : v) {
        it = it - p;
        it = it * k;
        it = it + p;
    }
    setPoints(v);
    return *this;
}

FormeSimple & FormeSimple::rotation(const Vecteur2D & p, const double & r) {
    vector<Vecteur2D> v = getPoints();
    for (auto & it : v) {
        it = it - p;
        it = Matrice22::creeRotation(r) * it;
        it = it + p;
    }
    setPoints(v);
    return *this;
}

FormeSimple & FormeSimple::transformationEcran(const Matrice22 & m, const Vecteur2D & ab) {
    vector<Vecteur2D> v = getPoints();
    for (auto & it : v) {
        it = m * it;
        it = it + ab;
    }
    setPoints(v);
    return *this;
}
