#include "modele.hpp"
#include <iostream>
using namespace std;

int main(){
    Plateau plateu_de_jeu = plateauInitial();
    char touche;
    while(!estTerminé(plateu_de_jeu)){
        cout << dessine(plateu_de_jeu);
        touche = ' ';
        while(!touche_valide(touche)){
            cout << "Entrez une touche(q,z,d,s): ";
            cin >> touche;
        }
        plateu_de_jeu = déplacement(plateu_de_jeu,touche_direction(touche));
        plateu_de_jeu = genere_nouvelle_case(plateu_de_jeu);

        if(estGagnant(plateu_de_jeu)){
            cout << "BRAVO VOUS AVEZ GAGNE" << endl;
            break;
        }

    }
    return 0; 
}