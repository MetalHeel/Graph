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

#include <cassert>  // assert
#include <utility>  // pair
#include <vector>   // vector
#include <deque>    // deque
#include <algorithm>

using namespace std;

// ---------
// has_cycle
// ---------

/**
 * @param g the graph
 * @param visited vector_descriptor at each index is true if visited and false if not
 * @param v the current vertex we are considering
 * @return true if the passed in graph has a cycle
 */
template <typename G>
bool cycle_found(const G& g, vector<bool>& visited, const typename G::vertex_descriptor& v)
{
    if(visited[v])
        return true;
    else
    {
        visited[v] = true;
        pair<typename G::adjacency_iterator, typename G::adjacency_iterator> adjacent = adjacent_vertices(v, g);
        typename G::adjacency_iterator b = adjacent.first;
        typename G::adjacency_iterator e = adjacent.second;
        while(b != e)
        {
            if(cycle_found(g, visited, *b))
                return true;
            b++;
        }
    }

    visited[v] = false;
    return false;
}

/**
 * depth-first traversal
 * three colors
 * @param g the graph
 * @return true if the passed in graph has a cycle
 */
template <typename G>
bool has_cycle (const G& g) {
    pair<typename G::vertex_iterator, typename G::vertex_iterator> verts = vertices(g);
    typename G::vertex_iterator b = verts.first;
    typename G::vertex_iterator e = verts.second;
    vector<bool> vis(num_vertices(g), false);

    while(b != e)
    {
        if(cycle_found(g, vis, *b))
            return true;
        b++;
    }
    return false;}

// ----------------
// topological_sort
// ----------------

/**
 * @param g the graph
 * @param v the current vertex we are considering
 * @param visited vector_descriptor at each index is true if visited and false if not
 * @param sorted a sorted list of the visited vertexes
 * topologically sorts the graph and outputs the ordering in sorted
 * Precondition: !has_cycle(g)
 */
template <typename G>
void visit(const G& g, const typename G::vertex_descriptor& v, vector<bool>& visited, deque<typename G::vertex_descriptor>& sorted)
{
    if(!visited[v])
    {
        visited[v] = true;
        pair<typename G::adjacency_iterator, typename G::adjacency_iterator> adjacent = adjacent_vertices(v, g);
        typename G::adjacency_iterator b = adjacent.first;
        typename G::adjacency_iterator e = adjacent.second;
        while(b != e)
        {
            visit(g, *b, visited, sorted);
            b++;
        }
        sorted.push_front(v);
    }
}


/**
 * depth-first traversal
 * two colors
 * @param g the graph
 * @param x the output iterator where the sorted vetices will go
 * topologically sorts the graph and outputs the ordering in x
 * Precondition: !has_cycle(g)
 */
template <typename G, typename OI>
void topological_sort (const G& g, OI x) {
    //assert(!has_cycle(g));

    pair<typename G::vertex_iterator, typename G::vertex_iterator> Gvertices = vertices(g);   //list of all verticies in the graph
    pair<typename G::edge_iterator,   typename G::edge_iterator>   Gedges    = edges(g);      //list of all edges in the graph
    deque<typename G::vertex_descriptor> roots;                                                    //set of all verticies with no incomming edges
    vector<bool> vis(num_vertices(g), false);
    deque<typename G::vertex_descriptor> sort;

    typename G::vertex_iterator bvert = Gvertices.first;
    typename G::vertex_iterator evert = Gvertices.second;
    typename G::edge_iterator bedge   = Gedges.first;
    typename G::edge_iterator eedge   = Gedges.second;

    //fill roots with all of the vertex descriptors from the graph
    //copy(bvert, evert, roots.begin(), roots.end());
    while(bvert != evert)
    {
        roots.push_back(*bvert);
        bvert++;
    }

    //go through and remove all of the verticies with incomming edges
    while(bedge != eedge)
    {
        if(find(roots.begin(), roots.end(), target(*bedge, g)) != roots.end())
            roots.erase(find(roots.begin(), roots.end(), target(*bedge, g)));
        bedge++;
    }

    for(int i = 0; i < (int)roots.size(); i++)
        visit(g, roots[i], vis, sort);

    for(int i = 0; i < (int)sort.size(); i++)
    {
        *x = sort[i];
        x++;
    }
}

#endif // GraphAlgorithms_h
