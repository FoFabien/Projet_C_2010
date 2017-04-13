#ifndef ARBRE_H_INCLUDED
#define ARBRE_H_INCLUDED

typedef struct noeud *Arbre;


Arbre fusion(int, Arbre, Arbre);
Arbre filsGauche(Arbre);
Arbre filsDroit(Arbre);
int filsGaucheExiste(Arbre);
int filsDroitExiste(Arbre);

int affichage(Arbre);

#endif
