#ifndef PPIL_FORMECHARGERTRIANGLE_H
#define PPIL_FORMECHARGERTRIANGLE_H
#include "FormeCharger.h"

/**
* @brief Permet le chargement d'un triangle
*/
class FormeChargerTriangle : public FormeCharger {
protected:
    /**
    * @brief Permet de charger un triangle
    * @param[in] s Le string étant la première ligne du flux en cours
    * @param[in] flux Le flux de string
    * @return Un triangle
    */
    Forme * charger(const string & s, istringstream & flux) const override;
public:
    /**
    * @brief Permet la construction d'un maillon du design pattern chain of responsability permettant le chargement d'une forme, ici pour un triangle
    * @param[in] suivant Le prochain maillon
    */
    explicit FormeChargerTriangle(FormeCharger * suivant);
    /**
    * @brief Permet la destruction de l'objet
    */
    ~FormeChargerTriangle() override;
};

#endif