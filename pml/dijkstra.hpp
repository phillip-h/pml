#ifndef __PML_DIJKSTRA__
#define __PML_DIJKSTRA__

#include <queue>
#include <set>

#include "directed_graph.hpp"

template <class T> directed_graph<T> dijkstra(directed_graph<T> &graph, 
                                              size_t start,
                                              T infinity = 0xfffff,
                                              T zero = 0)
{
    typedef std::pair<size_t, T> vertex_t;

    auto distance = directed_graph<T>(graph);
    distance.clear_edges();

    const auto comp = [](const vertex_t &a, const vertex_t &b)
    {
        return a.second > b.second;
    };
    std::priority_queue<vertex_t, std::vector<vertex_t>, 
                        decltype(comp)> queue(comp);
    
    const auto len = graph.vertices().size();
    for (size_t i = 0; i < len; i++)
    {
        if (i == start) {
            distance.vertex(i) = zero;
            queue.emplace(i, zero);
        } else {
            distance.vertex(i) = infinity;
            queue.emplace(i, infinity);
        }
    }

    vertex_t current;
    std::vector<size_t> edges;
    std::set<size_t> complete;
    T tmp_cost;
    size_t tmp_pos;
    while (!queue.empty())
    {
        current = queue.top();
        queue.pop();

        if (complete.find(current.first) != complete.end())
            continue;

        complete.insert(current.first);

        edges = graph.edges(current.first);
        for (size_t i = 0; i < edges.size(); i++)
        {
            tmp_pos = edges.at(i);
           
            tmp_cost = distance.vertex(current.first) + 
                       graph.vertex(tmp_pos); 
           
            if (tmp_cost < distance.vertex(tmp_pos)) {
                distance.clear_edge(tmp_pos);
                distance.add_edge(tmp_pos, current.first);
                distance.vertex(tmp_pos) = tmp_cost;
                queue.emplace(tmp_pos, tmp_cost);
            }
        }
    }

    return distance;
}

#endif
