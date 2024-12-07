#include "modele.hpp"
#include <iostream>
using namespace std;

int main(){
    Plateau plateau_de_jeu = plateauInitial();
    char touche;
    while(!estTerminé(plateau_de_jeu)){
        cout << dessine(plateau_de_jeu);
        touche = ' ';
        while(!touche_valide(touche)){
            cout << "Entrez une touche(q,z,d,s): ";
            cin >> touche;
        }
        plateau_de_jeu = déplacement(plateau_de_jeu,touche_direction(touche));
        plateau_de_jeu = genere_nouvelle_case(plateau_de_jeu);

        if(estGagnant(plateau_de_jeu)){
            cout << "BRAVO VOUS AVEZ GAGNE" << endl;
            break;
        }

    }
    return 0; 
}