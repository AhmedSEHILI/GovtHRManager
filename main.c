
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Headers.h"
#include "info.c"
#include "Implem_L_nonO_F.c"
#include "Implem_LLC.c"
#include <string.h>
#include "conio2.h"
#include "conio.c"
#include "gtk\gtk.h"
#include "Modules_L_nonO_F.c"


/********************* Cette page contient le main (programme pricipale) et les connexions des signals des boutons
                       untilisé par GTK avec les différente fonctionnalité du TP *************************************/

/**************** les déclarations des widget de la fenetre A propos *************/
GtkWidget *propo;
GtkWidget *propo_fixed;
GtkWidget *imgaide1;
GtkWidget *scrl1;
GtkWidget *view1;
GtkWidget *vb1;
GtkWidget *gr1;
GtkWidget *gr1_label1;
GtkWidget *gr1_label2;
GtkWidget *gr1_label3;
GtkWidget *titre;
GtkWidget *text;
GtkWidget *num_bloc1;
GtkWidget *error_label;
GtkWidget *propo_button1;
GtkWidget *propo_button2;
GtkWidget *propo_button3;
GtkWidget *exp1;
GtkWidget *exp1_label1;
GtkWidget *exp1_label2;
GtkWidget *exp2;
GtkWidget *exp2_label1;
GtkWidget *exp2_label2;


/*********************************************/


/**************** les confirmations des différentes operations des modules du TP ***********/

void Dest_dialog1(GtkWidget *widget, gpointer data)
{
    gtk_widget_destroy(dialog1);
}


void Confirm_supp(GtkWidget *widget, gpointer data)
{
    NbEnr --;
    supp_enr_LnonOF(mat);
    Statistiques();
    save(t_vide_actif, Lb_vide);
    save(t_vide_archive, Lb_vide_arch);


    gtk_widget_destroy(dialog1);

    gtk_label_set_text(GTK_LABEL(label22), "Enregistrement supprime avec succes");

}


void Confirm_modif(GtkWidget *widget, gpointer data)
{
    Modifier_rg_forc_grad(matM, nouvelle_region, nouvelle_force, nouveau_grade);

    Statistiques();

    gtk_widget_destroy(dialog1);

    gtk_label_set_text(GTK_LABEL(label57), "Modifications effectuees avec succees");
}


void Confirm_supp_evol(GtkWidget *widget, gpointer data)
{

    dialog0 = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
    gtk_window_set_default_size(GTK_WINDOW(dialog0), 490, 300);

    lab = GTK_WIDGET(gtk_builder_get_object(builder, "label"));
    progress0 = GTK_WIDGET(gtk_builder_get_object(builder, "progress"));
    gtk_window_set_position(GTK_WINDOW(dialog0),GTK_WIN_POS_CENTER);

    double Gcpt = Count_requete(F_LnonOF, infos[0], infos[1], infos[2], infos[3], infos[4], infos[5], infos[6], infos[7], infos[7]);

    suppression_generale(infos[0], infos[1], infos[2], infos[3], infos[4], infos[5], infos[6], infos[7], Gcpt);

    Statistiques();

    fichier F;

    save(t_vide_actif, Lb_vide);
    save(t_vide_archive, Lb_vide_arch);


    gtk_widget_show_all(dialog0);
    gtk_widget_destroy(dialog0);


    gtk_widget_destroy(dialog1);

    if (!Gcpt) gtk_label_set_text(GTK_LABEL(label79), "Aucun enregistement trouve ");
    else gtk_label_set_text(GTK_LABEL(label79), "Suppressions effectuees avec succees");
}


void Confirm_fragmentation(GtkWidget *widget, gpointer data)
{

    dialog0 = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
    gtk_window_set_default_size(GTK_WINDOW(dialog0), 490, 300);

    lab = GTK_WIDGET(gtk_builder_get_object(builder, "label"));
    progress0 = GTK_WIDGET(gtk_builder_get_object(builder, "progress"));
    gtk_window_set_position(GTK_WINDOW(dialog0),GTK_WIN_POS_CENTER);

    if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radio3))) fragmentation_region(1,0,"Fichier1.bin", "Fichier2.bin", "Fichier3.bin", "Fichier4.bin",
                                                                                     "Fichier5.bin", "Fichier6.bin", "Fichier7.bin", "Fichier8.bin");

    if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radio4))) fragmentation_region(0,1,"Fichier1.bin", "Fichier2.bin", "Fichier3.bin", "Fichier4.bin",
                                                                                     "Fichier5.bin", "Fichier6.bin", "Fichier7.bin", "Fichier8.bin");

    gtk_label_set_text(GTK_LABEL(label73), "Fragmentation du fichier personnel terminee");

    gtk_widget_show_all(dialog0);
    gtk_widget_destroy(dialog0);


    gtk_widget_destroy(dialog1);



}

/*****************************************************************/
/*****************************************************************/

/***************** affichage des fragments resultants du module fragmentation ******************/


void Affichier_fragment(GtkWidget *widget, gpointer data)
{

    gtk_label_set_text(GTK_LABEL(label158), "");


    if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radio5))) affichage_frag(1);
    if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radio6))) affichage_frag(2);
    if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radio7))) affichage_frag(3);
    if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radio8))) affichage_frag(4);
    if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radio9))) affichage_frag(5);
    if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radio10))) affichage_frag(6);
    if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radio11))) affichage_frag(7);
    if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radio12))) affichage_frag(8);





}


/****************************** preparation d'onglet de fragmentation dans l'interface ****************************/

void Fragmentation(GtkWidget *widget, gpointer data)
{
        gtk_label_set_text(GTK_LABEL(label73), "");
        gtk_label_set_text(GTK_LABEL(label158), "");

        builder = gtk_builder_new_from_file("project.glade");
        dialog1 = GTK_WIDGET(gtk_builder_get_object(builder, "dialog1"));
        gtk_window_set_position(GTK_WINDOW(dialog1),GTK_WIN_POS_CENTER);

        labdialog = GTK_WIDGET(gtk_builder_get_object(builder, "labdialog"));
        b0 = GTK_WIDGET(gtk_builder_get_object(builder, "b0"));
        annuler = GTK_WIDGET(gtk_builder_get_object(builder, "annuler"));
        oui = GTK_WIDGET(gtk_builder_get_object(builder, "oui"));

        gtk_label_set_text(GTK_LABEL(labdialog), "Voulez vous vraiment effectuer cette Fragmentation ?");


        g_signal_connect(annuler, "clicked", G_CALLBACK(Dest_dialog1), NULL);

        g_signal_connect(oui, "clicked", G_CALLBACK(Confirm_fragmentation), NULL);


        gtk_widget_show_all(dialog1);




}


/****************************** preparation d'onglet de la Supprission_Evoluee dans l'interface ****************************/


void Supprission_Evoluee(GtkWidget *widget, gpointer data)
{

    gtk_label_set_text(GTK_LABEL(label79), "");

    char tmp[28];

    char t[3];

    int age_min, age_max;
    int grad_min, grad_max;

    char sx[28];    int sexe;
    char wil[35];   int wilaya;
    char gr[28];    int grp_sang;
    char reg[28];   int region;
    char forc[28];  int force;
    char grad[28];  int grade;




    int problem = 0;


    strcpy(sx, gtk_entry_get_text(GTK_ENTRY(ent21)));
    strcpy(wil, gtk_entry_get_text(GTK_ENTRY(ent27)));
    strcpy(gr, gtk_entry_get_text(GTK_ENTRY(ent23)));
    strcpy(reg, gtk_entry_get_text(GTK_ENTRY(ent24)));
    strcpy(forc, gtk_entry_get_text(GTK_ENTRY(ent25)));
    strcpy(grad, gtk_entry_get_text(GTK_ENTRY(ent26)));


    age_min = (int)gtk_spin_button_get_value(GTK_SPIN_BUTTON(spin6));
    age_max = (int)gtk_spin_button_get_value(GTK_SPIN_BUTTON(spin7));





        if (!strcmp(reg, "vide"))
        {
            region = -1;
        }
        else
        {
            t[0] = reg[0];
            t[1] = reg[1];
            region = atoi(t);
        }

        if (!strcmp(forc, "vide"))
        {
            force = -1;
        }
        else
        {
            t[0] = forc[0];
            t[1] = forc[1];
            force = atoi(t);
        }

        if (!strcmp(grad, "vide"))
        {
            grade = -1;
        }
        else
        {
            t[0] = grad[0];
            t[1] = grad[1];
            grade = atoi(t);
        }

        if (!strcmp(wil, "vide"))
        {
            wilaya = -1;
        }
        else
        {
            t[0] = wil[0];
            t[1] = wil[1];
            wilaya = atoi(t);
        }

        if (!strcmp(gr, "vide"))
        {
            grp_sang = -1;
        }
        else
        {
            t[0] = gr[0];
            t[1] = gr[1];
            grp_sang = atoi(t);
        }

        if (!strcmp(sx, "vide"))
        {
            sexe = -1;
        }
        else
        {
            t[0] = sx[0];
            t[1] = sx[1];
            sexe = atoi(t);
        }


        infos[0] = age_min;
        infos[1] = age_max;
        infos[2] = sexe;
        infos[3] = wilaya;
        infos[4] = grp_sang;
        infos[5] = region;
        infos[6] = force;
        infos[7] = grade;



        builder = gtk_builder_new_from_file("project.glade");
        dialog1 = GTK_WIDGET(gtk_builder_get_object(builder, "dialog1"));
        gtk_window_set_position(GTK_WINDOW(dialog1),GTK_WIN_POS_CENTER);

        labdialog = GTK_WIDGET(gtk_builder_get_object(builder, "labdialog"));
        b0 = GTK_WIDGET(gtk_builder_get_object(builder, "b0"));
        annuler = GTK_WIDGET(gtk_builder_get_object(builder, "annuler"));
        oui = GTK_WIDGET(gtk_builder_get_object(builder, "oui"));

        gtk_label_set_text(GTK_LABEL(labdialog), "Voulez vous vraiment effectuer cette suppression ?");


        g_signal_connect(annuler, "clicked", G_CALLBACK(Dest_dialog1), NULL);

        g_signal_connect(oui, "clicked", G_CALLBACK(Confirm_supp_evol), NULL);


        gtk_widget_show_all(dialog1);



}


/****************************** preparation d'onglet de la requete dans l'interface ****************************/


void Requete(GtkWidget *widget, gpointer data)
{
    char *F;
    gtk_label_set_text(GTK_LABEL(label151), "");

    char tmp[28];

    int age_min, age_max;    char t[3];
    int grad_min, grad_max;

    char sx[28];    int sexe;
    char wil[35];   int wilaya;
    char gr[28];    int grp_sang;
    char reg[28];   int region;
    char forc[28];  int force;
    char grad[28];  int grade;


    int problem = 0;


    strcpy(sx, gtk_entry_get_text(GTK_ENTRY(ent15)));
    strcpy(wil, gtk_entry_get_text(GTK_ENTRY(ent20)));
    strcpy(gr, gtk_entry_get_text(GTK_ENTRY(ent16)));
    strcpy(reg, gtk_entry_get_text(GTK_ENTRY(ent17)));
    strcpy(forc, gtk_entry_get_text(GTK_ENTRY(ent18)));
    strcpy(grad, gtk_entry_get_text(GTK_ENTRY(ent19)));


    age_min = (int)gtk_spin_button_get_value(GTK_SPIN_BUTTON(spin5));
    age_max = (int)gtk_spin_button_get_value(GTK_SPIN_BUTTON(spin4));





        if (!strcmp(reg, "vide"))
        {
            region = -1;
        }
        else
        {
            t[0] = reg[0];
            t[1] = reg[1];
            region = atoi(t);
        }

        if (!strcmp(forc, "vide"))
        {
            force = -1;
        }
        else
        {
            t[0] = forc[0];
            t[1] = forc[1];
            force = atoi(t);
        }

        if (!strcmp(grad, "vide"))
        {
            grade = -1;
        }
        else
        {
            t[0] = grad[0];
            t[1] = grad[1];
            grade = atoi(t);
        }

        if (!strcmp(wil, "vide"))
        {
            wilaya = -1;
        }
        else
        {
            t[0] = wil[0];
            t[1] = wil[1];
            wilaya = atoi(t);
        }

        if (!strcmp(gr, "vide"))
        {
            grp_sang = -1;
        }
        else
        {
            t[0] = gr[0];
            t[1] = gr[1];
            grp_sang = atoi(t);
        }

        if (!strcmp(sx, "vide"))
        {
            sexe = -1;
        }
        else
        {
            t[0] = sx[0];
            t[1] = sx[1];
            sexe = atoi(t);
        }

        if (grade == -1) grad_min = -1;
        else if (grade == 1) {grad_min = 1 ; grad_max = 4;}
        else if (grade == 2) {grad_min = 5 ; grad_max = 7;}
        else if (grade == 3) {grad_min = 8 ; grad_max = 11;}
        else if (grade == 4) {grad_min = 12 ; grad_max = 15;}
        else if (grade == 5) {grad_min = 16 ; grad_max = 18;}


        if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radio1))) F = F_LnonOF;
        if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radio2))) F = F_arch;

        double Gcpt = Count_requete(F, age_min, age_max, sexe, wilaya, grp_sang, region, force, grad_min, grad_max);

        Requete_General(F, age_min, age_max, sexe, wilaya, grp_sang, region, force, grad_min, grad_max, Gcpt);


}










/****************************** preparation d'onglet de la modification dans l'interface ****************************/






void Modifier(GtkWidget *widget, gpointer data)
{

    fichier F; tbloc buf;
    fichier_index F_mat; tbloc_index_mat buf_m;


    gtk_label_set_text(GTK_LABEL(label54), "");
    gtk_label_set_text(GTK_LABEL(label55), "");
    gtk_label_set_text(GTK_LABEL(label56), "");
    gtk_label_set_text(GTK_LABEL(label57), "");
    gtk_label_set_text(GTK_LABEL(label58), "");

    char reg[26];
    char forc[60];
    char grad[26];   char t[3];




    int problem = 0;  int i, j, trouv;

    gtk_entry_set_max_length (GTK_ENTRY(ent11), 6);

    strcpy(matM, gtk_entry_get_text(GTK_ENTRY(ent11)));

    strcpy(grad, gtk_entry_get_text(GTK_ENTRY(ent14)));

    strcpy(reg, gtk_entry_get_text(GTK_ENTRY(ent12)));
    strcpy(forc, gtk_entry_get_text(GTK_ENTRY(ent13)));

        if (!strcmp(reg, "vide"))
        {
            nouvelle_region = -1;
        }
        else
        {
            t[0] = reg[0];
            t[1] = reg[1];
            nouvelle_region = atoi(t);
        }

        if (!strcmp(forc, "vide"))
        {
            nouvelle_force = -1;
        }
        else
        {
            t[0] = forc[0];
            t[1] = forc[1];
            nouvelle_force = atoi(t);
        }

        if (!strcmp(grad, "vide"))
        {
            nouveau_grade = -1;
        }
        else
        {
            t[0] = grad[0];
            t[1] = grad[1];
            nouveau_grade = atoi(t);
        }



    Ouvrir(&F, F_LnonOF, 'A');
    Ouvrir_index(&F_mat, F_indx_mat, 'A');


    if (!digits_only(matM))
    {
        gtk_label_set_text(GTK_LABEL(label58), "Le matricule ne doit contenir que des chiffres");
        problem = 1;
    }


    else if ((strlen(matM)<6) &&(strlen(matM)>0))
    {
        gtk_label_set_text(GTK_LABEL(label58), "Le matricule dois contenir 6 chiffres ");
        problem = 1;
    }


    else if (strlen(matM)==0)
    {
        gtk_label_set_text(GTK_LABEL(label58), "Champ manquant ");
        problem = 1;
    }
    else
    {
        rech_optimisee_mat(matM, F_indx_mat , index_NONdense, taille_non_dense, &trouv, &i, &j);
        LireDir_index_mat(F_mat, i, &buf_m);
        LireDir(F, buf_m.tab[j].adr.bloc, &buf);
        if (! trouv)
        {
            gtk_label_set_text(GTK_LABEL(label58), "Cet enregistrement n'existe pas");
            problem = 1;
        }
        else
        {
            gtk_label_set_text(GTK_LABEL(label58), "");



            if (buf.tab[buf_m.tab[j].adr.pos].region == nouvelle_region)
            {
                gtk_label_set_text(GTK_LABEL(label54), "Meme region");
                problem = 1;
            }
            else
            {
                gtk_label_set_text(GTK_LABEL(label54), "");
            }

            if (buf.tab[buf_m.tab[j].adr.pos].force == nouvelle_force)
            {
                gtk_label_set_text(GTK_LABEL(label55), "Meme force");
                problem = 1;
            }
            else
            {
                gtk_label_set_text(GTK_LABEL(label55), "");
            }
            if (buf.tab[buf_m.tab[j].adr.pos].grade == nouveau_grade)
            {
                gtk_label_set_text(GTK_LABEL(label56), "Meme grade");
                problem = 1;
            }
            else
            {
                gtk_label_set_text(GTK_LABEL(label56), "");
            }


            if ((!strcmp(reg, "vide")) && (!strcmp(forc,"vide")) && (!strcmp(grad,"vide")))
            {
                gtk_label_set_text(GTK_LABEL(label57), "Veuillez effectuer au mois un\nchangement avant de valider");
                problem = 1;
            }
            else
            {
                gtk_label_set_text(GTK_LABEL(label57), "");
            }

        }
    }

    Fermer(F);
    Fermer_index(F_mat);

    if (!problem)
    {


        MODIFi = i;
        MODIFj = j;

        builder = gtk_builder_new_from_file("project.glade");
        dialog1 = GTK_WIDGET(gtk_builder_get_object(builder, "dialog1"));
        gtk_window_set_position(GTK_WINDOW(dialog1),GTK_WIN_POS_CENTER);

        labdialog = GTK_WIDGET(gtk_builder_get_object(builder, "labdialog"));
        b0 = GTK_WIDGET(gtk_builder_get_object(builder, "b0"));
        annuler = GTK_WIDGET(gtk_builder_get_object(builder, "annuler"));
        oui = GTK_WIDGET(gtk_builder_get_object(builder, "oui"));

        gtk_label_set_text(GTK_LABEL(labdialog), "Voulez vous vraiment effectuer ces modification ?");


        g_signal_connect(annuler, "clicked", G_CALLBACK(Dest_dialog1), NULL);

        g_signal_connect(oui, "clicked", G_CALLBACK(Confirm_modif), NULL);


        gtk_widget_show_all(dialog1);



    }





}


/****************************** preparation d'onglet de la recherche dans l'interface ****************************/


void Rechercher(GtkWidget *widget, gpointer data)
{

        gtk_label_set_text(GTK_LABEL(label26), "");
        gtk_label_set_text(GTK_LABEL(label27), "");
        gtk_label_set_text(GTK_LABEL(label28), "");
        gtk_label_set_text(GTK_LABEL(label29), "");
        gtk_label_set_text(GTK_LABEL(label30), "");
        gtk_label_set_text(GTK_LABEL(label31), "");
        gtk_label_set_text(GTK_LABEL(label32), "");
        gtk_label_set_text(GTK_LABEL(label33), "");
        gtk_label_set_text(GTK_LABEL(label34), "");
        gtk_label_set_text(GTK_LABEL(label46), "");



        gtk_label_set_text(GTK_LABEL(label35), "");
        gtk_label_set_text(GTK_LABEL(label36), "");
        gtk_label_set_text(GTK_LABEL(label37), "");
        gtk_label_set_text(GTK_LABEL(label38), "");
        gtk_label_set_text(GTK_LABEL(label39), "");
        gtk_label_set_text(GTK_LABEL(label40), "");
        gtk_label_set_text(GTK_LABEL(label41), "");
        gtk_label_set_text(GTK_LABEL(label42), "");
        gtk_label_set_text(GTK_LABEL(label43), "");
        gtk_label_set_text(GTK_LABEL(label47), "");


    fichier F; tbloc buf;
    fichier_index F_indx; tbloc_index_mat buf_m;

    char date_n[12];




    int problem = 0;  int i, j, trouv;

    gtk_entry_set_max_length (GTK_ENTRY(ent10), 6);

    strcpy(matR, gtk_entry_get_text(GTK_ENTRY(ent10)));


    if (!digits_only(matR))
    {
        gtk_label_set_text(GTK_LABEL(label25), "Le matricule ne doit contenir que des chiffres");
        problem = 1;
    }


    else if ((strlen(matR)<6) &&(strlen(matR)>0))
    {
        gtk_label_set_text(GTK_LABEL(label25), "Le matricule dois contenir 6 chiffres ");
        problem = 1;
    }


    else if (strlen(matR)==0)
    {
        gtk_label_set_text(GTK_LABEL(label25), "Champ manquant ");
        problem = 1;
    }
    else
    {
        rech_optimisee_mat(matR, F_indx_mat , index_NONdense, taille_non_dense, &trouv, &i, &j);
        if (! trouv)
        {
            gtk_label_set_text(GTK_LABEL(label25), "Cet enregistrement n'existe pas");
            problem = 1;
        }
        else gtk_label_set_text(GTK_LABEL(label25), "");
    }

    if (!problem)
    {
        builder = gtk_builder_new_from_file("project.glade");

        gtk_label_set_text(GTK_LABEL(label26), "MATRICULE");
        gtk_label_set_text(GTK_LABEL(label27), "NOM");
        gtk_label_set_text(GTK_LABEL(label28), "PRENOM");
        gtk_label_set_text(GTK_LABEL(label29), "SEXE");
        gtk_label_set_text(GTK_LABEL(label30), "DATE DE NAISSANCE");
        gtk_label_set_text(GTK_LABEL(label31), "WILLAYA");
        gtk_label_set_text(GTK_LABEL(label32), "GROUPE SANGUIN");
        gtk_label_set_text(GTK_LABEL(label33), "REGION");
        gtk_label_set_text(GTK_LABEL(label34), "FORCE");
        gtk_label_set_text(GTK_LABEL(label46), "GRADE");



        Ouvrir_index(&F_indx, F_indx_mat, 'A');
        LireDir_index_mat(F_indx, i, &buf_m);
        Fermer_index(F_indx);

        Ouvrir(&F, F_LnonOF, 'A');
        LireDir(F, buf_m.tab[j].adr.bloc, &buf);


        sprintf(date_n, "%d/%d/%d", buf.tab[buf_m.tab[j].adr.pos].date_de_naissance.jour, buf.tab[buf_m.tab[j].adr.pos].date_de_naissance.mois, buf.tab[buf_m.tab[j].adr.pos].date_de_naissance.an);

        gtk_label_set_text(GTK_LABEL(label35), buf.tab[buf_m.tab[j].adr.pos].matricule);
        gtk_label_set_text(GTK_LABEL(label36), buf.tab[buf_m.tab[j].adr.pos].nom);
        gtk_label_set_text(GTK_LABEL(label37), buf.tab[buf_m.tab[j].adr.pos].prenom);
        gtk_label_set_text(GTK_LABEL(label39), date_n);

        gchar *w = g_locale_to_utf8 (tab_wilaya[buf.tab[buf_m.tab[j].adr.pos].willaya - 1], -1, NULL, NULL, NULL);

        gtk_label_set_text(GTK_LABEL(label40), w);
        gtk_label_set_text(GTK_LABEL(label41), tab_grp_sang[buf.tab[buf_m.tab[j].adr.pos].grp_sang -1]);

        gchar *r = g_locale_to_utf8 (tab_region[buf.tab[buf_m.tab[j].adr.pos].region -1], -1, NULL, NULL, NULL);

        gtk_label_set_text(GTK_LABEL(label42), r);

        gchar *f = g_locale_to_utf8 (tab_force[buf.tab[buf_m.tab[j].adr.pos].force -1], -1, NULL, NULL, NULL);

        gtk_label_set_text(GTK_LABEL(label43), f);

        gchar *g = g_locale_to_utf8 (tab_grade[buf.tab[buf_m.tab[j].adr.pos].grade -1], -1, NULL, NULL, NULL);

        gtk_label_set_text(GTK_LABEL(label47), g);
        if (buf.tab[buf_m.tab[j].adr.pos].sexe == 1) gtk_label_set_text(GTK_LABEL(label38), "MASCULIN");
        else gtk_label_set_text(GTK_LABEL(label38), "FEMININ");

        Fermer(F);

    }


}


/****************************** preparation d'onglet de la suppression dans l'interface ****************************/



void Supprimer(GtkWidget *widget, gpointer data)
{
    int problem = 0;  int i, j, trouv;

    gtk_entry_set_max_length (GTK_ENTRY(ent9), 6);

    strcpy(mat, gtk_entry_get_text(GTK_ENTRY(ent9)));

    if (!digits_only(mat))
    {
        gtk_label_set_text(GTK_LABEL(label22), "Le matricule ne doit contenir que des chiffres");
        problem = 1;
    }


    else if ((strlen(mat)<6) &&(strlen(mat)>0))
    {
        gtk_label_set_text(GTK_LABEL(label22), "Le matricule dois contenir 6 chiffres ");
        problem = 1;
    }


    else if (strlen(mat)==0)
    {
        gtk_label_set_text(GTK_LABEL(label22), "Champ manquant ");
        problem = 1;
    }
    else
    {
        rech_optimisee_mat(mat, F_indx_mat , index_NONdense, taille_non_dense, &trouv, &i, &j);
        if (! trouv)
        {
            gtk_label_set_text(GTK_LABEL(label22), "Cet enregistrement n'existe pas");
            problem = 1;
        }
        else gtk_label_set_text(GTK_LABEL(label22), "");
    }

    if (!problem)
    {
        SUPi = i; SUPj = j;
        builder = gtk_builder_new_from_file("project.glade");
        dialog1 = GTK_WIDGET(gtk_builder_get_object(builder, "dialog1"));
        gtk_window_set_position(GTK_WINDOW(dialog1),GTK_WIN_POS_CENTER);

        labdialog = GTK_WIDGET(gtk_builder_get_object(builder, "labdialog"));
        b0 = GTK_WIDGET(gtk_builder_get_object(builder, "b0"));
        annuler = GTK_WIDGET(gtk_builder_get_object(builder, "annuler"));
        oui = GTK_WIDGET(gtk_builder_get_object(builder, "oui"));

        gtk_label_set_text(GTK_LABEL(labdialog), "Voulez vous vraiment supprimer cet enregistrement");


        g_signal_connect(annuler, "clicked", G_CALLBACK(Dest_dialog1), NULL);

        g_signal_connect(oui, "clicked", G_CALLBACK(Confirm_supp), NULL);


        gtk_widget_show_all(dialog1);
    }



}

/******************************************************************/
/******************************************************************/
/******************************************************************/

/********** cette fonction test si une chaine de caracteres contient des chiffres ***************/

int checkString(char str1[])
{
    int i, x=0, p;
    p=strlen(str1);
    for (i = 0; i < p ; i++)
    {
        if ((str1[i] >= 'a' && str1[i] <= 'z') || (str1[i] >= 'A' && str1[i] <= 'Z') || (str1[i] == ' '))
        {
            continue;
        }
        else{ return 0; }
    }
    return 1;
}


/********** cette fonction test si une chaine de caracteres contient que des chiffres ***************/

int digits_only(const char *s)
{
    while (*s) {
        if (isdigit(*s++) == 0) return 0;
    }

    return 1;
}

/********** cette fonction test si une date donnée est valide ***************/

int valid_Date(int jour, int mois, int an)
{
    if ((an%4 == 0 ) && (mois == 2) && (jour>29)) return 0;
    else if ((an%4 != 0 ) && (mois == 2) && (jour>28)) return 0;
    else if ((mois<=7) && ( mois%2 == 0) && (jour>30)) return 0;
    else if  ((mois>=8) && ( mois%2 == 1) && (jour>30)) return 0;
    else return 1;
}


/**************** cette fonction prépare l'onglet d'insertion dans l'interface *******************/

void Ajouter(GtkWidget *widget, gpointer data)
{


    char mat[7];
    char nm[28];
    char pm[28];        char tmp[28];

    char sx[28];

    int jour;
    int mois;
    int an;        char t[3];

    char wil[35];

    char gr[10];
    char reg[28];
    char forc[28];
    char grad[28];

    int problem = 0;      tenr e;

    gtk_entry_set_max_length (GTK_ENTRY(ent1), 6);

    gtk_entry_set_max_length (ent2, 26);

    gtk_entry_set_max_length (ent3, 26);

    strcpy(mat, gtk_entry_get_text(GTK_ENTRY(ent1)));
    strcpy(nm, gtk_entry_get_text(GTK_ENTRY(ent2)));
    strcpy(pm, gtk_entry_get_text(GTK_ENTRY(ent3)));

    strcpy(sx, gtk_entry_get_text(GTK_ENTRY(ent4)));

    jour = (int)gtk_spin_button_get_value(GTK_SPIN_BUTTON(spin1));
    an = (int)gtk_spin_button_get_value(GTK_SPIN_BUTTON(spin2));
    mois = (int)gtk_spin_button_get_value(GTK_SPIN_BUTTON(spin3));

    strcpy(grad, gtk_entry_get_text(GTK_ENTRY(ent8)));

    strcpy(wil, gtk_entry_get_text(GTK_ENTRY(ent66)));
    strcpy(gr, gtk_entry_get_text(GTK_ENTRY(ent5)));
    strcpy(reg, gtk_entry_get_text(GTK_ENTRY(ent6)));
    strcpy(forc, gtk_entry_get_text(GTK_ENTRY(ent7)));



    if (!digits_only(mat))
    {
        gtk_label_set_text(GTK_LABEL(label10), "Le matricule ne doit contenir que des chiffres");
        gtk_label_set_text(GTK_LABEL(label19), "Echec");
        problem = 1;
    }


    else if ((strlen(mat)<6) &&(strlen(mat)>0))
    {
        gtk_label_set_text(GTK_LABEL(label10), "Le matricule dois contenir 6 chiffres ");
        gtk_label_set_text(GTK_LABEL(label19), "Echec");
        problem = 1;
    }


    else if (strlen(mat)==0)
    {
        gtk_label_set_text(GTK_LABEL(label10), "Champ manquant ");
        gtk_label_set_text(GTK_LABEL(label19), "Echec");
        problem = 1;
    }
    else
    {
        gtk_label_set_text(GTK_LABEL(label10), "");
    }


    if (!checkString(nm))
    {
        gtk_label_set_text(GTK_LABEL(label18), "Le nom ne dois centenir que des lettres");
        gtk_label_set_text(GTK_LABEL(label19), "Echec");
        problem = 1;
    }


    else if (strlen(nm)==0 )
    {

        gtk_label_set_text(GTK_LABEL(label18), "Champ manquant ");
        gtk_label_set_text(GTK_LABEL(label19), "Echec");
        problem = 1;
    }
    else
    {
        gtk_label_set_text(GTK_LABEL(label18), "");
    }


    if (!checkString(pm))
    {
        gtk_label_set_text(GTK_LABEL(label11), "Le nom ne dois centenir que des lettres");
        gtk_label_set_text(GTK_LABEL(label19), "Echec");
        problem = 1;
    }


    else if (strlen(pm)==0 )
    {

        gtk_label_set_text(GTK_LABEL(label11), "Champ manquant ");
        gtk_label_set_text(GTK_LABEL(label19), "Echec");
        problem = 1;
    }
    else
    {
        gtk_label_set_text(GTK_LABEL(label11), "");
    }

    if (!valid_Date(jour, mois, an))
    {
        gtk_label_set_text(GTK_LABEL(label13), "Date invalide");
        gtk_label_set_text(GTK_LABEL(label19), "Echec");
        problem = 1;
    }
    else
    {
        gtk_label_set_text(GTK_LABEL(label13), "");
    }

    if (!strcmp(wil, "vide"))
    {
        gtk_label_set_text(GTK_LABEL(label45), "Champ manquant ");
        gtk_label_set_text(GTK_LABEL(label19), "Echec");
        problem = 1;
    }
    else  gtk_label_set_text(GTK_LABEL(label45), "");

    if (!strcmp(gr, "vide"))
    {
        gtk_label_set_text(GTK_LABEL(label14), "Champ manquant ");
        gtk_label_set_text(GTK_LABEL(label19), "Echec");
        problem = 1;
    }
    else  gtk_label_set_text(GTK_LABEL(label14), "");

    if (!strcmp(reg, "vide"))
    {
        gtk_label_set_text(GTK_LABEL(label15), "Champ manquant ");
        gtk_label_set_text(GTK_LABEL(label19), "Echec");
        problem = 1;
    }
    else  gtk_label_set_text(GTK_LABEL(label15), "");

    if (!strcmp(forc, "vide"))
    {
        gtk_label_set_text(GTK_LABEL(label16), "Champ manquant ");
        gtk_label_set_text(GTK_LABEL(label19), "Echec");
        problem = 1;
    }
    else  gtk_label_set_text(GTK_LABEL(label16), "");

    if (!strcmp(grad, "vide"))
    {
        gtk_label_set_text(GTK_LABEL(label17), "Champ manquant ");
        gtk_label_set_text(GTK_LABEL(label19), "Echec");
        problem = 1;
    }
    else  gtk_label_set_text(GTK_LABEL(label17), "");

    if (!strcmp(sx, "vide"))
    {
        gtk_label_set_text(GTK_LABEL(label12), "Champ manquant ");
        gtk_label_set_text(GTK_LABEL(label19), "Echec");
        problem = 1;
    }
    else  gtk_label_set_text(GTK_LABEL(label12), "");


    if (!problem)
    {

        gtk_label_set_text(GTK_LABEL(label19), "");
        strcpy(e.matricule , mat);
        strcpy(e.nom , strupr(nm));
        strcpy(tmp , strlwr(pm));
        tmp[0] = (char)(tmp[0]-32);
        strcpy(e.prenom , tmp);

        e.date_de_naissance.jour = jour;
        e.date_de_naissance.mois = mois;
        e.date_de_naissance.an = an;

        t[0] = wil[0];
        t[1] = wil[1];
        e.willaya = atoi(t);

        t[0] = gr[0];
        t[1] = gr[1];
        e.grp_sang = atoi(t);

        t[0] = sx[0];
        t[1] = sx[1];
        e.sexe = atoi(t);

        t[0] = reg[0];
        t[1] = reg[1];
        e.region = atoi(t);

        t[0] = forc[0];
        t[1] = forc[1];
        e.force = atoi(t);


        t[0] = grad[0];
        t[1] = grad[1];
        e.grade = atoi(t);

        int inserer ;

        inserer = Insertion_LnonOF(e);
        if (inserer)
        {
            gtk_label_set_text(GTK_LABEL(label19), "Operation reussite");
            NbEnr++;
            TSTATreg[e.region]++;
            TSTATforc[e.force]++;
            TSTATcatgrad[Determin_cat_grad(e.grade)]++;
            TSTATcatage[Determin_cat_age(an_courant - an)]++;
            Statistiques();
        }
        if (!inserer) gtk_label_set_text(GTK_LABEL(label19), "Ce matricule existe deja");
        save(t_vide_actif, Lb_vide);
        save(t_vide_archive, Lb_vide_arch);


    }

}


/****************** cette fonction contient l'affichage sur ecran de tous les widgets de la fenetre des fonctionnalités *****************/


void window_principale (GtkWidget *widget, gpointer data)
{
        builder = gtk_builder_new_from_file("project.glade");
        window2 = GTK_WIDGET(gtk_builder_get_object(builder, "window2"));
        gtk_window_set_default_size(GTK_WINDOW(window2), 4100, 700);
        gtk_window_set_position(GTK_WINDOW(window2),GTK_WIN_POS_CENTER);
        gtk_window_maximize (GTK_WINDOW(window2));

        context = gtk_widget_get_style_context(GTK_WIDGET(window2));
        gtk_style_context_add_class(context, "window2");

        stack1 = GTK_WIDGET(gtk_builder_get_object(builder, "stack1"));
        switcher1 = GTK_WIDGET(gtk_builder_get_object(builder, "switcher1"));





        /************************* fixed 1********************************/

        label1 = GTK_WIDGET(gtk_builder_get_object(builder, "label1"));
            context = gtk_widget_get_style_context(GTK_WIDGET(label1));
            gtk_style_context_add_class(context, "label1");

        label2 = GTK_WIDGET(gtk_builder_get_object(builder, "label2"));
            context = gtk_widget_get_style_context(GTK_WIDGET(label2));
            gtk_style_context_add_class(context, "label2");

        label3 = GTK_WIDGET(gtk_builder_get_object(builder, "label3"));
            context = gtk_widget_get_style_context(GTK_WIDGET(label3));
            gtk_style_context_add_class(context, "label3");

        label4 = GTK_WIDGET(gtk_builder_get_object(builder, "label4"));
            context = gtk_widget_get_style_context(GTK_WIDGET(label4));
            gtk_style_context_add_class(context, "label4");

        label5 = GTK_WIDGET(gtk_builder_get_object(builder, "label5"));
            context = gtk_widget_get_style_context(GTK_WIDGET(label5));
            gtk_style_context_add_class(context, "label5");

        label6 = GTK_WIDGET(gtk_builder_get_object(builder, "label6"));
            context = gtk_widget_get_style_context(GTK_WIDGET(label6));
            gtk_style_context_add_class(context, "label6");

        label7 = GTK_WIDGET(gtk_builder_get_object(builder, "label7"));
            context = gtk_widget_get_style_context(GTK_WIDGET(label7));
            gtk_style_context_add_class(context, "label7");

        label8 = GTK_WIDGET(gtk_builder_get_object(builder, "label8"));
            context = gtk_widget_get_style_context(GTK_WIDGET(label8));
            gtk_style_context_add_class(context, "label8");

        label9 = GTK_WIDGET(gtk_builder_get_object(builder, "label9"));
            context = gtk_widget_get_style_context(GTK_WIDGET(label9));
            gtk_style_context_add_class(context, "label9");

        label10 = GTK_WIDGET(gtk_builder_get_object(builder, "label10"));
            context = gtk_widget_get_style_context(GTK_WIDGET(label10));
            gtk_style_context_add_class(context, "label10");

        label11 = GTK_WIDGET(gtk_builder_get_object(builder, "label11"));
            context = gtk_widget_get_style_context(GTK_WIDGET(label11));
            gtk_style_context_add_class(context, "label11");
        label12 = GTK_WIDGET(gtk_builder_get_object(builder, "label12"));
            context = gtk_widget_get_style_context(GTK_WIDGET(label12));
            gtk_style_context_add_class(context, "label12");

        label13 = GTK_WIDGET(gtk_builder_get_object(builder, "label13"));
            context = gtk_widget_get_style_context(GTK_WIDGET(label13));
            gtk_style_context_add_class(context, "label13");

        label14 = GTK_WIDGET(gtk_builder_get_object(builder, "label14"));
            context = gtk_widget_get_style_context(GTK_WIDGET(label14));
            gtk_style_context_add_class(context, "label14");

        label15 = GTK_WIDGET(gtk_builder_get_object(builder, "label15"));
            context = gtk_widget_get_style_context(GTK_WIDGET(label15));
            gtk_style_context_add_class(context, "label15");

        label16 = GTK_WIDGET(gtk_builder_get_object(builder, "label16"));
            context = gtk_widget_get_style_context(GTK_WIDGET(label16));
            gtk_style_context_add_class(context, "label16");

        label17 = GTK_WIDGET(gtk_builder_get_object(builder, "label17"));
            context = gtk_widget_get_style_context(GTK_WIDGET(label17));
            gtk_style_context_add_class(context, "label17");

        label18 = GTK_WIDGET(gtk_builder_get_object(builder, "label18"));
            context = gtk_widget_get_style_context(GTK_WIDGET(label18));
            gtk_style_context_add_class(context, "label18");

        label19 = GTK_WIDGET(gtk_builder_get_object(builder, "label19"));
            context = gtk_widget_get_style_context(GTK_WIDGET(label19));
            gtk_style_context_add_class(context, "label19");

        label44 = GTK_WIDGET(gtk_builder_get_object(builder, "label44"));
            context = gtk_widget_get_style_context(GTK_WIDGET(label44));
            gtk_style_context_add_class(context, "label44");

        label45 = GTK_WIDGET(gtk_builder_get_object(builder, "label45"));
            context = gtk_widget_get_style_context(GTK_WIDGET(label45));
            gtk_style_context_add_class(context, "label45");


        ent1 = GTK_WIDGET(gtk_builder_get_object(builder, "ent1"));
        ent2 = GTK_WIDGET(gtk_builder_get_object(builder, "ent2"));
        ent3 = GTK_WIDGET(gtk_builder_get_object(builder, "ent3"));
        ent4 = GTK_WIDGET(gtk_builder_get_object(builder, "ent4"));
        ent5 = GTK_WIDGET(gtk_builder_get_object(builder, "ent5"));
        ent6 = GTK_WIDGET(gtk_builder_get_object(builder, "ent6"));
        ent7 = GTK_WIDGET(gtk_builder_get_object(builder, "ent7"));
        ent8 = GTK_WIDGET(gtk_builder_get_object(builder, "ent8"));
        ent66 = GTK_WIDGET(gtk_builder_get_object(builder, "ent66"));


        combo1 = GTK_WIDGET(gtk_builder_get_object(builder, "combo1"));
        combo2 = GTK_WIDGET(gtk_builder_get_object(builder, "combo2"));
        combo3 = GTK_WIDGET(gtk_builder_get_object(builder, "combo3"));
        combo4 = GTK_WIDGET(gtk_builder_get_object(builder, "combo4"));
        combo5 = GTK_WIDGET(gtk_builder_get_object(builder, "combo5"));
        combo6 = GTK_WIDGET(gtk_builder_get_object(builder, "combo6"));

        spin1 = GTK_WIDGET(gtk_builder_get_object(builder, "spin1"));
        spin2 = GTK_WIDGET(gtk_builder_get_object(builder, "spin2"));
        spin3 = GTK_WIDGET(gtk_builder_get_object(builder, "spin3"));

        image1 = GTK_WIDGET(gtk_builder_get_object(builder, "image1"));

        button1 = GTK_WIDGET(gtk_builder_get_object(builder, "button1"));
            context = gtk_widget_get_style_context(GTK_WIDGET(button1));
            gtk_style_context_add_class(context, "button1");

        button2 = GTK_WIDGET(gtk_builder_get_object(builder, "button2"));

        /***********************************************************************/

        /*************************** fixed 2***********************************/

        label20 = GTK_WIDGET(gtk_builder_get_object(builder, "label20"));
            context = gtk_widget_get_style_context(GTK_WIDGET(label20));
            gtk_style_context_add_class(context, "label20");

        label21 = GTK_WIDGET(gtk_builder_get_object(builder, "label21"));
            context = gtk_widget_get_style_context(GTK_WIDGET(label21));
            gtk_style_context_add_class(context, "label21");

        label22 = GTK_WIDGET(gtk_builder_get_object(builder, "label22"));
            context = gtk_widget_get_style_context(GTK_WIDGET(label22));
            gtk_style_context_add_class(context, "label22");

        ent9 = GTK_WIDGET(gtk_builder_get_object(builder, "ent9"));

        button3 = GTK_WIDGET(gtk_builder_get_object(builder, "button3"));
            context = gtk_widget_get_style_context(GTK_WIDGET(button3));
            gtk_style_context_add_class(context, "button3");
        button4 = GTK_WIDGET(gtk_builder_get_object(builder, "button4"));

        image2 = GTK_WIDGET(gtk_builder_get_object(builder, "image2"));


        /***********************************************************************/


        /*************************** fixed 3 ***********************************/

        label23 = GTK_WIDGET(gtk_builder_get_object(builder, "label23"));
            context = gtk_widget_get_style_context(GTK_WIDGET(label23));
            gtk_style_context_add_class(context, "label23");

        label24 = GTK_WIDGET(gtk_builder_get_object(builder, "label24"));
            context = gtk_widget_get_style_context(GTK_WIDGET(label24));
            gtk_style_context_add_class(context, "label24");

        label25 = GTK_WIDGET(gtk_builder_get_object(builder, "label25"));
            context = gtk_widget_get_style_context(GTK_WIDGET(label25));
            gtk_style_context_add_class(context, "label25");

        ent10 = GTK_WIDGET(gtk_builder_get_object(builder, "ent10"));

        button5 = GTK_WIDGET(gtk_builder_get_object(builder, "button5"));
            context = gtk_widget_get_style_context(GTK_WIDGET(button5));
            gtk_style_context_add_class(context, "button5");

        button6 = GTK_WIDGET(gtk_builder_get_object(builder, "button6"));

        image3 = GTK_WIDGET(gtk_builder_get_object(builder, "image3"));

        box1 = GTK_WIDGET(gtk_builder_get_object(builder, "box1"));

        label26 = GTK_WIDGET(gtk_builder_get_object(builder, "label26")); gtk_label_set_text(GTK_LABEL(label26), "");
            context = gtk_widget_get_style_context(GTK_WIDGET(label26));
            gtk_style_context_add_class(context, "label26");

        label27 = GTK_WIDGET(gtk_builder_get_object(builder, "label27")); gtk_label_set_text(GTK_LABEL(label27), "");
            context = gtk_widget_get_style_context(GTK_WIDGET(label27));
            gtk_style_context_add_class(context, "label27");

        label28 = GTK_WIDGET(gtk_builder_get_object(builder, "label28")); gtk_label_set_text(GTK_LABEL(label28), "");
            context = gtk_widget_get_style_context(GTK_WIDGET(label28));
            gtk_style_context_add_class(context, "label28");

        label29 = GTK_WIDGET(gtk_builder_get_object(builder, "label29")); gtk_label_set_text(GTK_LABEL(label29), "");
            context = gtk_widget_get_style_context(GTK_WIDGET(label29));
            gtk_style_context_add_class(context, "label29");

        label30 = GTK_WIDGET(gtk_builder_get_object(builder, "label30")); gtk_label_set_text(GTK_LABEL(label30), "");
            context = gtk_widget_get_style_context(GTK_WIDGET(label30));
            gtk_style_context_add_class(context, "label30");

        label31 = GTK_WIDGET(gtk_builder_get_object(builder, "label31")); gtk_label_set_text(GTK_LABEL(label31), "");
            context = gtk_widget_get_style_context(GTK_WIDGET(label31));
            gtk_style_context_add_class(context, "label31");

        label32 = GTK_WIDGET(gtk_builder_get_object(builder, "label32")); gtk_label_set_text(GTK_LABEL(label32), "");
            context = gtk_widget_get_style_context(GTK_WIDGET(label32));
            gtk_style_context_add_class(context, "label32");

        label33 = GTK_WIDGET(gtk_builder_get_object(builder, "label33")); gtk_label_set_text(GTK_LABEL(label33), "");
            context = gtk_widget_get_style_context(GTK_WIDGET(label33));
            gtk_style_context_add_class(context, "label33");

        label34 = GTK_WIDGET(gtk_builder_get_object(builder, "label34")); gtk_label_set_text(GTK_LABEL(label34), "");
            context = gtk_widget_get_style_context(GTK_WIDGET(label34));
            gtk_style_context_add_class(context, "label34");

        label46 = GTK_WIDGET(gtk_builder_get_object(builder, "label46")); gtk_label_set_text(GTK_LABEL(label46), "");
            context = gtk_widget_get_style_context(GTK_WIDGET(label46));
            gtk_style_context_add_class(context, "label46");


        box2 = GTK_WIDGET(gtk_builder_get_object(builder, "box2"));

        label35 = GTK_WIDGET(gtk_builder_get_object(builder, "label35")); gtk_label_set_text(GTK_LABEL(label35), "");
            context = gtk_widget_get_style_context(GTK_WIDGET(label35));
            gtk_style_context_add_class(context, "label35");

        label36 = GTK_WIDGET(gtk_builder_get_object(builder, "label36")); gtk_label_set_text(GTK_LABEL(label36), "");
            context = gtk_widget_get_style_context(GTK_WIDGET(label36));
            gtk_style_context_add_class(context, "label36");

        label37 = GTK_WIDGET(gtk_builder_get_object(builder, "label37")); gtk_label_set_text(GTK_LABEL(label37), "");
            context = gtk_widget_get_style_context(GTK_WIDGET(label37));
            gtk_style_context_add_class(context, "label37");

        label38 = GTK_WIDGET(gtk_builder_get_object(builder, "label38")); gtk_label_set_text(GTK_LABEL(label38), "");
            context = gtk_widget_get_style_context(GTK_WIDGET(label38));
            gtk_style_context_add_class(context, "label38");

        label39 = GTK_WIDGET(gtk_builder_get_object(builder, "label39")); gtk_label_set_text(GTK_LABEL(label39), "");
            context = gtk_widget_get_style_context(GTK_WIDGET(label39));
            gtk_style_context_add_class(context, "label39");

        label40 = GTK_WIDGET(gtk_builder_get_object(builder, "label40")); gtk_label_set_text(GTK_LABEL(label40), "");
            context = gtk_widget_get_style_context(GTK_WIDGET(label40));
            gtk_style_context_add_class(context, "label40");

        label41 = GTK_WIDGET(gtk_builder_get_object(builder, "label41")); gtk_label_set_text(GTK_LABEL(label41), "");
            context = gtk_widget_get_style_context(GTK_WIDGET(label41));
            gtk_style_context_add_class(context, "label41");

        label42 = GTK_WIDGET(gtk_builder_get_object(builder, "label42")); gtk_label_set_text(GTK_LABEL(label42), "");
            context = gtk_widget_get_style_context(GTK_WIDGET(label42));
            gtk_style_context_add_class(context, "label42");

        label43 = GTK_WIDGET(gtk_builder_get_object(builder, "label43")); gtk_label_set_text(GTK_LABEL(label43), "");
            context = gtk_widget_get_style_context(GTK_WIDGET(label43));
            gtk_style_context_add_class(context, "label43");

        label47 = GTK_WIDGET(gtk_builder_get_object(builder, "label47")); gtk_label_set_text(GTK_LABEL(label47), "");
            context = gtk_widget_get_style_context(GTK_WIDGET(label47));
            gtk_style_context_add_class(context, "label47");




        /***********************************************************************/

        /*************************** fixed 4 ***********************************/


        button7 = GTK_WIDGET(gtk_builder_get_object(builder, "button7"));
            context = gtk_widget_get_style_context(GTK_WIDGET(button7));
            gtk_style_context_add_class(context, "button7");

        button8 = GTK_WIDGET(gtk_builder_get_object(builder, "button8"));

        image4 = GTK_WIDGET(gtk_builder_get_object(builder, "image4"));

        label48 = GTK_WIDGET(gtk_builder_get_object(builder, "label48"));
            context = gtk_widget_get_style_context(GTK_WIDGET(label48));
            gtk_style_context_add_class(context, "label48");

        label49 = GTK_WIDGET(gtk_builder_get_object(builder, "label49"));
            context = gtk_widget_get_style_context(GTK_WIDGET(label49));
            gtk_style_context_add_class(context, "label49");

        label50 = GTK_WIDGET(gtk_builder_get_object(builder, "label50"));
            context = gtk_widget_get_style_context(GTK_WIDGET(label50));
            gtk_style_context_add_class(context, "label50");

        label51 = GTK_WIDGET(gtk_builder_get_object(builder, "label51"));
            context = gtk_widget_get_style_context(GTK_WIDGET(label51));
            gtk_style_context_add_class(context, "label51");

        label52 = GTK_WIDGET(gtk_builder_get_object(builder, "label52"));
            context = gtk_widget_get_style_context(GTK_WIDGET(label52));
            gtk_style_context_add_class(context, "label52");

        label53 = GTK_WIDGET(gtk_builder_get_object(builder, "label53"));
            context = gtk_widget_get_style_context(GTK_WIDGET(label53));
            gtk_style_context_add_class(context, "label53");

        label54 = GTK_WIDGET(gtk_builder_get_object(builder, "label54"));
            context = gtk_widget_get_style_context(GTK_WIDGET(label54));
            gtk_style_context_add_class(context, "label54");

        label55 = GTK_WIDGET(gtk_builder_get_object(builder, "label55"));
            context = gtk_widget_get_style_context(GTK_WIDGET(label55));
            gtk_style_context_add_class(context, "label55");

        label56 = GTK_WIDGET(gtk_builder_get_object(builder, "label56"));
            context = gtk_widget_get_style_context(GTK_WIDGET(label56));
            gtk_style_context_add_class(context, "label56");

        label57 = GTK_WIDGET(gtk_builder_get_object(builder, "label57"));
            context = gtk_widget_get_style_context(GTK_WIDGET(label57));
            gtk_style_context_add_class(context, "label57");

        label58 = GTK_WIDGET(gtk_builder_get_object(builder, "label58"));
            context = gtk_widget_get_style_context(GTK_WIDGET(label58));
            gtk_style_context_add_class(context, "label58");

        ent11 = GTK_WIDGET(gtk_builder_get_object(builder, "ent11"));
        ent12 = GTK_WIDGET(gtk_builder_get_object(builder, "ent12"));
        ent13 = GTK_WIDGET(gtk_builder_get_object(builder, "ent13"));
        ent14 = GTK_WIDGET(gtk_builder_get_object(builder, "ent14"));

        combo7 = GTK_WIDGET(gtk_builder_get_object(builder, "combo7"));
        combo8 = GTK_WIDGET(gtk_builder_get_object(builder, "combo8"));
        combo9 = GTK_WIDGET(gtk_builder_get_object(builder, "combo9"));



        /***********************************************************************/


        /*************************** fixed 5 ***********************************/


        button9 = GTK_WIDGET(gtk_builder_get_object(builder, "button9"));
            context = gtk_widget_get_style_context(GTK_WIDGET(button9));
            gtk_style_context_add_class(context, "button9");
        button10 = GTK_WIDGET(gtk_builder_get_object(builder, "button10"));

        label61 = GTK_WIDGET(gtk_builder_get_object(builder, "label61"));
            context = gtk_widget_get_style_context(GTK_WIDGET(label61));
            gtk_style_context_add_class(context, "label61");

        label62 = GTK_WIDGET(gtk_builder_get_object(builder, "label62"));
            context = gtk_widget_get_style_context(GTK_WIDGET(label62));
            gtk_style_context_add_class(context, "label62");

        label64 = GTK_WIDGET(gtk_builder_get_object(builder, "label64"));
            context = gtk_widget_get_style_context(GTK_WIDGET(label64));
            gtk_style_context_add_class(context, "label64");

        label65 = GTK_WIDGET(gtk_builder_get_object(builder, "label65"));
            context = gtk_widget_get_style_context(GTK_WIDGET(label65));
            gtk_style_context_add_class(context, "label65");

        label66 = GTK_WIDGET(gtk_builder_get_object(builder, "label66"));
            context = gtk_widget_get_style_context(GTK_WIDGET(label66));
            gtk_style_context_add_class(context, "label66");

        label67 = GTK_WIDGET(gtk_builder_get_object(builder, "label67"));
            context = gtk_widget_get_style_context(GTK_WIDGET(label67));
            gtk_style_context_add_class(context, "label67");

        label77 = GTK_WIDGET(gtk_builder_get_object(builder, "label77"));
            context = gtk_widget_get_style_context(GTK_WIDGET(label77));
            gtk_style_context_add_class(context, "label77");

        label78 = GTK_WIDGET(gtk_builder_get_object(builder, "label78"));
            context = gtk_widget_get_style_context(GTK_WIDGET(label78));
            gtk_style_context_add_class(context, "label78");

        label59 = GTK_WIDGET(gtk_builder_get_object(builder, "label59"));
            context = gtk_widget_get_style_context(GTK_WIDGET(label59));
            gtk_style_context_add_class(context, "label59");

        label60 = GTK_WIDGET(gtk_builder_get_object(builder, "label60"));
            context = gtk_widget_get_style_context(GTK_WIDGET(label60));
            gtk_style_context_add_class(context, "label60");

        label151 = GTK_WIDGET(gtk_builder_get_object(builder, "label151"));
            context = gtk_widget_get_style_context(GTK_WIDGET(label151));
            gtk_style_context_add_class(context, "label151");

        combo12 = GTK_WIDGET(gtk_builder_get_object(builder, "combo12"));
        combo13 = GTK_WIDGET(gtk_builder_get_object(builder, "combo13"));
        combo14 = GTK_WIDGET(gtk_builder_get_object(builder, "combo14"));
        combo15 = GTK_WIDGET(gtk_builder_get_object(builder, "combo15"));

        ent15 = GTK_WIDGET(gtk_builder_get_object(builder, "ent15"));
        ent16 = GTK_WIDGET(gtk_builder_get_object(builder, "ent16"));
        ent17 = GTK_WIDGET(gtk_builder_get_object(builder, "ent17"));
        ent18 = GTK_WIDGET(gtk_builder_get_object(builder, "ent18"));
        ent19 = GTK_WIDGET(gtk_builder_get_object(builder, "ent19"));
        ent20 = GTK_WIDGET(gtk_builder_get_object(builder, "ent20"));

        spin4 = GTK_WIDGET(gtk_builder_get_object(builder, "spin4"));
        spin5 = GTK_WIDGET(gtk_builder_get_object(builder, "spin5"));

        radio1 = GTK_WIDGET(gtk_builder_get_object(builder, "radio1"));
            context = gtk_widget_get_style_context(GTK_WIDGET(radio1));
            gtk_style_context_add_class(context, "radio1");

        radio2 = GTK_WIDGET(gtk_builder_get_object(builder, "radio2"));
            context = gtk_widget_get_style_context(GTK_WIDGET(radio2));
            gtk_style_context_add_class(context, "radio2");


        progress1 = GTK_WIDGET(gtk_builder_get_object(builder, "progress1"));
            context = gtk_widget_get_style_context(GTK_WIDGET(progress1));
            gtk_style_context_add_class(context, "progress1");

        scroll1 = GTK_WIDGET(gtk_builder_get_object(builder, "scroll1"));

        port1 = GTK_WIDGET(gtk_builder_get_object(builder, "port1"));
        tabG[iGTK] = GTK_WIDGET(gtk_builder_get_object(builder, "box3"));



        /***********************************************************************/



        /*************************** fixed 6 ***********************************/


        button11 = GTK_WIDGET(gtk_builder_get_object(builder, "button11"));
            context = gtk_widget_get_style_context(GTK_WIDGET(button11));
            gtk_style_context_add_class(context, "button11");
        button12 = GTK_WIDGET(gtk_builder_get_object(builder, "button12"));

        label63 = GTK_WIDGET(gtk_builder_get_object(builder, "label63"));
            context = gtk_widget_get_style_context(GTK_WIDGET(label63));
            gtk_style_context_add_class(context, "label63");

        label68 = GTK_WIDGET(gtk_builder_get_object(builder, "label68"));
            context = gtk_widget_get_style_context(GTK_WIDGET(label68));
            gtk_style_context_add_class(context, "label68");

        label69 = GTK_WIDGET(gtk_builder_get_object(builder, "label69"));
            context = gtk_widget_get_style_context(GTK_WIDGET(label69));
            gtk_style_context_add_class(context, "label69");

        label70 = GTK_WIDGET(gtk_builder_get_object(builder, "label70"));
            context = gtk_widget_get_style_context(GTK_WIDGET(label70));
            gtk_style_context_add_class(context, "label70");

        label71 = GTK_WIDGET(gtk_builder_get_object(builder, "label71"));
            context = gtk_widget_get_style_context(GTK_WIDGET(label71));
            gtk_style_context_add_class(context, "label71");

        label72 = GTK_WIDGET(gtk_builder_get_object(builder, "label72"));
            context = gtk_widget_get_style_context(GTK_WIDGET(label72));
            gtk_style_context_add_class(context, "label72");

        label74 = GTK_WIDGET(gtk_builder_get_object(builder, "label74"));
            context = gtk_widget_get_style_context(GTK_WIDGET(label74));
            gtk_style_context_add_class(context, "label74");

        label75 = GTK_WIDGET(gtk_builder_get_object(builder, "label75"));
            context = gtk_widget_get_style_context(GTK_WIDGET(label75));
            gtk_style_context_add_class(context, "label75");

        label76 = GTK_WIDGET(gtk_builder_get_object(builder, "label76"));
            context = gtk_widget_get_style_context(GTK_WIDGET(label76));
            gtk_style_context_add_class(context, "label76");

        label79 = GTK_WIDGET(gtk_builder_get_object(builder, "label79"));
            context = gtk_widget_get_style_context(GTK_WIDGET(label79));
            gtk_style_context_add_class(context, "label79");

        image6 = GTK_WIDGET(gtk_builder_get_object(builder, "image6"));

        combo16 = GTK_WIDGET(gtk_builder_get_object(builder, "combo16"));
        combo17 = GTK_WIDGET(gtk_builder_get_object(builder, "combo17"));
        combo18 = GTK_WIDGET(gtk_builder_get_object(builder, "combo18"));
        combo19 = GTK_WIDGET(gtk_builder_get_object(builder, "combo19"));
        combo20 = GTK_WIDGET(gtk_builder_get_object(builder, "combo20"));
        combo21 = GTK_WIDGET(gtk_builder_get_object(builder, "combo21"));

        ent21 = GTK_WIDGET(gtk_builder_get_object(builder, "ent21"));
        ent23 = GTK_WIDGET(gtk_builder_get_object(builder, "ent23"));
        ent24 = GTK_WIDGET(gtk_builder_get_object(builder, "ent24"));
        ent25 = GTK_WIDGET(gtk_builder_get_object(builder, "ent25"));
        ent26 = GTK_WIDGET(gtk_builder_get_object(builder, "ent26"));
        ent27 = GTK_WIDGET(gtk_builder_get_object(builder, "ent27"));

        spin6 = GTK_WIDGET(gtk_builder_get_object(builder, "spin6"));
        spin7 = GTK_WIDGET(gtk_builder_get_object(builder, "spin7"));



        /***********************************************************************/


        /*************************** fixed 7 ***********************************/

        stack2 = GTK_WIDGET(gtk_builder_get_object(builder, "stack2"));
        switcher2 = GTK_WIDGET(gtk_builder_get_object(builder, "switcher2"));

                /*************************** fixed 7 ***********************************/

        stack2 = GTK_WIDGET(gtk_builder_get_object(builder, "stack2"));
        switcher2 = GTK_WIDGET(gtk_builder_get_object(builder, "switcher2"));

                /********** fix 1 ***********/

        radio3 = GTK_WIDGET(gtk_builder_get_object(builder, "radio3"));
        context = gtk_widget_get_style_context(GTK_WIDGET(radio3));
        gtk_style_context_add_class(context, "radio3");

        radio4 = GTK_WIDGET(gtk_builder_get_object(builder, "radio4"));
        context = gtk_widget_get_style_context(GTK_WIDGET(radio4));
        gtk_style_context_add_class(context, "radio4");


        button13 = GTK_WIDGET(gtk_builder_get_object(builder, "button13"));
            context = gtk_widget_get_style_context(GTK_WIDGET(button13));
            gtk_style_context_add_class(context, "button13");

        image7 = GTK_WIDGET(gtk_builder_get_object(builder, "image7"));

        radio5 = GTK_WIDGET(gtk_builder_get_object(builder, "radio5"));
        context = gtk_widget_get_style_context(GTK_WIDGET(radio5));
        gtk_style_context_add_class(context, "radio5");

        radio6 = GTK_WIDGET(gtk_builder_get_object(builder, "radio6"));
        context = gtk_widget_get_style_context(GTK_WIDGET(radio6));
        gtk_style_context_add_class(context, "radio6");

        radio7 = GTK_WIDGET(gtk_builder_get_object(builder, "radio7"));
        context = gtk_widget_get_style_context(GTK_WIDGET(radio7));
        gtk_style_context_add_class(context, "radio7");

        radio8 = GTK_WIDGET(gtk_builder_get_object(builder, "radio8"));
        context = gtk_widget_get_style_context(GTK_WIDGET(radio8));
        gtk_style_context_add_class(context, "radio8");

        radio9 = GTK_WIDGET(gtk_builder_get_object(builder, "radio9"));
        context = gtk_widget_get_style_context(GTK_WIDGET(radio9));
        gtk_style_context_add_class(context, "radio9");

        radio10 = GTK_WIDGET(gtk_builder_get_object(builder, "radio10"));
        context = gtk_widget_get_style_context(GTK_WIDGET(radio10));
        gtk_style_context_add_class(context, "radio10");

        radio11 = GTK_WIDGET(gtk_builder_get_object(builder, "radio11"));
        context = gtk_widget_get_style_context(GTK_WIDGET(radio11));
        gtk_style_context_add_class(context, "radio11");

        radio12 = GTK_WIDGET(gtk_builder_get_object(builder, "radio12"));
        context = gtk_widget_get_style_context(GTK_WIDGET(radio12));
        gtk_style_context_add_class(context, "radio12");


        label73 = GTK_WIDGET(gtk_builder_get_object(builder, "label73"));
        context = gtk_widget_get_style_context(GTK_WIDGET(label73));
        gtk_style_context_add_class(context, "label73");

        scroll2 = GTK_WIDGET(gtk_builder_get_object(builder, "scroll2"));
        port2 = GTK_WIDGET(gtk_builder_get_object(builder, "port2"));

        tabG2[iGTK2] = GTK_WIDGET(gtk_builder_get_object(builder, "box4"));

        button14 = GTK_WIDGET(gtk_builder_get_object(builder, "button14"));
        progress2 = GTK_WIDGET(gtk_builder_get_object(builder, "progress2"));
        context = gtk_widget_get_style_context(GTK_WIDGET(progress2));
        gtk_style_context_add_class(context, "progress2");

        label158 = GTK_WIDGET(gtk_builder_get_object(builder, "label158"));
         context = gtk_widget_get_style_context(GTK_WIDGET(label158));
        gtk_style_context_add_class(context, "label158");

        button15 = GTK_WIDGET(gtk_builder_get_object(builder, "button15"));
            context = gtk_widget_get_style_context(GTK_WIDGET(button15));
            gtk_style_context_add_class(context, "button15");

                        /****************************/

/*************************** fixed 7 ***********************************/

        stack2 = GTK_WIDGET(gtk_builder_get_object(builder, "stack2"));
        switcher2 = GTK_WIDGET(gtk_builder_get_object(builder, "switcher2"));

                /********** fix 1 ***********/

        radio3 = GTK_WIDGET(gtk_builder_get_object(builder, "radio3"));
        context = gtk_widget_get_style_context(GTK_WIDGET(radio3));
        gtk_style_context_add_class(context, "radio3");

        radio4 = GTK_WIDGET(gtk_builder_get_object(builder, "radio4"));
        context = gtk_widget_get_style_context(GTK_WIDGET(radio4));
        gtk_style_context_add_class(context, "radio4");


        button13 = GTK_WIDGET(gtk_builder_get_object(builder, "button13"));

        image7 = GTK_WIDGET(gtk_builder_get_object(builder, "image7"));

        radio5 = GTK_WIDGET(gtk_builder_get_object(builder, "radio5"));
        context = gtk_widget_get_style_context(GTK_WIDGET(radio5));
        gtk_style_context_add_class(context, "radio5");

        radio6 = GTK_WIDGET(gtk_builder_get_object(builder, "radio6"));
        context = gtk_widget_get_style_context(GTK_WIDGET(radio6));
        gtk_style_context_add_class(context, "radio6");

        radio7 = GTK_WIDGET(gtk_builder_get_object(builder, "radio7"));
        context = gtk_widget_get_style_context(GTK_WIDGET(radio7));
        gtk_style_context_add_class(context, "radio7");

        radio8 = GTK_WIDGET(gtk_builder_get_object(builder, "radio8"));
        context = gtk_widget_get_style_context(GTK_WIDGET(radio8));
        gtk_style_context_add_class(context, "radio8");

        radio9 = GTK_WIDGET(gtk_builder_get_object(builder, "radio9"));
        context = gtk_widget_get_style_context(GTK_WIDGET(radio9));
        gtk_style_context_add_class(context, "radio9");

        radio10 = GTK_WIDGET(gtk_builder_get_object(builder, "radio10"));
        context = gtk_widget_get_style_context(GTK_WIDGET(radio10));
        gtk_style_context_add_class(context, "radio10");

        radio11 = GTK_WIDGET(gtk_builder_get_object(builder, "radio11"));
        context = gtk_widget_get_style_context(GTK_WIDGET(radio11));
        gtk_style_context_add_class(context, "radio11");

        radio12 = GTK_WIDGET(gtk_builder_get_object(builder, "radio12"));
        context = gtk_widget_get_style_context(GTK_WIDGET(radio12));
        gtk_style_context_add_class(context, "radio12");


        label73 = GTK_WIDGET(gtk_builder_get_object(builder, "label73"));
        context = gtk_widget_get_style_context(GTK_WIDGET(label73));
        gtk_style_context_add_class(context, "label73");

        scroll2 = GTK_WIDGET(gtk_builder_get_object(builder, "scroll2"));
        port2 = GTK_WIDGET(gtk_builder_get_object(builder, "port2"));

        tabG2[iGTK2] = GTK_WIDGET(gtk_builder_get_object(builder, "box4"));

        button14 = GTK_WIDGET(gtk_builder_get_object(builder, "button14"));
        progress2 = GTK_WIDGET(gtk_builder_get_object(builder, "progress2"));
        context = gtk_widget_get_style_context(GTK_WIDGET(progress2));
        gtk_style_context_add_class(context, "progress2");

        label158 = GTK_WIDGET(gtk_builder_get_object(builder, "label158"));
        context = gtk_widget_get_style_context(GTK_WIDGET(label158));
        gtk_style_context_add_class(context, "label158");

        button15 = GTK_WIDGET(gtk_builder_get_object(builder, "button15"));

                        /****************************/




                        /********** fix2 ***************/

        grid1 = GTK_WIDGET(gtk_builder_get_object(builder, "grid1"));
            label80 = GTK_WIDGET(gtk_builder_get_object(builder, "label80"));
            label81 = GTK_WIDGET(gtk_builder_get_object(builder, "label81"));
            label82 = GTK_WIDGET(gtk_builder_get_object(builder, "label82"));
            label83 = GTK_WIDGET(gtk_builder_get_object(builder, "label83"));
            label84 = GTK_WIDGET(gtk_builder_get_object(builder, "label84"));
            label85 = GTK_WIDGET(gtk_builder_get_object(builder, "label85"));
            label86 = GTK_WIDGET(gtk_builder_get_object(builder, "label86"));
            label87 = GTK_WIDGET(gtk_builder_get_object(builder, "label87"));
            label88 = GTK_WIDGET(gtk_builder_get_object(builder, "label88"));
            label89 = GTK_WIDGET(gtk_builder_get_object(builder, "label89"));
            label90 = GTK_WIDGET(gtk_builder_get_object(builder, "label90"));
            label91 = GTK_WIDGET(gtk_builder_get_object(builder, "label91"));
            label92 = GTK_WIDGET(gtk_builder_get_object(builder, "label92"));
            label93 = GTK_WIDGET(gtk_builder_get_object(builder, "label93"));
            label94 = GTK_WIDGET(gtk_builder_get_object(builder, "label94"));
            label95 = GTK_WIDGET(gtk_builder_get_object(builder, "label95"));
            label96 = GTK_WIDGET(gtk_builder_get_object(builder, "label96"));
            label97 = GTK_WIDGET(gtk_builder_get_object(builder, "label97"));
            label98 = GTK_WIDGET(gtk_builder_get_object(builder, "label98"));
            label99 = GTK_WIDGET(gtk_builder_get_object(builder, "label99"));
            label100 = GTK_WIDGET(gtk_builder_get_object(builder, "label100"));

        grid2 = GTK_WIDGET(gtk_builder_get_object(builder, "grid2"));
             label101 = GTK_WIDGET(gtk_builder_get_object(builder, "label101"));
             label102 = GTK_WIDGET(gtk_builder_get_object(builder, "label102"));
             label103 = GTK_WIDGET(gtk_builder_get_object(builder, "label103"));
             label104 = GTK_WIDGET(gtk_builder_get_object(builder, "label104"));
             label105 = GTK_WIDGET(gtk_builder_get_object(builder, "label105"));
             label106 = GTK_WIDGET(gtk_builder_get_object(builder, "label106"));
             label107 = GTK_WIDGET(gtk_builder_get_object(builder, "label107"));
             label108 = GTK_WIDGET(gtk_builder_get_object(builder, "label108"));
             label109 = GTK_WIDGET(gtk_builder_get_object(builder, "label109"));
             label110 = GTK_WIDGET(gtk_builder_get_object(builder, "label110"));
             label111 = GTK_WIDGET(gtk_builder_get_object(builder, "label111"));
             label112 = GTK_WIDGET(gtk_builder_get_object(builder, "label112"));
             label113 = GTK_WIDGET(gtk_builder_get_object(builder, "label113"));
             label114 = GTK_WIDGET(gtk_builder_get_object(builder, "label114"));
             label115 = GTK_WIDGET(gtk_builder_get_object(builder, "label115"));
             label116 = GTK_WIDGET(gtk_builder_get_object(builder, "label116"));
             label117 = GTK_WIDGET(gtk_builder_get_object(builder, "label117"));
             label118 = GTK_WIDGET(gtk_builder_get_object(builder, "label118"));
             label119 = GTK_WIDGET(gtk_builder_get_object(builder, "label119"));
             label120 = GTK_WIDGET(gtk_builder_get_object(builder, "label120"));
             label121 = GTK_WIDGET(gtk_builder_get_object(builder, "label121"));
                context = gtk_widget_get_style_context(GTK_WIDGET(label121));
                gtk_style_context_add_class(context, "label121");

             label122 = GTK_WIDGET(gtk_builder_get_object(builder, "label122"));
             label123 = GTK_WIDGET(gtk_builder_get_object(builder, "label123"));
                context = gtk_widget_get_style_context(GTK_WIDGET(label123));
                gtk_style_context_add_class(context, "label123");

             label124 = GTK_WIDGET(gtk_builder_get_object(builder, "label124"));
             label125 = GTK_WIDGET(gtk_builder_get_object(builder, "label125"));
             label126 = GTK_WIDGET(gtk_builder_get_object(builder, "label126"));
             label127 = GTK_WIDGET(gtk_builder_get_object(builder, "label127"));

        grid3 = GTK_WIDGET(gtk_builder_get_object(builder, "grid3"));
             label128 = GTK_WIDGET(gtk_builder_get_object(builder, "label128"));
             label129 = GTK_WIDGET(gtk_builder_get_object(builder, "label129"));
             label131 = GTK_WIDGET(gtk_builder_get_object(builder, "label131"));
             label132 = GTK_WIDGET(gtk_builder_get_object(builder, "label132"));
             label133 = GTK_WIDGET(gtk_builder_get_object(builder, "label133"));
                context = gtk_widget_get_style_context(GTK_WIDGET(label133));
                gtk_style_context_add_class(context, "label133");

             label135 = GTK_WIDGET(gtk_builder_get_object(builder, "label135"));
             label136 = GTK_WIDGET(gtk_builder_get_object(builder, "label136"));
             label137 = GTK_WIDGET(gtk_builder_get_object(builder, "label137"));
             label138 = GTK_WIDGET(gtk_builder_get_object(builder, "label138"));
             label139 = GTK_WIDGET(gtk_builder_get_object(builder, "label139"));
             label140 = GTK_WIDGET(gtk_builder_get_object(builder, "label140"));
             label141 = GTK_WIDGET(gtk_builder_get_object(builder, "label141"));
             label143 = GTK_WIDGET(gtk_builder_get_object(builder, "label143"));
             label144 = GTK_WIDGET(gtk_builder_get_object(builder, "label144"));
             label145 = GTK_WIDGET(gtk_builder_get_object(builder, "label145"));
             label146 = GTK_WIDGET(gtk_builder_get_object(builder, "label146"));
             label147 = GTK_WIDGET(gtk_builder_get_object(builder, "label147"));

        grid4 = GTK_WIDGET(gtk_builder_get_object(builder, "grid4"));
             label134 = GTK_WIDGET(gtk_builder_get_object(builder, "label134"));
             label142 = GTK_WIDGET(gtk_builder_get_object(builder, "label142"));
             label148 = GTK_WIDGET(gtk_builder_get_object(builder, "label148"));
             label149 = GTK_WIDGET(gtk_builder_get_object(builder, "label149"));
             label150 = GTK_WIDGET(gtk_builder_get_object(builder, "label150"));
             label152 = GTK_WIDGET(gtk_builder_get_object(builder, "label152"));
             label153 = GTK_WIDGET(gtk_builder_get_object(builder, "label153"));
             label154 = GTK_WIDGET(gtk_builder_get_object(builder, "label154"));
             label155 = GTK_WIDGET(gtk_builder_get_object(builder, "label155"));
             label156 = GTK_WIDGET(gtk_builder_get_object(builder, "label156"));
             label157 = GTK_WIDGET(gtk_builder_get_object(builder, "label157"));
             label159 = GTK_WIDGET(gtk_builder_get_object(builder, "label159"));
             label160 = GTK_WIDGET(gtk_builder_get_object(builder, "label160"));
             label161 = GTK_WIDGET(gtk_builder_get_object(builder, "label161"));
             label162 = GTK_WIDGET(gtk_builder_get_object(builder, "label162"));

        /***********************************************************************/
        Statistiques();



        g_signal_connect(button1, "clicked", G_CALLBACK(Ajouter), NULL);

        g_signal_connect(button3, "clicked", G_CALLBACK(Supprimer), NULL);

        g_signal_connect(button5, "clicked", G_CALLBACK(Rechercher), NULL);

        g_signal_connect(button7, "clicked", G_CALLBACK(Modifier), NULL);

        g_signal_connect(button9, "clicked", G_CALLBACK(Requete), NULL);

        g_signal_connect(button11, "clicked", G_CALLBACK(Supprission_Evoluee), NULL);

        g_signal_connect(button13, "clicked", G_CALLBACK(Fragmentation), NULL);

        g_signal_connect(button15, "clicked", G_CALLBACK(Affichier_fragment), NULL);

        gtk_widget_show_all(window2);
}


/************** cette fonction charge le fichier CSS utiliser pour faire un design coloré pour l'application ***************/

void load_css()
{
    GtkCssProvider *cssprovider;
    GdkScreen *screen;
    GdkDisplay *display;

    const gchar *css_style_file = "style.css";

    GFile *css_file = g_file_new_for_path(css_style_file);

    GError *error = 0;

    cssprovider = gtk_css_provider_new();
    display = gdk_display_get_default();
    screen = gdk_display_get_default_screen(display);

    gtk_style_context_add_provider_for_screen(screen, GTK_STYLE_PROVIDER(cssprovider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    gtk_css_provider_load_from_file(cssprovider, css_file, &error);

    if (error) printf("error");

    g_object_unref(cssprovider);
}


/****************** cette fonction affiche le bloc suivant dans la fenetre a propos *********************/

void bloc_suivant(GtkWidget *widget, gpointer data)
{
    fichier F; char str[256]; char str_nb[256]; gchar *snb, *donnee;
    char genre[15];
    int i, j;

    Ouvrir(&F, F_LnonOF, 'A');

    if (premiere_fois) i = entete(F, 1);
    else i = buf_general.suivant;

    gtk_label_set_text(GTK_LABEL(gr1_label1), "");
    gtk_label_set_text(GTK_LABEL(gr1_label2), "");
    gtk_label_set_text(GTK_LABEL(gr1_label3), "");

    gtk_container_remove (GTK_CONTAINER(view1), GTK_WIDGET(tab_Gpropo[iGTK3]));

    iGTK3++;

    tab_Gpropo[iGTK3] = gtk_vbox_new (TRUE,5);

    gtk_container_add(GTK_CONTAINER(view1),GTK_WIDGET(tab_Gpropo[iGTK3]));


    if(entete(F, 3) == 0)
    {
        gtk_label_set_text(GTK_LABEL(error_label), "Le fichier\nest vide ");
    }
    else if((i == 0)&&(!premiere_fois))
    {
        gtk_label_set_text(GTK_LABEL(error_label), "Auccun bloc\nsuivant");
        buf_general.precedent = entete(F, 2);
    }
    else
    {
        LireDir(F, i, &buf_general); premiere_fois = 0;

        sprintf(str_nb, "/num du bloc precedent: %d/", buf_general.precedent);
        snb = g_locale_to_utf8 (str_nb, -1, NULL, NULL, NULL);
        gtk_label_set_text(GTK_LABEL(gr1_label1), snb);

        sprintf(str_nb, "    /nbr d'enregistrement du bloc: %d/", buf_general.nb);
        snb = g_locale_to_utf8 (str_nb, -1, NULL, NULL, NULL);
        gtk_label_set_text(GTK_LABEL(gr1_label2), snb);

        sprintf(str_nb, "\t/num du bloc suivant: %d/", buf_general.suivant);
        snb = g_locale_to_utf8 (str_nb, -1, NULL, NULL, NULL);
        gtk_label_set_text(GTK_LABEL(gr1_label3), snb);

        sprintf(str_nb, "num du bloc: %d", i);
        snb = g_locale_to_utf8 (str_nb, -1, NULL, NULL, NULL);
        gtk_label_set_text(GTK_LABEL(error_label), snb);

        for (j = 0; j<buf_general.nb; j++)
        {
            if ( buf_general.tab[j].sexe == 1) strcpy(genre, "MASCULIN\n");
            if ( buf_general.tab[j].sexe == 2) strcpy(genre, "FEMININ\n");
            sprintf(str,"\n  %s   %s\n\t%s\n\t%s\t%s\t%d / %d / %d\n\t%s\n\tRegion %d : %s\t%s\t%s\n", buf_general.tab[j].nom, buf_general.tab[j].prenom, buf_general.tab[j].matricule, genre, tab_wilaya[buf_general.tab[j].willaya-1],
                                     buf_general.tab[j].date_de_naissance.jour, buf_general.tab[j].date_de_naissance.mois, buf_general.tab[j].date_de_naissance.an,
                                     tab_grp_sang[buf_general.tab[j].grp_sang-1],buf_general.tab[j].region, tab_region[buf_general.tab[j].region-1], tab_force[buf_general.tab[j].force-1], tab_grade[buf_general.tab[j].grade-1]);
            donnee = g_locale_to_utf8 (str, -1, NULL, NULL, NULL);

            tab_propo[iLAB_propos] = gtk_label_new("Lb");
            gtk_misc_set_alignment(tab_propo[iLAB_propos], 0, 0);
            gtk_label_set_text(GTK_LABEL(tab_propo[iLAB_propos]), donnee);

            context = gtk_widget_get_style_context(GTK_WIDGET(tab_propo[iLAB_propos]));
            gtk_style_context_add_class(context, "labbox3");


            gtk_box_pack_start(GTK_BOX(tab_Gpropo[iGTK3]),tab_propo[iLAB_propos],0,0,0);
            iLAB_propos++;

            while (gtk_events_pending()) gtk_main_iteration();
            gtk_widget_show_all(propo);
        }
    }
    Fermer(F);

}

/****************** cette fonction affiche le bloc precedent dans la fenetre a propos *********************/

void bloc_precedent(GtkWidget *widget, gpointer data)
{
    fichier F; char str[256]; char str_nb[256]; gchar *snb, *donnee;
    char genre[15];
    int i, j;

    Ouvrir(&F, F_LnonOF, 'A');

    if (premiere_fois) i = entete(F, 1);
    else i = buf_general.precedent;

    gtk_label_set_text(GTK_LABEL(gr1_label1), "");
    gtk_label_set_text(GTK_LABEL(gr1_label2), "");
    gtk_label_set_text(GTK_LABEL(gr1_label3), "");

    gtk_container_remove (GTK_CONTAINER(view1), GTK_WIDGET(tab_Gpropo[iGTK3]));

    iGTK3++;

    tab_Gpropo[iGTK3] = gtk_vbox_new (TRUE,5);

    gtk_container_add(GTK_CONTAINER(view1),GTK_WIDGET(tab_Gpropo[iGTK3]));


    if(entete(F, 3) == 0)
    {
        gtk_label_set_text(GTK_LABEL(error_label), "Le fichier\nest vide ");
    }
    else if((i == 0)&&(!premiere_fois))
    {
        gtk_label_set_text(GTK_LABEL(error_label), "Auccun bloc\nprecedent");
        buf_general.suivant = entete(F, 1);
    }
    else
    {
        LireDir(F, i, &buf_general); premiere_fois = 0;

        sprintf(str_nb, "/num du bloc precedent: %d/", buf_general.precedent);
        snb = g_locale_to_utf8 (str_nb, -1, NULL, NULL, NULL);
        gtk_label_set_text(GTK_LABEL(gr1_label1), snb);

        sprintf(str_nb, "    /nbr d'enregistrement du bloc: %d/", buf_general.nb);
        snb = g_locale_to_utf8 (str_nb, -1, NULL, NULL, NULL);
        gtk_label_set_text(GTK_LABEL(gr1_label2), snb);

        sprintf(str_nb, "\t/num du bloc suivant: %d/", buf_general.suivant);
        snb = g_locale_to_utf8 (str_nb, -1, NULL, NULL, NULL);
        gtk_label_set_text(GTK_LABEL(gr1_label3), snb);

        sprintf(str_nb, "num du bloc: %d", i);
        snb = g_locale_to_utf8 (str_nb, -1, NULL, NULL, NULL);
        gtk_label_set_text(GTK_LABEL(error_label), snb);

        for (j = 0; j<buf_general.nb; j++)
        {
            if ( buf_general.tab[j].sexe == 1) strcpy(genre, "MASCULIN\n");
            if ( buf_general.tab[j].sexe == 2) strcpy(genre, "FEMININ\n");
            sprintf(str,"\n  %s   %s\n\t%s\n\t%s\t%s\t%d / %d / %d\n\t%s\n\tRegion %d : %s\t%s\t%s\n", buf_general.tab[j].nom, buf_general.tab[j].prenom, buf_general.tab[j].matricule, genre, tab_wilaya[buf_general.tab[j].willaya-1],
                                     buf_general.tab[j].date_de_naissance.jour, buf_general.tab[j].date_de_naissance.mois, buf_general.tab[j].date_de_naissance.an,
                                     tab_grp_sang[buf_general.tab[j].grp_sang-1],buf_general.tab[j].region, tab_region[buf_general.tab[j].region-1], tab_force[buf_general.tab[j].force-1], tab_grade[buf_general.tab[j].grade-1]);
            donnee = g_locale_to_utf8 (str, -1, NULL, NULL, NULL);

            tab_propo[iLAB_propos] = gtk_label_new("Lb");
            gtk_misc_set_alignment(tab_propo[iLAB_propos], 0, 0);
            gtk_label_set_text(GTK_LABEL(tab_propo[iLAB_propos]), donnee);

            context = gtk_widget_get_style_context(GTK_WIDGET(tab_propo[iLAB_propos]));
            gtk_style_context_add_class(context, "labbox3");

            gtk_box_pack_start(GTK_BOX(tab_Gpropo[iGTK3]),tab_propo[iLAB_propos],0,0,0);
            iLAB_propos++;

            while (gtk_events_pending()) gtk_main_iteration();
            gtk_widget_show_all(propo);
        }
    }
    Fermer(F);

}


/****************** cette fonction affiche le premier bloc dans la fenetre a propos *********************/


void consulter(GtkWidget *widget, gpointer data)
{
    fichier F; char str[256]; char str_nb[256]; gchar *snb, *donnee;
    char genre[15];
    int i, j;

    gtk_container_remove(GTK_CONTAINER(view1), GTK_WIDGET(tab_Gpropo[iGTK3]));

    iGTK3++;

    tab_Gpropo[iGTK3] = gtk_vbox_new (TRUE,5);

    gtk_container_add(GTK_CONTAINER(view1),GTK_WIDGET(tab_Gpropo[iGTK3]));

    gtk_label_set_text(GTK_LABEL(gr1_label1), "");
    gtk_label_set_text(GTK_LABEL(gr1_label2), "");
    gtk_label_set_text(GTK_LABEL(gr1_label3), "");

    Ouvrir(&F, F_LnonOF, 'A');

    i = entete(F, 1);

    if(i == 0)
    {
        gtk_label_set_text(GTK_LABEL(error_label), "Le fichier est vide ");
    }
    else
    {
        LireDir(F, i, &buf_general); premiere_fois = 0;

        sprintf(str_nb, "/num du bloc precedent: %d/", buf_general.precedent);
        snb = g_locale_to_utf8 (str_nb, -1, NULL, NULL, NULL);
        gtk_label_set_text(GTK_LABEL(gr1_label1), snb);

        sprintf(str_nb, "    /nbr d'enregistrement du bloc: %d/", buf_general.nb);
        snb = g_locale_to_utf8 (str_nb, -1, NULL, NULL, NULL);
        gtk_label_set_text(GTK_LABEL(gr1_label2), snb);

        sprintf(str_nb, "\t/num du bloc suivant: %d/", buf_general.suivant);
        snb = g_locale_to_utf8 (str_nb, -1, NULL, NULL, NULL);
        gtk_label_set_text(GTK_LABEL(gr1_label3), snb);

        sprintf(str_nb, "num du bloc: %d", i);
        snb = g_locale_to_utf8 (str_nb, -1, NULL, NULL, NULL);
        gtk_label_set_text(GTK_LABEL(error_label), snb);

        for (j = 0; j<buf_general.nb; j++)
        {
            if ( buf_general.tab[j].sexe == 1) strcpy(genre, "MASCULIN\n");
            if ( buf_general.tab[j].sexe == 2) strcpy(genre, "FEMININ\n");
            sprintf(str,"\n  %s   %s\n\t%s\n\t%s\t%s\t%d / %d / %d\n\t%s\n\tRegion %d : %s\t%s\t%s\n", buf_general.tab[j].nom, buf_general.tab[j].prenom, buf_general.tab[j].matricule, genre, tab_wilaya[buf_general.tab[j].willaya-1],
                                     buf_general.tab[j].date_de_naissance.jour, buf_general.tab[j].date_de_naissance.mois, buf_general.tab[j].date_de_naissance.an,
                                     tab_grp_sang[buf_general.tab[j].grp_sang-1],buf_general.tab[j].region, tab_region[buf_general.tab[j].region-1], tab_force[buf_general.tab[j].force-1], tab_grade[buf_general.tab[j].grade-1]);
            donnee = g_locale_to_utf8 (str, -1, NULL, NULL, NULL);

            tab_propo[iLAB_propos] = gtk_label_new("Lb");
            gtk_misc_set_alignment(tab_propo[iLAB_propos], 0, 0);
            gtk_label_set_text(GTK_LABEL(tab_propo[iLAB_propos]), donnee);

            context = gtk_widget_get_style_context(GTK_WIDGET(tab_propo[iLAB_propos]));
            gtk_style_context_add_class(context, "labbox3");


            gtk_box_pack_start(GTK_BOX(tab_Gpropo[iGTK3]),tab_propo[iLAB_propos],0,0,0);
            iLAB_propos++;

            while (gtk_events_pending()) gtk_main_iteration();
            gtk_widget_show_all(propo);
        }
    }
    Fermer(F);

}

/************************ cette fonction affiche sur ecran tout les widgets de la fenetre a propos **********************/


void window_propo(GtkWidget *widget, gpointer data)
{
    char str[256]; fichier F; gchar *donnee;
    builder = gtk_builder_new_from_file("project.glade");
    propo = GTK_WIDGET(gtk_builder_get_object(builder, "propos"));
    gtk_window_set_default_size(GTK_WINDOW(propo), 4100, 700);
    gtk_window_set_position(GTK_WINDOW(window1),GTK_WIN_POS_CENTER);


    propo_fixed = GTK_WIDGET(gtk_builder_get_object(builder, "propo_fixed"));
    imgaide1 = GTK_WIDGET(gtk_builder_get_object(builder, "imgaide"));
    scrl1 = GTK_WIDGET(gtk_builder_get_object(builder, "scrl1"));
    view1 = GTK_WIDGET(gtk_builder_get_object(builder, "view1"));
    gr1_label1 = GTK_WIDGET(gtk_builder_get_object(builder, "prec"));
    gr1_label2 = GTK_WIDGET(gtk_builder_get_object(builder, "nb"));
    gr1_label3 = GTK_WIDGET(gtk_builder_get_object(builder, "suivant"));
    titre = GTK_WIDGET(gtk_builder_get_object(builder, "titre"));
    text = GTK_WIDGET(gtk_builder_get_object(builder, "text"));
    num_bloc1 = GTK_WIDGET(gtk_builder_get_object(builder, "num_bloc1"));
    error_label = GTK_WIDGET(gtk_builder_get_object(builder, "error_label"));
    propo_button1 = GTK_WIDGET(gtk_builder_get_object(builder, "propo_button1"));
    propo_button2 = GTK_WIDGET(gtk_builder_get_object(builder, "propos_button2"));
    propo_button3 = GTK_WIDGET(gtk_builder_get_object(builder, "propos_button3"));
    exp1 = GTK_WIDGET(gtk_builder_get_object(builder, "exp1"));
    exp1_label1 = GTK_WIDGET(gtk_builder_get_object(builder, "exp1_label1"));
    exp1_label2 = GTK_WIDGET(gtk_builder_get_object(builder, "exp1_label2"));
    exp2 = GTK_WIDGET(gtk_builder_get_object(builder, "exp2"));
    exp2_label1 = GTK_WIDGET(gtk_builder_get_object(builder, "exp2_label1"));
    exp2_label2 = GTK_WIDGET(gtk_builder_get_object(builder, "exp2_label2"));
    Ouvrir(&F, F_LnonOF, 'A');
    sprintf(str, "\nNum de premier bloc : %d\nNum de dernier bloc: %d\nNbr d'enregistrement: %d\nNbr de blocs : %d", entete(F, 1),
            entete(F, 2), entete(F, 3), entete(F, 4));
    donnee = g_locale_to_utf8 (str, -1, NULL, NULL, NULL);
    gtk_label_set_text(GTK_LABEL(exp1_label2), donnee);
    Fermer(F);

    sprintf(str, "\nNbr de lectures disque : %d\nNbr d'écriture disque: %d\nCout total: %d", nb_liredir, nb_ecriredir, nb_liredir+nb_ecriredir);
    donnee = g_locale_to_utf8 (str, -1, NULL, NULL, NULL);
    gtk_label_set_text(GTK_LABEL(exp2_label2), donnee);

    tab_Gpropo[iGTK3] = gtk_vbox_new (TRUE,5);

    gtk_container_add(GTK_CONTAINER(view1),GTK_WIDGET(tab_Gpropo[iGTK3]));

    g_signal_connect(propo_button1, "clicked", G_CALLBACK(consulter), NULL);
    g_signal_connect(propo_button2, "clicked", G_CALLBACK(bloc_precedent), NULL);
    g_signal_connect(propo_button3, "clicked", G_CALLBACK(bloc_suivant), NULL);


    gtk_widget_show_all(propo);


}

/*********************** le programme principale *****************/


int main(int *argc, int **argv)
{

    GtkStyleContext *context;  /******* cette variable est utilisée par les fonctionnalité du CSS  ***/

    gtk_init(&argc, &argv);

    load_css();      /***** chargement du fichier du CSS ****/

    builder = gtk_builder_new_from_file("project.glade");


    int x, p, choix, reussi, echec, trouv, i, j, cpt, a_min, a_max, grade_min, grade_max;
    fichier F; tbloc buf;
    fichier_index Fich;  tbloc_index_mat bufi;
    tenr_index_mat *tab_m;
    tenr_index_mat *tab;
    char matricule[7];


    FILE *f;


    charg_groupe_sang();
    charg_wilaya();
    charg_force();
    charg_grade();
    charg_region();



    Creer_liste(Lb_vide, &t_vide_actif);
    Creer_liste(Lb_vide_arch, &t_vide_archive);


    f = fopen("premiere_fois.txt", "r");
    fscanf(f, "%d", &p);
    fclose(f);

    if (p == 0)    /******************** si le fichier personnel n'est pas creer, il va etre creé est epuré *****/
    {
        dialog0 = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
        gtk_window_set_default_size(GTK_WINDOW(dialog0), 490, 300);




        lab = GTK_WIDGET(gtk_builder_get_object(builder, "label"));
        progress0 = GTK_WIDGET(gtk_builder_get_object(builder, "progress"));



        gtk_window_set_position(GTK_WINDOW(dialog0),GTK_WIN_POS_CENTER);

        context = gtk_widget_get_style_context(GTK_WIDGET(dialog0));
        gtk_style_context_add_class(context, "wind");

        context = gtk_widget_get_style_context(GTK_WIDGET(lab));
        gtk_style_context_add_class(context, "label");


        x = 300000;

        tab = malloc (x*sizeof(tenr_index_mat));
        charg_init(F_LnonOF, x, tab);
        epuration(F_LnonOF, tab, x);
        free(tab);
        tab_m = malloc(x*sizeof(tenr_index_mat));
        index_NONdense = malloc(x*sizeof(tenr_index_mat));
        charg_index_mat(F_LnonOF, tab_m, &taille_m);
        Creer_index_mat(F_indx_mat, tab_m, taille_m);
        free(tab_m);

        f = fopen("premiere_fois.txt", "w");
        fprintf(f,"1");
        fclose(f);
        Creer_archive(F_arch);
        frag_init("Fichier1.bin", "Fichier2.bin", "Fichier3.bin", "Fichier4.bin","Fichier5.bin", "Fichier6.bin", "Fichier7.bin", "Fichier8.bin");

        informations_generales();

        gtk_label_set_text(GTK_LABEL(lab), "Fin de chargement");


        gtk_widget_show_all(dialog0);

        gtk_widget_destroy(dialog0);


    }
     else    /****************  si le fichier du personnel est déja créé en accède directement au fonctionnalité ***********/
    {
        tbloc bufff;
        Ouvrir(&F, F_LnonOF, 'A');
        x = entete(F, 3);


        Fermer(F);

        index_NONdense = malloc(x*sizeof(tenr_index_mat));
        creer_indexNONdense_Mat(F_indx_mat);

        informations_generales();

    }


 /*********************************** affichage window 1*****************************/

        window1 = GTK_WIDGET(gtk_builder_get_object(builder, "window1"));
        gtk_window_set_default_size(GTK_WINDOW(window1), 4100, 700);
        gtk_window_set_position(GTK_WINDOW(window1),GTK_WIN_POS_CENTER);
        gtk_window_maximize (GTK_WINDOW(window1));


        context = gtk_widget_get_style_context(GTK_WIDGET(window1));
        gtk_style_context_add_class(context, "window1");

        button0 = GTK_WIDGET(gtk_builder_get_object(builder, "button0"));

        context = gtk_widget_get_style_context(GTK_WIDGET(button0));
        gtk_style_context_add_class(context, "button0");


        image0 = GTK_WIDGET(gtk_builder_get_object(builder, "image0"));
        Apropos = GTK_WIDGET(gtk_builder_get_object(builder, "Apropos"));
        developpers = GTK_WIDGET(gtk_builder_get_object(builder, "developers"));

        context = gtk_widget_get_style_context(GTK_WIDGET(developpers));
        gtk_style_context_add_class(context, "developpers");

        context = gtk_widget_get_style_context(GTK_WIDGET(Apropos));
        gtk_style_context_add_class(context, "Apropos");

        g_signal_connect(button0, "clicked", G_CALLBACK(window_principale), NULL);
        g_signal_connect(Apropos, "clicked", G_CALLBACK(window_propo), NULL);



        gtk_widget_show_all(window1);


/*************************************************************************************/


     gtk_main();

    return 0;

}









