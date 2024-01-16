#ifndef RPS_SERVER_PLAYER_H
#define RPS_SERVER_PLAYER_H

#include <cstdio>
#include <iostream>

using namespace std;

/**
 * Reprezentace hráče
 */
class Player {
public:
    /**
     * IP adresa hráče, používána pro ladění
     */
    char *ip;
    /**
     * ID socketu pro komunikaci
     */
    int socket;
    /**
     * ID aktuálně zapojené hry
     */
    int game_id;
    /**
     * tah ve hře (sloupec 1-7)
     */
    int game_move;

    /**
     * Udává kdo je na řadě (1 - je, 0 - není)
     */
    int prioriti;
    /**
     * Pokud je hráč připojen = 1, pokud ne = -1
     */
    int connected;

    /**
     * Používá se pro validaci uživatelského vstupu. Po 3 neplatných zprávách je hráč odpojen
     */
    int invalid_message_counter;

    /**
     * Používá se pro udávání zda hráč dohrál hru
     */
    int end;

    /**
     * Používá se pro počítání missnutých pingů
     */
    int ping_counter;

    /**
     * Symbol hráče
     */
    string mark;

    /**
     * Jméno hráče
     */
    string name;

    /**
     * Poslední zpráva odeslaná hráčem, používána pro ladění
     */
    string msg_in;

    /**
     * Poslední odpověď odeslaná hráči, používána pro ladění
     */
    string msg_out;

    /**
     * Stav hráče: NEW, LOBBY, INGAME, WAITING, END
     */
    string state;

    /**
     * Player state CONN, DISCON
     */
    string state1;

    /**
     * Konstruktor třídy Player
     * @param ip IP adresa hráče
     * @param socket ID socketu pro komunikaci s hráčem
     */
    Player(char *ip, int socket);

    /**
     * Destruktor třídy Player
     */
    ~Player();

    /**
    * Nastaví nové jméno hráče
    * @param new_name Nové jméno hráče
    */
    void set_name(string new_name) { name = new_name; };
};


#endif
