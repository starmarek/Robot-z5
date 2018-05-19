/*!
 * \file
 * \brief Zawiera definicje metod klasy Scena.
 *
 * Zawiera definicje metod klasy Scena, wraz z ich opisem.
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
    std::cout << "g -> Selekcja robota" << std:: endl;
    std::cout << "z -> Zmiana szybkosci robota" << std::endl << std::endl;
    std::cout << "k -> Zakonczenie dzialania programu" << std::endl;
}

void Scena::DodajRoboty()
{
    std::shared_ptr <Robot> r(new Robot(&lacze));
    std::shared_ptr <ObiektGraficzny> ro(r);

    LRobotow.push_back(r);
    LObiektow.push_back(ro);

    ++Rit;
    ++Oit;

    (*Rit)->InicjalizujKsztalt();
    (*Rit)->DodajRobota1();

    std::shared_ptr <Robot> r1(new Robot(&lacze));
    std::shared_ptr <ObiektGraficzny> ro1(r1);

    LRobotow.push_back(r1);
    LObiektow.push_back(ro1);

    ++Rit;
    ++Oit;

    (*Rit)->InicjalizujKsztalt();
    (*Rit)->DodajRobota2();

    std::shared_ptr <Robot> r2(new Robot(&lacze));
    std::shared_ptr <ObiektGraficzny> ro2(r2);

    LRobotow.push_back(r2);
    LObiektow.push_back(ro2);

    ++Rit;
    ++Oit;

    (*Rit)->InicjalizujKsztalt();
    (*Rit)->DodajRobota3();

}

void Scena::DodajPrzeszkody()
{
    std::shared_ptr <ObiektGraficzny> p(new Przeszkoda(&lacze));

    LObiektow.push_back(p);

    ++Oit;

    (*Oit)->DodajPrzeszkode1();

    std::shared_ptr <ObiektGraficzny> p1(new Przeszkoda(&lacze));

    LObiektow.push_back(p1);

    ++Oit;

    (*Oit)->DodajPrzeszkode2();

    std::shared_ptr <ObiektGraficzny> p2(new Przeszkoda(&lacze));

    LObiektow.push_back(p2);

    ++Oit;

    (*Oit)->DodajPrzeszkode3();
}

void Scena::JakiRobot()
{
    int ktory = std::distance(LRobotow.begin(), Rit);
    std::cout << std::endl << std::endl << "Aktualnie wyselekscjonowanym robotem jest: "<< std::endl << "Robot " << ++ktory << ". \t";
    std::cout << "Wspolrzedne: " << (*Rit)->ZwrocPolozenie() << std::endl << std::endl;
}


void Scena::WyborRobota()
{
    unsigned int w;
    std::cout << std::endl << "Aktualnie aktywne roboty: " << std::endl;
    Rit = LRobotow.begin();

    for(unsigned int i = 1; i <= LRobotow.size(); ++i)
    {
        std::cout << "Robot " << i << "\t Wspolrzedne: " << (*Rit)->ZwrocPolozenie() << std::endl;
        if ((Rit != LRobotow.end()) && (next(Rit) == LRobotow.end())) break;
        Rit++;
    }

    std::cout << "Prosze wybrac robota: " << std::endl;
    std::cin >> w;
    Rit = LRobotow.begin();

    for(unsigned int i = 1; i < w; ++i)
    {
        ++Rit;
    }
}


/*!
 * Jest jako jedyna, jawnie wywoływana w funkcji \e main. Inicjalizuje cały przebieg działania prgramu. Posiada
 * menu do komunikacji z użytkownikiem w postaci \e switch'a, który jest uodporniony na podanie opcji, która nie jest
 * obsługiwana.
 */


void Scena::Menu()
{
    char znak;
    std::cout << std::endl << "---------------Centrum Sterowania Robotem--------------------" << std::endl << std::endl;
    WyswietlMenu();
    do
    {
        JakiRobot();
        std::cout << "Twój wybór> ";
        std::cin >> znak;
        std::cout << "\n";

        switch(znak)
        {
        case 'j':
            int tmp;
            std::cout << "Podaj odleglosc (ilosc jednostek) na jaka ma sie przemiescic robot: \n";
            std::cin >> tmp;
            (*Rit)->JedzProsto(tmp, LObiektow);
            break;

        case 'w':
            WyswietlMenu();
            break;

        case 'z':
            (*Rit)->ZmienSzybkosc();
            break;

        case 'o':
            int tm;
            std::cout << "Podaj kat o jaki ma sie obrocic robot: \n";
            std::cin >> tm;
            (*Rit)->obroc(tm);
            break;

        case 's':
            double a;
            std::cout << "Podaj wartosc do skalowania robota:  " << std::endl;
            std::cin >> a;
            (*Rit)->Skaluj(a);
            break;

        case 'g':
            WyborRobota();
            break;

        default:
            if(znak == 'k')
            {
                std::cout << "Koniec dzialania programu, dziekuje za uzytkowanie! \n";
                return;
            }
            else
            {
                std::cout << "Proszę wybrać odpowiednia opcje. \n";
            }
            break;
        }
    }while(znak != 'k');

}


void Scena::Run()
{
    DodajRoboty();
    DodajPrzeszkody();
    lacze.Rysuj();
    Menu();
}
