#ifndef PRZESZKODA_HH
#define PRZESZKODA_HH

/*!
 * \file
 * \brief Definicja klasy Przeszkoda.
 *
 * Plik zawiera definicję klasy Przeszkoda.
 */

#include "ObiektGraficzny.hh"
#include <cmath>

/*!
 * \brief Modeluje przeszkode utworzoną w przestrzeni sceny.
 *
 * Przeszkoda powinna być wielokątem zamkniętym. Jej sęs istnienia jest taki
 * aby blokować robotowi drogę i stwarzać możliwości kolizji.
 */
class Przeszkoda : public ObiektGraficzny
{

    /*!
     * \brief Wskaznik na lacze.
     *
     * Służy do komunikacji z polem 'lacze' w klasie Scena.
     */
    PzG::LaczeDoGNUPlota * wsklacze;


    /*!
     * \brief Zmienna indeksująca przeszkody.
     *
     * Zmienna służąca do indeksowania plików do zapisu przeszkód.
     */
    static int Indeks;

    Przeszkoda(PzG::LaczeDoGNUPlota * lacznik);

    Przeszkoda(const Przeszkoda &) { };

public:

    static Przeszkoda* stworz(PzG::LaczeDoGNUPlota * lacznik)
    {
        return new Przeszkoda(lacznik);
    }

    void DodajPrzeszkode();

   /*!
    * \brief Inicjalizajca przeszkody numer 1.
    */
    void DodajPrzeszkode1();


   /*!
    * \brief Inicjalizajca przeszkody numer 2.
    */
    void DodajPrzeszkode2();


   /*!
    * \brief Inicjalizajca przeszkody numer 3.
    */
    void DodajPrzeszkode3();


    /*!
     * \brief Wykonuje podstawowe czynności przy stworzeniu obiektu typu Przeszkoda.
     */


    /*!
     * \brief Wykrywa kolizję robota z przeszkodą
     */
     bool Kolizja(Wektor2D wek, double r);
};

#endif
