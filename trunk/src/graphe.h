#ifndef STRUCT_H
#define STRUCT_H
#define n_max 10 /*nombre maximum de sommets*/
typedef int sommet; /*indices des sommets*/

/*representation par matrice d'adjacence*/
typedef struct
{ 
	int a[n_max][n_max]; /*matrice carre representant les valeurs de c entre 2sommets*/
	int circ[n_max][n_max]; /*matrice carre representant les valeurs circ entre 2sommets*/
	int n; /*valeur comprise en 0 et n_max. C'est le nombre de sommets du graphe*/
} graphe_m;

graphe_m gm;

/*représentation par listes d'adjacence*/
typedef struct chainon
{
	sommet st; /*indice de sommet de 0 à n_max-1*/
	int c;
	int circ;
	struct chainon *suivant;
} Couple;

typedef Couple *liste;

typedef struct
{
	liste a[n_max]; /*tableau de liste*/
	int n; /*valeur comprise entre 0 et n_max. C'est le nombre de sommets du graphe*/
} graphe_l;

graphe_l gl;


typedef struct pfile
{
	sommet st;
	struct pfile *suivant;
} ppfile;

typedef ppfile *Pfile;

#endif
