#ifndef PPIL_POLYGONE_H
#define PPIL_POLYGONE_H
#include "FormeSimple.h"

/**
 * @brief Permet de gérer du polygone
 */
class Polygone : public FormeSimple {
    /**
    * @brief L'ensemble des points du polygone
    */
    vector<Vecteur2D> v;
    /**
     * @brief Verifie dans un vector l'existence ou non de deux vecteurs identiques
     * @param[in] v Un vector de Vecteur2D
     * @return void
     */
    void static verificationParametreVector(const vector<Vecteur2D> & v);
    /**
     * @brief Verifie dans un vector de Vecteur2D l'existence ou non d'un vecteur \p p
     * @param[in] v Un vector de Vecteur2D
     * @param[in] p Un vecteur2D
     * @return void
     */
    void static verificationVectorEtVecteur2D(const vector<Vecteur2D> & v, const Vecteur2D & p);
public:
    /**
     * @brief Construit un Polygone à partir d'une couleur
     * @param[in] couleur La couleur souhaitée
     * @return Un polygone
     */
    explicit Polygone(const Couleur & couleur);
    /**
     * @brief Construit un Polygone à partir d'une couleur et d'un vecteur de points
     * @param[in] v Le vecteur de points
     * @param[in] couleur La couleur souhaitée (à défaut noir)
     * @return Un polygone
     * @details Un point ne peut pas apparaître deux fois
     */
    explicit Polygone(const vector<Vecteur2D> & v = {}, const Couleur & couleur = Couleur::BLACK);
    /**
     * @brief Retourne un clone du polygone
     * @return Un clone du polygone
     */
    Polygone * clone() const override;
    /**
     * @brief Permet la destruction du polygone
     */
    ~Polygone() override;
    /**
     * @brief Permet d'obtenir l'ensemble des points du polygone
     * @return L'ensemble des points
     */
    vector<Vecteur2D> getPoints() const override;
    /**
     * @brief Permet de modifier l'ensemble des points du polygone
     * @param[in] v Un vecteur de points
     * @return \p (*this) L'objet implicite
     * @details Un point ne peut pas apparaître deux fois
     */
    Polygone & setPoints(const vector<Vecteur2D> & v) override;
    /**
     * @brief Permet d'obtenir un point en fonction de sa position dans le vecteur du polygone
     * @param[in] i Une position
     * @return Le point à la position \p i
     */
    Vecteur2D getPointAt(int i) const;
    /**
     * @brief Permet d'ajouter un point à la fin du vecteur du polygone
     * @param[in] p Le point
     * @return \p (*this) L'objet implicite
     * @details Un point ne peut pas apparaître deux fois
     */
    Polygone & addPoint(const Vecteur2D & p);
    /**
     * @brief Permet d'ajouter un point à la position i du vecteur du polygone
     * @param[in] p Le point
     * @param[in] i La position
     * @return \p (*this) L'objet implicite
     * @details La position doit respecter la taille du vecteur
     * @details Un point ne peut pas apparaître deux fois
     */
    Polygone & addPointAt(const Vecteur2D & p, int i);
    /**
     * @brief Permet de retirer un point du polygone
     * @param[in] p Le point
     * @return \p (*this) L'objet implicite
     */
    Polygone & removePoint(const Vecteur2D & p);
    /**
     * @brief Permet de retirer un point à la position i du vecteur du polygone
     * @param[in] i La position
     * @return \p (*this) L'objet implicite
     * @details La position doit respecter la taille du vecteur
     */
    Polygone & removePointAt(int i);
    /**
     * @brief Permet de modifier un point du polygone
     * @param[in] p Le point à modifier
     * @param[in] q Le nouveau point
     * @return \p (*this) L'objet implicite
     * @details Un point ne peut pas apparaître deux fois
     */
    Polygone & modifyPoint(const Vecteur2D & p, const Vecteur2D & q);
    /**
     * @brief Permet de modifier un point à la position i du vecteur du polygone
     * @param[in] i La position
     * @param[in] q Le nouveau point
     * @return \p (*this) L'objet implicite
     * @details Un point ne peut pas apparaître deux fois
     */
    Polygone & modifyPointAt(int i, const Vecteur2D & q);
    /**
     * @brief Permet d'inverser la position de deux points
     * @param[in] p Un point du polygone
     * @param[in] q Un point du polygone
     * @return \p (*this) L'objet implicite
     */
    Polygone & switchPoint(const Vecteur2D & p, const Vecteur2D & q);
    /**
     * @brief Permet d'inverser la position de deux points en fonction de leurs indices
     * @param[in] i La position d'un point
     * @param[in] j La position d'un point
     * @return \p (*this) L'objet implicite
     * @details La position doit respecter la taille du vecteur
     */
    Polygone & switchPointAt(int i, int j);
    /**
     * @brief Retourne l'aire du polygone
     * @return L'aire du polygone
     */
    double getAire() const override;
    /**
    * @brief Permet d'obtenir une chaîne de caractère indiquant les spécificités du polygone
    * @return Une chaîne de caractère
    */
    string toString() const override;
    /**
     * @brief Permet d'ajouter un point au vecteur du polygone
     * @param[in] p Le point
     * @return \p (*this) L'objet implicite
     * @details Un point ne peut pas apparaître deux fois
     */
    Polygone & operator+(const Vecteur2D & p);
    /**
     * @brief Permet de retirer un point au vecteur du polygone
     * @param[in] p Le point
     * @return \p (*this) L'objet implicite
     */
    Polygone & operator-(const Vecteur2D & p);
    /**
     * @brief Permet d'obtenir un point en fonction de sa position dans le vecteur
     * @param[in] i Une position
     * @return Le point à la position \p i
     */
    Vecteur2D operator[](int i) const;
    /**
     * @brief Permet l'introduction de méthode via le design pattern visitor
     * @param[in] visiteur Un objet répondant au pattern visitor
     * @return \p (*this) L'objet implicite
     */
    Polygone & accept(FormeVisiteur & visiteur) override;
};

#endif