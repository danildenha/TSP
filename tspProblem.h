#ifndef PROBLEM_H
#define PROBLEM_H

#include <iostream>
#include <climits>
#include <vector>
#include <assert.h>
#include <bitset>
#include <string>
#include "graph.h"

using namespace std;
const int MAX_BITS = 32;
//TODO : FIX computeMinTourCost and printMinTour !!!
 
class tspProblem
{
private:
    Graph W;
    vector<vector<int>> D,P;
    bitset<MAX_BITS> mainSet;
    size_t size;
public:
	tspProblem(Graph& w): W(w), size(w.getNumVertices()) {
        bitset<MAX_BITS> set;
        for ( int i = 0; i < size; ++i ) {set.set(i);}
        mainSet = set;
        //rows: number of vertices
        //cols: number of possible subsets
        D.resize(size, vector<int>(set.to_ulong(), -1));
        P.resize(size, vector<int>(set.to_ulong(), -1));
    }

    //FOR DEBUGGING ONLY
    void print() {
        unsigned int bestTourCost = computeMinTourCost( 0, mainSet.reset(0));
        if (bestTourCost == INT_MAX)
        {
            cout << "No Hamiltonian Cycle" << endl;
        }
        else
        {
            cout << "Optimal Tour Cost = [" <<  bestTourCost << ", <";
            printMinCostTour();
            cout << ">]";
            cout << endl;
        }
        

    }

    unsigned int computeMinTourCost(unsigned int i, bitset<MAX_BITS> S) {
        int subsetVal = S.to_ulong();
        //chekc if subset is empty
        if (S.none()) 
            return W.getEdgeCost(i, 0);
        //if value already computed, use it 
        if (D[i][subsetVal] >= 0) return D[i][subsetVal];

        unsigned int bestCost = INT_MAX;
        unsigned int best_j = -1;
        bool found_at_least_one_vertex = false;
        //iterate through every subset. J = SUBSET
        for (unsigned int j = 1; j < size; j++) {
            if (S[j] == 1){
                unsigned int aCost = W.getEdgeCost(i, j) + computeMinTourCost(j, S.reset(j));
                S.set(j);
                
                //check if we found smaller cost
                if (aCost < bestCost) {
                    found_at_least_one_vertex = true;
                    bestCost = aCost;
                    best_j = j;
                }
            }
        }
        //memoization step
        if (found_at_least_one_vertex) {
            D[i][subsetVal] = bestCost;
            P[i][subsetVal] = best_j;
        }

        return bestCost;
    }
    void printMinCostTour() {
        //Starting with index = 0
        unsigned int start_vertex = 0;
        bitset<MAX_BITS> remaining_vertices = mainSet;
        //reset first vertex to 0
        remaining_vertices.reset(start_vertex);

        //unsigned int current_vertex = start_vertex;
        cout << W.getVertexName(start_vertex); // print the starting vertex

        while (remaining_vertices.any()) {
            cout << ",";
            //unsigned long next_vertex = P[current_vertex][remaining_vertices.to_ulong()];
            unsigned long currIndex = remaining_vertices.to_ulong();
            start_vertex = P[start_vertex][currIndex];

            cout << W.getVertexName(start_vertex);
            remaining_vertices.reset(start_vertex);
            //update curr vertex
            //current_vertex = next_vertex;
        }

        cout << "," << W.getVertexName(0);
    }

};

#endif