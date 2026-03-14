#ifndef PPIL_FORMEVISITEUR_H
#define PPIL_FORMEVISITEUR_H
#include "FormeComposee.h"
#include "Cercle.h"
#include "Polygone.h"
#include "Segment.h"
#include "Triangle.h"

/**
 * @brief Permet de gérer l'ensemble des exceptions liées aux visiteurs de formes
 */
class ExceptionFormeVisiteur : public ExceptionForme {
    /**
    * @brief Le message lié à l'exception
    */
    string message = " ExceptionFormeVisiteur -";
public:
    /**
    * @brief Permet d'obtenir une chaîne de caractère lié à l'erreur
    * @return Une chaîne de caractère
    */
    string getMessage() const override {
        return ExceptionForme::getMessage() + message;
    }
};

/**
 * @brief Permet l'implémentation du pattern design visiteur pour les formes
 */
class FormeVisiteur {
public:
    /**
     * @brief Permet la destruction du visiteur de forme simple
     */
    virtual ~FormeVisiteur() = default;
    /**
     * @brief Permet l'introduction de méthode pour un segment via le design pattern visitor
     * @param[in] f Un segment
     * @return \p (*this) L'objet implicite
     */
    virtual FormeVisiteur & visit(const Segment & f) = 0;
    /**
     * @brief Permet l'introduction de méthode pour un cercle via le design pattern visitor
     * @param[in] f Un cercle
     * @return \p (*this) L'objet implicite
     */
    virtual FormeVisiteur & visit(const Cercle & f) = 0;
    /**
     * @brief Permet l'introduction de méthode pour un triangle via le design pattern visitor
     * @param[in] f Un triangle
     * @return \p (*this) L'objet implicite
     */
    virtual FormeVisiteur & visit(const Triangle & f) = 0;
    /**
     * @brief Permet l'introduction de méthode pour un polygone via le design pattern visitor
     * @param[in] f Un polygone
     * @return \p (*this) L'objet implicite
     */
    virtual FormeVisiteur & visit(const Polygone & f) = 0;
    /**
     * @brief Permet l'introduction de méthode pour une forme composée via le design pattern visitor
     * @param[in] f Une forme composée
     * @return \p (*this) L'objet implicite
     */
    virtual FormeVisiteur & visit(const FormeComposee & f) = 0;
};

#endif