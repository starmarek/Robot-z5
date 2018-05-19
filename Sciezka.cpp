/*!
 * \file
 * \brief Zawiera definicje metod klasy Sciezka.
 *
 * Zawiera definicje metod klasy Sciezka
 * wraz z ich opisem.
 */

#include "Sciezka.hh"

/*!
 * Dodaje wektor do tablicy \e _TabWierz
 * a następnie zapisuje go do osobnego pliku.
 *
 * \param a - X'owa współrzędna wektora.
 * \param b - Y'owa współrzędna wektora.
 * \param g - Nazwa pliku do którego należy zapisać punkt.
 */
void Sciezka::DodajPierwszyPunkt(double a, double b, std::string g)
{
    _TabWierz.DodajWierzcholek(a, b);
    ZapiszDoPliku(g.c_str());
}

/*!
 * Zapisuje do pliku kolejny punkt linii.
 *
 * \param pol - Współrzędne kolejnego punktu linii, podane na podstawie
 * aktualnego położenia robota.
 * \param g - Nazwa pliku do którego należy zapisać punkt.
 */
void Sciezka::RysujSciezke(Wektor2D pol, std::string g)
{
    _TabWierz.DodajWierzcholek(pol[0], pol[1]);
    ZapiszDoPliku(g.c_str());
}
