#include "definition.h"
#include "compte.h"
#include "SP.h"

static int resultat; // on aurait pu passer ces int en argument de chaque fonction de compte.c
static int difference; // mémorise l'ecart avec le résultat à trouvé
static int compte; // compte le nombre de SP dans la pile save

void compter(int arg)
{
  resultat = (rand() % (NUM_MAX - NUM_MIN))  + NUM_MIN; // Nombre pseudo-aleatoire entre 100 et 1000
  difference = MAX_SIGNED_INT_32; // On initialise difference au maximum possible
  compte = 0;

  Pile stock = NULL;
  Pile save = NULL;

  init(&stock);
  gestionStock(&stock, &save);
  if (arg == 1)
    affichageComplet(&save); // si -t, affichage complet
  else
  {
    tri(&save); // sinon affichage simple avec tri des SP par complexité
    affichageUne(&save);
  }
}

void init(Pile *stock)
{
  SP *tmp1 = creerSP6(); // On cree la SP6
  printf("\n\t\t\tLE COMPTE EST BON\n\npar Forest Fabien, Gabe Pierre-Emmanuel,\n    Galassi Michelle et Giraud Franck\n\n\nLe nombre a trouve est %d avec ", resultat);
  afficherSP6(tmp1); // On l'affiche
  printf("\nVeuillez patienter quelques secondes...\n\n");
  empiler(stock, tmp1); // Puis on l'empile dans le stock
}

void gestionStock(Pile *stock, Pile *save)
{
  int a, i, j, k;
  SP *tmp1 = NULL, *tmp2 = NULL;

  do
  {
    tmp1 = depiler(stock); // On dépile la SP au sommet
    for (i = 0;i < getTaille(tmp1) - 1; i++)
    {
      for (j = i + 1; j < getTaille(tmp1);j++)
      {
        for (k = PLUS; k < DIVISER + 1; k++)
        {
          tmp2 = calculerSP(tmp1, i, j, k); // on calcule une SP d'ordre n-1
          if (tmp2 != NULL)
          {
            a = ecart(tmp2, resultat);
            if (a == 0) // ecart nul, solution trouvee, on sauvegarde
            {
              if (difference != 0)
              {
                vider(save);
                compte = 0;
              }
              empiler(save, tmp2);
              difference = 0;
              compte++;
            }
            else if (a == difference) // Solution egale a celle(s) deja en stock, on garde dans la sauvegarde
            {
              empiler(save, tmp2);
              compte++;
            }
            else if (a < difference) // Meilleure solution trouvee que celle(s) deja en mémoire
            {
              vider(save);
              empiler(save, tmp2);
              compte = 1;
              difference = a;
            }
            if (getTaille(tmp2) > 1) // Si ce n'est pas une SP1, on la rempile dans le stock (c'est possible de faire mieux ou aussi bien)
              empiler(stock, tmp2);
          }
        }
      }
    }
  }while (!estVide(*stock));
}

void tri(Pile *save)
{
  SP* sTmp;
  Pile p1 = NULL, p2 = NULL; // on utilisera deux autres piles
  int i;
  for (i = 5; i > 0; i--) // on triera les SP par taille, une SP5 étant plus simple à trouver qu'une SP1
  {
    while (!estVide(*save)) // On vide save
    {
      sTmp = sommet(*save);
      if (getTaille(sTmp) == i)
        empiler(&p1, depiler(save)); // dans p1 si la SP a une bonne taille
      else empiler(&p2, depiler(save)); // p2 sinon
    }
    while (!estVide(p2))
      empiler(save, depiler(&p2)); // on empile p2 dans save pour retrier ceux de p2
  }
  while (!estVide(p1))
    empiler(save, depiler(&p1)); // puis on empile le tout dans save à la fin
}

void affichageUne(Pile *save)
{
  if (difference != 0)
    printf("Aucune Solution Trouvee\nAffichage d'une solution proche (%d equivalente(s)) :\n\n", compte - 1);
  else if (difference == 0)
    printf("%d Solution(s) trouvee(s)\nAffichage de la solution la plus simple:\n\n", compte);
  printf("=====================================\n");
  affichageHistorique(sommet(*save));
  printf("=====================================\n\n");
}

void affichageComplet(Pile *save)
{
  if (difference != 0)
    printf("Aucune Solution Trouvee\nAffichage des plus proches :\n\n");
  else if (difference == 0)
    printf("Affichage des solution(s):\n");
  printf("=====================================\n\n");
  do
  {
    affichageHistorique(depiler(save));
    printf("=====================================\n\n");
  }while (!estVide(*save));
  printf("%d Solution(s) trouvee(s)\n", compte);
}
