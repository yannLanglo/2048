#include "2048_Yann.h"
#include "2048_Julie.h"
#include "2048_Elise.h"
#include "2048_Lucas.h"

int haut(int** t_Plateau, int taille)
{
    int res; /* Valeur de retour */
    int i; /* Variable de boucle 1 */
    int j = 0; /* Variable de boucle 2 */
    int w;

    /* Initialisation de la valeur de retour à FAUX */
	res = 0;
    
    /* On parcourt le plateau de haut en bas */
	while ((res == 0) && (j < taille)){
	/* On parcourt les colonnes */ 
        i = 0;
		while ((res == 0) && (i < taille-1)) {
            /* Si la case au dessus n'est pas occupée ou que ces deux cases sont égales */
            if (t_Plateau[i][j] == t_Plateau[i+1][j] && t_Plateau[i][j] != 0){ 
                /* La valeur de retour prend VRAI */;
                res = 1;
            
            }else if(t_Plateau[i][j] == 0){
                w = i;
                while((w < taille) && (res == 0)){
                    if(t_Plateau[w][j] != 0){
                        res = 1;
                    }
                    w++;
                }
            }
            i++;
        }
        j++;
    }
    /* On retourne la valeur de retour */
	return(res);
}


int bas(int** t_Plateau, int taille)
{
    int res; /* Valeur de retour */
    int i; /* Variable de boucle 1 */
    int j = 0; /* Variable de boucle 2 */
    int w;
    
    /* Initialisation de la valeur de retour à FAUX*/
	res = 0;
    
    /* On parcourt le plateau de haut en bas */
	while ((res == 0) && (j < taille)){
	/* On parcourt les colonnes */ 
        i = taille-1;
		while ((res == 0) && (i > 0)){
            /* Si la case en dessous n'est pas occupée ou que ces deux cases sont égales */
            if ((t_Plateau[i][j] != 0) && (t_Plateau[i][j] == t_Plateau[i-1][j])){ 
                /* La valeur de retour prend VRAI */
                res = 1;

            }else if(t_Plateau[i][j] == 0){
                w = i;
                while((w >= 0) && (res == 0)){
                    if(t_Plateau[w][j] != 0){
                        res = 1;
                    }
                    w--;
                }
            }
            i--;
        }
        j++;
    }
    /* On retourne la valeur de retour */
	return(res);
}

int droite(int** t_Plateau, int taille)
{
    int res; /* Valeur de retour */
    int i = 0; /* Variable de boucle 1 */
    int j; /* Variable de boucle 2 */
    int w;
    
    /* Initialisation de la valeur de retour à FAUX */
	res = 0;
    
    /* On parcourt le plateau de haut en bas */
	while ((res == 0) && (i < taille)){
	/* On parcourt les colonnes */ 
        j = taille -1;
		while ((res == 0) && (j > 0)){
            /* Si la case à sa droite n'est pas occupée ou que ces deux cases sont égales */
            if ((t_Plateau[i][j] != 0) && (t_Plateau[i][j] == t_Plateau[i][j-1])){ 
                /* La valeur de retour prend VRAI */
                res = 1;

            }else if(t_Plateau[i][j] == 0){
                w = j;
                while((w >= 0) && (res == 0)){
                    if(t_Plateau[i][w] != 0){
                        res = 1;
                    }
                    w--;
                }
            }
            j--;
        }
        i++;
    }
    /* On retourne la valeur de retour */
	return(res);
}

int gauche(int** t_Plateau, int taille)
{
    int res; /* Valeur de retour */
    int i = 0; /* Variable de boucle 1 */
    int j; /* Variable de boucle 2 */
    int w;
    
    /* Initialisation de la valeur de retour à FAUX */
	res = 0;
    
    /* On parcourt le plateau de haut en bas */
	while ((res == 0) && (i < taille)){
	/* On parcourt les colonnes */ 
        j= 0;
		while ((res == 0) && (j < taille-1)){
            /* Si la case à sa gauche n'est pas occupée ou que ces deux cases sont bien égales*/
            if ((t_Plateau[i][j] != 0) && (t_Plateau[i][j] == t_Plateau[i][j+1])){ 
                /* La valeur de retour prend VRAI */
                res = 1;

            }else if(t_Plateau[i][j] == 0){
                w = j;
                while((w < taille) && (res == 0)){
                    if(t_Plateau[i][w] != 0){
                        res = 1;
                    }
                    w++;
                }
            }
            j++;
        }
        i++;
    }
    /* On retourne la valeur de retour */
	return(res);
}


int mouvement(int** t_Plateau, int taille)
{
    int res; /* Valeur de retour */
    int res1; /* Valeur de retour de la fonction haut */
    int res2; /* Valeur de retour de la fonction bas */
    int res3; /* Valeur de retour de la fonction droite */
    int res4; /* Valeur de retour de la fonction gauche */
    
    /* La variable prend la valeur de retour de la fonction haut */
    res1 = haut(t_Plateau,taille);

    /* La variable prend la valeur de retour de la fonction bas */
    res2 = bas(t_Plateau,taille);

    /* La variable prend la valeur de retour de la fonction droite */
    res3 = droite(t_Plateau,taille);

    /* La variable prend la valeur de retour de la fonction gauche */
    res4 = gauche(t_Plateau,taille);

    /* Si tous les déplacements sont impossible */
    if ((res1 == 0) && (res2 == 0) && (res3 == 0) && (res4 == 0)){
        /* La valeur de retour prend FAUX */
        res = 0;
    }
    else{
        /* La valeur de retour prend VRAI */
        res = 1;
    }
    /* On retourne la valeur de retour */
    return(res);
}
















