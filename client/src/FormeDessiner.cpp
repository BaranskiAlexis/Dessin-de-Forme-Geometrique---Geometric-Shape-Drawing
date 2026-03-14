#include "../include/FormeDessiner.h"
#include "../include/MaWinsock.h"
#include "../include/Matrice22.h"

const string FormeDessiner::adress = "127.0.0.1";

FormeDessiner & FormeDessiner::traiterFormePourRequete(const Forme & f) {
    envoyerRequete("Couleur " + couleurToString(f.getCouleur())+"\r\n");
    Forme * tmp = f.clone();
    preTransformationPassageEcran(*tmp);
    envoyerRequete(string(*tmp) + "\r\n");
    envoyerRequete("Dessiner\r\n");
    delete tmp;
    return *this;
}

FormeDessiner & FormeDessiner::preTransformationPassageEcran(Forme & f) {
    vector<Vecteur2D> p = f.getPoints();
    if (p.empty()) return *this;
    double xMin = p[0].x;
    double xMax = p[0].x;
    double yMin = p[0].y;
    double yMax = p[0].y;
    for (auto it = p.begin() + 1; it != p.end(); ++it) {
        if (xMin > it->x) xMin = it->x;
        else if (xMax < it->x) xMax = it->x;
        if (yMin > it->y) yMin = it->y;
        else if (yMax < it->y) yMax = it->y;
    }
    const Vecteur2D p1(xMin, yMin);
    const Vecteur2D p2(xMax, yMax);
    const Vecteur2D q1(0, 500);
    const Vecteur2D q2(800, 0);
    const double diffqx = q2.x - q1.x;
    const double diffpx = p2.x - p1.x;
    const double diffqy = q2.y - q1.y;
    const double diffpy = p2.y - p1.y;
    if (diffpx == 0 || diffpy == 0) {
        throw ExceptionTransformationForme();
    }
    const double ratioX = abs(diffqx) / abs(diffpx);
    const double ratioY = abs(diffqy) / abs(diffpy);
    const double l = (ratioX < ratioY) ? ratioX : ratioY;
    const int e1 = ((diffqx < 0) == (diffpx < 0)) ? 1 : -1;
    const int e2 = ((diffqy < 0) == (diffpy < 0)) ? 1 : -1;
    const Vecteur2D pc((p1.x + p2.x) / 2, (p1.y + p2.y) / 2);
    const Vecteur2D qc((q1.x + q2.x) / 2, (q1.y + q2.y) / 2);
    const Vecteur2D ab(qc.x - l * e1 * pc.x, qc.y - l * e2 * pc.y);
    const Matrice22 m(l * e1, 0, 0, l * e2);
    f.transformationEcran(m, ab);
    return *this;
}

FormeDessiner & FormeDessiner::envoyerRequete(const string & requete) {
    if (send(sock, requete.c_str(), static_cast<int>(requete.length()), 0) == SOCKET_ERROR) {
        throw ExceptionEnvoieImpossible();
    }
    return *this;
}

FormeDessiner::FormeDessiner() {
    MaWinsock::getInstance();
    sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock == INVALID_SOCKET) {
        throw ExceptionCreationSocket();
    }
    constexpr int opt = 1;
    if (setsockopt(sock, IPPROTO_TCP, TCP_NODELAY, reinterpret_cast<const char *>(&opt), sizeof(opt)) == SOCKET_ERROR) {
        throw ExceptionParametragePaquet();
    }
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_addr.s_addr = inet_addr(adress.c_str());
    sockaddr.sin_port = htons(port);
    if (connect(sock, reinterpret_cast<SOCKADDR*>(&sockaddr), sizeof(sockaddr)) == SOCKET_ERROR) {
        throw ExceptionConnexionImpossible();
    }
}

FormeDessiner::~FormeDessiner() {
    shutdown(sock, SD_BOTH);
    closesocket(sock);
}

FormeDessiner & FormeDessiner::visit(const Segment & f) {
    traiterFormePourRequete(f);
    return *this;
}

FormeDessiner & FormeDessiner::visit(const Cercle & f) {
    traiterFormePourRequete(f);
    return *this;
}

FormeDessiner & FormeDessiner::visit(const Triangle & f) {
    traiterFormePourRequete(f);
    return *this;
}

FormeDessiner & FormeDessiner::visit(const Polygone & f) {
    traiterFormePourRequete(f);
    return *this;
}

FormeDessiner & FormeDessiner::visit(const FormeComposee & f) {
    traiterFormePourRequete(f);
    return *this;
}