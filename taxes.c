/*
 -----------------------------------------------------------------------------------
 Laboratoire : 05
 Fichier     : taxes.c
 Auteur(s)   : Eric Bousbaa, Lucas Gianinetti, Cassandre Wojciechowski
 Date        : 29.05.2019

 But         : Ce fichier contient la déclaration de la fonction principale de 
 * calcul des taxes pour chaque objet de type "Bateau" et les déclarations des 
 * fonctions calculant la moyenne et la médiane.

 Remarque(s) : Aide pour le calcul de la médiane : 
 * https://en.wikiversity.org/wiki/C_Source_Code/Find_the_median_and_mean

 Compilateur : - MinGW-gcc 6.3.0
               - Apple LLVM version 9.0.0 (clang-900.0.39.2)
 -----------------------------------------------------------------------------------
*/

#include "taxes.h"
#include "bateau.h"

// Calcul des taxes selon le type de bateau et les paramètres propres à chaque objet
double calculTaxes(const Bateau* bateau){

    double taxeSpecifique;

    if(typeBateau(bateau) == BATEAU_VOILIER){
        taxeSpecifique =  (bateau->uTypeBateau.bateauVoilier.surfaceVoile 
        < 200 ? 0 : 25);
        return (double) TAXE_BASE_VOILIER + taxeSpecifique;
    }
    else if(typeBateauMoteur(bateau) == BATEAU_PECHE){
        taxeSpecifique = 
        (bateau->uTypeBateau.bateauMoteur.uTypeBateauMoteur.bateauPeche.capacitePecheMax 
         < 20 ? 0 : 100);
        return (double) TAXE_BASE_MOTEUR + taxeSpecifique;
    }
    else{ // (typeBateauMoteur(bateau) == BATEAU_PLAISANCE)
        taxeSpecifique = (bateau->uTypeBateau.bateauMoteur.puissanceMoteur < 100 ? 50 :
        bateau->uTypeBateau.bateauMoteur.uTypeBateauMoteur.bateauPlaisance.longueur * 15);
        return (double) TAXE_BASE_MOTEUR + taxeSpecifique;
    }
}

// Calcul de la moyenne
double calculMoyenne(double total, size_t nbrElements){
        return total / nbrElements;
}

// Calcul de la médiane
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
        if(taille % 2){
            return((valeurs[taille/2] + valeurs[taille/2 - 1]) / 2.0);
        }
        else{
            return valeurs[taille/2];
        }
    }
}
