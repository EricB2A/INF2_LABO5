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

void affichageBateau(const Bateau* bateau){

       printf("%s %30s \n",
              MESSAGE_NOM_BATEAU,
              bateau->nom);

       printf("%s %30s \n",
              MESSAGE_CATEGORIES,
              NOM_TYPES_BATEAUX[bateau->typeBateau]);

       if(typeBateau(bateau) == BATEAU_VOILIER){
              printf("%s %*" PRIu16 " %s \n",
                     MESSAGE_VOILE,
                     bateau->uTypeBateau.bateauVoilier.surfaceVoile,
                     MESSAGE_VOILE_UNITE);

       }else{ // BATEAU A MOTEUR

              printf("%s %30s \n",
                     MESSAGE_CATEGORIES,
                     NOM_TYPES_BATEAUX[bateau->typeBateau]);

              printf("%s %*" PRIu16 " %s \n",
                     MESSAGE_PUISSANCE_MOTEUR,
                     bateau->uTypeBateau.bateauMoteur.puissanceMoteur,
                     MESSAGE_PUISSANCE_MOTEUR_UNITE
                     );

              if(typeBateauMoteur(bateau) == BATEAU_PLAISANCE){

                     printf("%s %30s \n",
                            MESSAGE_NOM_PROPRIETAIRE,
                            bateau->uTypeBateau.bateauMoteur.uTypeBateauMoteur.bateauPlaisance.nomProprietaire);
                     
                     printf("%s %*" PRIu8 " %s \n",
                            MESSAGE_LONGUEUR_BATEAU,
                            bateau->uTypeBateau.bateauMoteur.uTypeBateauMoteur.bateauPlaisance.nomProprietaire,
                            MESSAGE_LONGUEUR_BATEAU_UNITE
                            );
                     
              }
       }


  
   
   printf("\n");
}