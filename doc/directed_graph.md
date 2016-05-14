# directed_graph
A class representing a directed graph

# about

`directed_graph.hpp` contains a class that represents a directed graph.
The class contains functions to manipulate the graph by adding and removing
vertices and edges, along with querying information about vertex values
and edges.

`directed_graph` is a template class, and is marked `final`.

# constructors

```C++
    explicit directed_graph(size_t size = 0);
             directed_graph(const directed_graph &other);
```

The first constructor will create an empty graph, and reserve `size`
elements in it's internal storage array. Changing the size is useful if
you want to prevent vector resizing, and already know the number of
vertices you will be adding to the graph.

The second constructor is a copy constructor that will create a copy
of the graph `other`.

# graph manipulation functions

```C++
    size_t add_vertex(T vert);
    void add_edge(size_t a, size_t b);
    void clear_edge(size_t id);
    void clear_edges();
```

`add_vertex()` will add a vertex to the graph with the value of `T vert`,
and return a `size_t` of it's index, which can be used to access the value
again in the future.

`add_edge()` will add an edge starting in `a` and pointing to `b`.

`clear_edge()` will clear all the edges of the vertex at `id`.

`clear_edges()` will clear all edges in the graph, but leave the vertices
unchanged.

# graph access functions

```C++
    T& vertex(size_t id);
    vector<size_t> edges(size_t id);
    vector<T> vertices();
```

`vertex()` will return a reference to the vertex value at `id`.

`edges()` will return a vector of all of the vertex at `id`'s edges
(in the form of `size_t` ids).

`vertices()` will return a vector of all the vertex values in the graph,
ordered so that they can be accessed using the same `size_t` ids as the
graph itself.
