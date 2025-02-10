
#include "graphs/graphListAdj.hpp"
#include <iostream>
#include "tp1.hpp"


void print_vector(vector<vertex> vec){
    for (auto v : vec) {
        cout << " " << v;
    }
    cout << endl;
}

int main(int argc , char* argv [])
{
    //string s("myciel");
    string s("p06"); // nom de l'instance

    if (argc>=2) {
        s = argv[1];
        s="../instances/"+s;
    }
    GraphAdjSet g(s);

   cout<<"Nombre de sommets du graphe : " << g.nb_vertices()<<endl;
   cout<<"Nombre d arretes du graphe : " << nb_edges(g)<<endl;
   cout<<"Densite du graphe : " << density(g)<<endl;
   cout<<"Degre max du graphe : " << max_degree(g)<<endl;
   cout<<"Parcours BFS du graphe partant de 0 : ";
   print_vector(breadth_first_search(g,0));
   cout<<"Parcours DFS du graphe partant de 0 : ";
   print_vector(depth_first_search(g,0));


    return 0;
}
