#include "Labyrinthe.h"

void testSommetsEquals()
{
	Sommet sommet1;
	sommet1.coordonneeCase.num_col = 2;
	sommet1.coordonneeCase.num_ligne = 4;

	Sommet sommet2;
	sommet2.coordonneeCase.num_col = 8;
	sommet2.coordonneeCase.num_ligne = 4;

	Sommet sommet3;
	sommet3.coordonneeCase.num_col = 2;
	sommet3.coordonneeCase.num_ligne = 4;

	Sommet sommet4;
	sommet4.coordonneeCase.num_col = 12;
	sommet4.coordonneeCase.num_ligne = 13;


	// Test avec deux sommets qui ont une des coordonnes en commun mais pas deux
	if (sommetsEquals(sommet1, sommet2) == NON)
	{
		printf("S1 et S2 ne sont pas sences etre egaux => ils ne le sont pas : OK\n");
	}
	else
	{
		printf("S1 et S2 ne sont pas sences etre egaux => ils le sont : PROBLEME\n");
	}

	// Test avec deux sommets qui n'ont rien en commun
	if (sommetsEquals(sommet1, sommet4) == NON)
	{
		printf("S1 et S4 ne sont pas sences etre egaux => ils ne le sont pas : OK\n");
	}
	else
	{
		printf("S1 et S4 ne sont pas sences etre egaux => ils le sont : PROBLEME\n");
	}


	// Test avec deux sommets égaux
	if (sommetsEquals(sommet1, sommet3) == OUI)
	{
		printf("S1 et S3 sont  sences etre egaux => ils le sont : OK ");
	}
	else
	{
		printf("S1 et S3 sont sences etre egaux => ils ne le sont pas : PROBLEME");
	}
}

void testISuccesseur()
{
	/*
	Labyrinthe leLabyrinthe;

	Sommet sommet1;
	sommet1.coordonneeCase.num_col = 1;
	sommet1.coordonneeCase.num_ligne = 11;

	Sommet sommet2;
	sommet2.coordonneeCase.num_col = 2;
	sommet2.coordonneeCase.num_ligne = 22;
	sommet2.successeur[0]=&sommet1;

	Sommet sommet3;
	sommet3.coordonneeCase.num_col = 3;
	sommet3.coordonneeCase.num_ligne = 33;
	sommet3.successeur[0]=&sommet1;
	sommet3.successeur[1]=&sommet2;

	Sommet sommet4;
	sommet4.coordonneeCase.num_col = 4;
	sommet4.coordonneeCase.num_ligne = 44;
	sommet4.successeur[1]=&sommet1;
	sommet4.successeur[2]=&sommet2;
	sommet4.successeur[3]=&sommet3;

	int i;

	for (i = 0; i < 4; i++) {
	    leLabyrinthe.graphe[i] = (Sommet*)malloc(sizeof(Sommet));
	}

	printf("coucou");
	leLabyrinthe.graphe[0] = sommet1;
	printf("aurevoir");
	leLabyrinthe.graphe[1] = sommet2;
	leLabyrinthe.graphe[2] = sommet3;
	leLabyrinthe.graphe[3] = sommet4;

	Sommet sommetRenvoye = iSuccesseur(leLabyrinthe.graphe, sommet4, 2);
	printf("Col attendu 1, obtenu : %d", sommetRenvoye.coordonneeCase.num_col);
	printf("Lig attendu 11, obtenu : %d", sommetRenvoye.coordonneeCase.num_ligne);*/

}
