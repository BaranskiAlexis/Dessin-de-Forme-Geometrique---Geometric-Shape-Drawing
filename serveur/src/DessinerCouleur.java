package src;

import java.awt.*;

/**
 * @brief Permet de gérer la récupération de la couleur pour le dessin
 */
public class DessinerCouleur extends Dessiner {
    /**
     * @brief Permet la construction d'un maillon du design pattern chain of responsibility permettant la récupération de la couleur
     * @param[in] suivant Le prochain maillon
     */
    public DessinerCouleur(final Dessiner suivant) {
        super(suivant);
    }
    /**
     * @brief Permet à partir d'un message reçu de le traîter afin d'en récupérer une couleur
     * @param[in] m La chaîne de caractères
     * @param[in] c L'objet courant
     * @return int (0 pour le succès, -1 pour l'échec)
     * @details \p ExceptionCouleurNonReconnue En cas de non-reconnaissance de la couleur
     */
    protected int charger(String m, ConnexionUtilisateur c) throws ExceptionCouleurNonReconnue {
        String s = m.trim();
        if (!s.startsWith("Couleur")) return -1;
        s = s.replaceFirst("Couleur", "").trim();
        switch (s) {
            case "Black":
                c.setColor(new Color(0, 0, 0));
                break;
            case "Blue":
                c.setColor(new Color(0, 0, 255));
                break;
            case "Red":
                c.setColor(new Color(255, 0, 0));
                break;
            case "Green":
                c.setColor(new Color(0, 255, 0));
                break;
            case "Yellow":
                c.setColor(new Color(255, 255, 0));
                break;
            case "Cyan":
                c.setColor(new Color(0, 255, 255));
                break;
            default:
                throw new ExceptionCouleurNonReconnue();
        }
        return 0;
    }
}
