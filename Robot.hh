#ifndef ROBOT_HH
#define ROBOT_HH

/*!
 * \file
 * \brief Definicja klasy Robot.
 *
 * Plik zawiera definicję klasy Robot.
 */

#include <math.h>
#include <unistd.h>
#include "ObiektGraficzny.hh"
#include "lacze_do_gnuplota.hh"
#include "Sciezka.hh"

/*!
 * \brief Modeluje Robota którym będziemy poruszać po scenie.
 *
 * Modeluje Robota, czyli jego kształt, cechy, jego własną scieżkę,
 * oraz wszystkie czynności, które może wykonać.
 */
class Robot : public ObiektGraficzny
{
    /*!
     * \brief Skala wielkości robota.
     *
     * Odzwierciedla wielkość robota, przyjmując wartość wyjściową równą jeden.
     */
    double skala = 1;

    /*!
     * \brief Zmienna potrzebna do komunikacji z programem \e gnuplot.
     *
     * Dzięki tej zmiennej możemy rysować na bierząco robota i  ścieżke
     * w programie \e gnuplot.
     */
    PzG::LaczeDoGNUPlota * wsklacze;

    /*!
     * \brief Osobista ścieżka danego robota.
     *
     * Zmienna dzięki której możemy rysować ścieżkę podczas ruchu robota.
     */
    Sciezka sciezkowy;

    /*!
     * \brief Osobista szybkosc animacji danego robota.
     *
     * Zmienna dzięki, której możemy modyfikować opóźnienie w pętlach odpowiedzialnych
     * za animację obrotu/ruchu. Wyjściowo jest ustawiona na 1, czyli jest to wartość
     * neutralna.
     */
    double szybkosc = 1;

    double Alpha;

    static int Indeks;

public:

    Robot(PzG::LaczeDoGNUPlota * lacznik);

    /*!
     * \brief Metoda zmieniająca szybkosc robota.
     */
    void ZmienSzybkosc();

    /*!
     * \brief Metoda obracająca robota o podany kąt.
     */
    void Obrot(double a);

    /*!
     * \brief Metoda odpowiadająca za realny obrót, to jest, animację.
     */
    int obroc(double b);

    /*!
     * \brief Metoda inicjalizująca robota na scenie.
     */
    void InicjalizujKsztalt();

    /*!
     * \brief Metoda przemieszczająca robota na podaną odległość,
     *  posiadająca już wbudowaną animację.
     */
    int JedzProsto(double dlugosc);

    /*!
     * \brief Metoda skalująca robota.
     */
    void Skaluj(double w);

    /*!
     * \brief Metoda wyświetlająca robota w zadanym przez użytkownika położeniu.
     */
    void DodajRobota();

    Wektor2D ZwrocPolozenie();
};

#endif
