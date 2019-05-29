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

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "bateau.h"
#include "affichage.h"
#include "taxes.h"

double calculMoyenne(double total, size_t nbrElements);
double calculMedian(double valeurs[], size_t taille);
void calculTaxesPort(const Bateau port[], size_t taille, TaxeTypeBateau* taxeTypeBateau);

void affichageTaxe(TaxeTypeBateau* taxeTypeBateau);
void affichagePort(const Bateau port[], size_t taille);

int main(void){

    /*
    TODO :
       - Taxes
       - Ports (à faire dans le main 💩)
    */

    /*
     * bateau peche: nom, puissance moteur, capacite peche
     * bateau plaisance: nom, puissance moteur, longueur, nom proprio
     * voilier: nom, surface voile
     */

    Bateau x = bateauPeche("peche", 200, 1000);
    Bateau y = bateauPlaisance("Sah ça fait plaisir", 200, 100, "Rene");
    Bateau z = voilier("Macarena", 400);
    Bateau a = bateauPeche("peche", 200, 1000);
    Bateau b = bateauPlaisance("Sah ça fait plaisir", 200, 100, "Rene");
    Bateau c = voilier("Macarena", 400);
    Bateau d = bateauPeche("peche", 200, 1000);
    Bateau e = bateauPlaisance("Sah ça fait plaisir", 200, 100, "Rene");
    Bateau f = voilier("Macarena", 400);

    Bateau port[] = {x,y,z,a,b,c,d,e,f};


    TaxeTypeBateau* taxeTypeBateau = (TaxeTypeBateau*) calloc(9, sizeof(TaxeTypeBateau));

    calculTaxesPort(port,9, taxeTypeBateau);

    affichagePort(port, 9);
    affichageTaxe(taxeTypeBateau);

    free(taxeTypeBateau);
    taxeTypeBateau = NULL;
    /*
    affichageBateau(x);
    affichageBateau(y);
    affichageBateau(z);
    */

    /*
    printf("Taxes: %.2f\n", calculTaxes(&x)); // doit faire 200 chf
    printf("Taxes: %.2f\n", calculTaxes(&y)); // doit faire 1600 chf
    printf("Taxes: %.2f\n", calculTaxes(z)); // doit faire 75 chf
   */
     // printf("Taxes: %.2f\n", calculTaxes(test)); // doit faire 150 chf


    return EXIT_SUCCESS;
}
double calculMoyenne(double total, size_t nbrElements){
        return total /nbrElements;
}

//https://en.wikiversity.org/wiki/C_Source_Code/Find_the_median_and_mean
double calculMedian(double valeurs[], size_t taille){
    if(taille == 1){
        return valeurs[0];
    }
    else{
        double temp;
        //trie les valeurs dans l'ordre croissant
        for(size_t i = 0; i < taille-1; i++){
            for(size_t j = 0; j < taille; j++){
                if(valeurs[i] < valeurs[j]){
                    temp = valeurs[i];
                    valeurs[i] = valeurs[j];
                    valeurs[j] = temp;
                }
            }
        }
        if(taille % 2)
            return((valeurs[taille/2] + valeurs[taille/2 - 1]) / 2.0);
        else
            return valeurs[taille/2];
    }
}


void calculTaxesPort(const Bateau port[], size_t taille, TaxeTypeBateau* taxeTypeBateau){
    assert(taxeTypeBateau);

    double* taxesBateauxVoiliers = (double*) malloc(taille * sizeof(double));
    double* taxesBateauxPlaisances = (double*) malloc(taille * sizeof(double));
    double* taxesBateauxPeches = (double*) malloc(taille * sizeof(double));


    for(size_t i = 0; i < taille; i++){
        if(port[i].typeBateau == BATEAU_VOILIER){
            assert(taxesBateauxVoiliers);
            printf("ZZZZZZZZZZZZZZZZZZZZZZZ %d",(int)(taxeTypeBateau + ORDRE_VOILIER)->nombreBateaux);
            taxesBateauxVoiliers[(taxeTypeBateau + ORDRE_VOILIER)->nombreBateaux] = calculTaxes(&port[i]);
            (taxeTypeBateau + ORDRE_VOILIER)->sommeTotale += calculTaxes(&port[i]);
            ++(taxeTypeBateau + ORDRE_VOILIER)->nombreBateaux;
        }
        else if(typeBateauMoteur(&port[i]) == BATEAU_PLAISANCE){
            assert(taxesBateauxPlaisances);
            taxesBateauxPlaisances[(taxeTypeBateau + ORDRE_PLAISANCE)->nombreBateaux] = calculTaxes(&port[i]);
            (taxeTypeBateau + ORDRE_PLAISANCE)->sommeTotale += calculTaxes(&port[i]);
            ++(taxeTypeBateau + ORDRE_PLAISANCE)->nombreBateaux;
        }
        else if(typeBateauMoteur(&port[i]) == BATEAU_PECHE){
            assert(taxesBateauxPeches);
            taxesBateauxPeches[(taxeTypeBateau + ORDRE_PECHE)->nombreBateaux] = calculTaxes(&port[i]);
            (taxeTypeBateau + ORDRE_PECHE)->sommeTotale += calculTaxes(&port[i]);
            ++(taxeTypeBateau + ORDRE_PECHE)->nombreBateaux;
        }
    }

    //Calcul des taxes moyenne
    (taxeTypeBateau + ORDRE_VOILIER)->montantMoyen =
            calculMoyenne((taxeTypeBateau + ORDRE_VOILIER)->sommeTotale,
                          (taxeTypeBateau + ORDRE_VOILIER)->nombreBateaux);
    (taxeTypeBateau + ORDRE_PLAISANCE)->montantMoyen =
            calculMoyenne((taxeTypeBateau + ORDRE_PLAISANCE)->sommeTotale,
                          (taxeTypeBateau + ORDRE_PLAISANCE)->nombreBateaux);
    (taxeTypeBateau + ORDRE_PECHE)->montantMoyen =
            calculMoyenne((taxeTypeBateau + ORDRE_PECHE)->sommeTotale,
                          (taxeTypeBateau + ORDRE_PECHE)->nombreBateaux);

    //Reallocation des tableaux, on diminue la taille si necessaire afin de pouvoir calculer la mediane par la suite
    taxesBateauxVoiliers =realloc(taxesBateauxVoiliers, (taxeTypeBateau + ORDRE_VOILIER)->nombreBateaux * sizeof(double));
    taxesBateauxPeches = realloc(taxesBateauxPeches, (taxeTypeBateau + ORDRE_PECHE)->nombreBateaux * sizeof(double));
    //tests
    for(size_t h = 0; h < 3;h++){
        printf("ICCCCCCCCCCCCCCCCCCCCCCCI_PECHE  %f", taxesBateauxPeches[h]);
        printf("ICCCCCCCCCCCCCCCCCCCCCCCI_PLAISANCE  %f", taxesBateauxPlaisances[h]);
        printf("ICCCCCCCCCCCCCCCCCCCCCCCI_VOILIER  %f", taxesBateauxVoiliers[h]);

    }



    taxesBateauxPlaisances = realloc(taxesBateauxPlaisances, (taxeTypeBateau + ORDRE_PLAISANCE)->nombreBateaux * sizeof(double));
    assert(taxesBateauxVoiliers);
    assert(taxesBateauxPeches);
    assert(taxesBateauxPlaisances);

    //Calcul des taxes médianes
    (taxeTypeBateau + ORDRE_VOILIER)->montantMedian =
            calculMedian(taxesBateauxVoiliers, (taxeTypeBateau + ORDRE_VOILIER)->nombreBateaux);
    (taxeTypeBateau + ORDRE_PECHE)->montantMedian =
            calculMedian(taxesBateauxPeches, (taxeTypeBateau + ORDRE_PECHE)->nombreBateaux);
    (taxeTypeBateau + ORDRE_PLAISANCE)->montantMedian =
          calculMedian(taxesBateauxPlaisances, (taxeTypeBateau + ORDRE_PLAISANCE)->nombreBateaux);
}

void affichagePort(const Bateau port[], size_t taille){
    for(size_t i = 0; i < taille; i++){
        affichageBateau(&port[i]);
    }
}
