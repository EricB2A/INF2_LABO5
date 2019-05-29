/*
 -----------------------------------------------------------------------------------
 Laboratoire : 05
 Fichier     : affichage.c
 Auteur(s)   : Eric Bousbaa, Lucas Gianinetti, Cassandre Wojciechowski
 Date        : 29.05.2019

 But         : Définition des fonctions d'affichage de bateau et de taxe par 
 * catégorie de bateau.

 Remarque(s) : -

Compilateur : - MinGW-gcc 6.3.0
              - Apple LLVM version 9.0.0 (clang-900.0.39.2)
 -----------------------------------------------------------------------------------
*/

#include "affichage.h"

void affichageBateau(const Bateau* bateau){

       // affichage nom bateau
       printf(ALIGNEMENT_GAUCHE SEPARATEUR" %s \n",
              MESSAGE_NOM_BATEAU,
              bateau->nom);

        // affichage catégorie du bateau
               printf(ALIGNEMENT_GAUCHE SEPARATEUR" %s \n",
                     MESSAGE_CATEGORIES,
                     NOM_TYPES_BATEAUX[bateau->typeBateau]);

       if(typeBateau(bateau) == BATEAU_VOILIER){

              // affichage surface voile
              printf(ALIGNEMENT_GAUCHE SEPARATEUR" %" PRIu16 " %s \n",
                     MESSAGE_VOILE,
                     bateau->uTypeBateau.bateauVoilier.surfaceVoile,
                     MESSAGE_VOILE_UNITE);

       }else{ // BATEAU A MOTEUR
                    
              // affichage catégorie pour bateau à moteur
              printf(ALIGNEMENT_GAUCHE SEPARATEUR" %s \n",
                     MESSAGE_CATEGORIES_MOTEUR,
                     NOM_TYPES_BATEAUX_MOTEUR[bateau->uTypeBateau.bateauMoteur.typeBateauMoteur]);

              // affichage puissance moteur
              printf(ALIGNEMENT_GAUCHE SEPARATEUR" %" PRIu16 " %s \n",
                     MESSAGE_PUISSANCE_MOTEUR,
                     bateau->uTypeBateau.bateauMoteur.puissanceMoteur,
                     MESSAGE_PUISSANCE_MOTEUR_UNITE);

              if(typeBateauMoteur(bateau) == BATEAU_PLAISANCE){

                     // affichage propriétaire
                     printf(ALIGNEMENT_GAUCHE SEPARATEUR " %s \n",
                            MESSAGE_NOM_PROPRIETAIRE,
                            bateau->uTypeBateau.bateauMoteur.uTypeBateauMoteur.bateauPlaisance.nomProprietaire);

                     printf(ALIGNEMENT_GAUCHE SEPARATEUR" %" PRIu8 " %s \n",
                            MESSAGE_LONGUEUR_BATEAU,
                            bateau->uTypeBateau.bateauMoteur.uTypeBateauMoteur.bateauPlaisance.longueur,
                            MESSAGE_LONGUEUR_BATEAU_UNITE);

              }else{ // BATEAU PECHE

              }
       }

       printf("\n");
}

void affichageTaxe(TaxeTypeBateau* taxeTypeBateau){
    assert(taxeTypeBateau);

    for(size_t i = 0; i < NBR_TAXE_TYPE_BATEAU; i++){
           printf("%s "SEPARATEUR"\n", NOM_TYPES_BATEAUX_TAXES[i]);

           printf(ALIGNEMENT_GAUCHE SEPARATEUR " " TAXE_FORMAT_PRECISION " " MESSAGE_TAXE_UNITE "\n",
                  MESSAGE_TAXE_SOMME,
                  (taxeTypeBateau + i)->sommeTotale);
           printf(ALIGNEMENT_GAUCHE  SEPARATEUR " " TAXE_FORMAT_PRECISION " " MESSAGE_TAXE_UNITE "\n",
                     MESSAGE_TAXE_MOYENNE,
                  (taxeTypeBateau + i)->montantMoyen);
           printf(ALIGNEMENT_GAUCHE  SEPARATEUR " "TAXE_FORMAT_PRECISION " " MESSAGE_TAXE_UNITE "\n",
                     MESSAGE_TAXE_MEDIANE,
                  (taxeTypeBateau + i)->montantMedian);
              printf("\n");
    }

}
