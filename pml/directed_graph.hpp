#ifndef __PML_DIRECTED_GRAPH__
#define __PML_DIRECTED_GRAPH__

#include <cstdint>
#include <vector>
#include <utility>

template <class T> class directed_graph final
{
    typedef std::pair<T, std::vector<size_t>> vertex_t;
    typedef std::vector<vertex_t> graph;
 
  private:
    graph graph_;

  public:
    explicit directed_graph(size_t size = 0)
    {
        graph_ = graph();
        graph_.reserve(size);
    }

    directed_graph(const directed_graph &other)
    {
        graph_ = graph(other.graph_.begin(), other.graph_.end());
    }

    size_t add_vertex(T vert)
    {
        graph_.push_back(vertex_t(vert, std::vector<size_t>()));
        return graph_.size() - 1;
    }

    T& vertex(size_t id)
    {
        return graph_.at(id).first;
    }

    void add_edge(size_t a, size_t b)
    {
        if (a >= graph_.size() || b >= graph_.size())
            return;
        graph_.at(a).second.push_back(b);
    }

    std::vector<size_t> edges(size_t id) const
    {
        if (id >= graph_.size())
            return std::vector<size_t>();
        return graph_.at(id).second;
    }

    std::vector<T> vertices() const
    {
        std::vector<T> ret;
        for (vertex_t v : graph_)
            ret.push_back(v.first);
        return ret;
    }

    void clear_edge(size_t id)
    {
        graph_.at(id).second.clear();
    }

    void clear_edges()
    {
        for (vertex_t &v : graph_)
        {
            v.second.clear();
        }
    }

};

#endif
