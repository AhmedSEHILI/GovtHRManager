#include <stdio.h>
#include <stdlib.h>
#include "Headers.h"

int Ouvrir(fichier *fich, char *nom_f, char mod)
{
    int l = 0;
    if (mod == 'A')
    {
        fich->f = fopen(nom_f,"rb+");
        l = fread(&fich->entete,sizeof (struct ent), 1, fich->f);
        if (!l) return 0;
    }
    else if (mod == 'N')
    {
        fich->f = fopen(nom_f,"wb+");
        fich->entete.tete = 0;
        fich->entete.queue = 0;
        fich->entete.nb_enr = 0;
        fich->entete.nb_bloc = 0;
    }
    else return 0;
    return 1;
}

void Fermer(fichier fich)
{
    fseek(fich.f,0,SEEK_SET);
    fwrite(&fich.entete, sizeof(struct ent), 1, fich.f);
    fclose(fich.f);
}

int LireDir(fichier fich,int i,tbloc *buf)
{
    int l = 0;
    fseek(fich.f,sizeof(struct ent)+(i-1)*sizeof(struct tbloc),SEEK_SET);
/***/
//    if (!feof(fich.f)) l = fread(buf,sizeof(tbloc),1,fich.f);
    l = fread(buf,sizeof(tbloc),1,fich.f);
/***/
    return l;
}

int EcrireDir(fichier fich, int i, tbloc buf)
{
    int e = 0;
    // déplacement pour ecrire le bloc (i+1) de fichier (en sautant le bloc de la caractéristique)
    fseek(fich.f, sizeof(struct ent)+(i-1)*sizeof(struct tbloc), SEEK_SET);
/***/
//    if (!feof(fich.f)) e = fwrite(&buf,sizeof(tbloc),1,fich.f);
    e = fwrite(&buf,sizeof(tbloc),1,fich.f);
/***/
    return e;
}

int LireSeq(fichier fich, tbloc *buf)
{
    int l = 0;
/***/
//    if(! feof(fich.f)) l = fread(buf, sizeof(struct tbloc), 1, fich.f);
    l = fread(buf, sizeof(struct tbloc), 1, fich.f);
/***/
    return l;
}

int EcrireSeq(fichier fich, tbloc buf)
{
    int e = 0;
/***/
//    if(! feof(fich.f)) e = fwrite(&buf, sizeof(struct tbloc), 1, fich.f);
    e = fwrite(&buf, sizeof(struct tbloc), 1, fich.f);
/***/
    return e;
}

int Aff_entete(fichier *fich, int i, int val)
{
/***/
//    if (i = 1) fich->entete.nb_blocs = val;
    if (i == 1) fich->entete.tete = val;
//    else if (i = 2) fich->entete.nb_enr = val;
/***/
    else if (i == 2) fich->entete.queue = val;
    else if (i == 3) fich->entete.nb_enr = val;
    else if (i == 4) fich->entete.nb_bloc = val;
    else return 0;
    return 1;
}



int entete(fichier fich, int i)
{
/***/
//    if (i = 1) return fich.entete.nb_blocs;
    if (i == 1) return fich.entete.tete;
//    else if (i = 2) return fich.entete.nb_enr;
/***/
    else if (i == 2) return fich.entete.queue;
    else if (i == 3) return fich.entete.nb_enr;
    else if (i == 4) return fich.entete.nb_bloc;
    else return -1;

}

int Alloc_Bloc(fichier fich, ptr *tete)
{
    int tmp; ptr p;
    if (*tete == NULL) return entete(fich,4)+1;
    else
    {
         tmp = valeur(*tete);
         p = *tete;
         *tete = suivant(*tete);
         free(p);
         return tmp;
    }
}


/************************************************************************************************************/
/************************************************************************************************************/
/************************************************************************************************************/
/************************************************************************************************************/
/************************************************************************************************************/
/************************************************************************************************************/
/************************************************************************************************************/
/************************************************************************************************************/
/************************************************************************************************************/

int Ouvrir_index(fichier_index *fich, char *nom_f, char mod)
{
    int l = 0;
    if (mod == 'A')
    {
        fich->f = fopen(nom_f,"rb+");
        l = fread(&fich->entete,sizeof (struct ent_index), 1, fich->f);
        if (!l) return 0;
    }
    else if (mod == 'N')
    {
        fich->f = fopen(nom_f,"wb+");
        fich->entete.nb_blocs = 0;
        fich->entete.nb_enr = 0;
        fich->entete.nb_supp = 0;
    }
    else return 0;
    return 1;
}

void Fermer_index(fichier_index fich)
{
    fseek(fich.f,0,SEEK_SET);
    fwrite(&fich.entete, sizeof(struct ent_index), 1, fich.f);
    fclose(fich.f);
}

int LireDir_index_mat(fichier_index fich,int i,tbloc_index_mat *buf)
{
    int l = 0;
    fseek(fich.f,sizeof( ent_index)+(i-1)*sizeof( tbloc_index_mat),SEEK_SET);

    l = fread(buf,sizeof(tbloc_index_mat),1,fich.f);

    return l;
}

int EcrireDir_index_mat(fichier_index fich, int i, tbloc_index_mat buf)
{
    int e = 0;
    fseek(fich.f, sizeof( ent_index)+(i-1)*sizeof( tbloc_index_mat), SEEK_SET);
    e = fwrite(&buf,sizeof(tbloc_index_mat),1,fich.f);

    return e;
}


int Aff_entete_index(fichier_index *fich, int i, int val)
{

    if (i == 1) fich->entete.nb_blocs = val;
    else if (i == 2) fich->entete.nb_enr = val;
    else if (i == 3) fich->entete.nb_supp = val;
    else return 0;
    return 1;
}

int entete_index(fichier_index fich, int i)
{
    if (i == 1) return fich.entete.nb_blocs;
    else if (i == 2) return fich.entete.nb_enr;
    else if (i == 3) return fich.entete.nb_supp;
    else return -1;

}

/*************************************************************************************/



int LireDir_index_region(fichier_index fich,int i,tbloc_index_region *buf)
{
    int l = 0;
    fseek(fich.f,sizeof( ent_index)+(i-1)*sizeof( tbloc_index_region),SEEK_SET);

    l = fread(buf,sizeof(tbloc_index_region),1,fich.f);

    return l;
}

int EcrireDir_index_region(fichier_index fich, int i, tbloc_index_region buf)
{
    int e = 0;
    fseek(fich.f, sizeof( ent_index)+(i-1)*sizeof( tbloc_index_region), SEEK_SET);
    e = fwrite(&buf,sizeof(tbloc_index_region),1,fich.f);

    return e;
}


/**********************************************************************************/



int LireDir_index_force(fichier_index fich,int i,tbloc_index_force *buf)
{
    int l = 0;
    fseek(fich.f,sizeof( ent_index)+(i-1)*sizeof( tbloc_index_force),SEEK_SET);

    l = fread(buf,sizeof(tbloc_index_force),1,fich.f);

    return l;
}

int EcrireDir_index_force(fichier_index fich, int i, tbloc_index_force buf)
{
    int e = 0;
    fseek(fich.f, sizeof( ent_index)+(i-1)*sizeof( tbloc_index_force), SEEK_SET);
    e = fwrite(&buf,sizeof(tbloc_index_force),1,fich.f);

    return e;
}


/**********************************************************************************/



int LireDir_index_grade(fichier_index fich,int i,tbloc_index_grade *buf)
{
    int l = 0;
    fseek(fich.f,sizeof( ent_index)+(i-1)*sizeof( tbloc_index_grade),SEEK_SET);

    l = fread(buf,sizeof(tbloc_index_grade),1,fich.f);

    return l;
}

int EcrireDir_index_grade(fichier_index fich, int i, tbloc_index_grade buf)
{
    int e = 0;
    fseek(fich.f, sizeof( ent_index)+(i-1)*sizeof( tbloc_index_grade), SEEK_SET);
    e = fwrite(&buf,sizeof(tbloc_index_grade),1,fich.f);

    return e;
}


/**********************************************************************************/

int LireDir_index_age(fichier_index fich,int i,tbloc_index_age *buf)
{
    int l = 0;
    fseek(fich.f,sizeof( ent_index)+(i-1)*sizeof( tbloc_index_age),SEEK_SET);

    l = fread(buf,sizeof(tbloc_index_age),1,fich.f);

    return l;
}

int EcrireDir_index_age(fichier_index fich, int i, tbloc_index_age buf)
{
    int e = 0;
    fseek(fich.f, sizeof( ent_index)+(i-1)*sizeof( tbloc_index_age), SEEK_SET);
    e = fwrite(&buf,sizeof(tbloc_index_age),1,fich.f);

    return e;
}


/**********************************************************************************/
