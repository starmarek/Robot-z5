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

/*!
 * Zmienna zliczająca aktualnie istniejące obiketu typu ObiektGraficzny.
 */
static int ObAkt;

/*!
 * Zmienna zliczająca ogólnie stworzone obiekty typu ObiektGraficzny.
 */
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

    /*!
     * Metoda detekcji kolizji nie mająca żadnego zastosowania w klasie bazowej.
     */
    virtual bool Kolizja(Wektor2D wek, double r) { std:: cout << "To nie tak, bo bazowa!"; return 0; }

    /*!
     * \brief Customowy konstruktor klasy ObiektGraficzny.
     */
    ObiektGraficzny();

    /*!
     * \brief Customowy destruktor klasy ObiektGraficzny.
     */
    ~ObiektGraficzny();

    /*!
     * Wyświetla aktualnie istniejącą i ogólnie stworzoną ilość obiektów graficznych. Metoda napisana
     * z myślą aby przetestować na koniec działania programu czy nie powstały żadne wycieki pamięci.
     */
    static void ZwrocOb()
    {
        std::cout << "\n\nLaczna ilosc stworzonych obiektow klasy ObiektGraficzny: " << ObOgol << std::endl;
        std::cout << "Ilosc nieusunietych obiektow klasy ObiektGraficzny: " << ObAkt << std::endl << std::endl;
    }

    /*!
     * Metoda tworząca przeszkodę, nie mająca żadnego zastosowania w klasie bazowej.
     */
    virtual void DodajPrzeszkode1() { ; }

    /*!
     * Metoda tworząca przeszkodę, nie mająca żadnego zastosowania w klasie bazowej.
     */
    virtual void DodajPrzeszkode2() { ; }

    /*!
     * Metoda tworząca przeszkodę, nie mająca żadnego zastosowania w klasie bazowej.
     */
    virtual void DodajPrzeszkode3() { ; }
};

#endif
