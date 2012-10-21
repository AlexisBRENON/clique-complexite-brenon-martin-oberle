#include <stdio.h>
#include <stdlib.h>

#include "graphe.h"
#include "clique.h"

int main (int argc, char* argv[])
{
    if (argc < 2)
    {
        fprintf(stderr,
            "Usage : %s <filename>\n",
            argv[0]);
        return EXIT_FAILURE;
    }

    graphe_l *g = loadFromFile(argv[1]);
    if (g == NULL) {return EXIT_FAILURE;}
    dispGraphe(*g);

    int loop = 1;
    int choice = 0;
    EnsembleDeSommets e = NULL;
    int i = 0;
    int starting = 0;

	while (loop == 1)
	{
		printf("Que voulez-vous faire ?\n");
		printf("\t1 : Clique Maximale\n");
		printf("\t2 : Clique Maximale Contenant...\n");
		printf("\t3 : Clique Maximum (calcul incomplet)\n");
		printf("\t4 : Clique Maximum (calcul complet)\n");
		printf("\t9 : Quitter\n");
		printf("  -> ");
		scanf("%d", &choice);
		switch (choice)
		{
			case 1:
				e = getCliqueMaximale(*g);
				printf ("Une clique maximale est composée de :\n\t{ ");
				for (i = 0; i < g->n; i++)
				{
					if (e[i] == 1)
					{
						printf("%d ", i);
					}
				}
				printf("}\n");
				free(e);
				break;
			case 2:
                printf("Quel sommet ?\n  -> ");
                scanf("%d", &starting);
				e = getCliqueMaximaleFromSt(*g, starting);
				printf ("Une clique maximale est composée de :\n\t{ ");
				for (i = 0; i < g->n; i++)
				{
					if (e[i] == 1)
					{
						printf("%d ", i);
					}
				}
				printf("}\n");
				free(e);
				break;
			case 3:
				e = getCliqueMaximumInc(*g);
				printf ("La clique maximum est supposée être :\n\t{ ");
				for (i = 0; i < g->n; i++)
				{
					if (e[i] == 1)
					{
						printf("%d ", i);
					}
				}
				printf("}\n");
				free(e);
				break;
			case 4:
				e = getCliqueMaximumFull(*g);
				printf ("La clique maximum est :\n\t{ ");
				for (i = 0; i < g->n; i++)
				{
					if (e[i] == 1)
					{
						printf("%d ", i);
					}
				}
				printf("}\n");
				free(e);
				break;
			case 9:
				loop = 0;
				printf("Au revoir\n");
				break;
			default:
				break;
		}
	}

    destroyGraphe(&g);
    return EXIT_SUCCESS;
}
