//
// Created by lucas on 24.05.19.
//

#ifndef BATEAUX_H
#define BATEAUX_H

#include <inttypes.h>
#include <stdint.h>

typedef enum{MOTEUR, VOILIER}TypeBateau;
typedef enum{PECHE, PLAISANCE}TypeBateauMoteur;

typedef struct{
    uint16_t surface; //en m²
}BateauVoilier;

typedef  struct{
    uint8_t longueur;//en m
    const char* nom;
}TypePlaisance;

typedef struct{
    uint8_t pecheMax; //en tonnes

}TypePeche;

typedef union{
    TypePlaisance plaisance;
    TypePeche peche;
}UTypeBateauMoteur;

typedef struct{
    uint16_t puissanceMoteur; // n CV
    TypeBateauMoteur typeBateauMoteur;
    UTypeBateauMoteur uTypeBateauMoteur;
}BateauMoteur;

typedef union{
    BateauVoilier voilier;
    BateauMoteur moteur;
} UTypeBateau;

typedef struct{
    const char* nom;
    TypeBateau typeBateau;
    UTypeBateau uTypeBateau;
} Bateau;


#endif //BATEAUX_H