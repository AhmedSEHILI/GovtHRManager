#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"
#define an_courant 2022



void informations_generales()
{
    int x;
    for (x = 0; x<9; x++)
    {
        TSTATreg[x] = 0;
        TSTATforc[x] = 0;
        TSTATcatgrad[x] = 0;
        TSTATcatage[x] = 0;
    }
    fichier F; tbloc buf;

    int i, j, age;

    Ouvrir(&F, F_LnonOF, 'A');
    NbEnr = entete(F, 3);

    i = entete(F, 1);
    while (i != 0)
    {
        LireDir(F, i , &buf);
        for (j = 0; j < buf.nb; j++)
        {
            age = an_courant - buf.tab[j].date_de_naissance.an;

            if (buf.tab[j].region == 1) TSTATreg[1]++;
            if (buf.tab[j].region == 2) TSTATreg[2]++;
            if (buf.tab[j].region == 3) TSTATreg[3]++;
            if (buf.tab[j].region == 4) TSTATreg[4]++;
            if (buf.tab[j].region == 5) TSTATreg[5]++;
            if (buf.tab[j].region == 6) TSTATreg[6]++;

            if (buf.tab[j].force == 1) TSTATforc[1]++;
            if (buf.tab[j].force == 2) TSTATforc[2]++;
            if (buf.tab[j].force == 3) TSTATforc[3]++;
            if (buf.tab[j].force == 4) TSTATforc[4]++;
            if (buf.tab[j].force == 5) TSTATforc[5]++;
            if (buf.tab[j].force == 6) TSTATforc[6]++;
            if (buf.tab[j].force == 7) TSTATforc[7]++;
            if (buf.tab[j].force == 8) TSTATforc[8]++;

            if ((buf.tab[j].grade >= 1) && (buf.tab[j].grade <= 4)) TSTATcatgrad[1]++;
            if ((buf.tab[j].grade >= 5) && (buf.tab[j].grade <= 7)) TSTATcatgrad[2]++;
            if ((buf.tab[j].grade >= 8) && (buf.tab[j].grade <= 11)) TSTATcatgrad[3]++;
            if ((buf.tab[j].grade >= 12) && (buf.tab[j].grade <= 15)) TSTATcatgrad[4]++;
            if ((buf.tab[j].grade >= 16) && (buf.tab[j].grade <= 18)) TSTATcatgrad[5]++;

            if (age <30) TSTATcatage[1]++;
            if ((age >=30) && (age<50)) TSTATcatage[2]++;
            if ((age >=50) && (age<70)) TSTATcatage[3]++;
            if (age >=70) TSTATcatage[4]++;
        }
        i = buf.suivant;
    }

    Fermer(F);
}





void charg_groupe_sang()
{
    strcpy(tab_grp_sang[0], "O+");
    strcpy(tab_grp_sang[1], "O-");
    strcpy(tab_grp_sang[2], "A+");
    strcpy(tab_grp_sang[3], "A-");
    strcpy(tab_grp_sang[4], "B+");
    strcpy(tab_grp_sang[5], "B-");
    strcpy(tab_grp_sang[6], "AB+");
    strcpy(tab_grp_sang[7], "AB-");
}


void charg_wilaya()
{
    int c = 0;
    FILE *fichier = NULL;
    fichier = fopen("wilaya.txt","r");
    if (fichier != NULL)
    {
        while (!feof(fichier))
        {
            if (fgets(tab_wilaya[c],sizeof(tab_wilaya[c]),fichier)) c++;
        }
    }
}

void charg_grade()
{
    int c = 0;
    FILE *fichier = NULL;
    fichier = fopen("grade.txt","r");
    if (fichier != NULL)
    {
        while (!feof(fichier))
        {
            if (fgets(tab_grade[c],sizeof(tab_grade[c]),fichier)) c++;
        }
    }
}


void charg_force()
{
    int c = 0;
    FILE *fichier = NULL;
    fichier = fopen("force.txt","r");
    if (fichier != NULL)
    {
        while (!feof(fichier))
        {
            if (fgets(tab_force[c],sizeof(tab_force[c]),fichier))
            {
                c++;
            }
        }
    }
}

void charg_region()
{
    int c = 0;
    FILE *fichier = NULL;
    fichier = fopen("region.txt","r");
    if (fichier != NULL)
    {
        while (!feof(fichier))
        {
            if (fgets(tab_region[c],sizeof(tab_region[c]),fichier))
            {
                c++;
            }
        }
    }
}

/**************************************************************************/
/**************************************************************************/
/**************************************************************************/

unsigned int Random (unsigned int Min, unsigned int Max)
{
    return Min+ rand()%(Max - Min +1) ;
}




