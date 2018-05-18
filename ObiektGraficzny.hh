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
#include <memory>
#include <list>

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


    /*!
     * \brief Tablica wierzchołków
     *
     * Zawiera współrzędne wierzchołków obiektów graficznych.
     */


    /*!
     * \brief Przechowuje nazwe do zapisu do pliku.
     *
     * Przechowuje nazwe do zapisu danego robota lub przeszkody.
     */


    /*!
     * \brief Przechowuje nazwe do zapisu do pliku.
     *
     * Przechowuje nazwe do zapisu ścieżki, należącej do danego robota.
     */
    std::string NazwaSciezki = "figury/";



public:
std::string Nazwa = "figury/";
Wektor2D   _PolozenieObiektu;
ZbiorWierzcholkow _TabWierz;
double Promien;
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

    virtual bool Kolizja(ObiektGraficzny R) { std:: cout << "To nie tak, bo bazowa!"; return 0; }
};

#endif
