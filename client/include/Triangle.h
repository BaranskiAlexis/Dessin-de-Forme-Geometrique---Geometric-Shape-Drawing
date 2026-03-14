#ifndef PPIL_TRIANGLE_H
#define PPIL_TRIANGLE_H
#include "FormeSimple.h"

/**
 * @brief Permet de gérer un triangle
 */
class Triangle : public FormeSimple {
    /**
    * @brief L'ensemble des points du triangle
    */
    Vecteur2D p[3];
public:
    /**
     * @brief Construit un triangle à partir d'une couleur, d'un sommet \p p1, d'un sommet \p p2 et d'un sommet \p p3
     * @param[in] p1 Un sommet
     * @param[in] p2 Un sommet
     * @param[in] p3 Un sommet
     * @param[in] couleur La couleur souhaitée (à défaut noir)
     * @return Un triangle
     * @details Aucun des sommets ne peut avoir les mêmes coordonnées
     */
    explicit Triangle(const Vecteur2D & p1, const Vecteur2D & p2, const Vecteur2D & p3, const Couleur & couleur = Couleur::BLACK);
    /**
     * @brief Construit un triangle à partir d'une couleur, de coordonnées \p x1 et \p y1 désignant un sommet, de coordonnées \p x2 et \p y2 désignant un autre sommet, et de coordonnées \p x3 et \p y3 désignant un troisième sommet
     * @param[in] x1 Coordonnée x du premier sommet (à defaut 0)
     * @param[in] y1 Coordonnée y du premier sommet (à defaut 0)
     * @param[in] x2 Coordonnée x du deuxième sommet (à defaut 1)
     * @param[in] y2 Coordonnée y du deuxième sommet (à defaut 1)
     * @param[in] x3 Coordonnée x du troisième sommet (à defaut 0)
     * @param[in] y3 Coordonnée y du troisième sommet (à defaut 1)
     * @param[in] couleur La couleur souhaitée (à défaut noir)
     * @return Un triangle
     * @details Aucun des sommets ne peut avoir les mêmes coordonnées
     */
    explicit Triangle(const double & x1 = 0, const double & y1 = 0, const double & x2 = 1, const double & y2 = 1, const double & x3 = 0, const double & y3 = 1, const Couleur & couleur = Couleur::BLACK);
    /**
     * @brief Retourne un clone du triangle
     * @return Un clone du triangle
     */
    Triangle * clone() const override;
    /**
     * @brief Permet la destruction du cercle
     */
    ~Triangle() override;
    /**
     * @brief Retourne le premier sommet
     * @return \p p1 Le premier sommet
     */
    Vecteur2D getp1() const;
    /**
     * @brief Retourne le deuxième sommet
     * @return \p p2 Le deuxième sommet
     */
    Vecteur2D getp2() const;
    /**
     * @brief Retourne le troisième sommet
     * @return \p p3 Le troisième sommet
     */
    Vecteur2D getp3() const;
    /**
     * @brief Change le premier sommet du triangle par un autre sommet \p p1
     * @param[in] p1 Le nouveau premier sommet du triangle
     * @return \p *this L'objet implicite
     * @details Aucun des sommets ne peut avoir les mêmes coordonnées
     */
    Triangle & setp1(const Vecteur2D & p1);
    /**
     * @brief Change le premier sommet du triangle par les coordonnées \p x1 et \p y1
     * @param[in] x1 Coordonnée x du nouveau premier sommet du triangle (à defaut 0)
     * @param[in] y1 Coordonnée y du nouveau premier sommet du triangle (à defaut 0)
     * @return \p *this L'objet implicite
     * @details Aucun des sommets ne peut avoir les mêmes coordonnées
     */
    Triangle & setp1(const double & x1 = 0, const double & y1 = 0);
    /**
     * @brief Change le deuxième sommet du triangle par un autre sommet \p p2
     * @param[in] p2 Le nouveau premier sommet du triangle
     * @return \p *this L'objet implicite
     * @details Aucun des sommets ne peut avoir les mêmes coordonnées
     */
    Triangle & setp2(const Vecteur2D & p2);
    /**
     * @brief Change le deuxième sommet du triangle par les coordonnées \p x2 et \p y2
     * @param[in] x2 Coordonnée x du nouveau deuxième sommet du triangle (à defaut 1)
     * @param[in] y2 Coordonnée y du nouveau deuxième sommet du triangle (à defaut 1)
     * @return \p *this L'objet implicite
     * @details Aucun des sommets ne peut avoir les mêmes coordonnées
     */
    Triangle & setp2(const double & x2 = 1, const double & y2 = 1);
    /**
     * @brief Change le troisème sommet du triangle par un autre sommet \p p3
     * @param[in] p3 Le nouveau deuxième sommet du triangle
     * @return \p *this L'objet implicite
     * @details Aucun des sommets ne peut avoir les mêmes coordonnées
     */
    Triangle & setp3(const Vecteur2D & p3);
    /**
     * @brief Change le troisième sommet du triangle par les coordonnées \p x3 et \p y3
     * @param[in] x3 Coordonnée x du nouveau troisième sommet du triangle (à defaut 0)
     * @param[in] y3 Coordonnée y du nouveau troisième sommet du triangle (à defaut 1)
     * @return \p *this L'objet implicite
     * @details Aucun des sommets ne peut avoir les mêmes coordonnées
     */
    Triangle & setp3(const double & x3 = 0, const double & y3 = 1);
    /**
    * @brief Permet d'obtenir l'ensemble des points du triangle
    * @return L'ensemble des points
    */
    vector<Vecteur2D> getPoints() const override;
    /**
     * @brief Permet de modifier l'ensemble des points du triangle
     * @param[in] v Un vecteur de points
     * @return \p (*this) L'objet implicite
     */
    Triangle & setPoints(const vector<Vecteur2D> & v) override;
    /**
     * @brief Retourne l'aire du triangle
     * @return L'aire du triangle
     */
    double getAire() const override;
    /**
    * @brief Permet d'obtenir une chaîne de caractère indiquant les spécificités du triangle
    * @return Une chaîne de caractère
    */
    string toString() const override;
    /**
     * @brief Permet l'introduction de méthode via le design pattern visitor
     * @param[in] visiteur Un objet répondant au pattern visitor
     * @return \p (*this) L'objet implicite
     */
    Triangle & accept(FormeVisiteur & visiteur) override;
};

#endif