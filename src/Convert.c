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
 * TO DO : Malloc foireux + remplir les successeurs.
*/
void successeurs (Labyrinthe Laby, Sommet *sommet){
    
    if (sommet->coordonneesCase.colonne+1 <= Laby.nb_colonne) {
        //sommet->successeur[] sommet->coordonneesCase.colonne;
    }
}


/* Converti la matrice d'entrŽe en un graphe.
 *
 * Le graphe est un tableau de sommets de taille=(nb_lignes * nb_colonnes)
 *
 * TO DO : Malloc foireux + remplir les successeurs.
 */
void matriceToGraphe (Labyrinthe *LeLabyrinthe){

    int i, j, cpt=1;
    LeLabyrinthe->graphe = (struct sommet *)malloc (sizeof(Sommet));
    
    for (i=0; i<LeLabyrinthe->nb_ligne; i++) {
        for (j=0; j<LeLabyrinthe->nb_colonne; j++) {
            if (i == LeLabyrinthe->depart.ligne && j == LeLabyrinthe->depart.colonne) {
                LeLabyrinthe->graphe[0].coordonneesCase.ligne=i;
                LeLabyrinthe->graphe[0].coordonneesCase.colonne=j;
            } else if (i == LeLabyrinthe->arrivee.ligne && j == LeLabyrinthe->arrivee.colonne) {
                LeLabyrinthe->graphe[sizeof(LeLabyrinthe->graphe)-1].coordonneesCase.ligne=i;
                LeLabyrinthe->graphe[sizeof(LeLabyrinthe->graphe)-1].coordonneesCase.colonne=j;
            }
            else {
                LeLabyrinthe->graphe[cpt].coordonneesCase.ligne=i;
                LeLabyrinthe->graphe[cpt].coordonneesCase.colonne=j;
                cpt++;
            }
        }
    }
    
}
