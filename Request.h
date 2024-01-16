#ifndef RPS_SERVER_REQUEST_H
#define RPS_SERVER_REQUEST_H


#include <cstdio>
#include <vector>
#include "Player.h"
#include "ClientManager.h"
#include "GameManager.h"
#include "Utils.h"

/**
 * Používá se pro zpracování uživatelských požadavků
 */
class Request {
public:
    /**
     * Zpracuje uživatelský požadavek podle jeho zprávy a identifikace hráče
     * @param pl identifikace hráče
     * @param msg zpráva
     */
    static void resolve(Player *pl, std::string msg);
};


#endif
