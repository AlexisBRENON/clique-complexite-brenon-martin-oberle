#include <stdlib.h>
#include <stdio.h>

#include "graphe.h"

/* Déclaration des fonctions "privées" */
/**
  * @fn void grapheAddArc(graphe_l *g, sommet s1, sommet s2);
  * @brief Ajoute l'arc (s1,s2) (et donc (s2,s1)) au graphe g.
  *
  * @param g Le graphe à modifier
  * @param s1 Premier sommet de l'arc
  * @param s2 Second sommet de l'arc
  */
void grapheAddArc(graphe_l *g, sommet s1, sommet s2);

graphe_l* createGraphe(int n)
{
    graphe_l* g = (graphe_l*) malloc(sizeof(graphe_l));
    initGraphe(g, n);
    return g;
}

void initGraphe(graphe_l* g, int n)
{
    int i = 0;

    g->n = n;
    g->a = (liste*) malloc(n*sizeof(liste));

    for (i = 0; i < n; i++)
    {
        g->a[i] = NULL;
    }
}

void releaseGraphe(graphe_l* g)
{
    int i = 0;
    Couple* p = NULL;
    Couple* next = NULL;

    for (i = 0; i < g->n; i++)
    {
        p = g->a[i];
        while (p != NULL) {
            next = p->suivant;
            free(p);
            p = next;
        }
    }
    free(g->a);
    g->n = 0;
}

void destroyGraphe (graphe_l** g)
{
    releaseGraphe(*g);
    free(*g);
    *g = NULL;
}

graphe_l* loadFromFile (char* filename)
{
    int n, m, i;
    sommet s1, s2;
    graphe_l* g = NULL;
    FILE* f = fopen(filename, "r");
    if (f != NULL)
    {
        fscanf(f, "%d %d\n", &n, &m);
        g = createGraphe(n);
        for (i = 0; i < m; i++)
        {
            fscanf(f, "%d %d\n", &s1, &s2);
            grapheAddArc(g, s1, s2);
        }
        fclose(f);
    }
    else
    {
        fprintf(stderr, "Impossible d'ouvrir le fichier '%s'.\n", filename);
    }
    return g;
}

void grapheAddArc(graphe_l *g, sommet s1, sommet s2)
{
    Couple* new1 = (Couple*) malloc(sizeof(Couple));
    new1->st = s2; new1->suivant = g->a[s1];
    g->a[s1] = new1;

    Couple* new2 = (Couple*) malloc(sizeof(Couple));
    new2->st = s1; new2->suivant = g->a[s2];
    g->a[s2] = new2;
}
    

void dispGraphe (graphe_l g)
{
    int i = 0;
    Couple* p = NULL;

    printf("Nombre de sommets : %d\n\n",g.n);

    for (i = 0; i < g.n; i++)
    {
        printf("voisin de %4d : ",i);

        p = g.a[i];
        while (p != NULL)
        {
            printf ("%4d ",p->st);
            p = p->suivant;
        }
        printf ("\n");
    }
}


