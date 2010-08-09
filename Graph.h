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

        typedef unsigned long vertex_descriptor;
        typedef pair<vertex_descriptor, vertex_descriptor> edge_descriptor;

        typedef const vertex_descriptor* vertex_iterator;
        typedef const edge_descriptor* edge_iterator;
        typedef const vertex_descriptor* adjacency_iterator;

        typedef size_t vertices_size_type;
        typedef size_t edges_size_type;

    public:
        // --------
        // add_edge
        // --------

        /**
         * @param  vone vertex_descriptor which will become the source of this edge
         * @param  vtwo vertex_descriptor which will become the target of this edge
         * @return pair containing the edge descriptor and a boolean which is true if the edge was successfully created
         */
        friend pair<edge_descriptor, bool> add_edge (vertex_descriptor vone, vertex_descriptor vtwo, Graph& theGraph) {
            edge_descriptor thisEdge = make_pair(vone, vtwo);
            bool success = false;
            if(find(theGraph.g[vone].begin(), theGraph.g[vone].end(), vtwo) == theGraph.g[vone].end())
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
         * Adds a vertex to the passed in graph.
         * @param theGraph
         * @return a vertex_descriptor for the newly created vertex
         */
        friend vertex_descriptor add_vertex (Graph& theGraph) {
            theGraph.g.push_back(vector<vertex_descriptor>());
            theGraph.my_vertices.push_back(theGraph.g.size() - 1);
            return theGraph.g.size() - 1;}

        // -----------------
        // adjacent_vertices
        // -----------------

        /**
         * @param v vertex_descriptor for which the request for adjacent verticies corresponds to
         * @param theGraph
         * @return a pair containing begining and ending iterators to go through all the adjacent vertices to vertex_descriptor v
         */
        friend pair<adjacency_iterator, adjacency_iterator> adjacent_vertices (vertex_descriptor v, const Graph& theGraph) {
            adjacency_iterator b = &*theGraph.g[v].begin();
            adjacency_iterator e = &*theGraph.g[v].end();
            return make_pair(b, e);}

        // ----
        // edge
        // ----

        /**
         * @param vone the source vertex_descriptor of this edge
         * @param vtwo the target vertex_descriptor of this edge
         * @return a pair containing the edge descriptor for this edge and boolean, which is true if it exists
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
         * @param theGraph
         * @return a pair containing beginning and end iterators whose range is all of the edges in theGraph
         */
        friend pair<edge_iterator, edge_iterator> edges (const Graph& theGraph) {
            return make_pair(&*theGraph.my_edges.begin(), &*theGraph.my_edges.end());}

        // ---------
        // num_edges
        // ---------

        /**
         * @param theGraph
         * @return the number of edges in theGraph
         */
        friend edges_size_type num_edges (const Graph& theGraph) {
            return theGraph.my_edges.size();}

        // ------------
        // num_vertices
        // ------------

        /**
         * @param theGraph
         * @return the number of vertices in theGraph.
         */
        friend vertices_size_type num_vertices (const Graph& theGraph) {
            return theGraph.my_vertices.size();}

        // ------
        // source
        // ------

        /**
         * @param ed edge_descriptor for the edge whose source is requested
         * @param theGraph
         * @return a vertex_descriptor for the source of this edge
         */
        friend vertex_descriptor source (edge_descriptor ed, const Graph& theGraph) {
            return ed.first;}

        // ------
        // target
        // ------

        /**
         * @param ed edge_descriptor for the edge whose target is requested
         * @param theGraph
         * @return a vertex_descriptor for the target of this edge
         */
        friend vertex_descriptor target (edge_descriptor ed, const Graph& theGraph) {
            return ed.second;}

        // ------
        // vertex
        // ------

        /**
         * @param vindex the index
         * @param theGraph
         * @return the vertex descriptor being indexed
         */
        friend vertex_descriptor vertex (vertices_size_type vindex, const Graph& theGraph) {
            if(theGraph.my_vertices.size() == 0)
                return 0;
            return theGraph.my_vertices[vindex];}

        // --------
        // vertices
        // --------

        /**
         * @param theGraph
         * @return a pair containing beginning and end iterators whose range is all of the vertices in theGraph
         */
        friend pair<vertex_iterator, vertex_iterator> vertices (const Graph& theGraph) {
            return make_pair(&*theGraph.my_vertices.begin(), &*theGraph.my_vertices.end());}

    private:
        // ----
        // data
        // ----

        vector< vector<vertex_descriptor> > g; //structure relating sources to their targets, and implicitly their edges
        vector<edge_descriptor> my_edges;      //list of all of the edge descriptors
        vector<vertex_descriptor> my_vertices; //list of all of the verticies

        // -----
        // valid
        // -----

        /**
         * @return true if this is a valid graph
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
         * Graph's default constructor.
         */
        Graph () {
            assert(valid());}

        // Default copy, destructor, and copy assignment
        // Graph  (const Graph<T>&);
        // ~Graph ();
        // Graph& operator = (const Graph&);
    };

#endif // Graph_h
