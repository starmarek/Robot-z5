#ifndef OBIEKTGRAFICZNY_HH
#define OBIEKTGRAFICZNY_HH


/*!
 * \file
 * \brief Definicja klasy ObiektGraficzny
 *
 * Plik zawiera definicję klasy ObiektGraficzny.
 */


#include "ZbiorWierzcholkow.hh"


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

static int ObAkt;

static int ObOgol;

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
     * \brief Przechowuje nazwe do zapisu do pliku.
     *
     * Przechowuje nazwe do zapisu danego robota lub przeszkody.
     */
    std::string Nazwa = "figury/";

    /*!
     * \brief Przechowuje nazwe do zapisu do pliku.
     *
     * Przechowuje nazwe do zapisu ścieżki, należącej do danego robota.
     */
    std::string NazwaSciezki = "figury/";

    double Promien;

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

    virtual bool Kolizja(Wektor2D wek, double r) { std:: cout << "To nie tak, bo bazowa!"; return 0; }

    ObiektGraficzny();

    ~ObiektGraficzny();

    ObiektGraficzny(const ObiektGraficzny &W);

    static void ZwrocOb()
    {
        std::cout << "Laczna ilosc stworzonych obiektow klasy ObiektGraficzny: " << ObOgol << std::endl;
        std::cout << "Ilosc nieusunietych obiektow klasy ObiektGraficzny: " << ObAkt << std::endl << std::endl;
    }

    virtual void DodajPrzeszkode1() { ; }
    virtual void DodajPrzeszkode2() { ; }
    virtual void DodajPrzeszkode3() { ; }
};

#endif
