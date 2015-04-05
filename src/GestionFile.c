#include "Labyrinthe.h"

/**
 * Initialise la file
 *
 * @author Guillaume Blanc
 */
 File initialiseFile()
 {
	 File laFile;
	 laFile.tete = NULL;
	 laFile.queue = NULL;

	 return laFile;
 }

 /**
  * Ajoute un element à la file
  *
  * @author Guillaume Blanc && Romain Daguet
  */
  void ajouteSommetDansFile(Sommet *sommet, File *f)
  {
      if ((sommet != NULL) && (f != NULL))
      {
          // Création de l'élément à ajouter
          Element *toAdd  = (Element *)malloc(sizeof(Element));

          // On ajoute le sommet dans l'élement
          toAdd->sommet = *sommet;
          // On fait pointer l'élément crée sur la queue de la file
          toAdd->suivant = f->queue;
          // On définit l'élément comme la nouvelle queue de la file
          f->queue = toAdd;
      }
  }

  /**
   * Retire un élément de la file
   *
   * @author Guillaume Blanc && Romain Daguet
   */
   Sommet retireElementFile(File * f)
   {
       Element * elementARetirer = f->tete;
       Sommet sommetARenvoyer = f->tete->sommet;
       f->tete = f->tete->suivant;

       free(elementARetirer);
       return sommetARenvoyer;
   }

   /**
    * Détermine si la file est vide
    *
    * @author Guillaume Blanc
    */
   int isFileVide(File * f)
   {
	   return (f->queue == NULL && f->tete == NULL ? OUI : NON);
   }
