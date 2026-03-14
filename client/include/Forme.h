#ifndef PPIL_FORME_H
#define PPIL_FORME_H
#include <string>
#include <vector>

#include "Matrice22.h"
#include "Vecteur2D.h"

using namespace std;

class FormeVisiteur;

/**
 * @brief Permet de caractériser les couleurs de nos formes
 */
enum class Couleur {BLACK, BLUE, RED, GREEN, YELLOW, CYAN};

/**
 * @brief Retourne la chaîne de caractères associée à la couleur
 * @param[in] couleur Une couleur
 * @return Une chaîne de caractères
 */
inline string couleurToString(const Couleur & couleur) {
    switch (couleur) {
        case Couleur::BLACK:
            return "Black";
        case Couleur::BLUE:
            return "Blue";
        case Couleur::RED:
            return "Red";
        case Couleur::GREEN:
            return "Green";
        case Couleur::YELLOW:
            return "Yellow";
        case Couleur::CYAN:
            return "Cyan";
    }
    return "";
}

/**
 * @brief Permet de gérer l'ensemble des exceptions liées aux formes
 */
class ExceptionForme : public exception {
    /**
     * @brief Le message lié à l'exception
     */
    string message = "ExceptionForme -";
public:
    /**
     * @brief Permet d'obtenir une chaîne de caractère lié à l'erreur
     * @return Une chaîne de caractère
     */
    const char * what() const noexcept override {
        return getMessage().c_str();
    }
    /**
    * @brief Permet d'obtenir une chaîne de caractère lié à l'erreur
    * @return Une chaîne de caractère
    */
    virtual string getMessage() const {
        return message;
    }
    /**
    * @brief Permet l'utilisation du << pour une erreur
    * @return L'ostream complété
*   */
    friend ostream & operator<<(ostream & s, const ExceptionForme & e) {
        return s << e.getMessage();
    }
};

/**
 * @brief Permet de gérer l'erreur lors de la non-reconnaissance d'une couleur
 */
class ExceptionCouleurInconnue : public ExceptionForme {
    /**
     * @brief Le message lié à l'exception
     */
    string message = " La couleur est inconnue";
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
 * @brief Retourne la couleur associée à la chaîne de caractères
 * @param[in] s Une chaîne de caractères
 * @return Une couleur
 * @details Si la chaîne est invalide, alors une erreur est lancée
 */
inline Couleur stringToCouleur(const string & s) {
    if (s == "Black") {
        return Couleur::BLACK;
    }
    if (s == "Blue") {
        return Couleur::BLUE;
    }
    if (s == "Red") {
        return Couleur::RED;
    }
    if (s == "Green") {
        return Couleur::GREEN;
    }
    if (s == "Yellow") {
        return Couleur::YELLOW;
    }
    if (s == "Cyan") {
        return Couleur::CYAN;
    }
    throw ExceptionForme();
}

/**
 * @brief Permet de gérer l'erreur de l'utilisation d'un k nulle pour la rotation
 */
class ExceptionKIsNull : public ExceptionForme {
    /**
     * @brief Le message lié à l'exception
     */
    string message = " Le rapport d'homothetie k = 0 est interdit";
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
 * @brief Permet de créer une forme
 */
class Forme {
    /**
    * @brief La couleur de la forme
    */
    Couleur couleur;
protected:
    /**
     * @brief Verifie si la constante k pour l'homothétie n'est pas nulle
     * @param[in] k La constante
     * @return void
     */
    static void verificationKIsNotNull(const double & k);
public:
    /**
     * @brief Construit une forme à partir d'une couleur
     * @param[in] couleur La couleur souhaitée (à défaut noir)
     * @return Une forme
     */
    explicit Forme(const Couleur & couleur = Couleur::BLACK);
    /**
     * @brief Retourne un clone de la forme
     * @return Un clone de la forme
     */
    virtual Forme * clone() const = 0;
    /**
     * @brief Permet la destruction de la forme
     */
    virtual ~Forme();
    /**
     * @brief Retourne la couleur de la forme courante
     * @return \p couleur La couleur
     */
    Couleur getCouleur() const;
    /**
     * @brief Permet de changer la couleur de la forme
     * @param[in] couleur La couleur
     * @return \p (*this) L'objet implicite
     */
    Forme & setCouleur(const Couleur & couleur);
    /**
     * @brief Permet d'obtenir l'ensemble des points de la forme
     * @return L'ensemble des points
     */
    virtual vector<Vecteur2D> getPoints() const = 0;
    /**
     * @brief Permet d'obtenir l'aire d'une forme
     * @return L'aire de la forme
     */
    virtual double getAire() const = 0;
    /**
     * @brief Permet de réaliser une translation de la forme
     * @return \p (*this) L'objet implicite
     */
    virtual Forme & translation(const Vecteur2D & p) = 0;
    /**
     * @brief Permet de réaliser une homothétie de la forme
     * @return \p (*this) L'objet implicite
     */
    virtual Forme & homothetie(const Vecteur2D & p, const double & k) = 0;
    /**
     * @brief Permet de réaliser une rotation de la forme
     * @return \p (*this) L'objet implicite
     */
    virtual Forme & rotation(const Vecteur2D & p, const double & r) = 0;
    /**
     * @brief Permet de réaliser une transformation de la forme pour un affichage sur écran
     * @param[in] m Une matrice
     * @param[in] ab Un vecteur
     * @return \p (*this) L'objet implicite
     */
    virtual Forme & transformationEcran(const Matrice22 & m, const Vecteur2D & ab) = 0;
    /**
    * @brief Permet de charger une forme à partir d'un fichier local
    * @param[in] path L'adresse du fichier souhaité
    * @return L'objet du fichier
    */
    static Forme * charger(const string & path);
    /**
    * @brief Permet d'obtenir une chaîne de caractère indiquant les spécificités de la forme
    * @return Une chaîne de caractère
    */
    virtual string toString() const;
    /**
    * @brief Permet d'obtenir une chaîne de caractère indiquant les spécificités de la forme
    * @return Une chaîne de caractère
    */
    explicit operator string() const;
    /**
    * @brief Permet l'utilisation du << pour une forme lors de l'utilisation d'ostream
    * @return L'ostream complété
*   */
    friend ostream & operator<<(ostream & s, const Forme & f);
    /**
     * @brief Permet l'introduction de méthode via le design pattern visitor
     * @param[in] visiteur Un objet répondant au pattern visitor
     * @return \p (*this) L'objet implicite
     */
    virtual Forme & accept(FormeVisiteur & visiteur) = 0;
};

#endif