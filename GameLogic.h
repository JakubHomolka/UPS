#ifndef RPS_SERVER_GAMELOGIC_H
#define RPS_SERVER_GAMELOGIC_H


#include "Game.h"
/**
 * Používá se pro pravidla hry
 */
class GameLogic {
public:
    /**
     * Vloží žeton do herního pole
     * @param x sloupec pro vložení
     * @param game ukazatel na objekt hry
     * @return int
     */
    static int insert(int x, Game *game);

    /**
     * Kontrola výhry hráče v řadě
     * @param a řádek
     * @param m symbol hráče
     * @param game ukazatel na objekt hry
     * @return true pokud vyhrál, jinak false
     */
    static bool win_p1_row (int a, string m, Game *game);

    /**
     * Kontrola výhry hráče na jedné diagonále
     * @param a řádek
     * @param b sloupec
     * @param m symbol hráče
     * @param game ukazatel na objekt hry
     * @return true pokud vyhrál, jinak false
     */
    static bool win_p1_dai1 (int a , int b, string m, Game *game);

    /**
     * Kontrola výhry hráče na druhé diagonále
     * @param a řádek
     * @param b sloupec
     * @param m symbol hráče
     * @param game ukazatel na objekt hry
     * @return true pokud vyhrál, jinak false
     */
    static bool win_p1_dai2 (int a , int b, string m, Game *game);

    /**
     * Kontrola výhry hráče ve sloupci
     * @param a sloupec
     * @param m symbol hráče
     * @param game ukazatel na objekt hry
     * @return true pokud vyhrál, jinak false
     */
    static bool win_p1_col (int a, string m, Game *game);

    /**
     * Vloží žeton na herní desku
     * @param a řádek
     * @param b sloupec
     * @param x symbol hráče
     * @param game ukazatel na objekt hry
     */
    static void insertboard(int a, int b, string x, Game *game);

    /**
     * Logika pro vyhodnocování hry Connect 4
     * @param game ukazatel na objekt hry
     * @param pl ukazatel na hráče
     * @return int
     */
    static int Connect4(Game *game, Player *pl);
};


#endif
