#ifndef PPIL_DESSINER_H
#define PPIL_DESSINER_H
#include "FormeVisiteur.h"

/**
 * @brief Permet de gérer l'ensemble des exceptions liées aux visiteurs de formes sauvegarde
 */
class ExceptionSauvegarder : public ExceptionFormeVisiteur {
    /**
    * @brief Le message lié à l'exception
    */
    string message = " ExceptionSauvegarder -";
public:
    /**
    * @brief Permet d'obtenir une chaîne de caractère lié à l'erreur
    * @return Une chaîne de caractère
    */
    string getMessage() const override {
        return ExceptionFormeVisiteur::getMessage() + message;
    }
};

/**
 * @brief Permet de gérer l'exception liée à l'impossibilité de créer un fichier.
 */
class ExceptionFileCantBeOpen : public ExceptionSauvegarder {
    /**
    * @brief Le message lié à l'exception
    */
    string message = " Le fichier ne peut pas etre cree";
public:
    /**
    * @brief Permet d'obtenir une chaîne de caractère lié à l'erreur
    * @return Une chaîne de caractère
    */
    string getMessage() const override {
        return ExceptionSauvegarder::getMessage() + message;
    }
};

/**
 * @brief Permet l'implémentation du pattern design visiteur pour les formes dans le cadre d'une sauvegarde
 */
class FormeSauvegarder : public FormeVisiteur {
    /**
    * @brief Le path du fichier où sera enregistrée la forme
    */
    const string path;
    /**
     * @brief Permet la sauvegarde d'une forme à partir de sa chaine de caractère
     * @param[in] formeToString La chaine de caractère de la forme
     * @return \p (*this) L'objet implicite
     */
    FormeSauvegarder & sauvegarderForme(const string & formeToString);
public:
    /**
     * @brief Permet la construction du Visiteur permettant la sauvegarde d'un objet à partir d'un nom de fichier
     * @param[in] path Le nom du fichier
     */
    explicit FormeSauvegarder(string path);
    /**
     * @brief Permet la destruction de l'objet
     */
    ~FormeSauvegarder() override;
    /**
     * @brief Permet l'introduction de méthode pour un segment via le design pattern visitor, ici la sauvegarde
     * @param[in] f Un segment
     * @return \p (*this) L'objet implicite
     */
    FormeSauvegarder & visit(const Segment & f) override;
    /**
     * @brief Permet l'introduction de méthode pour un cercle via le design pattern visitor, ici la sauvegarde
     * @param[in] f Un cercle
     * @return \p (*this) L'objet implicite
     */
    FormeSauvegarder & visit(const Cercle & f) override;
    /**
     * @brief Permet l'introduction de méthode pour un triangle via le design pattern visitor, ici la sauvegarde
     * @param[in] f Un triangle
     * @return \p (*this) L'objet implicite
     */
    FormeSauvegarder & visit(const Triangle & f) override;
    /**
     * @brief Permet l'introduction de méthode pour un polygone via le design pattern visitor, ici la sauvegarde
     * @param[in] f Un polygone
     * @return \p (*this) L'objet implicite
     */
    FormeSauvegarder & visit(const Polygone & f) override;
    /**
     * @brief Permet l'introduction de méthode pour une forme composée via le design pattern visitor, ici la sauvegarde
     * @param[in] f Une forme composée
     * @return \p (*this) L'objet implicite
     */
    FormeSauvegarder & visit(const FormeComposee & f) override;
};

#endif //PPIL_DESSINER_H