#ifndef ZBIORWIERZCHOLKOW_HH
#define ZBIORWIERZCHOLKOW_HH
#include <fstream>

/*!
 * \file
 * \brief Definicja klasy ZbiorWierzcholkow.
 *
 * Plik zawiera definicję klasy ZbiorWierzcholkow.
 */

#include "Wektor2D.hh"
#include "lacze_do_gnuplota.hh"

/*!
 * \brief Modeluje kontener do którego są wrzucane wierzchołki obiektów.
 *
 * Klasa bezpośrednio dziedziczy po \e std::vector<Wektor2D> zatem jest to kontener
 * do którego wrzucamy obiekty typu \e Wektor2D, czyli wierzchołki o dwóch współrzędnych.
 */
class ZbiorWierzcholkow : public std::vector<Wektor2D>
{

public:

    /*!
     * \brief Metoda dodająca nowy wierzchołek do kontenera.
     */
    void DodajWierzcholek(double a, double c);

};

#endif
