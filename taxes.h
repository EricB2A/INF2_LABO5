#ifndef TAXES_H
#define TAXES_H

#include "bateau.h"

#define TAXE_BASE_VOILIER 50
#define TAXE_BASE_MOTEUR 100

typedef struct{
    double sommeTotale;
    double montantMoyen;
    double montantMedian;
    size_t nombreBateaux;
}TaxeTypeBateau;

double calculTaxes(const Bateau* bateau);

#endif /* TAXES_H */
