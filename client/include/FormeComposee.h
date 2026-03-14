#ifndef PPIL_FORMECOMPOSEE_H
#define PPIL_FORMECOMPOSEE_H
#include "Forme.h"

/**
 * @brief Permet de gérer l'ensemble des exceptions liées aux formes composées
 */
class ExceptionFormeComposee : public ExceptionForme {
    /**
     * @brief Le message lié à l'exception
     */
    string message = " ExceptionFormeComposee -";
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
 * @brief Permet de gérer l'exception en cas de dépassement de case d'un tableau
 */
class ExceptionArrayOutOfBoundFC : public ExceptionFormeComposee {
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
        return ExceptionFormeComposee::getMessage() + message;
    }
};

/**
 * @brief Permet de gérer une forme composée
 */
class FormeComposee : public Forme {
    /**
     * @brief L'ensemble des formes
     */
    vector<Forme *> v;
    /**
     * @brief Permet de copier une forme f pour l'objet implicite
     * @param[in] f Une forme composée
     * @return void
     */
    void copy(const FormeComposee & f);
    /**
     * @brief Permet la destruction des champs de l'objet implicite
     * @return void
     */
    void destroy();
    /**
     * @brief Verifie si un entier \p i permet l'accès à un élément d'un vecteur \p v
     * @param[in] v Un vector
     * @param[in] i Un entier
     * @return void
     */
    static void verificationAccesVector(const vector<Forme *> & v, int i);
    /**
     * @brief Verifie si un entier \p i permet l'accès à un élément d'un vecteur \p v lors de l'ajout d'une forme
     * @param[in] v Un vector
     * @param[in] i Un entier
     * @return void
     */
    static void verificationAccesVectorAddForme(const vector<Forme *> & v, int i);
public:
    /**
     * @brief Construit une forme composée à partir d'une couleur
     * @param[in] couleur La couleur souhaitée
     * @return Une forme composée
     */
    explicit FormeComposee(const Couleur & couleur);
    /**
     * @brief Construit une forme composée à partir d'une couleur et d'un vecteur de forme
     * @param[in] v Le vecteur de formes
     * @param[in] couleur La couleur souhaitée (à défaut noir)
     * @return Une forme composée
     * @details Chaque forme ne doit pas avoir de parent, et chaque forme ne doit pas être un antécédent de la forme composée.
     */
    explicit FormeComposee(const vector<Forme *> & v = vector<Forme *>(), const Couleur & couleur = Couleur::BLACK);
    /**
     * @brief Construit une forme composée à partir d'une autre forme composée
     * @param[in] f Une forme composée
     * @return Une forme composée
     */
    FormeComposee(const FormeComposee & f);
    /**
    * @brief Permet la copie des champs de \p f dans l'objet implicite
    * @param[in] f Une forme composée
    * @return (*this) l'objet implicite
    */
    FormeComposee & operator=(const FormeComposee & f);
    /**
     * @brief Permet la destruction de la forme composée
     */
    ~FormeComposee() override;
    /**
     * @brief Retourne un clone de la forme composée
     * @return Un clone de la forme composée
     */
    FormeComposee * clone() const override;
    /*
     * @brief Permet d'obtenir l'ensemble des points de la forme composée
     * @return L'ensemble des points
     */
    vector<Vecteur2D> getPoints() const override;
    /**
     * @brief Retourne l'ensemble des formes de la forme composée
     * @return L'ensemble des formes
     */
    vector<Forme *> getFormes() const;
    /**
     * @brief Attribue un ensemble de forme à la forme composée
     * @param[in] vf Un vecteur de forme
     * @return \p (*this) l'objet implicite
     * @details Chaque forme ne doit pas avoir de parent, et chaque forme ne doit pas être un antécédent de la forme composée.
     */
    FormeComposee & setFormes(const vector<Forme *> & vf);
    /**
     * @brief Retourne une forme à l'indice \p i parmi les formes de la forme composée
     * @param[in] i Un indice
     * @return Un pointeur de forme
     * @details La position doit respecter la taille du vecteur
     */
    Forme * getFormeAt(int i) const;
    /**
     * @brief Permet d'ajouter une forme à la forme composée
     * @param[in] f La forme
     * @return \p (*this) L'objet implicite
     * @details La forme ne doit pas avoir de parent, et la forme ne doit pas être un antécédent de la forme composée.
     */
    FormeComposee & addForme(const Forme & f);
    /**
     * @brief Permet d'ajouter une forme à la forme composée à la position i
     * @param[in] f La forme
     * @param[in] i L'indice
     * @return \p (*this) L'objet implicite
     * @details La forme ne doit pas avoir de parent, et la forme ne doit pas être un antécédent de la forme composée.
     * @details La position doit respecter la taille du vecteur
     */
    FormeComposee & addFormeAt(const Forme & f, int i);
    /**
     * @brief Permet de retirer une forme à la position i du vecteur de la forme composée
     * @param[in] i La position
     * @return \p (*this) L'objet implicite
     * @details La position doit respecter la taille du vecteur
     */
    FormeComposee & removeFormeAt(int i);
    /**
     * @brief Retourne l'aire de la forme composée
     * @return L'aire de la forme composée
     */
    double getAire() const override;
    /**
     * @brief Permet de réaliser une translation de la forme composée
     * @return \p (*this) L'objet implicite
     */
    FormeComposee & translation(const Vecteur2D & p) override;
    /**
     * @brief Permet de réaliser une homothétie de la forme composée
     * @return \p (*this) L'objet implicite
     */
    FormeComposee & homothetie(const Vecteur2D & p, const double & k) override;
    /**
     * @brief Permet de réaliser une rotation de la forme composée
     * @return \p (*this) L'objet implicite
     */
    FormeComposee & rotation(const Vecteur2D & p, const double & r) override;
    /**
     * @brief Permet de réaliser une transformation de la forme simple pour un affichage sur écran
     * @param[in] m Une matrice
     * @param[in] ab Un vecteur
     * @return \p (*this) L'objet implicite
     */
    FormeComposee & transformationEcran(const Matrice22 & m, const Vecteur2D & ab) override;
    /**
    * @brief Permet d'obtenir une chaîne de caractère indiquant les spécificités de la forme composée
    * @return Une chaîne de caractère
    */
    string toString() const override;
    /**
     * @brief Permet d'ajouter une forme à la forme composée
     * @param[in] f La forme
     * @return \p (*this) L'objet implicite
     * @details La forme ne doit pas avoir de parent, et la forme ne doit pas être un antécédent de la forme composée.
     */
    FormeComposee & operator+(const Forme & f);
    /**
     * @brief Retourne l'aire de la forme composée
     * @return L'aire de la forme composée
     */
    FormeComposee & operator-(int i);
    /**
     * @brief Retourne une forme à l'indice \p i parmi les formes de la forme composée
     * @param[in] i Un indice
     * @return Un pointeur de forme
     * @details La position doit respecter la taille du vecteur
     */
    Forme * operator[](int i) const;
    /**
     * @brief Permet l'introduction de méthode via le design pattern visitor
     * @param[in] visiteur Un objet répondant au pattern visitor
     * @return \p (*this) L'objet implicite
     */
    FormeComposee & accept(FormeVisiteur & visiteur) override;
};

#endif