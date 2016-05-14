#include "catch.hpp"

#include "../pml/directed_graph.hpp"

const char* dg_tag = "[directed graph]";

TEST_CASE("validate directed_graph", dg_tag)
{
    directed_graph<unsigned> graph;
    REQUIRE(graph.vertices().size() == 0);

    graph.add_vertex(1);
    graph.add_vertex(2);
    graph.add_vertex(3);
    graph.add_edge(0, 1);
    graph.add_edge(1, 2);

    REQUIRE(graph.vertices().size() == 3);
    REQUIRE(graph.edges(0).size() == 1);
    REQUIRE(graph.edges(2).size() == 0);
    REQUIRE(graph.vertex(1) == 2);

    graph.clear_edge(1);
    REQUIRE(graph.edges(1).size() == 0);
    graph.clear_edges();
    REQUIRE(graph.edges(0).size() == 0);
}

