#include <stdlib.h>
#include <stdio.h>

#include "graphe.h"
#include "clique.h"


//O(n^3)
//passer e en liste chainee (pb 2eme boucle??)
/*int verif_clique(graphe_l g, int e[]){
	sommet x,i;
	liste p;
	int ok;
	x=0; ok=1;
	do{
		if (e[x])
		{
			for (i=x; i<g.n; i++){
				if (e[i])
				{
					p=g.a[x];
					while (p!=null && p->st!=i)
						p=p->suivant;
					ok=(p==null);
				}
			}
		}
		x++;
	}while(x<g.n && ok);
	return ok;
} */

//O(n²)
//passer e en liste chainee (pb 2eme boucle??)
int isClique(graphe_l g, EnsembleDeSommets e){
	sommet x,i;
	liste p;
	int ok;
	x=0; ok=1;
	do{
		if (e[x])
		{
			p=g.a[x];
			e[x]=2;
			while (p!=NULL)
			{
				if (e[p->st] && p->st>x)
					e[p->st]=2;
				p=p->suivant;
			}
			for (i=x; i<g.n; i++){
				if (e[i]==1)
				{
					ok=0;
				}
				else if (e[i]==2)
				{
					e[i]=1;
				}
			}
		}
		x++;
	}while(x<g.n && ok);
	return ok;
}

//O(n²)
int isMaximale(graphe_l g, EnsembleDeSommets e)
{
	sommet x,i;
	liste p;
	int ok;
	x=0;
	do{
		ok=1;
		if (!e[x])
		{
			p=g.a[x];
			while (p!=NULL){
				if (e[p->st])
				{
					e[p->st]=2;
				}
				p=p->suivant;
			}
			for (i=0; i<g.n;i++)
			{
				if (e[i]==1)
				{
					ok=0;
				}
				else if (e[i]==2)
				{
					e[i]=1;
				}
			}
		}

		x++;
	}while(x<g.n && !ok);
	return !ok;
}

//O(n²)
EnsembleDeSommets getCliqueMaximale(graphe_l g)
{
	return getCliqueMaximaleFromSt(g, 0);
}

EnsembleDeSommets getCliqueMaximaleFromSt(graphe_l g, sommet st)
{
	EnsembleDeSommets e = (EnsembleDeSommets) malloc(sizeof(int)*g.n);
	sommet x,i;
	liste p;
	int ok;

	for (x=0; x<g.n; x++)
	{
		e[x]=0;
	}
	e[st] = 1;
	x = (st+1)%g.n;
	do{
		ok=1;
		if (!e[x])
		{
			p=g.a[x];
			while (p!=NULL){
				if (e[p->st])
				{
					e[p->st]=2;
				}
				p=p->suivant;
			}
			i = x;
			do
			{
				if (e[i]==1)
				{
					ok=0;
				}
				else if (e[i]==2)
				{
					e[i]=1;
				}
                i = (i+1)%g.n;
			} while (i != x);
		}

		if (ok)
			e[x]=1;
		x = (x+1)%g.n;
	} while(x!=st);
	return e;
}

EnsembleDeSommets getCliqueMaximumInc (graphe_l g)
{
	/* Résultat des appels à getCliqueMaximum */
	EnsembleDeSommets e = NULL;
	/* Stocke les résultats indexés par leur taille */
	EnsembleDeSommets* results =
		(EnsembleDeSommets*) malloc(sizeof(EnsembleDeSommets)*g.n);
	/* Sommet déja inclus dans une clique et donc à ne pas re-tester */
	EnsembleDeSommets done =
		(EnsembleDeSommets) malloc(sizeof(int)*g.n);

	int i = 0;
	int loop = 1;
	sommet st = 0;
	int ok = 0;

	for (i = 0; i < g.n; i++)
	{
        results[i] = NULL;
		done[i] = 0;
	}

	while (ok == 0)
	{
		e = getCliqueMaximaleFromSt(g, st);
		int counter = 0;
		/* On compte le nombre de sommets présents */
		for (i = 0; i < g.n; i++)
		{
			if (e[i] == 1)
			{
				done[i] = 1;
				counter++;
			}
		}
		/* On sauvegarde la clique actuelle */
		if (results[counter] != NULL)
		{
		    free(results[counter]);
		}
		results[counter] = e;

		loop = 1;
		i = 0;
		while (i < g.n && loop == 1) {
			if (done[i] == 0)
			{
				st = i;
				loop = 0;
			}
			i++;
		}
		if (loop == 1)
		{
			ok = 1;
		}
	}

	/* Désallocation de la mémoire et renvoi du resultat. */
	free(done);
	i = g.n-1;
	while (i >= 0)
	{
		if (results[i] != NULL && loop == 1)
		{
			e = results[i];
			loop = 0;
		}
		else if (results[i] != NULL)
		{
			free(results[i]);
		}
		i--;
	}
	free(results);

	return e;
}

void getCliqueMaximumFullRec (graphe_l g,
                                EnsembleDeSommets cliqueToTest,
                                int size,
                                int currentVertex,
                                EnsembleDeSommets cliqueMax,
                                int* maxSize)
{
    sommet x;

    if (isClique(g, cliqueToTest) == 1)
    {
        if (size > *maxSize)
        {
            for (x = 0; x < g.n; x++)
            {
                cliqueMax[x] = cliqueToTest[x];
            }
            *maxSize = size;
        }
    }
    else if (currentVertex < g.n)
    {
        x = currentVertex;
        while (x < g.n)
        {
            cliqueToTest[x] = 0;
            getCliqueMaximumFullRec(g,
                                    cliqueToTest,
                                    size-1,
                                    x+1,
                                    cliqueMax,
                                    maxSize);
            cliqueToTest[x] = 1;
            x++;
        }
    }
}

EnsembleDeSommets getCliqueMaximumFull (graphe_l g)
{
	EnsembleDeSommets cliqueToTest =
		(EnsembleDeSommets) malloc(sizeof(int)*g.n);
    EnsembleDeSommets cliqueMax =
		(EnsembleDeSommets) malloc(sizeof(int)*g.n);
	int i = 0;
	for (i = 0; i < g.n; i++)
	{
		cliqueToTest[i] = 1;
		cliqueMax[i] = 0;
	}

    int maxSize = 0;
	getCliqueMaximumFullRec(
                        g, /* Graphe à analyser */
                        cliqueToTest,
                        g.n,
                        0,
                        cliqueMax,
                        &maxSize);
    free(cliqueToTest);
	return cliqueMax;
}
