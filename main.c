/*
 -----------------------------------------------------------------------------------
 Laboratoire : 05
 Fichier     : main.c
 Auteur(s)   : Eric Bousbaa, Lucas Gianinetti, Cassandre Wojciechowski
 Date        : 29.05.2019

 But         : Teste le bon fonctionnement du programme. Pour se faire, 
 * ce fichier contient les constructions en "dur" des objets de type 
 * Bateau ainsi que la modélisation d'un port sous forme de tableau de bateaux. En
 * dessous de la fonction main se trouve la définition de la fonction permettant de 
 * calculer les taxes dans un port et d'afficher un port. 

 Remarque(s) : -

 Compilateur : - MinGW-gcc 6.3.0
               - Apple LLVM version 9.0.0 (clang-900.0.39.2)
 -----------------------------------------------------------------------------------
*/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <inttypes.h>
#include "bateau.h"
#include "affichage.h"
#include "taxes.h"

// Calcul pour chaque type de bateau dans le port la somme totale des taxes,
// la moyennes des taxes et la médiane des taxes
void calculTaxesPort(const Bateau port[], size_t taille, TaxeTypeBateau* taxeTypeBateau);

//affiche les differents bateaux du port
void affichagePort(const Bateau port[], size_t taille);

int main(void){
    //nom, puissance moteur, peche max
    Bateau peche1 = bateauPeche("peche1", 200, 10);
    Bateau peche2 = bateauPeche("peche2", 200, 20);
    Bateau peche3 = bateauPeche("peche3", 200, 100);

    Bateau voilier1 = voilier("voilier1", 100);
    Bateau voilier2 = voilier("voilier2", 200);
    Bateau voilier3 = voilier("voilier3", 400);

    //nom bateau, puissance, longueur, nom propriétaire
    Bateau plaisance1 = bateauPlaisance("plaisance1", (uint8_t)50, 10, "Cassandre");
    Bateau plaisance2 = bateauPlaisance("plaisance2", (uint8_t)100, 100, "Eric");
    Bateau plaisance3 = bateauPlaisance("plaisance3", (uint8_t)150, 150, "Lucas");

    Bateau bateauSansNom = bateauPeche("", 200, 10);


    Bateau port[] = {peche1, peche2, peche3, voilier1, voilier2, voilier3, plaisance1,
                     plaisance2, plaisance3, bateauSansNom};

    size_t nbrBateauxDansPort = sizeof(port) / sizeof(Bateau);

    TaxeTypeBateau* taxeTypeBateau = (TaxeTypeBateau*) calloc(nbrBateauxDansPort, sizeof(TaxeTypeBateau));

    calculTaxesPort(port,nbrBateauxDansPort, taxeTypeBateau);

    affichagePort(port, nbrBateauxDansPort);
    affichageTaxe(taxeTypeBateau);

    free(taxeTypeBateau);
    taxeTypeBateau = NULL;

    printf("Appuyez sur une touche pour continuer...\n");
    getchar();

    return EXIT_SUCCESS;
}

void calculTaxesPort(const Bateau port[], size_t taille, TaxeTypeBateau* taxeTypeBateau){

    assert(taxeTypeBateau);
    //alloue un tableau de la taille du port pour chaque type de bateau
    double* taxesBateauxVoiliers = (double*) malloc(taille * sizeof(double));
    double* taxesBateauxPlaisances = (double*) malloc(taille * sizeof(double));
    double* taxesBateauxPeches = (double*) malloc(taille * sizeof(double));

    for(size_t i = 0; i < taille; i++){
        if(port[i].typeBateau == BATEAU_VOILIER){
            assert(taxesBateauxVoiliers);
            //Ajoute pour chaque voilier sa taxe dans le tableau taxeBateauxVoiliers
            taxesBateauxVoiliers[(taxeTypeBateau + ORDRE_VOILIER)->nombreBateaux] = calculTaxes(&port[i]);
            (taxeTypeBateau + ORDRE_VOILIER)->sommeTotale += calculTaxes(&port[i]);
            //nombre de voiliers dans le port ++
            ++(taxeTypeBateau + ORDRE_VOILIER)->nombreBateaux;
        }
        else if(typeBateauMoteur(&port[i]) == BATEAU_PLAISANCE){
            assert(taxesBateauxPlaisances);
            //Ajoute pour chaque voilier sa taxe dans le tableau taxeBateauxMoteur
            taxesBateauxPlaisances[(taxeTypeBateau + ORDRE_PLAISANCE)->nombreBateaux] = calculTaxes(&port[i]);
            (taxeTypeBateau + ORDRE_PLAISANCE)->sommeTotale += calculTaxes(&port[i]);
            //nombre de bateau plaisance dans le port ++
            ++(taxeTypeBateau + ORDRE_PLAISANCE)->nombreBateaux;
        }
        else if(typeBateauMoteur(&port[i]) == BATEAU_PECHE){
            assert(taxesBateauxPeches);
            //Ajoute pour chaque voilier sa taxe dans le tableau taxeBateauxPeches
            taxesBateauxPeches[(taxeTypeBateau + ORDRE_PECHE)->nombreBateaux] = calculTaxes(&port[i]);
            (taxeTypeBateau + ORDRE_PECHE)->sommeTotale += calculTaxes(&port[i]);
            //nombre de bateau peche dans le port ++
            ++(taxeTypeBateau + ORDRE_PECHE)->nombreBateaux;
        }
    }

    //Reallocation des tableaux, on diminue la taille si necessaire afin de pouvoir calculer la mediane par la suite
    taxesBateauxVoiliers =realloc(taxesBateauxVoiliers,
                                  (taxeTypeBateau + ORDRE_VOILIER)->nombreBateaux * sizeof(double));
    taxesBateauxPeches = realloc(taxesBateauxPeches, (taxeTypeBateau + ORDRE_PECHE)->nombreBateaux * sizeof(double));
    taxesBateauxPlaisances = realloc(taxesBateauxPlaisances,
                                     (taxeTypeBateau + ORDRE_PLAISANCE)->nombreBateaux * sizeof(double));

    assert(taxesBateauxVoiliers);
    assert(taxesBateauxPeches);
    assert(taxesBateauxPlaisances);

    //Calculs des taxes moyennes et médianes
    for(size_t i = 0; i < NBR_TAXE_TYPE_BATEAU; i++){
        (taxeTypeBateau + i)->montantMoyen =
                calculMoyenne((taxeTypeBateau + i)->sommeTotale,
                              (taxeTypeBateau + i)->nombreBateaux);

        (taxeTypeBateau + i)->montantMedian =
                calculMedian(taxesBateauxVoiliers, (taxeTypeBateau + i)->nombreBateaux);
    }
}

void affichagePort(const Bateau port[], size_t taille){
    for(size_t i = 0; i < taille; i++){
        affichageBateau(&port[i]);
    }
}
