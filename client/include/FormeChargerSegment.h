#ifndef PPIL_FORMECHARGERSEGMENT_H
#define PPIL_FORMECHARGERSEGMENT_H
#include "FormeCharger.h"

/**
* @brief Permet le chargement d'un segment
*/
class FormeChargerSegment : public FormeCharger {
protected:
    /**
    * @brief Permet de charger un segment
    * @param[in] s Le string étant la première ligne du flux en cours
    * @param[in] flux Le flux de string
    * @return Un segment
    */
    Forme * charger(const string & s, istringstream & flux) const override;
public:
    /**
    * @brief Permet la construction d'un maillon du design pattern chain of responsability permettant le chargement d'une forme, ici pour un segment
    * @param[in] suivant Le prochain maillon
    */
    explicit FormeChargerSegment(FormeCharger * suivant);
    /**
    * @brief Permet la destruction de l'objet
    */
    ~FormeChargerSegment() override;
};

#endif