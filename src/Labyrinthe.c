/*
 ============================================================================
 Name        : Labyrinthe.c
 Author      : Guillaume Blanc
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "Labyrinthe.h"

int main() {
	FILE* file;
	file = fopen("map.txt", "r" );
	if(file == NULL) {
		printf("\n Erreur ouverture fichier\n");
	}
	else {
		Labyrinthe labyrinthe;
		lire_fichier(file,&labyrinthe);
		Affiche_matrice(&labyrinthe);
		// la suite est à faire ... là
		libere_matrice(&labyrinthe);
	}
	return 0;
}

void lire_fichier(FILE *f, Labyrinthe *lab) {

	int i, j;
	char c;
	lire_coordonnee(f,&lab->depart);
	lire_coordonnee(f,&lab->arrivee);
	fscanf(f,"%i\n",&lab->nb_ligne);
	fscanf(f,"%i\n",&lab->nb_colonne);
	lab->matrice = (char **) malloc(sizeof(char *)*lab->nb_ligne);
	if(lab->matrice==NULL) {
		printf("\nallocation impossible, pas assez de mémoire\n");
		exit (1);
	}
	else {
		for (i = 0; i < lab->nb_ligne; i++) {
			lab->matrice[i] = (char*)malloc(sizeof(char)*lab->nb_colonne);
			if (lab->matrice[i]==NULL) {
				printf("\nallocation impossible, pas assez de mémoire\n");
				exit (1);
			}
		}
	}
	for (i = 0; i < lab->nb_ligne; i++) {
		for(j=0; j< lab->nb_colonne; j++) {
			fscanf(f,"%c",&lab->matrice[i][j]);
		}
		fscanf(f,"%c",&c);  // enlève le  \n
	}
}
void Affiche_matrice(Labyrinthe *lab) {
	int i,j;
	printf("position de depart : %i;%i\n",lab->depart.num_ligne,lab->depart.num_col);
	printf("position de arrivee : %i;%i\n",lab->arrivee.num_ligne,lab->arrivee.num_col);
	printf("nb_ligne : %i; nb_colonne : %i\n", lab->nb_ligne, lab->nb_colonne);
	for (i = 0; i < lab->nb_ligne; i++) {
		//printf("\nligne %i :\n", i);
		for (j = 0; j < lab->nb_colonne; j++) {
			printf("%c",lab->matrice[i][j]);
		}
		// printf("f\n");
	}
}

void lire_coordonnee(FILE *f, Coordonnee *c) {
	fscanf(f,"%i\t%i\n",&c->num_ligne,&c->num_col);
}

void libere_matrice(Labyrinthe *lab){
	int i;
	for (i = 0; i < lab->nb_ligne; i++) {
		free(lab->matrice[i]);
	}
	free(lab->matrice);
}
