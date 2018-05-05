/*!
 *  \file
 *  \brief Zawiera definicje metod klasy ZbiorWierzcholkow.
 *
 *  Zawiera definicje metod klasy ZbiorWierzcholkow, wraz
 *  z ich opisem.
 */

#include "ZbiorWierzcholkow.hh"

/*!
 * Metoda Tworzy nowy obiekt klasy \e Wektor2D, oraz
 * dodaje do niego pobrane wartości. Następnie dziedziczoną
 * metodą \e push_back(), dodaje dany obiekt na początek tablicy \e vector.
 *
 * \param a - X'owa współrzędna wierzchołka
 * \param b - Y'owa współrzędna wierzchołka
 */
void ZbiorWierzcholkow::DodajWierzcholek(double a, double c)
    {
        Wektor2D nowy;
        nowy[0] = a;
        nowy[1] = c;
        push_back(nowy);
    }



