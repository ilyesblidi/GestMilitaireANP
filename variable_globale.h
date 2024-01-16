//
// Created by  Apple on 12/22/23.
//

#ifndef VARIABLE_GLOBALE_H
#define VARIABLE_GLOBALE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//-----------------------dectionnere-----------------------------------
  extern const char* algerianWilayas[58];
extern char* bloodTypes[8];
extern const char *militaryGrades[19];
extern const char *Grades[5];
extern const char *militaryRegions[6];
extern const char *armedForces[8];

//--------------------------les structures-----------------------------


//----------------------------------------------------------------------
//TODO 1: modifier les structures de notre projet
typedef  struct  date{
    int day;
    int month;
    int year;
}date;
// -------------------les structures de fichier t7of--------------------
typedef struct Tenrg {
    int Matricule ; // cle pour la recherche
    char Nom[31] ;
    char Prenom[31] ;
    date Date_Naissance;
    char Wilaya_Naissance[32];
    char Grade[50];
    char Region_militaire[30] ;
    char Force_armee[50];
    char Groupe_sanguin[4];
}tenrg;

typedef struct Tbloc {
    tenrg tab[1024] ;
}Buffer ;

typedef struct Entete {
    int nbBloc ;
    int nbEnrgDernierBloc ;
}Entete;

// -------------------les structures de index primaire--------------------
typedef struct Adress {
    int nbBloc;
    int nbEnrg;
}Adress;
typedef struct Ienrg{
    int cle;
    Adress adress;
}Ienrg;
typedef struct Index{
   Ienrg tab[100010];//
    int nb ;//le nombre de enrg dans le tableau d'index primaire
}Index;

typedef struct Tibloc {  // les blocs de fichier d'index primaire vue comme TOF
    Ienrg tab[1024] ;
}BufferIndexP ;

// -------------------les structures de index secondaire regionMilaire--------------------
typedef struct Menrg{
    int indice;
    int cle;
}Menrg;
typedef struct IndexM{
    Menrg tab[100010];//
    int nb ;//le nombre de enrg dans le tableau d'index regionMilitaire
}IndexM;
typedef struct Tmbloc{
    Menrg tab[1024];
}BufferIndexM;

//***********************************************************************************************

//---------------------------------------les variable gloubals----------------------------------

 extern Buffer buffer,buf1 ;
 extern BufferIndexP bufferIndexP;
 extern BufferIndexM bufferIndexM;
 extern Entete header ;
 extern Index indexP ;
 extern IndexM indexM,indexF,indexG;
 extern date currentDate;

 extern int Lecture;
 extern int Ecriture;

//*************************************************************************************************
#endif //VARIABLE_GLOBALE_H
