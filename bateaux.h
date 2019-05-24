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

#include <inttypes.h>
#include <stdint.h>

#define TAXE_BASE_VOILIER 50
#define TAXE_BASE_MOTEUR 100

typedef enum{MOTEUR, VOILIER}TypeBateau;
typedef enum{PECHE, PLAISANCE}TypeBateauMoteur;

/* CATEGORIES : VOILIERS & A MOTEURS */
typedef struct{
    uint16_t surface; //en m²
    double taxeDeBase;
}BateauVoilier;

typedef struct{
    uint16_t puissanceMoteur; // n CV
    TypeBateauMoteur typeBateauMoteur;
    UTypeBateauMoteur uTypeBateauMoteur;
    double taxeDeBase;
} BateauMoteur;

/* POUR BATEAUX A MOTEURS : PLAISANCE & PECHE */
typedef  struct{
    uint8_t longueur; //en m
    const char* nom;
}TypePlaisance;

typedef struct{
    uint8_t pecheMax; //en tonnes

}TypePeche;

typedef union{
    TypePlaisance plaisance;
    TypePeche peche;
}UTypeBateauMoteur;

typedef union{
    BateauVoilier voilier;
    BateauMoteur moteur;
} UTypeBateau;

/* BATEAU */
typedef struct{
    const char* nom;
    TypeBateau typeBateau;
    UTypeBateau uTypeBateau;
} Bateau;

#endif //BATEAUX_H