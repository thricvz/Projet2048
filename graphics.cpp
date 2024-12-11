#include <SFML/Graphics.hpp>
#include"modele.hpp"
#include <vector>

int main()
{   
    //le plateau de jeu
    Plateau plateau_de_jeu = plateauInitial();
    // Création de la fenêtre
    sf::RenderWindow window(sf::VideoMode(800, 800), "2048");
    sf::Font font;
    // Limite de frame
    window.setFramerateLimit(60);
    font.loadFromFile("Roboto-Black.ttf");
    // Liste des carrés
    char touche;
    std::vector<sf::RectangleShape> squares;
    //liste des textes
    std::vector<sf::Text> textboxes;
    // Couleurs des carrés
    sf::Color colors[] = {sf::Color::Red, sf::Color::Green, sf::Color::Blue, sf::Color::Yellow};
    
    // Boucle principale
    while (window.isOpen() and !estTerminé(plateau_de_jeu)) {
        // Gestion des événements
        sf::Event event;
        touche = ' ';
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
                    case sf::Keyboard::Q:
                        touche = 'q';
                        break;
                    case sf::Keyboard::Z:
                        touche = 'z';
                        break;
                    case sf::Keyboard::D:
                        touche = 'd';
                        break;
                    case sf::Keyboard::S:
                        touche = 's';
                        break;
                    default:
                        break;
                }
            }
        }

        if(touche_valide(touche)){
            if(déplacement(plateau_de_jeu,touche_direction(touche)) != plateau_de_jeu){
                plateau_de_jeu = déplacement(plateau_de_jeu,touche_direction(touche));
                plateau_de_jeu = genere_nouvelle_case(plateau_de_jeu);
            }
        }
        squares.clear();
        textboxes.clear();

        //gere l'affichage du tableau
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(plateau_de_jeu[i][j]!=0){
                    sf::RectangleShape square(sf::Vector2f(200.f, 200.f));
                    sf::Text text;
                    square.setFillColor(sf::Color(50 *i, 100, 200));
                    square.setPosition(j*200.f, i*200.f);
                    //le texte
                    text.setFont(font);
                    text.setString(std::to_string(plateau_de_jeu[i][j])); // Set text to the value in the grid
                    text.setCharacterSize(50); // Font size
                    text.setFillColor(sf::Color::White);

                    // Center the text in the square
                    sf::FloatRect textBounds = text.getLocalBounds();
                    text.setPosition(
                        square.getPosition().x + (square.getSize().x - textBounds.width) / 2.f - textBounds.left,
                        square.getPosition().y + (square.getSize().y - textBounds.height) / 2.f - textBounds.top
                    );
                    textboxes.push_back(text);
                    squares.push_back(square);  
                }
            }   
        }

        window.clear();
        // effacer la fenêtre

        // Dessiner les carrés
        for (const auto& square : squares) {
            window.draw(square);
        }
        for (const auto& text : textboxes) {
            window.draw(text);
        }
        window.display();
        // Afficher le rendu

    }

    return 0;
}
