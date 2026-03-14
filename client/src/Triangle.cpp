#include "../include/Triangle.h"
#include "../include/FormeVisiteur.h"

Triangle::Triangle(const Vecteur2D & p1, const Vecteur2D & p2, const Vecteur2D & p3, const Couleur& couleur) : FormeSimple(couleur) {
    verificationNonEgaliteVecteur2D(p1, p2); verificationNonEgaliteVecteur2D(p2, p3); verificationNonEgaliteVecteur2D(p1, p3);
    p[0] = p1;
    p[1] = p2;
    p[2] = p3;
}

Triangle::Triangle(const double & x1, const double & y1, const double & x2, const double & y2, const double & x3, const double & y3, const Couleur & couleur) : Triangle(Vecteur2D(x1, y1), Vecteur2D(x2, y2), Vecteur2D(x3, y3), couleur) {}

Triangle * Triangle::clone() const {
    return new Triangle(*this);
}

Triangle::~Triangle() = default;

Vecteur2D Triangle::getp1() const {
    return p[0];
}

Vecteur2D Triangle::getp2() const {
    return p[1];
}

Vecteur2D Triangle::getp3() const {
    return p[2];
}

Triangle & Triangle::setp1(const Vecteur2D & p1) {
    p[0] = p1;
    return *this;
}

Triangle & Triangle::setp1(const double & x1, const double & y1) {
    return setp1(Vecteur2D(x1, y1));
}

Triangle & Triangle::setp2(const Vecteur2D & p2) {
    verificationNonEgaliteVecteur2D(p2, p[0]); verificationNonEgaliteVecteur2D(p2, p[2]);
    p[1] = p2;
    return *this;
}

Triangle & Triangle::setp2(const double & x2, const double & y2) {
    return setp2(Vecteur2D(x2, y2));
}

Triangle & Triangle::setp3(const Vecteur2D & p3) {
    verificationNonEgaliteVecteur2D(p3, p[0]); verificationNonEgaliteVecteur2D(p3, p[1]);
    p[2] = p3;
    return *this;
}

Triangle & Triangle::setp3(const double & x3, const double & y3) {
    return setp3(Vecteur2D(x3, y3));
}

vector<Vecteur2D> Triangle::getPoints() const {
    return {p, p + sizeof(p) / sizeof(p[0])};
}

Triangle & Triangle::setPoints(const vector<Vecteur2D> & v) {
    verificationTailleVector(v, 3);
    verificationNonEgaliteVecteur2D(v[0], v[1]); verificationNonEgaliteVecteur2D(v[1], v[2]); verificationNonEgaliteVecteur2D(v[2], v[0]);
    p[0] = v[0];
    p[1] = v[1];
    p[2] = v[2];
    return *this;
}

double Triangle::getAire() const {
    return ((p[1] - p[0]) | (p[2] - p[0])) / 2;
}

string Triangle::toString() const {
    return "Triangle " + Forme::toString() + " " + string(p[0]) + " " + string(p[1]) + " " + string(p[2]);
}

Triangle & Triangle::accept(FormeVisiteur & visiteur) {
    visiteur.visit(*this);
    return *this;
}