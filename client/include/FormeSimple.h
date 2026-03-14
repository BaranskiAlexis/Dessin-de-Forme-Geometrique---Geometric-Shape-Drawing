#ifndef PPIL_FORMESIMPLE_H
#define PPIL_FORMESIMPLE_H
#include "Forme.h"

/**
 * @brief Permet de gérer l'ensemble des exceptions liées aux formes simples
 */
class ExceptionFormeSimple : public ExceptionForme {
    /**
     * @brief Le message lié à l'exception
     */
    string message = " ExceptionFormeSimple -";
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
 * @brief Permet de gérer l'exception lorsque deux points sont identiques dans une forme simple
 */
class ExceptionPointEqualsAnotherPoint : public ExceptionFormeSimple {
    /**
     * @brief Le message lié à l'exception
     */
    string message = " Deux des points sont de memes coordonnees";
public:
    /**
    * @brief Permet d'obtenir une chaîne de caractère lié à l'erreur
    * @return Une chaîne de caractère
    */
    string getMessage() const override {
        return ExceptionFormeSimple::getMessage() + message;
    }
};

/**
 * @brief Permet de gérer l'exception lorsqu'on essaye d'appliquer un ensemble de points pour une forme tandis que cet ensemble n'est pas de bonne taille
 */
class ExceptionArrayIsTooShort : public ExceptionFormeSimple {
    /**
     * @brief Le message lié à l'exception
     */
    string message = " Le tableau ne possede pas suffisamment de points pour couvrir la forme";
public:
    /**
    * @brief Permet d'obtenir une chaîne de caractère lié à l'erreur
    * @return Une chaîne de caractère
    */
    string getMessage() const override {
        return ExceptionFormeSimple::getMessage() + message;
    }
};

/**
 * @brief Permet de gérer l'exception en cas de dépassement de case d'un tableau
 */
class ExceptionArrayOutOfBound : public ExceptionFormeSimple {
    /**
     * @brief Le message lié à l'exception
     */
    string message = " La case du tableau n'existe pas";
public:
    /**
    * @brief Permet d'obtenir une chaîne de caractère lié à l'erreur
    * @return Une chaîne de caractère
    */
    string getMessage() const override {
        return ExceptionFormeSimple::getMessage() + message;
    }
};

/**
 * @brief Permet de gérer une forme simple
 */
class FormeSimple : public Forme {
protected:
    /**
     * @brief Verifie si un vecteur \p a n'est pas égal à un vecteur \p b
     * @param[in] a Un vecteur
     * @param[in] b Un vecteur
     * @return void
     */
    static void verificationNonEgaliteVecteur2D(const Vecteur2D & a, const Vecteur2D & b);
    /**
     * @brief Verifie si un entier \p i correspond à la taille d'un vector \p v
     * @param[in] v Un vector
     * @param[in] i Un entier
     * @return void
     */
    static void verificationTailleVector(const vector<Vecteur2D> & v, int i);
    /**
     * @brief Verifie si un entier \p i permet l'accès à un élément d'un vecteur \p v
     * @param[in] v Un vector
     * @param[in] i Un entier
     * @return void
     */
    static void verificationAccesVector(const vector<Vecteur2D> & v, int i);
    /**
     * @brief Verifie si un entier \p i permet l'accès à un élément d'un vecteur \p v lors de l'ajout d'un point
     * @param[in] v Un vector
     * @param[in] i Un entier
     * @return void
     */
    static void verificationAccesVectorAddPoint(const vector<Vecteur2D> & v, int i);
public:
    /**
     * @brief Construit une forme simple à partir d'une couleur
     * @param[in] couleur La couleur souhaitée (à défaut noir)
     * @return Une forme simple
     */
    explicit FormeSimple(const Couleur & couleur = Couleur::BLACK);
    /**
     * @brief Retourne un clone de la forme simple
     * @return Un clone de la forme simple
     */
    FormeSimple * clone() const override = 0;
    /**
     * @brief Permet la destruction de la forme simple
     */
    ~FormeSimple() override;
    /**
     * @brief Permet de modifier l'ensemble des points de la forme simple
     * @return \p (*this) L'objet implicite
     */
    virtual FormeSimple & setPoints(const vector<Vecteur2D> & v) = 0;
    /**
     * @brief Permet d'obtenir l'aire d'une forme simple
     * @return L'aire de la forme simple
     */
    double getAire() const override = 0;
    /**
     * @brief Permet de réaliser une translation de la forme simple
     * @return \p (*this) L'objet implicite
     */
    FormeSimple & translation(const Vecteur2D & p) override;
    /**
     * @brief Permet de réaliser une homothétie de la forme simple
     * @return \p (*this) L'objet implicite
     */
    FormeSimple & homothetie(const Vecteur2D & p, const double & k) override;
    /**
     * @brief Permet de réaliser une rotation de la forme simple
     * @return \p (*this) L'objet implicite
     */
    FormeSimple & rotation(const Vecteur2D & p, const double & r) override;
    /**
     * @brief Permet de réaliser une transformation de la forme simple pour un affichage sur écran
     * @param[in] m Une matrice
     * @param[in] ab Un vecteur
     * @return \p (*this) L'objet implicite
     */
    FormeSimple & transformationEcran(const Matrice22 & m, const Vecteur2D & ab) override;
    /**
     * @brief Permet l'introduction de méthode via le design pattern visitor
     * @param[in] visiteur Un objet répondant au pattern visitor
     * @return \p (*this) L'objet implicite
     */
    FormeSimple & accept(FormeVisiteur & visiteur) override = 0;
};

#endif