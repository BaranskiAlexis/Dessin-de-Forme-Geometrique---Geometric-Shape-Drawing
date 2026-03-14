package src;

import java.awt.*;
import java.util.Locale;
import java.util.Scanner;

/**
 * @brief Permet de gérer la récupération d'un triangle
 */
public class DessinerTriangle extends Dessiner {
    /**
     * @brief Permet la construction d'un maillon du design pattern chain of responsibility permettant la récupération d'un triangle
     * @param[in] suivant Le prochain maillon
     */
    public DessinerTriangle(final Dessiner suivant) {
        super(suivant);
    }
    /**
     * @brief Permet à partir d'un message reçu de le traîter afin d'en récupérer un triangle
     * @param[in] m La chaîne de caractères
     * @param[in] c L'objet courant
     * @return int (0 pour le succès, -1 pour l'échec)
     */
    protected int charger(String m, ConnexionUtilisateur c) {
        final String s = m.trim();
        final Scanner sc = new Scanner(s);
        sc.useLocale(Locale.US);
        if (!sc.next().equals("Triangle")) {
            return -1;
        }
        sc.next();
        final double x1 = sc.nextDouble();
        final double y1 = sc.nextDouble();
        final double x2 = sc.nextDouble();
        final double y2 = sc.nextDouble();
        final double x3 = sc.nextDouble();
        final double y3 = sc.nextDouble();
        Polygon triangle = new Polygon();
        triangle.addPoint((int) x1, (int) y1);
        triangle.addPoint((int) x2, (int) y2);
        triangle.addPoint((int) x3, (int) y3);
        c.addShape(triangle);
        return 0;
    }
}
