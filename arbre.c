#include "definition.h"
#include "arbre.h"

struct noeud
{
  int element;
  struct noeud *filsGauche;
  struct noeud *filsDroit;
};

Arbre fusion(int op, Arbre g, Arbre d)
{
  Arbre r = malloc(sizeof(struct noeud));
  r->element = op;
  r->filsGauche = g;
  r->filsDroit = d;
  return r;
}

Arbre filsGauche(Arbre a)
{
  return a->filsGauche;
}

Arbre filsDroit(Arbre a)
{
  return a->filsDroit;
}

int filsGaucheExiste(Arbre a)
{
  if (a->filsGauche == NULL)
    return 0;
  else return 1;
}

int filsDroitExiste(Arbre a)
{
  if (a->filsDroit == NULL)
    return 0;
  else return 1;
}

int taille(Arbre a)
{
  return 0;
}

int affichage(Arbre a) // Affichage recursif
{
  int i1 = 0, i2 = 0;
  if (filsGaucheExiste(a))
  {
    i1 = affichage(filsGauche(a));

  }
  if (filsDroitExiste(a))
  {
    i2 = affichage(filsDroit(a));
    printf("%d ", i1);
    switch(a->element)
    {
        case PLUS:printf("+ ");break;
        case MOINS:printf("- ");break;
        case FOIS:printf("* ");break;
        case DIVISER:printf("/ ");break;
    }
    printf("%d = ", i2);
    switch(a->element)
    {
        case PLUS:printf("%d\n", i1 + i2);return i1 + i2;
        case MOINS:printf("%d\n", i1 - i2);return i1 - i2;
        case FOIS:printf("%d\n", i1 * i2);return i1 * i2;
        case DIVISER:printf("%d\n", i1 / i2);return i1 / i2;
    }
  }
  return a->element;
}

