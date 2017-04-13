#ifndef SP_H_INCLUDED
#define SP_H_INCLUDED

typedef struct solP SP;

SP* creerSP(int taille);
SP* creerSP6(void);

int ecart(SP* solution, int entier);
SP* calculerSP(SP* solution,int i, int j, int k);
int getTaille(SP* solution);
void copieSP(SP* original, SP* copie, int ex1, int ex2);

void afficherSP6(SP* sol);
void affichageHistorique(SP* sol);

#endif // SP_H_INCLUDED
