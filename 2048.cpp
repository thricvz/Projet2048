#include "modele.hpp"
#include <curses.h>
#include <iostream>
using namespace std;


int main(){
    //demarre n_curses
    initscr();
    keypad(stdscr, TRUE);

    Plateau plateau_de_jeu = plateauInitial();
    char touche;
    while(!estTerminé(plateau_de_jeu)){
        clear();
        mvprintw(2, 0, dessine(plateau_de_jeu).c_str());
        mvprintw(6, 0, "Entrez une touche(q,z,d,s): ");
        touche = ' ';
        touche = getch();
        //transforme les fleches a l'équivalent des touches normales
        if(touche_valide(touche)){
            if(déplacement(plateau_de_jeu,touche_direction(touche)) != plateau_de_jeu){
                plateau_de_jeu = déplacement(plateau_de_jeu,touche_direction(touche));
                plateau_de_jeu = genere_nouvelle_case(plateau_de_jeu);
            }
        }

        if(estGagnant(plateau_de_jeu)){
            clear();
            mvprintw(2, 0, "BRAVO VOUS AVEZ GAGNE");
            refresh();
            napms(5000);
            break;
        }
        refresh();
    }
    clear();
    mvprintw(2, 0, "VOUS AVEZ PERDU");
    refresh();
    napms(5000);
    endwin();

    return 0; 
}