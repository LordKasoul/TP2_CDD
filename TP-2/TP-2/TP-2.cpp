// Importation des librairies. (Commandes pré-processeur)
#include <iostream>
#include <locale> // Pour pouvoir avoir les accent. Mais ne semble pas marcher
#include <thread> // Pour pouvoir faire des pauses sur l'affichage

//Import fichier h
#include "constante.h"
#include "text.h"
#include "formatage.h"
 
// Déclaration des fonctions PERMANANTES (Pour assembler les pieces du jeu) !Peut pottentielement finir dans un fichier appart
void planJeu(void);

// Déclaration des fonctions TEMPORAIRES (Pour test puis en librairies)
void ecranTitre(void);
void initialisation(int &vie, int &soin, int& degatArme, int& vieBoss, int& degatBoss, int& vieMechant, int& degatMechant);
void intro(void);
int salle1(int& degatArme);

using namespace std;
int main()
{
    //locale::global(locale("fr-FR"));
    cout << "Good morning New York\n";
    planJeu();
}


void planJeu(void)
{
    int numSalle = 0, vie = 0, soin = 0, degatArme = 0, vieBoss = 0, degatBoss = 0, vieMechant = 0, degatMechant = 0;

    ecranTitre();
    initialisation(vie, soin, degatArme, vieBoss,  degatBoss, vieMechant, degatMechant);
    numSalle = salle1(degatArme);
    do 
    {
        switch (numSalle)
        {
        case 1:
            numSalle = salle1(degatArme);
            break;
        case 2:
            //numSalle = salle1(degatArme);
            break;
        default:
            RetourALaLigne(5);
            TabVersDroite(5);
            cout << text::errorSalle;
            RetourALaLigne(5);
            this_thread::sleep_for(8000ms);
            numSalle = -1;
            break;
        }

    } while (numSalle != -1);
    //Les prochaines salles ne seront accecible seulement depuis les autres fonctions salle
}

void ecranTitre(void)
{
    system("cls");
    RetourALaLigne(12);
    TabVersDroite(7);
    cout << text::titreCompagnie;
    this_thread::sleep_for(5000ms);
    
    system("cls");
    RetourALaLigne(12);
    TabVersDroite(7);
    cout << text::realise;
    this_thread::sleep_for(2000ms);
    
    system("cls");
    RetourALaLigne(12);
    TabVersDroite(7);;
    cout << text::nomDev1;
    this_thread::sleep_for(3000ms);
    
    system("cls");
    RetourALaLigne(12);
    TabVersDroite(7);
    cout << text::nomDev2;
    this_thread::sleep_for(3000ms);
    
    system("cls");
    RetourALaLigne(12);
    TabVersDroite(7);
    cout << text::present;
    this_thread::sleep_for(2000ms);
    
    system("cls");
    RetourALaLigne(12);
    TabVersDroite(6);
    cout << text::titreJeu;
    this_thread::sleep_for(5000ms);
    
    system("cls");

}


void initialisation(int &vie, int &soin, int &degatArme, int& vieBoss, int& degatBoss, int& vieMechant, int& degatMechant)
{
    int chiffreChoix = 0;
    RetourALaLigne(9);
    cout << text::intro1;
    cout << text::intro2;
    cout << text::choixNiveauFacile;
    cout << text::choixNiveauInter;
    cout << text::choixNiveauDiffi;
    cout << text::fleche;
    cin >> chiffreChoix;
    switch (chiffreChoix)
    {
        case 1:
            cout << text::choixFacile;
            vie = constante::PV_FACILE;
            soin = constante::SOIN_FACILE;
            break;
    }
}

void intro(void)
{

}


// Foonction Temporaire avant d'aller dans une librairie
int salle1(int& degatArme)
{
    int numSalle = 0;
    return numSalle;

}