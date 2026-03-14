package src;

/**
 * @brief Classe permettant la gestion des erreurs liée au dessin
 */
public class ExceptionDessin extends RuntimeException {
    public ExceptionDessin(String message) {
        super(message);
    }
}
