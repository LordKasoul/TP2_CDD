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
            retour(5);
            tab(5);
            cout << text::errorSalle;
            retour(5);
            this_thread::sleep_for(8000ms);
            numSalle = -1;
            break;
        }
    } while (numSalle != -1);
}

void ecranTitre(void)
{
    system("cls");
    retour(12);
    tab(7);
    cout << text::titreCompagnie;
    this_thread::sleep_for(3000ms);
    
    system("cls");
    retour(12);
    tab(7);
    cout << text::realise;
    this_thread::sleep_for(1500ms);
    
    system("cls");
    retour(12);
    tab(7);;
    cout << text::nomDev1;
    this_thread::sleep_for(2000ms);
    
    system("cls");
    retour(12);
    tab(7);
    cout << text::nomDev2;
    this_thread::sleep_for(2000ms);
    
    system("cls");
    retour(12);
    tab(7);
    cout << text::present;
    this_thread::sleep_for(1500ms);
    
    system("cls");
    retour(12);
    tab(6);
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
        retour(9);
        tab(5);
        cout << text::initia1;
        tab(5);
        cout << text::initia2;
        tab(6);
        cout << text::choixNiveauFacile;
        tab(6);
        cout << text::choixNiveauInter;
        tab(6);
        cout << text::choixNiveauDiffi;
        tab(6);
        cout << text::fleche;
        cin >> chiffreChoix;    
        system("cls");
        switch (chiffreChoix)
        {
        case 1:
            retour(12);
            tab(5);
            cout << text::choixFacile;
            tab(7);
            vie = constante::PV_FACILE;
            soin = constante::SOIN_FACILE;
            degatArme = constante::DEG_ARME_FACILE;
            this_thread::sleep_for(3000ms);
            break;
        case 2:
            retour(12);
            tab(5);
            cout << text::choixInter;
            tab(7);
            vie = constante::PV_INTER;
            soin = constante::SOIN_INTER;
            degatArme = constante::DEG_ARME_INTER;
            this_thread::sleep_for(3000ms);
            break;
        case 3:
            retour(12);
            tab(5);
            cout << text::choixDiffi;
            tab(7);
            vie = constante::PV_DIFFI;
            soin = constante::SOIN_DIFFI;
            degatArme = constante::DEG_ARME_DIFFI;
            this_thread::sleep_for(3000ms);
            break;
        default:
            retour(12);
            tab(5);
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
    retour(9);
    tab(5);
    cout << text::intro1;
    tab(6);
    cout << text::intro2;
    tab(5);
    cout << text::intro3;
    tab(5);
    cout << text::introChoix;
    tab(6);
    cout << text::introExploration;
    tab(6);
    cout << text::introPasseChemin;
    tab(7);
    cout << text::fleche;
    cin >> numSalle;
    (numSalle == 1) ? numSalle = 1 : numSalle = 66;
    system("cls");
    return numSalle;
}

void sortie(void)
{
    retour(12);
    tab(4);
    cout << text::messSortie;
    retour(12);
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
        system("cls");
        retour(8);
        tab(5);
        cout << text::desSalle1;
        tab(4);
        cout << text::desSalle12;
        tab(3);
        cout << text::desSalle13;
        tab(2);
        cout << text::desSalle13Bis;
        tab(6);
        cout << text::propositionSalle1;
        if (coffreOuvert == 0)
        {
            tab(6);
            cout << text::choixSalle11;
        }
        tab(6);
        cout << text::choixSalle12;
        tab(6);
        cout << text::fleche;
        cin >> chiffreChoix;
        switch (chiffreChoix)
        {
        case 1:
            if (coffreOuvert == 1)
            {
                cout << text::coffreOuvert;
                this_thread::sleep_for(2500ms);
                verif = false;
            }
            else
            {
                system("cls");
                retour(8);
                tab(5);
                cout << text::ouvertureCoffreSalle1;
                tab(6);
                cout << text::ouvertureCoffreSalle1_2;
                tab(4);
                cout << text::ouvertureCoffreSalle1_3;
                coffreOuvert = 1;
                verif = false;
                this_thread::sleep_for(5000ms);
                break;
            }
        case 2:
            if (coffreOuvert == 1)
            {
                system("cls");
                retour(12);
                tab(5);
                cout << text::versPorte;
                tab(4);
                cout << text::versPorte_2;
                verif = true;
                numSalle = 2;
                this_thread::sleep_for(5000ms);
                break;
            }
            else
            {
                system("cls");
                retour(12);
                tab(4);
                cout << text::coffreNonOuvert;
                verif = false;
                this_thread::sleep_for(3500ms);
                break;
            }
        default:
            system("cls");
            retour(12);
            tab(5);
            cout << text::erreurSaisie;
            verif = false;
            this_thread::sleep_for(3500ms);
            break;
        }
    } while (verif != true);

    return numSalle;
}

int salle2(void)
{
    int numSalle = 0;
    return numSalle;
}