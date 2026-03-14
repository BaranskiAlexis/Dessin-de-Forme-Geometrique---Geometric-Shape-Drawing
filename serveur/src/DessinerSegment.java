package src;

import java.awt.geom.Line2D;
import java.util.Locale;
import java.util.Scanner;

/**
 * @brief Permet de gérer la récupération d'un segment
 */
public class DessinerSegment extends Dessiner {
    /**
     * @brief Permet la construction d'un maillon du design pattern chain of responsibility permettant la récupération d'un segment
     * @param[in] suivant Le prochain maillon
     */
    public DessinerSegment(final Dessiner suivant) {
        super(suivant);
    }
    /**
     * @brief Permet à partir d'un message reçu de le traîter afin d'en récupérer un segment
     * @param[in] m La chaîne de caractères
     * @param[in] c L'objet courant
     * @return int (0 pour le succès, -1 pour l'échec)
     */
    protected int charger(String m, ConnexionUtilisateur c) {
        final String s = m.trim();
        final Scanner sc = new Scanner(s);
        sc.useLocale(Locale.US);
        if (!sc.next().equals("Segment")) {
            return -1;
        }
        sc.next();
        final double x1 = sc.nextDouble();
        final double y1 = sc.nextDouble();
        final double x2 = sc.nextDouble();
        final double y2 = sc.nextDouble();
        final Line2D.Double line = new Line2D.Double(x1, y1, x2, y2);
        c.addShape(line);
        return 0;
    }
}
