#ifndef RPS_SERVER_RESPONSE_H
#define RPS_SERVER_RESPONSE_H

#include "Player.h"
#include <cstdio>
#include <sys/types.h>
#include <sys/socket.h>
/**
 * Používá se jako odpověď na požadavek
 */
class Response {

public:
    /**
     * sends a message to the client by its socket file descriptor
     * @param sockFd
     * @param message
     */
    static void sendToClient(int sockFd, string message);

    /**
     * Odešle zprávu hráči
     * @param player hráč
     * @param message zpráva
     */
    static void sendToPlayer(Player *player, string message);

    /**
     * Odešle specifikovanou chybovou zprávu hráči s počítadlem chybových zpráv
     * @param player hráč
     * @param errorMessage chybová zpráva
     */
    static void sendErrorToPlayer(Player *player, string errorMessage);

    /**
     * Odešle specifikovanou chybovou zprávu hráči beze jména s počítadlem chybových zpráv
     * @param player hráč
     * @param errorMessage chybová zpráva
     */
    static void sendErrorToPlayer1(Player *player, string errorMessage);

};


#endif
