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

        typedef unsigned long vertex_descriptor;          // fix!
        typedef pair<vertex_descriptor, vertex_descriptor> edge_descriptor;            // fix!

        typedef const vertex_descriptor* vertex_iterator;           // fix!
        typedef const edge_descriptor* edge_iterator;             // fix!
        typedef const vertex_descriptor* adjacency_iterator;        // fix!

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
            edge_descriptor thisEdge = make_pair(vone, vtwo);
            bool success = false;
            if(find(theGraph.g[vone].begin(), theGraph.g[vone].end(), vtwo) == theGraph.g[vone].end() && vone != vtwo)
            {
                theGraph.g[vone].push_back(vtwo);
                theGraph.my_edges.push_back(thisEdge);
                success = true;
            }
            return make_pair(thisEdge, success);}

        // ----------
        // add_vertex
        // ----------

        /**
         * <your documentation>
         */
        friend vertex_descriptor add_vertex (Graph& theGraph) {
            theGraph.g.push_back(vector<vertex_descriptor>());
            theGraph.my_vertices.push_back(theGraph.g.size() - 1);
            return theGraph.g.size() - 1;}

        // -----------------
        // adjacent_vertices
        // -----------------

        /**
         * <your documentation>
         */
        friend pair<adjacency_iterator, adjacency_iterator> adjacent_vertices (vertex_descriptor v, const Graph& theGraph) {
            adjacency_iterator b = &*theGraph.g[v].begin();
            adjacency_iterator e = &*theGraph.g[v].end();
            return make_pair(b, e);}

        // ----
        // edge
        // ----

        /**
         * <your documentation>
         */
        friend pair<edge_descriptor, bool> edge (vertex_descriptor vone, vertex_descriptor vtwo, const Graph& theGraph) {
            edge_descriptor ed = make_pair(vone, vtwo);
            bool success = false;
            if(find(theGraph.g[vone].begin(), theGraph.g[vone].end(), vtwo) != theGraph.g[vone].end())
                success = true;
            return make_pair(ed, success);}

        // -----
        // edges
        // -----

        /**
         * O(1) in space
         * O(1) in time
         * <your documentation>
         */
        friend pair<edge_iterator, edge_iterator> edges (const Graph& theGraph) {
            return make_pair(&*theGraph.my_edges.begin(), &*theGraph.my_edges.end());}

        // ---------
        // num_edges
        // ---------

        /**
         * <your documentation>
         */
        friend edges_size_type num_edges (const Graph& theGraph) {
            return theGraph.my_edges.size();}

        // ------------
        // num_vertices
        // ------------

        /**
         * <your documentation>
         */
        friend vertices_size_type num_vertices (const Graph& theGraph) {
            return theGraph.my_vertices.size();}

        // ------
        // source
        // ------

        /**
         * <your documentation>
         */
        friend vertex_descriptor source (edge_descriptor ed, const Graph& theGraph) {
            return ed.first;}

        // ------
        // target
        // ------

        /**
         * <your documentation>
         */
        friend vertex_descriptor target (edge_descriptor ed, const Graph& theGraph) {
            return ed.second;}

        // ------
        // vertex
        // ------

        /**
         * <your documentation>
         */
        friend vertex_descriptor vertex (vertices_size_type vindex, const Graph& theGraph) {
            if(theGraph.my_vertices.size() == 0)
                return 0;
            return theGraph.my_vertices[vindex];}

        // --------
        // vertices
        // --------

        /**
         * <your documentation>
         */
        friend pair<vertex_iterator, vertex_iterator> vertices (const Graph& theGraph) {
            return make_pair(&*theGraph.my_vertices.begin(), &*theGraph.my_vertices.end());}

    private:
        // ----
        // data
        // ----

        vector< vector<vertex_descriptor> > g;
        vector<edge_descriptor> my_edges;
        vector<vertex_descriptor> my_vertices;

        // -----
        // valid
        // -----

        /**
         * <your documentation>
         */
        bool valid () const {
            if(my_edges.size() == 0 && my_vertices.size() == 0)
                return true;
            for(int x = 0; x < (int)my_edges.size(); x++)
            {
                if(!edge(my_edges[x].first, my_edges[x].second, *this).second)
                  return false;
            }
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
