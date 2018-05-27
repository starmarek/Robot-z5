#ifndef FABRYKAOG_HH
#define FABRYKAOG_HH

/*!
 * \file
 * \brief Definicja klasy Fabryka
 *
 * Plik zawiera definicję klasy Fabryka
 */

#include "Robot.hh"
#include "Przeszkoda.hh"

/*!
 * \brief Modeluje obiekt tworzący inne obiekty.
 *
 * Fabryka jest zaprojektowana według wzorca \e singletonu. Jej obiekt jest wykorzystywany aby tworzyć roboty i przeszkody.
 */
class Fabryka
{

   /*!
    * Przechowuje jedyny obiekt fabryki w tym programie.
    */
    static Fabryka fab;

    /*!
     * Konstruktor umieszczony w sekcji \e private aby zapobiec przypadkowemu tworzeniu się obiektów tej klasy.
     */
    Fabryka() { }

    /*!
     * Konstruktor umieszczony w sekcji \e private aby zapobiec przypadkowemu tworzeniu się obiektów tej klasy.
     */
    Fabryka(const Fabryka &) { }

public:

    /*!
     * Wywołuje metode \e dodajObiekt na obiekcie fabryki.
     */
    static std::shared_ptr < ObiektGraficzny > Buduj(int w, PzG::LaczeDoGNUPlota * dupa) { return fab.dodajObiekt(w, dupa); }

    /*!
     * \brief Tworzy nową przeszkodę lub robota.
     */
    std::shared_ptr < ObiektGraficzny > dodajObiekt(int w, PzG::LaczeDoGNUPlota * dupa);

};

#endif
