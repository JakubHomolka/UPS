#ifndef RPS_SERVER_CLIENTMANAGER_H
#define RPS_SERVER_CLIENTMANAGER_H

#include <cstdio>
#include <map>
#include <vector>
#include <stack>
#include <memory>
#include <string>
#include "Player.h"
#include "Server.h"
#include "Response.h"
#include "GameManager.h"

/**
 * Manipuluje s klienty (hráči)
 */
class ClientManager {
public:
    /**
     * Používá se pro manipulaci s nepřihlášenými hráči (token pro přihlášení ještě nebyl odeslán)
     */
    static map<int, Player *> unlogged_players;
    /**
     * Používá se pro manipulaci s přihlášenými hráči (token pro přihlášení byl již odeslán)
     */
    static map<string, Player *> logged_players;

    /**
     * získá přihlášeného hráče z mapy podle socket ID
     * @param socket_id socket ID hráče
     * @return Objekt hráče
     */
    static Player *get_logged_player_by_socket(int socket_id);

    /**
     * získá nepřihlášeného hráče z mapy
     * @param id socket ID hráče
     * @return Objekt hráče
     */
    static Player *get_unlogged_player(int id);

    /**
     * vytvoří nepřihlášeného hráče v mapě nepřihlášených hráčů
     * @param ip IP klienta
     * @param client_socket
     */
    static void create_unlogged_player(char *ip, int client_socket);

    /**
     * vrátí hráče z mapy přihlášených hráčů podle jména
     * @param name jméno hráče
     * @return Objekt hráče
     */
    static Player *get_logged_player_by_name(string name);

    /**
     * Používá se pro přihlášení hráče, znamená to odstranění z mapy nepřihlášených a přesun do mapy přihlášených hráčů
     * @param client_socket
     * @param name
     */
    static void log_player(int client_socket, string name);

    /**
     * Zpracovává nové připojení hráče. Pokud je hráč přihlášen a odpojen, pak se znovu připojí.
     * Pokud je klient nepřihlášený, pak ho přihlásí
     * @param sock_fd
     * @param name
     */
    static void handleNewConnection(int sock_fd, string name);

    /**
     * Znovu připojí hráče s nastaveným stavem připojení -1
     * @param pl
     * @param newSockFd
     */
    static void reconnect(Player *pl, int newSockFd);

    /**
     * odstraní hráče a veškeré jeho informace ze serveru
     * @param sock_fd
     */
    static void logoutPlayer(int sock_fd);

    /**
     * Zničí hráče, odstraní všechny jeho informace a zdroje spojené s daným socketem
     * @param sock_fd
     */
    static void destroyPlayer(int sock_fd);

};


#endif
