#ifndef PPIL_MAWINSOCK_H
#define PPIL_MAWINSOCK_H
#include <winsock2.h>

/**
 * @brief Permet la gestion de la socket serveur
 */
class MaWinsock final {
    WSADATA wsaData;
    /**
    * @brief Permet la création de l'instance
    */
    explicit MaWinsock();
    /**
    * @brief L'instance unique (singleton)
    */
    static MaWinsock * instanceUnique;
public:
    /**
    * @brief Permet l'obtention de l'instance, et la crée si elle n'existe pas
    * @return L'instance Winsock
    */
    static MaWinsock * getInstance();
    /**
    * @brief Permet la destruction de la socket
    */
    ~MaWinsock();
};

#endif