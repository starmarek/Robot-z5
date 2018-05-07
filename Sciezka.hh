#ifndef SCIEZKA_HH
#define SCIEZKA_HH

/*!
 * \file
 * \brief Definicja klasy Sciezka.
 *
 * Plik zawiera definicję klasy Scieza.
 */

#include "ObiektGraficzny.hh"

/*!
 * \brief Modeluje linię ciągnącą się za robotem.
 *
 * Klasa modeluje linię, czyli zbiór punktów które są łączone w programie gnuplot.
 */
class Sciezka : public ObiektGraficzny
{

public:

    /*!
     * \brief Konstruktor inicjalizujący pierwszy punkt linii.
     */
    void DodajPierwszyPunkt(double a, double b);

    /*!
     * \brief Funkcja rysująca linie
     */
    void RysujSciezke(Wektor2D pol);
};

#endif
