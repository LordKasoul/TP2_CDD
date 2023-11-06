// Importation des librairies. (Commandes pré-processeur)
#include <iostream>
#include <locale> // Pour pouvoir avoir les accent. Mais ne semble pas marcher
#include <thread> // Pour pouvoir faire des pauses sur l'affichage
#include <stdlib.h>

//Import fichier h
#include "constante.h"
#include "text.h"
#include "formatage.h"
 
// Déclaration des fonctions PERMANANTES (Pour assembler les pieces du jeu) !Peut pottentielement finir dans un fichier appart
void planJeu(void);

// Déclaration des fonctions TEMPORAIRES (Pour test puis en librairies)
void ecranTitre(void);
void initialisation(int &vie, int &soin, int& degatArme, int& vieBoss, int& degatBoss, int& vieMechant, int& degatMechant);
int intro(void);
void sortie(void);
int salle1(void);
int salle2(void);

using namespace std;
int main()
{
    //locale::global(locale("fr-FR"));
    planJeu();
}


void planJeu(void)
{
    int numSalle = 0, vie = 0, soin = 0, degatArme = 0, vieBoss = 0, degatBoss = 0, vieMechant = 0, degatMechant = 0;

    //ecranTitre();
    initialisation(vie, soin, degatArme, vieBoss,  degatBoss, vieMechant, degatMechant);
    numSalle = intro();
    do 
    {
        switch (numSalle)
        {
        case 1:
            numSalle = salle1();
            break;
        case 2:
            numSalle = salle2();
            break;
        case 66:
            sortie();
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
}

void ecranTitre(void)
{
    system("cls");
    RetourALaLigne(12);
    TabVersDroite(7);
    cout << text::titreCompagnie;
    this_thread::sleep_for(3000ms);
    
    system("cls");
    RetourALaLigne(12);
    TabVersDroite(7);
    cout << text::realise;
    this_thread::sleep_for(1500ms);
    
    system("cls");
    RetourALaLigne(12);
    TabVersDroite(7);;
    cout << text::nomDev1;
    this_thread::sleep_for(2000ms);
    
    system("cls");
    RetourALaLigne(12);
    TabVersDroite(7);
    cout << text::nomDev2;
    this_thread::sleep_for(2000ms);
    
    system("cls");
    RetourALaLigne(12);
    TabVersDroite(7);
    cout << text::present;
    this_thread::sleep_for(1500ms);
    
    system("cls");
    RetourALaLigne(12);
    TabVersDroite(6);
    cout << text::titreJeu;
    this_thread::sleep_for(4000ms);
    
    system("cls");

}


void initialisation(int &vie, int &soin, int &degatArme, int& vieBoss, int& degatBoss, int& vieMechant, int& degatMechant)
{
    int chiffreChoix = 0;
    bool verif = true;
    do 
    {
        RetourALaLigne(9);
        TabVersDroite(5);
        cout << text::initia1;
        TabVersDroite(5);
        cout << text::initia2;
        TabVersDroite(6);
        cout << text::choixNiveauFacile;
        TabVersDroite(6);
        cout << text::choixNiveauInter;
        TabVersDroite(6);
        cout << text::choixNiveauDiffi;
        TabVersDroite(6);
        cout << text::fleche;
        cin >> chiffreChoix;    
        system("cls");
        switch (chiffreChoix)
        {
        case 1:
            RetourALaLigne(12);
            TabVersDroite(5);
            cout << text::choixFacile;
            TabVersDroite(7);
            vie = constante::PV_FACILE;
            soin = constante::SOIN_FACILE;
            degatArme = constante::DEG_ARME_FACILE;
            this_thread::sleep_for(3000ms);
            break;
        case 2:
            RetourALaLigne(12);
            TabVersDroite(5);
            cout << text::choixInter;
            TabVersDroite(7);
            vie = constante::PV_INTER;
            soin = constante::SOIN_INTER;
            degatArme = constante::DEG_ARME_INTER;
            this_thread::sleep_for(3000ms);
            break;
        case 3:
            RetourALaLigne(12);
            TabVersDroite(5);
            cout << text::choixDiffi;
            TabVersDroite(7);
            vie = constante::PV_DIFFI;
            soin = constante::SOIN_DIFFI;
            degatArme = constante::DEG_ARME_DIFFI;
            this_thread::sleep_for(3000ms);
            break;
        default:
            RetourALaLigne(12);
            TabVersDroite(5);
            cout << text::erreurSaisie;
            verif = false;
            this_thread::sleep_for(3000ms);
            break;
        }
        system("cls");
    } while (verif != true);

}

int intro(void)
{
    int numSalle = 0;
    RetourALaLigne(9);
    TabVersDroite(5);
    cout << text::intro1;
    TabVersDroite(6);
    cout << text::intro2;
    TabVersDroite(5);
    cout << text::intro3;
    TabVersDroite(5);
    cout << text::introChoix;
    TabVersDroite(6);
    cout << text::introExploration;
    TabVersDroite(6);
    cout << text::introPasseChemin;
    TabVersDroite(7);
    cout << text::fleche;
    cin >> numSalle;
    (numSalle == 1) ? numSalle = 1 : numSalle = 66;
    system("cls");
    return numSalle;
}

void sortie(void)
{
    RetourALaLigne(12);
    TabVersDroite(4);
    cout << text::messSortie;
    RetourALaLigne(12);
    this_thread::sleep_for(5000ms);
    exit(EXIT_SUCCESS);
}


// Fonction Temporaire avant d'aller dans une librairie
int salle1(void)
{
    int numSalle = 0, chiffreChoix = 0, coffreOuvert = 0;
    bool verif = true;
    do
    {
        RetourALaLigne(8);
        TabVersDroite(5);
        cout << text::desSalle1;
        TabVersDroite(4);
        cout << text::desSalle12;
        TabVersDroite(3);
        cout << text::desSalle13;
        TabVersDroite(2);
        cout << text::desSalle13Bis;
        TabVersDroite(6);
        cout << text::propositionSalle1;
        TabVersDroite(6);
        cout << text::choixSalle11;
        TabVersDroite(6);
        cout << text::choixSalle12;
        TabVersDroite(6);
        cout << text::fleche;
        cin >> chiffreChoix;
        switch (chiffreChoix)
        {
        case 1:
            cout << text::desSalle1;
            coffreOuvert = 1;
            break;
        case 2:
            if (coffreOuvert == 1)
            {
                numSalle = 2;
            }
            else
            {
                cout << text::coffreNonOuvert;
                break;
            }
        default:
            system("cls");
            RetourALaLigne(12);
            TabVersDroite(5);
            cout << text::erreurSaisie;
            verif = false;
            this_thread::sleep_for(5000ms);
            break;
        }
    } while (verif != true);

    return numSalle;
}

int salle2(void)
{
    int numSalle = 0;
    return -1;
}