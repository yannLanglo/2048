#include "2048_Yann.h"
#include "2048_Julie.h"
#include "2048_Elise.h"
#include "2048_Lucas.h"
 
element_liste* creerElement(int x, int y)
{
	element_liste* nouveau = malloc(sizeof(element_liste));
	nouveau->x = x;
	nouveau->y = y;
	nouveau->suivant = NULL;
	return(nouveau);
}


void ajouterElementDebut(Tete* teteListe, int x, int y)
{
	element_liste* nouveau;
	nouveau = creerElement(x, y);
	nouveau->suivant = *teteListe;
	*teteListe = nouveau;
}


void sauvegarde(int** plateau, int taille, char fich[100])
{
	FILE* fichier = NULL;
	fichier = fopen(fich, "w");	//ouverture du fichier
	if(fichier != NULL){		//on vérifie sil'ouverture est réussie
		fputc(taille, fichier); //on écrit dans le fichier de sauvegarde la taille du plateau de jeu pour permettre la restauration de celui-ci plus tard.
		//On parcourt toutes les cases du plateau de jeu et on écrit la valeur de chaque case dans le fichier
		for(int i = 0; i < taille; i++){
			for(int j = 0; j < taille; j++){
				fputc(plateau[i][j], fichier);	
			}
		}
	}else{	//cas où l'ouverture du fichier échoue
		printf("Erreur de sauvegarde !!\n");
	}
	fclose(fichier);	//on ferme le fichier
}


int restauration(int*** plateau, char fich[100])
{
	FILE* fichier = NULL;
	int taille;
	int** tableau;
	fichier = fopen(fich, "r"); //ouverture du fichier
	if(fichier != NULL){	//on teste l'ouverture du fichier
		taille = fgetc(fichier);	//on récupère la taille du plateau de jeu à restaurer
		tableau = initPlateau(taille);	//on initialise le plateau de jeu à la bonne taille
		//on récupère les valeurs du plateau de jeu dans l'ordre où elles ont été écrites.
		for(int i = 0; i < taille; i ++){
			for(int j = 0; j < taille; j++){
				tableau[i][j] = fgetc(fichier);
			}
		}
		*plateau = tableau;
	}else{ 		//cas où l'ouverture du fichier a échoué
		printf("Erreur dans la restauration de la sauvegarde !!\n");
	}
	fclose(fichier);	//on ferme le fichier
	return(taille);
}


void ajouter(int** t_Plateau, int taille)
{
	Tete liste = NULL;
	int compteur;
	int compteur2;
	compteur = 0;
	//on parcourt le plateau de jeu et chaque fois qu'une case est vide on ajoute ses coordonnées dans la liste
	for(int i = 0; i < taille; i++){
		for(int j = 0; j < taille; j++){
			if(t_Plateau[i][j] == 0){
				compteur++;		//on incrémente le compteur
				ajouterElementDebut(&liste, i , j);
			}
		}
	}
	srand(time(NULL));
	compteur2 = rand()%compteur; //on prend un nombre au hasard en 0 et compteur
	compteur = 0;
	//on parcourt la liste jusqu'à la valeur compteur2 et on ajoute un 2 au plateau de jeu
	while(liste != NULL || compteur <= compteur2){
		if(compteur == compteur2){
			t_Plateau[liste->x][liste->y] = 2;
		}
		compteur++;
		liste = liste->suivant;
	}
}
