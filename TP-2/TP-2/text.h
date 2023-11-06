#pragma once
#include <string>
#include <iostream>
using namespace std;
namespace text
{
	// Messages erreurs
	string errorSalle = "ERREUR : Une erreur dans le choix de la prochaine salle.\n";
	string erreurSaisie = "ERREUR : Votre choix n'est pas possible.\n";

	// Text general
	string fleche = "--> ";

	//Écran titre
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

}
	