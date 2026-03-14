#ifndef PPIL_FORMECHARGERFORMECOMPOSEE_H
#define PPIL_FORMECHARGERFORMECOMPOSEE_H
#include "FormeCharger.h"

/**
* @brief Permet le chargement d'une forme composée
*/
class FormeChargerFormeComposee : public FormeCharger {
protected:
    /**
    * @brief Permet de charger une forme composée
    * @param[in] s Le string étant la première ligne du flux en cours
    * @param[in] flux Le flux de string
    * @return Une forme composée
    */
    Forme * charger(const string & s, istringstream & flux) const override;
public:
    /**
    * @brief Permet la construction d'un maillon du design pattern chain of responsability permettant le chargement d'une forme, ici pour une forme composée
    * @param[in] suivant Le prochain maillon
    */
    explicit FormeChargerFormeComposee(FormeCharger * suivant);
    /**
    * @brief Permet la destruction de l'objet
    */
    ~FormeChargerFormeComposee() override;
};

#endif