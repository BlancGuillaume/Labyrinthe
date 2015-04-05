//
//  Convert.c
//  Labyrinthe
//
//  Created by Romain Daguet on 25/03/2015.
//  Copyright (c) 2015 Romain Daguet. All rights reserved.
//

#include "Labyrinthe.h"


/* Rempli les successeurs du sommet passÃ© en parametre.
 *
 * Le graphe est un tableau de sommets de taille=(nb_lignes * nb_colonnes)
 *
 * @Author : Romain Daguet
*/
void successeurs (Labyrinthe Laby, Sommet *sommet){
    
    if (sommet->coordonneeCase.num_col+1 <= Laby.nb_colonne) {
        //sommet->successeur[] sommet->coordonneesCase.colonne;
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
    
}
