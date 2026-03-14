#ifndef PPIL_MATRICE22_H
#define PPIL_MATRICE22_H
#include "Vecteur2D.h"

/**
 * @brief Permet de gérer des matrices de taille 2 * 2
 */
class Matrice22 {
public:
	/**
	 * @brief Les deux vecteurs représentatifs de la matrice
	 */
	Vecteur2D ligneHaut, ligneBas;
	/**
	 * @brief Construit une matrice à partir d'un vecteur \p ligneHaut et d'un vecteur \p ligneBas
	 * @param[in] ligneHaut Un vecteur 2D
	 * @param[in] ligneBas Un vecteur 2D
	 * @return Une matrice22
	 */
	Matrice22(const Vecteur2D & ligneHaut, const Vecteur2D & ligneBas) : ligneHaut(ligneHaut), ligneBas(ligneBas) {}
	/**
	 * @brief Construit une matrice à partir d'un double \p a11, d'un double \p a12, d'un double \p a21, et d'un double \p a22
	 * @param[in] a11 Un double (à defaut 1)
	 * @param[in] a12 Un double (à defaut 1)
	 * @param[in] a21 Un double (à defaut 1)
	 * @param[in] a22 Un double (à defaut 1)
	 * @return Une matrice22
	 */
	explicit Matrice22(const double & a11 = 1 , const double & a12 = 0, const double & a21 = 0, const double & a22 = 1) : Matrice22(Vecteur2D(a11, a12), Vecteur2D(a21, a22)) {}
	/**
	 * @brief Construit une matrice utile à la réalisation d'une rotation
	 * @param[in] alpha Un double correspondant à un angle radiant
	 * @return Une matrice22
	 */
	static Matrice22 creeRotation(const double & alpha) {
		const double calpha = cos(alpha);
		const double salpha = sin(alpha);
		return Matrice22(calpha, -salpha, salpha, calpha);
	}
	/**
	 * @brief Permet d'obtenir une chaîne de caractère indiquant les spécificités de la matrice
	 * @return Une chaîne de caractère
	 */
	explicit operator string() const {
		ostringstream o;
		o << ligneHaut << endl;
		o << ligneBas;
		return o.str();
	}
	/**
	 * @brief Realise la multiplication d'une matrice par rapport à un vecteur
	 * @param[in] v Un vecteur2D
	 * @return Un vecteur2D
	 */
	Vecteur2D operator *(const Vecteur2D & v) const {
		return Vecteur2D(ligneHaut*v, ligneBas*v);
	}
};

/**
* @brief Permet l'utilisation du << pour une matrice lors de l'utilisation d'ostream
* @return L'ostream complété
*/
inline ostream & operator <<(ostream & o, const Matrice22 & mat) {
	return o << string(mat);
}

#endif