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

#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include <stdio.h>
#include <inttypes.h>
#include "bateau.h"
#include "taxes.h"

#define MESSAGE_SEPARATEUR ":"

// MESSAGES BATEAUX
#define MESSAGE_NOM_BATEAU       "Nom du bateau"
#define MESSAGE_NOM_CATEGORIE    "Categorie"
#define MESSAGE_NOM_PROPRIETAIRE "Nom du proprietaire"

#define MESSAGE_VOILE                    "Surface de la voile"
#define MESSAGE_VOILE_UNITE              "[m²]"

#define MESSAGE_PUISSANCE_MOTEUR         "Puissance du moteur"
#define MESSAGE_PUISSANCE_MOTEUR_UNITE   "[CV]"

#define MESSAGE_CAPACITE_PECHE_MAX       "Capacite peche maximum "
#define MESSAGE_CAPACITE_PECHE_MAX_UNITE "[t] "

#define MESSAGE_LONGUEUR_BATEAU          "Longueur"
#define MESSAGE_LONGUEUR_BATEAU_UNITE    "[m]"

#define MESSAGE_CATEGORIES   "Categorie"
#define MESSAGE_NB_BATEAUX   "Nombre bateaux"
#define MESSAGE_TAXE_SOMME   "Somme des taxes"
#define MESSAGE_TAXE_MOYENNE "En moyenne"
#define MESSAGE_TAXE_UNITE   "[EUR]"

static const Nom NOM_TYPES_BATEAUX[] = {"Bateau a moteur", "Voilier"};
static const Nom NOM_TYPES_BATEAUX_MOTEUR[] = {
   "Bateau de peche", "Bateau de plaisance"
};

// MESSAGES TAXES
#define MESSAGE_TAXE_SOMME   "Somme"
#define MESSAGE_TAXE_MOYENNE "Moyenne"
#define MESSAGE_TAXE_MEDIANE "Median"

void affichageBateau(const Bateau* bateau);
void affichageTaxe(TaxeTypeBateau* taxeTypeBateau);

#endif AFFICHAGE_H