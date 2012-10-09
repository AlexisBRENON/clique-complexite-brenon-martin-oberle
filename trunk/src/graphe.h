#ifndef __GRAPHE_H__
#define __GRAPHE_H__

/**
  * @typedef sommet
  * @brief Représente un sommet par son indice.
  */
typedef int sommet;

/**
  * @struct chainon
  * @brief Element d'une liste.
  */
/**
  * @typedef Couple
  * @brief Un élément et le pointeur vers l'élément suivant.
  */
typedef struct chainon
{
	sommet st; /**< Indice du sommet */
	struct chainon *suivant; /**< Pointeur vers l'élément suivant de la liste. */
} Couple;

/**
  * @typedef liste
  * @brief Une liste est une suite de couple.
  */
typedef Couple *liste;

/**
  * @typedef graphe_l
  * @brief Un graphe est un ensemble de n sommets, dont on liste les voisins.
  */
typedef struct
{
	liste* a; /**< Tableau de voisins de chacun des sommets. */
	int n; /**< Nombre de sommets du graphes. */
} graphe_l;

/**
  * @fn graphe_l* createGraphe(int n);
  * @brief Constructeur de graphe
  *
  * Alloue et initialise un graphe de n noeuds.
  *
  * @param[in] n Nombre de noeuds du graphe
  * @return Un graphe de n noeuds.
  */
graphe_l* createGraphe(int n);

/**
  * @fn void initGraphe(graphe_l* g, int n);
  * @brief Initialise un graphe alloué avec n noeud.
  *
  * @param g Graphe à initialiser
  * @param n Nombre de noeud du graphe
  */
void initGraphe(graphe_l* g, int n);

/**
  * @fn void releaseGraphe(graphe_l* g);
  * @brief Libère la mémoire alloué par le graphe
  *
  * @param g Graphe à libérer
  */
void releaseGraphe(graphe_l* g);

/**
  * @fn void destroyGraphe (graphe_l** g);
  * @brief Désalloue et détruit un graphe
  *
  * @param g Pointeur sur le graphe à désalouer et à détruire
  */
void destroyGraphe (graphe_l** g);

/**
  * @fn graphe_l* loadFromFile (char* filename);
  * @brief Crée et initialise un graphe depuis le fichier filename.
  *
  * @param filename Chemin et nom du fichier contenant la description du graphe
  * @return Un nouveau graphe, alloué et initialisé
  */
graphe_l* loadFromFile (char* filename);

/**
  * @fn void saveToFile (graphe_l g, char* filename);
  * @brief Sauvegarde le graphe g dans le fichier filename.
  *
  * @param g Graphe à sauvegarder
  * @param filename chemin et nom du fichier résultant
  */
void saveToFile (graphe_l g, char* filename);

/**
  * @fn graphe_l* loadFromInput ();
  * @brief Crée un graphe et l'initialise grace à une description saisie sur
l'entrée standard.
  *
  * @return Le nouveau graphe créé
  */
graphe_l* loadFromInput ();

/**
  * @fn void dispGraphe (graphe_l g);
  * @brief Affiche le graphe g
  *
  * @param g Le graphe à afficher
  */
void dispGraphe  (graphe_l g);

/**
  * @fn int existArc(graphe_l g, sommet s1, sommet s2);
  * @brief Teste l'existance d'un arc dans le graphe
  *
  * @param g Graphe à vérfier
  * @param s1 Premier sommet de l'arc
  * @param s2 Second sommet de l'arc
  * @return 1 si l'arc s1-s2 (ou s2-s1) existe, 1 sinon.
  */
int existArc (graphe_l g, sommet s1, sommet s2);

#endif /* __GRAPHE_H__ */
