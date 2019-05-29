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

#include "bateau.h"

/*
   TODO: 
   - Faire fonction retournant le type d'un bateau {PLAISANCE, VOILIER, PECHE}
      => je vois pas comment il veut faire ça, sachant que MOTEUR/VOILIER est un type
         et PECHE/PUISSANCE en est un autre...
*/
Bateau voilier(Nom nom, uint16_t surfaceVoile){
   assert(nom);
   return (Bateau) {
      nom, 
      BATEAU_VOILIER, 
      {
         .bateauVoilier = {
            surfaceVoile
         }
      }
   };
}
Bateau bateauPeche(Nom nom, uint16_t puissancMoteur, uint8_t capacitePecheMax){
   assert(nom);
   return (Bateau) { 
      nom, 
      BATEAU_MOTEUR, 
      {
         .bateauMoteur = { 
            puissancMoteur, 
            BATEAU_PECHE, 
            {
               .bateauPeche = { 
                  capacitePecheMax
               }
            }
         }
      }
   };
}

Bateau bateauPlaisance(Nom nom, uint16_t puissanceMoteur, uint8_t longueur, Nom nomProprietaire){
   assert(nom); 
   return (Bateau) {
      nom, 
      BATEAU_MOTEUR, 
      {
         .bateauMoteur = {
            puissanceMoteur, 
            BATEAU_PLAISANCE, 
            {
               .bateauPlaisance = {
                  longueur,
                  nomProprietaire
               }
            }
         }
      }
   };
}

TypeBateau typeBateau(const Bateau* bateau){
    return bateau->typeBateau;
}
TypeBateauMoteur typeBateauMoteur(const Bateau* bateau){
    return bateau->uTypeBateau.bateauMoteur.typeBateauMoteur;
}