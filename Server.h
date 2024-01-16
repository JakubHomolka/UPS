#ifndef RPS_SERVER_SERVER_H
#define RPS_SERVER_SERVER_H

#include <string>
#include <cstdio>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/un.h>
#include <unistd.h>
#include <netinet/in.h>
#include <cstdlib>
#include <sys/socket.h>
#include <iostream>
#include <sys/ioctl.h>

#include "ClientManager.h"
#include "GameManager.h"
#include "GameLogic.h"
#include "Request.h"

using namespace std;
/**
 * Třída serveru
 */
class Server {

public:

    /**
     * Používá se pro inicializaci serveru a validaci argumentů příkazové řádky
     * @param ip IP adresa serveru
     * @param port port pro naslouchání
     * @return -1 chyba, 0 v pořádku
     */
    int init(string ip, int port);

    /**
     * Smyčka pro naslouchání socketu
     */
    int listenConnections();

    /**
     * Ukončí socke
     * @param socket ID socket file descriptoru
     */
    static void closeSocket(int socket);

    /**
    * Odpojí socket
    * @param socket ID socket file descriptoru
    */
    void disconnect(int socket);

    static fd_set client_socks, tests; // Statické sady deskriptorů socketů pro klienty a testování

private:

    int server_socket, client_socket; // Socket serveru a socket pro přijímání klientů

    static struct sockaddr_in server, client, peer_addr; // Statické struktury pro adresy serveru, klienta a peer adresy
};


#endif
