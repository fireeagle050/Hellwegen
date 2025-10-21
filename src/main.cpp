#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    // Utwórz okno aplikacji
    sf::RenderWindow window(sf::VideoMode(800, 600), "Hellwegen");

    // Wczytaj teksturę tła
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("assets/main_background.png"))
    {
        std::cerr << "Błąd: Nie można wczytać pliku tła 'assets/main_background.png'" << std::endl;
    }

    sf::Sprite backgroundSprite(backgroundTexture);

    // Główna pętla aplikacji
    while (window.isOpen())
    {
        // Obsługa zdarzeń
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // Czyszczenie okna (ustawia czarne tło domyślnie)
        window.clear(sf::Color::Black);

        // Rysowanie tła
        window.draw(backgroundSprite);

        // Wyświetlanie zawartości okna
        window.display();
    }

    return 0;
}