
#include "Labyrinthe.h"

#define NON 0
#define OUI 1


/**
 * Parcours tout le graphe en utilisant la m�thode de largeur
 * => utilisation d'une file
 * @param leLabyrinthe contient notamment le graphe � parcourir
 * @author Guillaume Blanc
 */
void parcoursGrapheEnLargeur(Labyrinthe leLabyrinthe)
{
    int sortieTrouvee = NON; // = 0
    int i;
    /**
     * Initialisation du tableau de marques
     * Quand un sommet est parcouru il est ajout� au tableau
     * => permet d'�viter les cycles
     */
    // nombre de sommets maximum : produits du nb de lignes et col de la matrice
    int tailleMax = leLabyrinthe.nb_ligne * leLabyrinthe.nb_colonne;
    Sommet marque[tailleMax];

    Sommet v; //sommet temporaire;
    Sommet u;
    Sommet depart = leLabyrinthe.graphe[0];
    Sommet sortie = leLabyrinthe.graphe[tailleMax - 1];

    // Ajout des coordonnes de d�part
    marque[0] = depart ;

    File file = initialiseFile();
    ajouteSommetDansFile(file, depart);

    while ((!isFileVide(file) && (sortieTrouvee != OUI)))
    {
        v = retireElement(file);
        if (sommetsEquals(v, sortie) == OUI)
        {
            sortieTrouvee = OUI;
        }
        else
        {
            for (i = 1 ; i < degreExt(leLabyrinthe.graphe, v); i++)
            {
                u = iSuccesseur(leLabyrinthe.graphe, v, i);
                if (!sommetPresentDansMarque(u))
                {
                    ajouteSommetDansMarque(marque, u);
                    ajouteSommetDansFile(file, u);
                    u.predecesseur = v;
                }
            }
        }
    }
}

/**
 * D�termine si 2 sommets sont �gaux
 * => ils poss�dent les m�mes coordonn�es
 * @param sommet1 premier sommet � comparer
 * @param sommet2 deuxi�me sommet � comparer � sommet1
 * @author Guillaume Blanc
 */
int sommetsEquals(Sommet sommet1, Sommet sommet2)
{
    return ((   (sommet1.coordonneeCase.num_ligne
             ==  sommet2.coordonneeCase.num_ligne)
             && (sommet2.coordonneeCase.num_col
             ==  sommet2.coordonneeCase.num_col)) ?
             OUI:
             NON);
}
