package src;

/**
 * @brief Permet de gérer la récupération d'une forme composée
 */
public class DessinerFormeComposee extends Dessiner {
    /**
     * @brief Permet la construction d'un maillon du design pattern chain of responsibility permettant la récupération d'une forme composée
     * @param[in] suivant Le prochain maillon
     */
    public DessinerFormeComposee(final Dessiner suivant) {
        super(suivant);
    }
    /**
     * @brief Permet à partir d'un message reçu de le traîter afin d'en récupérer une forme composée
     * @param[in] m La chaîne de caractères
     * @param[in] c L'objet courant
     * @return int (0 pour le succès, -1 pour l'échec)
     */
    protected int charger(String m, ConnexionUtilisateur c) {
        String s = m.trim();
        if (!s.startsWith("FormeComposee") && !s.startsWith("]")) return -1;
        return 0;
    }
}
