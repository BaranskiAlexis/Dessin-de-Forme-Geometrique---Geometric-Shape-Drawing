package src;

/**
 * @brief Classe permettant la gestion de l'erreur en cas non-reconnaissance de la forme
 */
public class ExceptionFormeNonReconnue extends ExceptionDessin {
    public ExceptionFormeNonReconnue() {
        super("ExceptionDessin - La forme n'est pas reconnue");
    }
}
