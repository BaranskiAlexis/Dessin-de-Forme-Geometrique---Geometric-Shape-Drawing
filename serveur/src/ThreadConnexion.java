package src;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;

/**
 * @brief Classe réseau permettant la gestion des messages lié au socket client
 */
public class ThreadConnexion extends Thread {
    /**
     * @brief L'entrée du socket client
     */
    private final BufferedReader in;
    /**
     * @brief La partie métier lié du socket client
     */
    private final ConnexionUtilisateur connexion;
    /**
     * @brief Paramètre permettant l'arrêt de la gestion du socket client
     */
    private boolean fin = false;
    /**
     * @brief Du socket client
     */
    private final Socket socket;
    /**
     * @brief Création de la classe permettant la réception des messages du socket client
     * @param[in] connexion La partie métier lié au socket client
     * @param[in] socket Le socket client
     */
    public ThreadConnexion(ConnexionUtilisateur connexion, Socket socket) {
        this.connexion = connexion;
        try {
            this.in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            this.socket = socket;
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        start();
    }
    /**
     * @brief Thread permettant la réception des messages du socket client
     */
    public void run() {
        while (!this.fin) {
            try {
                String message = in.readLine();
                if (message == null) {
                    this.fin = true;
                }
                else {
                    this.connexion.traiterMessage(message);
                }

            } catch (IOException e) {
                this.fin = true;
                try {
                    socket.close();
                } catch (IOException ex) {
                    throw new RuntimeException(ex);
                }
            } catch (Exception e) {
                this.fin = true;
                throw new RuntimeException(e);
            }
        }
    }
}
