#include "taxes.h"
#include "bateau.h"
#define TAXE_BASE_VOILIER 50
#define TAXE_BASE_MOTEUR 100

double calculTaxes(const Bateau* bateau){

    double taxeSpecifique;

    if(typeBateau(bateau) == BATEAU_VOILIER)
    {
        taxeSpecifique =  (bateau->uTypeBateau.bateauVoilier.surfaceVoile < 200 ? 0 : 25);
        return (double) TAXE_BASE_VOILIER + taxeSpecifique;
    }
    else if(typeBateauMoteur(bateau) == BATEAU_PECHE)
    {
        taxeSpecifique =  (bateau->uTypeBateau.bateauMoteur.uTypeBateauMoteur.bateauPeche.capacitePecheMax < 20 ? 0 : 100);
        return (double) TAXE_BASE_MOTEUR + taxeSpecifique;
    }
    else if (typeBateauMoteur(bateau) == BATEAU_PLAISANCE)
    {
        taxeSpecifique =  (bateau->uTypeBateau.bateauMoteur.puissanceMoteur < 100 ? 50 :
                           bateau->uTypeBateau.bateauMoteur.uTypeBateauMoteur.bateauPlaisance.longueur * 15);
        return (double) TAXE_BASE_MOTEUR + taxeSpecifique;
    }
}