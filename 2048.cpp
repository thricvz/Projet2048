#include "modele.hpp"
#include <curses.h>
#include <iostream>
using namespace std;


int main(){
    //demarre n_curses
    initscr();
    keypad(stdscr, TRUE);
    start_color(); 
    //variables necessaires
    Plateau plateau_de_jeu = plateauInitial();
    char touche;
    //met en place le moyen de guarder les scores
    SCORE Stockage_score;
    Stockage_score.plateau_tiré = plateau_de_jeu;
    Stockage_score.score = 0;

    while(!estTerminé(plateau_de_jeu)){
        clear();
        Stockage_score.score_str = "Votre score est " + to_string(Stockage_score.score);
        mvprintw(1, 0,Stockage_score.score_str.c_str());
        //couleur dans le tableau
        init_pair(1, COLOR_RED,COLOR_BLACK);
        attron(COLOR_PAIR(1));
        mvprintw(2, 0, dessine(plateau_de_jeu).c_str());
        attroff(COLOR_PAIR(1));

        mvprintw(6, 0, "Entrez une touche(q,z,d,s): ");
        touche = ' ';
        touche = getch();
        //transforme les fleches a l'équivalent des touches normales
        if(touche_valide(touche)){
            if(déplacement(plateau_de_jeu,touche_direction(touche)) != plateau_de_jeu){
                plateau_de_jeu = déplacement(plateau_de_jeu,touche_direction(touche));
                Stockage_score.plateau_deplacé = plateau_de_jeu;
                score(Stockage_score.plateau_tiré,Stockage_score.plateau_deplacé,&(Stockage_score.score));
                
                plateau_de_jeu = genere_nouvelle_case(plateau_de_jeu);
                Stockage_score.plateau_tiré = plateau_de_jeu;
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