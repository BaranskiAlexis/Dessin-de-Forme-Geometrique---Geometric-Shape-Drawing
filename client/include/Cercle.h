#ifndef PPIL_CERCLE_H
#define PPIL_CERCLE_H
#include "FormeSimple.h"

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

/**
 * @brief Permet de gérer l'ensemble des exceptions liées aux cercles
 */
class ExceptionCercle : public ExceptionFormeSimple {
    /**
     * @brief Le message lié à l'exception
     */
    string message = " ExceptionCercle -";
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
 * @brief Permet de gérer l'exception lorsque le rayon est negatif
 */
class ExceptionRayonNegatif : public ExceptionCercle {
    /**
     * @brief Le message lié à l'exception
     */
    string message = " Le rayon doit etre superieur a 0";
public:
    /**
    * @brief Permet d'obtenir une chaîne de caractère lié à l'erreur
    * @return Une chaîne de caractère
    */
    string getMessage() const override {
        return ExceptionCercle::getMessage() + message;
    }
};

/**
 * @brief Permet de gérer un cercle
 */
class Cercle : public FormeSimple {
    /**
    * @brief Le centre du cercle
    */
    Vecteur2D c;
    /**
    * @brief Le rayon du cercle
    */
    double r;
    /**
    * @brief Verifie si le rayon est bien supérieur à 0
    * @return void
    */
    static void verificationRayon(const double & r);
public:
    /**
     * @brief Construit un cercle à partir d'une couleur, d'un centre \p c et d'un rayon \p r
     * @param[in] c Le centre du cercle
     * @param[in] r Le rayon du cercle
     * @param[in] couleur La couleur souhaitée (à défaut noir)
     * @return Un cercle
    * @return \p r Le rayon du cercle
     */
    explicit Cercle(const Vecteur2D & c, const double & r = 1, const Couleur & couleur = Couleur::BLACK);
    /**
     * @brief Construit un cercle à partir d'une couleur, de coordonnées \p xc et \p yc désignant le centre et \p r le rayon
     * @param[in] xc Coordonnée x du centre du cercle (à defaut 0)
     * @param[in] yc Coordonnée y du centre du cercle (à defaut 0)
     * @param[in] r Le rayon du cercle (à defaut 1)
     * @param[in] couleur La couleur souhaitée (à défaut noir)
     * @return Un cercle
     * @details \p r doit être supérieur à 0
     */
    explicit Cercle(const double & xc = 0, const double & yc = 0, const double & r = 1, const Couleur & couleur = Couleur::BLACK);
    /**
     * @brief Retourne un clone du cercle
     * @return Un clone du cercle
     */
    Cercle * clone() const override;
    /**
     * @brief Permet la destruction du cercle
     */
    ~Cercle() override;
    /**
     * @brief Retourne le centre du cercle
     * @return \p c Le centre du cercle
     */
    Vecteur2D getc() const;
    /**
     * @brief Retourne le rayon du cercle
     * @return \p r Le rayon du cercle
     */
    double getr() const;
    /**
     * @brief Change le centre du cercle par un autre centre \p c
     * @param[in] c Le nouveau centre du cercle
     * @return \p *this L'objet implicite
     * @details \p r doit être supérieur à 0
     */
    Cercle & setc(const Vecteur2D & c);
    /**
     * @brief Change le centre du cercle par les coordonnées \p xc et \p yc
     * @param[in] xc Coordonnée x du nouveau centre du cercle (à defaut 0)
     * @param[in] yc Coordonnée y du nouveau centre du cercle (à defaut 0)
     * @return \p *this L'objet implicite
     * @details \p xc et \p xr ne peuvent pas être égaux en même temps que \p yc et \p yr
     */
    Cercle & setc(const double & xc = 0, const double & yc = 0);
    /**
     * @brief Change le rayon du cercle par un autre rayon \p r
     * @param[in] r Le nouveau rayon du cercle
     * @return \p *this L'objet implicite
     * @details \p r doit être supérieur à 0
     */
    Cercle & setr(const double & r);
    /**
     * @brief Permet d'obtenir l'ensemble des points du cercle
     * @return L'ensemble des points
     */
    vector<Vecteur2D> getPoints() const override;
    /**
     * @brief Permet de modifier l'ensemble des points du cercle
     * @param[in] v Un vecteur de points
     * @return \p (*this) L'objet implicite
     */
    Cercle & setPoints(const vector<Vecteur2D> & v) override;
    /**
     * @brief Retourne l'aire du cercle
     * @return L'aire du cercle
     */
    double getAire() const override;
    /**
    * @brief Permet d'obtenir une chaîne de caractère indiquant les spécificités du cercle
    * @return Une chaîne de caractère
    */
    string toString() const override;
    /**
     * @brief Permet l'introduction de méthode via le design pattern visitor
     * @param[in] visiteur Un objet répondant au pattern visitor
     * @return \p (*this) L'objet implicite
     */
    Cercle & accept(FormeVisiteur & visiteur) override;
};

#endif