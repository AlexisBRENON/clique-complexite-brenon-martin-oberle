#ifndef __CLIQUE_H__
#define __CLIQUE_H__

#include "graphe.h"

/**
  * @typedef EnsembleDeSommets
  * @brief Représente un ensemble de sommet via une liste chainée
  */
typedef liste EnsembleDeSommets;

/**
  * @fn int isClique (graphe_l g, EnsembleDeSommets E);
  * @brief Teste si E est une clique de g.
  *
  * @param g Graphe
  * @param E Ensemble de sommet à tester
  * @return 1 si E est une clique de g, 0 sinon.
  */
int isClique (graphe_l g, EnsembleDeSommets E);

/**
  * @fn int isMaximale (graphe_l g, EnsembleDeSommets E);
  * @brief Teste si E est une clique maximale de g.
  *
  * @param g Graphe
  * @param E Ensemble de sommet à tester
  * @return 1 si E est une clique maximale, 0 sinon
  */
int isMaximale (graphe_l g, EnsembleDeSommets E);

/**
  * @fn EnsembleDeSommets* getCliqueMaximale (graphe_l g);
  * @brief Calcule une clique maximale de g.
  *
  * @param g Graphe
  * @return L'ensemble des sommets formant une clique maximale.
  */
EnsembleDeSommets* getCliqueMaximale (graphe_l g);

/**
  * @fn EnsembleDeSommets getCliqueMaximum (graphe_l g);
  * @brief Calcule une clique maximum de g.
  *
  * @param g Graphe
  * @return L'ensemble des sommets formant une clique maximum
  */
EnsembleDeSommets getCliqueMaximum (graphe_l g);

#endif /* __CLIQUE_H__ */
