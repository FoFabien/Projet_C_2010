#ifndef _PAIRE_

#include "arbre.h"

typedef struct association *Paire;

Paire creerPaire(int);
Paire* creerTableauPaire(int);
Paire combiner(Paire, Paire, int);
int getElement(Paire);
void chercherHistoDansPaire(Paire);

#define _PAIRE__

#endif
