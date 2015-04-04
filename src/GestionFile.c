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
  * Ajoute un element � la file
  * @author Guillaume Blanc && Romain Daguet
  */
  void ajouteSommetDansFile(Sommet *sommet, file *f)
  {
      if ((sommet != null)&&(f != null))
      {
          // Cr�ation de l'�l�ment � ajouter
          Element toAdd;

          // malloc


          // On ajoute le sommet dans l'�lement
          toAdd.sommet=sommet;
          // On fait pointer l'�l�ment cr�e sur la queue de la file
          toAdd.suivant=f.queue;
          // On d�finit l'�l�ment comme la nouvelle queue de la file
          f.queue = toAdd;
      }
  }

  /**
   * Retire un �l�ment de la file
   * @author Guillaume Blanc && Romain Daguet
   */
   Sommet retireElementFile(file * f)
   {
       Element * elementARetirer = f->tete;
       f->tete = f->tete->suivant;
       free(ellementARetirer)

   }
