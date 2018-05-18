/*!
 * \file
 * \brief Zawiera definicje metod klasy Robot.
 *
 * Zawiera definicje metod klasy Robot
 * wraz z ich opisem.
 */

#include "Robot.hh"

int Robot::Indeks;

/*!
 * Pobiera od użytkownika nową wartość szybkości i nadpisuje aktualną.
 */
void Robot::ZmienSzybkosc()
{
    double g;
    std::cout << "Prosze podac nowa szybkosc poruszania sie i obrotu dla robota: \n";
    std::cin >> g;
    szybkosc = g;
}

/*!
 * Obraca każdy wierzchołek robota w oparciu o wzór:
 *
 * |x' = x * cos(alpha) - y * sin(alpha)
 * |y' = x * sin(alpha) + y * cos(alpha)
 *
 * gdzie \e x i \e y to aktualne współrzędne wierzchołka,
 * \e x' i \e y' to współrzędne po przekształceniu a \e alpha
 * to kąt podany w radianach, o który chcemy obrócić dany wierzchołek.
 *
 * \param a - kąt o który chcemy obrócić robota, podany w stopniach.
 */
void Robot::Obrot(double a)
{
    double x, y;
    a *= M_PI/180;
    Alpha += a;



    for(unsigned int i = 0; i < _TabWierz.size(); ++i)
    {
        x = _TabWierz[i][0];
        y = _TabWierz[i][1];

        _TabWierz[i][0] = x*cos(a) - y*sin(a);
        _TabWierz[i][1] = x*sin(a) + y*cos(a);

    }
}

/*!
 * Wykonuje animację obrotu widoczną na scenie.
 * Wykrzystuje funkcję \e usleep z nagłówka \e <unistd.h>,
 * aby pętla \e for była opóźniona, co daje efekt wykonującej się animacji.
 * Metoda reaguje na zmiany szybkości, modyfikując ilość wykonanych skoków w pętli
 * co daje wizulany efekt zmieniającej się prędkość robota.
 *
 * \param b - kąt o który ma się obrócić robot podany w stopniach, potrzebny aby pętla
 * \e for wykonała odpowiednią ilość skoków.
 */
int Robot::obroc(double b)
{
    double tmp = b/szybkosc;

    for (int i = 0; i < tmp; ++i)
    {
        if(tmp - i < 1)
        {
            Obrot((tmp - i) * szybkosc);
            ZapiszDoPliku(Nazwa.c_str());
            wsklacze->Rysuj();
            usleep(40000);
            return 0;
        }

        Obrot(szybkosc);
        ZapiszDoPliku(Nazwa.c_str());
        wsklacze->Rysuj();
        usleep(40000);
    }
    return 0;
}

/*!
 * Tworzy wierzchołki robota o podanych współrzędnych.
 */
void Robot::InicjalizujKsztalt()
{
    _TabWierz.DodajWierzcholek(0, 0);
    _TabWierz.DodajWierzcholek(30, 0);
    _TabWierz.DodajWierzcholek(0, -30);
    _TabWierz.DodajWierzcholek(-30, -30);
    _TabWierz.DodajWierzcholek(-30, 30);
    _TabWierz.DodajWierzcholek(0, 30);
    _TabWierz.DodajWierzcholek(30, 0);

    ZapiszDoPliku(Nazwa.c_str());
}

/*!
 * Metoda zmieniająca położenie robota względem zadanego przez użytkownika punktu.
 * Dodatkowo inicjalizuje pierwszy punkt ścieżki oraz rysuje robota w programie
 * \e gnuplot.
 */
void Robot::DodajRobota()
{
    std::cout << "Podaj wspolrzedne srodka robota aby go stworzyc: " << std::endl;
    std::cin >> _PolozenieObiektu[0] >> _PolozenieObiektu[1];
    ZapiszDoPliku(Nazwa.c_str());
    sciezkowy.DodajPierwszyPunkt(_PolozenieObiektu[0], _PolozenieObiektu[1], NazwaSciezki);
}

/*!
 * W oparciu o odlegść na jaką ma się przemieścić robot, obliczą wektor przesunięcią
 * ze wzoru:
 *
 * |x' = cos(Alpha) * odleglosc
 * |y' = sin(Alpha) * odleglosc
 *
 * Gdzie \e x' i \e y' to współrzędne wektora przsunięcia a \e Alpha
 * to kąt o jaki jest aktualnie obrócony robot. Jako, że chcemy uzyskać wersor
 * dzielimy prawą stronę równana przez \e odlegosc, zatem zostaje sam \e cos i \e sin.
 * Następnie w pętli \e for, metoda dokonuje przesunięcia robota dzięki funkcji \e PoruszOWektor,
 * wraz z animcją, przy uzyciu funkcji \e usleep.
 *
 * \param dlugosc - ilosc jednostek na skali sceny, o które ma się przesunąć robot względem swojego
 * aktualnego położenia.
 */
int Robot::JedzProsto(double dlugosc, std::list < std::shared_ptr <ObiektGraficzny> > lista)
{
    Wektor2D wektorPrzemieszczenia;
    double tmp = dlugosc / szybkosc;

    wektorPrzemieszczenia[0] = cos(Alpha);
    wektorPrzemieszczenia[1] = sin(Alpha);

    for (unsigned int i = 0; i < tmp; ++i)
    {
        if(tmp - i < 1)
        {
           PoruszOWektor(wektorPrzemieszczenia * ((tmp - i) * szybkosc));
           ZapiszDoPliku(Nazwa.c_str());
           sciezkowy.RysujSciezke(_PolozenieObiektu, NazwaSciezki);
           wsklacze->Rysuj();
           usleep(40000);
           for(std::list < std::shared_ptr <ObiektGraficzny> > :: iterator it = lista.begin(); it != lista.end(); ++it)
            {
                if((*it)->Kolizja(*this))
                {
                    std::cout << "git w chuj";
                    return 0;
                }
            }
           return 0;
        }
        PoruszOWektor(wektorPrzemieszczenia * szybkosc);
        ZapiszDoPliku(Nazwa.c_str());
        sciezkowy.RysujSciezke(_PolozenieObiektu, NazwaSciezki);
        wsklacze->Rysuj();
        usleep(40000);
        for(std::list < std::shared_ptr <ObiektGraficzny> > :: iterator it = lista.begin(); it != lista.end(); ++it)
        {
            if((*it)->Kolizja(*this))
            {
                std::cout << "git w chuj";
                return 0;
            }
        }
    }
    return 0;
}

/*!
 * Zmienia wielkość robota względem skali podanej przez użytkownika. Metoda zawsze
 * najpierw uwzględnia aktualną skalę aby skalować robota przyjmując wartość podstawową
 * równą jeden.
 */
void Robot::Skaluj(double w)
{

    for(unsigned int i = 0; i < _TabWierz.size(); ++i)
    {
        _TabWierz[i][0] /= skala;
        _TabWierz[i][1] /= skala;
        _TabWierz[i][0] *= w;
        _TabWierz[i][1] *= w;
    }
    skala = w;
    ZapiszDoPliku(Nazwa.c_str());
    wsklacze->Rysuj();
}


Robot::Robot(PzG::LaczeDoGNUPlota * lacznik)
{
    wsklacze = lacznik;

    Promien = 30;

    ++Indeks;

    Nazwa += "Robot" + std::to_string(Indeks) + ".dat";

    NazwaSciezki += "Sciezka" + std::to_string(Indeks) + ".dat";

    wsklacze->DodajNazwePliku(Nazwa.c_str(), PzG::RR_Ciagly, 3);
    wsklacze->DodajNazwePliku(NazwaSciezki.c_str(), PzG::RR_Ciagly,2);
}

Wektor2D Robot::ZwrocPolozenie()
{
    return _PolozenieObiektu;
}

bool Robot::Kolizja(ObiektGraficzny R)
{
    double a = abs(_PolozenieObiektu[0] - R._PolozenieObiektu[0]);
    double b = abs(_PolozenieObiektu[1] - R._PolozenieObiektu[1]);
    double dist = sqrt(pow(a, 2) + pow(b, 2));

    if(dist == 0) { return false; }
    if(Promien + R.Promien >= dist) { return true; }

    return false;
}
