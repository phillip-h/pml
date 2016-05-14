#include "catch.hpp"

#include "../pml/dijkstra.hpp"

const char* d_tag = "[dijkstra]";

TEST_CASE("validate dijkstra()", d_tag)
{
    directed_graph<unsigned> graph;

    graph.add_vertex(1);
    graph.add_vertex(2);
    graph.add_vertex(3);
    graph.add_vertex(4);
    graph.add_edge(0, 1);
    graph.add_edge(1, 2);
    graph.add_edge(1, 4);

    auto out = dijkstra (graph, 0);
    REQUIRE(out.vertex(0) == 0);
    REQUIRE(out.vertex(2) == 5);

}

