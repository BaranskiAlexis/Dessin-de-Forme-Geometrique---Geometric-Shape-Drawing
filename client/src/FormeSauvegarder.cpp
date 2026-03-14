#include <fstream>
#include <utility>
#include "../include/FormeSauvegarder.h"

FormeSauvegarder & FormeSauvegarder::sauvegarderForme(const string & formeToString) {
    ofstream file(path, ios::out);
    if (!file) {
        throw ExceptionFileCantBeOpen();
    }
    file << formeToString;
    file.close();
    return *this;
}

FormeSauvegarder::FormeSauvegarder(string path) : path(std::move(path)) {}

FormeSauvegarder::~FormeSauvegarder() = default;

FormeSauvegarder & FormeSauvegarder::visit(const Segment & f) {
    return sauvegarderForme(string(f));
}

FormeSauvegarder & FormeSauvegarder::visit(const Cercle & f) {
    return sauvegarderForme(string(f));
}

FormeSauvegarder & FormeSauvegarder::visit(const Triangle & f) {
    return sauvegarderForme(string(f));
}

FormeSauvegarder & FormeSauvegarder::visit(const Polygone & f) {
    return sauvegarderForme(string(f));
}

FormeSauvegarder & FormeSauvegarder::visit(const FormeComposee & f) {
    return sauvegarderForme(string(f));
}