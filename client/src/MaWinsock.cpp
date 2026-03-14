#include "../include/MaWinsock.h"
#include <exception>

MaWinsock * MaWinsock::instanceUnique = nullptr;

MaWinsock * MaWinsock::getInstance() {
    if (!instanceUnique) instanceUnique = new MaWinsock;
    return instanceUnique;
}

MaWinsock::MaWinsock() {
    if (WSAStartup( MAKEWORD(2,0), &wsaData) != 0) throw std::exception();
}

MaWinsock::~MaWinsock() {
    WSACleanup();
}