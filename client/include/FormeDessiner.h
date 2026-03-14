#ifndef PPIL_FORMEDESSIN_H
#define PPIL_FORMEDESSIN_H
#include "FormeVisiteur.h"
#include <winsock2.h>

/**
 * @brief Permet de gérer l'ensemble des exceptions liées aux visiteurs de forme dessin
 */
class ExceptionDessin : public ExceptionFormeVisiteur {
    /**
    * @brief Le message lié à l'exception
    */
    string message = " ExceptionDessin -";
public:
    /**
    * @brief Permet d'obtenir une chaîne de caractère lié à l'erreur
    * @return Une chaîne de caractère
    */
    string getMessage() const override {
        return ExceptionFormeVisiteur::getMessage() + message;
    }
};

/**
 * @brief Permet de gérer l'exception lors de l'impossibilité de transformer la forme
 */
class ExceptionTransformationForme : public ExceptionDessin {
    /**
    * @brief Le message lié à l'exception
    */
    string message = " Il est impossible de transformer la forme";
public:
    /**
    * @brief Permet d'obtenir une chaîne de caractère lié à l'erreur
    * @return Une chaîne de caractère
    */
    string getMessage() const override {
        return ExceptionDessin::getMessage() + message;
    }
};

/**
 * @brief Permet de gérer l'exception lors de l'impossibilité de créer le socket
 */
class ExceptionCreationSocket : public ExceptionDessin {
    /**
    * @brief Le message lié à l'exception
    */
    string message = " Il est impossible de creer la socket";
public:
    /**
    * @brief Permet d'obtenir une chaîne de caractère lié à l'erreur
    * @return Une chaîne de caractère
    */
    string getMessage() const override {
        return ExceptionDessin::getMessage() + message;
    }
};

/**
 * @brief Permet de gérer l'exception lors de l'impossibilité d'envoyer un message
 */
class ExceptionEnvoieImpossible : public ExceptionDessin {
    /**
    * @brief Le message lié à l'exception
    */
    string message = " Il est impossible d'envoyer un message";
public:
    /**
    * @brief Permet d'obtenir une chaîne de caractère lié à l'erreur
    * @return Une chaîne de caractère
    */
    string getMessage() const override {
        return ExceptionDessin::getMessage() + message;
    }
};

/**
 * @brief Permet de gérer l'exception lors de l'impossibilité de paramétrer l'envoie des messages.
 */
class ExceptionParametragePaquet : public ExceptionDessin {
    /**
    * @brief Le message lié à l'exception
    */
    string message = " Il est impossible de parametrer les paquets";
public:
    /**
    * @brief Permet d'obtenir une chaîne de caractère lié à l'erreur
    * @return Une chaîne de caractère
    */
    string getMessage() const override {
        return ExceptionDessin::getMessage() + message;
    }
};

/**
 * @brief Permet de gérer l'exception lors de l'impossibilité de se connecter au serveur
 */
class ExceptionConnexionImpossible : public ExceptionDessin {
    /**
    * @brief Le message lié à l'exception
    */
    string message = " Il est impossible de se connecter au serveur";
public:
    /**
    * @brief Permet d'obtenir une chaîne de caractère lié à l'erreur
    * @return Une chaîne de caractère
    */
    string getMessage() const override {
        return ExceptionDessin::getMessage() + message;
    }
};

/**
 * @brief Permet l'implémentation du pattern design visiteur pour les formes dans le cadre d'un dessin
 */
class FormeDessiner : public FormeVisiteur {
    /**
    * @brief Adresse IP du serveur
    */
    static const string adress;
    /**
    * @brief Port du serveur
    */
    static constexpr int port = 4567;
    /**
    * @brief Socket
    */
    SOCKET sock;
    /**
    * @brief Paramètrage de la socket
    */
    SOCKADDR_IN sockaddr{};
    /**
    * @brief Permet l'envoie d'une forme pour la dessiner
    * @param[in] f Une forme
    * @return \p (*this) L'objet implicite
    */
    FormeDessiner & traiterFormePourRequete(const Forme & f);
    /**
    * @brief Permet le prétraitement d'une forme afin que celle-ci soit adaptée pour le dessin
    * @param[in] f Une forme
    * @return \p (*this) L'objet implicite
    */
    FormeDessiner & preTransformationPassageEcran(Forme & f);
    /**
    * @brief Permet l'envoie d'un message au serveur
    * @param[in] requete Une chaîne de caractère
    * @return \p (*this) L'objet implicite
    */
    FormeDessiner & envoyerRequete(const string & requete);
public:
    /**
     * @brief Permet la construction du Visiteur permettant le dessin d'un objet
     */
    explicit FormeDessiner();
    /**
     * @brief Permet la destruction de l'objet
     */
    ~FormeDessiner() override;
    /**
     * @brief Permet l'introduction de méthode pour un segment via le design pattern visitor, ici le dessin
     * @param[in] f Un segment
     * @return \p (*this) L'objet implicite
     */
    FormeDessiner & visit(const Segment & f) override;
    /**
     * @brief Permet l'introduction de méthode pour un cercle via le design pattern visitor, ici le dessin
     * @param[in] f Un cercle
     * @return \p (*this) L'objet implicite
     */
    FormeDessiner & visit(const Cercle & f) override;
    /**
     * @brief Permet l'introduction de méthode pour un triangle via le design pattern visitor, ici le dessin
     * @param[in] f Un triangle
     * @return \p (*this) L'objet implicite
     */
    FormeDessiner & visit(const Triangle & f) override;
    /**
     * @brief Permet l'introduction de méthode pour un polygone via le design pattern visitor, ici le dessin
     * @param[in] f Un polygone
     * @return \p (*this) L'objet implicite
     */
    FormeDessiner & visit(const Polygone & f) override;
    /**
     * @brief Permet l'introduction de méthode pour une forme composée via le design pattern visitor, ici le dessin
     * @param[in] f Une forme composée
     * @return \p (*this) L'objet implicite
     */
    FormeDessiner & visit(const FormeComposee & f) override;
};

#endif