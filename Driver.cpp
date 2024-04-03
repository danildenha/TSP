#include <iostream>
#include <fstream> 
#include <sstream> 
#include <string>
#include <list> 
#include <map>
#include <climits>
#include <vector>
#include <assert.h>
#include "graph.h"

using namespace std;



int main() {
    ifstream graph1("graph1.txt");
    if (!graph1.is_open()) {
        cout << "Couldn't open graph file" << endl;
        return 1;
    }
    Graph* g = new Graph();
    g->read(graph1);

    //TODO: Find the shortest distance and the shortest path
    //on the graph
    //cout << "Optimal tour cost = [" << shortestDistance(g) << ", <"
    // << shortestPath(g) << ">]" << endl;

    g->print();
    delete g;
    graph1.close();

    return 0;
}