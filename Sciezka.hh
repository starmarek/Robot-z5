#ifndef SCIEZKA_HH
#define SCIEZKA_HH

/*!
 * \file
 * \brief Definicja klasy Sciezka.
 *
 * Plik zawiera definicję klasy Sciezka.
 */

#include "ObiektGraficzny.hh"

/*!
 * \brief Modeluje linię ciągnącą się za robotem.
 *
 * Klasa modeluje linię, czyli zbiór punktów które są łączone w programie \e gnuplot.
 */
class Sciezka : public ObiektGraficzny
{

public:

    /*!
     * \brief Inicjalizuje pierwszy punkt linii.
     */
    void DodajPierwszyPunkt(double a, double b, std::string g);

    /*!
     * \brief Metoda rysująca linię.
     */
    void RysujSciezke(Wektor2D pol, std::string g);
};

#endif
