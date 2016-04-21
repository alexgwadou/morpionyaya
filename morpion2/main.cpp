#include <iostream>

using namespace std;

void initialiseGrille(char grille[3][3])
{
     int i, j;
     for (i=0; i<3; i++) {
                          for (j=0; j<3; j++) {
                                               grille[i][j] ='_';
                                               }
                          }
}

void affichegrille(char grille[3][3])
{
     int i,j;
     for (i=0; i<3; i++) {
                          for (j=0; j<3; j++) {
                                               cout<<grille[i][j]<<" ";
                                               }
                          cout<<endl;
                          }

}

void metUnPionSurLaGrille(char grille[3][3], char&prochain_joueur)
{
     int ligne, colonne;
     cout<<"Quelle ligne ?"<<endl;
     cin>>ligne;
     cout<<"Quelle colonne ?"<<endl;
     cin>>colonne;
     while((grille[ligne-1][colonne-1]) != '_'){
                                            cout<<"Saisie eronnee"<<endl;
                                            cout<<"Quelle ligne ?"<<endl;
                                            cin>>ligne;
                                            cout<<"Quelle colonne ?"<<endl;
                                            cin>>colonne;
                                            }
     grille[ligne-1][colonne-1]=prochain_joueur;
     if (prochain_joueur == 'O'){
                                prochain_joueur = 'X';
                                }
     else{
          prochain_joueur = 'O';
          }
}

int testeFinJeu(char T[3][3], char prochain_jeu)
{
        if ((T[1][1]==T[2][1])&&(T[0][1]==T[1][1])&&(T[1][1]==prochain_jeu)){
                                                                return 1;
                                                                }
        if ((T[1][2]==T[2][2])&&(T[0][2]==T[1][2])&&(T[1][2]==prochain_jeu)){
                                                                return 1;
                                                                }
        if ((T[1][0]==T[2][0])&&(T[0][0]==T[1][0])&&(T[1][0]==prochain_jeu)){
                                                                return 1;
                                                                }
        if ((T[1][1]==T[1][2])&&(T[1][0]==T[1][1])&&(T[1][1]==prochain_jeu)){
                                                                return 1;
                                                                }
        if ((T[2][1]==T[2][2])&&(T[2][0]==T[2][1])&&(T[2][1]==prochain_jeu)){
                                                                return 1;
                                                                }
        if ((T[0][1]==T[0][2])&&(T[0][0]==T[0][1])&&(T[0][1]==prochain_jeu)){
                                                                return 1;
                                                                }
        if ((T[1][1]==T[2][2])&&(T[0][0]==T[1][1])&&(T[1][1]==prochain_jeu)){
                                                                return 1;
                                                                }
        if ((T[0][1]==T[2][2])&&(T[1][0]==T[2][2])&&(T[2][2]==prochain_jeu)){
                                                                return 1;
                                                                }

        else {
             return 0;
             }
}

int main (void)
{
    char grille[3][3];
    int b, i, a;
    char prochainjoueur;
    prochainjoueur='O';
    initialiseGrille(grille);
    b=testeFinJeu(grille, prochainjoueur);
    while(b==0){
                affichegrille(grille);
                metUnPionSurLaGrille(grille, prochainjoueur);
                b=testeFinJeu(grille, prochainjoueur);
                }
    affichegrille(grille);
    cout<<"Partie finie"<<endl;
    system("PAUSE");
    return 0;
}
