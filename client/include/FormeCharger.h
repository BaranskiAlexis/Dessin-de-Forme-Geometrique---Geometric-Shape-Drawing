#ifndef PPIL_FORMECHAINOFRESPONSABILITY_H
#define PPIL_FORMECHAINOFRESPONSABILITY_H
#include "Forme.h"

/**
 * @brief Permet de gérer l'ensemble des exceptions liées au chargement d'une forme
 */
class ExceptionFormeCharger : public ExceptionForme {
    /**
     * @brief Le message lié à l'exception
     */
    string message = " ExceptionFormeCharge -";
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
 * @brief Permet de gérer l'exception liée à l'impossible de lire un fichier
 */
class ExceptionFileCantBeRead : public ExceptionFormeCharger {
    /**
     * @brief Le message lié à l'exception
     */
    string message = " Le fichier ne peut pas être ouvert";
public:
    /**
    * @brief Permet d'obtenir une chaîne de caractère lié à l'erreur
    * @return Une chaîne de caractère
    */
    string getMessage() const override {
        return ExceptionFormeCharger::getMessage() + message;
    }
};

/**
 * @brief Permet de gérer l'exception liée à un fichier vide
 */
class ExceptionFileIsEmpty : public ExceptionFormeCharger {
    /**
     * @brief Le message lié à l'exception
     */
    string message = " Le fichier est vide";
public:
    /**
    * @brief Permet d'obtenir une chaîne de caractère lié à l'erreur
    * @return Une chaîne de caractère
    */
    string getMessage() const override {
        return ExceptionFormeCharger::getMessage() + message;
    }
};

/**
 * @brief Permet de gérer l'exception dans le cas d'une forme non reconnue
 */
class ExceptionStringIsNotRecognizable : public ExceptionFormeCharger {
    /**
     * @brief Le message lié à l'exception
     */
    string message = " Aucune forme ne peut être déduit d'une des chaînes de caractères du fichier";
public:
    /**
    * @brief Permet d'obtenir une chaîne de caractère lié à l'erreur
    * @return Une chaîne de caractère
    */
    string getMessage() const override {
        return ExceptionFormeCharger::getMessage() + message;
    }
};

/**
 * @brief Permet de gérer le chargement d'une forme
 */
class FormeCharger {
    /**
     * @brief L'origine de la chaîne
     */
    static FormeCharger * origine;
    /**
     * @brief Le prochain maillon de la chaîne
     */
    FormeCharger * suivant;
    /**
    * @brief Permet la mise en place de la fonction chargerDepuisFlux
    * @param[in] flux Le flux de string
    * @return L'objet du flux
    */
    Forme * chargerDepuisFluxStart(istringstream & flux) const;
protected:
    /**
    * @brief Permet de charger une forme
    * @param[in] s Le string étant la première ligne du flux en cours
    * @param[in] flux Le flux de string
    * @return L'objet du flux
    */
    virtual Forme * charger(const string & s, istringstream & flux) const = 0;
public:
    /**
    * @brief Permet la construction d'un maillon du design pattern chain of responsability permettant le chargement d'une forme
    * @param[in] suivant Le prochain maillon
    */
    explicit FormeCharger(FormeCharger * suivant);
    /**
    * @brief Permet la destruction de l'objet
    */
    virtual ~FormeCharger();
    /**
    * @brief Permet d'obtenir le maillon originel de la chaîne
    * @return \p origine Le maillon originel
    */
    static FormeCharger * getOrigine();
    /**
    * @brief Permet de charger une forme à partir d'un fichier local
    * @param[in] path L'adresse du fichier souhaité
    * @return L'objet du fichier
    */
    Forme * chargerDepuisFichier(const string & path) const;
    /**
    * @brief Permet de charger une forme à partir d'un flux et d'un string
    * @param[in] s Le string étant la première ligne du flux en cours
    * @param[in] flux Le flux de string
    * @return L'objet du flux
    */
    Forme * chargerDepuisFlux(const string & s, istringstream & flux) const;
};

#endif