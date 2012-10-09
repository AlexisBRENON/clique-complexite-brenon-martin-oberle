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
int isClique(graphe_l g, EnsembleDeSommet e){
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
//passer e en liste chainee (pb 2eme boucle??)
int isMaximale(graphe_l g, ensembleDeSommet e)
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
//passer e en liste chainee (pb 2eme boucle??)
ensembleDeSommet* getCliqueMaximale(graphe_l g)
{
	ensembleDeSommet* e = (ensembleDeSommet*) malloc(sizeof(int)*g.n);
	sommet x,i;
	liste p;
	int ok;

	for (x=0; x<g.n; x++)
	{
		e[x]=0;
	}
	e[0]=1;
	x=1;
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

		if (ok)
			e[x]=1;
		x++;
	}while(x<g.n && !ok);
	return e;
}
