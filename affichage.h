/*
 -----------------------------------------------------------------------------------
 Laboratoire : 05
 Fichier     : affichage.h
 Auteur(s)   : Eric Bousbaa, Lucas Gianinetti, Cassandre Wojciechowski
 Date        : 29.05.2019

 But         : Déclaration du contenu affiché, utilisé dans les fonctions d'affichages,
 * ainsi que des tableau permettant de traduire un mot clef en chaine de caractères.
 * Le fichier contient également les formats d'affichages, tels que la largeur ou la 
 * précision de réels.

 Remarque(s) : - L'ordre des éléments contenu dans le tableau de traduction mentionné
 * précédamment doit respecter l'ordre d'indicage du mot clef lié.

Compilateur : - MinGW-gcc 6.3.0
              - Apple LLVM version 9.0.0 (clang-900.0.39.2)
 -----------------------------------------------------------------------------------
*/
#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include <stdio.h>
#include <inttypes.h>
#include "bateau.h"
#include "taxes.h"

#define SEPARATEUR ":"
#define ALIGNEMENT_GAUCHE "%-30s"

// MESSAGES BATEAUX
#define MESSAGE_NOM_BATEAU        "Nom du bateau"
#define MESSAGE_NOM_CATEGORIE     "Categorie"
#define MESSAGE_CATEGORIES_MOTEUR "Categorie bateau moteur"
#define MESSAGE_NOM_PROPRIETAIRE  "Nom du proprietaire"

#define MESSAGE_VOILE                    "Surface de la voile"
#define MESSAGE_VOILE_UNITE              "[m^2]"

#define MESSAGE_PUISSANCE_MOTEUR         "Puissance du moteur"
#define MESSAGE_PUISSANCE_MOTEUR_UNITE   "[CV]"

#define MESSAGE_CAPACITE_PECHE_MAX       "Capacite peche maximum "
#define MESSAGE_CAPACITE_PECHE_MAX_UNITE "[t] "

#define MESSAGE_LONGUEUR_BATEAU          "Longueur"
#define MESSAGE_LONGUEUR_BATEAU_UNITE    "[m]"

#define MESSAGE_CATEGORIES    "Categorie"
#define MESSAGE_NB_BATEAUX    "Nombre bateaux"

static const Nom NOM_TYPES_BATEAUX[] = {"Bateau a moteur", "Voilier"};
static const Nom NOM_TYPES_BATEAUX_MOTEUR[] = {
   "Bateau de peche", "Bateau de plaisance"
};

// MESSAGES TAXES
#define MESSAGE_TAXE_SOMME   "Somme"
#define MESSAGE_TAXE_MOYENNE "Moyenne"
#define MESSAGE_TAXE_MEDIANE "Median"

#define TAXE_FORMAT_PRECISION "%-.2f"
#define MESSAGE_TAXE_UNITE    "[EUR]"

static const Nom NOM_TYPES_BATEAUX_TAXES[] = {
    "Bateaux de plaisance", "Bateaux de peche", "Voilier"
};

void affichageBateau(const Bateau* bateau);
void affichageTaxe(TaxeTypeBateau* taxeTypeBateau);

#endif //AFFICHAGE_H
