#include "2048_Yann.h"
#include "2048_Julie.h"
#include "2048_Elise.h"
#include "2048_Lucas.h"
 
void viderBuffer(void)
{
	int c; /* Carcatère*/

	/* Réinitialise la fonction scanf */
	while((c = getchar()) != EOF && c != '\n');
}

int menuTaille(void)
{
	int valeur; /* Taille du plateau choisie par l'utilisateur */
	int taille; /* Taille du plateau choisie par l'utilisateur */
	int scanretour; /* Valeur de vérification */

	/* Affichage du menu */
	printf("----- TAILLE DU PLATEAU -----\n");
	printf("1. 4x4\n");
	printf("2. 8x8\n");
	printf("3. Charger une partie.\n");
	printf("4. Jeu de tests.\n");

	/* La valeur de vérification prend la valeur entrée par l'utilisateur */
	scanretour = scanf("%d",&valeur);
	/* On vide le buffer */
	viderBuffer();

	/* Tant que la valeur entrée par l'utilisateur n'est pas valable */
	while ((scanretour == 0) || (valeur < 1) || (valeur > 4)){
		/* Affichage d'un message d'erreur */
		printf("Erreur de saisie veuillez écrire 1 ou 2 selon la taille voulue\n");
		/* La valeur de vérification prend la nouvelle valeur entrée par l'utilisateur */
		scanretour = scanf("%d",&valeur);
		/* On vide le buffer */
		viderBuffer();
	}
	/* Si la valeur entrée par l'utiisateur est 1 */
	if (valeur == 1){
		/* La taille du plateau de jeu sera de 4 */
		taille = 4;
	}
	/* Si la valeur entrée par l'utiisateur est 2 */
	if (valeur == 2){
		/* La taille du plateau de jeu sera de 8 */
		taille = 8;
	}

	if( valeur == 3){
		/*On charge une partie*/
		taille = valeur;
	}

	if(valeur == 4){
		/*On charge les jeux de tests*/
		
		taille = 6;
	}
	/* On retourne la taille du tableau */
	return(taille);
}

int** initPlateau(int taille)
{
	int** t_Plateau; /* Plateau de jeu */
	int i; /* Variable de boucle */

	/* On alloue la mémoire pour le tableau de pointeurs */
	t_Plateau = malloc(taille * sizeof(int*));
	/* Si le plateau est vide */
	if (t_Plateau == NULL){
		/* On affiche un message d'erreur */
		fprintf(stderr, "Allocation impossible\n");
		/* On libère l'espace mémoire */
		free(t_Plateau);
		/* On quitte */
		exit(0);
	}
	/* On parcourt le tableau de pointeurs */
	for (i = 0; i < taille; i++){
		/* On alloue la mémoire pour le tableau de pointeurs de pointeurs */
		t_Plateau[i] = malloc(taille*sizeof(int));

		if (t_Plateau == NULL){
			/* On affiche un message d'erreur */
			fprintf(stderr, "Allocation impossible\n");
			/* On libère l'espace mémoire */
			free(t_Plateau);
			/* On quitte */
			exit(0);
		}
	}
	/* On retourne le plateau */
	return(t_Plateau);
}

void afficherPlateau(int** t_Plateau,int taille)
{
	int i; /* Variable de boucle 1 */
	int j; /* Variable de boucle 2 */
	int l; /* Variable de boucle 3 */

	/* On parcourt les lignes */
	for (i = 0; i < taille; i++){
		/* On affiche un saut de ligne */
		printf("\n");
		/* On affiche le bord de gauche */
		printf("+");
		/* On parcourt les colonnes */
		for(l = 0 ; l < taille ; l++){
			/* On affiche les bordures de cases horizontales du dessus */
			printf("---+");
		}
		/* On affiche un saut de ligne */
		printf("\n");
		/* On parcourt les colonnes */
		for (j = 0; j < taille; j++){
			if(t_Plateau[i][j] == 0){
				printf("|   ");
			}
			else{
				/* On affiche la bordure de gauche de chaque case et son contenu */
				printf("| %d ",t_Plateau[i][j]);
			}
		}
		/* On affiche la bordure de droite du tableau */
		printf("|");
	}
	/* On affiche un saut de ligne */
	printf("\n");

	/* ----- ON AFFICHE LA BORDURE DU BAS DU TABLEAU ----- */
	
	/* On affiche le coin en bas à gauche */
	printf("+");
	/* On parcourt les colonnes */
	for(l = 0 ; l < taille ; l++){
		/* On affiche la bordure du bas du tableau */
		printf("---+");
	}
	/* On affiche un saut de ligne */
	printf("\n");
}

int menuCoup(void)
{
	int valeur; /* Valeur entrée par l'utilisateur */
	int scanretour; /* Valeur de vérification */

	/* Affichage du menu */
	printf(" --- OÙ VOULEZ-VOUS JOUER ? ---\n");
	printf("1. Haut\n");
	printf("2. Bas\n");
	printf("3. Gauche\n");
	printf("4. Droite\n");
	printf("5. Sauvegarder et Quitter\n");
	/* La valeur de vérification prend la valeur entrée par l'utilisateur */
	scanretour = scanf("%d",&valeur);
	/* On vide le buffer */ 
	viderBuffer();

	/* Tant que la valeur entrée par l'utilisateur n'est pas valable */
	while ((scanretour == 0) || (valeur < 1) || (valeur > 5)){
		printf("Erreur de saisie veuillez écrire 1,2,3 ou 4 selon le mouvement que vous voulez effectuer\n");
		/* La valeur de vérification prend la valeur entrée par l'utilisateur */
		scanretour = scanf("%d",&valeur);
		/* On vide le buffer */
		viderBuffer();
	}
	/* On retourne la valeur qu'a entré l'utilisateur */ 
	return(valeur);
}

int verifCoup(int** t_Plateau,int taille,int direction)
{
	int v_haut; /* Variable permettant de savoir si le déplacement vers le haut est possible */
	int v_bas; /* Variable permettant de savoir si le déplacement vers le bas est possible */
	int v_gauche; /* Variable permettant de savoir si le déplacement vers la gauche est possible */
	int v_droite; /* Variable permettant de savoir si le déplacement vers la droite est possible */
	int res; /* Valeur de retour */
	
	/* Initialisation de la valeur de retour à VRAI */
	res = 1;
	/* Les variables prennent la valeur de retour des fonctions correspondantes */
	v_haut = haut(t_Plateau,taille);
	v_bas = bas(t_Plateau,taille);
	v_droite = droite(t_Plateau, taille);
	v_gauche = gauche(t_Plateau,taille);

	/* Si le choix de l'utilisateur est le même qu'un mouvement impossible */
	if (((direction == 1) && (v_haut == 0)) || ((direction == 2) && (v_bas == 0)) || ((direction == 3) && (v_gauche == 0)) || ((direction == 4) && (v_droite == 0))){
		/* La valeur de retour prend FAUX */
		res = 0;
	}
	/* On retourne res */
	return(res);
}

int victoire(int** t_Plateau,int taille)
{
	int res = 0; /* Valeur de retour */
	int i; /* Variable de boucle 1 */
	int j; /* Variable de boucle 2 */

	/* On parcourt les lignes */
	for (i = 0; i < taille; i++){
		/* On parcourt les colonnes */
		for (j = 0; j < taille; j++){
			/* Si la case contient 2048 */
			if (t_Plateau[i][j] == 2048){
				/* Le joueur a gagné */
				res = 1;
			}
		}
	}
	/* On retourne la valeur de retour */
	return(res);
}

int defaite(int mouvement)
{
	int res; /* Valeur de retour */

	/* Initialisation de la valeur de retour à FAUX */
	res = 0;

	/* Si aucun mouvement n'est possible*/
	if (mouvement == 0){
		/* La valeur de retour prend VRAI */
		res = 1;
	}
	/* On retourne res */
	return(res);
}