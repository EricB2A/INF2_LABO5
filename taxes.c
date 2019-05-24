#include "taxes.h"

#define TAXE_BASE_VOILIER 50
#define TAXE_BASE_MOTEUR 100

double calculTaxes (Bateaux bateau){
   double taxeSpecifique;
   if(bateau == Bateaux.UTypeBateau.voilier) {
      taxeSpecifique = (BateauVoilier.surface < 200 ? 25 : 0);
      return TAXE_BASE_VOILIER + taxeSpecifique;
   } else if(bateau == Bateaux.UTypeBateau.moteur){
      ...
   }
           
}