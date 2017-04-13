#include "definition.h"
#include "SP.h"
#include "paire.h"

struct solP
{
  Paire *p;
  int taille;
};

SP* creerSP(int taille) // cr�� un pointeur sur une SP de taille � d�finir par l'utilisateur
{
  SP* solution = malloc(sizeof(SP));
  solution->p = creerTableauPaire(taille);
  solution->taille = taille;
  return solution;
}

SP* creerSP6(void) // cr�� une SP6 avec les 6 nombres al�atoires
{
  int n[24] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10, 25, 50, 75, 100};
  int i = 0, x = 0;
  SP* sol = malloc(sizeof(SP));
  sol->taille = 6;
  sol->p = creerTableauPaire(6);
  do
  {
    x = rand()%24;
    if (n[x] != 0) // voir commentaire ci-dessous
    {
      sol->p[i] = creerPaire(n[x]);
      n[x] = 0; // on met � 0 pour �viter de retomber sur cette case du tableau n (pour ne pas retirer le m�me nombre de la m�me case 2 fois)
      i++;
    }
  }while (i < 6);
  return sol;
}

int ecart(SP* solution, int entier) // Retourne l'�cart entre le r�sultat voulu et le dernier calcul effectu� dans la SP (celui-ci est forc�ment la derni�re Paire de la SP)
{
  int resultat = entier - getElement(solution->p[solution->taille - 1]);
  if (resultat < 0)
    return -resultat;
  else return resultat;
}

SP* calculerSP(SP* solution, int i, int j, int k) // calcule une SP d'ordre n-1
{
  SP* sp;
  Paire tmp;

  if (solution->taille <= 1) // on test que la SP en param�tre est valide
    return NULL;
  tmp = combiner(solution->p[i], solution->p[j], k); // On combine (k correspond � l'op�rateur)
  if (tmp == NULL)
    return NULL; // on v�rifie que �a c'est bien pass�
  sp = creerSP(solution->taille - 1); // si c'est bon, on cr�� une SP
  copieSP(solution, sp, i, j); // on copie les paires non utilis�s dans la nouvelle SP
  sp->p[sp->taille - 1] = tmp; // puis on met la paire qui a �t� obtenue en combinant � la fin des paires de la SP

  return sp;
}

int getTaille(SP* solution)
{
  return solution->taille;
}

void copieSP(SP* original, SP* copie, int ex1, int ex2)
{
  int i = 0, j = 0;
  do
  {
    if (i != ex1 && i != ex2)
    {
      copie->p[j] = original->p[i];
      j++;
    }
    i++;
  }while ((i < original->taille) && (j < copie->taille - 1));
}

void afficherSP6(SP* sol)
{
  int i;
  for (i = 0;i < 6;i++)
    printf("%d ", getElement(sol->p[i]));
}

void affichageHistorique(SP* sol)
{
  chercherHistoDansPaire(sol->p[sol->taille - 1]);
}
