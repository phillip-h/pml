#ifndef __PML_DIJKSTRA__
#define __PML_DIJKSTRA__

#include <algorithm>
#include <map>
#include <set>

#include "directed_graph.hpp"

template <class T> directed_graph<T> dijkstra(directed_graph<T> &graph, 
                                              size_t start,
                                              T infinity = 0xfffff,
                                              T zero = 0)
{
    typedef std::pair<size_t, T> vertex_t;

    std::map<size_t, T> entries; 
    directed_graph<T> distance = directed_graph<T>(graph);
    auto comp = [&entries](const size_t &a, const size_t &b)
    {
        return entries.at(a) < entries.at(b);
    };
    std::multiset<size_t, decltype(comp)> queue(comp);
    
    std::vector<T> verticies = graph.verticies();
    for (size_t i = 0; i < verticies.size(); i++)
    {
        if (i == start) {
            entries.insert(vertex_t(i, zero));
        } else {
            entries.insert(vertex_t(i, infinity));
        }
        queue.insert(i);
        distance.vertex(i) = 0;
    }

    size_t current;
    std::vector<size_t> edges;
    T tmp_cost;
    while (!queue.empty())
    {
        current = *queue.begin();
        queue.erase(queue.begin());

        distance.vertex(current) = entries.at(current);

        edges = graph.edges(current);
        for (size_t i = 0; i < edges.size(); i++)
        {
           if (distance.vertex(edges.at(i)) != 0)
               continue;

           tmp_cost = entries.at(current) + graph.vertex(edges.at(i)); 
           
           if (tmp_cost < entries.at(edges.at(i)))
               entries.at(edges.at(i)) = tmp_cost;
        }
    }

    return distance;
}

#endif
