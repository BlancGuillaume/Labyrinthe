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
		Problem probleme;
		lire_fichier(file,&probleme);
		Affiche_matrice(&probleme);
		// la suite est à faire ... là
		libere_matrice(&probleme);
	}
	return 0;
}

void lire_fichier(FILE *f, Problem *p) {

	int i, j;
	char c;
	fscanf(f,"%s\n",p->nom);
	lire_coordonnee(f,&p->depart);
	lire_coordonnee(f,&p->arrive);
	fscanf(f,"%i\n",&p->nb_ligne);
	fscanf(f,"%i\n",&p->nb_colonne);
	p->carte = (char **) malloc(sizeof(char *)*p->nb_ligne);
	if(p->carte==NULL) {
		printf("\nallocation impossible, pas assez de mémoire\n");
		exit (1);
	}
	else {
		for (i = 0; i < p->nb_ligne; i++) {
			p->carte[i] = (char*)malloc(sizeof(char)*p->nb_colonne);
			if (p->carte[i]==NULL) {
				printf("\nallocation impossible, pas assez de mémoire\n");
				exit (1);
			}
		}
	}
	for (i = 0; i < p->nb_ligne; i++) {
		for(j=0; j< p->nb_colonne; j++) {
			fscanf(f,"%c",&p->carte[i][j]);
		}
		fscanf(f,"%c",&c);  // enlève le  \n
	}
}
void Affiche_matrice(Problem *p) {
	int i,j;
	printf("nom du labyrinthe : %s\n", p->nom);
	printf("position de depart : %i;%i\n",p->depart.num_ligne,p->depart.num_col);
	printf("position de arrivee : %i;%i\n",p->arrive.num_ligne,p->arrive.num_col);
	printf("nb_ligne : %i; nb_colonne : %i\n", p->nb_ligne, p->nb_colonne);
	for (i = 0; i < p->nb_ligne; i++) {
		//printf("\nligne %i :\n", i);
		for (j = 0; j < p->nb_colonne; j++) {
			printf("%c",p->carte[i][j]);
		}
		// printf("f\n");
	}
}

void lire_coordonnee(FILE *f, Coordonnee *c) {
	fscanf(f,"%i\t%i\n",&c->num_ligne,&c->num_col);
}

void libere_matrice(Problem *p){
	int i;
	for (i = 0; i < p->nb_ligne; i++) {
		free(p->carte[i]);
	}
	free(p->carte);
}
