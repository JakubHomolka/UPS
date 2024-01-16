#ifndef RPS_SERVER_UTILS_H
#define RPS_SERVER_UTILS_H


#include <cstdio>
#include <iostream>
#include <vector>
#include <regex>

using namespace std;
/**
 * Používá se pro různé pomocné funkce
 */
class Utils {
public:
    /**
     * Rozdělí řetězec podle zadaného oddělovače
     * @param str řetězec
     * @param delim oddělovač ("|")
     * @return vektor částí
     */
    static vector<string> split(const string str, const string delim);

    /**
     * Ořeže whitespace ze řetězce
     * @param text řetězec
     * @return řetězec bez whitespace
     */
    static string trim(string text);

    /**
     * Ořeže whitespace ze řetězce z levé strany
     * @param text řetězec
     * @return řetězec bez whitespace
     */
    static string left_trim(string s);

    /**
     * Ořeže whitespace ze řetězce z pravé strany
     * @param text řetězec
     * @return řetězec bez whitespace
     */
    static string right_trim(string s);

    /**
     * Kontroluje, zda je řetězec složen pouze z písmen
     * @param s řetězec
     * @return true, pokud obsahuje pouze písmena, jinak false
     */
    static bool isAlpha(string s);
};


#endif
