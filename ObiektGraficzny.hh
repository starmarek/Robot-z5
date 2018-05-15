#ifndef OBIEKTGRAFICZNY_HH
#define OBIEKTGRAFICZNY_HH

/*!
 * \file
 * \brief Definicja klasy ObiektGraficzny
 *
 * Plik zawiera definicję klasy ObiektGraficzny.
 */

#include "ZbiorWierzcholkow.hh"
#include "lacze_do_gnuplota.hh"

/*!
 * \brief Modeluje obiekt, który ma swoją reprezentację graficzną
 *
 * Modeluje obiekt, który ma swoją reprezentację graficzną
 * w postaci łamanej. Może ona być łamaną zamkniętą w postaci
 * wieloboku lub otwartą. Ilość jej wierzchołków nie jest jawnie
 * ograniczona. Jedynym ograniczeniem jest dostępność pamięci
 * komputera.
 */
class ObiektGraficzny
{

protected:

    /*!
     * \brief Współrzędne pozycji obiektu
     *
     *  Zawiera współrzędne punktu względem, którego podane są
     *  współrzędne punktów obrysu obiektu.
     */
    Wektor2D   _PolozenieObiektu;

    /*!
     * \brief Tablica wierzchołków
     *
     * Zawiera współrzędne wierzchołków obiektów graficznych.
     */
    ZbiorWierzcholkow _TabWierz;

    /*!
     * Przechowuje kąt o jaki jest aktualnie obrócony obikekt.
     */

    int Indeks = 0;

    std::string Nazwa = "figury/";

    std::string NazwaSciezki = "figury/";

public:

    /*!
     * \brief Metoda zmieniająca aktualne położenie obiektu
     */
    void PoruszOWektor(Wektor2D c);

    /*!
     * \brief Metoda zapisuje do pliku współrzędne wierzchołków
     */
    bool ZapiszDoPliku(const char* sNazwaPliku) const;

    /*!
     * \brief Metoda zapisuje do strumienia współrzędne wierzchołków
     */
    bool ZapiszDoStrumienia(std::ostream& StrmWy) const;
};

#endif
