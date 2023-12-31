#pragma once
#include <string>
#include <iostream>
using namespace std;
namespace text
{
	// Messages erreurs
	string erreurSalle = "ERREUR : Une erreur dans le choix de la prochaine salle.\n";
	string erreurSaisie = "ERREUR : Votre choix n'est pas possible.\n";

	// Text general
	string fleche = "--> ";

	//�cran titre
	string titreCompagnie = "KABROCK Ind\n";
	string realise = "Realise par\n";
	string nomDev1 = "Antoine Ruyet\n";
	string nomDev2 = "Mael Daniel\n";
	string present = "Vous presente\n";
	string titreJeu = "Coincer dans un Donjon\n";

	
	// Initialisation
	string initia1 = "Avant de commancer votre grande aventure.\n";
	string initia2 = "Choississez votre niveau de difficultee.\n";
	string choixNiveauFacile = "1 - Facile\n";
	string choixNiveauInter = "2 - Intermediaire\n";
	string choixNiveauDiffi = "3 - Difficile\n";

	string choixFacile = "Vous avez choisi le niveau de Facile.\n";
	string choixInter = "Vous avez choisi le niveau de Intermediaire.\n";
	string choixDiffi = "Vous avez choisi le niveau de Difficile\n";

	// Introduction
	string intro1 = "Partie chercher du bois dans la foret proche du village.\n";
	string intro2 = "Vous appercevez entre deux arbres un escalier.\n";
	string intro3 = "Celui ci semble descendre dans les profondeur de la foret.\n";
	string introChoix = "Voulez vous explorer ses escaliser ?\n";
	string introExploration = "1 - Commencer votre aventure.\n";
	string introPasseChemin = "0 - Vous passer votre chemin.\n";
	string messSortie = "Vous passer votre chemin sans vous procuper de ces escaliers.\n";


	//Salle 1
	string desSalle1 = "Vous arriver dans une salle lugubre.\n";
	string desSalle12 = "La seul lumiere de la piece proviens d'un luminere au plafond.\n";
	string desSalle13 = "Dans cette salle seul un coffre et une porte tout deux fermes, sembles d'interet.\n";
	string desSalle13Bis = "Dans cette salle il n'y-a rien d'interressant de plus que le coffre que vous avez deja fouillez.\n";
	string propositionSalle1 = "Que comptez vous faire ?\n";
	string choixSalle11 = "1 - Ouvrir le coffre\n";
	string choixSalle12 = "2 - Ouvrir la porte\n";

	string coffreNonOuvert = "Votre instinct et votre curiosite vous inscite a ouvrir ce coffre.\n";
	string ouvertureCoffreSalle1 = "Vous ouvrer avec un peu de force ce vieux coffre.\n";
	string ouvertureCoffreSalle1_2 = "A l'interrieur ce trouve une epee.\n";
	string ouvertureCoffreSalle1_3 = "Vous la saisisser et vous vous sentez pret pour ce qui vous attend.\n";

	string coffreOuvert = "Vous avez deja ouvert ce coffre.\n";

	string versPorte = "Vous poussez la seul et unique porte de cette piece.\n";
	string versPorte_2 = "Vous avez un peu peur mais vous etes aussi plein d'envie d'aventure.\n";

	//Salle 2 

	string desSalle2_1 = "Apres avoir monter des escalier, vous entrez dans la deuxieme salle.\n";
	string desSalle2_2 = "L'environement change, l'atmosphere devient lourde.\n";
	string desSalle2_3 = "il vous semble entendre une respiration impossante venir de la piece a votre gauche.\n";
	string desSalle2_4 = "Vous remarquer au total 3 portes en plus des escalier.\n";
	string propositionSalle2 = "Quel porte voulez vous utilisee ?\n";
	string choixSalle2_1 = "1 - la porte a gauche. (salle 4)\n";
	string choixSalle2_2 = "2 - La porte en face. (salle 5)\n";
	string choixSalle2_3 = "3 - La porte a droite. (salle 3)\n";
	string choixSalle2_4 = "4 - Les escaliers. (salle 1)\n";
	string Salle2_choixChemin1 = "Vous avez decidez d'entrer dans la piece a votre gauche. (salle 4)\n";
	string Salle2_choixChemin2 = "Vous avez decidez d'entrer dans la piece a en face de vous. (salle 5)\n";
	string Salle2_choixChemin3 = "Vous avez decidez d'entrer dans la piece a votre droite. (salle 3)\n";
	string Salle2_choixChemin4 = "Vous avez decidez de reprendre les escaliers. (salle 1)\n";
	string Salle2_choixChemin2_1 = "Le maitre du jeu a detecter que vous avez obtenu la cle dans la salle numero 3 vous entrez dans la salle 5.\n";
	string Salle2_choixChemin2_2 = "Le maitre du jeu a detecter que vous n avez pas obtenu la cle dans une salle antierieur vous ne pouvez entrez dans la salle 5.\n";
	string deSalle2_3 = "Vous quitter la salle numero 2, Bonne chance pour la suite de votre aventure....En esperant qu elle soit pas la derniere.\n";
	string deSalle2_clef5 = "La porte de la salle semble bloquer.Vous n'avez pas la clef.\n";


	//Salle 3
	string desSalle3_decouverte = "Vous penetrez dans la salle numero 3. \n";
	string desSalle3_description = "Vous voyez un coffre en plein milieu de la salle. \n";
	string desSalle3_Choix = "Vous avez 1- le choix de l'ouvrir ou 2- de passer votre chemin.\n";
	string desSalle3_CoffreOuvert = "Vous avez choisi d'ouvrir le coffre, vous obtenez une clef pour la prochaine salle.\n";
	string desSalle3_CoffreFermer = "Vous avez chosi de faire demi tour.\n";
	string desSalle3_Clef5 = "Vous avez deja recupere la clef de la salle 5.\n";
}
	