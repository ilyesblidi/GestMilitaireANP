//
// Created by  Apple on 12/24/23.
//

#include <stdio.h>
#include "affichage.h"
#include "variable_globale.h"
#include "fonction.h"
#include "machine_abtraite.h"


void affichIndexPrimaire(Index index) {
    for (int i = 0; i < index.nb; ++i) {
        printf(" %d/ le matricule %d dans  %d %d \n", i, index.tab[i].cle, index.tab[i].adress.nbBloc,
               index.tab[i].adress.nbEnrg);
    }
}

void affichIndexMilitaire(IndexM index) {
    for (int i = 0; i < index.nb; ++i) {
        printf(" %d/ le matricule %d de  %s\n", i, index.tab[i].cle, getRegionAssocie(index.tab[i].indice));
    }
}
void affichIndexForce(IndexM index){
    for (int i = 0; i < index.nb; ++i) {
        printf(" %d/ le matricule %d de %s \n",i,index.tab[i].cle, getForceAssocie(index.tab[i].indice));
    }
}
void affichIndexGrade(IndexM index){
    for (int i = 0; i < index.nb; ++i) {
        printf(" %d/ le matricule %d de %s \n",i,index.tab[i].cle, getGradeAssocie(index.tab[i].indice));
    }
}



void printfFichier(char *nomFichier) {
    FILE *f = NULL;
    int s = 1024;
    Ouvrire(&f, nomFichier, 'A');
    for (int i = 1; i <= entete(f, 1); ++i) {
        if (i == entete(f, 1)) {
            s = entete(f, 2);
        }else {
            s = 1024;
        }
        LireDir(f, i, &buffer);
        for (int j = 0; j < s; ++j) {
            printf("buffer de %d %d est %d %s\n", i, j, buffer.tab[j].Matricule, buffer.tab[j].Region_militaire);
        }
    }
    Fermer(f);
}



void printIndexPrimaire(char *nomFichier) {
    FILE *f;
    int s = 1024;
    int in = 0;
    BufferIndexP bufer;
    Ouvrire(&f, nomFichier, 'A');
    for (int i = 1; i <= entete(f, 1); ++i) {
        LireDirIP(f, i, &bufer);
        if (i == entete(f, 1)) {
            s = entete(f, 2);
        } else {
            s = 1024;
        }
        for (int j = 0; j < s; ++j) {
            printf(" %d/ le matricule %d dans  %d %d \n", in, bufer.tab[j].cle, bufer.tab[j].adress.nbBloc,
                   bufer.tab[j].adress.nbEnrg);
            in++;
        }
    }
    Fermer(f);
}
void printMilitaireIndex(char *nomFichier) {
    FILE *f;
    int s = 1024;
    int in = 0;
    BufferIndexM bufer;
    Ouvrire(&f, nomFichier, 'A');
    for (int i = 1; i <= entete(f, 1); ++i) {
        LireDirIM(f, i, &bufer);
        if (i == entete(f, 1)) {
            s = entete(f, 2);
        } else {
            s = 1024;
        }
        for (int j = 0; j < s; ++j) {
            printf(" %d/ le matricule %d de  %s\n", in, bufer.tab[j].cle, getRegionAssocie(bufer.tab[j].indice));
            in++;
        }
    }
    Fermer(f);
}
void printForceIndex(char *nomFichier) {
    FILE *f;
    int s = 1024;
    int in = 0;
    BufferIndexM bufer;
    Ouvrire(&f, nomFichier, 'A');
    for (int i = 1; i <= entete(f, 1); ++i) {
        LireDirIM(f, i, &bufer);
        if (i == entete(f, 1)) {
            s = entete(f, 2);
        } else {
            s = 1024;
        }
        for (int j = 0; j < s; ++j) {
            printf(" %d/ le matricule %d de  %s\n", in, bufer.tab[j].cle, getForceAssocie(bufer.tab[j].indice));
            in++;
        }
    }
    Fermer(f);
}
void printGradeIndex(char *nomFichier) {
    FILE *f;
    int s = 1024;
    int in = 0;
    BufferIndexM bufer;
    Ouvrire(&f, nomFichier, 'A');
    for (int i = 1; i <= entete(f, 1); ++i) {
        LireDirIM(f, i, &bufer);
        if (i == entete(f, 1)) {
            s = entete(f, 2);
        } else {
            s = 1024;
        }
        for (int j = 0; j < s; ++j) {
            printf(" %d/ le matricule %d de  %s\n", in, bufer.tab[j].cle, getGradeAssocie(bufer.tab[j].indice));
            in++;
        }
    }
    Fermer(f);
}
