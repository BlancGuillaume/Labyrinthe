
#include "Labyrinthe.h"

/**
 * Parcours tout le graphe en utilisant la m�thode de largeur
 * => utilisation d'une file
 * @param leLabyrinthe contient notamment le graphe � parcourir
 *
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
    int nbSommetDansMarque = 0; // au d�but marque est vide

    Sommet v; //sommet temporaire;
    Sommet u;
    Sommet depart = leLabyrinthe.graphe[0];
    Sommet sortie = leLabyrinthe.graphe[tailleMax - 1];

    // Ajout des coordonnes de d�part
    marque[0] = depart ;

    File file = initialiseFile();
    ajouteSommetDansFile(depart, &file);

    while (    (isFileVide(file) != OUI)
    		&& (sortieTrouvee != OUI))
    {
        v = retireElementFile(&file);
        if (sommetsEquals(v, sortie) == OUI)
        {
            sortieTrouvee = OUI;
        }
        else
        {
            for (i = 1 ; i < degreExt(v); i++)
            {
                u = iSuccesseur(leLabyrinthe.graphe, v, i);

                if (sommetPresentDansMarque(marque, u, nbSommetDansMarque,
                		                    tailleMax) == NON)
                {
                    ajouteSommetDansMarque(&marque, u, nbSommetDansMarque, tailleMax);
                    // Mise � jour du nombre de sommets dans Marque
                    nbSommetDansMarque++;

                    ajouteSommetDansFile(u, &file);
                    u.predecesseur = &v;
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
 *
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

/**
 * Retourne la valeur du i�me successeur du sommet
 * @param Graphe le Graphe (tableau) qui contient tous les sommets
 * 				 et qui correspond au labyrinthe (matrice)
 * @param leSommet a rechercher dans le graphe
 * @param i l'indice du i�me successeur de leSommet (0 <= i <= 4)
 * @return sommetRenvoye le i�me successeur
 *
 * @author Guillaume Blanc
 */
Sommet iSuccesseur(Sommet Graphe[], Sommet leSommet, int i)
{

	Sommet sommetRenvoye; //le i�me successeur (sommet) du sommet �tudi�
	int sommetTrouve = NON;
	int indiceParcoursGraphe = 0;

	do {
		if (sommetsEquals( Graphe[indiceParcoursGraphe], leSommet))
		{
			// Les 2 sommets sont �gaux => On peut trouver le i�me successeur
			// i-1 pour g�rer le fait que l'on commence � 1
			// dans le for de parcoursGrapheEnLargeur
			sommetRenvoye = Graphe[indiceParcoursGraphe].successeur[i-1];
			sommetTrouve = OUI;
		}
		indiceParcoursGraphe++;
		//TODO g�rer le cas d'erreur si leSommet n'est pas dans le Graphe ...
	} while (sommetTrouve != OUI);

	return sommetRenvoye;
}

/**
 * Ajoute le sommet parcouru dans un tableau sommet : Marque
 * => Permet d'�viter un cycle infini dans le pacours du Graphe
 * @param marque le tableau qui contient tous les sommets marqu�s
 * @param aAjouter le sommet � ajouter dans marque
 * @param indiceAjout l'indice de marque dans lequel il faut ajouter sommet
 * @param tailleMax la taille maximale de marque
 *
 * @author Guillaume Blanc
 */
void ajouteSommetDansMarque(Sommet * marque[], Sommet aAjouter,
		                    int indiceAjout, int tailleMax )
{
	if (indiceAjout > -1 && indiceAjout < tailleMax)
	{
		marque[indiceAjout] = aAjouter;
	}
	else
	{
		// Ca ne devrait jamais arriver mais bon ...
		printf("Ajout du sommet impossible l'indice d'ajout dans marque donn� "
			   " est soit n�gatif soit sup�rieure � la taille maximum");
	}
}

/**
 * D�termine si le sommet est pr�sent dans marque
 * @param marque le tableau qui contient tous les sommets marqu�s
 * @param aComparer le sommet � Comparer avec les sommets dans marques
 * @param indiceMaximum le dernier indice qui contient un Sommet
 * @param tailleMax de marque
 * @return OUI (1) si il est pr�sent, sinon NON(0)
 *
 * @author Guillaume Blanc
 */
int sommetPresentDansMarque(Sommet marque[], Sommet aComparer,
							int indiceMaximum, int tailleMax)
{
	int indiceParcoursMarque = 0;
	int estPresent = NON; // Par d�faut => OUI si il est trouv�

	if (indiceMaximum > -1 && indiceMaximum < tailleMax)
	{

			do
			{
				if (sommetsEquals(marque[indiceParcoursMarque], aComparer) == OUI)
				{
					estPresent = OUI;
				}
				indiceParcoursMarque++;
			} while (indiceParcoursMarque < indiceMaximum && estPresent == NON);
	}
	else
	{
			// Ca ne devrait jamais arriver mais bon ...
			printf("Comparaison impossible l'indice maximum donn� "
				   " est soit n�gatif soit sup�rieure � la taille maximum");
	}

	return estPresent;
}

/**
 * D�termine le nombre de successeurs (degreExt) du sommet pass� en param�tre
 * @param leSommet le sommet donc on doit d�terminer le nombre de successeurs
 * @return nombreDeSuccesseurs 0<= nombreDeSuccesseurs <= 4
 *
 * @author Guillaume Blanc
 */
int degreExt(Sommet leSommet)
{

	int indiceParcoursSuccesseurs = 0;
	int nombreDeSuccesseurs = 0; // <==> degrExt

	// Parcours du tableau de successeur du sommet
	do {
		if (leSommet.successeur[indiceParcoursSuccesseurs] != NULL)
		{
			nombreDeSuccesseurs++;
		}
	} while(leSommet.successeur[indiceParcoursSuccesseurs] < 4);

	return nombreDeSuccesseurs;
}
