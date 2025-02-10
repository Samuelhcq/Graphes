#include "graphListAdj.hpp"

#include <algorithm>

GraphAdjSet::GraphAdjSet(std::string &filename) {
    import_dimacs_file(filename, *this);
}

GraphAdjSet::GraphAdjSet(vertex nb_vertices,
                           float proba_edges,
                           vertex seed) {
    generate_random(nb_vertices, proba_edges, seed);
}

gint GraphAdjSet::nb_vertices() const {
    return _nb_vertices;
};

// Returns the number of edges in the graph.
gint GraphAdjSet::nb_edges() const {
    return _nb_edges;
}

// Whether the vertices v1 and v2 are connected by an edge
bool GraphAdjSet::is_edge(vertex v1, vertex v2) const {
    return std::find(_neighbors_set[v1].begin(), _neighbors_set[v1].end(), v2) !=
           _neighbors_set[v1].end();
}

// Add an edge between the vertices v1 and v2.
void GraphAdjSet::add_edge(vertex v1, vertex v2) {
    if (is_edge(v1,v2)) return ;
    _neighbors_set[v1].insert(v2);
    _neighbors_set[v2].insert(v1);
    ++_nb_edges;
}

// Remove the edge between the vertices v1 and v2.
void GraphAdjSet::delete_edge(vertex v1, vertex v2) {
    _neighbors_set[v1].erase(v2);
    _neighbors_set[v2].erase(v1);
    --_nb_edges;
}

// Returns the degree of the vertex.
// The degree of a vertex is the number of edges incident to it.
gint GraphAdjSet::degree(vertex vertex) const {
    return _neighbors_set[vertex].size();
}

// Returns the list of neighbors of the vertex v1.
std::vector<vertex> GraphAdjSet::neighbors(vertex v1) const {
    std::vector<vertex> v = std::vector<vertex>(_neighbors_set[v1].begin(),
                                                _neighbors_set[v1].end());
    std::sort(v.begin(),v.end());
    return v;
}

// Reset the graph to a new size nb_vertices.
void GraphAdjSet::reset(vertex nb_vertices) {
    _nb_vertices = nb_vertices;
    _nb_edges = 0;
    _neighbors_set.clear();
    _neighbors_set.resize(nb_vertices);
    _neighbors_set.shrink_to_fit();
}
