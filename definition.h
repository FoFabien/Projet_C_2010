#ifndef __DEFINITION__
#define __DEFINITION__

#include <stdlib.h> // Les includes qui sont les plus utilis�s
#include <stdio.h>
#include <malloc.h>

enum{ // Enum�ration pour les op�rateurs
    PLUS = -4,
    MOINS = -3,
    FOIS = -2,
    DIVISER = -1
  };

#define NUM_MAX 1000 // Nombre maximal � trouv�
#define NUM_MIN 100 // Nombre minimal � trouv�
#define MAX_SIGNED_INT_32 0x7FFFFFFF // Valeur maximale d'un entier non sign�, on aurait pu utiliser limits.h

#endif
