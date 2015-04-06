//
//  Convert.c
//  Labyrinthe
//
//  Created by Romain Daguet on 25/03/2015.
//  Copyright (c) 2015 Romain Daguet. All rights reserved.
//

#include "Labyrinthe.h"


/* Rempli les successeurs du sommet passe en parametre.
 *
 * Dans le sommet, le tableau successeurs, de taille 4 sera rempli ainsi :
 * [0] : adresse du successeurs du haut
 * [1] : adresse du successeurs du bas
 * [2] : adresse du successeurs du gauche
 * [3] : adresse du successeurs du droite
 * S'il n'y a pas de successeurs, ou un mur, la case est mise ˆ NULL
 *
 * @Author : Romain Daguet
*/
void successeurs (Labyrinthe Laby, Sommet *sommet){
	int i;

	for(i=0;i<sizeof(Laby.graphe);i++){

		//colonne+1
		if (sommet->coordonneeCase.num_col+1 <= Laby.nb_colonne
				&& (Laby.matrice[sommet->coordonneeCase.num_col+1][sommet->coordonneeCase.num_ligne] != '|'
				|| Laby.matrice[sommet->coordonneeCase.num_col+1][sommet->coordonneeCase.num_ligne] != '-' )
				&& Laby.graphe[i].coordonneeCase.num_col==sommet->coordonneeCase.num_col+1
				&& Laby.graphe[i].coordonneeCase.num_ligne==sommet->coordonneeCase.num_ligne) {
			sommet->successeur[0] = &Laby.graphe[i];
		}
		else{
			sommet->successeur[0] = NULL;
		}

		//colonne-1
		if (sommet->coordonneeCase.num_col-1 >= 0
						&& (Laby.matrice[sommet->coordonneeCase.num_col-1][sommet->coordonneeCase.num_ligne] != '|'
						|| Laby.matrice[sommet->coordonneeCase.num_col-1][sommet->coordonneeCase.num_ligne] != '-' )
						&& Laby.graphe[i].coordonneeCase.num_col==sommet->coordonneeCase.num_col-1
						&& Laby.graphe[i].coordonneeCase.num_ligne==sommet->coordonneeCase.num_ligne) {
					sommet->successeur[1] = &Laby.graphe[i];
				}
		else{
			sommet->successeur[1] = NULL;
		}

		//ligne-1
		if (sommet->coordonneeCase.num_ligne-1 >= 0
						&& (Laby.matrice[sommet->coordonneeCase.num_col][sommet->coordonneeCase.num_ligne-1] != '|'
						|| Laby.matrice[sommet->coordonneeCase.num_col][sommet->coordonneeCase.num_ligne-1] != '-' )
						&& Laby.graphe[i].coordonneeCase.num_col==sommet->coordonneeCase.num_col
						&& Laby.graphe[i].coordonneeCase.num_ligne==sommet->coordonneeCase.num_ligne-1) {
					sommet->successeur[2] = &Laby.graphe[i];
				}
		else{
			sommet->successeur[2] = NULL;
		}

		//ligne+1
		if (sommet->coordonneeCase.num_ligne+1 <= Laby.nb_ligne
						&& (Laby.matrice[sommet->coordonneeCase.num_col][sommet->coordonneeCase.num_ligne+1] != '|'
						|| Laby.matrice[sommet->coordonneeCase.num_col][sommet->coordonneeCase.num_ligne+1] != '-' )
						&& Laby.graphe[i].coordonneeCase.num_col==sommet->coordonneeCase.num_col
						&& Laby.graphe[i].coordonneeCase.num_ligne==sommet->coordonneeCase.num_ligne+1) {
					sommet->successeur[3] = &Laby.graphe[i];
				}
		else{
			sommet->successeur[3] = NULL;
		}


	}
}


/* Converti la matrice d'entrŽe en un graphe.
 *
 * Le graphe est un tableau de sommets de taille=(nb_lignes * nb_colonnes)
 *
 * @Author : Romain Daguet
 */
void matriceToGraphe (Labyrinthe *LeLabyrinthe){

    int i, j, cpt=1;
    LeLabyrinthe->graphe = (Sommet *)malloc (sizeof(Sommet)*LeLabyrinthe->nb_colonne*LeLabyrinthe->nb_ligne );
    
    for (i=0; i<LeLabyrinthe->nb_ligne; i++) {
        for (j=0; j<LeLabyrinthe->nb_colonne; j++) {
            if (i == LeLabyrinthe->depart.num_ligne && j == LeLabyrinthe->depart.num_col) {
                LeLabyrinthe->graphe[0].coordonneeCase.num_ligne=i;
                LeLabyrinthe->graphe[0].coordonneeCase.num_col=j;
            } else if (i == LeLabyrinthe->arrivee.num_ligne && j == LeLabyrinthe->arrivee.num_col) {
                LeLabyrinthe->graphe[sizeof(LeLabyrinthe->graphe)-1].coordonneeCase.num_ligne=i;
                LeLabyrinthe->graphe[sizeof(LeLabyrinthe->graphe)-1].coordonneeCase.num_col=j;
            }
            else {
                LeLabyrinthe->graphe[cpt].coordonneeCase.num_ligne=i;
                LeLabyrinthe->graphe[cpt].coordonneeCase.num_col=j;
                cpt++;
            }

        }
    }
    for(i=0;i<sizeof(LeLabyrinthe->graphe);i++){
    	successeurs(*LeLabyrinthe, &LeLabyrinthe->graphe[i]);
    }
    
}
