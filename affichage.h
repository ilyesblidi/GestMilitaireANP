//
// Created by  Apple on 12/24/23.
//

#ifndef AFFICHAGE_H
#define AFFICHAGE_H


#include "variable_globale.h"


// affichage des index dans la memoire central
void affichIndexPrimaire(Index index);
void affichIndexMilitaire(IndexM index);
void affichIndexForce(IndexM index);
void affichIndexGrade(IndexM index);


//affichage des fichier qui contient les index en memoire secondaire
void printfFichier(char *nomFichier);
void printIndexPrimaire(char *nomFichier);
void printMilitaireIndex(char *nomFichier);
void printForceIndex(char *nomFichier);
void printGradeIndex(char *nomFichier);



#endif //AFFICHAGE_H
