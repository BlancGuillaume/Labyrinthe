#include "Labyrinthe.h"

/**
 * Initialise la file
 * @author Guillaume Blanc
 */
 File initialiseFile()
 {

    //init pointeur tete queue
 }

 /**
  * Ajoute un element à la file
  * @author Guillaume Blanc && Romain Daguet
  */
  void ajouteSommetDansFile(Sommet *sommet, file *f)
  {
      if ((sommet != null)&&(f != null))
      {
          // Création de l'élément à ajouter
          Element toAdd;

          // malloc


          // On ajoute le sommet dans l'élement
          toAdd.sommet=sommet;
          // On fait pointer l'élément crée sur la queue de la file
          toAdd.suivant=f.queue;
          // On définit l'élément comme la nouvelle queue de la file
          f.queue = toAdd;
      }
  }

  /**
   * Retire un élément de la file
   * @author Guillaume Blanc && Romain Daguet
   */
   Sommet retireElementFile(file * f)
   {
       Element * elementARetirer = f->tete;
       f->tete = f->tete->suivant;
       free(ellementARetirer)

   }
