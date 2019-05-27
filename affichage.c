/*
 -----------------------------------------------------------------------------------
 Laboratoire : <nn>
 Fichier     : <nom du fichier>.cpp
 Auteur(s)   : <prénom> <nom>
 Date        : <jj.mm.aaaa>

 But         : <à compléter>

 Remarque(s) : <à compléter>

 Compilateur : MinGW-g++ <x.y.z>
 -----------------------------------------------------------------------------------
*/

#include "affichage.h"

void affichageBateau(const Bateau bateau){
       printf("%s %30s \n", MESSAGE_NOM_BATEAU, bateau.nom);
       return;
   printf("%-*s %*s \n", 
          ALIGNEMENT_PORT_GAUCHE,
          MESSAGE_NOM_BATEAU,
          ALIGNEMENT_PORT_DROITE,
          bateau.nom);

   if(bateau.typeBateau == BATEAU_VOILIER){
      printf("%.*s %*s \n", 
             ALIGNEMENT_PORT_GAUCHE,
             MESSAGE_CATEGORIES, 
             ALIGNEMENT_PORT_DROITE,
             NOM_TYPES_BATEAUX[bateau.typeBateau]);

      printf("%-*s %*" PRIu16" %-s \n", 
             ALIGNEMENT_PORT_GAUCHE,
             MESSAGE_VOILE, 
             ALIGNEMENT_PORT_DROITE,
             bateau.uTypeBateau.bateauVoilier.surfaceVoile,
             MESSAGE_VOILE_UNITE);
   }else{
      printf("%-*s %*s \n", 
             ALIGNEMENT_PORT_GAUCHE,
             MESSAGE_CATEGORIES, 
             ALIGNEMENT_PORT_DROITE,
             NOM_TYPES_BATEAUX_MOTEUR[bateau.uTypeBateau.bateauMoteur.typeBateauMoteur]);

      printf("%-*s %*" PRIu16" %-s \n", 
             ALIGNEMENT_PORT_GAUCHE,
             MESSAGE_PUISSANCE_MOTEUR,
             ALIGNEMENT_PORT_DROITE,
             bateau.uTypeBateau.bateauMoteur.puissanceMoteur,
             MESSAGE_PUISSANCE_MOTEUR_UNITE);

      if(bateau.uTypeBateau.bateauMoteur.typeBateauMoteur == BATEAU_MOTEUR){
             printf("%-*s %*" PRIu8 " %-s \n",
                    ALIGNEMENT_PORT_GAUCHE,
                    MESSAGE_CAPACITE_PECHE_MAX,
                    ALIGNEMENT_PORT_DROITE,
                    bateau.uTypeBateau.bateauMoteur.uTypeBateauMoteur.bateauPeche.capacitePecheMax,
                    MESSAGE_CAPACITE_PECHE_MAX_UNITE);
      }
      else if (bateau.uTypeBateau.bateauMoteur.typeBateauMoteur == BATEAU_PLAISANCE){

             printf("%-*s %*s \n",
                    ALIGNEMENT_PORT_GAUCHE,
                    MESSAGE_NOM_PROPRIETAIRE,
                    ALIGNEMENT_PORT_DROITE,
                    bateau.uTypeBateau.bateauMoteur.uTypeBateauMoteur.bateauPlaisance.nomProprietaire);

             printf("%-*s %*" PRIu8" %-s \n",
                    ALIGNEMENT_PORT_GAUCHE,
                    MESSAGE_LONGUEUR_BATEAU,
                    ALIGNEMENT_PORT_DROITE,
                    bateau.uTypeBateau.bateauMoteur.uTypeBateauMoteur.bateauPlaisance.longueur,
                    MESSAGE_LONGUEUR_BATEAU_UNITE);
      }
   }
   printf("\n");
}