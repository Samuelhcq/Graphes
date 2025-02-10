#include "graph.hpp"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <random>


void Graph::display(std::ostream & f) const{
    f << "DISPLAY GRAPH" << std::endl;
    f << "nb of vertices " << nb_vertices() << std::endl;
    f << "nb of edges " << nb_edges() << std::endl;
    for (vertex v1 = 0; v1 < nb_vertices(); ++v1) {
        f << "neighbors of " << v1 << " : " ;
        for (auto v2 : neighbors(v1)) {
            f << v2 << " ";
        }
        f << std::endl;

    }
        f << "END DISPLAY GRAPH" << std::endl;
    }



void Graph::display_screen() const{
    display(std::cout);
}




void Graph::intersect_neighbors(vector<vertex> &vect, vertex v1) const
{
   std::vector<vertex> neigh_v1 = neighbors(v1);
   std::set_intersection(vect.begin(), vect.end(), neigh_v1.begin(), neigh_v1.end(),
                            std::back_inserter(vect));
}

void Graph::union_neighbors(vector<vertex> &vect, vertex v1) const
{
    std::vector<vertex> neigh_v1 = neighbors(v1);
    std::set_union(vect.begin(), vect.end(), neigh_v1.begin(), neigh_v1.end(),
                             std::back_inserter(vect));
}

void Graph::diff_neighbors(vector<vertex> &vect, vertex v1) const
{
    std::vector<vertex> neigh_v1 = neighbors(v1);
    std::set_difference(vect.begin(), vect.end(), neigh_v1.begin(), neigh_v1.end(),
                             std::back_inserter(vect));
}

// Convert the graph to a dot file.
void Graph::to_dot(const std::string &filename) const {
    std::ofstream file(filename);
    file << "graph {" << std::endl;
    for (vertex vertex = 0; vertex < nb_vertices(); ++vertex) {
        file << vertex << ";" << std::endl;
    }
    for (vertex v1 = 0; v1 < nb_vertices(); ++v1) {
        for (vertex v2 = v1; v2 < nb_vertices(); ++v2) {
            if (is_edge(v1, v2)) {
                file << v1 << " -- " << v2 << ";" << std::endl;
            }
        }
    }
    file << "}" << std::endl;
}

void Graph::export_as_dimacs_file(const std::string &filename) const {
    std::ofstream file(filename);
    file << "p edge " << nb_vertices() << " " << nb_edges() << std::endl;
    for (vertex v1 = 0; v1 < nb_vertices(); ++v1) {
        for (vertex v2 = v1; v2 < nb_vertices(); ++v2) {
            if (is_edge(v1, v2)) {
                file << "e " << v1 << " " << v2 << std::endl;
            }
        }
    }
}


// Generate a random graph with nb_vertices vertices and a density of
// proba_density [0,100].
void Graph::generate_random(vertex nb_vertices,
                            float proba_edges,
                            vertex seed) {
    std::mt19937 generator(seed);
    std::uniform_int_distribution<vertex> distribution(0, 100);

    vertex proba = 100 * proba_edges;
    if (proba > 100) proba = 100;

    reset(nb_vertices);
    for (vertex v1 = 0; v1 < nb_vertices; ++v1) {
        for (vertex v2 = v1 + 1; v2 < nb_vertices; ++v2) {
            if (distribution(generator) < proba) {
                add_edge(v1, v2);
            }
        }
    }
}

// Import a graph from a file in the DIMACS format.
void Graph::import_dimacs_file(const std::string &name, Graph &graph) {
    const std::string file_name = "../instances/" + name + ".col";

    std::ifstream file(file_name);
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open file " + file_name);
    }

    vertex nb_vertices;
    vertex nb_edges;
    vertex vertex1;
    vertex vertex2;

    std::string first;
    file >> first;
    while (!file.eof()) {
        if (first == "e") {
            file >> vertex1 >> vertex2;
            vertex1--;
            vertex2--;
            graph.add_edge(vertex1, vertex2);
        } else if (first == "c") {
            getline(file, first);
        } else if (first == "p") {
            file >> first >> nb_vertices >> nb_edges;
            graph.reset(nb_vertices);
        } else {
            throw std::runtime_error("Unknown character while reading file: " + first);
        }
        file >> first;
    }
    if (graph.nb_edges() != nb_edges) {
        throw std::runtime_error("Error: number of edges does not match");
    }
}


