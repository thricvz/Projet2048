#include <SFML/Graphics.hpp>
#include <vector>
#include "modele.hpp"
#include <iostream>

// Function to get the color based on the case_value (2048 game original colors)
sf::Color get_color(int case_value) {
    switch (case_value) {
        case 0: return sf::Color(255,255,255);
        case 2:    return sf::Color(238, 228, 218);  // Light beige
        case 4:    return sf::Color(237, 224, 200);  // Light yellowish beige
        case 8:    return sf::Color(242, 177, 121);  // Light orange
        case 16:   return sf::Color(245, 149, 99);   // Orange
        case 32:   return sf::Color(246, 124, 59);   // Dark orange
        case 64:   return sf::Color(246, 94, 59);    // Red-orange
        case 128:  return sf::Color(237, 207, 114);  // Yellow
        case 256:  return sf::Color(237, 204, 97);   // Light yellow
        case 512:  return sf::Color(237, 200, 80);   // Light yellow
        case 1024: return sf::Color(237, 195, 47);   // Dark yellow
        case 2048: return sf::Color(237, 190, 25);   // Gold
        default:   return sf::Color(204, 192, 179);  // Default (gray for higher values)
    }
}

int main() {
    // Create a window with size 800x600
    sf::RenderWindow window(sf::VideoMode(400, 400), "Draw 5 Rectangles");

    // Create an array of 5 rectangles
    std::vector<sf::RectangleShape>rectangles;
    std::vector<sf::Text> textboxes;
    Plateau plateau_de_jeu = plateauInitial();
    char touche;
    sf::Font font;
    if (!font.loadFromFile("Roboto-Black.ttf")) {
        // Error loading font
        return -1;
    }
    // Define properties for each rectangle

    // Main loop to keep the window open
    while (window.isOpen() and !estTerminé(plateau_de_jeu)) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();  // Close window if the event is a close
            }
        }

        // Clear the screen with a black color
        window.clear(sf::Color::Black);
        for (int i = 0; i < 4;i++) {
            for(int j=0;j<4;j++){
                // Set size and position for each rectangle
                if(plateau_de_jeu[i][j]!=0){
                    sf::RectangleShape rect;
                    rect.setSize(sf::Vector2f(100.f, 100.f)); // width: 100, height: 50
                    rect.setFillColor(get_color(plateau_de_jeu[i][j]));      // set the color to green
                    rect.setPosition(100.f * j, 100.f*i);      // position each rectangle in a row
                    sf::Text text(std::to_string(plateau_de_jeu[i][j]), font, 24);  // Text content and font size
                    text.setFillColor(sf::Color::White);
                    // Position the text inside the rectangle
                    // Center the text within the rectangle
                    sf::FloatRect textBounds = text.getLocalBounds();
                    text.setOrigin(textBounds.width / 2.f, textBounds.height / 2.f); // Set origin to center of the text
                    text.setPosition(rect.getPosition().x + rect.getSize().x / 2.f, 
                    rect.getPosition().y + rect.getSize().y / 2.f);

                    rectangles.push_back(rect);
                    textboxes.push_back(text);     

                }
            }
        }
        // Draw each rectangle
        for (auto rect:rectangles) {
            window.draw(rect);
        }
        for (auto text:textboxes) {
            window.draw(text);
        }


        // Display the contents of the window
        window.display();
        textboxes.clear();
        rectangles.clear();
        touche = ' ';
        while(!touche_valide(touche)){
            std::cout << "Entrez une touche(q,z,d,s): ";
            std::cin >> touche;
        }
        plateau_de_jeu = déplacement(plateau_de_jeu,touche_direction(touche));
        plateau_de_jeu = genere_nouvelle_case(plateau_de_jeu);

        if(estGagnant(plateau_de_jeu)){
            std::cout << "BRAVO VOUS AVEZ GAGNE" << endl;
            break;
        }

    }

    return 0;
}


