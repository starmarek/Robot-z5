/*!
 * \file
 * \brief Zawiera definicje metod klasy Scena, oraz funkcji inicjalizującej plik z wektorami aktualnymi.
 *
 * Zawiera definicje metod klasy Scena, oraz funkcji inicjalizującej plik z wektorami aktualnymi
 * wraz z ich opisem.
 */

#include "Scena.hh"

/*!
 * Wyświetla informację o możliwych wyborach obsługiwanych przez program. Dodatkowo przy
 * użyciu metody \e PokazWektory wyświetla informacje o ilości obiektów typu \e Wektor2D.
 */
void Scena::WyswietlMenu()
{
    Wektor2D::PokazWektory();
    std::cout << "j -> Jazda na wprost" << std::endl;
    std::cout << "s -> Zmiana wielkosci robota" << std::endl;
    std::cout << "o -> Obrot o kat" << std::endl;
    std::cout << "w -> Ponowne wyswietlenie menu" << std::endl;
    std::cout << "z -> Zmiana szybkosci robota" << std::endl << std::endl;
    std::cout << "k -> Zakonczenie dzialania programu" << std::endl;
}

void Scena::DodajRobota()
{
    std::shared_ptr <Robot> p(new Robot(&lacze));

    LRobotow.push_back(p);

    ++Rit;

    Rit->get()->InicjalizujKsztalt();
    Rit->get()->DodajRobota();

    std::shared_ptr <Robot> q(new Robot(&lacze));

    LRobotow.push_back(q);

    ++Rit;

    Rit->get()->InicjalizujKsztalt();
    Rit->get()->DodajRobota();

    std::shared_ptr <Robot> d(new Robot(&lacze));

    LRobotow.push_back(d);

    ++Rit;

    Rit->get()->InicjalizujKsztalt();
    Rit->get()->DodajRobota();

}

void Scena::DodajPrzeszkody()
{
    std::shared_ptr <Przeszkoda> p(new Przeszkoda(&lacze));

    LPrzeszkod.push_back(p);

    ++Pit;

    Pit->get()->DodajPrzeszkode1();

    std::shared_ptr <Przeszkoda> q(new Przeszkoda(&lacze));

    LPrzeszkod.push_back(q);

    ++Pit;

    Pit->get()->DodajPrzeszkode2();

    std::shared_ptr <Przeszkoda> d(new Przeszkoda(&lacze));

    LPrzeszkod.push_back(d);

    ++Pit;

    Pit->get()->DodajPrzeszkode3();
}

void Scena::JakiRobot()
{
    int ktory = std::distance(Rit, LRobotow.begin());
    std::cout << std::endl << "Numer aktualnie wybranego robota: "<< ++ktory << std::endl;
    std::cout << "Wspolrzedne srodka aktualnie wybranego robota:" << Rit->get()->ZwrocPolozenie() << std::endl << std::endl;
}

/*!
 * Jest jako jedyna, jawnie wywoływana w funkcji \e main. Inicjalizuje cały przebieg działania prgramu. Posiada
 * menu do komunikacji z użytkownikiem w postaci \e switch'a, który jest uodporniony na podanie opcji, która nie jest
 * obsługiwana.
 */
void Scena::Run()
{
    char znak;
    DodajRobota();
    DodajPrzeszkody();
    lacze.Rysuj();

    std::cout << std::endl << "---------------Centrum Sterowania Robotem--------------------" << std::endl << std::endl;
    WyswietlMenu();


    while(znak != 'k')
    {
        JakiRobot();
        std::cin >> znak;

        switch(znak)
        {
        case 'j':
            int tmp;
            std::cout << "Podaj odleglosc (ilosc jednostek) na jaka ma sie przemiescic robot: \n";
            std::cin >> tmp;
            Rit->get()->JedzProsto(tmp);
            break;

        case 'w':
            WyswietlMenu();
            break;

        case 'z':
            Rit->get()->ZmienSzybkosc();
            break;

        case 'o':
            int tm;
            std::cout << "Podaj kat o jaki ma sie obrocic robot: \n";
            std::cin >> tm;
            Rit->get()->obroc(tm);
            break;

        case 's':
            double a;
            std::cout << "Podaj wartosc do skalowania robota:  " << std::endl;
            std::cin >> a;
            Rit->get()->Skaluj(a);
            break;

        case 'g':

            break;

        default:
            if(znak == 'k')
            {
                std::cout << "Koniec dzialania programu, dziekuje za uzytkowanie! \n";
                exit(0);
            }
            else
            {
                std::cout << "Proszę wybrać odpowiednia opcje. \n";
            }
            break;
        }
    }
}
