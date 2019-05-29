/*
 -----------------------------------------------------------------------------------
 Laboratoire : 05
 Fichier     : taxes.h
 Auteur(s)   : Eric Bousbaa, Lucas Gianinetti, Cassandre Wojciechowski
 Date        : 29.05.2019

 But         : Ce fichier contient les divers éléments permettant de calculer les 
 * taxes propres à chaque type de bateau et plus précisément à chaque bateau 
 * directement. 
 * Il contient aussi les déclarations des fonctions de calcul des taxes de chaque 
 * bateau et des moyennes et médianes pour chaque type de bateau.

 Remarque(s) : -

 Compilateur : - MinGW-gcc 6.3.0
               - Apple LLVM version 9.0.0 (clang-900.0.39.2)
 -----------------------------------------------------------------------------------
*/

#ifndef TAXES_H
#define TAXES_H

#include "bateau.h"

#define TAXE_BASE_VOILIER 50
#define TAXE_BASE_MOTEUR 100
#define NBR_TAXE_TYPE_BATEAU 3
typedef enum{ORDRE_PLAISANCE, ORDRE_PECHE, ORDRE_VOILIER} OrdreTaxe;

typedef struct{
    double sommeTotale;
    double montantMoyen;
    double montantMedian;
    size_t nombreBateaux;
}TaxeTypeBateau;

double calculTaxes(const Bateau* bateau);
double calculMoyenne(double total, size_t nbrElements);
double calculMedian(double valeurs[], size_t taille);

#endif /* TAXES_H */
