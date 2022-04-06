#ifndef _2048_JULIE_H__
#define _2048_JULIE_H__
#include <stdlib.h>
#include <stdio.h>
 

/*!
 *	\fn void executeHaut(int** t_Plateau, int taille)
 *	\author Julie Berrieix <berrieixju@eisti.eu>
 *	\version 1.0 
 *	\date 8 mai 2020
 *
 *	\brief execute le mouvement vers le haut en additionnant si besoin
 *
 *	\param t_Plateau : plateau de jeu
 *		   taille : taille du plateau
 *
 *  \remarks
*/
void executeHaut(int** t_Plateau, int taille);

/*!
 *	\fn void executeBas(int** t_Plateau, int taille)
 *	\author Julie Berrieix <berrieixju@eisti.eu>
 *	\version 1.0 
 *	\date 8 mai 2020
 *
 *	\brief execute le mouvement vers le bas en additonnant si besoin
 *
 *	\param t_Plateau : plateau de jeu
 *		   taille : taille du plateau
 *
 *  \remarks
*/
void executeBas(int** t_Plateau, int taille);

/*!
 *	\fn void executeGauche(int** t_Plateau, int taille)
 *	\author Julie Berrieix <berrieixju@eisti.eu>
 *	\version 1.0 
 *	\date 8 mai 2020
 *
 *	\brief execute le mouvement à gauche en additionnant si besoin
 *
 *	\param t_Plateau : plateau de jeu
 *		   taille : taille du plateau
 *
 *  \remarks
*/
void executeGauche(int** t_Plateau, int taille);

/*!
 *	\fn void executeDroite(int** t_Plateau, int taille)
 *	\author Julie Berrieix <berrieixju@eisti.eu>
 *	\version 1.0 
 *	\date 8 mai 2020
 *
 *	\brief execute le mouvement à droite en additionnant si besoin
 *
 *	\param t_Plateau : plateau de jeu
 *		   taille : taille du plateau
 *
 *  \remarks
*/
void executeDroite(int** t_Plateau, int taille);

/*!
 *	\fn void executeMouvement(int** t_Plateau, int direction, int mouvement)
 *	\author Julie Berrieix <berrieixju@eisti.eu>
 *	\version 1.0
 *	\date 8 mai 2020
 *
 *	\brief execute les mouvements
 *
 *	\param t_Plateau : plateau de jeu
 *		   taille : taille du plateau de jeu
 *		   direction : direction du mouvement (haut,bas,gauche ou droite)
 *
 *  \remarks
*/
void executeMouvement(int** t_Plateau, int taille, int direction);

#endif



