#ifndef PPIL_FORMECHARGERCERCLE_H
#define PPIL_FORMECHARGERCERCLE_H
#include "FormeCharger.h"

/**
* @brief Permet le chargement d'un cercle
*/
class FormeChargerCercle : public FormeCharger {
protected:
    /**
    * @brief Permet de charger un cercle
    * @param[in] s Le string étant la première ligne du flux en cours
    * @param[in] flux Le flux de string
    * @return Un cercle
    */
    Forme * charger(const string & s, istringstream & flux) const override;
public:
    /**
    * @brief Permet la construction d'un maillon du design pattern chain of responsability permettant le chargement d'une forme, ici pour un cercle
    * @param[in] suivant Le prochain maillon
    */
    explicit FormeChargerCercle(FormeCharger * suivant);
    /**
    * @brief Permet la destruction de l'objet
    */
    ~FormeChargerCercle() override;
};

#endif