#ifndef _2048_YANN_H__
#define _2048_YANN_H__
#include <stdlib.h>
#include <stdio.h>
 
/*!
 *	\fn void viderBuffer(void)
 *	\author Yann Langlo <langloyann@eisti.eu>
 *	\version 1.0 
 *	\date 8 mai 2020
 *
 *	\brief Procédure qui vide le buffer
 *
 *  \remarks
*/
void viderBuffer(void);

/*!
 *	\fn int menuTaille(void)
 *	\author Yann Langlo <langloyann@eisti.eu>
 *	\version 1.0 
 *	\date 8 mai 2020
 *
 *	\brief Fonction qui demande à l'utilisateur la taille du plateau qu'il veut
 *
 *	\return taille : taille qui correspond à la valeur entrée par l'utilisateur
 *
 *  \remarks
*/
int menuTaille(void);

/*!
 *	\fn int** initPlateau(int taille)
 *	\author Yann Langlo <langloyann@eisti.eu>
 *	\version 1.0
 *	\date 8 mai 2020
 *
 *	\brief Fonction qui initialise le plateau de jeu
 *
 *	\param taille : taille du plateau de jeu
 *
 *  \return t_Plateau : plateau de jeu
 *
 *  \remarks
*/
int** initPlateau(int taille);

/*!
 *	\fn void afficherPlateau(int** t_Plateau, int taille)
 *	\author Yann Langlo <langloyann@eisti.eu>
 *	\version 1.0
 *	\date 8 mai 2020
 *
 *	\brief Procédure qui affiche le plateau de jeu
 *
 *	\param t_Plateau : plateau de jeu
 *		   taille : taille du plateau de jeu
 *
 *  \remarks
*/
void afficherPlateau(int** t_Plateau, int taille);

/*!
 *	\fn int menuCoup(void)
 *	\author Yann Langlo <langloyann@eisti.eu>
 *	\version 1.0
 *	\date 8 mai 2020
 *
 *	\brief Fonction qui demande quel mouvement souhaite faire l'utilisateur
 *
 *	\return valeur : direction qui correspond à la valeur entrée par l'utilisateur 
 *
 *  \remarks
*/
int menuCoup(void);

/*!
 *	\fn int verifCoup(int** t_Plateau,int taille,int direction)
 *	\author Yann Langlo <langloyann@eisti.eu>
 *	\version 1.0
 *	\date 8 mai 2020
 *
 *	\brief Fonction qui vérifie si le coup choisit par l'utilisateur est valable
 *
 *	\param t_Plateau : plateau de jeu
 *		   taille : taille du plateau de jeu 
 *		   direction : direction choisie par l'utilisateur
 *
 *  \return res : vaut 1 si le coup est valide et 0 sinon
 *
 *  \remarks
*/
int verifCoup(int** t_Plateau,int taille,int direction);

/*!
 *	\fn int victoire(int** t_Plateau,int taille)
 *	\author Yann Langlo <langloyann@eisti.eu>
 *	\version 1.0
 *	\date 8 mai 2020
 *
 *	\brief Fonction qui vérifie si le joueur a gagné
 *
 *	\param t_Plateau : plateau de jeu
 *		   taille : taille du plateau de jeu
 *
 *  \return res : vaut 1 si le joueur a gagné et 0 sinon
 *
 *  \remarks
*/
int victoire(int** t_Plateau,int taille);

/*!
 *	\fn int defaite(int mouvement)
 *	\author Yann Langlo <langloyann@eisti.eu>
 *	\version 1.0
 *	\date 8 mai 2020
 *
 *	\brief Fonction qui vérifie si le joueur a perdu
 *
 *	\param mouvement : valeur de retour de la fonction mouvement
 *
 *  \return res : vaut 1 si le joueur a perdu et 0 sinon
 *
 *  \remarks
*/
int defaite(int mouvement);

#endif