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
void initialisation(int &vie, int &soin, int &degatArme, int &vieBoss, int &degatBoss, int &vieMechant1, int &degatMechant1, int &vieMechant2);
int intro(void);
bool mort(void);
int salle1(void);
int salle2(bool &cleSalle5);
int salle4(int &vie, int &soin, int &degatArme, int &vieMechant1, int &degatMechant1, bool &clefSalle7);
int combat(int& vie, int& soin, int& degatArme, int& vieMechant1, int& degatMechant1);
int salle3(bool& clefSalle5);

using namespace std;
int main()
{
    //locale::global(locale("fr-FR"));
    planJeu();
}


void planJeu(void)
{
    int numSalle = 0, vie = 0, soin = 0, degatArme = 0, vieBoss = 0, degatBoss = 0, vieMechant1 = 0, degatMechant1 = 0,  vieMechant2 = 0;
    bool clefSalle5 = false, clefSalle7 = false;

    //ecranTitre();
    initialisation(vie, soin, degatArme, vieBoss,  degatBoss, vieMechant1, degatMechant1, vieMechant2);
    numSalle = intro();
    do 
    {
        switch (numSalle)
        {
        case 1:
            numSalle = salle1();
            break;
        case 2:
            numSalle = salle2(clefSalle5);
            break;
        case 3:
            numSalle = salle3(clefSalle5);
            break;
        case 4:
            numSalle = salle4(vie, soin, degatArme, vieMechant1, degatMechant1, clefSalle7);
            break;
        case 66:
            exit(EXIT_SUCCESS);
            break;
        
        default:
            retour(5);
            tab(5);
            cout << text::erreurSalle;
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


void initialisation(int &vie, int &soin, int &degatArme, int& vieBoss, int& degatBoss, int& vieMechant1, int& degatMechant1, int& vieMechant2)
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
    vieMechant1 = constante::PV_MINION;
    degatMechant1 = constante::DEG_MINION;
    vieMechant2 = constante::PV_MINION;
    // les degats des deux mechant font le meme nombre de degat
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
    retour(12);
    tab(4);
    if (numSalle == 66)
    {
        cout << text::messSortie;
        retour(12);
        this_thread::sleep_for(5000ms);
    }

    return numSalle;
}

bool mort(void)
{
    bool choixFin = false, verif = true;
    int chiffreChoix = 0;
    do
    {
        system("cls");
        retour(12);
        tab(6);
        cout << "Vous est mort.\n";
        tab(5);
        cout << "Voulez vous recommencer ?\n";
        tab(6);
        cout << "1 - Oui.\n";
        tab(6);
        cout << "2 - Non.\n";
        tab(6);
        cout << text::fleche;
        cin >> chiffreChoix;
        switch (chiffreChoix)
        {
        case 1:
            system("cls");
            retour(12);
            tab(6);
            cout << "Bon courage a vous.\n";
            this_thread::sleep_for(3000ms);
            choixFin = true;
            break;
        case 2: 
            system("cls");
            retour(12);
            tab(5);
            cout << "Ainsi ce termine votre histoire.\n";
            this_thread::sleep_for(3000ms);
            exit(EXIT_SUCCESS);
            choixFin = false;
            break;
        default:
            retour(12);
            tab(6);
            cout << text::erreurSaisie;
            this_thread::sleep_for(3000ms);
            verif = false;
        }

    } while (verif != true);
    return choixFin;
}

int combat(int& vie, int& soin, int& degatArme, int& vieMechant, int& degatMechant)
{
    bool choixFin = false, verif = false;
    int chiffreChoix = 0, degat = 0, iniJoueur = 0, iniMechant = 0, degatMin = 0, degatMax = 0, choixAleatoire = 0, soinAleatoire = 0, premier = 0;
    srand(time(NULL));
    iniJoueur = 1 + rand()%100;
    iniMechant = 1 + rand() % 100;
    do
    {
        for (int n=1;n<100;n++)
        {
            system("cls");
            tab(4);
            cout << "Vie : " << vie << "\tPotion de soin : " << soin << "\tVie monstre : " << vieMechant << endl;
            if (premier == 2)
            {
                n = iniJoueur;
                premier = 0;
            }
            else if (premier == 1)
            {
                choixAleatoire = rand() % 10;
                if (choixAleatoire >= 7)
                {
                    vie -= degatMechant * 2;
                    cout << "Le monstre fait une attaque lourde.\n";
                    cout << "Le monstre vous inflige " << degatMechant * 2 << " de points de degats.\n";
                    if (vie <= 0) mort();
                    this_thread::sleep_for(2500ms);
                }
                else
                {
                    vie -= degatMechant;
                    cout << "Le monstre vous inflige " << degatMechant << " de points de degats.\n";
                    if (vie <= 0) mort();
                    this_thread::sleep_for(2500ms);
                }
                premier = 0;
            }

            if (n == iniJoueur)
            do {
                premier = 1;
                //system("cls");
                cout << "Votre tour :\n";
                cout << "1 - Attaquer.\n";
                cout << "2 - Attaque lourde.\n";
                cout << "3 - Vous soigner.\n";
                cout << text::fleche;
                cin >> chiffreChoix;
                switch (chiffreChoix)
                {
                case 1:
                    degatMin = degatArme - 2;
                    degatMax = degatArme + 2;
                    degat = degatMin + rand() % degatMax;
                    vieMechant -= degat;
                    if (vieMechant <= 0) return n = 100;
                    cout << "Vous attaquer de " << degat << " de points de degats.\n";
                    cout << "Il reste " << vieMechant << " de vie au monstre.\n";
                    this_thread::sleep_for(2500ms);
                    verif = true;
                    break;
                case 2:
                    choixAleatoire = rand()%10;
                    if (choixAleatoire >= 8)
                    {
                        vieMechant = degatArme * 2;
                        if (vieMechant <= 0) return n = 100;
                        cout << "Vous attaquer de " << degatArme*2 << " de points de degats.\n";
                        cout << "Il reste " << vieMechant << " de vie au monstre.\n";
                        this_thread::sleep_for(2500ms);
                    }
                    else
                    {
                        cout << "vous n'avez pas reussi a porter le coup au monstre.\n";
                        this_thread::sleep_for(2500ms);
                    }
                    verif = true;
                    break;
                case 3:
                    if (soin > 0)
                    {
                        soinAleatoire = 2+ rand() % 10;
                        vie += soinAleatoire;
                        cout << "Vous gagner " << soinAleatoire << " points de vie.\n";
                        soin -= 1;
                        this_thread::sleep_for(2500ms);
                    }
                    else
                    {
                        cout << "vous n'avez plus de potion de soin.\n";
                        this_thread::sleep_for(2500ms);
                    }
                    verif = true;
                    break;
                default:
                    retour(12);
                    tab(6);
                    cout << text::erreurSaisie;
                    this_thread::sleep_for(3000ms);
                    verif = false;
                }
            } while (verif != true);
            else if (n == iniMechant && premier == 0)
            {
                premier = 2;
                choixAleatoire = rand() % 10;
                if (choixAleatoire >= 7)
                {
                    vie -= degatMechant*2;
                    cout << "Le monstre fait une attaque lourde.\n";
                    cout << "Le monstre vous inflige " << degatMechant*2 << " de points de degats.\n";
                    if (vie <= 0) mort();
                    this_thread::sleep_for(2500ms);
                }
                else
                {
                    vie -= degatMechant;
                    cout << "Le monstre vous inflige " << degatMechant << " de points de degats.\n";
                    if (vie <= 0) mort();
                    this_thread::sleep_for(2500ms);
                }
                
            }
            cout << "n : " << n;
            this_thread::sleep_for(500ms);
            if (n == 140) n = 100;
            if (n == iniJoueur || n == iniMechant) n = 1;
            
        }
    } while (vie >= 0 || vieMechant >= 0);
    if (vie == 0) mort();
    else
    {
        cout << "Vous avez vaincu le monstre.\n";
        cout << "Vos degats font 2 degat en plus.\n";
        degatArme += 2;
        cout << "Vous faites maintenants " << degatArme << " de degats.\n";
        this_thread::sleep_for(2500ms);
    }
    return 1;

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

int salle2(bool& clefSalle5)
{
    int numSalle = 0;
    int chiffreChoix = 0;
    bool verif = false;
    do {
        system("cls");
        retour(8);
        tab(4);
        cout << text::desSalle2_1;
        tab(6);
        cout << text::desSalle2_2;
        tab(4);
        cout << text::desSalle2_3;
        tab(5);
        cout << text::desSalle2_4;
        tab(6);
        cout << text::propositionSalle2;
        tab(6);
        cout << text::choixSalle2_1;
        tab(6);
        cout << text::choixSalle2_2;
        tab(6);
        cout << text::choixSalle2_3;
        tab(6);
        cout << text::choixSalle2_4;
        tab(6);
        cout << text::fleche;
        cin >> chiffreChoix;
        switch (chiffreChoix)
        {
        case 1:
            system("cls");
            retour(12);
            tab(2);
            cout << text::Salle2_choixChemin1;
            numSalle = 4;
            verif = true;
            break;
        case 2:
            if (clefSalle5 == false)
            {
                system("cls");
                retour(12);
                tab(2);
                cout << text::deSalle2_clef5;
                this_thread::sleep_for(5000ms);
            }
            else
            {
                system("cls");
                retour(12);
                tab(2);
                cout << text::Salle2_choixChemin2;
                this_thread::sleep_for(5000ms);
                numSalle = 5;
                verif = true;
            }
            break;
        case 3:
            system("cls");
            retour(12);
            tab(2);
            cout << text::Salle2_choixChemin3;
            this_thread::sleep_for(5000ms);
            numSalle = 3;
            verif = true;
            break;
        case 4:
            system("cls");
            retour(12);
            tab(2);
            cout << text::Salle2_choixChemin4;
            this_thread::sleep_for(5000ms);
            numSalle = 1;
            verif = true;
            break;

        default:
            system("cls");
            retour(12);
            tab(2);
            cout << text::erreurSalle;
            this_thread::sleep_for(5000ms);
            break;
        }
       }while (verif == false);
       cout << numSalle;
    return numSalle;
}


int salle3(bool& clefSalle5)
{
    bool verif = false;
    int choixSalle3 = 0, numSalle = 0;
    do
    {
        cout << text::desSalle3_decouverte;
        cout << text::desSalle3_description;
        cout << text::desSalle3_Choix;

        cin >> choixSalle3;
        switch (choixSalle3)
        {
        case 1:
            if (clefSalle5 == true)
            {
                cout << text::desSalle3_Clef5;
            }
            else
            {
            cout << text::desSalle3_CoffreOuvert;
            this_thread::sleep_for(4000ms);
            clefSalle5 = true;
            verif = true;
            }
            break;
        case 2:
            cout << text::desSalle3_CoffreFermer;
            this_thread::sleep_for(4000ms);
            verif = true;
            numSalle = 2;
            break;
        case 4:
            system("cls");
            retour(12);
            tab(2);
            cout << text::Salle2_choixChemin4;
            this_thread::sleep_for(5000ms);
            numSalle = 1;
            verif = true;
            break;

        default:
            system("cls");
            retour(12);
            tab(2);
            cout << text::erreurSalle;
            this_thread::sleep_for(5000ms);
            break;
        }
       }while (verif == false);
    return numSalle;
}

int salle4(int& vie, int& soin, int& degatArme, int& vieMechant1, int& degatMechant1, bool &clefSalle7)
{
    int numSalle = 0, chiffreChoix = 0;
    bool verif = false, resultatCombat = false;
    do
    {
        if (vieMechant1 == 0 && clefSalle7 == true)
        {
            do {
                system("cls");
                retour(12);
                tab(6);
                cout << "Vous avez deja fouillez cette piece.\n";
                tab(6);
                cout << "1 - Sortir\n";
                cout << text::fleche;
                cin >> chiffreChoix;
                if (chiffreChoix == 1)
                {
                    numSalle = 2;
                    verif = true;
                }
            } while (verif != true);
            resultatCombat = true;

        }
        else if (vieMechant1 == 0 && clefSalle7 == false)
        {
            do
            {
                system("cls");
                retour(8);
                tab(5);
                cout << "La seul chose qui reste d'interret dans cette piece,\n";
                tab(6);
                cout << "est ce vieux coffre dans un coin de la piece.\n";
                tab(6);
                cout << "Que voulez vous faire ?\n";
                tab(7);
                cout << "1 - Ouvrir le coffre.";
                tab(7);
                cout << "2 - Retourner dans la deuxiemme salle.";
                cout << text::fleche;
                cin >> chiffreChoix;
                switch (chiffreChoix)
                {
                case 1:
                    system("cls");
                    retour(12);
                    tab(6);
                    cout << "Vous ouvrez le coffre ce qui provoqua un crincement.\n";
                    tab(6);
                    cout << "A l'interrieur vous trouvez une veille clef avec le numero 7 graver dessus.\n";
                    clefSalle7 = true;
                    verif = true;
                    break;
                case 2:
                    system("cls");
                    retour(12);
                    tab(6);
                    cout << "Vous retourner dans la deuxieme salle.\n";
                    numSalle = 2;
                    verif = true;
                    break;
                default:
                    retour(12);
                    tab(6);
                    cout << text::erreurSaisie;
                    break;
                }
            } while (verif != true);
            resultatCombat = true;
        }
        else
        {
            if (vieMechant1 > 0)
            {
                resultatCombat = false;
            }
            else
            {
                resultatCombat = true;
            }
            system("cls");
            retour(12);
            tab(5);
            cout << "Il semblerait qu'un monstre ce trouve dans cette piece.\n";
            tab(6);
            cout << "Et il ne semble pas vraiment amicale.\n";
            this_thread::sleep_for(2500ms);
            combat(vie, soin, degatArme, vieMechant1, degatMechant1);
            cout << "bouh";

        }
    } while (resultatCombat != true);

    return numSalle;
}