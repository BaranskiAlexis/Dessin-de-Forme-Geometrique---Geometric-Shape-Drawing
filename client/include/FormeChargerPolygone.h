#ifndef PPIL_FORMECHARGERPOLYGONE_H
#define PPIL_FORMECHARGERPOLYGONE_H
#include "FormeCharger.h"

/**
* @brief Permet le chargement d'un polygone
*/
class FormeChargerPolygone : public FormeCharger {
protected:
    /**
    * @brief Permet de charger un polygone
    * @param[in] s Le string étant la première ligne du flux en cours
    * @param[in] flux Le flux de string
    * @return Un polygone
    */
    Forme * charger(const string & s, istringstream & flux) const override;
public:
    /**
    * @brief Permet la construction d'un maillon du design pattern chain of responsability permettant le chargement d'une forme, ici pour un polygone
    * @param[in] suivant Le prochain maillon
    */
    explicit FormeChargerPolygone(FormeCharger * suivant);
    /**
    * @brief Permet la destruction de l'objet
    */
    ~FormeChargerPolygone() override;
};

#endif