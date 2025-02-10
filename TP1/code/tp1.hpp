#pragma once

#include "graph.hpp"



// Returns the number of vertices in the graph.
gint nb_edges(const Graph &g);

// Returns the density of the graph.
double density(const Graph &g);

// Returns the maximum degree of the graph.
gint max_degree(const Graph &g);

// Returns a pair of the max degree vertex and its degree.
std::pair<vertex, gint> max_degree_vertex(const Graph &g);

// Returns a pair of  the vector with all the max degree vertices and the maximum degree.
gint max_degree_vertices(const Graph &g, std::vector<vertex> &vertices);

// Returns true if the vertices of the graph are a clique.
bool is_clique(const Graph &g, const std::vector<vertex> &vertices);

// Returns true if the vertices of the graph are a stable set.
bool is_stable_set(const Graph &g, const std::vector<vertex> &vertices);




/**
 * @brief Return the path from the starting vertex to the others, Breadth First Search
 */
vector<vertex> breadth_first_search(const Graph &graph, const vertex start);

/**
 * @brief Return the path from the starting vertex to the others, Depth First Search
 */
vector<vertex> depth_first_search(const Graph &graph, const vertex start);

/**
 * @brief Print the connected components of the graph
 */
void connected_components(const Graph &graph);

// Returns true if the graph is connected (i.e., there is a path between any pair
// of vertices).
bool is_connected(const Graph &g);

// Returns true if the graph as an eulerian path.
bool has_eulerian_path(const Graph &g);

// Returns true if the graph as an eulerian cycle.
bool has_eulerian_cycle(const Graph &g);
