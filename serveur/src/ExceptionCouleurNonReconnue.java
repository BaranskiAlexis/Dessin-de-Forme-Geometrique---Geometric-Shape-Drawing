package src;

/**
 * @brief Classe permettant la gestion de l'erreur en cas non-reconnaissance de la couleur
 */
public class ExceptionCouleurNonReconnue extends ExceptionDessin {
    public ExceptionCouleurNonReconnue() {
        super("ExceptionDessin - La forme n'est pas reconnue");
    }
}
