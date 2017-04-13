#ifndef _PILE_
#define _PILE_

#include "SP.h"

typedef struct boite *Pile;

Pile creerPile(SP*);

int estVide(Pile);

void empiler(Pile*, SP*);
SP* depiler(Pile*);
SP* sommet(Pile);

void vider(Pile*);

#endif
