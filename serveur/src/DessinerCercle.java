package src;

import java.awt.geom.Ellipse2D;
import java.util.Locale;
import java.util.Scanner;

/**
 * @brief Permet de gérer le dessin d'un cercle
 */
public class DessinerCercle extends Dessiner {
    /**
     * @brief Permet la construction d'un maillon du design pattern chain of responsibility permettant le dessin d'un cercle
     * @param[in] suivant Le prochain maillon
     */
    public DessinerCercle(final Dessiner suivant) {
        super(suivant);
    }
    /**
     * @brief Permet à partir d'un message reçu de le traîter afin d'en récupérer un cercle
     * @param[in] m La chaîne de caractères
     * @param[in] c L'objet courant
     * @return int (0 pour le succès, -1 pour l'échec)
     */
    protected int charger(String m, ConnexionUtilisateur c) {
        final String s = m.trim();
        final Scanner sc = new Scanner(s);
        sc.useLocale(Locale.US);
        if (!sc.next().equals("Cercle")) {
            return -1;
        }
        sc.next();
        final double xc = sc.nextDouble();
        final double yc = sc.nextDouble();
        final double r = sc.nextDouble();
        final Ellipse2D.Double circle = new Ellipse2D.Double(xc-r, yc-r, r*2, r*2);
        c.addShape(circle);
        return 0;
    }
}
