#include <stdio.h>
#include <stdlib.h>

#include "graphe.h"

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
    dispGraphe(*g);

    return EXIT_SUCCESS;
}
