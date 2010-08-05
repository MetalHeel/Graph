// ----------------------
// projects/graph/Graph.h
// Copyright (C) 2010
// Glenn P. Downing
// ----------------------

#ifndef Graph_h
#define Graph_h

// --------
// includes
// --------

#include <cassert> // assert
#include <cstddef> // size_t
#include <utility> // make_pair, pair
#include <vector>  // vector
#include <deque>  // deque
#include <algorithm>

using namespace std;

// -----
// Graph
// -----



class Graph {
    public:
        // --------
        // typedefs
        // --------

        typedef int vertex_descriptor;          // fix!
        typedef pair<vertex_descriptor, vertex_descriptor> edge_descriptor;            // fix!

        typedef int* vertex_iterator;           // fix!
        typedef pair<vertex_descriptor, vertex_descriptor>* edge_iterator;             // fix!
        typedef int* adjacency_iterator;        // fix!

        typedef size_t vertices_size_type;
        typedef size_t edges_size_type;

    public:
        // --------
        // add_edge
        // --------

        /**
         * <your documentation>
         */
        friend pair<edge_descriptor, bool> add_edge (vertex_descriptor vone, vertex_descriptor vtwo, Graph& theGraph) {
            
            edge_descriptor thisEdge;
            bool success = false;

            /*if((deque(*v1)).end() == find((deque(*v1)).begin(), (deque(*v1)).end(), v2)) //if the edge does not already exist
            {
                (deque(*v1)).push_back(v2);
                success = true;
            }
            else                                              //if the edge does already exist
            {
              thisEdge = make_pair(v1, v2);
            }*/
            return make_pair(thisEdge, success);}

        // ----------
        // add_vertex
        // ----------

        /**
         * <your documentation>
         */
        friend vertex_descriptor add_vertex (Graph& theGraph) {
            vertex_descriptor vd;
            //deque* searchResult = &(*find(theGraph.g.begin(), theGraph.g.end(), 0));
            //theGraph.g.push_back(deque<vertex_descriptor>());
            //return (vertex_descriptor)&theGraph.g.back();}
            return vd;}

        // -----------------
        // adjacent_vertices
        // -----------------

        /**
         * <your documentation>
         */
        friend pair<adjacency_iterator, adjacency_iterator> adjacent_vertices (vertex_descriptor, const Graph&) {
            // <your code>
            adjacency_iterator b = adjacency_iterator();
            adjacency_iterator e = adjacency_iterator();
            return make_pair(b, e);}

        // ----
        // edge
        // ----

        /**
         * <your documentation>
         */
        friend pair<edge_descriptor, bool> edge (vertex_descriptor, vertex_descriptor, const Graph&) {
            // <your code>
            edge_descriptor ed;
            bool            b;
            return make_pair(ed, b);}

        // -----
        // edges
        // -----

        /**
         * O(1) in space
         * O(1) in time
         * <your documentation>
         */
        friend pair<edge_iterator, edge_iterator> edges (const Graph&) {
            // <your code>
            edge_iterator b;
            edge_iterator e;
            return make_pair(b, e);}

        // ---------
        // num_edges
        // ---------

        /**
         * <your documentation>
         */
        friend edges_size_type num_edges (const Graph&) {
            // <your code>
            edges_size_type s;
            return s;}

        // ------------
        // num_vertices
        // ------------

        /**
         * <your documentation>
         */
        friend vertices_size_type num_vertices (const Graph&) {
            // <your code>
            vertices_size_type s;
            return s;}

        // ------
        // source
        // ------

        /**
         * <your documentation>
         */
        friend vertex_descriptor source (edge_descriptor, const Graph&) {
            // <your code>
            vertex_descriptor v;
            return v;}

        // ------
        // target
        // ------

        /**
         * <your documentation>
         */
        friend vertex_descriptor target (edge_descriptor, const Graph&) {
            // <your code>
            vertex_descriptor v;
            return v;}

        // ------
        // vertex
        // ------

        /**
         * <your documentation>
         */
        friend vertex_descriptor vertex (vertices_size_type, const Graph&) {
            // <your code>
            vertex_descriptor vd;
            return vd;}

        // --------
        // vertices
        // --------

        /**
         * <your documentation>
         */
        friend pair<vertex_iterator, vertex_iterator> vertices (const Graph&) {
            // <your code>
            vertex_iterator b = vertex_iterator();
            vertex_iterator e = vertex_iterator();
            return make_pair(b, e);}

    private:
        // ----
        // data
        // ----

        deque<deque <vertex_descriptor> > g; // something like this

        // -----
        // valid
        // -----

        /**
         * <your documentation>
         */
        bool valid () const {
            // <your code>
            return true;}

    public:
        // ------------
        // constructors
        // ------------

        /**
         * <your documentation>
         */
        Graph () {
            assert(valid());}

        // Default copy, destructor, and copy assignment
        // Graph  (const Graph<T>&);
        // ~Graph ();
        // Graph& operator = (const Graph&);
    };

#endif // Graph_h