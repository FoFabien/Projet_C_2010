#ifndef __DEFINITION__
#define __DEFINITION__

#include <stdlib.h> // Les includes qui sont les plus utilisés
#include <stdio.h>
#include <malloc.h>

enum{ // Enumération pour les opérateurs
    PLUS = -4,
    MOINS = -3,
    FOIS = -2,
    DIVISER = -1
  };

#define NUM_MAX 1000 // Nombre maximal à trouvé
#define NUM_MIN 100 // Nombre minimal à trouvé
#define MAX_SIGNED_INT_32 0x7FFFFFFF // Valeur maximale d'un entier non signé, on aurait pu utiliser limits.h

#endif
