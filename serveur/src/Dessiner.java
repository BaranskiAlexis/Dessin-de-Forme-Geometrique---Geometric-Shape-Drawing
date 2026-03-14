package src;

/**
 * @brief Permet de gérer le dessin d'une forme
 */
public abstract class Dessiner {
    /**
     * @brief Le prochain maillon de la chaîne
     */
    private final Dessiner suivant;
    /**
     * @brief Permet la construction d'un maillon du design pattern chain of responsibility permettant le dessin d'une forme
     * @param[in] suivant Le prochain maillon
     */
    public Dessiner(final Dessiner suivant) {
        this.suivant = suivant;
    }
    /**
     * @brief Permet à partir d'un message reçu de le traîter afin d'en récupérer une couleur, une forme ou l'ordre de dessiner
     * @param[in] m La chaîne de caractères
     * @param[in] c L'objet courant
     * @return int (0 pour le succès, -1 pour l'échec)
     * @details \p ExceptionDessin Exception liée au dessin
     * @details \p InterruptedException Exception liée à Java AWT
     */
    protected abstract int charger(String m, ConnexionUtilisateur c) throws ExceptionDessin, InterruptedException;
    /**
     * @brief Permet de démarrer la chain of responsibility dans le but de dessiner
     * @param[in] m La chaîne de caractères
     * @param[in] c L'objet courant
     * @return int (0 pour le succès, -1 pour l'échec)
     * @details \p ExceptionDessin Exception liée au dessin
     * @details \p InterruptedException Exception liée à Java AWT
     */
    public int dessiner(String m, ConnexionUtilisateur c) throws ExceptionFormeNonReconnue, InterruptedException {
        int i = charger(m, c);
        if (i == -1) i = suivant.dessiner(m, c);
        if (i == -1) throw new ExceptionFormeNonReconnue();
        return 0;
    }
}
