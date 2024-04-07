#include <bitset>
#include <string>
#include "graph.h"
#include "tspProblem.h"

using namespace std;

int main() {
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;
    ifstream graph1(filename);
    if (!graph1.is_open()) {
        cerr << "Couldn't open graph file" << endl;
        return 1;
    }
    Graph g;
    g.read(graph1);

    //TODO: Find the shortest distance and the shortest path
    //on the graph
    //cout << "Optimal tour cost = [" << minDist(g) << ", <"
    // << shortestPath(g) << ">]" << endl;
    //cout << minDist(g) << "----" << endl;

    g.print();
    graph1.close();

    return 0;
}
