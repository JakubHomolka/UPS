#ifndef RPS_SERVER_GAMEMANAGER_H
#define RPS_SERVER_GAMEMANAGER_H

#include <queue>
#include <map>
#include <cstdio>
#include <vector>
#include "Player.h"
#include "Game.h"
#include "Response.h"
#include "GameLogic.h"

using namespace std;
/**
 * Spravuje hry
 */
class GameManager {
public:
    /**
     * Mapa běžících her (které byly spuštěny)
     */
    static map<int, Game *> runningGames;
    /**
     * Fronta hráčů, používána pro párování hráčů
     */
    static queue<Game *> waitingGames;
    /**
     * ID generátoru her. Začíná od 1
     */
    static int idOfNextGame;

    /**
     * Nastaví hráče jako připraveného k hře. Najde hru pro hráče.
     * @param pl
     */
    static void playerEnqueue(Player *pl);

    /**
     * Hráč opustí čekací frontu
     * @param pl
     */
    static void playerDequeue(Player *pl);

    /**
     * Spustí hru
     * @param pl hráč, který hru spouští
     */

    static void startGame(Player *pl);

    /**
     * Tah hráče (tah ve hře)
     * @param pl
     * @param option sloupec (1-7)
     */
    static void turn(Player *pl, int option);

    /**
     * Hráč opouští hru a informuje ostatní hráče
     * @param pl
     */
    static void playerLeaveGame(Player *pl);

    /**
     * Odesílá informace oponentovi ve hře o stavu hráče.
     * @param pl
     * @param message
     */
    static void notifyOponent(Player *pl, string message);

    /**
     * Pokud hra existuje, vrátí na ni ukazatel
     * @param gameId
     * @return ukazatel na hru
     */
    static Game *gameExists(int gameId);
};


#endif
