#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NON 0
#define OUI 1

typedef struct coordonnee {
    unsigned int num_ligne,num_col;
} Coordonnee;


typedef
struct sommet
{
    Coordonnee coordonneeCase;
    struct sommet *predecesseur;
    struct sommet *successeur[4];

} Sommet;

typedef struct element {
    Sommet sommet;
    struct element * suivant;
} Element;

typedef struct file {
    Element * tete;  // premier
    Element * queue; // dernier élément de la file
} File;

typedef
struct labyrinthe
{
    // nombres de ligne et de colonnes du labyrinthe
    int nb_ligne,
        nb_colonne;

    Coordonnee arrivee,
               depart;

    char ** matrice;

    Sommet graphe[];

} Labyrinthe;

/********************* Fonctions liées aux files **********************/
File initialiseFile();
void ajouteSommetDansFile(Sommet *sommet, File *f);
int isFileVide(File * f);

/******************** Fonctions liées aux graphes *********************/
void parcoursGrapheEnLargeur(Labyrinthe leLabyrinthe);
int sommetsEquals(Sommet sommet1, Sommet sommet2);
Sommet iSuccesseur(Sommet Graphe[], Sommet leSommet, int i);
void ajouteSommetDansMarque(Sommet marque[], Sommet aAjouter,
							int indiceAjout, int tailleMax );
int sommetPresentDansMarque(Sommet marque[], Sommet aComparer,
							int indiceMaximum, int tailleMax);


