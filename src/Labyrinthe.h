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


File initialiseFile();
void ajouteSommetDansFile(Sommet *sommet, File *f);


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


void parcoursGrapheEnLargeur(Labyrinthe leLabyrinthe);
int sommetsEquals(Sommet sommet1, Sommet sommet2);
