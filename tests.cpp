#include "modele.hpp"
#include <iostream>
#include <vector>
#include <string>
#define CHECK(test) if (!(test)) cerr << "Test failed in file " << __FILE__ << " line " << __LINE__ << ": " #test << endl
using namespace std;
using Plateau = vector<vector<int>>;

/** Compare les deux plateau
 *  @param plateau1
 *  @param plateau2
 *  @return true si les plateau sont pareils false sinon
 **/
bool ComparePlateau(Plateau plateau1,Plateau plateau2){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(plateau1[i][j]!=plateau2[i][j]){
                 return false;   
            }
        }   
    }
    return true;
}
void TesttireDeuxOuQuatre(int n_tirages){
    int tirage;
    for(int i=0;i<n_tirages;i++){
        tirage = tireDeuxOuQuatre();
        CHECK(tirage == 2 || tirage == 4);
    }
};

void TestplateauVide(){
    Plateau tableau_vide = plateauVide();
    Plateau tableau_attendu = { {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0} };
    CHECK(ComparePlateau(tableau_attendu, tableau_vide));
};


void TestplateauInitial(){
    Plateau tab = plateauInitial();
    int cases_non_vides = 0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(tab[i][j]!=0){
                cases_non_vides++;
            };
        }  
    }
    CHECK(cases_non_vides==2);
};

void TestdéplacementGauche(){;
    //definition variables
    Plateau tab_origine;
    Plateau tab_origine_post_deplacement;
    Plateau tab_attendu;
    //test deplacement tableau vide

    cout << "Test deplacement gauche tableau vide" << endl;
    tab_origine =  {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    tab_origine_post_deplacement = déplacementGauche(tab_origine);
    CHECK(ComparePlateau(tab_origine,tab_origine_post_deplacement));

    //test deplacement tableau avec combinaison
    cout << "Test deplacement gauche tableau avec combinaison 1" << endl;
    tab_origine =  {{0,0,0,0},{0,0,8,0},{0,2,2,0},{0,0,0,0}};
    tab_origine_post_deplacement = déplacementGauche(tab_origine);
    tab_attendu = {{0,0,0,0},{8,0,0,0},{4,0,0,0},{0,0,0,0}};
    CHECK(ComparePlateau(tab_attendu,tab_origine_post_deplacement));
    
    cout << "Test deplacement gauche tableau avec combinaison 2" << endl;
    tab_origine =  {{2,4,4,2},{4,4,8,8},{2,4,8,0},{2,4,0,0}};
    tab_origine_post_deplacement = déplacementGauche(tab_origine);
    tab_attendu = {{2,8,2,0},{16,8,0,0},{2,4,8,0},{2,4,0,0}};
    CHECK(ComparePlateau(tab_attendu,tab_origine_post_deplacement));
    //test deplacement tableau sans combinaison
    cout << "Test deplacement gauche tableau sans combinaison" << endl;
    tab_origine =  {{0,0,0,0},{0,0,4,0},{0,2,0,0},{0,0,0,0}};
    tab_origine_post_deplacement = déplacementGauche(tab_origine);
    tab_attendu = {{0,0,0,0},{4,0,0,0},{2,0,0,0},{0,0,0,0}};
    CHECK(ComparePlateau(tab_attendu,tab_origine_post_deplacement));
}
//{{},{},{},{}}
void TestdéplacementDroite(){
    //definition variables
    Plateau tab_origine;
    Plateau tab_origine_post_deplacement;
    Plateau tab_attendu;
    //test deplacement tableau vide

    cout << "Test deplacement droite tableau vide" << endl;
    tab_origine =  {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    tab_origine_post_deplacement = déplacementDroite(tab_origine);
    CHECK(ComparePlateau(tab_origine,tab_origine_post_deplacement));

    //test deplacement tableau avec combinaison
    cout << "Test deplacement droite tableau avec combinaison 1" << endl;
    tab_origine =  {{0,0,0,0},{0,0,8,0},{0,2,2,0},{0,0,0,0}};
    tab_origine_post_deplacement = déplacementDroite(tab_origine);
    tab_attendu = {{0,0,0,0},{0,0,0,8},{0,0,0,4},{0,0,0,0}};
    CHECK(ComparePlateau(tab_attendu,tab_origine_post_deplacement));
    
    cout << "Test deplacement droite tableau avec combinaison 2" << endl;
    tab_origine =  {{2,4,4,2},{4,4,8,8},{2,4,8,0},{2,4,0,0}};
    tab_origine_post_deplacement = déplacementDroite(tab_origine);
    tab_attendu = {{0,2,8,2},{0,0,8,16},{0,2,4,8},{0,0,2,4}};
    CHECK(ComparePlateau(tab_attendu,tab_origine_post_deplacement));
    //test deplacement tableau sans combinaison
    cout << "Test deplacement droite tableau sans combinaison" << endl;
    tab_origine =  {{0,0,0,0},{0,0,4,0},{0,2,0,0},{0,0,0,0}};
    tab_origine_post_deplacement = déplacementDroite(tab_origine);
    tab_attendu = {{0,0,0,0},{0,0,0,4},{0,0,0,2},{0,0,0,0}};
    CHECK(ComparePlateau(tab_attendu,tab_origine_post_deplacement));
};


void TestdéplacementHaut(){
    Plateau tab_origine;
    Plateau tab_origine_post_deplacement;
    Plateau tab_attendu;
    //test deplacement tableau vide

    cout << "Test deplacement haut tableau vide" << endl;
    tab_origine =  {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    tab_origine_post_deplacement = déplacementHaut(tab_origine);
    CHECK(ComparePlateau(tab_origine,tab_origine_post_deplacement));

    //test deplacement tableau avec combinaison
    cout << "Test deplacement haut tableau avec combinaison 1" << endl;
    tab_origine =  {{4,0,0,0},{4,0,0,0},{0,0,0,0},{0,8,2,0}};
    tab_origine_post_deplacement = déplacementHaut(tab_origine);
    tab_attendu = {{8,8,2,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    CHECK(ComparePlateau(tab_attendu,tab_origine_post_deplacement));
    
    cout << "Test deplacement haut tableau avec combinaison 2" << endl;

    tab_origine =  {{4,0,0,0},{4,0,16,0},{2,8,0,0},{2,0,0,0}};
    tab_origine_post_deplacement = déplacementHaut(tab_origine);
    tab_attendu = {{8,8,16,0},{4,0,0,0},{0,0,0,0},{0,0,0,0}};
    CHECK(ComparePlateau(tab_attendu,tab_origine_post_deplacement));
    //test deplacement tableau sans combinaison

    cout << "Test deplacement haut tableau sans combinaison" << endl;
    tab_origine =  {{0,0,0,0},{0,2,0,0},{8,0,4,0},{0,0,0,0}};
    tab_origine_post_deplacement = déplacementHaut(tab_origine);
    tab_attendu = {{8,2,4,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    CHECK(ComparePlateau(tab_attendu,tab_origine_post_deplacement));
};

void TestdéplacementBas(){
    Plateau tab_origine;
    Plateau tab_origine_post_deplacement;
    Plateau tab_attendu;
    //test deplacement tableau vide

    cout << "Test deplacement bas tableau vide" << endl;
    tab_origine =  {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    tab_origine_post_deplacement = déplacementBas(tab_origine);
    CHECK(ComparePlateau(tab_origine,tab_origine_post_deplacement));

    //test deplacement tableau avec combinaison
    cout << "Test deplacement bas  avec combinaison 1 " << endl;
    tab_origine =  {{4,0,0,0},{4,0,0,0},{0,0,0,0},{0,8,2,0}};
    tab_origine_post_deplacement = déplacementBas(tab_origine);
    tab_attendu = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{8,8,2,0}};
    CHECK(ComparePlateau(tab_attendu,tab_origine_post_deplacement));
    
    cout << "Test deplacement bas  avec combinaison 2 " << endl;
    tab_origine =  {{4,0,0,0},{4,0,16,0},{2,8,0,0},{2,0,0,0}};
    tab_origine_post_deplacement = déplacementBas(tab_origine);
    tab_attendu = {{0,0,0,0},{0,0,0,0},{8,0,0,0},{4,8,16,0}};
    CHECK(ComparePlateau(tab_attendu, tab_origine_post_deplacement));
    //test deplacement tableau sans combinaison
    cout << "Test deplacement bas  sans combinaison" << endl;
    tab_origine =  {{0,0,0,0},{0,2,0,0},{8,0,4,0},{0,0,0,0}};
    tab_origine_post_deplacement = déplacementBas(tab_origine);
    tab_attendu = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{8,2,4,0}};
    CHECK(ComparePlateau(tab_attendu,tab_origine_post_deplacement));
};


void Testdéplacement(){
    Plateau tab_origine;
    Plateau tab_origine_post_deplacement;
    Plateau tab_attendu;

    //test deplacement gauche
    cout << "Test déplacement gauche";
    tab_origine =  {{0,2,0,0},{0,0,0,4},{0,0,0,0},{8,0,0,0}};
    tab_origine_post_deplacement = déplacement(tab_origine,1);
    tab_attendu = {{2,0,0,0},{4,0,0,0},{0,0,0,0},{8,0,0,0}};
    CHECK(ComparePlateau(tab_attendu,tab_origine_post_deplacement));
    //test deplacement droite
    cout << "Test déplacement droite";
    tab_origine =  {{0,2,0,0},{0,0,0,4},{0,0,0,0},{8,0,0,0}};
    tab_origine_post_deplacement = déplacement(tab_origine,3);
    tab_attendu = {{0,0,0,2},{0,0,0,4},{0,0,0,0},{0,0,0,8}};
    CHECK(ComparePlateau(tab_attendu,tab_origine_post_deplacement));

    //test deplacement haut 
    cout << "Test déplacement haut";
    tab_origine =  {{0,2,0,0},{0,0,4,4},{0,0,4,0},{0,0,0,0}};
    tab_origine_post_deplacement = déplacement(tab_origine,2);
    tab_attendu = {{0,2,8,4},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    CHECK(ComparePlateau(tab_attendu,tab_origine_post_deplacement));

    //test deplacement bas 
    cout << "Test déplacement bas";
    tab_origine =  {{0,2,0,0},{0,0,4,4},{0,0,4,0},{0,0,0,0}};
    tab_origine_post_deplacement = déplacement(tab_origine,4);
    tab_attendu = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,2,8,4}};
    CHECK(ComparePlateau(tab_attendu,tab_origine_post_deplacement));
    // test deplacement impossible
    cout << "Test déplacement impossible gauche";
    tab_origine =  {{8,32,512,4},{2,128,4,2},{4,32,2,8},{8,2,4,16}};
    tab_origine_post_deplacement = déplacement(tab_origine,1);
    tab_attendu = {{8,32,512,4},{2,128,4,2},{4,32,2,8},{8,2,4,16}};
    CHECK(ComparePlateau(tab_attendu,tab_origine_post_deplacement));

    cout << "Test déplacement impossible droite";
    tab_origine = { {8,32,512,4},{2,128,4,2},{4,32,2,8},{8,2,4,16} };
    tab_origine_post_deplacement = déplacement(tab_origine, 3);
    tab_attendu = { {8,32,512,4},{2,128,4,2},{4,32,2,8},{8,2,4,16} };
    CHECK(ComparePlateau(tab_attendu, tab_origine_post_deplacement));

    cout << "Test déplacement impossible haut";
    tab_origine = { {8,32,512,4},{2,128,4,2},{4,32,2,8},{8,2,4,16} };
    tab_origine_post_deplacement = déplacement(tab_origine, 2);
    tab_attendu = { {8,32,512,4},{2,128,4,2},{4,32,2,8},{8,2,4,16} };
    CHECK(ComparePlateau(tab_attendu, tab_origine_post_deplacement));

    cout << "Test déplacement impossible bas";
    tab_origine = { {8,32,512,4},{2,128,4,2},{4,32,2,8},{8,2,4,16} };
    tab_origine_post_deplacement = déplacement(tab_origine, 4);
    tab_attendu = { {8,32,512,4},{2,128,4,2},{4,32,2,8},{8,2,4,16} };
    CHECK(ComparePlateau(tab_attendu, tab_origine_post_deplacement));
};


void TestestTerminé(){
    Plateau tableau_termine = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    CHECK(estTerminé(tableau_termine));
    Plateau tableau_pas_termine= {{8,8,512,4},{2,0,4,2},{4,32,2,8},{8,2,4,16}};
    CHECK(!estTerminé(tableau_pas_termine));
};


void TestestGagnant(){
    Plateau tableau_gagnant = {{2048,32,512,4},{2,128,4,2},{4,32,2,8},{8,2,4,16}};
    CHECK(estGagnant(tableau_gagnant));
    Plateau tableau_pas_gagnant = {{0,32,512,4},{2,128,4,2},{4,32,2,8},{8,2,4,16}};
    CHECK(!estGagnant(tableau_gagnant));
};

void LanceTests() {
    cout << "TEST FUNCTION tireDeuxOuQuatre()" << endl;
    TesttireDeuxOuQuatre(4);

    cout << "TEST FUNCTION plateauVide()" << endl;
    TestplateauVide();
    
    cout << "TEST FUNCTION plateauInitial()" << endl;
    TestplateauInitial();

    cout << "TEST FUNCTION déplacementGauche()" << endl;
    TestdéplacementGauche();

    cout << "TEST FUNCTION déplacementDroite()" << endl;
    TestdéplacementDroite();

    cout << "TEST FUNCTION déplacementHaut()" << endl;
    TestdéplacementHaut();

    cout << "TEST FUNCTION déplacementBas()" << endl;
    TestdéplacementBas();

    cout << "TEST FUNCTION déplacement()" << endl;
    Testdéplacement();


    cout << "TEST FUNCTION estTerminé()" << endl;
    TestestTerminé();

    cout << "TEST FUNCTION estGagnant()" << endl;
    TestestGagnant();

   
}
int main(){
    LanceTests();
    return 0;
}