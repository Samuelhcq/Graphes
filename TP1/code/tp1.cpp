#include "tp1.hpp"

#include <algorithm>
#include <deque>
#include <fstream>
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_set>
//#include <set>
#include <sstream>

using gint = int;
using vertex = gint;
using t_cost = int;




// Returns the number of vertices in the graph.
gint nb_edges(const Graph &g) {
    return g.nb_edges();
}

// Returns the density of the graph.
double density(const Graph &g) {
    double n = g.nb_vertices();
    return g.nb_edges()/(n*(n-1)/2);

}

// Returns the maximum degree of the graph.
gint max_degree(const Graph &g) {
    gint max_d = g.degree(0);
    for(vertex v = 1 ; v<g.nb_vertices() ; ++v){
        if (g.degree(v)>max_d){
            max_d = g.degree(v);
        }
    }
    return max_d;
}

// Returns a pair of the max degree vertex and its degree.
std::pair<gint, gint> max_degree_vertex(const Graph &g) {
    gint max_d = g.degree(0);
    vertex max_vertex = 0;
    for(vertex v = 1 ; v<g.nb_vertices() ; ++v){
        if (g.degree(v)>max_d){
            max_d = g.degree(v);
            max_vertex = v;
        }
    }
    return std::make_pair(max_d, max_vertex);
}

gint max_degree_vertices(const Graph &g, std::vector<vertex> &vertices)
{//TODO
    return 0;
}


// Returns true if the vertices of the graph are a clique.
bool is_clique(const Graph &graph, const std::vector<gint> &vertices) {
    //TODO
  return true;
}

// Returns true if the vertices of the graph are a stable set.
bool is_stable_set(const Graph &graph, const std::vector<gint> &vertices) {
    //TODO
  return true;
}


vector<vertex> breadth_first_search(const Graph &graph, const vertex start) {
    vector<vertex> vertices_visited;
    std::queue<vertex> todo;
    std::unordered_set<vertex> visited;

    todo.push(start);
    visited.insert(start);

    while (!todo.empty()) {
        vertex v = todo.front();
        todo.pop();
        vertices_visited.push_back(v);

        for (vertex v_neighbour : graph.neighbors(v)) {
            if (visited.find(v_neighbour) == visited.end()) {
                visited.insert(v_neighbour);
                todo.push(v_neighbour);
            }
        }
    }
    return vertices_visited;
}

std::vector<vertex> depth_first_search(const Graph &graph, const vertex start) {
    std::vector<vertex> vertices_visited;
    std::stack<vertex> stack;
    std::unordered_set<vertex> visited;

    stack.push(start);
    visited.insert(start);

    while (!stack.empty()) {
        vertex v = stack.top();
        stack.pop();
        vertices_visited.push_back(v);
        for (vertex v_neighbor : graph.neighbors(v)) {
            if (visited.find(v_neighbor) == visited.end()) {
                visited.insert(v_neighbor);
                stack.push(v_neighbor);
            }
        }
    }
    return vertices_visited;
}


void connected_components(const Graph &graph) {
    // TODO : implement the connected components algorithm


}

