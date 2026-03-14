package src;

import java.awt.*;
import java.util.Locale;
import java.util.Scanner;

/**
 * @brief Permet de gérer la récupération d'un polygone
 */
public class DessinerPolygone extends Dessiner {
    /**
     * @brief Permet la construction d'un maillon du design pattern chain of responsibility permettant la récupération d'un polygone
     * @param[in] suivant Le prochain maillon
     */
    public DessinerPolygone(final Dessiner suivant) {
        super(suivant);
    }
    /**
     * @brief Permet à partir d'un message reçu de le traîter afin d'en récupérer un polygone
     * @param[in] m La chaîne de caractères
     * @param[in] c L'objet courant
     * @return int (0 pour le succès, -1 pour l'échec)
     */
    protected int charger(String m, ConnexionUtilisateur c) {
        final String s = m.trim();
        final Scanner sc = new Scanner(s);
        sc.useLocale(Locale.US);
        if (!sc.next().equals("Polygone")) {
            return -1;
        }
        final Polygon polygone = new Polygon();
        sc.next();
        while (sc.hasNextDouble()) {
            double x = sc.nextDouble();
            double y = sc.nextDouble();
            polygone.addPoint((int) x, (int) y);
        }
        c.addShape(polygone);
        return 0;
    }
}
