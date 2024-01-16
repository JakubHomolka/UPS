#ifndef RPS_SERVER_GAME_H
#define RPS_SERVER_GAME_H

#define MAX_PLAYERS 2

#include <vector>
#include <string>
#include "Player.h"


using namespace std;

/**
 * Reprezentace hry
 */
class Game {
public:
    /**
     * stav hry (WAITING nebo RUNNING)
     */
    string gameState;

    // Herní deska
    string arr[6][7];
    // Kontrola obsazených polí na herní desce
    int c1;
    int c2;
    int c3;
    int c4;
    int c5;
    int c6;
    int c7;

    int counter;
    /**
     * Přidá hráče do seznamu hráčů hry
     * @param pl
     */
    void addPlayer(Player *pl);

    /**
     * Odstraní hráče ze hry
     * @param pl
     */
    void removePlayer(Player *pl);

    /**
     * Plnost hry
     * @return true pokud ano, false pokud ne
     */
    bool isFull();

    /**
     * Prázdnost hry
     * @return true pokud ano, false pokud ne
     */
    bool isEmpty();

    /**
     * @return vektor hráčů ve hře (připojených i nepřipojených (v důsledku chyby připojení))
     */
    vector<Player *> getPlayers();

    /**
     * @return id hry
     */
    int getGameId();


    explicit Game(int gameId);

private:
    /**
     * Struktura pro hráče
     */
    vector<Player *> players;

    /**
     * Identifikace hry.
     */
    int gameId;


};


#endif
