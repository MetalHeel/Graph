// ----------------------------
// projects/graph/TestGraph.c++
// Copyright (C) 2010
// Glenn P. Downing
// ----------------------------

/*
To test the program:
    % g++ -ansi -pedantic -I/public/linux/include/boost-1_38 -lcppunit -ldl -Wall TestGraph.c++ -o TestGraph.app
    % valgrind TestGraph.app >& TestGraph.c++.out
*/

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <iterator> // ostream_iterator
#include <sstream>  // ostringstream
#include <utility>  // pair

#include "boost/graph/adjacency_list.hpp" // adjacency_list

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TestSuite.h"               // TestSuite
#include "cppunit/TextTestRunner.h"          // TestRunner

#include "Graph.h"
#include "GraphAlgorithms.h"

// ---------
// TestGraph
// ---------

template <typename T>
struct TestGraph : CppUnit::TestFixture {
    // --------
    // typedefs
    // --------

    typedef T                                       graph_type;

    typedef typename graph_type::vertex_descriptor  vertex_descriptor;
    typedef typename graph_type::edge_descriptor    edge_descriptor;

    typedef typename graph_type::vertex_iterator    vertex_iterator;
    typedef typename graph_type::edge_iterator      edge_iterator;
    typedef typename graph_type::adjacency_iterator adjacency_iterator;

    typedef typename graph_type::vertices_size_type vertices_size_type;
    typedef typename graph_type::edges_size_type    edges_size_type;

    // -----
    // tests
    // -----

    graph_type g;

    vertex_descriptor vdA;
    vertex_descriptor vdB;
    vertex_descriptor vdC;
    vertex_descriptor vdD;
    vertex_descriptor vdE;
    vertex_descriptor vdF;
    vertex_descriptor vdG;
    vertex_descriptor vdH;

    edge_descriptor edAB;
    edge_descriptor edAC;
    edge_descriptor edAE;
    edge_descriptor edBD;
    edge_descriptor edBE;
    edge_descriptor edCD;
    edge_descriptor edDE;
    edge_descriptor edDF;
    edge_descriptor edFD;
    edge_descriptor edFH;
    edge_descriptor edGH;

    graph_type g2;

    vertex_descriptor vdA2;
    vertex_descriptor vdB2;

    edge_descriptor edAB2;
    edge_descriptor edBA2;

    graph_type emptyG;

    // -----
    // setUp
    // -----

    // directed, sparse, unweighted
    // possibly connected
    // possibly cyclic
    // Collins, 2nd, pg. 653
    void setUp () {
        vdA  = add_vertex(g);
        vdB  = add_vertex(g);
        vdC  = add_vertex(g);
        vdD  = add_vertex(g);
        vdE  = add_vertex(g);
        vdF  = add_vertex(g);
        vdG  = add_vertex(g);
        vdH  = add_vertex(g);
        edAB = add_edge(vdA, vdB, g).first;
        edAC = add_edge(vdA, vdC, g).first;
        edAE = add_edge(vdA, vdE, g).first;
        edBD = add_edge(vdB, vdD, g).first;
        edBE = add_edge(vdB, vdE, g).first;
        edCD = add_edge(vdC, vdD, g).first;
        edDE = add_edge(vdD, vdE, g).first;
        edDF = add_edge(vdD, vdF, g).first;
        //edFD = add_edge(vdF, vdD, g).first;
        edFH = add_edge(vdF, vdH, g).first;
        edGH = add_edge(vdG, vdH, g).first;

        vdA2 = add_vertex(g2);
        vdB2 = add_vertex(g2);
        edAB2 = add_edge(vdA2, vdB2, g2).first;
        edBA2 = add_edge(vdB2, vdA2, g2).first;}

    // -------------
    // test_add_edge
    // -------------

    void test_add_edge () {
        std::pair<edge_descriptor, bool> p = add_edge(vdA, vdB, g);
        CPPUNIT_ASSERT(p.first  == edAB);
        CPPUNIT_ASSERT(p.second == false);}

    void test_add_edge_b1 () {
        std::pair<edge_descriptor, bool> p = add_edge(vdA, vdA, g);
        CPPUNIT_ASSERT(p.second == true);}

    // ----------------------
    // test_adjacent_vertices
    // ----------------------

    void test_adjacent_vertices () {
        std::pair<adjacency_iterator, adjacency_iterator> p = adjacent_vertices(vdA, g);
        adjacency_iterator b = p.first;
        adjacency_iterator e = p.second;
        CPPUNIT_ASSERT(b != e);
        if (b != e) {
            vertex_descriptor vd = *b;
            CPPUNIT_ASSERT(vd == vdB);}
        ++b;
        if (b != e) {
            vertex_descriptor vd = *b;
            CPPUNIT_ASSERT(vd == vdC);}}

    void test_adjacent_vertices_b1 () {
        std::pair<adjacency_iterator, adjacency_iterator> p = adjacent_vertices(vdB, g);
        adjacency_iterator b = p.first;
        adjacency_iterator e = p.second;
        CPPUNIT_ASSERT(b != e);
        if (b != e) {
            vertex_descriptor vd = *b;
            CPPUNIT_ASSERT(vd == vdD);}
        ++b;
        if (b != e) {
            vertex_descriptor vd = *b;
            CPPUNIT_ASSERT(vd == vdE);}}

    void test_adjacent_vertices_b2 () {
        std::pair<adjacency_iterator, adjacency_iterator> p = adjacent_vertices(vdC, g);
        adjacency_iterator b = p.first;
        adjacency_iterator e = p.second;
        CPPUNIT_ASSERT(b != e);
        if (b != e) {
            vertex_descriptor vd = *b;
            CPPUNIT_ASSERT(vd == vdD);}
        ++b;
        CPPUNIT_ASSERT(b == e);}

    void test_adjacent_vertices_b3 () {
        std::pair<adjacency_iterator, adjacency_iterator> p = adjacent_vertices(vdD, g);
        adjacency_iterator b = p.first;
        adjacency_iterator e = p.second;
        CPPUNIT_ASSERT(b != e);
        if (b != e) {
            vertex_descriptor vd = *b;
            CPPUNIT_ASSERT(vd == vdE);}
            ++b;
        if (b != e) {
            vertex_descriptor vd = *b;
            CPPUNIT_ASSERT(vd == vdF);}}

    void test_adjacent_vertices_b4 () {
        std::pair<adjacency_iterator, adjacency_iterator> p = adjacent_vertices(vdE, g);
        adjacency_iterator b = p.first;
        adjacency_iterator e = p.second;
        CPPUNIT_ASSERT(b == e);}

    // ---------
    // test_edge
    // ---------

    void test_edge () {
        std::pair<edge_descriptor, bool> p = edge(vdA, vdB, g);
        CPPUNIT_ASSERT(p.first  == edAB);
        CPPUNIT_ASSERT(p.second == true);}

    void test_edge_b1 () {
        std::pair<edge_descriptor, bool> p = edge(vdE, vdB, g);
        CPPUNIT_ASSERT(p.second == false);}

    void test_edge_b2 () {
        std::pair<edge_descriptor, bool> p = edge(vdA, vdD, g);
        CPPUNIT_ASSERT(p.second == false);}

    void test_edge_k1 () {
        std::pair<edge_descriptor, bool> p = edge(vdB2, vdA2, g2);
        CPPUNIT_ASSERT(p.first == edBA2);
        CPPUNIT_ASSERT(p.second == true);}

    void test_edge_k2 () {
        std::pair<edge_descriptor, bool> p = edge(vdB, vdA2, emptyG);
        CPPUNIT_ASSERT(p.second == false);}

    // ----------
    // test_edges
    // ----------

    void test_edges () {
        std::pair<edge_iterator, edge_iterator> p = edges(g);
        edge_iterator                           b = p.first;
        edge_iterator                           e = p.second;
        CPPUNIT_ASSERT(b != e);
        if (b != e) {
            edge_descriptor ed = *b;
            CPPUNIT_ASSERT(ed == edAB);}
        ++b;
        if (b != e) {
            edge_descriptor ed = *b;
            CPPUNIT_ASSERT(ed == edAC);}}

    void test_edges_b1 () {
        std::pair<edge_iterator, edge_iterator> p = edges(emptyG);
        edge_iterator                           b = p.first;
        edge_iterator                           e = p.second;
        CPPUNIT_ASSERT(b == e);}

    // --------------
    // test_num_edges
    // --------------

    void test_num_edges () {
        edges_size_type es = num_edges(g);
        CPPUNIT_ASSERT(es == 11);}

    void test_num_edges_b1 () {
        edges_size_type es = num_edges(emptyG);
        CPPUNIT_ASSERT(es == 0);}

    // -----------------
    // test_num_vertices
    // -----------------

    void test_num_vertices () {
        vertices_size_type vs = num_vertices(g);
        CPPUNIT_ASSERT(vs == 8);}

    void test_num_vertices_b1 () {
        vertices_size_type vs = num_vertices(emptyG);
        CPPUNIT_ASSERT(vs == 0);}

    // -----------
    // test_source
    // -----------

    void test_source () {
        vertex_descriptor vd = source(edAB, g);
        CPPUNIT_ASSERT(vd == vdA);}

    void test_source_1 () {
        vertex_descriptor vd = source(edAB2, g2);
        CPPUNIT_ASSERT(vd == vdA2);
    
        vertex_descriptor vd1 = source(edBA2, g2);
        CPPUNIT_ASSERT(vd1 == vdB2);}

    // -----------
    // test_target
    // -----------

    void test_target () {
        vertex_descriptor vd = target(edAB, g);
        CPPUNIT_ASSERT(vd == vdB);}

    void test_target_1 () {
        vertex_descriptor vd = target(edAB2, g2);
        CPPUNIT_ASSERT(vd == vdB2);

        vertex_descriptor vd1 = target(edBA2, g2);
        CPPUNIT_ASSERT(vd1 == vdA2);}

    // -----------
    // test_vertex
    // -----------

    void test_vertex () {
        vertex_descriptor vd = vertex(0, g);
        CPPUNIT_ASSERT(vd == vdA);}

    void test_vertex1 () {
        vertex_descriptor vd = vertex(0, emptyG);
        CPPUNIT_ASSERT(vd == vd); // so there are no warnings...
    }

    // -------------
    // test_vertices
    // -------------

    void test_vertices () {
        std::pair<vertex_iterator, vertex_iterator> p = vertices(g);
        vertex_iterator                             b = p.first;
        vertex_iterator                             e = p.second;
        CPPUNIT_ASSERT(b != e);
        if (b != e) {
            vertex_descriptor vd = *b;
            CPPUNIT_ASSERT(vd == vdA);}
        ++b;
        if (b != e) {
            vertex_descriptor vd = *b;
            CPPUNIT_ASSERT(vd == vdB);}}

    void test_vertices_b1 () {
        std::pair<vertex_iterator, vertex_iterator> p = vertices(emptyG);
        vertex_iterator                             b = p.first;
        vertex_iterator                             e = p.second;
        CPPUNIT_ASSERT(b == e);}

    // --------------
    // test_has_cycle
    // --------------

    void test_has_cycle () {
        CPPUNIT_ASSERT(has_cycle(g));}

    // ---------------------
    // test_topological_sort
    // ---------------------

    void test_topological_sort () {
        std::ostringstream out;
        topological_sort(g, std::ostream_iterator<vertex_descriptor>(out, " "));
        std::cout << "test: " << out.str() << std::endl;}

    // ---------------------
    // test_graph2
    // ---------------------

    void test_graph2 () {
        pair<vertex_iterator, vertex_iterator> p = vertices(g2);
        CPPUNIT_ASSERT(*p.first == vdA2);
        p.first++;
        CPPUNIT_ASSERT(*p.first == vdB2);
        CPPUNIT_ASSERT(edge(vdA2, vdB2, g2).second);}

    // ---------------------
    // test_assignment
    // ---------------------

    void test_assignment () {
        g2 = g;
        CPPUNIT_ASSERT(num_edges(g) == num_edges(g2));
        CPPUNIT_ASSERT(num_vertices(g) == num_vertices(g2));}

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestGraph);
    /*CPPUNIT_TEST(test_add_edge);
    CPPUNIT_TEST(test_add_edge_b1);
    CPPUNIT_TEST(test_adjacent_vertices);
    CPPUNIT_TEST(test_adjacent_vertices_b1);
    CPPUNIT_TEST(test_adjacent_vertices_b2);
    CPPUNIT_TEST(test_adjacent_vertices_b3);
    CPPUNIT_TEST(test_adjacent_vertices_b4);
    CPPUNIT_TEST(test_edge);
    CPPUNIT_TEST(test_edge_b1);
    CPPUNIT_TEST(test_edge_b2);
    CPPUNIT_TEST(test_edge_k1);
    CPPUNIT_TEST(test_edges);
    CPPUNIT_TEST(test_edges_b1);
    CPPUNIT_TEST(test_num_edges);
    CPPUNIT_TEST(test_num_edges_b1);
    CPPUNIT_TEST(test_num_vertices);
    CPPUNIT_TEST(test_num_vertices_b1);
    CPPUNIT_TEST(test_source);
    CPPUNIT_TEST(test_source_1);
    CPPUNIT_TEST(test_target);
    CPPUNIT_TEST(test_target_1);
    CPPUNIT_TEST(test_vertex);
    CPPUNIT_TEST(test_vertex1);
    CPPUNIT_TEST(test_vertices);
    CPPUNIT_TEST(test_vertices_b1);*/
    CPPUNIT_TEST(test_topological_sort);
    //CPPUNIT_TEST(test_graph2);
    //CPPUNIT_TEST(test_assignment);
    CPPUNIT_TEST_SUITE_END();};


// ----
// main
// ----

int main () {
    using namespace std;
    using namespace boost;

    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O
    cout << "TestGraph.c++" << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest(TestGraph< adjacency_list<setS, vecS, directedS> >::suite());
    tr.addTest(TestGraph<Graph>::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;}
