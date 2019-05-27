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
#include "bateau.h"
#include "affichage.h"

int main(void){

   /*
   TODO : 
      - Taxes
      - Ports (à faire dans le main 💩)
   */
   Bateau x = bateauPeche("🍑", 200, 1000);
   Bateau y = bateauPlaisance("Sah ça fait plaisir", 200, 100, "René");
   Bateau z = voilier("Macarena", 400);

   affichageBateau(x);
   affichageBateau(y);
   affichageBateau(z);

   printf("%d\n", typeBateau(x) == BATEAU_VOILIER);
   printf("%d\n", typeBateau(x) == BATEAU_MOTEUR);

   return EXIT_SUCCESS;
}