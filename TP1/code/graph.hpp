#pragma once

#include <string>
#include <vector>
#include "graphDefs.hpp"
//#include "graphs/adjmat.hpp"


class Graph {
  public:
    virtual ~Graph() = default;

    // Returns the number of vertices in the graph.
    virtual gint nb_vertices() const = 0;

    // Returns the number of edges in the graph.
    virtual gint nb_edges() const = 0;

    // Whether the vertices v1 and v2 are connected by an edge
    virtual bool is_edge(vertex v1, vertex v2) const = 0;

    // Add an edge between the vertices v1 and v2.
    virtual void add_edge(vertex v1, vertex v2) = 0;

    // Remove the edge between the vertices v1 and v2.
    virtual void delete_edge(vertex v1, vertex v2) = 0;

    // Returns the degree of the vertex.
    // The degree of a vertex is the number of edges incident to it.
    virtual gint degree(vertex vertex) const = 0;

    // Returns the list of neighbors of the vertex v1.
    virtual std::vector<vertex> neighbors(vertex v1) const = 0;

    //Intersect in place sorted vector vect with neighbors of v1
    virtual void intersect_neighbors(vector<vertex>& vect, vertex v1) const;

    //Union in place of  sorted vector vect with neighbors of v1
    virtual void union_neighbors(vector<vertex>& vect, vertex v1) const;

    //Remove in place from  sorted vector vect the neighbors of v1
    virtual void diff_neighbors(vector<vertex>& vect, vertex v1) const;

    // Convert the graph to a dot file.
    void to_dot(const std::string &filename) const;

    // Export the graph to a file in the DIMACS format.
    void export_as_dimacs_file(const std::string &filename) const;

    // Display on screen : TODO use fstream
    void display(std::ostream & f) const;
    void display_screen() const;


  protected:
    // Reset the graph to a new size nb_vertices.
    virtual void reset(gint nb_vertices) = 0;

    // Generate a random graph with nb_vertices vertices and a density of
    // proba_density [0,100].
    void generate_random(gint nb_vertices,
                         float proba_edges,
                         gint seed);

    // Import a graph from a file in the DIMACS format.
    void import_dimacs_file(const std::string &name, Graph &graph);
};
