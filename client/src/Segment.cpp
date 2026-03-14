#include "../include/Segment.h"
#include "../include/FormeVisiteur.h"

Segment::Segment(const Vecteur2D & p1, const Vecteur2D & p2, const Couleur& couleur) : FormeSimple(couleur) {
    verificationNonEgaliteVecteur2D(p1, p2);
    p[0] = p1; p[1] = p2;
}

Segment::Segment(const double & x1, const double & y1, const double & x2, const double & y2 , const Couleur & couleur) : Segment(Vecteur2D(x1, y1), Vecteur2D(x2, y2), couleur) {}

Segment * Segment::clone() const {
    return new Segment(*this);
}

Segment::~Segment() = default;

Vecteur2D Segment::getp1() const {
    return p[0];
}

Vecteur2D Segment::getp2() const {
    return p[1];
}

Segment & Segment::setp1(const Vecteur2D & p1) {
    verificationNonEgaliteVecteur2D(p1, p[1]);
    p[0] = p1;
    return *this;
}

Segment & Segment::setp1(const double & x1, const double & y1) {
    return setp1(Vecteur2D(x1, y1));
}

Segment & Segment::setp2(const Vecteur2D & p2) {
    verificationNonEgaliteVecteur2D(p2, p[0]);
    p[1] = p2;
    return *this;
}

Segment & Segment::setp2(const double & x2, const double & y2) {
    return setp2(Vecteur2D(x2, y2));
}

vector<Vecteur2D> Segment::getPoints() const {
    return {p, p + sizeof(p) / sizeof(p[0])};
}

Segment & Segment::setPoints(const vector<Vecteur2D> & v) {
    verificationTailleVector(v, 2);
    verificationNonEgaliteVecteur2D(v[0], v[1]);
    p[0] = v[0];
    p[1] = v[1];
    return *this;
}

double Segment::getAire() const {
    return 0;
}


string Segment::toString() const {
    return "Segment " + Forme::toString() + " " + string(p[0]) + " " + string(p[1]);
}

Segment& Segment::accept(FormeVisiteur & visiteur) {
    visiteur.visit(*this);
    return *this;
}