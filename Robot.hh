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
#include <memory>
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
     * \brief Wskaznik na lacze.
     *
     * Służy do komunikacji z polem 'lacze' w klasie Scena.
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

    /*!
     * \brief Zmienna przechowująca kąt obrotu.
     *
     * Przechowuje informację o jaki kąt jest aktualnie obrócony robot.
     */
    double Alpha;

    /*!
     * \brief Zmienna indeksująca roboty.
     *
     * Zmienna służąca do indeksowania plików do zapisu robotów.
     */
    static int Indeks;

    /*!
     * \brief Zmienna przechowująca aktualną długość promienia robota.
     *
     * Podczas wykrywania kolizji przyjmuje się że na robocie da się opisać okrąg, którego promień
     * jest przechowywany właśnie w tej zmiennej.
     */
    double Promien;

    /*!
     * \brief Wykonuje podstawowe czynności przy stworzeniu obiektu typu Robot.
     */
    Robot(PzG::LaczeDoGNUPlota * lacznik);

    Robot(const Robot &) { };


public:

    static Robot* dodajtypa(PzG::LaczeDoGNUPlota * lacznik)
    {
        return new Robot(lacznik);
    }

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
    void obroc(double b);

    /*!
     * \brief Metoda inicjalizująca robota na scenie.
     */
    void InicjalizujKsztalt();

    /*!
     * \brief Metoda przemieszczająca robota na podaną odległość,
     *  posiadająca już wbudowaną animację, i detekcję kolizji.
     */
    void JedzProsto(double dlugosc, std::list < std::shared_ptr <ObiektGraficzny> > lista);

    /*!
     * \brief Metoda skalująca robota.
     */
    void Skaluj(double w);

    /*!
     * \brief Metoda dodająca robota w zadanym położeniu.
     */
    void DodajRobota1();

    /*!
     * \brief Metoda dodająca robota w zadanym położeniu.
     */
    void DodajRobota2();

    /*!
     * \brief Metoda dodająca robota w zadanym położeniu.
     */
    void DodajRobota3();

    /*!
     * \brief Zwraca aktualny wektor położenia robota.
     */
    Wektor2D ZwrocPolozenie();

    /*!
     * \brief Wykrywa kolizję robota z robotem.
     */
    bool Kolizja(Wektor2D wek, double r);

    /*!
     * \brief Metoda wykrywająca wszystkie kolizję w podanej liście Obiektów graficznych.
     */
    bool DetekcjaKol(std::list < std::shared_ptr <ObiektGraficzny> > lista);
};

#endif
