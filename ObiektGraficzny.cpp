/*!
 * \file
 * \brief Zawiera definicje metod klasy ObiektGraficzny
 *
 * Zawiera definicje metod klasy ObiektGraficzny
 * wraz z ich opisem.
 */

#include <fstream>
#include "ObiektGraficzny.hh"

int ObiektGraficzny::ObAkt;
int ObiektGraficzny::ObOgol;

/*!
 * Zapisuje do strumienia współrzędne globalne wierzchołków
 * obrysu obiektu.
 * \param[in,out] - strumień, do którego wpisane zostałe współrzędne
 *                  wierzchołków.
 * \retval true - gdy operacja powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
bool ObiektGraficzny::ZapiszDoStrumienia(std::ostream& StrmWy) const
{
    Wektor2D  W_glob;

    for (const Wektor2D&  W_lok : _TabWierz)
    {
        W_glob = W_lok + _PolozenieObiektu;
        StrmWy << W_glob << std::endl;
    }
    return !StrmWy.fail();
}

/*!
 * Do aktualnego wektora położenia dodaje wektor, który zmienia jego wartość
 * a zatem zmienia położenie robota.
 *
 * \param c - Wektor o który ma się zmienić położenie.
 */
void ObiektGraficzny::PoruszOWektor(Wektor2D c)
{
    _PolozenieObiektu[0] += c[0];
    _PolozenieObiektu[1] += c[1];
}

/*!
 * Zapisuje do pliku współrzędne globalne wierzchołków
 * obrysu obiektu.
 * \param[in,out] - strumień, do którego wpisane zostałe współrzędne
 *                  wierzchołków.
 * \retval true - gdy operacja powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
bool ObiektGraficzny::ZapiszDoPliku(const char* sNazwaPliku) const
{
    std::ofstream   StrmWy(sNazwaPliku);

    if (!StrmWy.is_open())
    {
        std::cerr << std::endl
             << "Blad: Otwarcie do zapisu pliku '" << sNazwaPliku
             << "' nie powiodlo sie." << std::endl
             << std::endl;
        return false;
    }
    return ZapiszDoStrumienia(StrmWy);
}

/*!
 * Dokumentuje stworzenie obiektu klasy ObiektGraficzny przez zwiększenie zmiennych statycznych
 * które przechowują informację o ich ilości.
 */
ObiektGraficzny::ObiektGraficzny()
{
    ++ObAkt;
    ++ObOgol;
}


/*!
 * Dokumentuje znieszczenie obiektu klasy ObiektGraficzny przez zmniejszenie zmiennej statycznej
 * która przechowuje informację o ilości obiektów aktualnie istniejących.
 */
ObiektGraficzny::~ObiektGraficzny()
{
    --ObAkt;
}
