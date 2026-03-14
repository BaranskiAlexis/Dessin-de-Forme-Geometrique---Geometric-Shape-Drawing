#ifndef PPIL_VECTEUR2D_H
#define PPIL_VECTEUR2D_H
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

/**
 * @brief Permet de gérer un vecteur
 */
class Vecteur2D {
public:
	/**
	* @brief L'ensemble des points du segment
	*/
	double x, y;
	/**
	 * @brief Construit un vecteur 2D à partir d'une abscisse \p x et d'une ordonnée \p y
	 * @param[in] x L'abscisse
	 * @param[in] y L'ordonnée
	 * @return Un vecteur 2D
	 */
	explicit Vecteur2D(const double &x = 0, const double &y = 0): x(x), y(y) {}
	/**
	 * @brief Realise l'addition de deux vecteurs
	 * @param[in] v Un vecteur
	 * @return Un vecteur 2D
	 */
	Vecteur2D operator+(const Vecteur2D& v) const {
		return Vecteur2D(x + v.x, y + v.y);
	}
	/**
	 * @brief Realise l'inverse du vecteur implicite
	 * @return Un vecteur 2D
	 */
	Vecteur2D operator-() const {
		return Vecteur2D(-x, -y);
	}
	/**
	 * @brief Realise la soustraction de deux vecteurs
	 * @param[in] v Un vecteur
	 * @return Un vecteur 2D
	 */
	Vecteur2D operator-(const Vecteur2D& v) const {
		return *this + -v;
	}
	/**
	 * @brief Realise l'addition de deux vecteurs
	 * @param[in] v Un vecteur
	 * @return Un vecteur 2D
	 */
	const Vecteur2D & operator+=(const Vecteur2D& v) {
		x += v.x;
		y += v.y;
		return *this;
	}
	/**
	 * @brief Realise le produit d'un vecteur en fonction d'une constante
	 * @param[in] k Une constante
	 * @return Un vecteur 2D
	 */
	Vecteur2D operator*(const double& k) const {
		return Vecteur2D(k * x, k * y);
	}
	/**
	 * @brief Realise le produit vectoriel de deux vecteurs
	 * @param[in] v Un vecteur
	 * @return Un nombre
	 */
	double operator*(const Vecteur2D & v) const {
		return x * v.x + y * v.y;
	}
	/**
	 * @brief Realise le determinant de deux vecteurs
	 * @param[in] v Un vecteur
	 * @return Le determinant
	 */
	double operator|(const Vecteur2D & v) const {
		return abs(x * v.y - y * v.x);
	}
	/**
	 * @brief Realise la norme au carré d'un vecteur
	 * @return La norme au carre
	 */
	double norme2() const {
		return *this * *this;
	}
	/**
	 * @brief Realise la norme d'un vecteur
	 * @return La norme
	 */
	double norme() const {
		return sqrt(norme2());
	}
	/**
	 * @brief Verifie si deux vecteurs sont égaux
	 * @return Un booléen
	 */
	bool operator==(const Vecteur2D & v) const {
		return x == v.x && y == v.y;
	}
	/**
	* @brief Permet d'obtenir une chaîne de caractère indiquant les spécificités du vecteur
	* @return Une chaîne de caractère
	*/
	explicit operator string() const {
		ostringstream o;
		o << x << " " << y;
		return o.str();
	}
};

/**
* @brief Permet l'utilisation du << pour un vecteur lors de l'utilisation d'ostream
* @return L'ostream completé
*/
inline ostream & operator <<(ostream& o, const Vecteur2D& v) {
	o << string(v);
	return o;
}

#endif