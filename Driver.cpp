#include <bitset>
#include "graph.h"

using namespace std;

//Find minimal distance for 
int minDist(const Graph& graph) {
    return 1;
};

int main() {
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;
    ifstream graph1(filename);
    if (!graph1.is_open()) {
        cerr << "Couldn't open graph file" << endl;
        return 1;
    }
    Graph* g = new Graph();
    g->read(graph1);

    //TODO: Find the shortest distance and the shortest path
    //on the graph
    //cout << "Optimal tour cost = [" << minDist(g) << ", <"
    // << shortestPath(g) << ">]" << endl;

    g->print();
    delete g;
    graph1.close();

    return 0;
}