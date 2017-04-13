#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "compte.h"

int main(int nbArgs, char *args[])
{
  float temps = clock();
  srand((unsigned int)time(NULL)); // Initialise la fonction rand

  if((nbArgs > 1) && (args[1] = "-t"))
  compter(1); // Si -t est en parametre, on envoi 1 en argument
  else compter(0); // sinon 0

  temps = ((clock() - temps) / CLOCKS_PER_SEC);
  printf("temps ecoule : environ %.1f seconde(s)\n", temps); // Affiche le temps écoulé

  return EXIT_SUCCESS;
}

