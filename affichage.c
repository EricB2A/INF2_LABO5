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

       printf("%s "MESSAGE_SEPARATEUR" %s \n",
              MESSAGE_NOM_BATEAU,
              bateau->nom);

       if(typeBateau(bateau) == BATEAU_VOILIER){

               printf("%s "MESSAGE_SEPARATEUR" %s \n",
                     MESSAGE_CATEGORIES,
                     NOM_TYPES_BATEAUX[bateau->typeBateau]);

              printf("%s "MESSAGE_SEPARATEUR" %" PRIu16 " %s \n",
                     MESSAGE_VOILE,
                     bateau->uTypeBateau.bateauVoilier.surfaceVoile,
                     MESSAGE_VOILE_UNITE);

       }else{ // BATEAU A MOTEUR
                     
              printf("%s "MESSAGE_SEPARATEUR" %s \n",
                     MESSAGE_CATEGORIES,
                     NOM_TYPES_BATEAUX[bateau->uTypeBateau.bateauMoteur.typeBateauMoteur]);

              printf("%s "MESSAGE_SEPARATEUR" %" PRIu16 " %s \n",
                     MESSAGE_PUISSANCE_MOTEUR,
                     bateau->uTypeBateau.bateauMoteur.puissanceMoteur,
                     MESSAGE_PUISSANCE_MOTEUR_UNITE);

              if(typeBateauMoteur(bateau) == BATEAU_PLAISANCE){

                     printf("%s "MESSAGE_SEPARATEUR" %s \n",
                            MESSAGE_NOM_PROPRIETAIRE,
                            bateau->uTypeBateau.bateauMoteur.uTypeBateauMoteur.bateauPlaisance.nomProprietaire);

                     printf("%s "MESSAGE_SEPARATEUR" %" PRIu8 " %s \n",
                            MESSAGE_LONGUEUR_BATEAU,
                            bateau->uTypeBateau.bateauMoteur.uTypeBateauMoteur.bateauPlaisance.nomProprietaire,
                            MESSAGE_LONGUEUR_BATEAU_UNITE);
              }
       }

       printf("\n");
}

void affichageTaxe(TaxeTypeBateau* taxeTypeBateau){
    assert(taxeTypeBateau);

    for(size_t i = 0; i < taxeTypeBateaue(); i++){
           printf(MESSAGE_TAXE_SOMME" "MESSAGE_SEPARATEUR" %f\n",
           (taxeTypeBateau + i)->sommeTotale); 
           printf(MESSAGE_TAXE_MOYENNE" "MESSAGE_SEPARATEUR" %f\n",
           (taxeTypeBateau + i)->montantMoyen); 
           printf(MESSAGE_TAXE_MEDIANE" "MESSAGE_SEPARATEUR" %f\n",
           (taxeTypeBateau + i)->montantMedian);
    }

    printf("\n");
}