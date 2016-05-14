# dijkstra
Implementation of Dijkstra's algorithm

# about

`dijkstra.hpp` contains an implementation of Dijkstra's algorithm,
using a `directed_graph` for a graph implementation.

The implementation is a template function that takes a type T, matching
that of the `directed_graph` given to the function.

`dijkstra.hpp` depends on `directed_graph.hpp`.

# functions 

```C++
    template <class T> directed_graph<T> dijkstra(directed_graph<T> &graph, 
                                                  size_t start,
                                                  T infinity = 0xfffff,
                                                  T zero = 0)
```

Run Dijkstra's algorithm on `graph`, using `start` as the starting point.
Note that while `graph` is not passed `const`, it WILL NOT be modified.

The algorithm returns a directed graph with the same size and indexing of
`graph` that has been modified so that each vertex value is the minimum
distance to that vertex to the start, and each vertex has an edge pointing
back to the node that will lead to the shortest path to the start.

`infinity` and `zero` are used by the algorithm to determine which vertices
have been checked and which vertex is the start.
