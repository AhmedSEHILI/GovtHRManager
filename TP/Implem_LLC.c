#include <stdio.h>
#include <stdlib.h>
#include "Headers.h"

void Allouer(ptr *p)
{
    *p = malloc(sizeof(maillon));
}

int valeur(ptr p)
{
    return p->info;
}

void aff_val(ptr p, int val)
{
    p->info = val;
}

void aff_adr(ptr p, ptr q)
{
    p->suivant = q;
}

ptr suivant(ptr p)
{
    return p->suivant;
}
