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
//TODO : 
            //Check minDist() function
            // Add printMinCost function
            /* void printMinCostTour (unsigned n, unsigned P[][],set<unsigned> V)
            {
                unsigned v = 1; //assume first vertex index is one. Labels could be reordered.
                set<unsigned> A = V – {v};
                cout << v; //print starting vertex
                while ( A != emptyset) {
                cout << “ -> “;
                unsigned v = P[v][A] //update to next vertex in tour as computed in travel algorithm
                cout << v;
                A = A – {v}; //remove current vertex v just vsited and visit the next vertex remaining in A
                // that is next on the optimal tour.
                }
                cout << “ -> “ << 1; //return back to starting vertex/
            } */
 
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
        // POTENTIAL UPGRADE : 
        //      set all bits of size - 1 to 1
        //      we use size - 1 since v1 is not included
        //for now lets stick with an easier version
        for ( int i = 0; i < size; ++i ) {set.set(i);}
        mainSet = set;
        //rows: number of vertices
        //cols: number of possible subsets
        D.resize(size, vector<int>(set.to_ulong()));
        P.resize(size, vector<int>(set.to_ulong()));
    }

    //FOR DEBUGGING ONLY
    void print() {
        cout << mainSet.to_ulong() << endl;
    }

    unsigned int minDist() {
        unsigned int minLength = INT_MAX;

        //every vertex except v1 the cost of edge
        //vi to v1 must be considered
        for ( unsigned int i{0}; i < size; i++ )
        {
            D[i][0] = W.getEdgeCost(i, 0);
        }

                    //TODO: implement the main DP loop and add bitsets

        //main DP loop
        //NOTE!!!:
                //Should work might be bug with indecies in the for loops
         for ( unsigned int k{1}; k < size-1; k++ )
            for ( unsigned int subset{1}; subset < mainSet.to_ulong(); subset++ ) //Potential bug
            {
                bitset<MAX_BITS> subsetBits(subset);
                if ( subsetBits.count() == k )
                {
                    for ( unsigned int i{1}; i < size; i++ )
                    {
                        // Check if Vertex i is not included in the subset
                        if (subsetBits.test(i - 1)) {
                            int minDist = INT_MAX;
                            int minPrev = -1;
                            for (size_t j = 1; j < size; j++) {
                                if (subsetBits.test(j - 1) && j != i) {
                                    int dist = W.getEdgeCost(i, j) + D[j][subset & ~(1 << (j - 1))];
                                    if (dist < minDist) {
                                        minDist = dist;
                                        minPrev = j;
                                    }
                                }
                            }
                            D[i][subset] = minDist;
                            P[i][subset] = minPrev;
                        }
                        
                    }    
                }
            }


        return minLength;
    }

};

#endif