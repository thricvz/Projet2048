#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
#include "modele.hpp"
using namespace std;

using Plateau = vector<vector<int>>;
// Vous pouvez ajouter des fonctions à ce fichier si besoin est


/** génère aléatoirement un 2 ou un 4 avec des probabilités respectives de 9/10 et 1/10
 *  @return 2 ou 4
 **/
int touche_direction(const char dir){
    int int_dir;
    switch(dir){
        case 'q':
            int_dir = 1;
            break;
        case 'z':
            int_dir = 2;
            break;
        case 'd':
            int_dir = 3;
            break;
        case 's':
            int_dir = 4;
            break;  
    }
    return int_dir;
}
int tireDeuxOuQuatre(){
    int nombre=rand()%10 + 1;
    if (nombre<=9){
        return 2;
    }else return 4;
}

Plateau genere_nouvelle_case(Plateau p){
    int ligneAlea,colonneAlea;
    int positions_tire = false;
    while(!positions_tire){
        ligneAlea=rand()%4;
        colonneAlea=rand()%4;
        if(p[ligneAlea][colonneAlea]==0){
            p[ligneAlea][colonneAlea]=tireDeuxOuQuatre();
            positions_tire = true;
        }
    }
    return p;
};

bool touche_valide(const char touche){
    char touches_valides[4] = {'z','q','s','d'};
    for(int i=0;i<4;i++){
        if(touches_valides[i]==touche){
            return true;
        }
    }
    return false;
};
/** génère un plateau de dimensions 4*4 ne contenant que des 0
 *  @return un plateau vide
 **/
Plateau plateauVide(){
    Plateau plateauJeu=Plateau(4);
    for (int i=0; i<plateauJeu.size();i++){
        plateauJeu[i]=vector<int>(4);
    }
    return plateauJeu;
}

/** génère deux nombres sur des cases aléatoires d'un plateau vide
 *  @return un plateau en début de jeu
 **/
Plateau plateauInitial(){
    Plateau plateauJeu=plateauVide();
    int ligneAlea,colonneAlea;
    int positions_tires = 0;
    while(positions_tires<2){
        ligneAlea=rand()%4;
        colonneAlea=rand()%4;
        if(plateauJeu[ligneAlea][colonneAlea]==0){
            plateauJeu[ligneAlea][colonneAlea]=tireDeuxOuQuatre();
            positions_tires +=1;
        }
    }
    return plateauJeu;
}

/** déplace les tuiles d'un plateau vers la gauche et les combine si possible
 *  @param plateau le plateau
 *  @return le plateau une fois déplacé vers la gauche
 **/
Plateau déplacementGauche(Plateau plateau){
    for (int i=0;i<4;i++){
        for (int j=1;j<4;j++){
            //deplace les elements au plus a gauche
            int indice = j;
            while(indice!=0){
                if(plateau[i][indice-1]==plateau[i][indice] ||plateau[i][indice-1]==0){
                    plateau[i][indice-1]+=plateau[i][indice];
                    plateau[i][indice]=0;
                    indice--;
                }else{
                    break;
                }

            }
        }
    }
    return plateau;
}

/** déplace les tuiles d'un plateau vers la droite et les combine si possible
 *  @param plateau le plateau
 *  @return le plateau une fois déplacé vers la droite
 **/
Plateau déplacementDroite(Plateau plateau){
    for (int i=0;i<4;i++){
        for (int j=2;j>-1;j--){
            //deplace les elements au plus a gauche
            int indice = j;
            while(indice!=3){
                if(plateau[i][indice+1]==plateau[i][indice] ||plateau[i][indice+1]==0){
                    plateau[i][indice+1]+=plateau[i][indice];
                    plateau[i][indice]=0;
                    indice++;
                }else{
                    break;
                }

            }
        }
    }
    return plateau;
}

/** déplace les tuiles d'un plateau vers le haut et les combine si possible
 *  @param plateau le plateau
 *  @return le plateau une fois déplacé vers le haut
 **/
Plateau déplacementHaut(Plateau plateau){
    for (int i=0;i<4;i++){
        for (int j=1;j<4;j++){
            //deplace les elements au plus a gauche
            int indice = j;
            while(indice!=0){
                if(plateau[indice-1][i]==plateau[indice][i] ||plateau[indice-1][i]==0){
                    plateau[indice-1][i] += plateau[indice][i];
                    plateau[indice][i]=0;
                    indice--;
                }else{
                    break;
                }

            }
        }
    }
    return plateau;
}

/** déplace les tuiles d'un plateau vers le bas et les combine si possible
 *  @param plateau le plateau
 *  @return le plateau une fois déplacé vers le bas
 **/
Plateau déplacementBas(Plateau plateau){
    for (int i=0;i<4;i++){
        for (int j=2;j>-1;j--){
            //deplace les elements au plus a gauche
            int indice = j;
            while(indice!=3){
                if(plateau[indice+1][i]==plateau[indice][i] ||plateau[indice+1][i]==0){
                    plateau[indice+1][i] += plateau[indice][i];
                    plateau[indice][i]=0;
                    indice++;
                }else{
                    break;
                }

            }
        }
    }
    return plateau;
}

/** déplace les tuiles d'un plateau dans la direction donnée et génère une nouvelle tuile si le déplacement est valide
 *  @param plateau le plateau
 *  @param direction la direction
 *  @return le plateau déplacé dans la direction
 **/
Plateau déplacement(Plateau plateau, int direction){
    if (direction==1){
        plateau=déplacementGauche(plateau);
    }else if (direction==2){
        plateau=déplacementHaut(plateau);
    }else if (direction==3){
        plateau=déplacementDroite(plateau);
    }else if (direction==4){
        plateau=déplacementBas(plateau);
    }
    return plateau;
}

/** permet d'obtenir le plus grand nombre du plateau
 * @param p un plateau
 * @return le plus grand nombre de p
 **/
int nombreMax(Plateau p){
    int max=0;
    for (int i=0;i<p.size();i++){
        for (int j=0;j<p[i].size();j++){
            if (p[i][j]>max) max=p[i][j];
        }
    }
    return max;
}

/** affiche un plateau
 * @param p le plateau
 **/
//a changer
string dessine(Plateau p){
    string d;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            d = d + std::to_string(p[i][j]);
            d.push_back('\t');
        }   
        d.push_back('\n');
    }
    return d;
}

/** permet de savoir si une partie est terminée
 *  @param plateau un plateau
 *  @return true si aucun déplacement n'est possible, false sinon
 **/
bool estTerminé(Plateau plateau){
    for (int i=1;i<5;i++){
        if (déplacement(plateau,i)!=plateau){
            return false;
        }
    }
    return true;
}

/** permet de savoir si une partie est gagnée
 * @param plateau un plateau
 * @return true si le plateau contient un 2048, false sinon
 **/
bool estGagnant(Plateau plateau){
    int max=nombreMax(plateau);
    if (max>=2048){
        return true;
    }else{
        return false;
    }
}
