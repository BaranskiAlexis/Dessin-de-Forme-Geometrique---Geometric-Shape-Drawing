package src;

import java.awt.*;
import java.net.Socket;
import java.util.ArrayList;

/**
 * @brief Classe permettant la gestion du dessin et du socket client
 */
public class ConnexionUtilisateur {
    /**
     * @brief Ensemble des formes à dessiner
     */
    private final ArrayList<Shape> shapes = new ArrayList<>();
    /**
     * @brief La couleur des formes
     */
    private Color color = new Color(0, 0, 0);
    /**
     * @brief Création de la classe permettant la gestion du dessin et du socket client
     * @param[in] socket Le socket client
     */
    public ConnexionUtilisateur(Socket socket) {
        new ThreadConnexion(this, socket);
    }
    /**
     * @brief Permet à partir d'un message reçu de le traîter afin d'en récupérer une couleur, une forme ou l'ordre de dessiner
     * @param[in] message La chaîne de caractères
     * @details \p ExceptionDessin Exception liée au dessin
     * @details \p InterruptedException Exception liée à Java AWT
     * @return void
     */
    public void traiterMessage(String message) throws ExceptionDessin, InterruptedException {
        System.out.println(message);
        Dessiner d = new DessinerSegment(null);
        d = new DessinerCercle(d);
        d = new DessinerTriangle(d);
        d = new DessinerPolygone(d);
        d = new DessinerFormeComposee(d);
        d = new DessinerCouleur(d);
        d = new DessinerDessiner(d);
        d.dessiner(message, this);
    }
    /**
     * @brief Retourne la couleur des formes
     * @return color La couleur des formes
     */
    public Color getColor() {
        return color;
    }
    /**
     * @brief Retourne l'ensemble des formes à dessiner
     * @return shapes L'ensemble des formes à dessiner
     */
    public ArrayList<Shape> getShapes() {
        return shapes;
    }
    /**
     * @brief Permet de changer la couleur des formes
     * @return void
     */
    public void setColor(Color color) {
        this.color = color;
    }
    /**
     * @brief Permet de rajouter une forme à dessiner
     * @return void
     */
    public void addShape(Shape s) {
        this.shapes.add(s);
    }
    /**
     * @brief Permet de vider l'ensemble des formes à dessiner
     * @return void
     */
    public void clearShapes() {
        this.shapes.clear();
    }
}