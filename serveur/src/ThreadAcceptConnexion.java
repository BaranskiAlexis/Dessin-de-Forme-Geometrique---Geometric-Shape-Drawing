package src;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

/**
 * @brief Classe réseau permettant la gestion du socket serveur
 */
public class ThreadAcceptConnexion extends Thread {
    /**
     * @brief Le socket serveur
     */
    private final ServerSocket serverSocket;
    /**
     * @brief Création du socket serveur et du thread associé pour recevoir les sockets clients
     * @param[in] port Le port du serveur
     */
    public ThreadAcceptConnexion(int port) {
        try {
            this.serverSocket = new ServerSocket(port);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        start();
    }
    /**
     * @brief Thread permettant la réception des sockets clients
     * @return void
     */
    @Override
    public void run() {
        try {
            while (true) {
                Socket socket = serverSocket.accept();
                new ConnexionUtilisateur(socket);
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
