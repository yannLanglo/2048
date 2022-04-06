#ifndef _2048_ELISE_H__
#define _2048_ELISE_H__
#include <stdio.h>
#include <stdlib.h>
 

/*!
 *	\fn int haut(int** t_Plateau, int taille)
 *	\author Elise Forçans <forcanseli@eisti.eu>
 *	\version 1.0 
 *	\date 30 janvier 2020
 *
 *	\brief vérifie si le mouvement vers le haut est possible
 *
 *	\param t_Plateau : plateau de jeu
 *		   taille : taille du tableau
 *
 *	\return res : 1 si le déplacement vers le haut est possible, 0 sinon
 *
 *  \remarks
*/

int haut(int** t_Plateau, int taille);

/*!
 *	\fn int bas(int** t_Plateau, int taille)
 *	\author Elise Forçans <forcanseli@eisti.eu>
 *	\version 1.0 
 *	\date 30 janvier 2020
 *
 *	\brief vérifie si le mouvement vers le bas est possible
 *
 *	\param t_Plateau : plateau de jeu
 *		   taille : taille du tableau
 *
 *	\return res : 1 si le déplacement vers le bas est possible, 0 sinon
 *
 *  \remarks
*/

int bas(int** t_Plateau, int taille);

/*!
 *	\fn int droite(int** t_Plateau, int taille)
 *	\author Elise Forçans <forcanseli@eisti.eu>
 *	\version 1.0 
 *	\date 30 janvier 2020
 *
 *	\brief vérifie si le mouvement vers la droite est possible
 *
 *	\param t_Plateau : plateau de jeu
 *		   taille : taille du tableau
 *
 *	\return res : 1 si le déplacement vers la droite est possible, 0 sinon
 *
 *  \remarks
*/

int droite(int** t_Plateau, int taille);

/*!
 *	\fn int gauche(int** t_Plateau, int taille)
 *	\author Elise Forçans <forcanseli@eisti.eu>
 *	\version 1.0 
 *	\date 30 janvier 2020
 *
 *	\brief vérifie si le mouvement vers la gauche est possible
 *
 *	\param t_Plateau : plateau de jeu
 *		   taille : taille du tableau
 *
 *	\return res : 1 si le déplacement vers la gauche est possible, 0 sinon
 *
 *  \remarks
*/

int gauche(int** t_Plateau, int taille);

/*!
 *	\fn int mouvement(int** t_Plateau, int taille)
 *	\author Elise Forçans <forcanseli@eisti.eu>
 *	\version 1.0 
 *	\date 30 janvier 2020
 *
 *	\brief vérifie si un mouvement est possible
 *
 *	\param t_Plateau : plateau de jeu
 *		   taille : taille du tableau
 *
 *	\return res : 1 si au moins un déplacement est possible, 0 sinon
 *
 *  \remarks
*/

int mouvement(int** t_Plateau, int taille);

#endif