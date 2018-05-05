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
    std::cout << "o -> Obrot o kat" << std::endl;
    std::cout << "w -> Ponowne wyswietlenie menu" << std::endl;
    std::cout << "z -> Zmiana szybkosci robota" << std::endl << std::endl;
    std::cout << "k -> Zakonczenie dzialania programu" << std::endl;
}

/*!
 * Jest jako jedyna, jawnie wywoływana w funkcji \e main. Inicjalizuje cały przebieg działania prgramu. Posiada
 * menu do komunikacji z użytkownikiem w postaci \e switch'a, który jest uodporniony na podanie opcji, która nie jest
 * obsługiwana.
 */
void Scena::Run()
{
    char znak;
    lacze.DodajNazwePliku("figury/robot.dat",PzG::RR_Ciagly,3);
    lacze.ZmienTrybRys(PzG::TR_2D);
    lacze.DodajNazwePliku("figury/sciezka.dat",PzG::RR_Ciagly,3);
    lacze.ZmienTrybRys(PzG::TR_2D);
    std::cout << std::endl << "---------------Centrum Sterowania Robotem--------------------" << std::endl << std::endl;
    R.InicjalizujKsztalt();
    WyswietlMenu();

    while(znak != 'k')
    {
        std::cin >> znak;

        switch(znak)
        {
        case 'j':
            int tmp;
            std::cout << "Podaj odleglosc (ilosc jednostek) na jaka ma sie przemiescic robot: \n";
            std::cin >> tmp;
            R.JedzProsto(tmp);
            break;

        case 'w':
            WyswietlMenu();
            break;

        case 'z':
            R.ZmienSzybkosc();
            break;

        case 'o':
            int tm;
            std::cout << "Podaj kat o jaki ma sie obrocic robot: \n";
            std::cin >> tm;
            R.obroc(tm);
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
