#include "definition.h"
#include "paire.h"
#include "arbre.h"

struct association
{
  int element;
  Arbre histo;
};

Paire creerPaire(int elem)
{
  Paire p = malloc(sizeof(struct association));
  p->element = elem;
  p->histo = fusion(elem, NULL, NULL); // on initialise l'historique avec un élément
  return p;
}

Paire* creerTableauPaire(int taille) // créé un tableau de Paire
{
  int i = 0;
  if (taille == 0)
    return NULL;
  Paire* p = malloc(sizeof(Paire) * taille);
  if (p == NULL)
    return NULL;
  for (i = 0; i < taille; i++)
    p[i] = NULL;
  return p;
}

Paire combiner(Paire p1, Paire p2, int operateur)
{
  Paire p3;
  switch (operateur)
  {
  case PLUS:
    p3 = creerPaire(p1->element + p2->element);
    p3->histo = fusion(PLUS, p1->histo, p2->histo);
    break;
  case MOINS:
    p3 = creerPaire(abs(p1->element - p2->element));
    if (p1->element >= p2->element) // si p1 > p2, le resultat est positif
      p3->histo = fusion(MOINS, p1->histo, p2->histo); // donc on met dans l'arbre p1 puis p2
    else p3->histo = fusion(MOINS, p2->histo, p1->histo); // sinon p2 puis p1 (l'ordre a une importance)
    break;
  case FOIS:
    p3 = creerPaire(p1->element * p2->element);
    p3->histo = fusion(FOIS, p1->histo, p2->histo);
    break;
  case DIVISER:
    if ((p1->element >= p2->element) && (p2->element != 0) && (p1->element % p2->element == 0)) // On verifie qu'on ne fait pas une division par 0
    {
        p3 = creerPaire(p1->element / p2->element);
        p3->histo = fusion(PLUS, p1->histo, p2->histo); // Meme principe que pour la soustraction
    }
    else if ((p1->element < p2->element) && (p1->element != 0) && (p2->element % p1->element == 0))
    {
        p3 = creerPaire(p2->element / p1->element);
        p3->histo = fusion(DIVISER, p2->histo, p1->histo); // Meme principe que pour la soustraction
    }
    else return NULL; // NULL est retourne en cas de division par 0
    break;
  default:
    return NULL; // ou d'un operateur mauvais en parametre
  }
  return p3;
}

int getElement(Paire p)
{
  if (p == NULL)
    return -1;
  return p->element;
}

void chercherHistoDansPaire(Paire p)
{
  affichage(p->histo);
}
