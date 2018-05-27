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

   /*!
    * \brief Wykonuje podstawowe czynności przy stworzeniu obiektu typu Przeszkoda.
    */
    Przeszkoda(PzG::LaczeDoGNUPlota * lacznik);

   /*!
    * Konstruktor przeniesiony do sekcji \e private aby zapobiec przypadkowemu tworzeniu sie obiektow tej klasy.
    */
    Przeszkoda(const Przeszkoda &) { };

public:

   /*!
    * Metoda umożliwiająca tworzenie obiektów klasy \e Przeszkoda, zwracajaca wskaźnik na nowo
    * utworzony obiekt.
    */
    static Przeszkoda* stworz(PzG::LaczeDoGNUPlota * lacznik) { return new Przeszkoda(lacznik); }

   /*!
    * \brief Tworzy nową przeszkodę.
    */
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
     * \brief Wykrywa kolizję robota z przeszkodą
     */
     bool Kolizja(Wektor2D wek, double r);
};

#endif
