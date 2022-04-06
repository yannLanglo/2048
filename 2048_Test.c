#include "2048_Yann.h"
#include "2048_Julie.h"
#include "2048_Elise.h"
#include "2048_Lucas.h"
#include "2048_Test.h"

int** test_victoire(int **t_Plateau)
{
	printf("Ce test permet de montrer que le programme détecte correctement une victoire.\n");
	t_Plateau = initPlateau(4);
	t_Plateau[0][0] = 1024;
	t_Plateau[0][1] = 1024;

	return(t_Plateau);
}

int** test_defaite(int **t_Plateau)
{	
	printf("Ce test permet de montrer que le programme détecte correctement une défaite.\n");
	t_Plateau = initPlateau(4);
	t_Plateau[0][0] = 2;
	t_Plateau[0][1] = 4;
	t_Plateau[0][2] = 8;
	t_Plateau[0][3] = 32;
	t_Plateau[1][0] = 4;
	t_Plateau[1][1] = 2;
	t_Plateau[1][2] = 4;
	t_Plateau[1][3] = 64;
	t_Plateau[2][0] = 8;
	t_Plateau[2][1] = 4;
	t_Plateau[2][2] = 2;
	t_Plateau[2][3] = 32;
	t_Plateau[3][0] = 64;
	t_Plateau[3][1] = 8;
	t_Plateau[3][2] = 16;
	

	return(t_Plateau);
}

int** test_haut(int **t_Plateau)
{
	printf("Ce test permet de montrer que le programme détecte correctement lorsque le joueur ne peut pas éxécuter de déplacement vers le haut.\n");
	t_Plateau = initPlateau(4);
	t_Plateau[0][0] = 2;
	t_Plateau[0][1] = 4;

	return(t_Plateau);
}


int** test_bas(int **t_Plateau)
{
	printf("Ce test permet de montrer que le programme détecte correctement lorsque le joueur ne peut pas éxécuter de déplacement vers le bas.\n");
	t_Plateau = initPlateau(4);
	t_Plateau[3][0] = 2;
	t_Plateau[3][1] = 4;

	return(t_Plateau);
}


int** test_droite(int **t_Plateau)
{
	printf("Ce test permet de montrer que le programme détecte correctement lorsque le joueur ne peut pas éxécuter de déplacement vers le droite.\n");
	t_Plateau = initPlateau(4);
	t_Plateau[0][0] = 2;
	t_Plateau[1][0] = 4;

	return(t_Plateau);
}


int** test_gauche(int **t_Plateau)
{
	printf("Ce test permet de montrer que le programme détecte correctement lorsque le joueur ne peut pas éxécuter de déplacement vers le gauche.\n");
	t_Plateau = initPlateau(4);
	t_Plateau[0][3] = 2;
	t_Plateau[1][3] = 4;

	return(t_Plateau);
}


int** menuTest(int** t_Plateau)
{
	int saisi;

	printf("----- JEU DE TEST -----\n");
	printf("1. Test victoire.\n");
	printf("2. Test défaite.\n");
	printf("3. Test déplacement haut impossible.\n");
	printf("4. Test déplacement bas impossible.\n");
	printf("5. Test déplacement droite impossible.\n");
	printf("6. Test déplacement gauche impossible.\n");

	do{
		scanf("%d", &saisi);
		viderBuffer();

		switch(saisi){
			case 1:
				t_Plateau = test_victoire(t_Plateau);
				break;

			case 2:
				t_Plateau = test_defaite(t_Plateau);
				break;

			case 3:
				t_Plateau = test_haut(t_Plateau);
				break;

			case 4:
				t_Plateau = test_bas(t_Plateau);
				break;

			case 5:
				t_Plateau = test_gauche(t_Plateau);
				break;

			case 6:
				t_Plateau = test_droite(t_Plateau);
				break;

			default :
				printf("Erreur de saisi! Recommencez !!\n");
				break;
		}
	}while(saisi < 1 || saisi > 6);

	return(t_Plateau);
}