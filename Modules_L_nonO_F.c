#include <stdio.h>
#include <stdlib.h>
#include "gtk\gtk.h"
#include "Headers.h"
#define an_courant 2022



/******************************* cette page contient les fonctionnalité demandées sur l'ennoncé su TP, ainsi que d'autre ************/
/************************************************************************************************************************************/


/******************* déclarations des différents widget utiliser par GTK dans cette page **************/

typedef GtkWidget *pGtkWidget;

pGtkWidget tabG[2000];
pGtkWidget tabG2[2000];
pGtkWidget tab[20000];

int iGTK = 0, iGTK2 = 0;
int iLAB = 0;

pGtkWidget tab_Gpropo[2000];
pGtkWidget tab_propo[30000];
int iGTK3 = 0;
int premiere_fois = 1, iLAB_propos = 0;

GtkStyleContext *context;

GtkWidget *fixed4;

GtkBuilder *builder;


/********************************** dialog 0 **********************************/

GtkWidget *dialog0;
GtkWidget *box0;
GtkWidget *suiv;
GtkWidget *lab;
GtkWidget *progress0;

/*******************************************************************************/



/********************************** dialog 1 **********************************/

GtkWidget *dialog1;
GtkWidget *b0;
GtkWidget *labdialog;
GtkWidget *annuler;
GtkWidget *oui;

/*******************************************************************************/

/********************************** window 1 ***********************************/


GtkWidget *window1;
GtkWidget *button0;
GtkWidget *image0;
GtkWidget *Apropos;
GtkWidget *developpers;

/*******************************************************************************/


/********************************** window 2 ***********************************/




/************ fixed 1 **************/


GtkWidget *window2;
GtkWidget *stack1;

GtkWidget *switcher1;

GtkWidget *label1;
GtkWidget *label2;
GtkWidget *label3;
GtkWidget *label4;
GtkWidget *label5;
GtkWidget *label6;
GtkWidget *label7;
GtkWidget *label8;
GtkWidget *label9;
GtkWidget *label10;
GtkWidget *label11;
GtkWidget *label12;
GtkWidget *label13;
GtkWidget *label14;
GtkWidget *label15;
GtkWidget *label16;
GtkWidget *label17;
GtkWidget *label18;
GtkWidget *label19;
GtkWidget *label44;
GtkWidget *label45;

GtkWidget *ent1;
GtkWidget *ent2;
GtkWidget *ent3;

GtkWidget *ent4;
GtkWidget *ent5;
GtkWidget *ent6;
GtkWidget *ent7;
GtkWidget *ent8;
GtkWidget *ent66;


GtkWidget *combo1;
GtkWidget *combo2;
GtkWidget *combo3;
GtkWidget *combo4;
GtkWidget *combo5;
GtkWidget *combo6;


GtkWidget *spin1;
GtkWidget *spin2;
GtkWidget *spin3;

GtkWidget *image1;

GtkWidget *button1;
GtkWidget *button2;

/***********************************/


/*********** fixed 2 ****************/



GtkWidget *label20;
GtkWidget *label21;
GtkWidget *label22;

GtkWidget *ent9;

GtkWidget *button3;
GtkWidget *button4;

GtkWidget *image2;

/**********************************/



/*********** fixed 3 ****************/



GtkWidget *label23;
GtkWidget *label24;
GtkWidget *label25;

GtkWidget *ent10;

GtkWidget *button5;
GtkWidget *button6;

GtkWidget *image3;

GtkWidget *box1;
    GtkWidget *label26;
    GtkWidget *label27;
    GtkWidget *label28;
    GtkWidget *label29;
    GtkWidget *label30;
    GtkWidget *label31;
    GtkWidget *label32;
    GtkWidget *label33;
    GtkWidget *label34;
    GtkWidget *label46;


GtkWidget *box2;
    GtkWidget *label35;
    GtkWidget *label36;
    GtkWidget *label37;
    GtkWidget *label38;
    GtkWidget *label39;
    GtkWidget *label40;
    GtkWidget *label41;
    GtkWidget *label42;
    GtkWidget *label43;
    GtkWidget *label47;

/**********************************/



/*********** fixed 4 ****************/



GtkWidget *label48;
GtkWidget *label49;

GtkWidget *ent11;

GtkWidget *button7;
GtkWidget *button7;
GtkWidget *button8;

GtkWidget *image4;

    GtkWidget *label50;
    GtkWidget *label51;
    GtkWidget *label52;
    GtkWidget *label53;


GtkWidget *combo7;
GtkWidget *ent12;

GtkWidget *combo8;
GtkWidget *ent13;

GtkWidget *combo9;
GtkWidget *ent14;


    GtkWidget *label54;
    GtkWidget *label55;
    GtkWidget *label56;
    GtkWidget *label57;
    GtkWidget *label58;


/**********************************/


/*********** fixed 5 ****************/



GtkWidget *label61;
GtkWidget *label62;
GtkWidget *label64;
GtkWidget *label65;
GtkWidget *label66;
GtkWidget *label67;

GtkWidget *label77;
GtkWidget *label78;

GtkWidget *label59;
GtkWidget *label60;

GtkWidget *button9;
GtkWidget *button10;

GtkWidget *image5;


GtkWidget *combo10;
GtkWidget *ent15;

GtkWidget *combo11;
GtkWidget *ent16;

GtkWidget *combo12;
GtkWidget *ent17;

GtkWidget *combo13;
GtkWidget *ent18;

GtkWidget *combo14;
GtkWidget *ent19;

GtkWidget *combo15;
GtkWidget *ent20;

GtkWidget *spin5;
GtkWidget *spin4;

GtkWidget *radio1;
GtkWidget *radio2;

GtkWidget *progress1;

GtkWidget *label151;

GtkWidget *scroll1;
GtkWidget *port1;
GtkWidget *box3;


/**********************************/


/*********** fixed 6 ****************/



GtkWidget *label63;
GtkWidget *label68;
GtkWidget *label69;
GtkWidget *label70;
GtkWidget *label71;
GtkWidget *label72;

GtkWidget *label74;

GtkWidget *label75;
GtkWidget *label76;

GtkWidget *label79;

GtkWidget *button11;
GtkWidget *button12;

GtkWidget *image6;


GtkWidget *combo16;
GtkWidget *ent21;

GtkWidget *combo17;
GtkWidget *ent23;

GtkWidget *combo18;
GtkWidget *ent24;

GtkWidget *combo19;
GtkWidget *ent25;

GtkWidget *combo20;
GtkWidget *ent26;

GtkWidget *combo21;
GtkWidget *ent27;

GtkWidget *spin6;
GtkWidget *spin7;



/**********************************/



/*********** fixed 7 ****************/

GtkWidget *stack2;
GtkWidget *switcher2;

/****** fix1 ********/


GtkWidget *radio3;
GtkWidget *radio4;


GtkWidget *button13;

GtkWidget *image7;

GtkWidget *radio5;
GtkWidget *radio6;
GtkWidget *radio7;
GtkWidget *radio8;
GtkWidget *radio9;
GtkWidget *radio10;
GtkWidget *radio11;
GtkWidget *radio12;

GtkWidget *label73;


GtkWidget *scroll2;

GtkWidget *port2;
GtkWidget *box4;

GtkWidget *button14;

GtkWidget *progress2;
GtkWidget *label158;

GtkWidget *button15;


/**********************************/


/*********** fix2 ******************/

GtkWidget *grid1;
    GtkWidget *label80;
    GtkWidget *label81;
    GtkWidget *label82;
    GtkWidget *label83;
    GtkWidget *label84;
    GtkWidget *label85;
    GtkWidget *label86;
    GtkWidget *label87;
    GtkWidget *label88;
    GtkWidget *label89;
    GtkWidget *label90;
    GtkWidget *label91;
    GtkWidget *label92;
    GtkWidget *label93;
    GtkWidget *label94;
    GtkWidget *label95;
    GtkWidget *label96;
    GtkWidget *label97;
    GtkWidget *label98;
    GtkWidget *label99;
    GtkWidget *label100;

GtkWidget *grid2;
    GtkWidget *label101;
    GtkWidget *label102;
    GtkWidget *label103;
    GtkWidget *label104;
    GtkWidget *label105;
    GtkWidget *label106;
    GtkWidget *label107;
    GtkWidget *label108;
    GtkWidget *label109;
    GtkWidget *label110;
    GtkWidget *label111;
    GtkWidget *label112;
    GtkWidget *label113;
    GtkWidget *label114;
    GtkWidget *label115;
    GtkWidget *label116;
    GtkWidget *label117;
    GtkWidget *label118;
    GtkWidget *label119;
    GtkWidget *label120;
    GtkWidget *label121;
    GtkWidget *label122;
    GtkWidget *label123;
    GtkWidget *label124;
    GtkWidget *label125;
    GtkWidget *label126;
    GtkWidget *label127;

GtkWidget *grid3;
    GtkWidget *label128;
    GtkWidget *label129;
    GtkWidget *label131;
    GtkWidget *label132;
    GtkWidget *label133;
    GtkWidget *label135;
    GtkWidget *label136;
    GtkWidget *label137;
    GtkWidget *label138;
    GtkWidget *label139;
    GtkWidget *label140;
    GtkWidget *label141;
    GtkWidget *label143;
    GtkWidget *label144;
    GtkWidget *label145;
    GtkWidget *label146;
    GtkWidget *label147;


GtkWidget *grid4;
    GtkWidget *label134;
    GtkWidget *label142;
    GtkWidget *label148;
    GtkWidget *label149;
    GtkWidget *label150;
    GtkWidget *label152;
    GtkWidget *label153;
    GtkWidget *label154;
    GtkWidget *label155;
    GtkWidget *label156;
    GtkWidget *label157;
    GtkWidget *label159;
    GtkWidget *label160;
    GtkWidget *label161;
    GtkWidget *label162;



/******************************************/


/*******************************************************************************/
/******************************************************* FIN des déclarations *****************************/



/**************** module d'insertion dans le fichier LnonOF  ***************************/

int Insertion_LnonOF (tenr e)
{
    fichier F; tbloc buf;
    int i, j, trouv, x, y;
    tenr_index_mat e1;

   // Rech_index_mat(e.matricule, F_indx_mat, &trouv, &x, &y);
    if (taille_non_dense == 0)
    {
        Ouvrir(&F, F_LnonOF, 'A');
        i = Alloc_Bloc(F, &t_vide_actif);
        buf.tab[0] = e;
        buf.nb = 1;
        buf.suivant = 0;
        buf.precedent = 0;
        EcrireDir(F, i, buf); nb_ecriredir++;
        Aff_entete(&F, 1, i);
        Aff_entete(&F, 2, i);
        Aff_entete(&F, 3, 1);
        Fermer(F);


        strcpy(e1.matricule, e.matricule); e1.adr.bloc = i; e1.adr.pos = 0; e1.supp = 0;

        Insert_index_mat(e1, F_indx_mat, 1 , 0);


        return 1;
    }
    else
    {
        rech_optimisee_mat(e.matricule, F_indx_mat , index_NONdense, taille_non_dense, &trouv, &x, &y);
        if (!trouv)
        {
            Ouvrir(&F, F_LnonOF, 'A');
            if (entete(F, 3) == 0)
            {
                i = Alloc_Bloc(F, &t_vide_actif);
                buf.nb = 1;
                buf.precedent = 0;
                buf.suivant = 0;
                buf.tab[0] = e;
                EcrireDir(F, i, buf); nb_ecriredir++;
                Aff_entete(&F, 1, i);
                Aff_entete(&F, 2, i);
                Aff_entete(&F, 3, 1);
                Aff_entete(&F, 4, 1);
                j = 0;
            }
            else
            {
                LireDir(F, entete(F, 2), &buf); nb_liredir++;
                if (buf.nb == 82)
                {
                    i = Alloc_Bloc(F, &t_vide_actif);
                    buf.suivant = i;
                    EcrireDir(F, entete(F, 2), buf ); nb_ecriredir++;

                    buf.suivant = 0;
                    buf.precedent = entete(F, 2);
                    buf.nb = 1;
                    buf.tab[0] = e;
                    EcrireDir(F, i, buf); nb_ecriredir++;
                    Aff_entete(&F, 2, i);
                    Aff_entete(&F, 3, entete(F, 3)+1);
                   // Aff_entete(&F, 4, entete(F, 4)+1);
                    if(t_vide_actif == NULL) Aff_entete(&F, 4, entete(F, 4) + 1);
                    j = 0;
                }
                else
                {
                    j = buf.nb;
                    buf.tab[buf.nb] = e;
                    buf.nb ++;
                    i = entete(F, 2);
                    EcrireDir(F, i, buf); nb_ecriredir++;
                    Aff_entete(&F, 3, entete(F, 3)+1);


                }
            }
            Fermer(F);

            fichier_index F_mat;

            strcpy(e1.matricule, e.matricule); e1.adr.bloc = i; e1.adr.pos = j; e1.supp = 0;

            Insert_index_mat(e1, F_indx_mat, x , y);

            return 1;

        }
        else return 0;
    }

}


/************************ module qui permet de modifier la region/ force /grade d'un enregistremant donnée par le matricule ***********/

int Modifier_rg_forc_grad(char matricule[7], int nouvelle_region, int nouvelle_force , int nouveau_grade)
{
    fichier F; tbloc buf;
    fichier_index F_mat;  tbloc_index_mat bufm;
    int trouv, i, j, tmp;


    Ouvrir(&F, F_LnonOF, 'A');
    Ouvrir_index(&F_mat, F_indx_mat, 'A');

    rech_optimisee_mat(matricule ,F_indx_mat , index_NONdense, taille_non_dense, &trouv, &i, &j);

    if (trouv)
    {
        LireDir_index_mat(F_mat, i, &bufm); nb_liredir++;
        LireDir(F, bufm.tab[j].adr.bloc, &buf); nb_liredir++;
        if ((buf.tab[bufm.tab[j].adr.pos].region != nouvelle_region) && ( nouvelle_region != -1))
        {
            TSTATreg[nouvelle_region]++;
            TSTATreg[buf.tab[bufm.tab[j].adr.pos].region]--;

            tmp = buf.tab[bufm.tab[j].adr.pos].region;
            buf.tab[bufm.tab[j].adr.pos].region = nouvelle_region;

        }

        if ((buf.tab[bufm.tab[j].adr.pos].force != nouvelle_force) && ( nouvelle_force != -1))
        {
            TSTATforc[buf.tab[bufm.tab[j].adr.pos].force]--;
            TSTATforc[nouvelle_force]++;

            tmp = buf.tab[bufm.tab[j].adr.pos].force;
            buf.tab[bufm.tab[j].adr.pos].force = nouvelle_force;
        }

        if ((buf.tab[bufm.tab[j].adr.pos].grade != nouveau_grade) && ( nouveau_grade != -1))
        {
            TSTATforc[nouveau_grade]++;
            TSTATforc[buf.tab[bufm.tab[j].adr.pos].grade]--;

            tmp = buf.tab[bufm.tab[j].adr.pos].grade;
            buf.tab[bufm.tab[j].adr.pos].grade = nouveau_grade;

        }

    }
    EcrireDir(F, bufm.tab[j].adr.bloc, buf); nb_ecriredir++;
    Fermer(F);
    Fermer_index(F_mat);
    return 0;
}

void Insertion_achive(tenr e, char *nom_fich_archive)
{
        fichier F; tbloc buf;
        int i, j;

        Ouvrir(&F, nom_fich_archive, 'A');
        if (entete(F, 4) == 0)
        {
            i = Alloc_Bloc(F, &t_vide_archive);
            buf.nb = 1;
            buf.precedent = 0;
            buf.suivant = 0;
            buf.tab[0] = e;
            EcrireDir(F, i, buf);
            Aff_entete(&F, 1, i);
            Aff_entete(&F, 2, i);
            Aff_entete(&F, 3, 1);
            Aff_entete(&F, 4, 1);
            j = 0;
        }
        else
        {
            LireDir(F, entete(F, 2), &buf);
            if (buf.nb == 82)
            {
                i = Alloc_Bloc(F, &t_vide_archive);
                buf.suivant = i;
                EcrireDir(F, entete(F, 2), buf);

                buf.suivant = 0;
                buf.precedent = entete(F, 2);
                buf.nb = 1;
                buf.tab[0] = e;
                EcrireDir(F, i, buf);
                Aff_entete(&F, 2, i);
                Aff_entete(&F, 3, entete(F, 3)+1);
                Aff_entete(&F, 4, entete(F, 4)+1);             /*******/
                j = 0;
            }
            else
            {
                j = buf.nb;
                buf.tab[buf.nb] = e;
                buf.nb ++;
                i = entete(F, 2);
                EcrireDir(F, i, buf);
                Aff_entete(&F, 3, entete(F, 3)+1);


            }
        }
        Fermer(F);

}

void Suppression_LnonOF(char *nom_fich, char *nom_fich_index, char *nom_fich_archive, tenr_index_mat *index_NONdense, int taille, int bloc, int pos)
{
    fichier F; tbloc buf1, buf2;
    fichier_index F_index; tbloc_index_mat buf_index;
    int tmp, i, j;
    Ouvrir(&F, nom_fich, 'A');

    LireDir(F, bloc, &buf1); nb_liredir++;
    Insertion_achive(buf1.tab[pos], nom_fich_archive);

        TSTATreg[buf1.tab[pos].region]--;
        TSTATforc[buf1.tab[pos].force]--;
        TSTATcatgrad[Determin_cat_grad(buf1.tab[pos].grade)]--;
        TSTATcatage[Determin_cat_age(an_courant - buf1.tab[pos].date_de_naissance.an)]--;

    if(buf1.nb == 1)
    {
                    ptr p;
                    Allouer(&p); aff_adr(p, t_vide_actif); aff_val(p, bloc); t_vide_actif = p;
                    if ((bloc != entete(F,1)) && (bloc != entete(F,2)))
                    {
                        LireDir(F, buf1.precedent, &buf2); nb_liredir++;
                        buf2.suivant = buf1.suivant;
                        EcrireDir(F, buf1.precedent, buf2); nb_ecriredir++;
                        LireDir(F, buf1.suivant, &buf2);  nb_liredir++;
                        buf2.precedent = buf1.precedent;
                        EcrireDir(F, buf1.suivant, buf2); nb_ecriredir++;
                    }
                    else if(bloc == entete(F,1))
                    {
                        Aff_entete(&F, 1, buf1.suivant);
                        if (buf1.suivant != 0)
                        {
                            LireDir(F, buf1.suivant, &buf2); nb_liredir++;
                            buf2.precedent = 0;
                            EcrireDir(F, buf1.suivant, buf2); nb_ecriredir++;
                        }
                    }
                    else if(bloc == entete(F,2))
                    {
                        Aff_entete(&F_index, 2,buf1.precedent);
                        if(buf1.precedent != 0)
                        {
                            LireDir(F, buf1.precedent, &buf2);  nb_liredir++;
                            buf2.suivant = 0;
                            EcrireDir(F, buf1.precedent, buf2); nb_ecriredir++;
                        }
                    }
    }
    else
    {
                    if (pos != buf1.nb)
                    {
                        buf1.tab[pos] = buf1.tab[buf1.nb-1];
                        rech_optimisee_mat(buf1.tab[buf1.nb-1].matricule, nom_fich_index, index_NONdense, taille, &tmp, &i, &j);
                        Ouvrir_index(&F_index, nom_fich_index, 'A');
                        //tmp = pos;
                        LireDir_index_mat(F_index, i, &buf_index);  nb_liredir++;
                        buf_index.tab[j].adr.pos = pos;
                        EcrireDir_index_mat(F_index, i, buf_index); nb_ecriredir++;
                        Fermer_index(F_index);
                    }
                    buf1.nb --;
                    EcrireDir(F, bloc, buf1); nb_ecriredir++;
    }


    Aff_entete(&F, 3, entete(F, 3)-1);
    Fermer(F);
}


/***************** module de suppression d'un enregistrement du fichier LnonOF *****************/

int supp_enr_LnonOF(char matricule[7])
{
    fichier_index Fi; tbloc_index_mat buf;
    int trouv, i, j;

    rech_optimisee_mat(matricule, F_indx_mat , index_NONdense, taille_non_dense, &trouv, &i, &j);
    if (trouv)
    {
         Ouvrir_index(&Fi, F_indx_mat, 'A');
         LireDir_index_mat(Fi, i, &buf);
         buf.tab[j].supp = 1;
         EcrireDir_index_mat(Fi, i, buf);
         Aff_entete_index(&Fi, 3, entete_index(Fi, 3)+1);
         Fermer_index(Fi);
         Suppression_LnonOF(F_LnonOF, F_indx_mat, F_arch,  index_NONdense, taille_non_dense, buf.tab[j].adr.bloc, buf.tab[j].adr.pos);
         return 1;
    }
    else return 0;
}


/*************** module de creation d'un fichier LnonOF  archive qui contient les enrs supprimées du fichier actif **************/

void Creer_archive(char *nom_fich_archive)
{
    fichier F;
    Ouvrir(&F, nom_fich_archive, 'N');
    Fermer(F);
}

/**************** cette fonction est utilisé par le tri rapide ***********/
int fctcmp_mat(const void *a, const void *b)
{
     tenr_index_mat x , y;
     x = *(tenr_index_mat *)a;
     y = *(tenr_index_mat *)b;
     if ( atoi(x.matricule) < atoi(y.matricule))
        return -1;
    if ( atoi(x.matricule) == atoi(y.matricule))
       return 0;
    // sinon c-a-d x.cle > y.cle
    return 1;
}


/********************* fonction de suppretion par un critere donnée (par ex : tous les enrs d'une region donnée entre deux ages donnés ********/

void suppression_generale(int age_min, int age_max, int sexe, int willaya, int grp_sang, int region, int force, int grade, double Gcpt)
{

    gtk_label_set_text(GTK_LABEL(lab), "Suppression en cours\nVeuillez patientez...");

    int an_min, an_max, affich;
    an_max = an_courant - age_min;
    an_min = an_courant - age_max;

    fichier F, Far; tbloc buf1, buf2, bufar;
    fichier_index  F_mat, F_index;  tbloc_index_mat buf_index, bufm;
    int trouv, i, j, x, y = 0, a, b, cpt = 0, bloc, d = 0;                     double prcntg = 0;
    tenr_index_mat *tab = malloc(300000*sizeof(tenr_index_mat));

    Ouvrir(&F, F_LnonOF, 'A');
    Ouvrir(&Far, F_arch, 'A');
    i = entete(F, 1);
    a = 1; b = 0;
    while (i != 0)
    {
        LireDir(F, i, &buf1); nb_liredir++;
        j = 0;
        while (j< buf1.nb)
        {
            affich = 1;

            if(grade != -1)
            {
                if (grade != buf1.tab[j].grade) affich = 0;
            }


            if ((buf1.tab[j].date_de_naissance.an > an_max)||(buf1.tab[j].date_de_naissance.an < an_min))
            {
                affich = 0;
            }

            if(sexe != -1)
            {
                if (sexe != buf1.tab[j].sexe) affich = 0;
            }

            if(willaya != -1)
            {
                if (willaya != buf1.tab[j].willaya) affich = 0;
            }

            if(grp_sang != -1)
            {
                if (grp_sang != buf1.tab[j].grp_sang) affich = 0;
            }

            if(region != -1)
            {
                if (region != buf1.tab[j].region) affich = 0;
            }

            if(force != -1)
            {
                if (force != buf1.tab[j].force) affich = 0;
            }

            if (affich == 1 )
            {

                NbEnr--;
                TSTATreg[buf1.tab[j].region]--;
                TSTATforc[buf1.tab[j].force]--;
                TSTATcatgrad[Determin_cat_grad(buf1.tab[j].grade)]--;
                TSTATcatage[Determin_cat_age(an_courant - buf1.tab[j].date_de_naissance.an)]--;

                prcntg++;


                gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress0), (gdouble) (prcntg/Gcpt));

                while (gtk_events_pending()) gtk_main_iteration();
                gtk_widget_show_all(dialog0);


                    if (d <= 81)
                    {
                        bufar.tab[d] = buf1.tab[j];
                        d++;
                    }
                    else
                    {
                        bufar.nb = 82;
                        bloc = Alloc_Bloc(Far, &t_vide_archive);
                        if (entete(Far, 3) == 0)
                        {
                            bufar.suivant = 0;
                            Aff_entete(&Far, 1, bloc);
                            Aff_entete(&Far, 2, bloc);
                            if(t_vide_archive == NULL) Aff_entete(&Far, 4, 1);
                            Aff_entete(&Far, 3, entete(Far, 3) + 82);
                        }
                        else
                        {
                            bufar.suivant = entete(Far, 1);
                            Aff_entete(&Far, 1, bloc);
                            if(t_vide_archive == NULL) Aff_entete(&Far, 4, entete(Far, 4) + 1);
                            Aff_entete(&Far, 3, entete(Far, 3) + 82);
                        }
                        EcrireDir(Far, bloc, bufar);
                        bufar.tab[0] = buf1.tab[j];
                        d = 1;
                    }

                    if(buf1.nb == 1)
                    {
                        ptr p;
                        Allouer(&p); aff_adr(p, t_vide_actif); aff_val(p, i); t_vide_actif = p;
                        if ((i != entete(F,1)) && (i != entete(F,2)))
                        {
                            LireDir(F, buf1.precedent, &buf2);  nb_liredir++;
                            buf2.suivant = buf1.suivant;
                            EcrireDir(F, buf1.precedent, buf2); nb_ecriredir++;
                            LireDir(F, buf1.suivant, &buf2); nb_liredir++;
                            buf2.precedent = buf1.precedent;
                            EcrireDir(F, buf1.suivant, buf2); nb_ecriredir++;
                        }
                        else if(i == entete(F,1))
                        {
                            Aff_entete(&F, 1, buf1.suivant);
                            if (buf1.suivant != 0)
                            {
                                LireDir(F, buf1.suivant, &buf2); nb_liredir++;
                                buf2.precedent = 0;
                                EcrireDir(F, buf1.suivant, buf2); nb_ecriredir++;
                            }
                        }
                        else if(i == entete(F,2))
                        {
                            Aff_entete(&F, 2, buf1.precedent);
                            if(buf1.precedent != 0)
                            {
                                LireDir(F, buf1.precedent, &buf2); nb_liredir++;
                                buf2.suivant = 0;
                                EcrireDir(F, buf1.precedent, buf2); nb_ecriredir++;
                            }
                        }
                    }
                    else
                    {
                        if (j != buf1.nb)
                        {
                            buf1.tab[j] = buf1.tab[buf1.nb-1];
                        }
                            buf1.nb --;
                            j--;
                    }
                    Aff_entete(&F, 3, entete(F, 3)-1);

            }
            else
            {
               strcpy(tab[b].matricule, buf1.tab[j].matricule);
               tab[b].adr.bloc = i; tab[b].adr.pos = j;
               tab[b].supp = 0;
               b++;
            }
            j++;
        }
        EcrireDir(F, i, buf1); nb_ecriredir++;
        i = buf1.suivant;
    }
     if (b)
     {
         qsort(tab, b, sizeof(tenr_index_mat), fctcmp_mat);
         Creer_index_mat(F_indx_mat, tab, b);
     }
     else
     {
          taille_non_dense = 0;
          Ouvrir_index(&F_mat, F_indx_mat, 'N');
          Fermer_index(F_mat);
     }

     bufar.nb = d;
     bloc = Alloc_Bloc(Far, &t_vide_archive);
     bufar.suivant = entete(Far, 1);
     Aff_entete(&Far, 1, bloc);
     if(t_vide_archive == NULL) Aff_entete(&Far, 4, entete(Far, 4) + 1);
     Aff_entete(&Far, 3, entete(Far, 3) + d);
     EcrireDir(Far, bloc, bufar);

     Fermer(Far);
     Fermer(F);
     free(tab);
}





/*********************************************************************************************/

double Count_requete (char *Fich, int age_min, int age_max, int sexe, int willaya, int grp_sang, int region, int force, int grad_min, int grad_max)
{
    double cpt = 0;


    int an_min, an_max, affich;
    an_max = an_courant - age_min;
    an_min = an_courant - age_max;



    fichier F; tbloc buf;
    int  i, j;
    Ouvrir(&F, Fich, 'A' );
    i = entete(F, 1);
    while (i != 0)
    {
        LireDir(F, i, &buf);
        for(j = 0; j< buf.nb; j++)
        {
            affich = 1;

            if(grad_min != -1)
            {
                if ((buf.tab[j].grade > grad_max)||(buf.tab[j].grade < grad_min))
                {
                    affich = 0;
                }
            }


            if ((buf.tab[j].date_de_naissance.an > an_max)||(buf.tab[j].date_de_naissance.an < an_min))
            {
                affich = 0;
            }

            if(sexe != -1)
            {
                if (sexe != buf.tab[j].sexe) affich = 0;
            }

            if(willaya != -1)
            {
                if (willaya != buf.tab[j].willaya) affich = 0;
            }

            if(grp_sang != -1)
            {
                if (grp_sang != buf.tab[j].grp_sang) affich = 0;
            }

            if(region != -1)
            {
                if (region != buf.tab[j].region) affich = 0;
            }

            if(force != -1)
            {
                if (force != buf.tab[j].force) affich = 0;
            }

            if (affich == 1 )
            {
                cpt++;
            }


        }
        i = buf.suivant;
    }
    Fermer(F);
    return cpt;
}



/************ la requete selon un critere donnée *************/


void Requete_General (char *Fich,int age_min, int age_max, int sexe, int willaya, int grp_sang, int region, int force, int grad_min, int grad_max, double Gcpt)
{
    double cpt;   int sss = 0;
    char str[256];
    char genre[30];

    gtk_label_set_text(GTK_LABEL(label151), "Chargement en cours .. veillez patientez");

    gtk_container_remove (GTK_CONTAINER(port1),GTK_WIDGET(tabG[iGTK]));

    iGTK++;

    tabG[iGTK] = gtk_vbox_new (TRUE,5);


    gtk_container_add(GTK_CONTAINER(port1),GTK_WIDGET(tabG[iGTK]));




    int an_min, an_max, affich;
    an_max = an_courant - age_min;
    an_min = an_courant - age_max;



    fichier F; tbloc buf;
    int  i, j;
    Ouvrir(&F, Fich, 'A' );
    i = entete(F, 1);
    while (i != 0)
    {
        LireDir(F, i, &buf); nb_liredir++;
        for(j = 0; j< buf.nb; j++)
        {
            affich = 1;

            if(grad_min != -1)
            {
                if ((buf.tab[j].grade > grad_max)||(buf.tab[j].grade < grad_min))
                {
                    affich = 0;
                }
            }


            if ((buf.tab[j].date_de_naissance.an > an_max)||(buf.tab[j].date_de_naissance.an < an_min))
            {
                affich = 0;
            }

            if(sexe != -1)
            {
                if (sexe != buf.tab[j].sexe) affich = 0;
            }

            if(willaya != -1)
            {
                if (willaya != buf.tab[j].willaya) affich = 0;
            }

            if(grp_sang != -1)
            {
                if (grp_sang != buf.tab[j].grp_sang) affich = 0;
            }

            if(region != -1)
            {
                if (region != buf.tab[j].region) affich = 0;
            }

            if(force != -1)
            {
                if (force != buf.tab[j].force) affich = 0;
            }

            if (affich == 1 )
            {
                cpt++;  sss++;

                if ( buf.tab[j].sexe == 1) strcpy(genre, "MASCULIN\n");
                if ( buf.tab[j].sexe == 2) strcpy(genre, "FEMININ\n");

                  sprintf(str, "\n  %s   %s\n\t%s\n\t%s\t%s\t%d / %d / %d\n\t%s\n\tRegion %d : %s\t%s\t%s\n\t%d", buf.tab[j].nom, buf.tab[j].prenom, buf.tab[j].matricule, genre, tab_wilaya[buf.tab[j].willaya-1],
                                 buf.tab[j].date_de_naissance.jour, buf.tab[j].date_de_naissance.mois, buf.tab[j].date_de_naissance.an,
                                 tab_grp_sang[buf.tab[j].grp_sang-1],buf.tab[j].region, tab_region[buf.tab[j].region-1], tab_force[buf.tab[j].force-1], tab_grade[buf.tab[j].grade-1], i);

                  gchar *bio = g_locale_to_utf8 (str, -1, NULL, NULL, NULL);

                  tab[iLAB] = gtk_label_new("Label 1");
                  gtk_misc_set_alignment(tab[iLAB], 0, 0);
                  gtk_label_set_text(GTK_LABEL(tab[iLAB]), bio);

                  context = gtk_widget_get_style_context(GTK_WIDGET(tab[iLAB]));
                  gtk_style_context_add_class(context, "labbox1");




                  gtk_box_pack_start(GTK_BOX(tabG[iGTK]),tab[iLAB],0,0,0);
                  iLAB++;
                  gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress1), (gdouble)( cpt/Gcpt));
                  while (gtk_events_pending()) gtk_main_iteration();
                  gtk_widget_show_all(window2);
            }


        }
        i = buf.suivant;
    }
    Fermer(F);
    gtk_label_set_text(GTK_LABEL(label151), "Fin de chargement");
    if (Gcpt == 0) gtk_label_set_text(GTK_LABEL(label151), "Aucun enregistrement correspondant aux criteres\n\t\t\t\tde requete");



}


/********************************************************************************************************/



/***********************************************************************************************************************************/


/************ creation des liste des blocs vide ***************/


void Creer_liste(char *Nom_fich, ptr *tete)
{
    FILE *f; int a; ptr p = NULL,q = NULL;
    f = fopen(Nom_fich, "r");
    fscanf(f,"%d",&a);
    if (a == 0) *tete = NULL;
    else
    {
        while (!feof(f))
        {

            Allouer(&q);
            aff_adr(q,p);
            aff_val(q,a);
            p = q;
            fscanf(f,"%d",&a);
        }
        *tete = p;
    }
    fclose(f);
}

/*********** sauvegarde des num des blocs vide **************/

void save(ptr tete, char *nom_fich)
{
    FILE *f;
    f = fopen(nom_fich,"w");
    if (tete == NULL) fprintf(f,"%d ",0);
    while(tete != NULL)
    {
        fprintf(f,"%d\n",valeur(tete));
        tete = suivant(tete);
    }
    fclose(f);
}


/************************************************************************************************/
/************************************************************************************************/


/********************** chargement initile du fichier des personnels LnonOF ***************/

void charg_init(char *nom_fich, int n, tenr_index_mat *tab)
{

    gtk_label_set_text(GTK_LABEL(lab), "Chargement du fichier personnel\n         Veuillez patientez...");

    char matricule[7], nom[31], prenom[31];
    LaDate date_de_naissance;
    int willaya, grp_sang, grade, force, region, sexe;
    fichier F;
    int j = 0, k, p; tbloc buf;        double pr;
    Ouvrir(&F,nom_fich,'N');
    int i = Alloc_Bloc(F,&t_vide_actif);
    Aff_entete(&F,1,i);
    for (k = 1; k<=n; k++)
    {

         mat_alea(matricule); nom_alea(nom, prenom); alea_date(&date_de_naissance);
         willaya = alea_general(1,0,0,0,0); grp_sang = alea_general(0,1,0,0,0);
         grade = alea_general(0,0,1,0,0); force = alea_general(0,0,0,1,0); region = alea_general(0,0,0,0,1);
         sexe = Random(1, 2);
         if (j < 82)
         {
             strcpy(buf.tab[j].matricule, matricule);
             strcpy(buf.tab[j].nom, nom); strcpy(buf.tab[j].prenom, prenom);
             buf.tab[j].date_de_naissance.jour = date_de_naissance.jour;
             buf.tab[j].date_de_naissance.mois = date_de_naissance.mois;
             buf.tab[j].date_de_naissance.an = date_de_naissance.an;
             buf.tab[j].willaya = willaya;
             buf.tab[j].sexe = sexe;
             buf.tab[j].grade = grade;
             buf.tab[j].grp_sang = grp_sang;
             buf.tab[j].force = force;
             buf.tab[j].region = region;
             strcpy(tab[k-1].matricule,matricule);
             tab[k-1].adr.bloc = i; tab[k-1].adr.pos = j;
             tab[k-1].supp = 0;
             j++;
         }
         else
         {
             Aff_entete(&F,4,i);
             p = Alloc_Bloc(F,&t_vide_actif);
             buf.suivant = p;
             buf.precedent = i-1;
             buf.nb = j; EcrireDir(F,i,buf); nb_ecriredir++;
             strcpy(buf.tab[0].matricule, matricule);
             strcpy(buf.tab[0].nom, nom); strcpy(buf.tab[0].prenom, prenom);
             buf.tab[0].date_de_naissance.jour = date_de_naissance.jour;
             buf.tab[0].date_de_naissance.mois = date_de_naissance.mois;
             buf.tab[0].date_de_naissance.an = date_de_naissance.an;
             buf.tab[0].willaya = willaya;
             buf.tab[0].sexe = sexe;
             buf.tab[0].grade = grade;
             buf.tab[0].grp_sang = grp_sang;
             buf.tab[0].force = force;
             buf.tab[0].region = region;
             i = p;
             strcpy(tab[k-1].matricule,matricule);
             tab[k-1].adr.bloc = i; tab[k-1].adr.pos = 0;
             tab[k-1].supp = 0;

             j = 1;
         }

         pr = (double) (k);

         gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress0), (gdouble) (pr/300000));

        while (gtk_events_pending()) gtk_main_iteration();
          gtk_widget_show_all(dialog0);
    }
    buf.suivant = 0;
    buf.precedent = i-1;
    buf.nb = j;
    EcrireDir(F,i,buf); nb_ecriredir++;
    Aff_entete(&F,1,1);
    Aff_entete(&F,3,n);
    Aff_entete(&F,2,i);
    Aff_entete(&F,4,i);
    Fermer(F);

    int y;
}


/***************** creation de l'index mat ***************/


void Creer_index_mat(char *nom_fich, tenr_index_mat *tab, int taille)
{
    int y = 0;
    fichier_index F; tbloc_index_mat buf;
    Ouvrir_index(&F, nom_fich, 'N');
    int i = 1, j = 0, k, cpt1 = 0, cpt2 = 0, tmp;
    for (k = 0; k<taille; k++)
    {

            strcpy(buf.tab[j].matricule, tab[k].matricule);
            buf.tab[j].adr.bloc = tab[k].adr.bloc; buf.tab[j].adr.pos = tab[k].adr.pos;
            buf.tab[j].supp = 0;
            j++;
            cpt1++;
            if(j == 70)
            {
                cpt2++;
                strcpy(index_NONdense[y].matricule, tab[k].matricule);
                index_NONdense[y].adr.bloc = cpt2; index_NONdense[y].adr.pos = 0;
                index_NONdense[y].supp = 0;
                y++;
                buf.nb = j;
                EcrireDir_index_mat(F, i, buf); nb_ecriredir++;
                i++; j = 0;
            }

    }
    if (( taille % 70) != 0)
    {
        buf.nb = j;
        EcrireDir_index_mat(F, i, buf); nb_ecriredir++;
        strcpy(index_NONdense[y].matricule, tab[taille-1].matricule);
        cpt2++;
        index_NONdense[y].adr.bloc = cpt2; index_NONdense[y].adr.pos = 0;
        index_NONdense[y].supp = 0;
        taille_non_dense = y+1;

    }
    else
    {
        i--; taille_non_dense = y;
    }

    Aff_entete_index(&F, 1, i);
    Aff_entete_index(&F, 2, cpt1);
    Fermer_index(F);

}
/***********************************************************************************************/
/***********************************************************************************************/


void mat_alea(char *mtr)
{
    unsigned int m;
    m = 111111 + (Random(1,999999)*Random(1,999999))% 888889 ;
    itoa(m, mtr, 10);
}

void nom_alea(char *nom, char *prenom)
{
    int len,i,n;
    len = Random(4,30);
    for (i = 0; i < len; i++)
    {
        n = Random(65,90);
        nom[i] = (char) n;
    }
    nom[len] = '\0';
    len = Random(4,30); n = Random(65,90);
    prenom[0] = (char) n;
    for (i = 1; i < len; i++)
    {
        n = Random(97,122);
        prenom[i] = (char) n;
    }
     prenom[len] = '\0';
}

void alea_date (LaDate *date)
{
    int x;
    x = Random(1940, 2003);
    date->an = x ;
    if (x % 4 == 0)
    {
        x = Random(1, 12);
        date->mois = x;
        if (x == 2) x = Random(1, 29);
        else
        {
            if (((x<=7) && ( x%2 == 1)) || ((x>=8) && (x%2 == 0))) x =  Random(1, 31);
            else if (((x<=7) && ( x%2 == 0)) || ((x>=8) && (x%2 == 1))) x =  Random(1, 30);
        }
        date->jour = x;
    }
    else
    {
        x = Random(1, 12);
        date->mois = x;
        if (x == 2) x = Random(1, 28);
        else
        {
            if (((x<=7) && ( x%2 == 1)) || ((x>=8) && (x%2 == 0))) x =  Random(1, 31);
            else if (((x<=7) && ( x%2 == 0)) || ((x>=8) && (x%2 == 1))) x =  Random(1, 33);
        }
        date->jour = x;
    }
}

int alea_general(int wilaya, int grp_sang, int grade, int force, int region )
{
    int x;

    if (wilaya == 1) x = Random(1,58);
    else if (grp_sang == 1) x = Random(1,8);
    else if (grade == 1) x = Random(1,18);
    else if (force == 1) x = Random(1,8);
    else if (region == 1) x = Random(1,6);
    else return 0;
    return x;
}

/*********************************************************************************************/

void Rech_index_mat(char matricule[7], char *Nom_Fich, int *trouv, int *i, int *j)
{
    int bi, bs, inf ,sup, stop =0;  tbloc_index_mat buf;
    fichier_index F;
    Ouvrir_index(&F, Nom_Fich, 'A');
    bs = entete_index(F, 1);
    bi = 1;
    *trouv = 0;
    *j = 0;
    while ((bi <= bs) && (! *trouv) && (!stop))
    {
        *i = (bi+bs)/2;
        LireDir_index_mat(F, *i, &buf );
        if ((atoi(matricule) >= atoi(buf.tab[0].matricule)) && ((atoi(matricule) <= atoi(buf.tab[buf.nb-1].matricule))))
        {
            inf = 0; sup = buf.nb-1;
            while((inf <= sup) && (!*trouv) && (!stop))
            {
                *j = (inf+sup)/2;
                if ((atoi(matricule) == atoi(buf.tab[*j].matricule)) && (buf.tab[*j].supp == 0)) *trouv = 1;
                else if ((atoi(matricule) == atoi(buf.tab[*j].matricule)) && (buf.tab[*j].supp == 1)) stop = 1;
                else if (atoi(matricule) < atoi(buf.tab[*j].matricule)) sup = *j-1;
                else if (atoi(matricule) > atoi(buf.tab[*j].matricule)) inf = *j+1;
                //else inf = *j+1;
            }
            if (inf > sup ) *j = inf;
            stop = 1;
        }
        else if (atoi(matricule) < atoi(buf.tab[0].matricule)) bs = *i-1;
        else bi = *i+1;
    }
    if (bi > bs) {*i = bi; *j = 0;}
    Fermer_index(F);
}

void Insert_index_mat (tenr_index_mat e, char *Nom_Fich, int i, int j)
{
    int  k, trouv, b; fichier_index F;
    tenr_index_mat x; tbloc_index_mat buf;
    Ouvrir_index(&F, Nom_Fich, 'A');
    //Rech_index_mat(e.matricule, Nom_Fich, &trouv, &i, &j);


    int continu = 1;
    while (continu && i <=entete_index(F, 1))
    {
        LireDir_index_mat(F, i, &buf); nb_liredir++;
        if (buf.tab[j].supp == 1)
        {
            buf.tab[j] = e;
            EcrireDir_index_mat(F, i, buf); nb_ecriredir++;
            continu = 0;
            if (j == buf.nb-1)
            {
                rech_insexNONdense_mat(e.matricule, index_NONdense, taille_non_dense, &trouv, &b);
                strcpy(index_NONdense[b].matricule, e.matricule);
            }
        }
        else
        {
            x = buf.tab[buf.nb-1];
            k = buf.nb-1;
            while (k > j)
            {
                buf.tab[k] = buf.tab[k-1];
                k--;
            }
            buf.tab[j] = e;
            if (buf.nb < 82)
            {
                buf.nb++;
                buf.tab[buf.nb-1] = x;
                EcrireDir_index_mat(F, i, buf); nb_ecriredir++;
                continu = 0;
            }
            else
            {
                rech_insexNONdense_mat(x.matricule, index_NONdense, taille_non_dense, &trouv, &b);
                strcpy(index_NONdense[b].matricule, buf.tab[81].matricule);
                EcrireDir_index_mat(F, i, buf); nb_ecriredir++;
                i++;
                j = 0;
                e = x;

            }
        }
    }
    if (i >entete_index(F,1))
    {
        strcpy(index_NONdense[taille_non_dense].matricule, e.matricule);
        index_NONdense[taille_non_dense].adr.bloc = entete_index(F, 1)+1;
        index_NONdense[taille_non_dense].supp = 0; index_NONdense[taille_non_dense].adr.pos = 0;
        taille_non_dense = taille_non_dense + 1;  // printf("\npleaaaaase %d", taille_non_dense);
        buf.tab[0] = e;
        buf.nb = 1;
        EcrireDir_index_mat(F, i, buf); nb_ecriredir++;
        Aff_entete_index(&F, 1, i);
    }
    Aff_entete_index(&F, 2, entete_index(F, 2)+1);
    Fermer_index(F);
}


void Reorganisation_index_mat(char *Nom_Fich)
{
    fichier_index F1,F2;
    tbloc_index_mat buf1, buf2;
    int i, j, m=0, k =0;
    int cpt = 0;
    Ouvrir_index(&F1, Nom_Fich, 'A');
    Ouvrir_index(&F2,"temp.bin", 'N' );

    for (i = 1; i<= entete_index(F1,1); i++)
    {
        LireDir_index_mat(F1, i, &buf1); nb_liredir++;
        for (j = 0; j < buf1.nb; j++)
        {
            if (!(buf1.tab[j].supp))
            {
                cpt++;
                buf2.tab[k] = buf1.tab[j];
                k++;
                if (k == 70)
                {
                    m++;
                    buf2.nb = k;
                    EcrireDir_index_mat(F2, m, buf2); nb_ecriredir++;
                    k = 0;
                }
            }
        }
    }
    buf2.nb = k;
    EcrireDir_index_mat(F2, m, buf2); nb_ecriredir++;
    Aff_entete_index(&F2, 1, m+1);
    Aff_entete_index(&F2, 2, cpt);
    Fermer_index(F1);
    Fermer_index(F2);
    rename(Nom_Fich,"temp.bin");
    remove(Nom_Fich);
    rename("temp.bin",Nom_Fich);
}

void Suppression_index_mat (char *Nom_Fich, tenr_index_mat e)
{
    fichier_index F;
    tbloc_index_mat buf;
    int trouv, i, j;
    Rech_index_mat(e.matricule, Nom_Fich, &trouv, &i, &j);
    if (trouv)
    {
        Ouvrir_index(&F, Nom_Fich, 'A');
        LireDir_index_mat(F,i, &buf); nb_liredir++;
        buf.tab[j].supp = 1;
        EcrireDir_index_mat(F, i, buf); nb_ecriredir++;
        Aff_entete_index(&F, 3, entete_index(F,3)+1);
    }
    Fermer_index(F);
}


void Rech_dech_table (tenr_index_mat *tab, int tai, char matricule[7], int bloc, int pos, int *trouv, int *indic)
{
    * trouv = 0;
    int inf = 0, sup = tai-1;
    while((inf <= sup) && (!*trouv))
    {
        *indic = (inf+sup)/2;
        if ((atoi(matricule) == atoi(tab[*indic].matricule)) && (tab[*indic].adr.bloc == bloc) && (tab[*indic].adr.bloc == bloc)) *trouv = 1;
        else if (atoi(matricule) < atoi(tab[*indic].matricule)) sup = *indic-1;
        else inf = *indic+1;
    }
}

void creer_indexNONdense_Mat(char *nom_fich)
{
    fichier_index F; tbloc_index_mat buf;
    int i;
    Ouvrir_index(&F, nom_fich, 'A');

    for (i = 1; i<=entete_index(F,1); i++)
    {
        LireDir_index_mat(F, i, &buf); nb_liredir++;
        strcpy(index_NONdense[i-1].matricule, buf.tab[buf.nb-1].matricule);
        index_NONdense[i-1].adr.bloc = i; index_NONdense[i-1].supp = 0; index_NONdense[i-1].adr.pos = 0;
    }
     taille_non_dense = entete_index(F, 1);
    Fermer_index(F);
}






void rech_insexNONdense_mat(char matricule[7], tenr_index_mat *tab, int taille, int *trouv, int *i)
{
    int bi = 0, bs = taille-1, k;
    int t = 0;
    while((bi <= bs) && (!t))
    {
        k = (bi + bs)/2;
        if (atoi(tab[k].matricule) == atoi(matricule))
        {
            t = 1; *i = k;
        }
        else if (atoi(matricule) < atoi(tab[k].matricule)) bs = k-1;
        else bi = k+1;
    }
    if (bi>bs) *i = bi;
    else if (tab[k].supp == 1) t = 0;
    *trouv = t;
}

void rech_optimisee_mat(char matricule[7], char *Nom_Fich, tenr_index_mat *tab, int taille, int *trouv, int *i, int *j)
{
    tbloc_index_mat buf;
    fichier_index F;
    Ouvrir_index(&F, Nom_Fich, 'A');
    rech_insexNONdense_mat(matricule, tab, taille, trouv, i);

    if (*i == taille)
    {
        *trouv = 0;
        *i = entete_index(F, 1)+1;
        *j = 0;
    }
    else
    {
        LireDir_index_mat(F, tab[*i].adr.bloc, &buf); nb_liredir++;
        *i = tab[*i].adr.bloc;
        rech_insexNONdense_mat(matricule, buf.tab, buf.nb, trouv, j);
    }
    Fermer_index(F);
}




/*********************** module d'epuration du fichier personnels **********/

void epuration(char *nom_fich, tenr_index_mat *tab, int tai)
{

    gtk_label_set_text(GTK_LABEL(lab), "Epuration du fichier personnel\n         Veuillez patientez...");

    fichier F; tbloc buf1, buf2;
    int j, trouv, indic, cpt = 0;   int i = 0; double pr = 0;
    ptr p;
    qsort(tab, tai, sizeof(tenr_index_mat), fctcmp_mat);
    Ouvrir(&F, nom_fich, 'A');
    while(i < tai)
    {
        j = i+1;
        while((j < tai) && (!strcmp(tab[i].matricule, tab[j].matricule)))
        {
            cpt ++ ;
            ////////printf("\n%s     ,    %d,%d\n", tab[j].matricule,tab[j].adr.bloc,tab[j].adr.pos);
            tab[j].supp = 1;
            LireDir(F, tab[j].adr.bloc, &buf1); nb_liredir++;
            if(buf1.nb == 1)
            {
                Allouer(&p); aff_adr(p, t_vide_actif); aff_val(p, tab[j].adr.bloc); t_vide_actif = p;
                if ((tab[j].adr.bloc != entete(F,1)) && (tab[j].adr.bloc != entete(F,2)))
                {
                    LireDir(F, buf1.precedent, &buf2); nb_liredir++;
                    buf2.suivant = buf1.suivant;
                    EcrireDir(F, buf1.precedent, buf2); nb_ecriredir++;
                    LireDir(F, buf1.suivant, &buf2); nb_liredir++;
                    buf2.precedent = buf1.precedent;
                    EcrireDir(F, buf1.suivant, buf2); nb_ecriredir++;
                }
                else if(tab[j].adr.bloc == entete(F,1))
                {
                        Aff_entete(&F, 1, buf1.suivant);
                        if (buf1.suivant != 0)
                        {
                            LireDir(F, buf1.suivant, &buf2); nb_liredir++;
                            buf2.precedent = 0;
                            EcrireDir(F, buf1.suivant, buf2); nb_ecriredir++;
                        }
                }
                else if(tab[j].adr.bloc == entete(F,2))
                {
                    Aff_entete(&F, 2, buf1.precedent);
                    if(buf1.precedent != 0)
                    {
                        LireDir(F, buf1.precedent, &buf2); nb_liredir++;
                        buf2.suivant = 0;
                        EcrireDir(F, buf1.precedent, buf2); nb_ecriredir++;
                    }
                }
            }
            else
            {
                if (tab[j].adr.pos != buf1.nb)
                {
                    buf1.tab[tab[j].adr.pos] = buf1.tab[buf1.nb-1];   /***/
                    Rech_dech_table(tab, tai, buf1.tab[buf1.nb-1].matricule, tab[j].adr.bloc, buf1.nb-1, &trouv, &indic);
                    tab[indic].adr.pos = tab[j].adr.pos;
                }

                buf1.nb--;
                EcrireDir(F, tab[j].adr.bloc, buf1); nb_ecriredir++;
                /***/

            }
            //Aff_entete(&F, 3, entete(F, 3)-1);
            j++;
            i++;

        }

        i++;

        pr = (double)(i);

        gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress0), (gdouble) (pr/300000));

        while (gtk_events_pending()) gtk_main_iteration();
          gtk_widget_show_all(dialog0);




      /*  double prcntg;
        prcntg = ( (double)i / (double)tai )*100;
        gotoxy(30,8);
        printf("%.2f %\n",prcntg);*/
    }

    Aff_entete(&F, 3, entete(F, 3) - cpt);
    Fermer(F);
}

void charg_index_mat(char *nom_fich, tenr_index_mat *tab, int *tai_tab)
{
    fichier F; tbloc buf;
    int i, j, k = 0;
    Ouvrir(&F, nom_fich, 'A');
    i = entete(F, 1);
    while (i != 0)
    {
        LireDir(F, i, &buf);  nb_liredir++;
        for (j = 0; j < buf.nb; j++)
        {
            strcpy(tab[k].matricule, buf.tab[j].matricule);
            tab[k].adr.bloc = i; tab[k].adr.pos = j;
            tab[k].supp = 0;
            k++;
        }
        i = buf.suivant;
    }
    *tai_tab = k;
    Fermer(F);
    qsort(tab, k, sizeof(tenr_index_mat), fctcmp_mat);
    //tri_rapide_grade(tab, k);
}

/****************** creation des fichiers fragments vides ****************/

void frag_init(char *nom_fich1, char *nom_fich2, char *nom_fich3, char *nom_fich4, char *nom_fich5, char *nom_fich6, char *nom_fich7, char *nom_fich8)
{
    fichier f1, f2, f3, f4, f5, f6, f7, f8;

    Ouvrir(&f1, nom_fich1, 'N');
    Ouvrir(&f2, nom_fich2, 'N');
    Ouvrir(&f3, nom_fich3, 'N');
    Ouvrir(&f4, nom_fich4, 'N');
    Ouvrir(&f5, nom_fich5, 'N');
    Ouvrir(&f6, nom_fich6, 'N');
    Ouvrir(&f7, nom_fich7, 'N');
    Ouvrir(&f8, nom_fich8, 'N');

    Aff_entete(&f1, 1, 0); Aff_entete(&f1, 2, 0); Aff_entete(&f1, 4, 0);
    Aff_entete(&f2, 1, 0); Aff_entete(&f2, 2, 0); Aff_entete(&f2, 4, 0);
    Aff_entete(&f3, 1, 0); Aff_entete(&f3, 2, 0); Aff_entete(&f3, 4, 0);
    Aff_entete(&f4, 1, 0); Aff_entete(&f4, 2, 0); Aff_entete(&f4, 4, 0);
    Aff_entete(&f5, 1, 0); Aff_entete(&f5, 2, 0); Aff_entete(&f5, 4, 0);
    Aff_entete(&f6, 1, 0); Aff_entete(&f6, 2, 0); Aff_entete(&f6, 4, 0);
    Aff_entete(&f7, 1, 0); Aff_entete(&f7, 2, 0); Aff_entete(&f7, 4, 0);
    Aff_entete(&f8, 1, 0); Aff_entete(&f8, 2, 0); Aff_entete(&f8, 4, 0);

    Aff_entete(&f1, 3, 0);
    Aff_entete(&f2, 3, 0);
    Aff_entete(&f3, 3, 0);
    Aff_entete(&f4, 3, 0);
    Aff_entete(&f5, 3, 0);
    Aff_entete(&f6, 3, 0);
    Aff_entete(&f7, 3, 0);
    Aff_entete(&f8, 3, 0);

    Fermer(f1);
    Fermer(f2);
    Fermer(f3);
    Fermer(f4);
    Fermer(f5);
    Fermer(f6);
    Fermer(f7);
    Fermer(f8);

}


/******************** fragmentation du fichier selon la region ou la force ************************/

void fragmentation_region(int region, int force,char *nom_fich1, char *nom_fich2, char *nom_fich3, char *nom_fich4, char *nom_fich5, char *nom_fich6, char *nom_fich7, char *nom_fich8)
{
    gtk_label_set_text(GTK_LABEL(lab), "Fragmentation du fichier personnel en cours");



    fichier f, f1, f2, f3, f4, f5, f6, f7, f8;
    tbloc buf, buf1, buf2, buf3, buf4, buf5, buf6, buf7, buf8;
    int i, i1, i2, i3, i4, i5, i6, i7, i8, j, j1, j2, j3, j4, j5, j6, j7, j8;           double prcntg = 0;
    int cpt1, cpt2, cpt3, cpt4, cpt5, cpt6, cpt7, cpt8;

    Ouvrir(&f, F_LnonOF, 'A');
    Ouvrir(&f1, nom_fich1, 'N');
    Ouvrir(&f2, nom_fich2, 'N');
    Ouvrir(&f3, nom_fich3, 'N');
    Ouvrir(&f4, nom_fich4, 'N');
    Ouvrir(&f5, nom_fich5, 'N');
    Ouvrir(&f6, nom_fich6, 'N');
    Ouvrir(&f7, nom_fich7, 'N');
    Ouvrir(&f8, nom_fich8, 'N');

    i = entete(f, 1);
    i1 = i2 = i3 = i4 = i5 = i6 = i7 = i8 = 1;
    j1 = j2 = j3 = j4 = j5 = j6 = j7 = j8 = 0;
    cpt1 = cpt2 = cpt3 = cpt4 = cpt5 = cpt6 = cpt7 = cpt8 = 0;

    Aff_entete(&f1, 1, 0); Aff_entete(&f1, 2, 0); Aff_entete(&f1, 4, 0);
    Aff_entete(&f2, 1, 0); Aff_entete(&f2, 2, 0); Aff_entete(&f2, 4, 0);
    Aff_entete(&f3, 1, 0); Aff_entete(&f3, 2, 0); Aff_entete(&f3, 4, 0);
    Aff_entete(&f4, 1, 0); Aff_entete(&f4, 2, 0); Aff_entete(&f4, 4, 0);
    Aff_entete(&f5, 1, 0); Aff_entete(&f5, 2, 0); Aff_entete(&f5, 4, 0);
    Aff_entete(&f6, 1, 0); Aff_entete(&f6, 2, 0); Aff_entete(&f6, 4, 0);
    Aff_entete(&f7, 1, 0); Aff_entete(&f7, 2, 0); Aff_entete(&f7, 4, 0);
    Aff_entete(&f8, 1, 0); Aff_entete(&f8, 2, 0); Aff_entete(&f8, 4, 0);

    int test = 0;


    while (i != 0)
    {
        LireDir(f, i, &buf); nb_liredir++;
        for(j = 0; j < buf.nb; j++)
        {
            if (region) test = buf.tab[j].region;
            else if (force) test = buf.tab[j].force;
            if (test == 1)
            {

                if(j1 < 82)
                {
                    buf1.tab[j1] = buf.tab[j];
                    j1++;
                }
                else
                {
                    buf1.nb = 82;
                    buf1.precedent = i1-1;
                    buf1.suivant = i1+1;
                    EcrireDir(f1, i1, buf1); nb_ecriredir++;
                    i1++;
                    buf1.tab[0] = buf.tab[j];
                    j1 = 1;
                }
                cpt1++;
            }
            else if (test == 2)
            {
                if(j2 < 82)
                {
                    buf2.tab[j2] = buf.tab[j];
                    j2++;
                }
                else
                {
                    buf2.nb = 82;
                    buf2.precedent = i2-1;
                    buf2.suivant = i2+1;
                    EcrireDir(f2, i2, buf2); nb_ecriredir++;
                    i2++;
                    buf2.tab[0] = buf.tab[j];
                    j2 = 1;
                }
                cpt2++;
            }
            else if(test == 3)
            {
                if(j3 < 82)
                {
                    buf3.tab[j3] = buf.tab[j];
                    j3++;
                }
                else
                {
                    buf3.nb = 82;
                    buf3.precedent = i3-1;
                    buf3.suivant = i3+1;
                    EcrireDir(f3, i3, buf3); nb_ecriredir++;
                    i3++;
                    buf3.tab[0] = buf.tab[j];
                    j3 = 1;
                }
                cpt3++;
            }
            else if (test == 4)
            {
                if(j4 < 82)
                {
                    buf4.tab[j4] = buf.tab[j];
                    j4++;
                }
                else
                {
                    buf4.nb = 82;
                    buf4.precedent = i4-1;
                    buf4.suivant = i4+1;
                    EcrireDir(f4, i4, buf4); nb_ecriredir++;
                    i4++;
                    buf4.tab[0] = buf.tab[j];
                    j4 = 1;
                }
                cpt4++;
            }
            else if(test == 5)
            {
                if(j5 < 82)
                {
                    buf5.tab[j5] = buf.tab[j];
                    j5++;
                }
                else
                {
                    buf5.nb = 82;
                    buf5.precedent = i5-1;
                    buf5.suivant = i5+1;
                    EcrireDir(f5, i5, buf5); nb_ecriredir++;
                    i5++;
                    buf5.tab[0] = buf.tab[j];
                    j5 = 1;
                }
                cpt5++;
            }
            else if(test == 6)
            {
                if(j6 < 82)
                {
                    buf6.tab[j6] = buf.tab[j];
                    j6++;
                }
                else
                {
                    buf6.nb = 82;
                    buf6.precedent = i6-1;
                    buf6.suivant = i6+1;
                    EcrireDir(f6, i6, buf6); nb_ecriredir++;
                    i6++;
                    buf6.tab[0] = buf.tab[j];
                    j6 = 1;
                }
                cpt6++;
            }
            else if ((force) && (test == 7))
            {
                if(j7 < 82)
                {
                    buf7.tab[j7] = buf.tab[j];
                    j7++;
                }
                else
                {
                    buf7.nb = 82;
                    buf7.precedent = i7-1;
                    buf7.suivant = i7+1;
                    EcrireDir(f7, i7, buf7); nb_ecriredir++;
                    i7++;
                    buf7.tab[0] = buf.tab[j];
                    j7 = 1;
                }
                cpt7++;
            }
            else if ((force) && (test == 8))
            {
                if(j8 < 82)
                {
                    buf8.tab[j8] = buf.tab[j];
                    j8++;
                }
                else
                {
                    buf8.nb = 82;
                    buf8.precedent = i8-1;
                    buf8.suivant = i8+1;
                    EcrireDir(f8, i8, buf8); nb_ecriredir++;
                    i8++;
                    buf8.tab[0] = buf.tab[j];
                    j8 = 1;
                }
                cpt8++;
            }

                prcntg++;


                gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress0), (gdouble) (prcntg/entete(f, 3)));

                while (gtk_events_pending()) gtk_main_iteration();
                gtk_widget_show_all(dialog0);


        }
        i = buf.suivant;


    }

    if(cpt1)
    {
        buf1.nb = j1;
        buf1.precedent = i1-1;
        buf1.suivant = 0;
        EcrireDir(f1, i1, buf1); nb_ecriredir++;
        Aff_entete(&f1, 1, 1);
        Aff_entete(&f1, 2, i1);
        Aff_entete(&f1, 4, i1);
    }
    if(cpt2)
    {
        buf2.nb = j2;
        buf2.precedent = i2-1;
        buf2.suivant = 0;
        EcrireDir(f2, i2, buf2); nb_ecriredir++;
        Aff_entete(&f2, 1, 1);
        Aff_entete(&f2, 2, i2);
        Aff_entete(&f2, 4, i2);
    }
    if(cpt3)
    {
        buf3.nb = j3;
        buf3.precedent = i3-1;
        buf3.suivant = 0;
        EcrireDir(f3, i3, buf3); nb_ecriredir++;
        Aff_entete(&f3, 1, 1);
        Aff_entete(&f3, 2, i3);
        Aff_entete(&f3, 4, i3);
    }
    if(cpt4)
    {
        buf4.nb = j4;
        buf4.precedent = i4-1;
        buf4.suivant = 0;
        EcrireDir(f4, i4, buf4); nb_ecriredir++;
        Aff_entete(&f4, 1, 1);
        Aff_entete(&f4, 2, i4);
        Aff_entete(&f4, 4, i4);
    }
    if(cpt5)
    {
        buf5.nb = j5;
        buf5.precedent = i5-1;
        buf5.suivant = 0;
        EcrireDir(f5, i5, buf5); nb_ecriredir++;
        Aff_entete(&f5, 1, 1);
        Aff_entete(&f5, 2, i5);
        Aff_entete(&f5, 4, i5);
    }
    if(cpt6)
    {
        buf6.nb = j6;
        buf6.precedent = i6-1;
        buf6.suivant = 0;
        EcrireDir(f6, i6, buf6); nb_ecriredir++;
        Aff_entete(&f6, 1, 1);
        Aff_entete(&f6, 2, i6);
        Aff_entete(&f6, 4, i6);
    }
    if(cpt7)
    {
        buf7.nb = j7;
        buf7.precedent = i7-1;
        buf7.suivant = 0;
        EcrireDir(f7, i7, buf7); nb_ecriredir++;
        Aff_entete(&f7, 1, 1);
        Aff_entete(&f7, 2, i7);
        Aff_entete(&f7, 4, i7);
    }
    if(cpt8)
    {
        buf8.nb = j8;
        buf8.precedent = i8-1;
        buf8.suivant = 0;
        EcrireDir(f8, i8, buf8); nb_ecriredir++;
        Aff_entete(&f8, 1, 1);
        Aff_entete(&f8, 2, i8);
        Aff_entete(&f8, 4, i8);
    }
    Aff_entete(&f1, 3, cpt1);
    Aff_entete(&f2, 3, cpt2);
    Aff_entete(&f3, 3, cpt3);
    Aff_entete(&f4, 3, cpt4);
    Aff_entete(&f5, 3, cpt5);
    Aff_entete(&f6, 3, cpt6);
    Aff_entete(&f7, 3, cpt7);
    Aff_entete(&f8, 3, cpt8);

    Fermer(f);
    Fermer(f1);
    Fermer(f2);
    Fermer(f3);
    Fermer(f4);
    Fermer(f5);
    Fermer(f6);
    Fermer(f7);
    Fermer(f8);

}

/*********************** affichage des fragments  ***************************/

void affichage_frag(int num_fich)
{

    gtk_container_remove (GTK_CONTAINER(port2),GTK_WIDGET(tabG2[iGTK2]));

    iGTK2++;

    tabG2[iGTK2] = gtk_vbox_new (TRUE,5);


    gtk_container_add(GTK_CONTAINER(port2),GTK_WIDGET(tabG2[iGTK2]));


    fichier F; tbloc buf;

    double cpt = 0;
    char str[256];
    char genre[30];

    char nom[26];
    sprintf(nom, "Fichier%d.bin", num_fich);


    int i = 0, j = 0;


        Ouvrir(&F, nom, 'A');
        if (entete(F, 3) == 0) gtk_label_set_text(GTK_LABEL(label158), "Ce fichier est vide");
        else
        {
            gtk_label_set_text(GTK_LABEL(label158), "Affichage du fichier en cours");
            i = entete(F, 1);
            while(i != 0)
            {
                LireDir(F, i, &buf);
                for (j = 0; j < buf.nb; j++)
                {


                      if ( buf.tab[j].sexe == 1) strcpy(genre, "MASCULIN\n");
                      if ( buf.tab[j].sexe == 2) strcpy(genre, "FEMININ\n");

                      sprintf(str, "\n  %s   %s\n\t%s\n\t%s\t%s\t%d / %d / %d\n\t%s\n\tRegion %d : %s\t%s\t%s", buf.tab[j].nom, buf.tab[j].prenom, buf.tab[j].matricule, genre, tab_wilaya[buf.tab[j].willaya-1],
                                     buf.tab[j].date_de_naissance.jour, buf.tab[j].date_de_naissance.mois, buf.tab[j].date_de_naissance.an,
                                     tab_grp_sang[buf.tab[j].grp_sang-1],buf.tab[j].region, tab_region[buf.tab[j].region-1], tab_force[buf.tab[j].force-1], tab_grade[buf.tab[j].grade-1]);

                      gchar *bio = g_locale_to_utf8 (str, -1, NULL, NULL, NULL);

                      tab[iLAB] = gtk_label_new("Label 1");
                      gtk_misc_set_alignment(tab[iLAB], 0, 0);
                      gtk_label_set_text(GTK_LABEL(tab[iLAB]), bio);

                      context = gtk_widget_get_style_context(GTK_WIDGET(tab[iLAB]));
                      gtk_style_context_add_class(context, "labbox2");


                      gtk_box_pack_start(GTK_BOX(tabG2[iGTK2]),tab[iLAB],0,0,0);
                      iLAB++;

                      cpt++;

                      gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress2), (gdouble)( cpt/entete(F, 3)));
                      while (gtk_events_pending()) gtk_main_iteration();
                      gtk_widget_show_all(window2);
                }
                i = buf.suivant;
            }

        }
        Fermer(F);



}

double Calcprcntg(int x , int total)
{
    return (((double)x)/((double)total))*100;
}



/**************** module des statistique sur le fichier personnel ************/

void Statistiques()
{
    typedef char pr[6];
    pr reg[7];
    pr forc[9];
    pr catgrad[6];
    pr catage[5];

    sprintf(reg[1], "%d", TSTATreg[1]);
    gtk_label_set_text(GTK_LABEL(label89), reg[1]);
    sprintf(reg[1], "%.2lf %%", Calcprcntg(TSTATreg[1], NbEnr));
    gtk_label_set_text(GTK_LABEL(label95), reg[1]);

    sprintf(reg[2], "%d", TSTATreg[2]);
    gtk_label_set_text(GTK_LABEL(label90), reg[2]);
    sprintf(reg[2], "%.2lf %%", Calcprcntg(TSTATreg[2], NbEnr));
    gtk_label_set_text(GTK_LABEL(label96), reg[2]);

    sprintf(reg[3], "%d", TSTATreg[3]);
    gtk_label_set_text(GTK_LABEL(label91), reg[3]);
    sprintf(reg[3], "%.2lf %%", Calcprcntg(TSTATreg[3], NbEnr));
    gtk_label_set_text(GTK_LABEL(label97), reg[3]);

    sprintf(reg[4], "%d", TSTATreg[4]);
    gtk_label_set_text(GTK_LABEL(label92), reg[4]);
    sprintf(reg[4], "%.2lf %%", Calcprcntg(TSTATreg[4], NbEnr));
    gtk_label_set_text(GTK_LABEL(label98), reg[4]);

    sprintf(reg[5], "%d", TSTATreg[5]);
    gtk_label_set_text(GTK_LABEL(label93), reg[5]);
    sprintf(reg[5], "%.2lf %%", Calcprcntg(TSTATreg[5], NbEnr));
    gtk_label_set_text(GTK_LABEL(label99), reg[5]);

    sprintf(reg[6], "%d", TSTATreg[6]);
    gtk_label_set_text(GTK_LABEL(label94), reg[6]);
    sprintf(reg[6], "%.2lf %%", Calcprcntg(TSTATreg[6], NbEnr));
    gtk_label_set_text(GTK_LABEL(label100), reg[6]);

    /*************************************************************/

    sprintf(forc[1], "%d", TSTATforc[1]);
    gtk_label_set_text(GTK_LABEL(label110), forc[1]);
    sprintf(forc[1], "%.2lf %%", Calcprcntg(TSTATforc[1], NbEnr));
    gtk_label_set_text(GTK_LABEL(label116), forc[1]);

    sprintf(forc[2], "%d", TSTATforc[2]);
    gtk_label_set_text(GTK_LABEL(label111), forc[2]);
    sprintf(forc[2], "%.2lf %%", Calcprcntg(TSTATforc[2], NbEnr));
    gtk_label_set_text(GTK_LABEL(label117), forc[2]);

    sprintf(forc[3], "%d", TSTATforc[3]);
    gtk_label_set_text(GTK_LABEL(label112), forc[3]);
    sprintf(forc[3], "%.2lf %%", Calcprcntg(TSTATforc[3], NbEnr));
    gtk_label_set_text(GTK_LABEL(label118), forc[3]);

    sprintf(forc[4], "%d", TSTATforc[4]);
    gtk_label_set_text(GTK_LABEL(label113), forc[4]);
    sprintf(forc[4], "%.2lf %%", Calcprcntg(TSTATforc[4], NbEnr));
    gtk_label_set_text(GTK_LABEL(label119), forc[4]);

    sprintf(forc[5], "%d", TSTATforc[5]);
    gtk_label_set_text(GTK_LABEL(label114), forc[5]);
    sprintf(forc[5], "%.2lf %%", Calcprcntg(TSTATforc[5], NbEnr));
    gtk_label_set_text(GTK_LABEL(label120), forc[5]);

    sprintf(forc[6], "%d", TSTATforc[6]);
    gtk_label_set_text(GTK_LABEL(label115), forc[6]);
    sprintf(forc[6], "%.2lf %%", Calcprcntg(TSTATforc[6], NbEnr));
    gtk_label_set_text(GTK_LABEL(label121), forc[6]);

    sprintf(forc[7], "%d", TSTATforc[7]);
    gtk_label_set_text(GTK_LABEL(label124), forc[7]);
    sprintf(forc[7], "%.2lf %%", Calcprcntg(TSTATforc[7], NbEnr));
    gtk_label_set_text(GTK_LABEL(label126), forc[7]);

    sprintf(forc[8], "%d", TSTATforc[8]);
    gtk_label_set_text(GTK_LABEL(label125), forc[8]);
    sprintf(forc[8], "%.2lf %%", Calcprcntg(TSTATforc[8], NbEnr));
    gtk_label_set_text(GTK_LABEL(label127), forc[8]);


    /*****************************************************************/

    sprintf(catgrad[1], "%d", TSTATcatgrad[1]);
    gtk_label_set_text(GTK_LABEL(label137), catgrad[1]);
    sprintf(catgrad[1], "%.2lf %%", Calcprcntg(TSTATcatgrad[1], NbEnr));
    gtk_label_set_text(GTK_LABEL(label143), catgrad[1]);

    sprintf(catgrad[2], "%d", TSTATcatgrad[2]);
    gtk_label_set_text(GTK_LABEL(label138), catgrad[2]);
    sprintf(catgrad[2], "%.2lf %%", Calcprcntg(TSTATcatgrad[2], NbEnr));
    gtk_label_set_text(GTK_LABEL(label144), catgrad[2]);

    sprintf(catgrad[3], "%d", TSTATcatgrad[3]);
    gtk_label_set_text(GTK_LABEL(label139), catgrad[3]);
    sprintf(catgrad[3], "%.2lf %%", Calcprcntg(TSTATcatgrad[3], NbEnr));
    gtk_label_set_text(GTK_LABEL(label145), catgrad[3]);

    sprintf(catgrad[4], "%d", TSTATcatgrad[4]);
    gtk_label_set_text(GTK_LABEL(label140), catgrad[4]);
    sprintf(catgrad[4], "%.2lf %%", Calcprcntg(TSTATcatgrad[4], NbEnr));
    gtk_label_set_text(GTK_LABEL(label146), catgrad[4]);

    sprintf(catgrad[5], "%d", TSTATcatgrad[5]);
    gtk_label_set_text(GTK_LABEL(label141), catgrad[5]);
    sprintf(catgrad[5], "%.2lf %%", Calcprcntg(TSTATcatgrad[5], NbEnr));
    gtk_label_set_text(GTK_LABEL(label147), catgrad[5]);


    /*******************************************************************/

    sprintf(catage[1], "%d", TSTATcatage[1]);
    gtk_label_set_text(GTK_LABEL(label154), catage[1]);
    sprintf(catage[1], "%.2lf %%", Calcprcntg(TSTATcatage[1], NbEnr));
    gtk_label_set_text(GTK_LABEL(label159), catage[1]);

    sprintf(catage[2], "%d", TSTATcatage[2]);
    gtk_label_set_text(GTK_LABEL(label155), catage[2]);
    sprintf(catage[2], "%.2lf %%", Calcprcntg(TSTATcatage[2], NbEnr));
    gtk_label_set_text(GTK_LABEL(label160), catage[2]);

    sprintf(catage[3], "%d", TSTATcatage[3]);
    gtk_label_set_text(GTK_LABEL(label156), catage[3]);
    sprintf(catage[3], "%.2lf %%", Calcprcntg(TSTATcatage[3], NbEnr));
    gtk_label_set_text(GTK_LABEL(label161), catage[3]);

    sprintf(catage[4], "%d", TSTATcatage[4]);
    gtk_label_set_text(GTK_LABEL(label157), catage[4]);
    sprintf(catage[4], "%.2lf %%", Calcprcntg(TSTATcatage[4], NbEnr));
    gtk_label_set_text(GTK_LABEL(label162), catage[4]);


}


int Determin_cat_grad(int grade)
{
        if ((grade >= 1) && (grade <= 4)) return 1;
        else if ((grade >= 5) && (grade <= 7)) return 2;
        else if ((grade >= 8) && (grade <= 11)) return 3;
        else if ((grade >= 12) && (grade <= 15)) return 4;
        else if ((grade >= 16) && (grade <= 18)) return 5;
}

int Determin_cat_age(int age)
{
        if (age <30) return 1;
        if ((age >=30) && (age<50)) return 2;
        if ((age >=50) && (age<70)) return 3;
        if (age >=70) return 4;
}

