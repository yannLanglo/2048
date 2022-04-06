#include "2048_Yann.h"
#include "2048_Julie.h"
#include "2048_Elise.h"
#include "2048_Lucas.h"


void executeHaut(int** t_Plateau, int taille)
{
	int i; /* Variable de boucle 1 */
	int j; /* Variable de boucle 2 */
	int tmp; /*Variable temporaire*/

	/*Double boucle for qui parcours le plateau de haut en bas*/
	for(j = 0; j < taille; j++){
		for(i = 0; i < taille; i++){
			/*Si la case de coordonées i,j n'est pas vide.*/
			if(t_Plateau[i][j] != 0){
				/*tmp prend la valeur i afin de ne pas modifier celle-ci.*/
				tmp = i;
				/*boucle while qui s'effectue tant que la case au-dessus est vide et tant que l'on se trouve dans les limites du plateau.*/
				while(tmp > 0 && t_Plateau[tmp-1][j] == 0){
					/*La case au-dessus prend la valeur de la case actuelle et la case actuelle prend la valeur 0.*/
					t_Plateau[tmp-1][j] = t_Plateau[tmp][j];
					t_Plateau[tmp][j] = 0;
					tmp--;			
				}
			}
		}
	}
	/* On parcourt le plateau de haut en bas */
	for(j = 0; j < taille ; j++){
	/* On parcourt les colonnes */ 
		for (i = 0; i < taille ; i++) {
			/* Si 2 cases adjacentes ont la même valeur */
			if ((i < taille-1) && (t_Plateau[i][j] == t_Plateau[i+1][j])) {
				/* On ajoute les valeurs des deux cases dans la case du dessus */
				t_Plateau[i][j] = t_Plateau[i][j] + t_Plateau[i+1][j]; 
				/* On remet celle du dessous à 0 */
				t_Plateau[i+1][j] = 0; 
			}
			/* Si la case du dessus est vide */
			if ((i > 0) && (t_Plateau[i-1][j] == 0)){
				/* On remonte */
				t_Plateau[i-1][j] = t_Plateau[i][j];
				/* On remet celle du dessous à 0 */
				t_Plateau[i][j] = 0;

			}
		}
	}
}


void executeBas(int** t_Plateau, int taille)
{
	int i; /* Variable de boucle 1 */
	int j; /* Variable de boucle 2 */
	int tmp; /*Variable temporaire*/

	/*Double boucle for qui parcours le plateau de bas en haut*/
	for(j = 0; j < taille; j++){
		for(i = taille-1; i >= 0; i--){
			/*Si la case de coordonées i,j n'est pas vide.*/
			if(t_Plateau[i][j] != 0){
				/*tmp prend la valeur i afin de ne pas modifier celle-ci.*/
				tmp = i;
				/*boucle while qui s'effectue tant que la case au-dessous est vide et tant que l'on se trouve dans les limites du plateau.*/
				while(tmp < taille -1 && t_Plateau[tmp+1][j] == 0){
					/*La case au-dessous prend la valeur de la case actuelle et la case actuelle prend la valeur 0.*/
					t_Plateau[tmp+1][j] = t_Plateau[tmp][j];
					t_Plateau[tmp][j] = 0;
					tmp++;			
				}
			}
		}
	}
	/* On parcourt le plateau de haut en bas */
	for(j = 0; j < taille ; j++){ 
		 /* On parcourt les colonnes */
		for(i = taille - 1 ;i >= 0 ; i--){
			/* Si 2 cases adjacentes ont la même valeur */
			if((i > 0) && (t_Plateau[i][j] == t_Plateau[i-1][j])){
				/* On ajoute les valeurs des deux cases dans la case du dessous */
				t_Plateau[i][j] = t_Plateau[i][j] + t_Plateau[i-1][j]; 
				/* On remet celle du dessus à 0 */
				t_Plateau[i-1][j] = 0; 
			}
			/* Si la case du dessous est vide */
			if((i < taille-1) && (t_Plateau[i+1][j] == 0)){
				/* On descend */
				t_Plateau[i+1][j] = t_Plateau[i][j];
				/* On remet celle du dessus à 0 */
				t_Plateau[i][j] = 0;
			}
		}
	}
}


void executeDroite(int** t_Plateau, int taille)
{
	int i; /* Variable de boucle 1 */
	int j; /* Variable de boucle 2 */
	int tmp; /*Variable temporaire*/

	/*Double boucle for qui parcours le plateau de droite à gauche*/
	for(i = 0; i < taille; i++){
		for(j = taille-1; j >= 0; j--){

			/*Si la case de coordonées i,j n'est pas vide.*/
			if(t_Plateau[i][j] != 0){
				/*tmp prend la valeur i afin de ne pas modifier celle-ci.*/
				tmp = j;
				/*boucle while qui s'effectue tant que la case à droite est vide et tant que l'on se trouve dans les limites du plateau.*/
				while(tmp < taille-1 && t_Plateau[i][tmp+1] == 0){
					/*La case à droite prend la valeur de la case actuelle et la case actuelle prend la valeur 0.*/
					t_Plateau[i][tmp +1] = t_Plateau[i][tmp];
					t_Plateau[i][tmp] = 0;
					tmp++;			
				}
			}
		}
	}
	/* On parcourt le plateau de haut en bas */
	for(i = 0 ;i < taille ; i++){
		/* On parcourt les colonnes */
		for(j = taille -1 ; j >= 0 ; j--){
			/* Si 2 cases adjacentes ont la même valeur */
			if((j > 0) && (t_Plateau[i][j] == t_Plateau[i][j-1])){	
				/* On ajoute les valeurs des deux cases dans la case de droite */
				t_Plateau[i][j] = t_Plateau[i][j] + t_Plateau[i][j-1];
				/* On remet celle de gauche à 0 */
				t_Plateau[i][j-1] = 0;
			}
			/* Si la case de droite est vide */
			if((j < taille-1) && (t_Plateau[i][j+1] == 0)){
				/* On décale vers la droite */
				t_Plateau[i][j+1] = t_Plateau[i][j];
				/* On met celle de gauche à 0 */
				t_Plateau[i][j] = 0;
			}
		}
	}
}



void executeGauche(int** t_Plateau, int taille)
{
	int i; /* Variable de boucle 1 */
	int j; /* Variable de boucle 2 */
	int tmp; /*Variable temporaire*/

	/*Double boucle for qui parcours le plateau de gauche à droite*/
	for(i = 0; i < taille; i++){
		for(j = 0; j < taille; j++){

			/*Si la case de coordonées i,j n'est pas vide.*/
			if(t_Plateau[i][j] != 0){
				/*tmp prend la valeur i afin de ne pas modifier celle-ci.*/
				tmp = j;
				/*boucle while qui s'effectue tant que la case à gauche est vide et tant que l'on se trouve dans les limites du plateau.*/
				while(tmp > 0 && t_Plateau[i][tmp-1] == 0){
					/*La case à gauche prend la valeur de la case actuelle et la case actuelle prend la valeur 0.*/
					t_Plateau[i][tmp -1] = t_Plateau[i][tmp];
					t_Plateau[i][tmp] = 0;
					tmp--;			
				}
			}
		}
	}
	/* On parcourt le plateau de haut en bas */
	for(i = 0; i < taille; i++){
		/* On parcourt les colonnes */
		for(j = 0; j < taille; j++){
			/* Si 2 cases adjacentes ont la même valeur */
			if((j < taille-1) && (t_Plateau[i][j] == t_Plateau[i][j+1])){	
				/* On ajoute les valeurs des deux cases dans la case de gauche */
				t_Plateau[i][j] = t_Plateau[i][j] + t_Plateau[i][j+1];
				/* On remet celle de droite à 0 */
				t_Plateau[i][j+1] = 0;			
			}
			/* Si la case de gauche est vide */
			if ((j > 0) && (t_Plateau[i][j-1] == 0)){
				/* On décale vers la gauche */
				t_Plateau[i][j-1] = t_Plateau[i][j];
				/* On remet celle de droite à 0 */
				t_Plateau[i][j] = 0;
			}
		}
	}
}


void executeMouvement(int** t_Plateau,int taille, int direction)
{
	/* Selon la direction choisie par l'utilisateur */
	switch (direction)
	{
		/* Si l'utilisateur souhaite réaliser un déplacement vers le haut */
		case 1:
		/* On execute le mouvement vers le haut */
		executeHaut(t_Plateau, taille);
		break;
		/* Si l'utilisateur souhaite réaliser un déplacement vers le bas */
		case 2:
		/* On execute le mouvement vers le bas */
		executeBas(t_Plateau, taille);
		break;
		/* Si l'utilisateur souhaite réaliser un déplacement vers la gauche */
		case 3:
		/* On execute le mouvement vers la gauche */
		executeGauche(t_Plateau, taille);
		break;
		/* Si l'utilisateur souhaite réaliser un déplacement vers la droite */
		case 4:
		/* On execute le mouvement vers la droite */
		executeDroite(t_Plateau, taille);
		break;
		default:
		exit(0);
		break;
	}
}



