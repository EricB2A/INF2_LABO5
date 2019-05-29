/*
 -----------------------------------------------------------------------------------
 Laboratoire : 05
 Fichier     : bateau.h
 Auteur(s)   : Eric Bousbaa, Lucas Gianinetti, Cassandre Wojciechowski
 Date        : 29.05.2019

 But         : Ce fichier contient les struct et les unions permettant de créer les 
 * objets "bateau", ainsi que les déclarations des fonctions utilisées sur les 
 * bateaux (construction et détermination du type). Il y a également deux enums 
 * rassemblant les types de bateaux et les types de bateaux à moteur. 

 Remarque(s) : Pour plus d'évolutivité et d'optimisation, nous avons créé des struct
 * contenant les paramètres spécifiques à chaque type de bateau. Ainsi la struct
 * globale "Bateau" ne contient que trois éléments. 

 Compilateur : - MinGW-gcc 6.3.0
               - Apple LLVM version 9.0.0 (clang-900.0.39.2)
 -----------------------------------------------------------------------------------
*/

#ifndef BATEAUX_H
#define BATEAUX_H

#include <stdio.h>
#include <inttypes.h>
#include <assert.h>

typedef const char* Nom;
typedef enum {BATEAU_MOTEUR, BATEAU_VOILIER} TypeBateau;
typedef enum {BATEAU_PECHE, BATEAU_PLAISANCE} TypeBateauMoteur;

/* BATEAUX VOILIERS */ 
typedef struct {
    uint16_t surfaceVoile; // en mètres-carrés [m²]
} BateauVoilier;

/* BATEAUX PLAISANCE */
typedef struct {
    uint8_t longueur; // en mètres [m]
    Nom nomProprietaire;
} BateauPlaisance;

/* BATEAUX PECHE */
typedef struct {
    uint8_t capacitePecheMax; // en tonnes [t]
} BateauPeche;

/* BATEAUX MOTEUR*/
typedef union {
    BateauPlaisance bateauPlaisance;
    BateauPeche bateauPeche;
} UTypeBateauMoteur;

typedef struct {
    uint16_t puissanceMoteur; // nombre de chevaux [cv]
    TypeBateauMoteur typeBateauMoteur;
    UTypeBateauMoteur uTypeBateauMoteur;
} bateauMoteur; 

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

/* Déclaration fonctions :
   - construction des objets "bateau" de chaque type (voilier, peche, plaisance)
   - determination du type de bateau a partir de l'objet construit
 */ 

Bateau voilier(Nom nom, uint16_t surfaceVoile);
Bateau bateauPeche(Nom nom, uint16_t puissanceMoteur, uint8_t capacitePecheMax);
Bateau bateauPlaisance(Nom nom, uint16_t puissanceMoteur, uint8_t longueur, 
        Nom nomProprietaire);

TypeBateau typeBateau(const Bateau* bateau);
TypeBateauMoteur typeBateauMoteur(const Bateau* bateau);

#endif //BATEAUX_H
