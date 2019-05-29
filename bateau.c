/*
 -----------------------------------------------------------------------------------
 Laboratoire : 05
 Fichier     : bateau.c
 Auteur(s)   : Eric Bousbaa, Lucas Gianinetti, Cassandre Wojciechowski
 Date        : 29.05.2019

 But         : Ce fichier contient les définitions des fonctions permettant de 
 * construire les objets "Bateau" et des fonctions déterminant le type des bateaux 
 * passés en paramètres. 

 Remarque(s) : -

 Compilateur : - MinGW-gcc 6.3.0
               - Apple LLVM version 9.0.0 (clang-900.0.39.2)
 -----------------------------------------------------------------------------------
*/

#include "bateau.h"

// Construction d'un voilier
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

// Construction d'un bateau de peche
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

// Construction d'un bateau de plaisance
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

// On retourne le type de bateau (voilier ou moteur)
TypeBateau typeBateau(const Bateau* bateau){
    return bateau->typeBateau;
}

// On retourne le type de bateau a moteur (peche ou plaisance)
TypeBateauMoteur typeBateauMoteur(const Bateau* bateau){
    return bateau->uTypeBateau.bateauMoteur.typeBateauMoteur;
}
