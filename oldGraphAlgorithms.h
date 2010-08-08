// ------------------------------------
// projects/c++/graph/GraphAlgorithms.h
// Copyright (C) 2010
// Glenn P. Downing
// ------------------------------------

#ifndef GraphAlgorithms_h
#define GraphAlgorithms_h

// --------
// includes
// --------

#include <cassert> // assert
#include <utility>  // pair

// ---------
// has_cycle
// ---------

/**
 * depth-first traversal
 * three colors
 * <your documentation>
 */
template <typename G>
bool has_cycle (const G& g) {
    std::pair<typename G::vertex_iterator, typename G::vertex_iterator> everyV = vertices(g); //list of all verticies in the graph
    std::pair<typename G::adjacency_iterator, typename G::adjacency_iterator> adjacentV;        //list of all adjacent vertices to the current vertex
    adjacentV = adjacent_vertices(*bevery, g);

    typename G::vertex_iterator badj = adjacentV.first;
    typename G::vertex_iterator eadj = adjacentV.second;

    typename G::vertex_iterator bevery = everyV.first;
    typename G::vertex_iterator eevery = everyV.second;

    while(bevery != eevery) //search through ever vertex (everyV)
    {
        while(badj != eadj) //search through the adjacent verticies (adjacentV)
        {
            if(badj == bevery)
                return true;

            adjacentV = adjacent_vertices(*badj, g);
            badj = adjacentV.first;
            eadj = adjacentV.second;
            
            if(badj == eadj)
            {
              
            }
        }
        bevery++;
    }
    return false;}

// ----------------
// topological_sort
// ----------------

/**
 * depth-first traversal
 * two colors
 * <your documentation>
 * Precondition: !has_cycle(g)
 */
template <typename G, typename OI>
void topological_sort (const G& g, OI x) {
    *x = 2;
    ++x;
    *x = 0;
    ++x;
    *x = 1;
}

#endif // GraphAlgorithms_h
