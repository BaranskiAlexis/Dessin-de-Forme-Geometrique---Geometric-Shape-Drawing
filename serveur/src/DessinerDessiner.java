package src;

import java.awt.*;
import java.awt.image.BufferStrategy;

/**
 * @brief Permet de gérer le dessin des formes
 */
public class DessinerDessiner extends Dessiner {
    /**
     * @brief Permet la construction d'un maillon du design pattern chain of responsibility permettant le dessin des formes
     * @param[in] suivant Le prochain maillon
     */
    public DessinerDessiner(final Dessiner suivant) {
        super(suivant);
    }
    /**
     * @brief Permet à partir d'un message reçu de le traîter afin de réaliser le dessin des formes
     * @param[in] m La chaîne de caractères
     * @param[in] c L'objet courant
     * @return int (0 pour le succès, -1 pour l'échec)
     */
    protected int charger(String m, ConnexionUtilisateur c) throws InterruptedException {
        String s = m.trim();
        if (!s.startsWith("Dessiner")) return -1;
        Frame frame = new Frame();
        frame.setUndecorated(true);
        frame.setSize(800, 500);
        frame.setLocationRelativeTo(null);
        frame.setIgnoreRepaint(true);
        frame.setVisible(true);
        frame.createBufferStrategy(2);
        Thread.sleep(150);
        BufferStrategy strategy = frame.getBufferStrategy();
        Graphics2D graphics = (Graphics2D) strategy.getDrawGraphics();
        graphics.setColor(c.getColor());
        for (Shape sh : c.getShapes()) {
            graphics.draw(sh);
            graphics.fill(sh);
        }
        strategy.show();
        graphics.dispose();
        c.clearShapes();
        c.setColor(Color.black);
        return 0;
    }
}
