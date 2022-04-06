#include "2048_Yann.h"
#include "2048_Julie.h"
#include "2048_Elise.h"
#include "2048_Lucas.h"
#include "2048_Test.h"

int main(int argc, char const *argv[])
{
	int** t_Plateau = NULL; /* Plateau de jeu */
	int taille; /* Taille du plateau de jeu */
	int gagne = 0; /* Valeur de retour de la fonction qui permet de savoir si le joueur à gagné */
	int perdu = 0; /* Valeur de retour de la fonction qui permet de savoir si plus aucun coup n'est possible */
	int direction; /* Valeur de retour de la fonction qui permet de savoir quel coup veut faire l'utilisateur */
	int v_mouvement; /* Valeur de retour de la fonction qui permet de savoir si un mouvement est réalisable */
	char fichier[100] = {0};	/* Nom du fichier de sauvegarde/restauration */
	int verif; /* Variable temporaire pour la gestion de la sauvegarde */

	/* On demande la taille du plateau de jeu à l'utilisateur */
	taille = menuTaille();

	if(taille == 3){
		printf("Saisissez le chemin ou le nom du fichier de sauvegarde à restaurer.\n");

		/*on demande le nom du fichier de sauvegarde */
		scanf("%s", fichier);
		viderBuffer();
		taille = restauration(&t_Plateau, fichier);
		verif = 0;
	}else{
		/* On initialise le plateau de jeu */
		if(taille == 6){
			/*Permet la gestion des jeux de tests */
			t_Plateau = initPlateau(4);
		}else{
			t_Plateau = initPlateau(taille);
		}
	}
	if(taille == 6){
		t_Plateau = menuTest(t_Plateau);
		taille = 4;
		verif = 0; 
	}

	/*Condition permettant de ne pas ajouter de 2 si la partie est restaurée */
	if(verif){
			/* On ajoute un 2 aléatoirement */
			ajouter(t_Plateau,taille);
		}else{
			verif = 1;
	}
	/* Tant que l'utilisateur n'a pas gagné et qu'il n'est pas bloqué */ 
	while ((gagne == 0) && (perdu == 0)){
		/* On affiche le nouveau plateau */
		afficherPlateau(t_Plateau,taille);

		do{
			/* On demande le mouvement que veut réaliser l'utilisateur et on stocke cette réponse dans une variable */
			direction = menuCoup();
		}while( (direction != 5) && ((direction == 4 && droite(t_Plateau, taille) == 0) || (direction == 3 && gauche(t_Plateau, taille) == 0) || (direction == 2 && bas(t_Plateau, taille) == 0) || (direction == 1 && haut(t_Plateau, taille) == 0)) );

		if(direction == 5){
			printf("Saisissez le chemin ou le nom du fichier de sauvegarde.\n");

			/*on demande le nom du fichier de sauvegarde */
			scanf("%s", fichier);
			viderBuffer();
			sauvegarde(t_Plateau, taille, fichier);
			free(t_Plateau);
			exit(0);
		}

		/* On execute le mouvement choisi */
		executeMouvement(t_Plateau,taille,direction);

		/* On affiche le nouveau plateau */
		afficherPlateau(t_Plateau,taille);

		//on ajoute un nouveau 2
		ajouter(t_Plateau,taille);

		system("clear");

		/* On vérifie si l'utilisateur a gagné et on stocke la valeur de retour dans une variable */
		gagne = victoire(t_Plateau,taille);

		/* On vérifie si un mouvement est encore possible et on stocke la valeur de retour dans une variable */
		v_mouvement = mouvement(t_Plateau,taille);

		/* On vérifie si l'utilisateur peut encore jouer et on stocke la valeur de retour dans une variable */
		perdu = defaite(v_mouvement);

	}
	/* Si le joueur a gagné */
	if (gagne == 1){
		/* On affiche un message pour le lui signaler */
		printf("Félicitation !! Vous avez gagné !!\n");
	}
	/* Si l'utilisateur a perdu */
	if (perdu == 1){
		/* On affiche un message pour le lui signaler */
		printf("Dommage... Réessayez encore.\n");
	}


	return 0;
}