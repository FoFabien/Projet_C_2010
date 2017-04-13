#include "definition.h"
#include "pile.h"

struct boite
{
  SP* elem;
  struct boite *precedent;
};

Pile creerPile(SP* premier)
{
  Pile p = malloc(sizeof(struct boite));
  p->elem = premier;
  p->precedent = NULL;
  return p;
}

int estVide(Pile p)
{
  if (p == NULL)
    return 1;
  else return 0;
}

void empiler(Pile *p, SP* elem)
{
  Pile n = malloc(sizeof(struct boite));
  n->elem = elem;
  n->precedent = *p;
  *p = n;
}

SP* depiler(Pile *p)
{
  SP* ret;
  if (*p != NULL)
  {
    ret = (*p)->elem;
    Pile tmp = (*p)->precedent;
    *p = tmp;
    return ret;
  }
  return NULL;
}

void vider(Pile *p)
{
  while (!estVide(*p))
  {
    depiler(p);
  }
}

SP* sommet(Pile p)
{
  SP* ret = NULL;
  if(p != NULL)
    ret = p->elem;
  return ret;
}

