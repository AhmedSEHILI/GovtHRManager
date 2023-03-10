#ifndef HEADERS_H_INCLUDED
#define HEADERS_H_INCLUDED

/*** D?finition des types ***/
typedef struct maillon maillon;
typedef struct maillon *ptr;
struct maillon{
    int info;
    ptr suivant;
};

typedef struct LaDate LaDate;
struct LaDate
{
    int jour;
    int mois;
    int an;
};

typedef struct tenr tenr; //des enregistrements
struct tenr{
    char matricule[7], nom[31], prenom[31];
    LaDate date_de_naissance;
    int willaya, sexe, grp_sang, grade, force, region;
};

typedef struct tbloc tbloc; //l'unit? de transf?re des donn?es de la MS ? la MC
struct tbloc{
    tenr tab[82];
    int nb;
    int suivant;
    int precedent;
};

typedef struct ent ent;
struct ent{
    int tete;
    int queue;
    int nb_enr;
    int nb_bloc;
};

typedef struct fichier fichier;
struct fichier{
    FILE *f;
    ent entete;
};

typedef char chaine1[27];
typedef char chaine2[4];
typedef char chaine3[50];
typedef char chaine4[14];
chaine1 tab_wilaya[59];
chaine1 tab_grade[19];
chaine2 tab_grp_sang[9];
chaine3 tab_force[9];
chaine4 tab_region[7];

ptr t_vide_actif, t_vide_archive;







/************************************************************************************************************/
/************************************************************************************************************/
/************************************************************************************************************/
/************************************************************************************************************/
/************************************************************************************************************/
/************************************************************************************************************/
/************************************************************************************************************/
/************************************************************************************************************/
/************************************************************************************************************/

typedef struct couple couple;
struct couple{
    int bloc;
    int pos;
};

typedef struct tenr_index_mat tenr_index_mat;  /*****************************/
struct tenr_index_mat{
    int supp;
    char matricule[7];
    couple adr;
};

typedef struct tbloc_index_mat tbloc_index_mat; /*****************************/
struct tbloc_index_mat{
    tenr_index_mat tab[82];
    int nb;
};

typedef struct ent_index ent_index;
struct ent_index{
   int nb_blocs;
   int nb_enr;
   int nb_supp;
};

typedef struct fichier_index fichier_index;
struct fichier_index{
    FILE *f;
    ent_index entete;
};


/*********************************************************************************/


typedef struct tenr_index_region tenr_index_region;  /*****************************/
struct tenr_index_region{
    int supp;
    int region;
    char matricule[7];
};

typedef struct tbloc_index_region tbloc_index_region; /*****************************/
struct tbloc_index_region{
    tenr_index_region tab[82];
    int nb;
};


/*********************************************************************************/


typedef struct tenr_index_force tenr_index_force;  /*****************************/
struct tenr_index_force{
    int supp;
    int force;
    char matricule[7];
};

typedef struct tbloc_index_force tbloc_index_force; /*****************************/
struct tbloc_index_force{
    tenr_index_force tab[82];
    int nb;
};


/*********************************************************************************/


typedef struct tenr_index_grade tenr_index_grade;  /*****************************/
struct tenr_index_grade{
    int supp;
    int grade;
    char matricule[7];
};

typedef struct tbloc_index_grade tbloc_index_grade; /*****************************/
struct tbloc_index_grade{
    tenr_index_grade tab[82];
    int nb;
};


/*********************************************************************************/


typedef struct tenr_index_age tenr_index_age;  /*****************************/
struct tenr_index_age{
    int supp;
    int age;
    char matricule[7];
};

typedef struct tbloc_index_age tbloc_index_age; /*****************************/
struct tbloc_index_age{
    tenr_index_age tab[82];
    int nb;
};




/*** Fin ***/
/************************************************************************************************************/
/************************************************************************************************************/
/************************************************************************************************************/
/************************************************************************************************************/
/************************************************************************************************************/
/************************************************************************************************************/
/************************************************************************************************************/
/************************************************************************************************************/
/************************************************************************************************************/


/*** impl?mentation de la machine abstraite pour manipuler la liste des blocs vides ***/
void Allouer(ptr *p);
int valeur(ptr p);
void aff_val(ptr p, int val);
void aff_adr(ptr p, ptr q);
ptr suivant(ptr p);
/*** fin ***/

/*** Impl?mentation de la machine abstraite pour L-nonO-F ***/
int Ouvrir(fichier *fich, char *nom_f, char mod);
void Fermer(fichier fich);
int LireDir(fichier fich,int i,tbloc *buf);
int EcrireDir(fichier fich, int i, tbloc buf);
int LireSeq(fichier fich, tbloc *buf);
int EcrireSeq(fichier fich, tbloc buf);
int Aff_entete(fichier *fich, int i, int val);
int entete(fichier fich, int i);
int Alloc_Bloc(fichier fich, ptr *tete);
/*** fin ***/



/*** Fonctions ***/
void Creer_liste(char *Nom_fich, ptr *tete);
void save(ptr tete, char *nom_fich);




char *F_LnonOF = "PERSONNEL-ANP_DZ.bin";
char *Lb_vide = "LB_vide_actif.txt";
char *Lb_vide_arch = "LB_vide_archive.txt";
char *F_indx_mat = "IndexMat.bin";
char *F_arch = "archive.bin";
int taille_m, taille_non_dense;
tenr_index_mat *index_NONdense;

char mat[7];        int SUPi, SUPj;
char matR[7];
char matM[7];       int MODIFi, MODIFj;


int nouvelle_region, nouvelle_force, nouveau_grade;

int infos[11];

int NbEnr = 0;

int TSTATreg[9];
int TSTATforc[9];
int TSTATcatgrad[9];
int TSTATcatage[9];

int nb_ecriredir = 0, nb_liredir = 0;

tbloc buf_general;



#endif // HEADERS_H_INCLUDED
