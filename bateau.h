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

#ifndef BATEAUX_H
#define BATEAUX_H

#include <stdio.h>
#include <inttypes.h>
#include <assert.h>

//NOTE: "BATEAU_VOILIER" ok ? 
typedef const char* Nom;
typedef enum {BATEAU_MOTEUR, BATEAU_VOILIER} TypeBateau;
typedef enum {BATEAU_PECHE, BATEAU_PLAISANCE} TypeBateauMoteur;

/* BATEAUX PLAISANCE */ 

typedef struct {
    uint16_t surfaceVoile; // en m²
} BateauVoilier;

/* BATEAUX PLAISANCE */

typedef struct {
    uint8_t longueur; // en m
    Nom nomProprietaire;
} BateauPlaisance;

/* BATEAUX PECHE */

typedef struct {
    uint8_t capacitePecheMax; // en tonnes
} BateauPeche;

/* BATEAUX MOTEUR*/

typedef union {
    BateauPlaisance bateauPlaisance;
    BateauPeche bateauPeche;
} UTypeBateauMoteur;

typedef struct {
    uint16_t puissanceMoteur; // nombre de  CV
    TypeBateauMoteur typeBateauMoteur;
    UTypeBateauMoteur uTypeBateauMoteur;
} bateauMoteur; // NOTE: nom ok ? 

/* BATEAUX  */ 

typedef union {
    BateauVoilier bateauVoilier;
    bateauMoteur bateauMoteur;
} UTypeBateau;

typedef struct {
    const char* nom;
    TypeBateau typeBateau; 
    UTypeBateau uTypeBateau; 
} Bateau;

/* Définition fonction */ 

Bateau voilier(Nom nom, uint16_t surfaceVoile);
Bateau bateauPeche(Nom nom, uint16_t puissancMoteur, uint8_t capacitePecheMax);
Bateau bateauPlaisance(Nom nom, uint16_t puissanceMoteur, uint8_t longueur, Nom nomProprietaire);

TypeBateau typeBateau(const Bateau bateau);
TypeBateauMoteur typeBateauMoteur(const Bateau bateau);

#endif //BATEAUX_H