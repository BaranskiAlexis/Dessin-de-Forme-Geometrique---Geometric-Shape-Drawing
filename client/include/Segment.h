#ifndef PPIL_SEGMENT_H
#define PPIL_SEGMENT_H
#include "FormeSimple.h"

/**
 * @brief Permet de créer un segment
 */
class Segment : public FormeSimple {
    /**
    * @brief L'ensemble des points du Segment
    */
    Vecteur2D p[2];
public:
    /**
     * @brief Construit un segment à partir d'une couleur, d'un sommet \p p1 et d'un sommet \p p2
     * @param[in] p1 Un sommet
     * @param[in] p2 Un sommet
     * @param[in] couleur La couleur souhaitée (à défaut noir)
     * @return Un segment
     * @details \p p1 et \p p2 ne peuvent pas être égaux
     */
    explicit Segment(const Vecteur2D & p1, const Vecteur2D & p2, const Couleur & couleur = Couleur::BLACK);
    /**
     * @brief Construit un segment à partir d'une couleur, de coordonnées \p x1 et \p y1 désignant un sommet et de coordonnées \p x2 et \p y2 désignant un autre sommet
     * @param[in] x1 Coordonnée x du premier sommet (à defaut 0)
     * @param[in] y1 Coordonnée y du premier sommet (à defaut 0)
     * @param[in] x2 Coordonnée x du deuxième sommet (à defaut 1)
     * @param[in] y2 Coordonnée y du deuxième sommet (à defaut 1)
     * @param[in] couleur La couleur souhaitée (à défaut noir)
     * @return Un segment
     * @details \p x1 et \p x2 ne peuvent pas être égaux en même temps que \p y1 et \p y2
     */
    explicit Segment(const double & x1 = 0, const double & y1 = 0, const double & x2 = 1, const double & y2 = 1, const Couleur & couleur = Couleur::BLACK);
    /**
     * @brief Retourne un clone du segment
     * @return Un clone du segment
     */
    Segment * clone() const override;
    /**
     * @brief Permet la destruction du segment
     */
    ~Segment() override;
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
     * @brief Change le premier sommet du segment par un autre sommet \p p1
     * @param[in] p1 Le nouveau premier sommet du segment
     * @return \p *this L'objet implicite
     * @details \p p1 et \p p2 ne peuvent pas être égaux
     */
    Segment & setp1(const Vecteur2D & p1);
    /**
     * @brief Change le premier sommet du segment par les coordonnées \p x1 et \p y1
     * @return \p *this L'objet implicite
     * @param[in] x1 Coordonnée x du nouveau premier sommet du segment (à defaut 0)
     * @param[in] y1 Coordonnée y du nouveau premier sommet du segment (à defaut 0)
     * @details \p x1 et \p x2 ne peuvent pas être égaux en même temps que \p y1 et \p y2
     */
    Segment & setp1(const double & x1 = 0, const double & y1 = 0);
    /**
     * @brief Change le deuxième sommet du segment par un autre sommet \p p2
     * @param[in] p2 Le nouveau deuxième sommet du segment
     * @return \p *this L'objet implicite
     * @details \p p1 et \p p2 ne peuvent pas être égaux
     */
    Segment & setp2(const Vecteur2D & p2);
    /**
     * @brief Change le deuxième sommet du segment par les coordonnées \p x2 et \p y2
     * @param[in] x2 Coordonnée x du nouveau premier sommet du segment (à defaut 1)
     * @param[in] y2 Coordonnée y du nouveau premier sommet du segment (à defaut 1)
     * @return \p *this L'objet implicite
     * @details \p x2 et \p x2 ne peuvent pas être égaux en même temps que \p y2 et \p y2
     */
    Segment & setp2(const double & x2 = 1, const double & y2 = 1);
    /*
     * @brief Permet d'obtenir l'ensemble des points du segment
     * @return L'ensemble des points
     */
    vector<Vecteur2D> getPoints() const override;
    /**
     * @brief Permet de modifier l'ensemble des points du segment
     * @param[in] v Un vecteur de points
     * @return \p (*this) L'objet implicite
     */
    Segment & setPoints(const vector<Vecteur2D> & v) override;
    /**
     * @brief Retourne l'aire du segment
     * @return L'aire du segment
     */
    double getAire() const override;
    /**
    * @brief Permet d'obtenir une chaîne de caractère indiquant les spécificités du segment
    * @return Une chaîne de caractère
    */
    string toString() const override;
    /**
     * @brief Permet l'introduction de méthode via le design pattern visitor
     * @param[in] visiteur Un objet répondant au pattern visitor
     * @return \p (*this) L'objet implicite
     */
    Segment & accept(FormeVisiteur & visiteur) override;
};

#endif