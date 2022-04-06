#ifndef _2048_LUCAS_H__
#define _2048_LUCAS_H__
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
//structure définissant une liste de coordonées.
typedef struct element_liste{
	int x;
	int y;
	struct element_liste *suivant;
}element_liste;

typedef struct element_liste* Tete;


/**
 * @fn element_liste* creerElement(int x, int y)
 * @author Lucas HUBERT <hubertluca@eisti.eu>
 * @date 01/04/2020
 * @version 1.0
 * @brief Fonction qui permet de générer un noeud d'une liste.
 * @return Un pointeur sur le noeud.
 * @param Le contenu du noeud.
 */
element_liste* creerElement(int x, int y);


/**
 * @fn void ajouterElementDebut(Tete* teteListe, int x, int y)
 * @author Lucas HUBERT <hubertluca@eisti.eu>
 * @date 01/04/2020
 * @version 1.0
 * @brief Procédure permettant d'ajouter un noeud au début d'une liste.
 * @param L'adresse de la liste et l'élément à ajouter.
 */
void ajouterElementDebut(Tete* teteListe, int x, int y);


/**
 * @fn void sauvegarde(int** plateau, int taille, char fich[100])
 * @author Lucas HUBERT <hubertluca@eisti.eu>
 * @date 06/05/2020
 * @version 1.0
 * @brief Procédure permettant de sauvegarder un plateau de jeu dans un fichier.
 * @param Le pointeur sur le tableau à 2 dimensions, la taille du tableau et le nom du fichier de sauvegarde.
 */
void sauvegarde(int** plateau, int taille, char fich[100]);


/**
 * @fn int restauration(int** plateau, char fich[100])
 * @author Lucas HUBERT <hubertluca@eisti.eu>
 * @date 06/05/2020
 * @version 1.0
 * @brief Fonction permettant de restaurer une sauvegarde d'une partie de 2048.
 * @param Un double pointeur de type int et le nom du fichier de sauvegarde à restaurer.
 * @return La taille du plateau de jeu
 */
int restauration(int*** plateau, char fich[100]);


/*!
 * @fn void ajouter(int** t_Plateau, int taille)
 * @author Lucas HUBERT <hubertlucas@eisti.eu>
 * @date 06/05/2020
 * @version 1.0
 * @brief Procédure qui ajoute un 2 après chaque coup
 * @param Le pointeur sur le tableau à 2 dimensions et la taille du tableau
*/
void ajouter(int** t_Plateau, int taille);


#endif